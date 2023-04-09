#include "string.h"

int main() {
  char str1[1024]= "1236at";
  char str2[1024]= "rt";
  if (s21_strpbrk(str1, str2))
    printf("%s\n", s21_strpbrk(str1, str2));
  else
    printf("NULL\n");
}

// change to s21_strlen
char *s21_strcat(char *dest, const char *src) {
  int length = strlen(dest);
  for (int i = 0; src[i]; i++) {
    dest[length + i] = src[i];
  }
  return dest;
}

// change to s21_strlen
char *s21_strncat(char *dest, const char *src, size_t n) {
  int length = strlen(dest);
  for (long unsigned int i = 0; src[i] && i < n; i++) {
    dest[length + i] = src[i];
  }
  return dest;
}

// change to s21_strcpy
char *s21_strchr(const char *str, int c) {
  int i;
  for (i = 0; str[i] && str[i] != c; i++) {
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

char *s21_strpbrk(const char *str1, const char *str2) {
  size_t i = 0, j = 0;
  for (; str2[i] && str1[j] != str2[i]; i++) {
    for (j = 0; str1[j] && str1[j] != str2[i]; j++) {};
  }
  return (j < strlen(str1)) ? (char *)str1 + j : NULL;
}

