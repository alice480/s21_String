#include "s21_string.h"

/*ищет первое вхождение строки needle в haystack*/

char *s21_strstr(const char *haystack, const char *needle) {
  char *move_haystack = (char *)haystack;
  char *move_needle = (char *)needle;
  char *result = S21_NULL;
  int move_needle_len = s21_strlen(needle), count = 0;
  if (move_needle_len == 0)
    result = move_haystack;
  else if (s21_strlen(haystack) != 0)
    while (*move_haystack != '\0') {
      if (*move_haystack == *move_needle) {
        while (*move_haystack == *move_needle && *move_needle != '\0') {
          count++;
          move_haystack++;
          move_needle++;
        }
        if (count == move_needle_len) {
          move_haystack -= count;
          result = move_haystack;
          break;
        } else {
          move_needle -= count;
          count = 0;
          move_haystack++;
        }
      } else
        move_haystack++;
    }
  return result;
}