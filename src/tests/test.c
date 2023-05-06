#include "test.h"

int main(void) {
  int failed = 0;

  Suite *s21_string_test[] = {
      test_s21_strncat(),        test_s21_strchr(),
      test_s21_strncmp(),        test_s21_strpbrk(),
      test_s21_sscanf(),         test_s21_strtok(),
      test_s21_to_lower(),       test_s21_insert(),
      test_s21__strstr(),        test_s21_strrchr(),
      test_s21_memchr_suite(),   test_s21_memcmp_suite(),
      test_s21_memcpy_suite(),   test_s21_memset_suite(),
      test_s21_strcspn_suite(),  test_s21_strlen_suite(),
      test_s21_strncpy_suite(),  test_s21_to_upper_suite(),
      test_s21_trim_suite(),     test_s21_sprintf_suite(),
      test_s21_strerror_suite(), NULL};

  for (int i = 0; s21_string_test[i] != NULL; i++) {  // (&& failed == 0)
    SRunner *runner = srunner_create(s21_string_test[i]);

    srunner_set_fork_status(runner, CK_NOFORK);
    srunner_run_all(runner, CK_NORMAL);

    failed += srunner_ntests_failed(runner);
    srunner_free(runner);
    printf("\n");
  }
  printf("========= FAILED: %d =========\n", failed);

  return failed == 0 ? 0 : 1;
}
