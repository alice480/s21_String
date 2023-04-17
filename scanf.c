#include "string.h"

int s21_sscanf(const char *str, const char *format, ...) {
  int output = 0;
  char *c_format = (char *)format;
  Format_string format_string = {0};
  va_list assign_variables;
  va_start(assign_variables, format);
  if (!s21_strcmp(str, ""))
    output = -1;
  else if (str != S21_NULL && (c_format) && s21_strchr(c_format, '%'))
    output = string_processing(str, c_format, assign_variables, &format_string);
  else
    output = 0;
  va_end(assign_variables);
  return output;
}

int string_processing(const char *str, const char *format,
                      va_list assign_variables, Format_string *format_string) {
  int flag = 0, used_args = 0;
  char *c_str = (char *)str;
  format_string->last_address = (s21_size_t)c_str;
  format_string->strlen_str = s21_strlen(str);
  if (*format != '%') {
    if (s21_strchr(" \t\n", *format)) {
      while (s21_strchr(" \t\n", *format) && *format != '\0') format++;
      if (s21_strchr(" \t\n", *c_str))
        while (s21_strchr(" \t\n", *c_str)) c_str++;
    }
  }

  while ((*format != '\0' && flag != -1 && *c_str != '\0' && flag != 1)) {
    while (s21_strchr(" \n\t", *format) && *format != '\0') {
      format++;
      while (s21_strchr("\t\n ", *c_str) && *c_str != '\0') c_str++;
    }
    if (*format != '%' && *format != '\0' && *c_str != '\0') {
      if (*format == *c_str && *c_str != '\0') {
        while (*format == *c_str && *c_str != '\0') {
          c_str++;
          format++;
        }
      } else
        flag = -1;
    }
    if (*format == '%' && flag != 1 && *format != '\0') {
      if (*(format + 1) == '%') {
        format += s21_strspn(format, " %%\t\n");
        while (s21_strchr(" %%", *c_str)) c_str++;
        if (*(c_str + 1) == '%') {
          flag = 1;
        } else {
          c_str += s21_strspn(c_str, " %%\t\n");
        }
      } else
        format++;
    }
    while (*format == '*' && *format != '\0' && *c_str != '\0' && flag != 1) {
      format_string->suppress_assignment += 1;
      format++;
      format_string->specificator = *format;
      while (*format != '%' && *format != '\0' && *c_str != '\0') format++;
      if (*format != '\0')
        format++;
      else
        flag = 1;
      if (*format != '*') break;
    }
    if ((*c_str != '\0' && *format != '\0') || (flag == 'n')) {
      if (flag == 0 && *c_str != '\0') {
        flag = format_string_parcing(&format, format_string, &used_args);
        if (flag == 0 && *c_str != '\0') {
          flag = writing_formatted(format_string, &c_str, assign_variables,
                                   &used_args);
          if (flag == 0 && *c_str != '\0') {
            format++;
            format_string->Width = 0;
          }
        }
      }
    }
    if (*(format + 3) == 'n' && *c_str == '\0') {
      format += 3;
      format_string->specificator = 'n';
      flag = writing_formatted(format_string, &c_str, assign_variables,
                               &used_args);
      if (flag == 0 && *c_str != '\0') {
        format++;
        format_string->Width = 0;
      }
    }
  }
  format_string->suppress_assignment = 0;
  if (flag == -1) used_args = -1;
  return used_args;
}

int format_string_parcing(const char **format, Format_string *format_string,
                          int *used_args) {
  int move = 0, flag = 0, is_spec = 0;
  char temp[256] = {0};
  while (**format != '\0' && flag == 0 && is_spec == 0) {
    if (s21_strchr("cdieEfgGosuxXpn", **format)) {
      format_string->specificator = **format;
      is_spec = 1;
    } else if (s21_strchr("0123456789", **format)) {
      s21_size_t ind = 0;
      while (**format >= 48 && **format <= 57) {
        temp[ind++] = **format;
        (*format)++;
      }
      move = s21_atoi(temp, format_string);
      format_string->Width = move;
    } else if (s21_strchr("hlL", **format)) {
      format_string->length = **format;
      (*format)++;
    }
  }
  return flag;
}

