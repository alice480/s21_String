#include "s21_string.h"

/*Функция strchr ищет последнее вхождение символа, код которого указан в
аргументе ch, в строке, на которую указывает аргумент str.*/

char *s21_strrchr(const char *str, int c) {
  char *str1 = (char *)str;
  unsigned char sym = (unsigned char)c;
  int flag = 0;
  char *res = S21_NULL;
  str1 = str1 + s21_strlen(str);
  for (; flag != 1 && str1 >= &str[0]; str1--) {
    if (*str1 == sym) {
      flag = 1;
      str1++;
    } else {
      flag = 0;
    }
  }
  if (flag == 0) {
    res = S21_NULL;
  } else {
    res = str1;
  }
  return res;
}