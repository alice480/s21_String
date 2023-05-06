#include ".././test.h"

START_TEST(simple_case_1) {
  char s21_str1[SIZE] = "1234567890";
  char *s21_str2 = "54hgd";
  char *s21_ch = s21_memcpy(s21_str1, s21_str2, s21_strlen(s21_str2));
  char str1[SIZE] = "1234567890";
  char *str2 = "54hgd";
  char *ch = memcpy(str1, str2, s21_strlen(str2));
  s21_size_t s21_len = s21_strlen(s21_ch);
  s21_size_t len = s21_strlen(ch);
  s21_size_t t_len = len > s21_len ? len : s21_len;
  ck_assert_int_eq(s21_memcmp(s21_ch, ch, t_len), 0);
}
END_TEST

START_TEST(simple_case_2) {
  char s21_str1[SIZE] = "1234567890";
  char *s21_str2 = "54hgd";
  char *s21_ch = s21_memcpy(s21_str1, s21_str2, s21_strlen(s21_str1));
  char str1[SIZE] = "1234567890";
  char *str2 = "54hgd";
  char *ch = memcpy(str1, str2, s21_strlen(str1));
  s21_size_t s21_len = s21_strlen(s21_ch);
  s21_size_t len = s21_strlen(ch);
  s21_size_t t_len = len > s21_len ? len : s21_len;
  ck_assert_int_eq(s21_memcmp(s21_ch, ch, t_len), 0);
}
END_TEST

START_TEST(simple_case_3) {
  char s21_str1[SIZE] = "1234567890";
  char *s21_str2 = "54hgd";
  char *s21_ch = s21_memcpy(s21_str1, s21_str2, 0);
  char str1[SIZE] = "1234567890";
  char *str2 = "54hgd";
  char *ch = memcpy(str1, str2, 0);
  s21_size_t s21_len = s21_strlen(s21_ch);
  s21_size_t len = s21_strlen(ch);
  s21_size_t t_len = len > s21_len ? len : s21_len;
  ck_assert_int_eq(s21_memcmp(s21_ch, ch, t_len), 0);
}
END_TEST

START_TEST(simple_case_4) {
  char s21_str1[SIZE] = "1234567890";
  char *s21_str2 = "\0";
  char *s21_ch = s21_memcpy(s21_str1, s21_str2, s21_strlen(s21_str2));
  char str1[SIZE] = "1234567890";
  char *str2 = "\0";
  char *ch = memcpy(str1, str2, s21_strlen(str2));
  s21_size_t s21_len = s21_strlen(s21_ch);
  s21_size_t len = s21_strlen(ch);
  s21_size_t t_len = len > s21_len ? len : s21_len;
  ck_assert_int_eq(s21_memcmp(s21_ch, ch, t_len), 0);
}
END_TEST

START_TEST(simple_case_5) {
  char *s21_str1 = "1dgsg890";
  char s21_str2[SIZE] = "54hgd";
  char *s21_ch = s21_memcpy(s21_str2, s21_str1, s21_strlen(s21_str2));
  char *str1 = "1dgsg890";
  char str2[SIZE] = "54hgd";
  char *ch = memcpy(str2, str1, s21_strlen(str2));
  s21_size_t s21_len = s21_strlen(s21_ch);
  s21_size_t len = s21_strlen(ch);
  s21_size_t t_len = len > s21_len ? len : s21_len;
  ck_assert_int_eq(s21_memcmp(s21_ch, ch, t_len), 0);
}
END_TEST

START_TEST(simple_case_6) {
  char *s21_str1 = "+_:>?|fbnux@$1";
  char s21_str2[SIZE] = "";
  char *s21_ch = s21_memcpy(s21_str2, s21_str1, s21_strlen(s21_str2));
  char *str1 = "+_:>?|fbnux@$1";
  char str2[SIZE] = "";
  char *ch = memcpy(str2, str1, s21_strlen(str2));
  s21_size_t s21_len = s21_strlen(s21_ch);
  s21_size_t len = s21_strlen(ch);
  s21_size_t t_len = len > s21_len ? len : s21_len;
  ck_assert_int_eq(s21_memcmp(s21_ch, ch, t_len), 0);
}
END_TEST

