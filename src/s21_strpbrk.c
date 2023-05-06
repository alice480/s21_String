#include "s21_string.h"

char *s21_strpbrk(const char *str1, const char *str2) {
  size_t i = 0, j = 0;
  for (; i < s21_strlen(str2) && str1[j] != str2[i]; i++) {
    for (j = 0; j < s21_strlen(str1) && str1[j] != str2[i]; j++) {
    };
  }
  return (j < s21_strlen(str1) && i < s21_strlen(str2)) ? (char *)str1 + j
                                                        : S21_NULL;
}