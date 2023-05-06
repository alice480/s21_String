#include ".././test.h"

START_TEST(simple_case_1) {
  char str[SIZE] = "1234567890";
  int len = s21_strlen(str);
  int s21_len = strlen(str);
  ck_assert_int_eq(len, s21_len);
}
END_TEST

START_TEST(simple_case_2) {
  char str[SIZE] = "";
  int len = s21_strlen(str);
  int s21_len = strlen(str);
  ck_assert_int_eq(len, s21_len);
}
END_TEST

START_TEST(simple_case_3) {
  char str[SIZE] = "\04534df";
  int len = s21_strlen(str);
  int s21_len = strlen(str);
  ck_assert_int_eq(len, s21_len);
}
END_TEST

START_TEST(simple_case_4) {
  char str[SIZE] = "1342\0gdfh3";
  int len = s21_strlen(str);
  int s21_len = strlen(str);
  ck_assert_int_eq(len, s21_len);
}
END_TEST

START_TEST(simple_case_5) {
  char str[SIZE] = "\n\n\n\n\n\t4$gth";
  int len = s21_strlen(str);
  int s21_len = strlen(str);
  ck_assert_int_eq(len, s21_len);
}
END_TEST

START_TEST(simple_case_6) {
  char str[SIZE] =
      "Success does not consist in never making mistakes but in never making "
      "the same one a second time.";
  int len = s21_strlen(str);
  int s21_len = strlen(str);
  ck_assert_int_eq(len, s21_len);
}
END_TEST

START_TEST(simple_case_7) {
  char str[SIZE] = "Simplicity is the ultimate sophistication.";
  int len = s21_strlen(str);
  int s21_len = strlen(str);
  ck_assert_int_eq(len, s21_len);
}
END_TEST

START_TEST(simple_case_8) {
  char str[SIZE] =
      "There are three things which the superior man guards against. In "
      "youth...lust. When he is strong...quarrelsomeness. When he is "
      "old...covetousness.";
  int len = s21_strlen(str);
  int s21_len = strlen(str);
  ck_assert_int_eq(len, s21_len);
}
END_TEST

START_TEST(simple_case_9) {
  char str[SIZE] = "Always forgive your enemies; nothing annoys them so much.";
  int len = s21_strlen(str);
  int s21_len = strlen(str);
  ck_assert_int_eq(len, s21_len);
}
END_TEST

START_TEST(simple_case_10) {
  char str[SIZE] =
      "Your time is limited, so don’t waste it living someone else’s life.";
  int len = s21_strlen(str);
  int s21_len = strlen(str);
  ck_assert_int_eq(len, s21_len);
}
END_TEST

START_TEST(simple_case_11) {
  char str[SIZE] =
      "I don't like those cold, precise, perfect people, who, in order not to "
      "speak wrong, never speak at all, and in order not to do wrong never do "
      "anything.";
  int len = s21_strlen(str);
  int s21_len = strlen(str);
  ck_assert_int_eq(len, s21_len);
}
END_TEST

Suite *test_s21_strlen_suite(void) {
  Suite *suite = suite_create(
      "Testing "
      "s21_strlen\n--------------------------------------------------"
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
