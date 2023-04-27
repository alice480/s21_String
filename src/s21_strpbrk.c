#include "s21_string.h"

// Находит первый символ в строке str1, который соответствует любому символу,
// указанному в str2.

char *s21_strpbrk(const char *str1, const char *str2) {
  char *cstr1 = (char *)str1;
  char *res = S21_NULL;
  int flag = 0;
  while (*cstr1 != '\0' && flag != 1) {
    if (s21_strchr(str2, *cstr1)) {
      flag = 1;
      res = cstr1;
    } else {
      cstr1++;
    }
  }
  return res;
}
