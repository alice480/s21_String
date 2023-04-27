#include "s21_string.h"

char *s21_strncat(char *dest, const char *src, s21_size_t n) {
  char *new_str = dest;
  while (*new_str != '\0') {
    new_str++;
  }
  for (int i = 0; i < n; i++) {
    *new_str = *src;
    src++;
    new_str++;
  }
  return dest;
}
