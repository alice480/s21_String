#include "./s21_string.h"

typedef struct {
  bool minus;
  bool plus;
  bool space;
  bool hash;
  bool zero;
} flags;

typedef struct {
  flags fl;
  int width;
  int precision;
  char length;
  char specifier;
  bool error;
  bool has_precision;
} arguments;

bool is_digit(const char ch) { return ch >= '0' && ch <= '9'; };

bool is_flag(const char ch) {
  bool ans = 0;
  switch (ch) {
    case '-':
    case '+':
    case ' ':
    case '#':
    case '0':
      ans = 1;
      break;
  }
  return ans;
}

bool is_specifier(const char ch) {
  bool ans = 0;
  switch (ch) {
    case 'c':
    case 'd':
    case 'i':
    case 'e':
    case 'E':
    case 'f':
    case 'g':
    case 'G':
    case 'o':
    case 's':
    case 'u':
    case 'x':
    case 'X':
    case 'p':
    case 'n':
    case '%':
      ans = 1;
      break;
  }
  return ans;
}

int char_to_digit(const char ch) { return is_digit(ch) ? ch - 48 : -1; }

const char *set_flags(const char *format, arguments *arg) {
  while (is_flag(*format) && !arg->error) {
    switch (*format) {
      case '-':
        if (!arg->fl.zero) {
          arg->fl.minus = 1;
        } else {
          arg->error = 1;
          // puts("Error: conflicts flags '-' and '0'");
        }
        break;
      case '+':
        if (!arg->fl.space) {
          arg->fl.plus = 1;
        } else {
          arg->error = 1;
          // puts("Error: conflicts flags '+' and '-'");
        }
        break;
      case ' ':
        if (!arg->fl.plus) {
          arg->fl.space = 1;
        } else {
          arg->error = 1;
          // puts("Error: conflicts flags ' ' and '+'");
        }
        break;
      case '#':
        arg->fl.hash = 1;
        break;
      case '0':
        if (!arg->fl.minus) {
          arg->fl.zero = 1;
        } else {
          arg->error = 1;
          // puts("Error: conflicts flags '0' and '-'");
        }
        break;
    }
    format++;
  }
  return format;
}

const char *set_width(const char *format, arguments *arg, va_list factor) {
  if (*format == '*') {
    // возможно нужна проверка на int
    arg->width = va_arg(factor, int);
    format++;
  } else if (is_digit(*format)) {
    int width = 0;
    while (is_digit(*format)) {
      width *= 10;
      width += char_to_digit(*format);
      format++;
    }
    arg->width = width;
  }
  return format;
}

const char *set_precision(const char *format, arguments *arg, va_list factor) {
  if (*format == '.') {
    format++;
    if (*format == '*') {
      format++;
      arg->precision = va_arg(factor, int);
      arg->has_precision = 1;
    } else if (is_digit(*format)) {
      int precision = 0;
      while (is_digit(*format)) {
        precision *= 10;
        precision += char_to_digit(*format);
        format++;
      }
      arg->precision = precision;
      arg->has_precision = 1;
    } else {
      // ошибка формата, не задана точность
      arg->error = 1;
      // puts("Error: has not precision");
    }
  }
  return format;
}

const char *set_length(const char *format, arguments *arg) {
  switch (*format) {
    case 'h':
      arg->length = 'h';
      format++;
      break;
    case 'l':
      arg->length = 'l';
      format++;
      break;
    case 'L':
      arg->length = 'L';
      format++;
      break;
  }
  return format;
}

const char *set_specifier(const char *format, arguments *arg) {
  if (is_specifier(*format)) {
    arg->specifier = *format;
  } else {
    // ошибка, нет спецификатора
    arg->error = 1;
    // puts("Error: has not specifier");
  }
  return format;
}

