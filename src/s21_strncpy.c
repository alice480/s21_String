#include "s21_string.h"

char* s21_strncpy(char* dest, const char* src, s21_size_t n) {
  int count = 0;
  char *src_cpy, *dest_cpy;
  dest_cpy = dest;
  src_cpy = (char*)src;
  while (count < n) {
    *dest_cpy = *src_cpy;
    src_cpy++;
    dest_cpy++;
    count++;
  }
  return dest;
}