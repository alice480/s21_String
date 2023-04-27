#include "s21_string.h"

/*заполняет первые n байт str, символом c*/

void *s21_memset(void *str, int c, s21_size_t n) {
  char *new_str = (char *)str;
  while (n != 0) {
    *new_str++ = c;
    n--;
  }
  return str;
}