void num_to_str(int64_t num, char *str_num, int base) {
  char tmp[SIZE] = {'\0'};
  int idx = SIZE - 2;
  bool sign = num < 0 ? 1 : 0;
  num = sign ? -num : num;
  if (num == 0) tmp[idx] = '0';
  while (num > 0) {
    idx--;
    tmp[idx] = "0123456789abcdef"[num % base];
    num /= base;
  }
  for (int j = 0; tmp[idx]; idx++, j++) {
    if (sign && j == 0) {
      str_num[j++] = '-';
    }
    str_num[j] = tmp[idx];
  }
}

char *format_char(arguments arg, char *str, char ch) {
  int width = arg.width;
  if (!arg.fl.minus && width) {
    for (int i = 1; i < width; i++) {
      *str++ = ' ';
      if (i == width - 1) *str++ = ch;
    }
  } else if (width) {
    str[0] = ch;
    str++;
    for (int i = 1; i < width; i++) *str++ = ' ';
  } else {
    str[0] = ch;
    str++;
  }
  return str;
}

char *format_wchar(arguments arg, char *str, wchar_t w_ch) {
  int width = arg.width;
  if (!arg.fl.minus && width) {
    for (int i = 1; i < width; i++) {
      *str++ = ' ';
      if (i == width - 1) wcstombs(str++, &w_ch, SIZE);
    }
  } else if (width) {
    wcstombs(str++, &w_ch, SIZE);
    ;
    for (int i = 1; i < width; i++) *str++ = ' ';
  } else {
    wcstombs(str++, &w_ch, SIZE);
  }
  return str;
}

char *parse_char(arguments arg, char *str, va_list factor) {
  if (arg.fl.hash || arg.fl.plus || arg.fl.space || arg.fl.zero ||
      arg.precision) {
    arg.error = 1;
    // puts("Error: invalid flag for char");
  } else if (arg.length == 'l') {
    wchar_t w_ch = va_arg(factor, wchar_t);
    str = format_wchar(arg, str, w_ch);
  } else {
    char ch = va_arg(factor, int);
    str = format_char(arg, str, ch);
  }
  return str;
}

void format_precision(char *str_num, arguments arg) {
  char tmp[SIZE] = {'\0'};
  int sign = 0;
  int len = s21_strlen(str_num);
  if (str_num[0] == '-') {
    tmp[0] = '-';
    len--;
    sign = 1;
  }
  if (arg.precision > len) {
    int i = sign;
    for (i = sign; i < arg.precision - len + sign; i++) tmp[i] = '0';
    for (int j = sign; str_num[j]; j++, i++) tmp[i] = str_num[j];
    s21_strcpy(str_num, tmp);
  }
  if (arg.precision == 0 && str_num[0] == '0') str_num[0] = '\0';
}

void format_flags(char *str_num, arguments arg) {
  char tmp[SIZE] = {'\0'};
  if (arg.fl.hash || arg.specifier == 'p') {
    if ((arg.specifier == 'o' && (int)s21_strlen(str_num) < arg.precision &&
         arg.has_precision) ||
        (arg.specifier == 'o' && !arg.has_precision)) {
      tmp[0] = '0';
      s21_strcpy(tmp + 1, str_num);
      s21_strcpy(str_num, tmp);
    }
    if (arg.specifier == 'x' || arg.specifier == 'X' || arg.specifier == 'p') {
      tmp[0] = '0';
      tmp[1] = arg.specifier == 'p' ? 'x' : arg.specifier;
      s21_strcpy(tmp + 2, str_num);
      s21_strcpy(str_num, tmp);
    }
  }
  size_t len = s21_strlen(str_num);
  size_t width = arg.width;
  if (width > len) {
    int delta = width - len;
    if (!arg.fl.minus) {
      s21_memset(tmp, arg.fl.zero ? '0' : ' ', delta);
      s21_strcpy(tmp + delta, str_num);
    } else {
      s21_strcpy(tmp, str_num);
      s21_memset(tmp + len, ' ', delta);
    }
    s21_strcpy(str_num, tmp);
  }
  bool sign = 0;
  if (str_num[0] == '-') sign = 1;
  if (arg.fl.plus) {
    tmp[0] = sign ? '-' : '+';
    s21_strcpy(tmp + 1, sign ? str_num + 1 : str_num);
    s21_strcpy(str_num, tmp);
  } else if (arg.fl.space && !sign) {
    tmp[0] = ' ';
    s21_strcpy(tmp + 1, str_num);
    s21_strcpy(str_num, tmp);
  }
}

