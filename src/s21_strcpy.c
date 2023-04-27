#include "s21_string.h"

char* s21_strcpy(char* dest, const char* src) {
  char *src_cpy, *dest_cpy;
  dest_cpy = dest;
  src_cpy = (char*)src;
  while (*src_cpy != '\0') {
    *dest_cpy = *src_cpy;
    src_cpy++;
    dest_cpy++;
  }
  *dest_cpy = '\0';
  return dest;
}