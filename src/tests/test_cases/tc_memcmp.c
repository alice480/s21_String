#include ".././test.h"

START_TEST(simple_case_1) {
  char *str1 = "1234567890";
  char *str2 = "1234567890";
  int s21_res = s21_memcmp(str1, str2, s21_strlen(str1));
  int res = memcmp(str1, str2, s21_strlen(str1));
  ck_assert_int_eq(res, s21_res);
}
END_TEST

START_TEST(simple_case_2) {
  char *str1 = "1234567890";
  char *str2 = "12347890";
  int s21_res = s21_memcmp(str1, str2, s21_strlen(str1));
  int res = memcmp(str1, str2, s21_strlen(str1));
  ck_assert_int_eq(res, s21_res);
}
END_TEST

START_TEST(simple_case_3) {
  char *str1 = "1567890";
  char *str2 = "1234567890";
  int s21_res = s21_memcmp(str1, str2, s21_strlen(str1));
  int res = memcmp(str1, str2, s21_strlen(str1));
  ck_assert_int_eq(res, s21_res);
}
END_TEST

START_TEST(simple_case_4) {
  char *str1 = "";
  char *str2 = "1234567890";
  int s21_res = s21_memcmp(str1, str2, s21_strlen(str1));
  int res = memcmp(str1, str2, s21_strlen(str1));
  ck_assert_int_eq(res, s21_res);
}
END_TEST

START_TEST(simple_case_5) {
  char *str1 = "1234567890";
  char *str2 = "";
  int s21_res = s21_memcmp(str1, str2, s21_strlen(str1));
  int res = memcmp(str1, str2, s21_strlen(str1));
  ck_assert_int_eq(res, s21_res);
}
END_TEST

START_TEST(simple_case_6) {
  char *str1 = "";
  char *str2 = "";
  int s21_res = s21_memcmp(str1, str2, s21_strlen(str1));
  int res = memcmp(str1, str2, s21_strlen(str1));
  ck_assert_int_eq(res, s21_res);
}
END_TEST

START_TEST(simple_case_7) {
  char *str1 = "\0234";
  char *str2 = "dgfdsg";
  int s21_res = s21_memcmp(str1, str2, s21_strlen(str1));
  int res = memcmp(str1, str2, s21_strlen(str1));
  ck_assert_int_eq(res, s21_res);
}
END_TEST

START_TEST(simple_case_8) {
  char *str1 = "\0234";
  char *str2 = "dgfd!@335sg";
  int s21_res = s21_memcmp(str1, str2, s21_strlen(str2));
  int res = memcmp(str1, str2, s21_strlen(str2));
  ck_assert_int_eq(res, s21_res);
}
END_TEST

START_TEST(simple_case_9) {
  char *str1 = "\0234";
  char *str2 = "dgfdsg";
  int s21_res = s21_memcmp(str1, str2, 0);
  int res = memcmp(str1, str2, 0);
  ck_assert_int_eq(res, s21_res);
}
END_TEST

START_TEST(simple_case_10) {
  char *str1 = "32tju6ei7jw_++(sgh";
  char *str2 = "32tju6ei7jw_++(sgh";
  int s21_res = s21_memcmp(str1, str2, 6);
  int res = memcmp(str1, str2, 6);
  ck_assert_int_eq(res, s21_res);
}
END_TEST

START_TEST(str2_null) {
  char *str2 = S21_NULL;
  char *str1 = "32tju6ei7jw_++(sgh";
  int s21_res = s21_memcmp(str1, str2, 0);
  int res = memcmp(str1, str2, 0);
  ck_assert_int_eq(s21_res, res);
}
END_TEST

// START_TEST(null_str) {
//     char *s21_ch = s21_memchr(S21_NULL, 'a', 10);
//     ck_assert_ptr_eq(s21_ch, S21_NULL);
// }
// END_TEST

Suite *test_s21_memcmp_suite(void) {
  Suite *suite = suite_create(
      "Testing "
      "s21_memcmp\n--------------------------------------------------"
      "------------------------------------------");

  TCase *tcase_core = tcase_create("CORE TESTS");

  tcase_add_test(tcase_core, simple_case_1);
  tcase_add_test(tcase_core, simple_case_2);
  tcase_add_test(tcase_core, simple_case_3);
  tcase_add_test(tcase_core, simple_case_4);
  tcase_add_test(tcase_core, simple_case_5);
  tcase_add_test(tcase_core, simple_case_6);
  tcase_add_test(tcase_core, simple_case_7);
  tcase_add_test(tcase_core, simple_case_8);
  tcase_add_test(tcase_core, simple_case_9);
  tcase_add_test(tcase_core, simple_case_10);
  tcase_add_test(tcase_core, str2_null);

  suite_add_tcase(suite, tcase_core);

  return suite;
}
