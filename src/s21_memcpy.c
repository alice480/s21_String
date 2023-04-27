#include "s21_string.h"

/*копирование непересекающихся массивов,
возвращает указатель на массив, в который были
скопированы данные, если перекрываются, рез-тат
не определен*/

void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  unsigned char *where = (unsigned char *)dest;
  unsigned char *from = (unsigned char *)src;

  for (int i = 0; i < n; i++) {
    *where++ = *from++;
  }
  return dest;
}