char *str_plus_str(char *str, char *str_num) {
  for (int i = 0; str_num[i]; i++) {
    *str++ = str_num[i];
  }
  return str;
}

char *parse_int(arguments arg, char *str, va_list factor) {
  long int num = 0;
  switch (arg.length) {
    case 'h':
      num = (short)va_arg(factor, int);
      break;
    case 'l':
      num = va_arg(factor, long);
      break;
    case 0:
      num = va_arg(factor, int);
  }
  char str_num[SIZE] = {'\0'};
  num_to_str(num, str_num, 10);
  format_precision(str_num, arg);
  format_flags(str_num, arg);
  return str_plus_str(str, str_num);
}

void double_to_string(long double num, char *str_num, arguments arg) {
  char buff[SIZE] = {'\0'};
  int idx = SIZE - 2;
  bool sign = num < 0 ? 1 : 0;
  num = sign ? num * -1 : num;
  long double div = 0;
  long double mod = modfl(num, &div);
  if (arg.precision == 0) {
    div = roundl(num);
    mod = 0;
  }
  char fractions[SIZE] = {'\0'};
  for (int i = 0; i < arg.precision; i++) {
    mod *= 10;
    fractions[i] = (int)mod + '0';
  }
  long long right = roundl(mod);
  long long left = div;
  if (!right) {
    for (int i = 0; i < arg.precision; idx--, i++) buff[idx] = '0';
  } else {
    for (int i = s21_strlen(fractions); right || i > 0; right /= 10, idx--, i--)
      buff[idx] = (int)(right % 10 + 0.05) + '0';
  }
  if ((arg.has_precision && arg.precision != 0) || (int)mod ||
      (!arg.has_precision && num == 0) || s21_strlen(fractions))
    buff[idx--] = '.';
  if (!left) {
    buff[idx] = '0';
    idx--;
  } else {
    for (; left; left /= 10, idx--) buff[idx] = (int)(left % 10) + '0';
  }
  for (int i = 0; buff[idx + 1]; idx++, i++) {
    if (sign && i == 0) {
      str_num[i] = '-';
      i++;
    }
    str_num[i] = buff[idx + 1];
  }
}

void normalize_double(long double *num, int *exp, char *exp_sign) {
  if ((*num) != 0.) {
    if (fabsl(*num) < 1) {
      while ((int)(*num) == 0) {
        (*exp)++;
        (*num) *= 10;
      }
    } else {
      (*exp_sign) = '+';
      while ((int)(*num) / 10 != 0) {
        (*exp)++;
        (*num) /= 10;
      }
    }
  }
}

void norm_double_to_sc_not(char *str_num, int exp, char exp_sign,
                           arguments arg) {
  int len = s21_strlen(str_num);
  if (arg.specifier == 'g')
    arg.specifier = 'e';
  else if (arg.specifier == 'G')
    arg.specifier = 'E';
  str_num[len] = arg.specifier;
  str_num[len + 1] = exp_sign;
  str_num[len + 3] = exp % 10 + '0';
  exp /= 10;
  str_num[len + 2] = exp % 10 + '0';
  str_num[len + 4] = '\0';
}

void remove_zeros(char *str_num) {
  size_t len = s21_strlen(str_num);
  if (s21_memchr(str_num, '.', len)) {
    for (int i = len - 1; i > 0; i--) {
      if (str_num[i] == '0')
        str_num[i] = '\0';
      else
        break;
    }
  }
}

void remove_point(char *str_num) {
  size_t len = s21_strlen(str_num);
  for (int i = len - 1; i > 0; i--) {
    if (str_num[i] == '.')
      str_num[i] = '\0';
    else
      break;
  }
}