int writing_formatted(Format_string *format_string, char **c_str,
                      va_list assign_variables, int *used_args) {
  int flag = 0;
  if (format_string->specificator == 'c')
    flag = write_to_char(format_string, c_str, assign_variables, used_args);
  else if (s21_strchr("diuxXopn", format_string->specificator))
    flag = write_to_int(format_string, c_str, assign_variables, used_args);
  else if (s21_strchr("fgGeE", format_string->specificator))
    flag = write_to_float(format_string, c_str, assign_variables, used_args);
  else if (format_string->specificator == 's')
    flag = write_to_str(format_string, c_str, assign_variables, used_args);
  return flag;
}

int write_to_char(Format_string *format_string, char **str,
                  va_list assign_variables, int *used_args) {
  int flag = 0, width = format_string->Width,
      not_assign = format_string->suppress_assignment, i = 0;
  char buf[300] = {0};
  if (format_string->Width == 0) width = 1;
  if (not_assign > 0) {
    if (width == 1) {
      while (not_assign != 0) {
        (*str)++;
        not_assign--;
      }
    } else {
      while (width != 0) {
        (*str)++;
        width--;
      }
      (*str)++;
      not_assign--;
    }
  }
  if (**str != '\0') {
    buf[i++] = **str;
    width--;
    while (width != 0) {
      (*str)++;
      width--;
    }
    (*str)++;
    buf[i] = '\0';
    i = 0;
    *(va_arg(assign_variables, char *)) = (int)buf[i];
    (*used_args)++;
    format_string->suppress_assignment = 0;
  }
  return flag;
}

int write_to_str(Format_string *format_string, char **str,
                 va_list assign_variables, int *used_args) {
  int flag = 0, width = 0, token_length = 0;
  width = (format_string->Width);
  char *argPtr = va_arg(assign_variables, char *);
  int isEmptyStr = 0;
  while (s21_strchr("\n\t ", **str)) (*str)++;
  if (format_string->suppress_assignment > 0) {
    while (format_string->suppress_assignment > 0 && **str != '\0') {
      while (**str && !s21_strchr("\n\t ", **str)) (*str)++;
      while (**str && s21_strchr("\n\t ", **str)) (*str)++;
      if (!s21_strchr("\n\t ", **str)) format_string->suppress_assignment--;
    }
  }
  while (**str && s21_strchr("\n\t ", **str)) {
    (*str)++;
    isEmptyStr = 1;
  }
  if (width >= 1) {
    while (**str && !s21_strchr("\n\t ", **str) && width != 0) {
      *argPtr++ = **str;
      (*str)++;
      isEmptyStr = 1;
      width--;
    }
  } else {
    while (**str && !s21_strchr("\n\t ", **str)) {
      *argPtr++ = **str;
      (*str)++;
      isEmptyStr = 1;
      width--;
    }
  }
  if (isEmptyStr) *argPtr = '\0';
  (*(used_args)) += 1;
  return flag;
}

