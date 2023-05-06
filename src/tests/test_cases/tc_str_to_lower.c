#include ".././test.h"

START_TEST(normal_case) {
  char str1[] = "hEllO, WoRLD!";
  char *str2 = (char *)s21_to_lower(str1);
  ck_assert_pstr_eq(str2, "hello, world!");
  free(str2);
}
END_TEST

START_TEST(case_with_digits) {
  char str1[] = "hEllO, WoRLD! 1177";
  char *str2 = (char *)s21_to_lower(str1);
  ck_assert_pstr_eq(str2, "hello, world! 1177");
  free(str2);
}
END_TEST

START_TEST(case_null) {
  char *str = (char *)s21_to_lower(S21_NULL);
  ck_assert_pstr_eq(S21_NULL, str);
}
END_TEST

Suite *test_s21_to_lower(void) {
  Suite *s = suite_create("\033[45m-=S21_TO_LOWER=-\033[0m");
  TCase *tc = tcase_create("test strtok");
  suite_add_tcase(s, tc);
  tcase_add_test(tc, normal_case);
  tcase_add_test(tc, case_with_digits);
  tcase_add_test(tc, case_null);
  return s;
}
