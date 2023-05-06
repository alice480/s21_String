#include ".././test.h"

START_TEST(simple_case_1) {
  char s21_str[SIZE] = "1234567890";
  char str[SIZE] = "1234567890";
  char *s21_ch = s21_memset(s21_str, '0', s21_strlen(s21_str));
  char *ch = memset(str, '0', s21_strlen(str));
  s21_size_t len = s21_strlen(s21_ch);
  ck_assert_int_eq(s21_memcmp(s21_ch, ch, len), 0);
}
END_TEST

START_TEST(simple_case_2) {
  char s21_str[SIZE] = "1234567890";
  char str[SIZE] = "1234567890";
  char *s21_ch = s21_memset(s21_str, '0', 5);
  char *ch = memset(str, '0', 5);
  s21_size_t len = s21_strlen(s21_ch);
  ck_assert_int_eq(s21_memcmp(s21_ch, ch, len), 0);
}
END_TEST

START_TEST(simple_case_3) {
  char s21_str[SIZE] = "";
  char str[SIZE] = "";
  char *s21_ch = s21_memset(s21_str, '\n', 8);
  char *ch = memset(str, '\n', 8);
  s21_size_t len = s21_strlen(s21_ch);
  ck_assert_int_eq(s21_memcmp(s21_ch, ch, len), 0);
}
END_TEST

START_TEST(simple_case_4) {
  char s21_str[SIZE] = "rer2323";
  char str[SIZE] = "rer2323";
  char *s21_ch = s21_memset(s21_str, '!', 3);
  char *ch = memset(str, '!', 3);
  s21_size_t len = s21_strlen(s21_ch);
  ck_assert_int_eq(s21_memcmp(s21_ch, ch, len), 0);
}
END_TEST

START_TEST(simple_case_5) {
  char s21_str[SIZE] = "  \0 23";
  char str[SIZE] = "  \0 23";
  char *s21_ch = s21_memset(s21_str, '+', 30);
  char *ch = memset(str, '+', 30);
  s21_size_t len = s21_strlen(s21_ch);
  ck_assert_int_eq(s21_memcmp(s21_ch, ch, len), 0);
}
END_TEST

START_TEST(simple_case_6) {
  char s21_str[SIZE] = "  \0 23";
  char str[SIZE] = "  \0 23";
  char *s21_ch = s21_memset(s21_str, '+', 1);
  char *ch = memset(str, '+', 1);
  s21_size_t len = s21_strlen(s21_ch);
  ck_assert_int_eq(s21_memcmp(s21_ch, ch, len), 0);
}
END_TEST

START_TEST(simple_case_7) {
  char s21_str[SIZE] = "  \0 23\n% ^11";
  char str[SIZE] = "  \0 23\n% ^11";
  char *s21_ch = s21_memset(s21_str, '\0', 6);
  char *ch = memset(str, '\0', 6);
  s21_size_t len = s21_strlen(s21_ch);
  ck_assert_int_eq(s21_memcmp(s21_ch, ch, len), 0);
}
END_TEST

START_TEST(simple_case_8) {
  char s21_str[SIZE] = "";
  char str[SIZE] = "";
  char *s21_ch = s21_memset(s21_str, '#', SIZE - 1);
  char *ch = memset(str, '#', SIZE - 1);
  s21_size_t len = s21_strlen(s21_ch);
  ck_assert_int_eq(s21_memcmp(s21_ch, ch, len), 0);
}
END_TEST

START_TEST(simple_case_9) {
  char s21_str[SIZE] = "oLd string";
  char str[SIZE] = "oLd string";
  char *s21_ch = s21_memset(s21_str, '\t', SIZE / 2);
  char *ch = memset(str, '\t', SIZE / 2);
  s21_size_t len = s21_strlen(s21_ch);
  ck_assert_int_eq(s21_memcmp(s21_ch, ch, len), 0);
}
END_TEST

START_TEST(simple_case_10) {
  char s21_str[SIZE] = "ahahaha lol";
  char str[SIZE] = "ahahaha lol";
  char *s21_ch = s21_memset(s21_str, '?', 6);
  char *ch = memset(str, '?', 6);
  s21_size_t len = s21_strlen(s21_ch);
  ck_assert_int_eq(s21_memcmp(s21_ch, ch, len), 0);
}
END_TEST

START_TEST(simple_case_11) {
  char s21_str[SIZE] = "ahahaha lol";
  char str[SIZE] = "ahahaha lol";
  char *s21_ch = s21_memset(s21_str, 3, 2);
  char *ch = memset(str, 3, 2);
  s21_size_t len = s21_strlen(s21_ch);
  ck_assert_int_eq(s21_memcmp(s21_ch, ch, len), 0);
}
END_TEST

Suite *test_s21_memset_suite(void) {
  Suite *suite = suite_create(
      "Testing "
      "s21_memset\n--------------------------------------------------"
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
