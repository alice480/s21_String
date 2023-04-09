#include "string.h"

int main() {
  char a[30] = "abcfchqofkwqof ok";
  // char* b = "cde";
  char sym = 'c';
  char *ptr = strchr(a, sym);
  printf("%s", ptr);
  // printf("%s", a);
}

// change to s21_strlen
char *s21_strcat(char *dest, const char *src) {
  int length = strlen(dest);
  for (int i = 0; src[i] != '\0'; i++) {
    dest[length + i] = src[i];
  }
  return dest;
}

// change to s21_strlen
char *s21_strncat(char *dest, const char *src, size_t n) {
  int length = strlen(dest);
  for (long unsigned int i = 0; src[i] != '\0' && i < n; i++) {
    dest[length + i] = src[i];
  }
  return dest;
}

// change to s21_strcpy
char *s21_strchr(const char *str, int c) {
  int i;
  for (i = 0; str[i] != '\0' && str[i] != c; i++) {
  };
  return (char *)str + i;
}