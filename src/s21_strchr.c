#include "s21_string.h"

/*Функция strchr ищет первое вхождение символа, код которого указан в аргументе
ch, в строке, на которую указывает аргумент str.*/

char *s21_strchr(const char *str, int c) {
  char *str1 = (char *)str;
  unsigned char sym = (unsigned char)c;
  int flag = 0;
  char *res;
  for (; flag != 1 && *str1 != '\0'; str1++) {
    if (*str1 == c) {
      flag = 1;
      str1--;
    }
  }
  if (*str1 == '\0' && c == '\0') {
    res = str1;
  } else if (flag == 0) {
    res = S21_NULL;
  } else
    res = str1;
  return res;
}
