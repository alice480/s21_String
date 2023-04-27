#include "s21_string.h"

/*Сравнивает первые n байтов str1 и str2,
возвращает 0, если байты равны, > 0, если найденный различающийся
байт первого массива больше второго, < 0, если меньше*/

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  int res = 0, flag = 0;
  if (n == 0) {
    res = 0;
  } else {
    unsigned char *sym2 = (unsigned char *)str2;
    unsigned char *sym1 = (unsigned char *)str1;
    for (int i = 0; i < n && flag != 1; i++) {
      if (*sym1++ != *sym2++) {
        flag = 1;
        res = (*--sym1 - *--sym2);
      }
    }
  }
  return res;
}