int write_to_int(Format_string *format_string, char **str,
                 va_list assign_variables, int *used_args) {
  int flag = 0;
  char buf[400] = {'\0'};
  char *buffPtr;
  buffPtr = buf;
  int *argPtr;
  long long int d_value = 0;
  int width = (format_string->Width);
  char spec = format_string->specificator;
  if (spec != 'n') {
    while (*str && s21_strchr("\n\t ", **str)) {
      (*str)++;
      format_string->count_symbols++;
    }
  }
  if (format_string->count_symbols == (format_string->strlen_str) + 1)
    flag = -1;
  else if (((!s21_strchr("aAbBcCdDeEfF0123456789+-", **str) && spec != 'n')))
    flag = 1;
  if (format_string->suppress_assignment > 0) {
    while (format_string->suppress_assignment > 0 && **str != '\0') {
      while (**str != '\0' && !s21_strchr("\n\t ", **str)) {
        (*str)++;
        format_string->count_symbols++;
      }
      format_string->suppress_assignment--;
    }
    while (s21_strchr("\n\t ", **str)) {
      (*str)++;
      format_string->count_symbols++;
    }
  }
  if (s21_strchr("aAbBcCdDeEfF", **str) &&
      (spec != 'x' && spec != 'X' && spec != 'n')) {
    flag = 1;
  }
  if (abs(flag) != 1) {
    if (s21_strchr("+-", **str) &&
        (!s21_strchr("aAbBcCdDeEfF0123456789", *(*str + 1)) || width == 1))
      flag = 1;
    if (**str == '+') {
      (*str)++;
      if (width > 0) {
        width--;
        if (width == 0) flag = 1;
      }
    } else if (**str == '-') {
      format_string->is_neg = 1;
      (*str)++;
      if (width > 0) {
        width--;
        if (width == 0) flag = 1;
      }
    }
    if (spec == 'p' || spec == 'x' || spec == 'X') {
      if ((*(*str + 1) == 'x' || *(*str + 1) == 'X')) {
        if (**str == '0') {
          *(str) += 2;
          if (width > 2) width -= 2;
        } else
          flag = 1;
      }
    } else if (spec == 'i') {
      format_string->is_i = 1;
      if (**str == '0') {
        if (*(*str + 1) == 'x' || *(*str + 1) == 'X') {
          *(str) += 2;
          if (width > 0) width -= 2;
          spec = 'x';
        } else {
          spec = 'o';
        }
      } else {
        spec = 'd';
      }
    }
    if (spec != 'n' && spec != 'd' && spec != 'u' && spec != 'o') {
      s21_size_t i = 0;
      if (width == 0) {
        while (!s21_strchr(" \n\t-+", **str) &&
               s21_strchr("0123456789aAbBcCdDeEfF-", **str)) {
          buf[i] = **str;
          (*str)++;
          i++;
        }
      } else {
        while (width > 0 && !s21_strchr(" \n\t-+", **str) &&
               s21_strchr("0123456789aAbBcCdDeEfF-", **str)) {
          buf[i] = **str;
          (*str)++;
          i++;
          width--;
        }
      }
    } else if (spec == 'u' || spec == 'd') {
      s21_size_t i = 0;
      if (width == 0) {
        while (!s21_strchr(" \n\t-+", **str) &&
               s21_strchr("0123456789-", **str)) {
          buf[i] = **str;
          (*str)++;
          i++;
        }
      } else {
        while (width > 0 && !s21_strchr(" \n\t-+aAbBcCdDeEfFxX", **str)) {
          buf[i] = **str;
          (*str)++;
          i++;
          width--;
        }
      }
    } else if (spec == 'o') {
      s21_size_t i = 0;
      if (width == 0) {
        while (!s21_strchr(" \n\t-+\0", **str) &&
               s21_strchr("01234567-", **str)) {
          buf[i] = **str;
          (*str)++;
          i++;
        }
      } else {
        while (width > 0 && s21_strchr("01234567-", **str)) {
          buf[i] = **str;
          (*str)++;
          i++;
          width--;
        }
      }
    }
    format_string->count_symbols += s21_strlen(buf);
    if (*buf == 0 && s21_strlen(buf) == 0 && spec == 'o') flag = 1;
    if ((s21_strlen(buf) != 0 || spec == 'n') && abs(flag) != 1) {
      if ((spec == 'p' || spec == 'x' || spec == 'X')) {
        d_value = conv_16_to_10(buf, format_string);
      } else if (spec == 'o' && flag != 1) {
        d_value = conv_8_to_10(buf, format_string);
      } else if ((spec == 'd' || spec == 'u')) {
        d_value = s21_atoi(buf, format_string);
      } else if (spec == 'n') {
        d_value = (long long int)(*str - (format_string->last_address));
      } else
        flag = 1;
    }
    if (abs(flag) != 1) {
      if (format_string->length) {
        if (spec != 'u' && spec != 'n') {
          if (format_string->length == 'h') {
            *(va_arg(assign_variables, short int *)) = (short int)d_value;
            (*used_args)++;
          } else if (format_string->length == 'l') {
            *(va_arg(assign_variables, long long int *)) =
                (long long int)d_value;
            (*used_args)++;
          } else {
            *(va_arg(assign_variables, int *)) = (int)d_value;
            (*used_args)++;
          }
          format_string->length = 0;
        } else if (spec != 'n') {
          if (format_string->length == 'h') {
            *(va_arg(assign_variables, unsigned short int *)) =
                (unsigned short int)d_value;
            (*used_args)++;
          } else if (format_string->length == 'l') {
            *(va_arg(assign_variables, unsigned long int *)) =
                (unsigned long int)d_value;
            (*used_args)++;
          } else {
            *(va_arg(assign_variables, unsigned int *)) = (unsigned int)d_value;
            (*used_args)++;
          }
        } else if (spec == 'n') {
          *(va_arg(assign_variables, int *)) = (int)d_value;
          (*used_args)++;
        }
        format_string->length = 0;
      } else {
        if (spec != 'u') {
          *(va_arg(assign_variables, int *)) = d_value;
          (*used_args)++;
        } else {
          *(va_arg(assign_variables, unsigned int *)) = (unsigned int)d_value;
          (*used_args)++;
        }
      }
      if (spec == 'n') (*used_args)--;
    }
  }
  return flag;
}

