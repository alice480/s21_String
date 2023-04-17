#include "string.h"

/*выделяет очередную часть строки, на которую указывает
аргумент str, отделенную одним из символов разделителей,
указанных в delim*/

char *s21_strtok(char *str, const char *delim) {
  static char *s;
  char *token;
  if (((str == S21_NULL && (s == S21_NULL || *s == 0)))) {
    token = S21_NULL;
  } else {
    if (str != S21_NULL) {
      s = str;
    }
    while (*s && s21_strchr(delim, *s)) {
      s++;
    }
    token = s;
    while (*s && !s21_strchr(delim, *s)) {
      s++;
    }
    if (*s != '\0') {
      *s++ = '\0';
    }
  }
  return token;
}