void remove_exp(char *str_num, int exp) {
  if (exp == 0) {
    size_t len = s21_strlen(str_num);
    str_num[len - 4] = '\0';
  }
}

void remove_end(char *str_num) {
  remove_zeros(str_num);
  remove_point(str_num);
}

void set_gG_size(char *str_num, int new_len) {
  size_t len = s21_strlen(str_num);
  int i = len;
  while ((int)len > new_len) {
    str_num[i--] = '\0';
    len--;
  }
}

int double_to_sc_notation(long double num, char *str_num, arguments arg) {
  char exp_sign = (fabsl(num) >= 1 || num == 0.0) ? '+' : '-';
  int exp = 0;
  normalize_double(&num, &exp, &exp_sign);
  double_to_string(num, str_num, arg);
  if ((arg.specifier == 'g' || arg.specifier == 'G') && !arg.fl.hash)
    remove_end(str_num);
  norm_double_to_sc_not(str_num, exp, exp_sign, arg);
  return exp;
}

void double_to_gG_format(arguments arg, long double num, char *str_num) {
  if (arg.precision == 1) arg.precision = 0;
  // обычное дробое число
  if (num < 0.) arg.precision++;
  double_to_string(num, str_num, arg);
  set_gG_size(str_num, arg.precision);
  if (!arg.fl.hash) remove_end(str_num);
  // научная нотация
  char str_num1[SIZE] = {'\0'};
  int exp = double_to_sc_notation(num, str_num1, arg);
  remove_exp(str_num1, exp);
  // сравнение
  size_t len = s21_strlen(str_num);
  size_t len1 = s21_strlen(str_num1);
  if (len1 < len || arg.precision < 2) s21_strcpy(str_num, str_num1);
}

char *parse_float(arguments arg, char *str, va_list factor) {
  long double num = 0;
  if (!arg.has_precision) arg.precision = 6;
  if (arg.length == 'L') {
    num = va_arg(factor, long double);
  } else {
    num = va_arg(factor, double);
  }
  char str_num[SIZE] = {'\0'};
  if (arg.specifier == 'f') {
    double_to_string(num, str_num, arg);
  } else if (arg.specifier == 'e' || arg.specifier == 'E') {
    double_to_sc_notation(num, str_num, arg);
  } else {
    double_to_gG_format(arg, num, str_num);
  }
  format_flags(str_num, arg);
  return str_plus_str(str, str_num);
}

void format_string(arguments arg, char *str, char *sstr) {
  char tmp[SIZE] = {'\0'};
  s21_strcpy(tmp, sstr);
  if (arg.has_precision) tmp[arg.precision] = '\0';
  int len = s21_strlen(tmp);
  int delta = arg.width - len;

  if (arg.fl.minus && delta > 0) {
    s21_strcpy(str, tmp);
    s21_memset(str + len, ' ', delta);
  } else if (delta > 0) {
    s21_memset(str, ' ', delta);
    s21_strcpy(str + delta, tmp);
  } else {
    s21_strcpy(str, tmp);
  }
}

void format_wstring(arguments arg, char *str, wchar_t *wstr) {
  char tmp[SIZE] = {'\0'};
  wcstombs(tmp, wstr, SIZE);
  if (arg.has_precision) tmp[arg.precision] = '\0';
  int len = s21_strlen(tmp);
  int delta = arg.width - len;
  if (arg.fl.minus && delta > 0) {
    s21_strcpy(str, tmp);
    s21_memset(str + len, ' ', delta);
  } else if (delta > 0) {
    s21_memset(str, ' ', delta);
    s21_strcpy(str + delta, tmp);
  } else {
    s21_strcpy(str, tmp);
  }
}

char *parse_string(arguments arg, char *str, va_list factor) {
  char tmp_str[SIZE] = {'\0'};
  if (arg.length == 'l') {
    wchar_t *wstr = va_arg(factor, wchar_t *);
    format_wstring(arg, tmp_str, wstr);
  } else {
    char *sstr = va_arg(factor, char *);
    format_string(arg, tmp_str, sstr);
  }
  str = str_plus_str(str, tmp_str);
  return str;
}