long unsigned conv_8_to_10(char *buffer, Format_string *format_string) {
  long long int sum = 0, count = 0;
  int flag = 0, overflow = 0, sign = 0;
  if (format_string->is_neg == 1) sign = -1;
  s21_strtok(buffer, ".");
  while (count < s21_strlen(buffer)) {
    sum += (buffer[count] - '0') * pow(8, s21_strlen(buffer) - count - 1);
    count++;
    if (sum < 0) overflow = 1;
  }
  if (overflow == 1) {
    if (format_string->is_i != 1)
      sum = ULLONG_MAX;
    else {
      if (sign == -1)
        sum = LLONG_MIN;
      else
        sum = LLONG_MAX;
    }
  } else if (sign == -1)
    sum *= sign;
  format_string->is_neg = 0;
  return sum;
}

long unsigned conv_16_to_10(char *buffer, Format_string *format_string) {
  long long int sum = 0, count = 0;
  int flag = 0, overflow = 0, sign = 0;
  if (format_string->is_neg == 1) sign = -1;
  s21_strtok(buffer, ".");
  while (count < s21_strlen(buffer)) {
    if ((buffer[count] >= 65 && buffer[count] <= 70))
      sum += (buffer[count] + 10 - 'A') *
             pow(16, s21_strlen(buffer) - ((count) + 1));
    else if (buffer[count] >= 'a' && buffer[count] <= 'f')
      sum += (buffer[count] + 10 - 'a') *
             pow(16, s21_strlen(buffer) - ((count) + 1));
    else if (buffer[count] >= 48 && buffer[count] <= 57)
      sum +=
          (buffer[count] - '0') * pow(16, s21_strlen(buffer) - ((count) + 1));
    if (sum < 0) {
      overflow = 1;
      break;
    }
    count++;
  }
  if (overflow == 1) {
    if (format_string->is_i != 1)
      sum = ULLONG_MAX;
    else {
      if (sign == -1)
        sum = LLONG_MIN;
      else
        sum = LLONG_MAX;
    }
  } else if (sign == -1)
    sum *= sign;
  format_string->is_neg = 0;
  format_string->is_i = 0;
  return sum;
}

long long s21_atoi(char *buffer, Format_string *format_string) {
  long long count = 0, sum = 0, overflow = 0, sign = 0;
  if (format_string->is_neg == 1) sign = -1;
  s21_strtok(buffer, ".");
  while (count < s21_strlen(buffer)) {
    sum = sum * 10 + (buffer[count] - '0');
    if (sum < 0) {
      overflow = 1;
      break;
    }
    count++;
  }
  if (overflow == 1) {
    if (format_string->specificator != 'u') {
      if (sign == -1)
        sum = LLONG_MIN;
      else
        sum = LLONG_MAX;
    } else {
      sum = ULLONG_MAX;
    }

  } else if (sign == -1)
    sum *= sign;
  format_string->is_neg = 0;
  return sum;
}

