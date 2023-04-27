#include "s21_string.h"

/*returns a new string in which a specified string(str) is
inserted at a specified index position (start_index) in
the given string(src).
in case of any error, return NULL*/

void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  char *new_str = S21_NULL;
  int error = 0;
  if (src != S21_NULL && str != S21_NULL) {
    s21_size_t src_length = s21_strlen(src);
    s21_size_t str_length = s21_strlen(str);

    if (str && src && start_index <= (src_length) && start_index >= 0) {
      new_str = (char *)calloc(str_length + 1 + src_length, sizeof(char));
      for (int i = 0; i < start_index; i++) {
        new_str[i] = src[i];
      }
      for (int i = start_index, j = 0; i < start_index + str_length; i++) {
        new_str[i] = str[j++];
      }
      for (int i = start_index + str_length; i < (str_length + src_length);
           i++) {
        new_str[i] = src[start_index++];
      }
    } else {
      error = 1;
    }
  } else if (str == S21_NULL && src != S21_NULL) {
    new_str = calloc(s21_strlen(src) + 1, sizeof(char));
    s21_strcpy(new_str, src);
  }
  return new_str;
}