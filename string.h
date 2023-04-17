#include <string.h>
#include <stdio.h>
#include <float.h>
#include <limits.h>
#include <math.h>
#include <stdarg.h>
#include <stdlib.h>
#include <wchar.h>
#define inf 1.0 / 0.0
#define BUFF_SIZE 512
#define S21_NULL ((void*)0)
typedef unsigned long s21_size_t;

typedef struct {
  char specificator;
  char length;
  int suppress_assignment;
  int Width;
  int percent_symbol;
  int count_symbols;
  s21_size_t last_address;
  int is_neg;
  int strlen_str;
  int is_i;
} Format_string;

typedef struct var_parameters {
  int align_minus;
  int show_sign;
  int space_for_pos;
  int hash_zero;
  int direct_zero;
  int width;
  int star_width;
  int star_precision;
  int precision_zero;
  int dot_check;
  int precision_num;
  int len_h;
  int len_l;
  int len_double;
} params;

char *s21_strcat(char *dest, const char *src);
char *s21_strncat(char *dest, const char *src, size_t n);
char *s21_strchr(const char *str, int c);
int s21_strcmp(const char *str1, const char *str2);
int s21_strncmp(const char *str1, const char *str2, size_t n);

char *s21_strpbrk(const char *str1, const char *str2);
char *s21_strrchr(const char *str, int c);
char *s21_strstr(const char *haystack, const char *needle);