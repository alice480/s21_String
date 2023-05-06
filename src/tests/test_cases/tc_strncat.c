#include ".././test.h"

START_TEST(normal_values_conditions) {
  char dest[20] = "first";
  char source[10] = "second";
  ck_assert_str_eq(strncat(dest, source, 6), s21_strncat(dest, source, 6));
}
END_TEST

START_TEST(n_less_then_source) {
  char dest[20] = "first";
  char source[10] = "second";
  ck_assert_str_eq(strncat(dest, source, 3), s21_strncat(dest, source, 3));
}
END_TEST

START_TEST(n_more_then_source) {
  char dest[20] = "first";
  char source[10] = "second";
  ck_assert_str_eq(strncat(dest, source, 10), s21_strncat(dest, source, 10));
}
END_TEST

START_TEST(single_length_source) {
  char dest[5] = "first";
  char source[6] = "N";
  ck_assert_str_eq(strncat(dest, source, 1), s21_strncat(dest, source, 1));
}
END_TEST

Suite *test_s21_strncat(void) {
  Suite *s = suite_create("\033[45m-=S21_STRNCAT=-\033[0m");
  TCase *tc = tcase_create("test strncat");
  suite_add_tcase(s, tc);
  tcase_add_test(tc, normal_values_conditions);
  tcase_add_test(tc, n_less_then_source);
  tcase_add_test(tc, n_more_then_source);
  tcase_add_test(tc, single_length_source);
  return s;
}