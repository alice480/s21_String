#include "s21_string.h"

/*определяет наибольшую длину начального участка строки,
на которую указывает аргумент str, не содержащего ни один
из символов строки, на которую указывает аргумент sym*/

s21_size_t s21_strcspn(const char* str1, const char* str2) {
  int count = 0, flag = 0, length2 = s21_strlen(str2);
  for (; flag == 0 && *str1 != '\0'; str1++) {
    if (!s21_memchr(str2, *str1, length2)) {
      count++;
    } else {
      flag = 1;
    }
  }
  return count;
}
