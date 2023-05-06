#include "s21_string.h"

// change to s21_strlen
char *s21_strncat(char *dest, const char *src, size_t n) {
  int length = s21_strlen(dest);
  for (long unsigned int i = 0; i < s21_strlen(src) && i < n; i++) {
    dest[length + i] = src[i];
  }
  return dest;
}