START_TEST(simple_case_7) {
  char *s21_str1 = "";
  char s21_str2[SIZE] = "";
  char *s21_ch = s21_memcpy(s21_str2, s21_str1, s21_strlen(s21_str2));
  char *str1 = "";
  char str2[SIZE] = "";
  char *ch = memcpy(str2, str1, s21_strlen(str2));
  s21_size_t s21_len = s21_strlen(s21_ch);
  s21_size_t len = s21_strlen(ch);
  s21_size_t t_len = len > s21_len ? len : s21_len;
  ck_assert_int_eq(s21_memcmp(s21_ch, ch, t_len), 0);
}
END_TEST

START_TEST(simple_case_8) {
  char *s21_str1 = "";
  char s21_str2[SIZE] = "FGKJNH*(&^62)";
  char *s21_ch = s21_memcpy(s21_str2, s21_str1, s21_strlen(s21_str2));
  char *str1 = "";
  char str2[SIZE] = "FGffffffffKJNH*(&^62)";
  char *ch = memcpy(str2, str1, s21_strlen(str2));
  s21_size_t s21_len = s21_strlen(s21_ch);
  s21_size_t len = s21_strlen(ch);
  s21_size_t t_len = len > s21_len ? len : s21_len;
  ck_assert_int_eq(memcmp(s21_ch, ch, t_len), 0);
}
END_TEST

START_TEST(simple_case_9) {
  char s21_str1[SIZE] = "126788   !!!!90";
  char *s21_str2 = "\0{}fe";
  char *s21_ch = s21_memcpy(s21_str1, s21_str2, s21_strlen(s21_str2));
  char str1[SIZE] = "126788   !!!!90";
  char *str2 = "\0{}fe";
  char *ch = memcpy(str1, str2, s21_strlen(str2));
  s21_size_t s21_len = s21_strlen(s21_ch);
  s21_size_t len = s21_strlen(ch);
  s21_size_t t_len = len > s21_len ? len : s21_len;
  ck_assert_int_eq(s21_memcmp(s21_ch, ch, t_len), 0);
}
END_TEST

START_TEST(simple_case_10) {
  char s21_str1[SIZE] = {'\0'};
  char *s21_str2 = "It is new string!";
  char *s21_ch = s21_memcpy(s21_str1, s21_str2, s21_strlen(s21_str2));
  char str1[SIZE] = {'\0'};
  char *str2 = "It is new string!";
  char *ch = memcpy(str1, str2, s21_strlen(str2));
  s21_size_t s21_len = s21_strlen(s21_ch);
  s21_size_t len = s21_strlen(ch);
  s21_size_t t_len = len > s21_len ? len : s21_len;
  ck_assert_int_eq(s21_memcmp(s21_ch, ch, t_len), 0);
}
END_TEST

START_TEST(simple_case_11) {
  char s21_str1[SIZE] = {'\0'};
  char *s21_str2 = "It is new string!";
  char *s21_ch = s21_memcpy(s21_str1, s21_str2, 0);
  char str1[SIZE] = {'\0'};
  char *str2 = "It is new string!";
  char *ch = memcpy(str1, str2, 0);
  s21_size_t s21_len = s21_strlen(s21_ch);
  s21_size_t len = s21_strlen(ch);
  s21_size_t t_len = len > s21_len ? len : s21_len;
  ck_assert_int_eq(s21_memcmp(s21_ch, ch, t_len), 0);
}
END_TEST

Suite *test_s21_memcpy_suite(void) {
  Suite *suite = suite_create(
      "Testing "
      "s21_memcpy\n--------------------------------------------------"
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