int write_to_float(Format_string *format_string, char **str,
                   va_list assign_variables, int *used_args) {
  int flag = 0, width = (format_string->Width);
  s21_size_t i = 0;
  char buf[500] = {'\0'};
  char spec = format_string->specificator;
  long double l_value = 0.0;
  while (*str && s21_strchr("\n\t ", **str)) (*str)++;
  if (**str == '.') {
    if (!s21_strchr("0123456789eE", *(*str + 1)) || *(*str + 1) == '\0')
      flag = 1;
  } else if (!s21_strchr("0123456789.+-", **str))
    flag = 1;
  if ((**str == '+' || **str == '-') &&
      !s21_strchr("0123456789.eE", *(*str + 1)))
    flag = 1;
  if (format_string->suppress_assignment > 0) {
    while (format_string->suppress_assignment > 0) {
      while (**str != '\0' && !s21_strchr("\n\t ", **str)) {
        (*str)++;
        format_string->count_symbols++;
      }
      format_string->suppress_assignment--;
    }
    while (s21_strchr("\n\t ", **str)) {
      (*str)++;
      format_string->count_symbols++;
    }
  }
  if (**str == '+') {
    (*str)++;
    if (width > 0) {
      width--;
      if (width == 0) flag = 1;
    }
  } else if (**str == '-') {
    format_string->is_neg = 1;
    (*str)++;
    if (width > 0) {
      width--;
      if (width == 0) flag = 1;
    }
  }
  if (flag != 1) {
    s21_size_t i = 0;
    if (width == 0) {
      while (!(s21_strchr(" \n\t", **str)) &&
             s21_strchr("0123456789eE.+-", **str)) {
        buf[i++] = **str;
        (*str)++;
      }
    } else {
      while (width > 0 && !s21_strchr(" \n\t", **str) &&
             s21_strchr("0123456789eE.+-", **str)) {
        buf[i] = **str;
        (*str)++;
        i++;
        width--;
      }
    }
    if (((buf[0] == '+' || buf[0] == '-') && buf[1] == 'e') ||
        (buf[0] == 'e' && s21_strchr("0123456789", buf[1])))
      flag = 1;
    if (abs(flag) != 1) {
      format_string->count_symbols += s21_strlen(buf);
      l_value = s21_strtold(buf, format_string);
      if (format_string->length) {
        if (format_string->length == 'l')
          *va_arg(assign_variables, double *) = (double)l_value;
        else
          *va_arg(assign_variables, long double *) = (long double)l_value;
        (*used_args)++;
      } else {
        *(va_arg(assign_variables, float *)) = (float)l_value;
        (*used_args)++;
      }
      format_string->length = 0;
    }
  }
  return flag;
}

long double s21_strtold(char *buffer, Format_string *format_string) {
  long double result = 0.0L;
  long double sign = 1.0L;
  int exp = 0;
  int exp_sign = 1;
  int found_digit = 0;
  int count = 0;
  if (format_string->is_neg == 1) sign = -1.0L;
  while (buffer[count] >= '0' && buffer[count] <= '9') {
    result = result * 10.0L + (long double)(buffer[count] - '0');
    found_digit = 1;
    count++;
  }
  if (buffer[count] == '.') {
    count++;
    long double fraction = 0.1L;
    while (buffer[count] >= '0' && buffer[count] <= '9') {
      result += (long double)(buffer[count] - '0') * fraction;
      fraction *= 0.1L;
      found_digit = 1;
      count++;
    }
  }
  if (buffer[count] == 'e' || buffer[count] == 'E') {
    count++;
    if (buffer[count] == '-') {
      exp_sign = -1;
      count++;
    } else if (buffer[count] == '+') {
      count++;
    }
    while (buffer[count] >= '0' && buffer[count] <= '9') {
      exp = exp * 10 + (buffer[count] - '0');
      count++;
    }
  }
  if (found_digit) {
    result *= sign;
    result *= powl(10.0L, (long double)(exp * exp_sign));
  }
  format_string->is_neg = 0;
  return result;
}