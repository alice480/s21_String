#include "string.h"

int main() {
  char str1[1024]= "1236atay";
  //char str2[1024]= "rt";
  if (s21_strstr(str1, "123"))
    printf("%s\n", s21_strstr(str1, "123"));
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

char *s21_strrchr(const char *str, int c) {
  int i;
  for (i = strlen(str) - 1; i != -1 && str[i] != c; i--) {};
  return (i != -1) ? (char*)str + i : NULL;
}

// change find to FALSE
char *s21_strstr(const char *haystack, const char *needle) {
  int find = 0;
  size_t i = 0;
  for (i = 0; haystack[i] && !find; i++) {
    if (haystack[i] == needle[0]) {
      size_t j;
      for (j = 0; needle[j] && haystack[i + j] == needle[j]; j++);
      find = (j == strlen(needle)) ? 1 : 0;
    }
  }
  return (find) ? (char*)haystack + (i - 1) : NULL;
}