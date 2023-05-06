#include ".././test.h"

START_TEST(simple_case_1) {
  char str[SIZE] = "12d56789fa0";
  char *chars = "2a170";
  char *s21_str_trim = s21_trim(str, chars);
  char *str_trim = "d56789f";
  s21_size_t len = s21_strlen(str_trim);
  ck_assert_int_eq(s21_memcmp(s21_str_trim, str_trim, len), 0);
  free(s21_str_trim);
}
END_TEST

START_TEST(simple_case_2) {
  char str[SIZE] = " Hello world! ";
  char *chars = "";
  char *s21_str_trim = s21_trim(str, chars);
  char *str_trim = "Hello world!";
  s21_size_t len = s21_strlen(str_trim);
  ck_assert_int_eq(s21_memcmp(s21_str_trim, str_trim, len), 0);
  free(s21_str_trim);
}
END_TEST

START_TEST(simple_case_3) {
  char str[SIZE] = "Hello world! ";
  char *chars = "";
  char *s21_str_trim = s21_trim(str, chars);
  char *str_trim = "Hello world!";
  s21_size_t len = s21_strlen(str_trim);
  ck_assert_int_eq(s21_memcmp(s21_str_trim, str_trim, len), 0);
  free(s21_str_trim);
}
END_TEST

START_TEST(simple_case_4) {
  char str[SIZE] = " Hello world!";
  char *chars = "";
  char *s21_str_trim = s21_trim(str, chars);
  char *str_trim = "Hello world!";
  s21_size_t len = s21_strlen(str_trim);
  ck_assert_int_eq(s21_memcmp(s21_str_trim, str_trim, len), 0);
  free(s21_str_trim);
}
END_TEST

START_TEST(simple_case_5) {
  char str[SIZE] = " Hello world! ";
  char *s21_str_trim = s21_trim(str, S21_NULL);
  char *str_trim = "Hello world!";
  s21_size_t len = s21_strlen(str_trim);
  ck_assert_int_eq(s21_memcmp(s21_str_trim, str_trim, len), 0);
  free(s21_str_trim);
}
END_TEST

START_TEST(simple_case_6) {
  char str[SIZE] = "#!@What?!f";
  char *chars = "@!f#";
  char *s21_str_trim = s21_trim(str, chars);
  char *str_trim = "What?";
  s21_size_t len = s21_strlen(str_trim);
  ck_assert_int_eq(s21_memcmp(s21_str_trim, str_trim, len), 0);
  free(s21_str_trim);
}
END_TEST

START_TEST(simple_case_7) {
  char str[SIZE] = "?Hi-hi, ha-ha!";
  char *chars = "?!i- ";
  char *s21_str_trim = s21_trim(str, chars);
  char *str_trim = "Hi-hi, ha-ha";
  s21_size_t len = s21_strlen(str_trim);
  ck_assert_int_eq(s21_memcmp(s21_str_trim, str_trim, len), 0);
  free(s21_str_trim);
}
END_TEST

START_TEST(simple_case_8) {
  char str[SIZE] = "Hello, Mark!";
  char *chars = "H l!o,e";
  char *s21_str_trim = s21_trim(str, chars);
  char *str_trim = "Mark";
  s21_size_t len = s21_strlen(str_trim);
  ck_assert_int_eq(s21_memcmp(s21_str_trim, str_trim, len), 0);
  free(s21_str_trim);
}
END_TEST

START_TEST(simple_case_9) {
  char str[SIZE] = "Hm, Volodya, it is not possible!";
  char *chars = " H,m";
  char *s21_str_trim = s21_trim(str, chars);
  char *str_trim = "Volodya, it is not possible!";
  s21_size_t len = s21_strlen(str_trim);
  ck_assert_int_eq(s21_memcmp(s21_str_trim, str_trim, len), 0);
  free(s21_str_trim);
}
END_TEST

START_TEST(simple_case_10) {
  char str[SIZE] = "Lalalalalala Lol blalbla";
  char *chars = "lLab ";
  char *s21_str_trim = s21_trim(str, chars);
  char *str_trim = "o";
  s21_size_t len = s21_strlen(str_trim);
  ck_assert_int_eq(s21_memcmp(s21_str_trim, str_trim, len), 0);
  free(s21_str_trim);
}
END_TEST

START_TEST(str_null) {
  char *chars = "lLab ";
  char *s21_str_trim = s21_trim(S21_NULL, chars);
  ck_assert_ptr_null(s21_str_trim);
}
END_TEST

Suite *test_s21_trim_suite(void) {
  Suite *suite = suite_create(
      "Testing "
      "s21_to_trim\n--------------------------------------------------"
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
  tcase_add_test(tcase_core, str_null);

  suite_add_tcase(suite, tcase_core);

  return suite;
}
