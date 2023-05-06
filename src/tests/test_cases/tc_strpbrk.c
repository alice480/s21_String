#include <stdio.h>

#include ".././test.h"

START_TEST(presenting_symbol) {
  // const char str1[5] = "abcdf";
  const char str2[5] = "efghi";
  const char symbols1[2] = "ae";
  // char symbols2[2] = "if";
  ck_assert_str_eq(strpbrk(str2, symbols1), s21_strpbrk(str2, symbols1));
  // ck_assert_str_eq(strpbrk(str1, symbols1), s21_strpbrk(str1, symbols1));
  // ck_assert_str_eq(strpbrk(str1, symbols2), s21_strpbrk(str1, symbols2));
  // ck_assert_str_eq(strpbrk(str2, symbols2), s21_strpbrk(str2, symbols2));
}
END_TEST

START_TEST(missing_symbol) {
  char str[5] = "abcdf";
  char symbols[5] = "dwhy?";
  ck_assert_pstr_eq(NULL, s21_strpbrk(str, symbols));
}
END_TEST

Suite *test_s21_strpbrk(void) {
  Suite *s = suite_create("\033[45m-=S21_STRPBRK=-\033[0m");
  TCase *tc = tcase_create("test strncat");
  suite_add_tcase(s, tc);
  tcase_add_test(tc, presenting_symbol);
  tcase_add_test(tc, missing_symbol);
  return s;
}