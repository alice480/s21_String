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

int s21_sprintf(char* s, const char* format, ...);
int s21_sscanf(const char* str, const char* format, ...);
void* s21_memchr(const void* str, int c, s21_size_t n);
int s21_memcmp(const void* str1, const void* str2, s21_size_t n);
void* s21_memcpy(void* dest, const void* src, s21_size_t n);
void* s21_memmove(void* dest, const void* src, s21_size_t n);
void* s21_memset(void* str, int c, s21_size_t n);
int s21_strcmp(const char* str1, const char* str2);
int s21_strncmp(const char* str1, const char* str2, s21_size_t n);
char* s21_strcat(char* dest, const char* src);
char* s21_strncat(char* dest, const char* src, s21_size_t n);
char* s21_strcpy(char* dest, const char* src);
char* s21_strncpy(char* dest, const char* src, s21_size_t n);
char* s21_strstr(const char* haystack, const char* needle);
s21_size_t s21_strcspn(const char* str1, const char* str2);
s21_size_t s21_strspn(const char* str1, const char* str2);
char* s21_strrchr(const char* str, int c);
char* s21_strchr(const char* str, int c);
char* s21_strtok(char* str, const char* delim);
char* s21_strpbrk(const char* str1, const char* str2);
s21_size_t s21_strlen(const char* str);
char* s21_strerror(int errnum);
char* int_to_char(int errnum);
void* s21_to_upper(const char* str);
void* s21_to_lower(const char* str);
void* s21_insert(const char* src, const char* str, s21_size_t start_index);
void* s21_trim(const char* src, const char* trim_chars);
int index_left_part(const char* src, const char* trim_chars, char* trimmed_str);
int index_right_part(const char* src, const char* trim_chars,
                     char* trimmed_str);
int format_string_parcing(const char** format, Format_string* format_string,
                          int* used_args);
int string_processing(const char* str, const char* format,
                      va_list assign_variables, Format_string* format_string);
int writing_formatted(Format_string* format_string, char** str,
                      va_list assign_variables, int* used_args);
int write_to_char(Format_string* format_string, char** str,
                  va_list assign_variables, int* used_args);
int write_to_str(Format_string* format_string, char** str,
                 va_list assign_variables, int* used_args);
int write_to_int(Format_string* format_string, char** str,
                 va_list assign_variables, int* used_args);
long long s21_atoi(char* buffer, Format_string* format_string);
long unsigned conv_8_to_10(char* buffer, Format_string* format_string);
long unsigned conv_16_to_10(char* buffer, Format_string* format_string);
int write_to_float(Format_string* format_string, char** str,
                   va_list assign_variables, int* used_args);
long double s21_strtold(char* buffer, Format_string* format_string);