#include ".././test.h"

START_TEST(strchr_normal_values) {
  ck_assert_str_eq(strchr("normal", 'r'), s21_strchr("normal", 'r'));
  ck_assert_str_eq(strchr("left", 'l'), s21_strchr("left", 'l'));
  ck_assert_str_eq(strchr("right", 't'), s21_strchr("right", 't'));
  ck_assert_str_eq(strchr("duplicated", 'd'), s21_strchr("duplicated", 'd'));
}
END_TEST

START_TEST(strchr_missing_symbol) {
  ck_assert_pstr_eq(strchr("normal", 'u'), s21_strchr("normal", 'u'));
}
END_TEST

Suite *test_s21_strchr(void) {
  Suite *s = suite_create("\033[45m-=S21_STRCHR=-\033[0m");
  TCase *tc = tcase_create("test strchr");
  suite_add_tcase(s, tc);
  tcase_add_test(tc, strchr_normal_values);
  tcase_add_test(tc, strchr_missing_symbol);
  return s;
}