char *parse_unsigned(arguments arg, char *str, va_list factor) {
  uint64_t num = va_arg(factor, uint64_t);
  switch (arg.length) {
    case 'h':
      num = (uint16_t)num;
      break;
    case 'l':
      num = (uint64_t)num;
      break;
    case 0:
      num = (uint32_t)num;
      break;
  }
  char str_num[SIZE] = {'\0'};
  num_to_str(num, str_num, 10);
  format_precision(str_num, arg);
  format_flags(str_num, arg);
  str = str_plus_str(str, str_num);
  return str;
}

char *parse_octal(arguments arg, char *str, va_list factor) {
  char str_num[SIZE] = {'\0'};
  unsigned int num = va_arg(factor, unsigned int);
  num_to_str(num, str_num, 8);
  format_precision(str_num, arg);
  format_flags(str_num, arg);
  str = str_plus_str(str, str_num);
  return str;
}

void *to_upper(char *str) {
  for (int i = 0; str[i]; i++)
    str[i] = (str[i] >= 97 && str[i] <= 122) ? str[i] - 32 : str[i];
  return str;
}

char *parse_hex(arguments arg, char *str, va_list factor) {
  uint64_t num = va_arg(factor, uint64_t);
  switch (arg.length) {
    case 0:
      num = (uint32_t)num;
      break;
    case 'h':
      num = (uint16_t)num;
      break;
    case 'l':
      num = (uint64_t)num;
      break;
  }
  char str_num[SIZE] = {'\0'};
  num_to_str(num, str_num, 16);
  if (arg.specifier == 'X') to_upper(str_num);
  format_precision(str_num, arg);
  format_flags(str_num, arg);
  str = str_plus_str(str, str_num);
  return str;
}

char *parse_pointer(arguments arg, char *str, va_list factor) {
  uint64_t num = va_arg(factor, uint64_t);
  char str_num[SIZE] = {'\0'};
  num_to_str(num, str_num, 16);
  format_precision(str_num, arg);
  format_flags(str_num, arg);
  str = str_plus_str(str, str_num);
  return str;
}

char *parse_value(arguments arg, char *str, va_list factor) {
  char specifier = arg.specifier;
  if (specifier == 'c')
    str = parse_char(arg, str, factor);
  else if (specifier == 'd' || specifier == 'i')
    str = parse_int(arg, str, factor);
  else if (specifier == 'f' || specifier == 'e' || specifier == 'E' ||
           specifier == 'g' || specifier == 'G')
    str = parse_float(arg, str, factor);
  else if (specifier == 's')
    str = parse_string(arg, str, factor);
  else if (specifier == 'u')
    str = parse_unsigned(arg, str, factor);
  else if (specifier == 'o')
    str = parse_octal(arg, str, factor);
  else if (specifier == 'x' || specifier == 'X')
    str = parse_hex(arg, str, factor);
  else if (specifier == 'p')
    str = parse_pointer(arg, str, factor);
  else if (specifier == '%')
    *str++ = '%';
  return str;
}

int s21_sprintf(char *str, const char *format, ...) {
  char *tmp_str = str;
  va_list factor = {0};
  va_start(factor, format);
  while (*format) {
    if (*format != '%') {
      *str++ = *format++;
      continue;
    } else {
      format++;
      arguments arg = {0};
      format = set_flags(format, &arg);
      format = set_width(format, &arg, factor);
      format = set_precision(format, &arg, factor);
      format = set_length(format, &arg);
      format = set_specifier(format, &arg);
      str = parse_value(arg, str, factor);
      if (arg.specifier == 'n') {
        int *num = va_arg(factor, int *);
        (*num) = str - tmp_str;
      }
    }
    format++;
  }
  *str = '\0';
  va_end(factor);
  return str - tmp_str;
}