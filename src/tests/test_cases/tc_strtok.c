#include ".././test.h"

START_TEST(normal_case) {
  char str4_1[] = "testing strtok and string.h";
  char str4_2[] = "testing strtok and string.h";
  char del4[3] = ". ";
  char *nstr_1, *nstr_2;
  nstr_1 = strtok(str4_1, del4);
  nstr_2 = s21_strtok(str4_2, del4);
  while (nstr_1 != S21_NULL) {
    ck_assert_pstr_eq(nstr_1, nstr_2);
    nstr_1 = strtok(S21_NULL, del4);
    nstr_2 = s21_strtok(S21_NULL, del4);
  }
}
END_TEST

START_TEST(separator_at_end) {
  char str4_1[] = "/testing/strtok/and/s21_strtok/";
  char str4_2[] = "/testing/strtok/and/s21_strtok/";
  char del4[3] = "/";
  char *nstr_1, *nstr_2;
  nstr_1 = strtok(str4_1, del4);
  nstr_2 = s21_strtok(str4_2, del4);
  while (nstr_1 != S21_NULL) {
    ck_assert_pstr_eq(nstr_1, nstr_2);
    nstr_1 = strtok(S21_NULL, del4);
    nstr_2 = s21_strtok(S21_NULL, del4);
  }
}
END_TEST

START_TEST(separators_one_after_other) {
  char str4_1[] = ". . testing s21_strtok and string.h";
  char str4_2[] = ". . testing s21_strtok and string.h";
  char del4[3] = ". ";
  char *nstr_1, *nstr_2;
  nstr_1 = strtok(str4_1, del4);
  nstr_2 = s21_strtok(str4_2, del4);
  while (nstr_1 != S21_NULL) {
    ck_assert_pstr_eq(nstr_1, nstr_2);
    nstr_1 = strtok(S21_NULL, del4);
    nstr_2 = s21_strtok(S21_NULL, del4);
  }
}
END_TEST

Suite *test_s21_strtok(void) {
  Suite *s = suite_create("\033[45m-=S21_STRTOK=-\033[0m");
  TCase *tc = tcase_create("test strtok");
  suite_add_tcase(s, tc);
  tcase_add_test(tc, normal_case);
  tcase_add_test(tc, separator_at_end);
  tcase_add_test(tc, separators_one_after_other);
  return s;
}