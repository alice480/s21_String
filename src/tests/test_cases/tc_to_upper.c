#include ".././test.h"

START_TEST(simple_case_1) {
  char str[SIZE] = "12d56789fa0";
  char *up_str = "12D56789FA0";
  char *s21_up_str = s21_to_upper(str);
  s21_size_t len = s21_strlen(s21_up_str);
  ck_assert_int_eq(s21_memcmp(s21_up_str, up_str, len), 0);
  free(s21_up_str);
}
END_TEST

START_TEST(simple_case_2) {
  char str[SIZE] = "addgjhs11";
  char *up_str = "ADDGJHS11";
  char *s21_up_str = s21_to_upper(str);
  s21_size_t len = s21_strlen(s21_up_str);
  ck_assert_int_eq(s21_memcmp(s21_up_str, up_str, len), 0);
  free(s21_up_str);
}
END_TEST

START_TEST(simple_case_3) {
  char str[SIZE] = "!#^$afdsAKT4";
  char *up_str = "!#^$AFDSAKT4";
  char *s21_up_str = s21_to_upper(str);
  s21_size_t len = s21_strlen(s21_up_str);
  ck_assert_int_eq(s21_memcmp(s21_up_str, up_str, len), 0);
  free(s21_up_str);
}
END_TEST

START_TEST(simple_case_4) {
  char str[SIZE] = "aDFDSfsf";
  char *up_str = "ADFDSFSF";
  char *s21_up_str = s21_to_upper(str);
  s21_size_t len = s21_strlen(s21_up_str);
  ck_assert_int_eq(s21_memcmp(s21_up_str, up_str, len), 0);
  free(s21_up_str);
}
END_TEST

START_TEST(simple_case_5) {
  char str[SIZE] = "as";
  char *up_str = "AS";
  char *s21_up_str = s21_to_upper(str);
  s21_size_t len = s21_strlen(up_str);
  ck_assert_int_eq(s21_memcmp(s21_up_str, up_str, len), 0);
  free(s21_up_str);
}
END_TEST

START_TEST(simple_case_6) {
  char str[SIZE] = "21546#%";
  char *up_str = "21546#%";
  char *s21_up_str = s21_to_upper(str);
  s21_size_t len = s21_strlen(s21_up_str);
  ck_assert_int_eq(s21_memcmp(s21_up_str, up_str, len), 0);
  free(s21_up_str);
}
END_TEST

START_TEST(simple_case_7) {
  char str[SIZE] = "Hello world!";
  char *up_str = "HELLO WORLD!";
  char *s21_up_str = s21_to_upper(str);
  s21_size_t len = s21_strlen(s21_up_str);
  ck_assert_int_eq(s21_memcmp(s21_up_str, up_str, len), 0);
  free(s21_up_str);
}
END_TEST

START_TEST(simple_case_8) {
  char str[SIZE] = "No two persons ever read the same book.";
  char *up_str = "NO TWO PERSONS EVER READ THE SAME BOOK.";
  char *s21_up_str = s21_to_upper(str);
  s21_size_t len = s21_strlen(s21_up_str);
  ck_assert_int_eq(s21_memcmp(s21_up_str, up_str, len), 0);
  free(s21_up_str);
}
END_TEST

// START_TEST(simple_case_9) {
//   char str[SIZE] = "Love the life you live, and live the life you love.";
//   char *up_str = "LOVE THE LIFE YOU LIVE, AND LIVE THE LIFE YOU LOVE.";
//   char *s21_up_str = s21_to_upper(str);
//   s21_size_t len = s21_strlen(s21_up_str);
//   ck_assert_int_eq(s21_memcmp(s21_up_str, up_str, len), 0);
//   free(s21_up_str);
// }
// END_TEST

START_TEST(simple_case_10) {
  char str[SIZE] =
      "Build your own dreams, or someone else will hire you to build theirs.";
  char *up_str =
      "BUILD YOUR OWN DREAMS, OR SOMEONE ELSE WILL HIRE YOU TO BUILD THEIRS.";
  char *s21_up_str = s21_to_upper(str);
  s21_size_t len = s21_strlen(s21_up_str);
  ck_assert_int_eq(s21_memcmp(s21_up_str, up_str, len), 0);
  free(s21_up_str);
}
END_TEST

START_TEST(simple_case_11) {
  char str[SIZE] =
      "It is not the strongest of the species that survives, nor the most "
      "intelligent, but the one most responsive to change.";
  char *up_str =
      "IT IS NOT THE STRONGEST OF THE SPECIES THAT SURVIVES, NOR THE MOST "
      "INTELLIGENT, BUT THE ONE MOST RESPONSIVE TO CHANGE.";
  char *s21_up_str = s21_to_upper(str);
  s21_size_t len = s21_strlen(s21_up_str);
  ck_assert_int_eq(s21_memcmp(s21_up_str, up_str, len), 0);
  free(s21_up_str);
}
END_TEST

START_TEST(null_str) {
  char *s21_up_str = s21_to_upper(NULL);
  ck_assert_ptr_null(s21_up_str);
}
END_TEST

Suite *test_s21_to_upper_suite(void) {
  Suite *suite = suite_create(
      "Testing "
      "s21_to_upper\n--------------------------------------------------"
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
  // tcase_add_test(tcase_core, simple_case_9);
  tcase_add_test(tcase_core, simple_case_10);
  tcase_add_test(tcase_core, simple_case_11);
  tcase_add_test(tcase_core, null_str);

  suite_add_tcase(suite, tcase_core);

  return suite;
}
