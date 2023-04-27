#include "s21_string.h"

/*returns a new string in which all leading and trailing occurences of a set of
specified characters (trim_chars) from the given strings (src) are removed.
In case of any error, return NULL*/

// int main() {
//   char strr[] = "&&*$#fgh+ty++00";
//   char trimmed_ch[] = "&*#0+";
//   char expectedly[] = "$#fgh+ty";
//   printf("trim         %s\n", s21_trim(strr, trimmed_ch));
// }

void *s21_trim(const char *src, const char *trim_chars) {
  char *trimmed_str = S21_NULL;
  char *default_chars = " \t\n\v\r\f\0";
  int is_error = 0, left_corner = 0, right_corner = 0;
  if (src) {
    if (trim_chars == S21_NULL || s21_strlen(trim_chars) == 0) {
      trim_chars = default_chars;
    }
    trimmed_str = (char *)calloc(s21_strlen(src) + 10, sizeof(char));
    left_corner = index_left_part(src, trim_chars, trimmed_str);
    right_corner = index_right_part(src, trim_chars, trimmed_str);
    for (int i = left_corner, j = 0; i <= right_corner; i++, j++) {
      trimmed_str[j] = src[i];
    }
    //}
  } else
    is_error = 1;
  return is_error ? S21_NULL : (void *)trimmed_str;
}

int index_left_part(const char *src, const char *trim_chars,
                    char *trimmed_str) {
  int flag = 0;
  for (int i = 0; i < s21_strlen(src); i++) {
    for (int j = 0; j < s21_strlen(trim_chars); j++)
      if (src[i] != trim_chars[j]) {
        flag += 1;
      }
    if (flag == s21_strlen(trim_chars)) {
      return i;
    }
    flag = 0;
  }
}

int index_right_part(const char *src, const char *trim_chars,
                     char *trimmed_str) {
  int flag = 0;
  for (int i = s21_strlen(src) - 1; i >= 0; i--) {
    for (int j = 0; j < s21_strlen(trim_chars); j++)
      if (src[i] != trim_chars[j]) {
        flag += 1;
      }
    if (flag == s21_strlen(trim_chars)) {
      return i;
    }
    flag = 0;
  }
}