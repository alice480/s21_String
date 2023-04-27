#include "s21_string.h"

/*Функция побайтно сравнивает коды символов двух строк, на которые указывают
 * аргументы функции*/

int s21_strcmp(const char* str1, const char* str2) {
  int result = 0;
  if (str1 && str2) {
    while (*str1 && (*str1 == *str2)) {
      str1++;
      str2++;
    }
    result = *str1 - *str2;
  }
  return result;
}
