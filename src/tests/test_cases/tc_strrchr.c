#include ".././test.h"

START_TEST(end_in_empty_line) {
  char str1[] = "";
  char str2 = '\0';

  ck_assert_pstr_eq(s21_strrchr(str1, str2), strrchr(str1, str2));
}
END_TEST

START_TEST(end_in_non_empty_line) {
  char str1[] = "non_empty_string";
  char str2 = '\0';

  ck_assert_pstr_eq(s21_strrchr(str1, str2), strrchr(str1, str2));
}
END_TEST

START_TEST(empty_string) {
  char str1[] = "";
  char str2 = 'f';

  ck_assert_pstr_eq(s21_strrchr(str1, str2), strrchr(str1, str2));
}
END_TEST

START_TEST(normal_case) {
  char str1[] = "stroka one";
  char str2 = 'o';

  ck_assert_pstr_eq(s21_strrchr(str1, str2), strrchr(str1, str2));
}
END_TEST

START_TEST(match_at_end) {
  char str1[] = "stroka one";
  char str2 = 'e';

  ck_assert_pstr_eq(s21_strrchr(str1, str2), strrchr(str1, str2));
}
END_TEST

START_TEST(find_zero) {
  char str1[] = "123456789";
  char str2 = '0';

  ck_assert_pstr_eq(s21_strrchr(str1, str2), strrchr(str1, str2));
}
END_TEST

Suite *test_s21_strrchr(void) {
  Suite *s = suite_create("\033[45m-=S21_STRRCHR=-\033[0m");
  TCase *tc = tcase_create("strrchr_tc");

  tcase_add_test(tc, end_in_empty_line);
  tcase_add_test(tc, end_in_non_empty_line);
  tcase_add_test(tc, empty_string);
  tcase_add_test(tc, normal_case);
  tcase_add_test(tc, match_at_end);
  tcase_add_test(tc, find_zero);

  suite_add_tcase(s, tc);
  return s;
}