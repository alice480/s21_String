#include "s21_string.h"

/*Выполняет поиск первого вхождения символа c (беззнаковый тип) в первых n
байтах строки, на которую указывает аргумент str.
(Выводит всю строку, начиная с заданного символа)*/

void *s21_memchr(const void *str, int c, s21_size_t n) {
  unsigned char *c_str = (unsigned char *)str;
  void *output = S21_NULL;
  unsigned char c_copy = c;
  int i = 0, flag = 0;
  while (c_str && i < n && flag != 1) {
    if (*c_str == c_copy) {
      output = c_str;
      flag = 1;
    }
    i++;
    c_str++;
  }
  return output;
}