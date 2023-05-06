#include ".././test.h"

START_TEST(simple_case_1) {
  char *str = "1234567890";
  char *s21_ch = s21_memchr(str, '5', 10);
  char *ch = memchr(str, '5', 10);
  ck_assert_ptr_eq(s21_ch, ch);
}
END_TEST

START_TEST(simple_case_2) {
  char *str = "1234567890";
  char *s21_ch = s21_memchr(str, 'a', 10);
  char *ch = memchr(str, 'a', 10);
  ck_assert_ptr_eq(s21_ch, ch);
}
END_TEST

START_TEST(simple_case_3) {
  char *str = "1234567890";
  char *s21_ch = s21_memchr(str, '6', 0);
  char *ch = memchr(str, '6', 0);
  ck_assert_ptr_eq(s21_ch, ch);
}
END_TEST

START_TEST(simple_case_4) {
  char *str = "asfАпрен21345436::;*!%;:Ж";
  char *s21_ch = s21_memchr(str, '$', s21_strlen(str));
  char *ch = memchr(str, '$', s21_strlen(str));
  ck_assert_ptr_eq(s21_ch, ch);
}
END_TEST

START_TEST(simple_case_5) {
  char *str = "asf\0Апрен21345436::;*!%;:Ж";
  char *s21_ch = s21_memchr(str, '\0', s21_strlen(str));
  char *ch = memchr(str, '\0', s21_strlen(str));
  ck_assert_ptr_eq(s21_ch, ch);
}
END_TEST

START_TEST(simple_case_6) {
  char *str = "asf\0Апрен21345436::;*!%;:Ж";
  char *s21_ch = s21_memchr(str, 'a', s21_strlen(str));
  char *ch = memchr(str, 'a', s21_strlen(str));
  ck_assert_ptr_eq(s21_ch, ch);
}
END_TEST

START_TEST(simple_case_7) {
  char *str = "asf\0Апрен21345436::;*!%;:Ж";
  char *s21_ch = s21_memchr(str, '!', s21_strlen(str));
  char *ch = memchr(str, '!', s21_strlen(str));
  ck_assert_ptr_eq(s21_ch, ch);
}
END_TEST

START_TEST(simple_case_8) {
  char *str = "asf\0Апрен21345436::;*!%;:Ж";
  char *s21_ch = s21_memchr(str, ':', s21_strlen(str));
  char *ch = memchr(str, ':', s21_strlen(str));
  ck_assert_ptr_eq(s21_ch, ch);
}
END_TEST

START_TEST(simple_case_9) {
  char *str = "asf\0Апрен21345436::;*!%;:Ж";
  char *s21_ch = s21_memchr(str, '*', s21_strlen(str));
  char *ch = memchr(str, '*', s21_strlen(str));
  ck_assert_ptr_eq(s21_ch, ch);
}
END_TEST

START_TEST(simple_case_10) {
  char *str = "asf\0Апрен21345436::;*!%;:Ж";
  char *s21_ch = s21_memchr(str, '%', s21_strlen(str));
  char *ch = memchr(str, '%', s21_strlen(str));
  ck_assert_ptr_eq(s21_ch, ch);
}
END_TEST

START_TEST(null_str) {
  char *s21_ch = s21_memchr(S21_NULL, 'a', 10);
  ck_assert_ptr_eq(s21_ch, S21_NULL);
}
END_TEST

Suite *test_s21_memchr_suite(void) {
  Suite *suite = suite_create(
      "Testing "
      "s21_memchr\n--------------------------------------------------"
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
  tcase_add_test(tcase_core, null_str);

  suite_add_tcase(suite, tcase_core);

  return suite;
}
