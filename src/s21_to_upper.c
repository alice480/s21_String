#include "s21_string.h"

/*Возвращает копию этой строки, переведенную в верхний регистр*/

void *s21_to_upper(const char *str) {
  char *new_str;
  if (str == S21_NULL)
    new_str = S21_NULL;

  else {
    if (str) {
      new_str = (char *)malloc((s21_strlen(str) + 1) * sizeof(char));
    }
    if (new_str) {
      s21_strcpy(new_str, str);
      for (int i = 0; i < s21_strlen(new_str) + 1; i++) {
        if (new_str[i] >= 97 && new_str[i] <= 122) {
          new_str[i] -= 32;
        }
      }
      new_str[s21_strlen(new_str)] = '\0';
    }
  }
  return (void *)new_str;
}
