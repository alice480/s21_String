#include "s21_string.h"

void *s21_memchr(const void *str, int c, s21_size_t n) {
  char *tmp = (char *)str;
  void *ret_vl = S21_NULL;
  if (str)
    for (s21_size_t i = 0; i <= n; i++)
      if (tmp[i] == c && tmp[i] != '\0') ret_vl = tmp + i;
  return ret_vl;
}

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  int ret_vl = 0;
  if (str1 && str2) {
    char *tmp1 = (char *)str1;
    char *tmp2 = (char *)str2;
    for (s21_size_t i = 0; i < n && ret_vl == 0; i++)
      ret_vl = tmp1[i] - tmp2[i];
  }
  return ret_vl;
}

void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  void *ret_vl = S21_NULL;
  if (dest && src) {
    char *tmp_dest = (char *)dest;
    char *tmp_src = (char *)src;
    for (s21_size_t i = 0; i < n; i++) tmp_dest[i] = tmp_src[i];
    ret_vl = dest;
  }
  return ret_vl;
}

void *s21_memset(void *str, int c, s21_size_t n) {
  void *ret_vl = S21_NULL;
  if (str) {
    char *tmp_str = (char *)str;
    for (s21_size_t i = 0; i < n; i++) tmp_str[i] = c;
    ret_vl = str;
  }
  return ret_vl;
}

char *s21_strcpy(char *dest, const char *src) {
  char *ret_vl = S21_NULL;
  if (dest && src) {
    s21_size_t i = 0;
    while (src[i] != '\0') {
      dest[i] = src[i];
      i++;
    }
    dest[i] = '\0';
    ret_vl = dest;
  }
  return ret_vl;
}

s21_size_t s21_strcspn(const char *str1, const char *str2) {
  s21_size_t i = 0;
  if (str1 && str2) {
    s21_size_t flag = 0;
    while (str1[i] != '\0' && !flag) {
      s21_size_t j = 0;
      while (str2[j] != '\0' && !flag) {
        if (str1[i] == str2[j]) flag = 1;
        j++;
      }
      i++;
    }
    if (i > 0 && flag) i--;
  }
  return i;
}

s21_size_t s21_strlen(const char *str) {
  s21_size_t len = 0;
  if (str)
    while (str[len] != '\0') len++;
  return len;
}

char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
  char *ret_vl = S21_NULL;
  if (dest && src) {
    for (s21_size_t i = 0; i < n; i++) dest[i] = src[i];
    ret_vl = dest;
  }
  return ret_vl;
}

void *s21_to_upper(const char *str) {
  char *copy_str = S21_NULL;
  if (str) {
    copy_str = malloc(s21_strlen(str) * sizeof(char));
  }
  if (copy_str) {
    for (int i = 0; str[i]; i++)
      copy_str[i] = (str[i] >= 97 && str[i] <= 122) ? str[i] - 32 : str[i];
  }
  return copy_str;
}

void *trimStart(const char *src, const char *trim_chars) {
  char *copy_src = S21_NULL;
  if (src) {
    copy_src = malloc(s21_strlen(src) * sizeof(char));
  }
  if (copy_src) {
    char keys[SIZE] = {'\0'};
    if (!trim_chars || s21_memcmp(trim_chars, "", s21_strlen(trim_chars)) == 0)
      keys[0] = ' ';
    else
      s21_strcpy(keys, trim_chars);
    bool flag = 0;
    size_t k = 0;
    for (int i = 0; src[i]; i++) {
      for (int j = 0; keys[j] && !flag; j++) {
        if (src[i] == keys[j]) break;
        if (!keys[j + 1]) flag = 1;
      }
      if (flag) copy_src[k++] = src[i];
    }
    copy_src[k] = '\0';
  }
  return copy_src;
}

void rev_str(char *str) {
  char buf[SIZE] = {'\0'};
  int len = s21_strlen(str);
  for (int i = 0; str[i]; i++) {
    buf[len - 1 - i] = str[i];
  }
  s21_strcpy(str, buf);
}

void *trimEnd(const char *src, const char *trim_chars) {
  char *copy_src = S21_NULL;
  if (src) {
    char tmp_src[SIZE] = {'\0'};
    s21_strcpy(tmp_src, src);
    rev_str(tmp_src);
    copy_src = trimStart(tmp_src, trim_chars);
    rev_str(copy_src);
  }
  return copy_src;
}

void *s21_trim(const char *src, const char *trim_chars) {
  char *copy_src = S21_NULL;
  if (src) {
    char tmp_src[SIZE] = {'\0'};
    s21_strcpy(tmp_src, src);
    copy_src = trimStart(tmp_src, trim_chars);
    s21_strcpy(tmp_src, copy_src);
    free(copy_src);
    copy_src = trimEnd(tmp_src, trim_chars);
  }
  return copy_src;
}