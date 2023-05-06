#ifndef SRC_TESTS_TEST_H
#define SRC_TESTS_TEST_H

#include <check.h>
#include <stdio.h>
#include <string.h>

#include ".././s21_sscanf.h"
#include ".././s21_string.h"

Suite *test_s21_strncat(void);
Suite *test_s21_strchr(void);
Suite *test_s21_strncmp(void);
Suite *test_s21_strpbrk(void);
Suite *test_s21_strtok(void);
Suite *test_s21__strstr(void);
Suite *test_s21_strrchr(void);

Suite *test_s21_sscanf(void);

Suite *test_s21_to_lower(void);
Suite *test_s21_insert(void);

Suite *test_s21_memchr_suite(void);
Suite *test_s21_memcmp_suite(void);
Suite *test_s21_memcpy_suite(void);
Suite *test_s21_memset_suite(void);
Suite *test_s21_strcspn_suite(void);
Suite *test_s21_strlen_suite(void);
Suite *test_s21_strncpy_suite(void);
Suite *test_s21_to_upper_suite(void);
Suite *test_s21_trim_suite(void);
Suite *test_s21_sprintf_suite(void);
Suite *test_s21_strerror_suite(void);

#endif  //  SRC_TESTS_TEST_H
