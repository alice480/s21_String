#include "s21_string.h"

void *s21_memmove(void *dest, const void *src, s21_size_t n) {
  char *csrc = (char *)src;
  char *cdest = (char *)dest;
  char *temp = (char *)malloc(n * sizeof(char));
  s21_size_t i = 0;
  while (i < n) {
    temp[i] = csrc[i];
    i++;
  }
  i = 0;
  while (i < n) {
    cdest[i] = temp[i];
    i++;
  }
  free(temp);
  return dest;
}