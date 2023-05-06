#include ".././test.h"

START_TEST(simple_case_1) {
  char str[SIZE] = "1234567890";
  char chars[SIZE] = "4890";
  int s21_size = s21_strcspn(str, chars);
  int size = strcspn(str, chars);
  ck_assert_int_eq(s21_size, size);
}
END_TEST

START_TEST(simple_case_2) {
  char str[SIZE] = "";
  char chars[SIZE] = "4890";
  int s21_size = s21_strcspn(str, chars);
  int size = strcspn(str, chars);
  ck_assert_int_eq(s21_size, size);
}
END_TEST

START_TEST(simple_case_3) {
  char str[SIZE] = "rhdfhdw";
  char chars[SIZE] = "";
  int s21_size = s21_strcspn(str, chars);
  int size = strcspn(str, chars);
  ck_assert_int_eq(s21_size, size);
}
END_TEST

START_TEST(simple_case_4) {
  char str[SIZE] = "gwrh57e9t978$^";
  char chars[SIZE] = "$ge";
  int s21_size = s21_strcspn(str, chars);
  int size = strcspn(str, chars);
  ck_assert_int_eq(s21_size, size);
}
END_TEST

START_TEST(simple_case_5) {
  char str[SIZE] = "   \n\0\t$@##@dsg";
  char chars[SIZE] = "\0";
  int s21_size = s21_strcspn(str, chars);
  int size = strcspn(str, chars);
  ck_assert_int_eq(s21_size, size);
}
END_TEST

START_TEST(simple_case_6) {
  char str[SIZE] = "   \n\0\t$@##@dsg";
  char chars[SIZE] = "\t";
  int s21_size = s21_strcspn(str, chars);
  int size = strcspn(str, chars);
  ck_assert_int_eq(s21_size, size);
}
END_TEST

START_TEST(simple_case_7) {
  char str[SIZE] = "Hello world!";
  char chars[SIZE] = "world";
  int s21_size = s21_strcspn(str, chars);
  int size = strcspn(str, chars);
  ck_assert_int_eq(s21_size, size);
}
END_TEST

START_TEST(simple_case_8) {
  char str[SIZE] = "This is ..";
  char chars[SIZE] = ".4";
  int s21_size = s21_strcspn(str, chars);
  int size = strcspn(str, chars);
  ck_assert_int_eq(s21_size, size);
}
END_TEST

START_TEST(simple_case_9) {
  char str[SIZE] = "";
  char chars[SIZE] = "";
  int s21_size = s21_strcspn(str, chars);
  int size = strcspn(str, chars);
  ck_assert_int_eq(s21_size, size);
}
END_TEST

START_TEST(simple_case_10) {
  char str[SIZE] = "Hi-hi ha-ha";
  char chars[SIZE] = "no";
  int s21_size = s21_strcspn(str, chars);
  int size = strcspn(str, chars);
  ck_assert_int_eq(s21_size, size);
}
END_TEST

START_TEST(simple_case_11) {
  char str[SIZE] = "WOW!";
  char chars[SIZE] = "\0";
  int s21_size = s21_strcspn(str, chars);
  int size = strcspn(str, chars);
  ck_assert_int_eq(s21_size, size);
}
END_TEST

Suite *test_s21_strcspn_suite(void) {
  Suite *suite = suite_create(
      "Testing "
      "s21_strcspn\n--------------------------------------------------"
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
  tcase_add_test(tcase_core, simple_case_11);

  suite_add_tcase(suite, tcase_core);

  return suite;
}
