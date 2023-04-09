#include "string.h"

int main() {
  char str1[1024]= "12365";
  char str2[1024]= "i";
  printf("%s", s21_strpbrk(str1, str2));
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

// change to max if it is defined in stdlib.h
int s21_strcmp(const char *str1, const char *str2) {\
  size_t end;
  end = (strlen(str1) < strlen(str2)) ? strlen(str2) : strlen(str1);
  size_t i;
  for (i = 0; i < end && str1[i] == str2[i]; i++) {};
  return str1[i] - str2[i];
}

int s21_strncmp(const char *str1, const char *str2, size_t n) {
  size_t end;
  end = (strlen(str1) < strlen(str2)) ? strlen(str2) : strlen(str1);
  size_t i;
  for (i = 0; i < end && str1[i] == str2[i] && i < n; i++) {};
  return str1[i] - str2[i];
}


