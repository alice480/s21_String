#include "s21_string.h"

int s21_strncmp(const char *str1, const char *str2, size_t n) {
  size_t end;
  end = (s21_strlen(str1) < s21_strlen(str2)) ? s21_strlen(str2)
                                              : s21_strlen(str1);
  size_t i;
  for (i = 0; i < end && str1[i] == str2[i] && i < n; i++) {
  };
  return (i < n) ? str1[i] - str2[i] : str1[i - 1] - str2[i - 1];
}