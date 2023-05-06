#include "s21_string.h"

char *s21_strtok(char *str, const char *delim) {
  static char *ptr;
  char *tokens;
  if (((str == S21_NULL && (ptr == S21_NULL || *ptr == 0)))) {
    tokens = S21_NULL;
  } else {
    if (str != S21_NULL) {
      ptr = str;
    }
    while (*ptr && s21_strchr(delim, *ptr)) {
      ptr++;
    }
    tokens = ptr;
    while (*ptr && !s21_strchr(delim, *ptr)) {
      ptr++;
    }
    if (*ptr != '\0') {
      *ptr++ = '\0';
    }
  }
  return tokens;
}