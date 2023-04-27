#include "s21_string.h"

char *s21_strcat(char *dest, const char *src) {
  char *new_str = dest;
  for (int i = 0; dest[i] != '\0'; i++) {
    new_str++;
  }
  for (int i = 0; *src != '\0'; i++) {
    *new_str = *src;
    src++;
    new_str++;
  }
  *new_str = '\0';
  return dest;
}