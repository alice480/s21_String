#include ".././test.h"

START_TEST(simple_case_1) {
  for (int i = -20; i < 160; i++) {
    ck_assert_str_eq(strerror(i), s21_strerror(i));
  }
}
END_TEST

Suite *test_s21_strerror_suite(void) {
  Suite *suite = suite_create(
      "Testing "
      "s21_strerror\n--------------------------------------------------"
      "------------------------------------------");

  TCase *tcase_core = tcase_create("CORE TESTS");

  tcase_add_test(tcase_core, simple_case_1);
  //   tcase_add_test(tcase_core, simple_case_1);

  suite_add_tcase(suite, tcase_core);

  return suite;
}
