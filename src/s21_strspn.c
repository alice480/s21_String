#include "s21_string.h"

/*Длина начального участка строки, содержащая только символы,
указанные в аргументе sym*/

s21_size_t s21_strspn(const char* str1, const char* str2) {
  int count = 0, flag = 0, length2 = s21_strlen(str2);
  for (; flag == 0 && *str1 != '\0'; str1++) {
    if (s21_memchr(str2, *str1, length2)) {
      count++;
    } else {
      flag = 1;
    }
  }
  return count;
}
