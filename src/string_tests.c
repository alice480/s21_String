#include <check.h>
#include <string.h>
#define BUFF_SIZE 512
#include <stdio.h>

#include "s21_string.h"
#define s21_NULL S21_NULL

START_TEST(strlen_1) {
  char *str_1 = "LUGANO\0";
  ck_assert_int_eq(strlen(str_1), s21_strlen(str_1));
}
END_TEST

START_TEST(strlen_2) {
  char *str_2 = "LUGANO THE \0BEST!!!";
  ck_assert_int_eq(strlen(str_2), s21_strlen(str_2));
}
END_TEST

START_TEST(strlen_3) {
  char *str_3 = "\0";
  ck_assert_int_eq(strlen(str_3), s21_strlen(str_3));
}
END_TEST

START_TEST(strcat_1) {
  char b1[1024] = "";
  char b11[1024] = "";
  char str_1_2[1024] = "LUGANO THE BEST!";
  ck_assert_pstr_eq(strcat(b1, str_1_2), s21_strcat(b11, str_1_2));
}
END_TEST

START_TEST(strcat_2) {
  char b2[1024] = "THE";
  char b22[1024] = "THE";
  char str_2_2[1024] = " BEST!!";
  ck_assert_pstr_eq(strcat(b2, str_2_2), s21_strcat(b22, str_2_2));
}
END_TEST

START_TEST(strcat_3) {
  char b3[1024] = "777";
  char b33[1024] = "777";
  char str_3_2[1024] = " LUGANO!";
  ck_assert_pstr_eq(strcat(b3, str_3_2), s21_strcat(b33, str_3_2));
}
END_TEST

START_TEST(strcmp_1) {
  char *str_1_1 = "LUGANO!";
  char *str_1_2 = "LUGANO!";
  int s21_c = s21_strcmp(str_1_1, str_1_2);
  int s_c = strcmp(str_1_1, str_1_2);
  if (s21_c > 0)
    s21_c = 1;
  else if (s21_c < 0)
    s21_c = -1;

  if (s_c > 0)
    s_c = 1;
  else if (s_c < 0)
    s_c = -1;
  ck_assert_int_eq(s21_c, s_c);
}
END_TEST

START_TEST(strcmp_2) {
  char *str_2_1 = "LUGANO THE BEST!";
  char *str_2_2 = "LUGANO OF THE BEST!";
  int s21_c = s21_strcmp(str_2_1, str_2_2);
  int s_c = strcmp(str_2_1, str_2_2);
  if (s21_c > 0)
    s21_c = 1;
  else if (s21_c < 0)
    s21_c = -1;

  if (s_c > 0)
    s_c = 1;
  else if (s_c < 0)
    s_c = -1;
  ck_assert_int_eq(s21_c, s_c);
}
END_TEST

START_TEST(strcmp_3) {
  char *str_3_1 = "LUGANO OF THE BEST!!!!!";
  char *str_3_2 = "LUGANO!";
  int s21_c = s21_strcmp(str_3_1, str_3_2);
  int s_c = strcmp(str_3_1, str_3_2);
  if (s21_c > 0)
    s21_c = 1;
  else if (s21_c < 0)
    s21_c = -1;

  if (s_c > 0)
    s_c = 1;
  else if (s_c < 0)
    s_c = -1;
  ck_assert_int_eq(s21_c, s_c);
}
END_TEST

START_TEST(strncat_1) {
  s21_size_t n1 = 2;
  char b1[1024] = "";
  char b11[1024] = "";
  char str_1_2[1024] = "LUGANO THE BEST!";
  ck_assert_pstr_eq(strncat(b1, str_1_2, n1), s21_strncat(b11, str_1_2, n1));
}
END_TEST

START_TEST(strncat_2) {
  s21_size_t n2 = 2;
  char b2[1024] = "THE";
  char b22[1024] = "THE";
  char str_2_2[1024] = " BEST!!";
  ck_assert_pstr_eq(strncat(b2, str_2_2, n2), s21_strncat(b22, str_2_2, n2));
}
END_TEST

START_TEST(strncat_3) {
  s21_size_t n3 = 2;
  char b3[1024] = "777";
  char b33[1024] = "777";
  char str_3_2[1024] = " LUGANO!";
  ck_assert_pstr_eq(strncat(b3, str_3_2, n3), s21_strncat(b33, str_3_2, n3));
}
END_TEST

START_TEST(strncmp_1) {
  s21_size_t n = 3;
  char *str_1_1 = "LUGANO!";
  char *str_1_2 = "LUGANO!";
  int s21_c = s21_strncmp(str_1_1, str_1_2, n);
  int s_c = strncmp(str_1_1, str_1_2, n);
  if (s21_c > 0)
    s21_c = 1;
  else if (s21_c < 0)
    s21_c = -1;

  if (s_c > 0)
    s_c = 1;
  else if (s_c < 0)
    s_c = -1;
  ck_assert_int_eq(s21_c, s_c);
}
END_TEST

START_TEST(strncmp_2) {
  s21_size_t n = 3;
  char *str_2_1 = "LUGANO THE BEST!";
  char *str_2_2 = "LU GANO OF THE BEST!!";
  int s21_c = s21_strncmp(str_2_1, str_2_2, n);
  int s_c = strncmp(str_2_1, str_2_2, n);
  if (s21_c > 0)
    s21_c = 1;
  else if (s21_c < 0)
    s21_c = -1;

  if (s_c > 0)
    s_c = 1;
  else if (s_c < 0)
    s_c = -1;
  ck_assert_int_eq(s21_c, s_c);
}
END_TEST

START_TEST(strncmp_3) {
  s21_size_t n = 3;
  char *str_3_1 = " LUGANO OF THE BEST!!";
  char *str_3_2 = "LUGANO!";
  int s21_c = s21_strncmp(str_3_1, str_3_2, n);
  int s_c = strncmp(str_3_1, str_3_2, n);
  if (s21_c > 0)
    s21_c = 1;
  else if (s21_c < 0)
    s21_c = -1;

  if (s_c > 0)
    s_c = 1;
  else if (s_c < 0)
    s_c = -1;
  ck_assert_int_eq(s21_c, s_c);
}
END_TEST

START_TEST(memcmp_1) {
  s21_size_t n1 = 3;
  void *str_1_1 = "LUGANO!";
  void *str_1_2 = "LUGANO!";
  ck_assert_int_eq(memcmp(str_1_1, str_1_2, n1),
                   s21_memcmp(str_1_1, str_1_2, n1));
}
END_TEST

START_TEST(memcmp_2) {
  s21_size_t n2 = 3;
  void *str_2_1 = "LUGANO THE BEST!";
  void *str_2_2 = "LU GANO OF THE BEST!!";
  ck_assert_int_eq(memcmp(str_2_1, str_2_2, n2),
                   s21_memcmp(str_2_1, str_2_2, n2));
}
END_TEST

START_TEST(memcmp_3) {
  s21_size_t n3 = 3;
  void *str_3_1 = " LUGANO OF THE BEST!!";
  void *str_3_2 = "LUGANO!";
  ck_assert_int_eq(memcmp(str_3_1, str_3_2, n3),
                   s21_memcmp(str_3_1, str_3_2, n3));
}
END_TEST

START_TEST(memset_1) {
  s21_size_t n1 = 6;
  int c1 = '7';
  char b1[1024] = "LUGANO THE BEST!";
  char b11[1024] = "LUGANO THE BEST!";
  ck_assert_pstr_eq(memset(b1, c1, n1), s21_memset(b11, c1, n1));
}
END_TEST

START_TEST(memset_2) {
  s21_size_t n2 = 4;
  int c2 = '4';
  char b2[1024] = " BEST!!";
  char b22[1024] = " BEST!!";
  ck_assert_pstr_eq(memset(b2, c2, n2), s21_memset(b22, c2, n2));
}
END_TEST

START_TEST(memset_3) {
  s21_size_t n3 = 6;
  int c3 = '3';
  char b3[1024] = " LUGANO!";
  char b33[1024] = " LUGANO!";
  ck_assert_pstr_eq(memset(b3, c3, n3), s21_memset(b33, c3, n3));
}
END_TEST

START_TEST(strcpy_1) {
  char b1[1024] = "";
  char b11[1024] = "";
  char str_1_2[1024] = "LUGANO THE BEST!";
  ck_assert_pstr_eq(strcpy(b1, str_1_2), s21_strcpy(b11, str_1_2));
}
END_TEST

START_TEST(strcpy_2) {
  char b2[1024] = "";
  char b22[1024] = "";
  char str_2_2[1024] = "THE OF \0BEST!!";
  ck_assert_pstr_eq(strcpy(b2, str_2_2), s21_strcpy(b22, str_2_2));
}
END_TEST

START_TEST(strcpy_3) {
  char b3[1024] = "777 ";
  char b33[1024] = "777 ";
  char str_3_2[1024] = "LUGANO!";
  ck_assert_pstr_eq(strcpy(b3, str_3_2), s21_strcpy(b33, str_3_2));
}
END_TEST

START_TEST(strncpy_1) {
  s21_size_t n1 = 3;
  char b1[1024] = "1111111111";
  char b11[1024] = "1111111111";
  char str_1_2[1024] = "123\0";
  ck_assert_pstr_eq(strncpy(b1, str_1_2, n1), s21_strncpy(b11, str_1_2, n1));
}
END_TEST

START_TEST(strncpy_2) {
  s21_size_t n2 = 5;
  char b2[1024] = "1111111111";
  char b22[1024] = "1111111111";
  char str_2_2[1024] = "12345\0006789";
  ck_assert_pstr_eq(strncpy(b2, str_2_2, n2), s21_strncpy(b22, str_2_2, n2));
}
END_TEST

START_TEST(strncpy_3) {
  s21_size_t n3 = 5;
  char b3[1024] = "11";
  char b33[1024] = "11";
  char str_3_2[1024] = "12345\0006789";
  ck_assert_pstr_eq(strncpy(b3, str_3_2, n3), s21_strncpy(b33, str_3_2, n3));
}
END_TEST

START_TEST(memcpy_1) {
  s21_size_t n1 = 3;
  char b1[1024] = "";
  char b11[1024] = "";
  char str_1_2[1024] = "LUGANO THE BEST!";
  ck_assert_pstr_eq(memcpy(b1, str_1_2, n1), s21_memcpy(b11, str_1_2, n1));
}
END_TEST

START_TEST(memcpy_2) {
  s21_size_t n2 = 5;
  char b2[1024] = "";
  char b22[1024] = "";
  char str_2_2[1024] = "THE OF \0BEST!!";
  ck_assert_pstr_eq(memcpy(b2, str_2_2, n2), s21_memcpy(b22, str_2_2, n2));
}
END_TEST

START_TEST(memcpy_3) {
  s21_size_t n3 = 4;
  char b3[1024] = "777 ";
  char b33[1024] = "777 ";
  char str_3_2[1024] = "LUGANO!";
  ck_assert_pstr_eq(memcpy(b3, str_3_2, n3), s21_memcpy(b33, str_3_2, n3));
}
END_TEST

START_TEST(memcpy_4) {
  s21_size_t n4 = 4;
  char b4[1024] = "LUGANO! 777 ";
  char b44[1024] = "LUGANO! 777 ";
  ck_assert_pstr_eq(memcpy(b4, b4 + 7, n4), s21_memcpy(b44, b44 + 7, n4));
}
END_TEST

START_TEST(memmove_1) {
  s21_size_t n1 = 3;
  char b1[1024] = "LUGANO THE BEST!";
  char b11[1024] = "LUGANO THE BEST!";
  ck_assert_pstr_eq(memmove(b1, b1 + 5, n1), s21_memmove(b11, b1 + 5, n1));
}
END_TEST

START_TEST(memmove_2) {
  s21_size_t n2 = 4;
  char b2[1024] = "777 9999999";
  char b22[1024] = "777 9999999";
  ck_assert_pstr_eq(memmove(b2, b2, n2), s21_memmove(b22, b2, n2));
}
END_TEST

START_TEST(memmove_3) {
  s21_size_t n3 = 4;
  char b3[1024] = "777 LUGANO!";
  char b33[1024] = "777 LUGANO!";
  ck_assert_pstr_eq(memmove(b3, b3, n3), s21_memmove(b33, b33, n3));
}
END_TEST

START_TEST(memmove_4) {
  s21_size_t n4 = 4;
  char b4[1024] = "777 LUGANO!";
  char b44[1024] = "777 LUGANO!";
  ck_assert_pstr_eq(memmove(b4, b4, n4), s21_memmove(b44, b44, n4));
}
END_TEST

START_TEST(memchr_1) {
  char str[] = "Hello w\0orld\0";
  ck_assert_pstr_eq(memchr(str, 'r', 5), s21_memchr(str, 'r', 5));
}
END_TEST

START_TEST(memchr_2) {
  char str2[] = "john.smith@microsoft.com";
  ck_assert_pstr_eq(memchr(str2, 's', 6), s21_memchr(str2, 's', 6));
}
END_TEST

START_TEST(memchr_3) {
  char str3[] = {'q', 'r', 's', 't', 'w', '\0'};
  ck_assert_pstr_eq(memchr(str3, 's', 5), s21_memchr(str3, 's', 5));
}
END_TEST

START_TEST(strchr_1) {
  char str[] = "Hello world";
  ck_assert_pstr_eq(strchr(str, ' '), s21_strchr(str, ' '));
}
END_TEST

START_TEST(strchr_2) {
  char str2[] = "john.smith\0@microsoft.com";
  ck_assert_pstr_eq(strchr(str2, 'm'), s21_strchr(str2, 'm'));
}
END_TEST

START_TEST(strchr_3) {
  char str3[] = "john.smith@microsoft.com";
  ck_assert_pstr_eq(strchr(str3, 'h'), s21_strchr(str3, 'h'));
}
END_TEST

START_TEST(strrchr_1) {
  char str[] = "0163456769";
  ck_assert_pstr_eq(strrchr(str, '6'), s21_strrchr(str, '6'));
}
END_TEST

START_TEST(strrchr_2) {
  char str2[] = "john.smith@microsoft.com";
  ck_assert_pstr_eq(strrchr(str2, 'o'), s21_strrchr(str2, 'o'));
}
END_TEST

START_TEST(strrchr_3) {
  char str3[] = "john.smith@microsoft.com";
  ck_assert_pstr_eq(strrchr(str3, 'h'), s21_strrchr(str3, 'h'));
}
END_TEST

START_TEST(strrchr_4) {
  char str4[] = "";
  ck_assert_pstr_eq(strrchr(str4, 'd'), s21_strrchr(str4, 'd'));
}
END_TEST

START_TEST(strrchr_5) {
  char str5[] = {""};
  ck_assert_pstr_eq(strrchr(str5, 'z'), s21_strrchr(str5, 'z'));
}
END_TEST

START_TEST(strcspn_1) {
  char str1[] = "this is a test";
  ck_assert_int_eq(strcspn(str1, "ab"), s21_strcspn(str1, "ab"));
}
END_TEST

START_TEST(strcspn_2) {
  char str2[] = "LOST: 4-8-15-16-23-42";
  ck_assert_int_eq(strcspn(str2, "1234567890"),
                   s21_strcspn(str2, "1234567890"));
}
END_TEST

START_TEST(strcspn_3) {
  char str3[] = {'q', 'r', 's', 't', 'w', 's', 'a', 's', '\0'};
  ck_assert_int_eq(strcspn(str3, "zx"), s21_strcspn(str3, "zx"));
}
END_TEST

START_TEST(strspn_1) {
  char str[] = "12-years";
  ck_assert_int_eq(strspn(str, "1234567890"), s21_strspn(str, "1234567890"));
}
END_TEST

START_TEST(strspn_2) {
  char str2[] = "this is a test";
  ck_assert_int_eq(strspn(str2, "shit "), s21_strspn(str2, "shit "));
}
END_TEST

START_TEST(strspn_3) {
  char str3[] = {'q', 'r', 's', 't', 'w', 's', 'a', 's'};
  ck_assert_int_eq(strspn(str3, "01234"), s21_strspn(str3, "01234"));
}
END_TEST

START_TEST(strpbrk_1) {
  char str[] = "this_is_a_";
  ck_assert_pstr_eq(strpbrk(str, "369"), s21_strpbrk(str, "369"));
}
END_TEST

START_TEST(strpbrk_2) {
  char str2[] = "john.smith@mic\0rosoft.com";
  ck_assert_pstr_eq(strpbrk(str2, "fzx"), s21_strpbrk(str2, "fzx"));
}
END_TEST

START_TEST(strpbrk_3) {
  char str3[] = {'q', 'r', 's', 't', 'w', 's', 'a', 's', '\0'};
  ck_assert_pstr_eq(strpbrk(str3, "saq"), s21_strpbrk(str3, "saq"));
}
END_TEST

START_TEST(strstr_1) {
  char str[] = "";
  ck_assert_pstr_eq(strstr(str, ""), s21_strstr(str, ""));
}
END_TEST

START_TEST(strstr_2) {
  char str2[] = "john.smith@mic\0rosoft.com";
  ck_assert_pstr_eq(strstr(str2, "sm"), s21_strstr(str2, "sm"));
}
END_TEST

START_TEST(strstr_3) {
  char str3[] = {'q', 'r', 's', 't', 'w', 's', 'a', 's', '\0'};
  ck_assert_pstr_eq(strstr(str3, "woo"), s21_strstr(str3, "woo"));
}
END_TEST

START_TEST(strtok_1) {
  char str4_1[] = "/testing/with/original/string.h/";
  char str4_2[] = "/testing/with/original/string.h/";
  char del4[3] = "/";
  char *nstr_1, *nstr_2;
  nstr_1 = strtok(str4_1, del4);
  nstr_2 = s21_strtok(str4_2, del4);
  while (nstr_1 != s21_NULL) {
    ck_assert_pstr_eq(nstr_1, nstr_2);
    nstr_1 = strtok(s21_NULL, del4);
    nstr_2 = s21_strtok(s21_NULL, del4);
  }
}
END_TEST

START_TEST(strtok_2) {
  char str4_1[] = ". . testing with original string.h";
  char str4_2[] = ". . testing with original string.h";
  char del4[3] = ". ";
  char *nstr_1, *nstr_2;
  nstr_1 = strtok(str4_1, del4);
  nstr_2 = s21_strtok(str4_2, del4);
  while (nstr_1 != s21_NULL) {
    ck_assert_pstr_eq(nstr_1, nstr_2);
    nstr_1 = strtok(s21_NULL, del4);
    nstr_2 = s21_strtok(s21_NULL, del4);
  }
}
END_TEST

START_TEST(strtok_3) {
  char str4_1[] = "testing with original string.h";
  char str4_2[] = "testing with original string.h";
  char del4[3] = ". ";
  char *nstr_1, *nstr_2;
  nstr_1 = strtok(str4_1, del4);
  nstr_2 = s21_strtok(str4_2, del4);
  while (nstr_1 != s21_NULL) {
    ck_assert_pstr_eq(nstr_1, nstr_2);
    nstr_1 = strtok(s21_NULL, del4);
    nstr_2 = s21_strtok(s21_NULL, del4);
  }
}
END_TEST

START_TEST(to_upper_1) {
  char str1[] = "hEllO, WoRLD!";
  char *str2 = (char *)s21_to_upper(str1);
  ck_assert_pstr_eq(str2, "HELLO, WORLD!");
  free(str2);
}
END_TEST

START_TEST(to_upper_2) {
  char str1[] = "hEllO, WoRLD! 1177";
  char *str2 = (char *)s21_to_upper(str1);
  ck_assert_pstr_eq(str2, "HELLO, WORLD! 1177");
  free(str2);
}
END_TEST

START_TEST(to_lower_1) {
  char str1[] = "hEllO, WoRLD!";
  char *str2 = (char *)s21_to_lower(str1);
  ck_assert_pstr_eq(str2, "hello, world!");
  free(str2);
}
END_TEST

START_TEST(to_lower_2) {
  char str1[] = "hEllO, WoRLD! 1177";
  char *str2 = (char *)s21_to_lower(str1);
  ck_assert_pstr_eq(str2, "hello, world! 1177");
  free(str2);
}
END_TEST

START_TEST(insert_1) {
  char *string = "diary";
  char *string2;
  string2 = s21_insert(string, "ction", 2);
  ck_assert_pstr_eq(string2, "dictionary");
  free(string2);
}
END_TEST

START_TEST(insert_2) {
  char *string = "diary";
  char *string2;
  string2 = s21_insert(string, "ction", 8);
  ck_assert_pstr_eq(string2, s21_NULL);
  free(string2);
}
END_TEST

START_TEST(insert_3) {
  char *string = S21_NULL;
  char *string2;
  string2 = s21_insert(string, "ction", 2);
  ck_assert_pstr_eq(string2, S21_NULL);
  free(string2);
}
END_TEST

START_TEST(trim_1) {
  char src1[] = "     &#@\n\n\t Hello, World! *&#@ \n\t   ";
  char trim_chars[] = " &#@\n\t";
  char *psrc = s21_trim(src1, trim_chars);
  ck_assert_pstr_eq(psrc, "Hello, World! *");
  free(psrc);
}
END_TEST

/* -----===== PART-1 =====----- */
/* -----===== FINISH =====----- */

/* -----===== PART-2 =====----- */
/* -----===== START =====----- */
// strlen ->
START_TEST(strlen_empty) {
  char src[] = "";
  ck_assert_int_eq(s21_strlen(src), strlen(src));
}
END_TEST

START_TEST(strlen_abosal) {
  char src[] = "abosal";
  ck_assert_int_eq(s21_strlen(src), strlen(src));
}
END_TEST

START_TEST(strlen_num) {
  char src[] = "987623456124678";
  ck_assert_int_eq(s21_strlen(src), strlen(src));
}
END_TEST

START_TEST(strlen_string) {
  char src[] =
      "987623456124678qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM";
  ck_assert_int_eq(s21_strlen(src), strlen(src));
}
END_TEST

START_TEST(strlen_abosal_no_dal) {
  char src[] = "abosal\0no_dal";
  ck_assert_int_eq(s21_strlen(src), strlen(src));
}
END_TEST

START_TEST(strlen_dai_mne_pen) {
  char src[] = "dai_mne_pen(321321)...123...123";
  ck_assert_int_eq(s21_strlen(src), strlen(src));
}
END_TEST

START_TEST(strlen_Floppy_disk) {
  char src[] = "Floppy_disk";
  ck_assert_int_eq(s21_strlen(src), strlen(src));
}
END_TEST

START_TEST(strlen_Russky_kot_Shlepa) {
  char src[] = "Russky_kot_Shlepa";
  ck_assert_int_eq(s21_strlen(src), strlen(src));
}
END_TEST

START_TEST(strlen_kot_Vasily) {
  char src[] = "kot Vasily";
  ck_assert_int_eq(s21_strlen(src), strlen(src));
}
END_TEST

START_TEST(strlen_floppa) {
  char src[] = "floppa";
  ck_assert_int_eq(s21_strlen(src), strlen(src));
}
END_TEST
// strlen <-

// strncat ->
START_TEST(strncat_all_empty) {
  char src[] = "";
  char res[] = "";
  char expected[] = "";
  s21_size_t n_byte = 0;
  s21_strncat(res, src, n_byte);
  strncat(expected, src, n_byte);
  ck_assert_mem_ge(res, expected, n_byte);
}
END_TEST

START_TEST(strncat_zero_byte) {
  char src[] = "abosal";
  char res[10] = "";
  char expected[10] = "";
  s21_size_t n_byte = 0;
  s21_strncat(res, src, n_byte);
  strncat(expected, src, n_byte);
  ck_assert_mem_ge(res, expected, n_byte);
}
END_TEST

START_TEST(strncat_empty_src) {
  char src[] = "";
  char res[10] = "cd";
  char expected[10] = "cd";
  s21_size_t n_byte = 0;
  s21_strncat(res, src, n_byte);
  strncat(expected, src, n_byte);
  ck_assert_mem_ge(res, expected, n_byte);
}
END_TEST

START_TEST(strncat_cd_abosa) {
  char src[] = "abosal";
  char res[10] = "cd";
  char expected[10] = "cd";
  s21_size_t n_byte = 5;
  s21_strncat(res, src, n_byte);
  strncat(expected, src, n_byte);
  ck_assert_mem_ge(res, expected, n_byte);
}
END_TEST

START_TEST(strncat_string) {
  char src[] = "abosal";
  char res[25] = "koleka";
  char expected[25] = "koleka";
  s21_size_t n_byte = 6;
  s21_strncat(res, src, n_byte);
  strncat(expected, src, n_byte);
  ck_assert_mem_ge(res, expected, n_byte);
}
END_TEST

START_TEST(strncat_BIGFLOPPA) {
  char src[] = "BIGFLOPPA";
  char res[25] = "BIGFLOPPA";
  char expected[25] = "BIGFLOPPA";
  s21_size_t n_byte = 5;
  s21_strncat(res, src, n_byte);
  strncat(expected, src, n_byte);
  ck_assert_mem_ge(res, expected, n_byte);
}
END_TEST

START_TEST(strncat_BIGFLOPPA2) {
  char src[] = "BIGFLOPPA";
  char res[25] = "BIGFLOPPA";
  char expected[25] = "BIGFLOPPA";
  s21_size_t n_byte = 0;
  s21_strncat(res, src, n_byte);
  strncat(expected, src, n_byte);
  ck_assert_mem_ge(res, expected, n_byte);
}
END_TEST

START_TEST(strncat_BIGFLOPPA3) {
  char src[] = "BIGFLOPPA";
  char res[25] = "BIGFLOPPA";
  char expected[25] = "BIGFLOPPA";
  s21_size_t n_byte = 1;
  s21_strncat(res, src, n_byte);
  strncat(expected, src, n_byte);
  ck_assert_mem_ge(res, expected, n_byte);
}
END_TEST

START_TEST(strncat_BIGFLOPPA4) {
  char src[] = "BIGFLOPPA";
  char res[25] = "BIGFLOPPA";
  char expected[25] = "BIGFLOPPA";
  s21_size_t n_byte = 10;
  s21_strncat(res, src, n_byte);
  strncat(expected, src, n_byte);
  ck_assert_mem_ge(res, expected, n_byte);
}
END_TEST

START_TEST(strncat_zero_char) {
  char src[] = "\0";
  char res[25] = "BIGFLOPPA";
  char expected[25] = "BIGFLOPPA";
  s21_size_t n_byte = 1;
  s21_strncat(res, src, n_byte);
  strncat(expected, src, n_byte);
  ck_assert_mem_ge(res, expected, n_byte);
}
END_TEST
// strncat <-

// strncmp ->
START_TEST(strncmp_empty) {
  char str1[] = "";
  char str2[] = "";
  s21_size_t n_byte = 0;
  int got = s21_strncmp(str1, str2, n_byte);
  int expected = strncmp(str1, str2, n_byte);
  if (got > 1) got = 1;
  if (expected > 1) expected = 1;
  if (got < -1) got = -1;
  if (expected < -1) expected = -1;
  ck_assert_int_eq(got, expected);
}
END_TEST

START_TEST(strncmp_floppa_) {
  char str1[] = "floppa";
  char str2[] = "";
  s21_size_t n_byte = 0;
  int got = s21_strncmp(str1, str2, n_byte);
  int expected = strncmp(str1, str2, n_byte);
  if (got > 1) got = 1;
  if (expected > 1) expected = 1;
  if (got < -1) got = -1;
  if (expected < -1) expected = -1;
  ck_assert_int_eq(got, expected);
}
END_TEST

START_TEST(strncmp__floppa) {
  char str1[] = "";
  char str2[] = "floppa";
  s21_size_t n_byte = 0;
  int got = s21_strncmp(str1, str2, n_byte);
  int expected = strncmp(str1, str2, n_byte);
  if (got > 1) got = 1;
  if (expected > 1) expected = 1;
  if (got < -1) got = -1;
  if (expected < -1) expected = -1;
  ck_assert_int_eq(got, expected);
}
END_TEST

START_TEST(strncmp_floppa_floppa) {
  char str1[] = "floppa";
  char str2[] = "floppa";
  s21_size_t n_byte = 6;
  int got = s21_strncmp(str1, str2, n_byte);
  int expected = strncmp(str1, str2, n_byte);
  if (got > 1) got = 1;
  if (expected > 1) expected = 1;
  if (got < -1) got = -1;
  if (expected < -1) expected = -1;
  ck_assert_int_eq(got, expected);
}
END_TEST

START_TEST(strncmp_floppa_floppa_zero_byte) {
  char str1[] = "floppabazbazkotya";
  char str2[] = "floppabaz";
  s21_size_t n_byte = 10;
  int got = s21_strncmp(str1, str2, n_byte);
  int expected = strncmp(str1, str2, n_byte);
  if (got > 1) got = 1;
  if (expected > 1) expected = 1;
  if (got < -1) got = -1;
  if (expected < -1) expected = -1;
  ck_assert_int_eq(got, expected);
}
END_TEST

START_TEST(strncmp_floppa_floppa_one_byte) {
  char str1[] = "floppa";
  char str2[] = "floppa";
  s21_size_t n_byte = 1;
  int got = s21_strncmp(str1, str2, n_byte);
  int expected = strncmp(str1, str2, n_byte);
  if (got > 1) got = 1;
  if (expected > 1) expected = 1;
  if (got < -1) got = -1;
  if (expected < -1) expected = -1;
  ck_assert_int_eq(got, expected);
}
END_TEST
// strncmp <-

// strrchr ->
START_TEST(strrchr_empty) {
  char str1[] = "";
  char str2 = '\0';
  ck_assert_pstr_eq(s21_strrchr(str1, str2), strrchr(str1, str2));
}
END_TEST

START_TEST(strrchr_floppy_) {
  char str1[] = "floppy";
  char str2 = '\0';
  ck_assert_pstr_eq(s21_strrchr(str1, str2), strrchr(str1, str2));
}
END_TEST

START_TEST(strrchr__floppy) {
  char str1[] = "";
  char str2 = 'f';
  ck_assert_pstr_eq(s21_strrchr(str1, str2), strrchr(str1, str2));
}
END_TEST

START_TEST(strrchr_poki_doki_o) {
  char str1[] = "poki doki";
  char str2 = 'o';
  ck_assert_pstr_eq(s21_strrchr(str1, str2), strrchr(str1, str2));
}
END_TEST

START_TEST(strrchr_poki_doki_i) {
  char str1[] = "poki doki";
  char str2 = 'i';
  ck_assert_pstr_eq(s21_strrchr(str1, str2), strrchr(str1, str2));
}
END_TEST

START_TEST(strrchr_poki_doki_p) {
  char str1[] = "poki p dokip";
  char str2 = 'p';
  ck_assert_pstr_eq(s21_strrchr(str1, str2), strrchr(str1, str2));
}
END_TEST

START_TEST(strrchr_find_big_P) {
  char str1[] = "ppPpppppppppP";
  char str2 = 'P';
  ck_assert_pstr_eq(s21_strrchr(str1, str2), strrchr(str1, str2));
}
END_TEST

START_TEST(strrchr_find_zero) {
  char str1[] = "123456789";
  char str2 = '0';
  ck_assert_pstr_eq(s21_strrchr(str1, str2), strrchr(str1, str2));
}
END_TEST
// strrchr <-

// strpbrk ->
START_TEST(strpbrk_empty) {
  char str1[] = "";
  char str2[] = "";
  ck_assert_pstr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(strpbrk_floppy_) {
  char str1[] = "floppy";
  char str2[] = "";
  ck_assert_pstr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(strpbrk__floppy) {
  char str1[] = "";
  char str2[] = "floppy";
  ck_assert_pstr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(strpbrk_poki_doki_o) {
  char str1[] = "poki doki";
  char str2[] = "o";
  ck_assert_pstr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(strpbrk_poki_doki_i) {
  char str1[] = "poki doki";
  char str2[] = "i";
  ck_assert_pstr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(strpbrk_poki_doki_p) {
  char str1[] = "poki doki";
  char str2[] = "p";
  ck_assert_pstr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(strpbrk_find_big_P) {
  char str1[] = "ppppppppppppP";
  char str2[] = "P";
  ck_assert_pstr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(strpbrk_find_zero) {
  char str1[] = "ppppppppppppP";
  char str2[] = "\0";
  ck_assert_pstr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST
// strpbrk <-

// strspn ->
START_TEST(strspn_empty) {
  char src[] = "";
  char res[] = "";
  ck_assert_int_eq(s21_strspn(res, src), strspn(res, src));
}
END_TEST

START_TEST(strspn_gora_) {
  char src[] = "gora";
  char res[] = "";
  ck_assert_int_eq(s21_strspn(res, src), strspn(res, src));
}
END_TEST

START_TEST(strspn__gora) {
  char src[] = "";
  char res[] = "gora";
  ck_assert_int_eq(s21_strspn(res, src), strspn(res, src));
}
END_TEST

START_TEST(strspn_any_register) {
  char src[] = "gora";
  char res[] = "gOra";
  ck_assert_int_eq(s21_strspn(res, src), strspn(res, src));
}
END_TEST

START_TEST(strspn_num_num) {
  char src[] = "123";
  char res[] = "123";
  ck_assert_int_eq(s21_strspn(res, src), strspn(res, src));
}
END_TEST

START_TEST(strspn_long_num_num) {
  char src[] = "12345";
  char res[] = "123";
  ck_assert_int_eq(s21_strspn(res, src), strspn(res, src));
}
END_TEST

START_TEST(strspn_num_long_num) {
  char src[] = "123";
  char res[] = "12345";
  ck_assert_int_eq(s21_strspn(res, src), strspn(res, src));
}
END_TEST

START_TEST(strspn_any_num) {
  char src[] = "1234567890";
  char res[] = "0987654321";
  ck_assert_int_eq(s21_strspn(res, src), strspn(res, src));
}
END_TEST

START_TEST(strspn_num_with_letter) {
  char src[] = "1A2A3A4A5A";
  char res[] = "123";
  ck_assert_int_eq(s21_strspn(res, src), strspn(res, src));
}
END_TEST

START_TEST(strspn_num_with_letter2) {
  char src[] = "a1aaa23aaa41235";
  char res[] = "123";
  ck_assert_int_eq(s21_strspn(res, src), strspn(res, src));
}
END_TEST

START_TEST(strspn_basic_test) {
  char src[] = "absD";
  char res[] = "aD";
  ck_assert_int_eq(s21_strspn(res, src), strspn(res, src));
}
END_TEST

START_TEST(strspn_any_sim) {
  char src[] = "32ASDASDPare[0g9jf m07y271234567890";
  char res[] = "0987654321";
  ck_assert_int_eq(s21_strspn(res, src), strspn(res, src));
}
END_TEST

START_TEST(strspn_upper_letter) {
  char src[] = "32ASDASDPare[0g9jf m07y271234567890";
  char res[] = "1234567890QWERTYUIOPASDFGHJKLZXCVBNM";
  ck_assert_int_eq(s21_strspn(res, src), strspn(res, src));
}
END_TEST

START_TEST(strspn_lower_letter) {
  char src[] = "32jersASDASDPare[0g9jf m07y271234567890";
  char res[] = "1234567890qwertyuiopasdfghjklczxcvbnm";
  ck_assert_int_eq(s21_strspn(res, src), strspn(res, src));
}
END_TEST

START_TEST(strspn_not_uniq_sim) {
  char src[] =
      "333333333333333333333333333333333333333333333333333333333333333333333333"
      "33333333333333";
  char res[] =
      "111111111111111111111111111111111111111111111111111111111111111111111111"
      "11111111111113";
  ck_assert_int_eq(s21_strspn(res, src), strspn(res, src));
}
END_TEST
// strspn <-

// strerror ->

START_TEST(strerror_1) {
  for (int i = -123; i < 0; i++) {
    ck_assert_str_eq(s21_strerror(i), strerror(i));
  }
  for (int i = 0; i <= 106; i++) {
    ck_assert_str_eq(s21_strerror(i), strerror(i));
  }
  for (int i = 107; i <= 234; i++) {
    ck_assert_str_eq(s21_strerror(i), strerror(i));
  }
}

END_TEST

// strerror <-

// strstr ->
START_TEST(strstr_empty_string_haystack_and_needle) {
  char haystack[] = "";
  char needle[] = "";
  ck_assert_pstr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

START_TEST(strstr_empty_string_haystack) {
  char haystack[] = "";
  char needle[] = "jho1faQsdkjnSa3aefwf8hiuJafeHioj";
  ck_assert_pstr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

START_TEST(strstr_empty_string_needle) {
  char haystack[] = "safQhilufas7MaSef2345wknwefnkjHawe2fhilu";
  char needle[] = "";
  ck_assert_pstr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

START_TEST(strstr_toxic_test) {
  char haystack[] = "You are toxic!";
  char needle[] = "toxic";
  ck_assert_pstr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

START_TEST(strstr_not_word_in_haystack) {
  char haystack[] = "There is no right word in this test!";
  char needle[] = "NOT";
  ck_assert_pstr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

START_TEST(strstr_words_with_any_register) {
  char haystack[] = "AbOBosNyTSa";
  char needle[] = "aBoboSNYTsa";
  ck_assert_pstr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

START_TEST(strstr_repeated_words) {
  char haystack[] = "AD AD AD";
  char needle[] = "AD";
  ck_assert_pstr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

START_TEST(strstr_word_at_end) {
  char haystack[] = "22 321 123";
  char needle[] = "123";
  ck_assert_pstr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

START_TEST(strstr_one_simbol_in_needle_and_haystack) {
  char haystack[] = "1";
  char needle[] = "1";
  ck_assert_pstr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

START_TEST(strstr_one_simbol_in_needle) {
  char haystack[] =
      "13625523478437263475984675342345sdghyftrg freshtsyASFWEt wEafe";
  char needle[] = " ";
  ck_assert_pstr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

START_TEST(strstr_one_simbol_in_haystack) {
  char haystack[] = "-";
  char needle[] = "1234567890qwertyuiopasdfghjk-";
  ck_assert_pstr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST
// strstr <-

// // strtok ->
START_TEST(strtok_correct_token_string) {
  char str1[] = "Aboba++Floppa_! Kotya====!Shleppa";
  char str2[] = "Aboba++Floppa_! Kotya====!Shleppa";
  const char delims[] = "+_! =";
  char *got = s21_strtok(str1, delims);
  char *expected = strtok(str2, delims);
  ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));
  ck_assert_str_eq(got, expected);
  while (got && expected) {
    got = s21_strtok(s21_NULL, delims);
    expected = strtok(s21_NULL, delims);
    if (got || expected) {
      ck_assert_str_eq(got, expected);
    } else {
      ck_assert_ptr_null(got);
      ck_assert_ptr_null(expected);
    }
  }
}
END_TEST

// START_TEST(strtok_hard_token_string) {
//   char str1[] = "++Aboba++Floppa_! Kotya===!Shleppa+++ A +";
//   char str2[] = "++Aboba++Floppa_! Kotya===!Shleppa+++ A +";
//   const char delims[] = "+_! =";
//   char *got = s21_strtok(str1, delims);
//   char *expected = strtok(str2, delims);
//   ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));
//   ck_assert_str_eq(got, expected);
//   while (got && expected) {
//     got = s21_strtok(s21_NULL, delims);
//     expected = strtok(s21_NULL, delims);
//     if (got || expected) {
//       ck_assert_str_eq(got, expected);
//     } else {
//       ck_assert_ptr_null(got);
//       ck_assert_ptr_null(expected);
//     }
//   }
// }
// END_TEST

START_TEST(strtok_unary_delimiters) {
  char str1[] = "Aboba+Anuroba_Floppa!Kotya_Kekus";
  char str2[] = "Aboba+Anuroba_Floppa!Kotya_Kekus";
  const char delims[] = "+_! =";
  char *got = s21_strtok(str1, delims);
  char *expected = strtok(str2, delims);
  ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));
  ck_assert_str_eq(got, expected);
  while (got && expected) {
    got = s21_strtok(s21_NULL, delims);
    expected = strtok(s21_NULL, delims);
    if (got || expected) {
      ck_assert_str_eq(got, expected);
    } else {
      ck_assert_ptr_null(got);
      ck_assert_ptr_null(expected);
    }
  }
}
END_TEST

START_TEST(strtok_no_delims) {
  char str1[] = "AbobaHasNoDelims";
  char str2[] = "AbobaHasNoDelims";
  const char delims[] = "+_! =";
  char *got = s21_strtok(str1, delims);
  char *expected = strtok(str2, delims);
  ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));
  ck_assert_str_eq(got, expected);
  while (got && expected) {
    got = s21_strtok(s21_NULL, delims);
    expected = strtok(s21_NULL, delims);
    if (got || expected) {
      ck_assert_str_eq(got, expected);
    } else {
      ck_assert_ptr_null(got);
      ck_assert_ptr_null(expected);
    }
  }
}
END_TEST

START_TEST(strtok_too_many_uses_non_segfault) {
  char str1[] = "Aboba_Floppa_Roba";
  char str2[] = "Aboba_Floppa_Roba";
  const char delims[] = "+_! =";
  char *got = s21_strtok(str1, delims);
  char *expected = strtok(str2, delims);
  ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));
  ck_assert_str_eq(got, expected);
  int i = 5;
  while (i) {
    got = s21_strtok(s21_NULL, delims);
    expected = strtok(s21_NULL, delims);
    i--;
    if (got || expected) {
      ck_assert_str_eq(got, expected);
    } else {
      ck_assert_ptr_null(got);
      ck_assert_ptr_null(expected);
    }
  }
}
END_TEST

START_TEST(strtok_even_n_of_delims) {
  char str1[] = "Roba++++Kepa++A++++B__V";
  char str2[] = "Roba++++Kepa++A++++B__V";
  const char delims[] = "+_! =";
  char *got = s21_strtok(str1, delims);
  char *expected = strtok(str2, delims);
  ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));
  ck_assert_str_eq(got, expected);
  while (got && expected) {
    got = s21_strtok(s21_NULL, delims);
    expected = strtok(s21_NULL, delims);
    if (got || expected) {
      ck_assert_str_eq(got, expected);
    } else {
      ck_assert_ptr_null(got);
      ck_assert_ptr_null(expected);
    }
  }
}
END_TEST

START_TEST(strtok_odd_n_of_delims) {
  char str1[] = "Aboba__+Floppa_  Roba";
  char str2[] = "Aboba__+Floppa_  Roba";
  const char delims[] = "+_! =";
  char *got = s21_strtok(str1, delims);
  char *expected = strtok(str2, delims);
  ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));
  ck_assert_str_eq(got, expected);
  while (got && expected) {
    got = s21_strtok(s21_NULL, delims);
    expected = strtok(s21_NULL, delims);
    if (got || expected) {
      ck_assert_str_eq(got, expected);
    } else {
      ck_assert_ptr_null(got);
      ck_assert_ptr_null(expected);
    }
  }
}
END_TEST

START_TEST(strtok_mixed_n_of_delims) {
  char str1[] = "Aboba__Floppa_+++Roba_Kepa";
  char str2[] = "Aboba__Floppa_+++Roba_Kepa";
  const char delims[] = "+_! =";
  char *got = s21_strtok(str1, delims);
  char *expected = strtok(str2, delims);
  ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));
  ck_assert_str_eq(got, expected);
  while (got && expected) {
    got = s21_strtok(s21_NULL, delims);
    expected = strtok(s21_NULL, delims);
    if (got || expected) {
      ck_assert_str_eq(got, expected);
    } else {
      ck_assert_ptr_null(got);
      ck_assert_ptr_null(expected);
    }
  }
}
END_TEST

START_TEST(strtok_hard_mixed) {
  char str1[] = "     Aboba__+ Flo!ppa_   Roba+";
  char str2[] = "     Aboba__+ Flo!ppa_   Roba+";
  const char delims[] = "+_! =";
  char *got = s21_strtok(str1, delims);
  char *expected = strtok(str2, delims);
  ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));
  ck_assert_str_eq(got, expected);
  while (got || expected) {
    got = s21_strtok(s21_NULL, delims);
    expected = strtok(s21_NULL, delims);
    if (got || expected) {
      ck_assert_str_eq(got, expected);
    } else {
      ck_assert_ptr_null(got);
      ck_assert_ptr_null(expected);
    }
  }
}
END_TEST

START_TEST(strtok_mixed_hard_incorrect) {
  char str1[] = "!Stepa__ !M!ish a____Anton+An!!!drey";
  char str2[] = "!Stepa__ !M!ish a____Anton+An!!!drey";
  const char delims[] = "+_! =";
  char *got = s21_strtok(str1, delims);
  char *expected = strtok(str2, delims);
  ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));
  ck_assert_str_eq(got, expected);
  while (got || expected) {
    got = s21_strtok(s21_NULL, delims);
    expected = strtok(s21_NULL, delims);
    if (got || expected) {
      ck_assert_str_eq(got, expected);
    } else {
      ck_assert_ptr_null(got);
      ck_assert_ptr_null(expected);
    }
  }
}
END_TEST

START_TEST(strtok_very_hard_mixed) {
  char str1[] = "!       A!B!C!D!E!!F!!G";
  char str2[] = "!       A!B!C!D!E!!F!!G";
  const char delims[] = "+_! =";
  char *got = s21_strtok(str1, delims);
  char *expected = strtok(str2, delims);
  ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));
  ck_assert_str_eq(got, expected);
  while (got || expected) {
    got = s21_strtok(s21_NULL, delims);
    expected = strtok(s21_NULL, delims);
    if (got || expected) {
      ck_assert_str_eq(got, expected);
      ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));
    } else {
      ck_assert_ptr_null(got);
      ck_assert_ptr_null(expected);
    }
  }
}
END_TEST
// strtok <-

// strncpy ->
START_TEST(strncpy_empty) {
  char src[] = "";
  char res[] = "";
  char exp[] = "";
  s21_size_t n_byte = 0;
  s21_strncpy(res, src, n_byte);
  strncpy(exp, src, n_byte);
  ck_assert_str_eq(res, exp);
}
END_TEST

START_TEST(strncpy_zero_byte) {
  char src[] = "123";
  char res[] = "123";
  char exp[] = "123";
  s21_size_t n_byte = 0;
  s21_strncpy(res, src, n_byte);
  strncpy(exp, src, n_byte);
  ck_assert_str_eq(res, exp);
}
END_TEST

START_TEST(strncpy_empty_src) {
  char src[] = "";
  char res[] = "123";
  char exp[] = "123";
  s21_size_t n_byte = 0;
  s21_strncpy(res, src, n_byte);
  strncpy(exp, src, n_byte);
  ck_assert_str_eq(res, exp);
}
END_TEST

START_TEST(strncpy_one_byte) {
  char src[] = "123";
  char res[5] = "123";
  char exp[5] = "123";
  s21_size_t n_byte = 1;
  s21_strncpy(res, src, n_byte);
  strncpy(exp, src, n_byte);
  ck_assert_str_eq(res, exp);
}
END_TEST

START_TEST(strncpy_two_byte) {
  char src[] = "123";
  char res[7] = "123";
  char exp[7] = "123";
  s21_size_t n_byte = 2;
  s21_strncpy(res, src, n_byte);
  strncpy(exp, src, n_byte);
  ck_assert_str_eq(res, exp);
}
END_TEST

START_TEST(strncpy_string) {
  char src[] = "Str1ng";
  char res[7 + 7] = "Str1ng";
  char exp[7 + 7] = "Str1ng";
  s21_size_t n_byte = 7;
  s21_strncpy(res, src, n_byte);
  strncpy(exp, src, n_byte);
  ck_assert_str_eq(res, exp);
}
END_TEST
// strncpy <-

// strcspn ->
START_TEST(strcspn_empty) {
  char src[] = "";
  char res[] = "";
  ck_assert_int_eq(s21_strcspn(res, src), strcspn(res, src));
}
END_TEST

START_TEST(strcspn_gora_) {
  char src[] = "gora";
  char res[] = "";
  ck_assert_int_eq(s21_strcspn(res, src), strcspn(res, src));
}
END_TEST

START_TEST(strcspn__gora) {
  char src[] = "";
  char res[] = "gora";
  ck_assert_int_eq(s21_strcspn(res, src), strcspn(res, src));
}
END_TEST

START_TEST(strcspn_any_register) {
  char src[] = "gora";
  char res[] = "gOra";
  ck_assert_int_eq(s21_strcspn(res, src), strcspn(res, src));
}
END_TEST

START_TEST(strcspn_num_num) {
  char src[] = "123";
  char res[] = "123";
  ck_assert_int_eq(s21_strcspn(res, src), strcspn(res, src));
}
END_TEST

START_TEST(strcspn_long_num_num) {
  char src[] = "12345";
  char res[] = "123";
  ck_assert_int_eq(s21_strcspn(res, src), strcspn(res, src));
}
END_TEST

START_TEST(strcspn_num_long_num) {
  char src[] = "123";
  char res[] = "12345";
  ck_assert_int_eq(s21_strcspn(res, src), strcspn(res, src));
}
END_TEST

START_TEST(strcspn_any_num) {
  char src[] = "1234567890";
  char res[] = "0987654321";
  ck_assert_int_eq(s21_strcspn(res, src), strcspn(res, src));
}
END_TEST

START_TEST(strcspn_num_with_letter) {
  char src[] = "1A2A3A4A5A";
  char res[] = "123";
  ck_assert_int_eq(s21_strcspn(res, src), strcspn(res, src));
}
END_TEST

START_TEST(strcspn_num_with_letter2) {
  char src[] = "a1aaa23aaa41235";
  char res[] = "123";
  ck_assert_int_eq(s21_strcspn(res, src), strcspn(res, src));
}
END_TEST

START_TEST(strcspn_basic_test) {
  char src[] = "absD";
  char res[] = "aD";
  ck_assert_int_eq(s21_strcspn(res, src), strcspn(res, src));
}
END_TEST

START_TEST(strcspn_any_sim) {
  char src[] = "32ASDASDPare[0g9jf m07y271234567890";
  char res[] = "0987654321";
  ck_assert_int_eq(s21_strcspn(res, src), strcspn(res, src));
}
END_TEST

START_TEST(strcspn_upper_letter) {
  char src[] = "32ASDASDPare[0g9jf m07y271234567890";
  char res[] = "1234567890QWERTYUIOPASDFGHJKLZXCVBNM";
  ck_assert_int_eq(s21_strcspn(res, src), strcspn(res, src));
}
END_TEST

START_TEST(strcspn_lower_letter) {
  char src[] = "32jersASDASDPare[0g9jf m07y271234567890";
  char res[] = "1234567890qwertyuiopasdfghjklczxcvbnm";
  ck_assert_int_eq(s21_strcspn(res, src), strcspn(res, src));
}
END_TEST

START_TEST(strcspn_not_uniq_sim) {
  char src[] =
      "333333333333333333333333333333333333333333333333333333333333333333333333"
      "33333333333333";
  char res[] =
      "111111111111111111111111111111111111111111111111111111111111111111111111"
      "11111111111113";
  ck_assert_int_eq(s21_strcspn(res, src), strcspn(res, src));
}
END_TEST
// strcspn <-

// strcmp ->
START_TEST(strcmp_Heloboba_Heloboba) {
  char a[] = "Heloboba";
  char b[] = "Heloboba";
  int got = s21_strcmp(a, b);
  int expected = strcmp(a, b);
  if (got > 1) got = 1;
  if (expected > 1) expected = 1;
  if (got < -1) got = -1;
  if (expected < -1) expected = -1;
  ck_assert_int_eq(got, expected);
}
END_TEST

START_TEST(strcmp_HEloboba_Heloboba) {
  char a[] = "HEloboba";
  char b[] = "Heloboba";
  int got = s21_strcmp(a, b);
  int expected = strcmp(a, b);
  if (got > 1) got = 1;
  if (expected > 1) expected = 1;
  if (got < -1) got = -1;
  if (expected < -1) expected = -1;
  ck_assert_int_eq(got, expected);
}
END_TEST

START_TEST(strcmp_Hel0boba_Helob0ba) {
  char a[] = "Hel0boba";
  char b[] = "Helob0ba";
  int got = s21_strcmp(a, b);
  int expected = strcmp(a, b);
  if (got > 1) got = 1;
  if (expected > 1) expected = 1;
  if (got < -1) got = -1;
  if (expected < -1) expected = -1;
  ck_assert_int_eq(got, expected);
}
END_TEST

START_TEST(strcmp_Heloboba_) {
  char a[] = "Heloboba";
  char b[] = "";
  int got = s21_strcmp(a, b);
  int expected = strcmp(a, b);
  if (got > 1) got = 1;
  if (expected > 1) expected = 1;
  if (got < -1) got = -1;
  if (expected < -1) expected = -1;
  ck_assert_int_eq(got, expected);
}
END_TEST

START_TEST(strcmp__Heloboba) {
  char a[] = "";
  char b[] = "Heloboba";
  int got = s21_strcmp(a, b);
  int expected = strcmp(a, b);
  if (got > 1) got = 1;
  if (expected > 1) expected = 1;
  if (got < -1) got = -1;
  if (expected < -1) expected = -1;
  ck_assert_int_eq(got, expected);
}
END_TEST

START_TEST(strcmp_Heloboba) {
  char a[] = "L(8)L";
  char b[] = "L(8)L";
  int got = s21_strcmp(a, b);
  int expected = strcmp(a, b);
  if (got > 1) got = 1;
  if (expected > 1) expected = 1;
  if (got < -1) got = -1;
  if (expected < -1) expected = -1;
  ck_assert_int_eq(got, expected);
}
END_TEST

START_TEST(strcmp_empty) {
  char a[] = "";
  char b[] = "";
  int got = s21_strcmp(a, b);
  int expected = strcmp(a, b);
  if (got > 1) got = 1;
  if (expected > 1) expected = 1;
  if (got < -1) got = -1;
  if (expected < -1) expected = -1;
  ck_assert_int_eq(got, expected);
}
END_TEST

START_TEST(strcmp_only_num) {
  char a[] = "1234567890";
  char b[] = "1234567890";
  int got = s21_strcmp(a, b);
  int expected = strcmp(a, b);
  if (got > 1) got = 1;
  if (expected > 1) expected = 1;
  if (got < -1) got = -1;
  if (expected < -1) expected = -1;
  ck_assert_int_eq(got, expected);
}
END_TEST
// strcmp <-

// strchr ->
START_TEST(strchr_abobasnutsa_find_a) {
  char src[] = "abobasnutsa";
  char find = 'a';
  ck_assert_pstr_eq(s21_strchr(src, find), strchr(src, find));
}
END_TEST

START_TEST(strchr_abobasnutAsa_find_A) {
  char src[] = "abobasnutAsa";
  char find = 'A';
  ck_assert_pstr_eq(s21_strchr(src, find), strchr(src, find));
}
END_TEST

START_TEST(strchr_abobasnutA1sa_find_1) {
  char src[] = "abobasnutA1sa";
  char find = '1';
  ck_assert_pstr_eq(s21_strchr(src, find), strchr(src, find));
}
END_TEST

START_TEST(strchr_abobasnutAsa_find_Z) {
  char src[] = "abobasnutAsa";
  char find = 'Z';
  ck_assert_pstr_eq(s21_strchr(src, find), strchr(src, find));
}
END_TEST

START_TEST(strchr_abobasnutAsa_find_3) {
  char src[] = "abobasnutAsa";
  char find = '3';
  ck_assert_pstr_eq(s21_strchr(src, find), strchr(src, find));
}
END_TEST

START_TEST(strchr_empty_src) {
  char src[] = "";
  char find = '3';
  ck_assert_pstr_eq(s21_strchr(src, find), strchr(src, find));
}
END_TEST
// strchr <-

// strcpy ->
START_TEST(strcpy_aboba_floppa) {
  char src[] = " floppa!!!";
  char res[5 + 15] = "aboba ";
  char expected[5 + 15] = "aboba ";
  s21_strcpy(res, src);
  strcpy(expected, src);
  ck_assert_str_eq(res, expected);
}
END_TEST

START_TEST(strcpy__floppa) {
  char src[] = "Floppa!!!";
  char res[5 + 15] = "";
  char expected[5 + 15] = "";
  s21_strcpy(res, src);
  strcpy(expected, src);
  ck_assert_str_eq(res, expected);
}
END_TEST

START_TEST(strcpy_aboba_) {
  char src[] = "";
  char res[5 + 15] = "abobas";
  char expected[5 + 15] = "abobas";
  s21_strcpy(res, src);
  strcpy(expected, src);
  ck_assert_str_eq(res, expected);
}
END_TEST

START_TEST(strcpy_empty) {
  char src[] = "";
  char res[5 + 15] = "";
  char expected[5 + 15] = "";
  s21_strcpy(res, src);
  strcpy(expected, src);
  ck_assert_str_eq(res, expected);
}
END_TEST

START_TEST(strcpy_empty_num) {
  char src[] = "1";
  char res[5 + 15] = "";
  char expected[5 + 15] = "";
  s21_strcpy(res, src);
  strcpy(expected, src);
  ck_assert_str_eq(res, expected);
}
END_TEST

START_TEST(strcpy_hello) {
  char src[] = " my dear friend\"";
  char res[5 + 15] = "Hello";
  char expected[5 + 15] = "Hello";
  s21_strcpy(res, src);
  strcpy(expected, src);
  ck_assert_str_eq(res, expected);
}
END_TEST

START_TEST(strcpy_over_string) {
  char src[] = "ab\0ba";
  char res[10 + 9] = "Gre\0t";
  char expected[10 + 9] = "Gre\0t";
  s21_strcpy(res, src);
  strcpy(expected, src);
  ck_assert_str_eq(res, expected);
}
END_TEST

START_TEST(strcpy_hard_test) {
  char src[] = "ad[sofijpoiajsdf pj98981h23 p9h floppa!!!";
  char res[49 + 42] = "as[oidjf paijsdf j9oqh2837o4h hUW auhduash W8awd";
  char expected[49 + 42] = "as[oidjf paijsdf j9oqh2837o4h hUW auhduash W8awd";
  s21_strcpy(res, src);
  strcpy(expected, src);
  ck_assert_str_eq(res, expected);
}
END_TEST
// strcpy <-

// strcat ->
START_TEST(strcat_Hello_aboba) {
  char src[] = " aboba!!!";
  char res[5 + 10] = "Hello";
  char expected[5 + 10] = "Hello";
  s21_strcat(res, src);
  strcat(expected, src);
  ck_assert_str_eq(res, expected);
}
END_TEST

START_TEST(strcat_zero_first) {
  char src[] = " aboba!!!";
  char res[0 + 10] = "";
  char expected[0 + 10] = "";
  s21_strcat(res, src);
  strcat(expected, src);
  ck_assert_str_eq(res, expected);
}
END_TEST

START_TEST(strcat_zero_last) {
  char src[] = "";
  char res[] = "Hello";
  char expected[] = "Hello";
  s21_strcat(res, src);
  strcat(expected, src);
  ck_assert_str_eq(res, expected);
}
END_TEST

START_TEST(strcat_any_letters_with_register) {
  char src[] = "asdfj  asdf aisdfjaiushdfASD SAD asDSad ASDAsdwqqeAS";
  char res[5 + 53] = "Hello";
  char expected[5 + 53] = "Hello";
  s21_strcat(res, src);
  strcat(expected, src);
  ck_assert_str_eq(res, expected);
}
END_TEST

START_TEST(strcat_any_letters_with_register_and_num) {
  char src[] = "asd0fj  asd1f aisdfjw6234A1241SD SA5 asDSad 89SDAsdw7qqeAS";
  char res[5 + 59] = "Hello";
  char expected[5 + 59] = "Hello";
  s21_strcat(res, src);
  strcat(expected, src);
  ck_assert_str_eq(res, expected);
}
END_TEST

START_TEST(strcat_any_letters_with_register_and_num_and_sim) {
  char src[] =
      "asd0fj  asd1f aisdfjw6234A1241SD SA5 asDSad 89SDAsdw7qqeAS)(?!.,";
  char res[5 + 65] = "Hello";
  char expected[5 + 65] = "Hello";
  s21_strcat(res, src);
  strcat(expected, src);
  ck_assert_str_eq(res, expected);
}
END_TEST
// strcat <-

// to_lower ->
START_TEST(to_lower_test1) {
  char str[] = "ShLePa V TaZ1Ke?";
  char expected[] = "shlepa v taz1ke?";
  char *got = s21_to_lower(str);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST

START_TEST(to_lower_test2) {
  char str[] = "123456789Q";
  char expected[] = "123456789q";
  char *got = s21_to_lower(str);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST

START_TEST(to_lower_test3) {
  char str[] = "Space created";
  char expected[] = "space created";
  char *got = s21_to_lower(str);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST

START_TEST(to_lower_test4) {
  char str[] = "";
  char expected[] = "";
  char *got = s21_to_lower(str);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST

START_TEST(to_lower_test5) {
  char str[] = "";
  char expected[] = "";
  char *got = s21_to_lower(str);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST
// to_lower <-

// trim ->
START_TEST(trim_all_empty) {
  char str[] = "";
  char trim_ch[] = "";
  char *expected = "";
  char *got = s21_trim(str, trim_ch);
  ck_assert_pstr_eq(got, expected);
  if (got) free(got);
}
END_TEST

START_TEST(trim_str_empty) {
  char str[] = "";
  char trim_ch[] = "+!0-aeoi2o3i23iuhuhh3O*YADyagsduyoaweq213";
  char expected[] = "";
  char *got = s21_trim(str, trim_ch);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST

START_TEST(trim_empty) {
  char str[] = "+!0-aeoi2o3i23iuhuhh3O*YADyagsduyoaweq213";
  char trim_ch[] = "";
  char *expected = "+!0-aeoi2o3i23iuhuhh3O*YADyagsduyoaweq213";
  char *got = s21_trim(str, trim_ch);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST

START_TEST(trim_and_str_eq) {
  char str[] = "+!0-aeoi2o3i23iuhuhh3O*YADyagsduyoaweq213";
  char trim_ch[] = "+!0-aeoi2o3i23iuhuhh3O*YADyagsduyoaweq213";
  char expected[] = "";
  char *got = s21_trim(str, trim_ch);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST

START_TEST(trim_test1) {
  char str[] = "+!!++Abo+ba++00";
  char trim_ch[] = "+!0-";
  char expected[] = "Abo+ba";
  char *got = (char *)s21_trim(str, trim_ch);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST

START_TEST(trim_test2) {
  char str[] = "Ab000cd0";
  char trim_ch[] = "003";
  char expected[] = "Ab000cd";
  char *got = s21_trim(str, trim_ch);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST

START_TEST(trim_test3) {
  char str[] = "DoNotTouch";
  char trim_ch[] = "Not";
  char expected[] = "DoNotTouch";
  char *got = s21_trim(str, trim_ch);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST

START_TEST(trim_test4) {
  char str[] = "&* !!sc21 * **";
  char trim_ch[] = "&!* ";
  char expected[] = "sc21";
  char *got = s21_trim(str, trim_ch);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST

START_TEST(trim_test5) {
  char str[] = " Good morning!    ";
  char trim_ch[] = " ";
  char expected[] = "Good morning!";
  char *got = s21_trim(str, trim_ch);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST

START_TEST(trim_empty_spaces) {
  char str[] = "        abc         ";
  char trim_ch[] = "";
  char *expected = "abc";
  char *got = s21_trim(str, trim_ch);
  ck_assert_pstr_eq(got, expected);
  if (got) free(got);
}
END_TEST

START_TEST(trim_null_ptr_trim_chars) {
  char str[] = "        abc         ";
  char *trim_ch = s21_NULL;
  char expected[] = "abc";
  char *got = s21_trim(str, trim_ch);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST
// trim <-

// to_upper ->
START_TEST(to_upper_test1) {
  char str[] = "good job";
  char expected[] = "GOOD JOB";
  char *got = s21_to_upper(str);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST

START_TEST(to_upper_test2) {
  char str[] = "empty";
  char expected[] = "EMPTY";
  char *got = s21_to_upper(str);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST

START_TEST(to_upper_test3) {
  char str[] = "1+1*1";
  char expected[] = "1+1*1";
  char *got = s21_to_upper(str);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST

START_TEST(to_upper_test4) {
  char str[] = " ";
  char expected[] = " ";
  char *got = s21_to_upper(str);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST

START_TEST(to_upper_test5) {
  char str[] = "";
  char expected[] = "";
  char *got = s21_to_upper(str);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST
// to_upper <-

// memcpy ->
START_TEST(memcpy_hate_test) {
  char src[] = "i hate memcmp";
  s21_size_t kByte = 12;
  char res[kByte + 8];
  char expected[kByte + 8];
  s21_memcpy(res, src, kByte);
  memcpy(expected, src, kByte);
  ck_assert_mem_eq(res, expected, kByte);
}
END_TEST

START_TEST(memcpy_zero_test_string) {
  char src[] = "aboba";
  s21_size_t kByte = 0;
  char res[kByte + 8];
  char expected[kByte + 8];
  s21_memcpy(res, src, kByte);
  memcpy(expected, src, kByte);
  ck_assert_mem_eq(res, expected, kByte);
}
END_TEST

START_TEST(memcpy_any_empty) {
  char src[] = "";
  s21_size_t kByte = 0;
  char res[kByte + 8];
  char expected[kByte + 8];
  s21_memcpy(res, src, kByte);
  memcpy(expected, src, kByte);
  ck_assert_mem_eq(res, expected, kByte);
}
END_TEST

START_TEST(memcpy_zero_test_string_with_register) {
  char src[] = "I hate memcmp";
  s21_size_t kByte = 0;
  char res[kByte + 8];
  char expected[kByte + 8];
  s21_memcpy(res, src, kByte);
  memcpy(expected, src, kByte);
  ck_assert_mem_eq(res, expected, kByte);
}
END_TEST

START_TEST(memcpy_zero_test_num) {
  char src[] = "123";
  s21_size_t kByte = 1;
  char res[kByte + 8];
  char expected[kByte + 8];
  s21_memcpy(res, src, kByte);
  memcpy(expected, src, kByte);
  ck_assert_mem_eq(res, expected, kByte);
}
END_TEST

START_TEST(memcpy_one_byte_string) {
  char src[] = "aboba";
  s21_size_t kByte = 1;
  char res[kByte + 8];
  char expected[kByte + 8];
  s21_memcpy(res, src, kByte);
  memcpy(expected, src, kByte);
  ck_assert_mem_eq(res, expected, kByte);
}
END_TEST

START_TEST(memcpy_one_byte_string_with_register) {
  char src[] = "Zboba";
  s21_size_t kByte = 1;
  char res[kByte + 8];
  char expected[kByte + 8];
  s21_memcpy(res, src, kByte);
  memcpy(expected, src, kByte);
  ck_assert_mem_eq(res, expected, kByte);
}
END_TEST

START_TEST(memcpy_one_byte_num) {
  char src[] = "09";
  s21_size_t kByte = 1;
  char res[kByte + 8];
  char expected[kByte + 8];
  s21_memcpy(res, src, kByte);
  memcpy(expected, src, kByte);
  ck_assert_mem_eq(res, expected, kByte);
}
END_TEST

START_TEST(memcpy_basic_long_string) {
  char src[] = "abobasdafoijasdofjas asdopij";
  s21_size_t kByte = 28;
  char res[kByte + 8];
  char expected[kByte + 8];
  s21_memcpy(res, src, kByte);
  memcpy(expected, src, kByte);
  ck_assert_mem_eq(res, expected, kByte);
}
END_TEST

START_TEST(memcpy_long_string_with_register) {
  char src[] = "aposkd AOSIjFasodijpaoisdjf poisdjfg";
  s21_size_t kByte = 36;
  char res[kByte + 8];
  char expected[kByte + 8];
  s21_memcpy(res, src, kByte);
  memcpy(expected, src, kByte);
  ck_assert_mem_eq(res, expected, kByte);
}
END_TEST

START_TEST(memcpy_long_string_with_register_and_num) {
  char src[] = "aodasf ieuwfh luhasdfLIAUSHD liuh 12li3uh 12i4ouhsdfh";
  s21_size_t kByte = 53;
  char res[kByte + 8];
  char expected[kByte + 8];
  s21_memcpy(res, src, kByte);
  memcpy(expected, src, kByte);
  ck_assert_mem_eq(res, expected, kByte);
}
END_TEST

START_TEST(memcpy_long_string_with_register_and_num_and_simbol) {
  char src[] =
      "()()(((())):!,....aodasf ieuwfh luhasdfLIAUSHD liuh 12li3uh 12i4ouhsdfh";
  s21_size_t kByte = 71;
  char res[kByte + 8];
  char expected[kByte + 8];
  s21_memcpy(res, src, kByte);
  memcpy(expected, src, kByte);
  ck_assert_mem_eq(res, expected, kByte);
}
END_TEST
// memcpy <-

// memmove ->
START_TEST(memmove_empty_dest_and_src) {
  char src[200] = "";
  char src2[200] = "";
  s21_size_t copy_kByte = 0;
  char *res = src;
  char *expected = src2;
  s21_size_t check_kByte = 0;
  s21_memmove(res, src, copy_kByte);
  memmove(expected, src2, copy_kByte);
  ck_assert_mem_eq(res, expected, check_kByte);
}
END_TEST

START_TEST(memmove_empty_dest) {
  char src[200] = "123SDFAZ`ESFsdfsdf";
  char src2[200] = "123SDFAZ`ESFsdfsdf";
  s21_size_t copy_kByte = 10;
  char res[200] = "";
  char expected[200] = "";
  s21_size_t check_kByte = 10;
  s21_memmove(res, src, copy_kByte);
  memmove(expected, src2, copy_kByte);
  ck_assert_mem_eq(res, expected, check_kByte);
}
END_TEST

START_TEST(memmove_empty_src) {
  char src[200] = "";
  char src2[200] = "";
  s21_size_t copy_kByte = 0;
  char res[200] = "i hate memcmp";
  char expected[200] = "i hate memcmp";
  s21_size_t check_kByte = 13;
  s21_memmove(res, src, copy_kByte);
  memmove(expected, src2, copy_kByte);
  ck_assert_mem_eq(res, expected, check_kByte);
}
END_TEST

START_TEST(memmove_write_in_left) {
  char src[200] = "Hate";
  char src2[200] = "Hate";
  s21_size_t copy_kByte = 4;
  char res[200] = "i hate memcmp";
  char expected[200] = "i hate memcmp";
  s21_size_t check_kByte = 17;
  s21_memmove(res, src, copy_kByte);
  memmove(expected, src2, copy_kByte);
  ck_assert_mem_eq(res, expected, check_kByte);
}
END_TEST

START_TEST(memmove_write_in_right) {
  char src[200] = "Hate";
  char src2[200] = "Hate";
  s21_size_t copy_kByte = 4;
  char res[200] = "i hate memcmp";
  char expected[200] = "i hate memcmp";
  s21_size_t check_kByte = 17;
  s21_memmove(res + 13, src, copy_kByte);
  memmove(expected + 13, src2, copy_kByte);
  ck_assert_mem_eq(res, expected, check_kByte);
}
END_TEST

START_TEST(memmove_write_in_mid) {
  char src[200] = "Hate";
  char src2[200] = "Hate";
  s21_size_t copy_kByte = 4;
  char res[200] = "i hate memcmp";
  char expected[200] = "i hate memcmp";
  s21_size_t check_kByte = 17;
  s21_memmove(res + 5, src, copy_kByte);
  memmove(expected + 5, src2, copy_kByte);
  ck_assert_mem_eq(res, expected, check_kByte);
}
END_TEST

START_TEST(memmove_overlap_write_in_left) {
  char src[200] = "I HATE memmove!!!";
  char src2[200] = "I HATE memmove!!!";
  s21_size_t copy_kByte = 17;
  char *res = src;
  char *expected = src2;
  s21_size_t check_kByte = 34;
  s21_memmove(res, src, copy_kByte);
  memmove(expected, src2, copy_kByte);
  ck_assert_mem_eq(res, expected, check_kByte);
}
END_TEST

START_TEST(memmove_overlap_write_in_right) {
  char src[200] = "I HATE memmove!!!";
  char src2[200] = "I HATE memmove!!!";
  s21_size_t copy_kByte = 17;
  char *res = src + 17;
  char *expected = src2 + 17;
  s21_size_t check_kByte = 34;
  s21_memmove(res, src, copy_kByte);
  memmove(expected, src2, copy_kByte);
  ck_assert_mem_eq(res, expected, check_kByte);
}
END_TEST

START_TEST(memmove_overlap_write_in_mid) {
  char src[200] = "I HATE memmove!!!";
  char src2[200] = "I HATE memmove!!!";
  s21_size_t copy_kByte = 17;
  char *res = src + 5;
  char *expected = src2 + 5;
  s21_size_t check_kByte = 34;
  s21_memmove(res, src, copy_kByte);
  memmove(expected, src2, copy_kByte);
  ck_assert_mem_eq(res, expected, check_kByte);
}
END_TEST

START_TEST(memmove_zero_test_string) {
  char src[] = "aboba";
  s21_size_t kByte = 0;
  char res[kByte + 8];
  char expected[kByte + 8];
  s21_memmove(res, src, kByte);
  memmove(expected, src, kByte);
  ck_assert_mem_eq(res, expected, kByte);
}
END_TEST

START_TEST(memmove_any_empty) {
  char src[] = "";
  s21_size_t kByte = 0;
  char res[kByte + 8];
  char expected[kByte + 8];
  s21_memmove(res, src, kByte);
  memmove(expected, src, kByte);
  ck_assert_mem_eq(res, expected, kByte);
}
END_TEST

START_TEST(memmove_zero_test_string_with_register) {
  char src[] = "I hate memcmp";
  s21_size_t kByte = 0;
  char res[kByte + 8];
  char expected[kByte + 8];
  s21_memmove(res, src, kByte);
  memmove(expected, src, kByte);
  ck_assert_mem_eq(res, expected, kByte);
}
END_TEST

START_TEST(memmove_zero_test_num) {
  char src[] = "123";
  s21_size_t kByte = 1;
  char res[kByte + 8];
  char expected[kByte + 8];
  s21_memmove(res, src, kByte);
  memmove(expected, src, kByte);
  ck_assert_mem_eq(res, expected, kByte);
}
END_TEST

START_TEST(memmove_one_byte_string) {
  char src[] = "aboba";
  s21_size_t kByte = 1;
  char res[kByte + 8];
  char expected[kByte + 8];
  s21_memmove(res, src, kByte);
  memmove(expected, src, kByte);
  ck_assert_mem_eq(res, expected, kByte);
}
END_TEST

START_TEST(memmove_one_byte_string_with_register) {
  char src[] = "Zboba";
  s21_size_t kByte = 1;
  char res[kByte + 8];
  char expected[kByte + 8];
  s21_memmove(res, src, kByte);
  memmove(expected, src, kByte);
  ck_assert_mem_eq(res, expected, kByte);
}
END_TEST

START_TEST(memmove_one_byte_num) {
  char src[] = "09";
  s21_size_t kByte = 1;
  char res[kByte + 8];
  char expected[kByte + 8];
  s21_memmove(res, src, kByte);
  memmove(expected, src, kByte);
  ck_assert_mem_eq(res, expected, kByte);
}
END_TEST

START_TEST(memmove_basic_long_string) {
  char src[] = "abobasdafoijasdofjas asdopij";
  s21_size_t kByte = 28;
  char res[kByte + 8];
  char expected[kByte + 8];
  s21_memmove(res, src, kByte);
  memmove(expected, src, kByte);
  ck_assert_mem_eq(res, expected, kByte);
}
END_TEST

START_TEST(memmove_long_string_with_register) {
  char src[] = "aposkd AOSIjFasodijpaoisdjf poisdjfg";
  s21_size_t kByte = 36;
  char res[kByte + 8];
  char expected[kByte + 8];
  s21_memmove(res, src, kByte);
  memmove(expected, src, kByte);
  ck_assert_mem_eq(res, expected, kByte);
}
END_TEST

START_TEST(memmove_long_string_with_register_and_num) {
  char src[] = "aodasf ieuwfh luhasdfLIAUSHD liuh 12li3uh 12i4ouhsdfh";
  s21_size_t kByte = 53;
  char res[kByte + 8];
  char expected[kByte + 8];
  s21_memmove(res, src, kByte);
  memmove(expected, src, kByte);
  ck_assert_mem_eq(res, expected, kByte);
}
END_TEST

START_TEST(memmove_long_string_with_register_and_num_and_simbol) {
  char src[] =
      "()()(((())):!,....aodasf ieuwfh luhasdfLIAUSHD liuh 12li3uh12i4ouhsdfh";
  s21_size_t kByte = 71;
  char res[kByte + 8];
  char expected[kByte + 8];
  s21_memmove(res, src, kByte);
  memmove(expected, src, kByte);
  ck_assert_mem_eq(res, expected, kByte);
}
END_TEST

START_TEST(memmove_ints) {
  int src[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  s21_size_t kByte = 4;
  char res[kByte + 8];
  char expected[kByte + 8];
  s21_memmove(res, src, kByte);
  memmove(expected, src, kByte);
  ck_assert_mem_eq(res, expected, kByte);
}
END_TEST

START_TEST(memmove_floats) {
  float src[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  s21_size_t kByte = 8;
  char res[kByte + 8];
  char expected[kByte + 8];
  s21_memmove(res, src, kByte);
  memmove(expected, src, kByte);
  ck_assert_mem_eq(res, expected, kByte);
}
END_TEST

START_TEST(memmove_long_doubels) {
  long double src[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  s21_size_t kByte = 16;
  char res[kByte + 8];
  char expected[kByte + 8];
  s21_memmove(res, src, kByte);
  memmove(expected, src, kByte);
  ck_assert_mem_eq(res, expected, kByte);
}
END_TEST
// // memmove <-

// memset ->
START_TEST(memset_aboba_test) {
  char res[] = "aboba";
  char expected[] = "aboba";
  char replace = 'g';
  s21_size_t n_byte = 5;
  s21_memset(res, replace, n_byte);
  memset(expected, replace, n_byte);
  ck_assert_str_eq(res, expected);
}
END_TEST

START_TEST(memset_zero_byte) {
  char res[] = "aboba";
  char expected[] = "aboba";
  char replace = 'g';
  s21_size_t n_byte = 0;
  s21_memset(res, replace, n_byte);
  memset(expected, replace, n_byte);
  ck_assert_str_eq(res, expected);
}
END_TEST

START_TEST(memset_empty) {
  char res[] = "";
  char expected[] = "";
  char replace = '\0';
  s21_size_t n_byte = 0;
  s21_memset(res, replace, n_byte);
  memset(expected, replace, n_byte);
  ck_assert_str_eq(res, expected);
}
END_TEST

START_TEST(memset_replace_on_register_sim) {
  char res[] = "aboba";
  char expected[] = "aboba";
  char replace = 'A';
  s21_size_t n_byte = 3;
  s21_memset(res, replace, n_byte);
  memset(expected, replace, n_byte);
  ck_assert_str_eq(res, expected);
}
END_TEST

START_TEST(memset_replace_on_register_num) {
  char res[] = "a1obA";
  char expected[] = "a1obA";
  char replace = '1';
  s21_size_t n_byte = 5;
  s21_memset(res, replace, n_byte);
  memset(expected, replace, n_byte);
  ck_assert_str_eq(res, expected);
}
END_TEST

START_TEST(memset_long_string) {
  char res[] =
      "a1oas[pifjaosidfj oapisjdfpoi asjdfoij ouh12oi3 uh12i3 "
      "hiajhIOUAHSDiouAHSdu1).bA";
  char expected[] =
      "a1oas[pifjaosidfj oapisjdfpoi asjdfoij ouh12oi3 uh12i3 "
      "hiajhIOUAHSDiouAHSdu1).bA";
  char replace = '1';
  s21_size_t n_byte = 5;
  s21_memset(res, replace, n_byte);
  memset(expected, replace, n_byte);
  ck_assert_str_eq(res, expected);
}
END_TEST
// memset <-

// memcmp ->
START_TEST(memcmp_zero_byte) {
  char str1[] = "aboba";
  char str2[] = "aboba";
  int n = 0;
  ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

START_TEST(memcmp_first_byte_in_string) {
  char str1[] = "aboba";
  char str2[] = "aboba";
  int n = 3;
  ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

START_TEST(memcmp_register_test) {
  char str1[] = "aboba";
  char str2[] = "Aboba";
  int n = 1;
  ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

START_TEST(memcmp_zero_byte_in_num) {
  char str1[] = "1";
  char str2[] = "1";
  int n = 0;
  ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

START_TEST(memcmp_first_byte_in_num) {
  char str1[] = "1";
  char str2[] = "1234";
  int n = 1;
  ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

START_TEST(memcmp_two_byte_in_num) {
  char str1[] = "1234";
  char str2[] = "1234";
  int n = 2;
  ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

START_TEST(memcmp_two_byte_long_two_num) {
  char str1[] = "13";
  char str2[] = "1234";
  int n = 2;
  ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

START_TEST(memcmp_two_byte_long_first_num) {
  char str1[] = "134567";
  char str2[] = "1234";
  int n = 2;
  ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

START_TEST(memcmp_eq_long_string) {
  char str1[] =
      "111111111111111111112312312312312312434524563567adsfe 4rafa ewfseASDASD";
  char str2[] =
      "111111111111111111112312312312312312434524563567adsfe 4rafa ewfseASDASD";
  int n = 71;
  ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

START_TEST(memcmp_not_eq_long_string) {
  char str1[] =
      "111111111111111111112312312312312312434524563567adsfe 4rafa ewfseASDASD";
  char str2[] =
      "111111111111111111112312312312312312434524563567adsfe 4rafa ewfseASDASd";
  int n = 71;
  ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST
// memcmp <-

// memchr ->
START_TEST(memchr_empty_str) {
  s21_size_t n_byte = 0;
  char str[10] = "";
  int find_byte = '\0';
  ck_assert_ptr_eq(s21_memchr(str, find_byte, n_byte),
                   memchr(str, find_byte, n_byte));
}
END_TEST

START_TEST(memchr_find_zero_in_string) {
  s21_size_t n_byte = 7;
  char str[10] = "string";
  int find_byte = '\0';
  ck_assert_ptr_eq(s21_memchr(str, find_byte, n_byte),
                   memchr(str, find_byte, n_byte));
}
END_TEST

START_TEST(memchr_find_simbol_in_string_in_start) {
  s21_size_t n_byte = 6;
  char str[10] = "Atring";
  int find_byte = 'A';
  ck_assert_ptr_eq(s21_memchr(str, find_byte, n_byte),
                   memchr(str, find_byte, n_byte));
}
END_TEST

START_TEST(memchr_find_simbol_in_string_in_end) {
  s21_size_t n_byte = 7;
  char str[10] = "StringA";
  int find_byte = 'A';
  ck_assert_ptr_eq(s21_memchr(str, find_byte, n_byte),
                   memchr(str, find_byte, n_byte));
}
END_TEST

START_TEST(memchr_find_num_in_string_in_mid) {
  s21_size_t n_byte = 15;
  char str[16] = "Str55333222ingA";
  int find_byte = '3';
  ck_assert_ptr_eq(s21_memchr(str, find_byte, n_byte),
                   memchr(str, find_byte, n_byte));
}
END_TEST

START_TEST(memchr_find_num_in_array_num) {
  int array[] = {1, 2, 3, 666, 5, 99, 100};
  s21_size_t n_byte = sizeof(int) * 7;
  int find_byte = 666;
  ck_assert_ptr_eq(s21_memchr(array, find_byte, n_byte),
                   memchr(array, find_byte, n_byte));
}
END_TEST

START_TEST(memchr_find_float_in_array) {
  float array[] = {1, 2, 3, 666, 5, 99, 100};
  s21_size_t n_byte = sizeof(float) * 7;
  int find_byte = 666;
  ck_assert_ptr_eq(s21_memchr(array, find_byte, n_byte),
                   memchr(array, find_byte, n_byte));
}
END_TEST

START_TEST(memchr_easy_test_string) {
  s21_size_t n_byte = 5;
  char str[10] = "aboba";
  int find_byte = 'c';
  ck_assert_ptr_eq(s21_memchr(str, find_byte, n_byte),
                   memchr(str, find_byte, n_byte));
}
END_TEST
// memchr <-

// insert ->
START_TEST(insert_test1) {
  char str[] = "Shlepa";
  char src[] = "I love my . He is very kind!";
  s21_size_t index = 10;
  char expected[] = "I love my Shlepa. He is very kind!";
  char *got = (char *)s21_insert(src, str, index);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST

START_TEST(insert_test2) {
  char str[] = "Hello, ";
  char src[] = "Aboba!";
  s21_size_t index = 0;
  char expected[] = "Hello, Aboba!";
  char *got = (char *)s21_insert(src, str, index);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST

START_TEST(insert_test3) {
  char str[] = "";
  char src[] = "";
  s21_size_t index = 100;
  char *expected = S21_NULL;
  char *got = (char *)s21_insert(src, str, index);
  ck_assert_pstr_eq(got, expected);
  if (got) free(got);
}
END_TEST

START_TEST(insert_test4) {
  char *src = S21_NULL;
  char *str = S21_NULL;
  s21_size_t index = 100;
  char *expected = S21_NULL;
  char *got = (char *)s21_insert(src, str, index);
  ck_assert_ptr_eq(got, expected);
  if (got) free(got);
}
END_TEST

START_TEST(insert_test5) {
  char str[] = "Monkey";
  char src[] = "Space  ";
  s21_size_t index = 6;
  char expected[] = "Space Monkey ";
  char *got = (char *)s21_insert(src, str, index);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST

/*------------------------s21_memchr---------------------*/
START_TEST(s21_memchr_test) {
  ck_assert_uint_eq((long unsigned int)s21_memchr("School21Sc", 'c', 4),
                    (long unsigned int)memchr("School21Sc", 'c', 4));
  ck_assert_uint_eq((long unsigned int)s21_memchr("School21Sc", ' ', 4),
                    (long unsigned int)memchr("School21Sc", ' ', 4));
  ck_assert_uint_eq((long unsigned int)s21_memchr("Hello", '\0', 3),
                    (long unsigned int)memchr("Hello", '\0', 3));
  ck_assert_uint_eq((long unsigned int)s21_memchr("Hello", 13, 15),
                    (long unsigned int)memchr("Hello", 13, 15));
  ck_assert_uint_eq((long unsigned int)s21_memchr("School21Sc", 'h', 1),
                    (long unsigned int)memchr("School21Sc", 'h', 1));
  ck_assert_uint_eq((long unsigned int)s21_memchr("School21Sc", '3', 8),
                    (long unsigned int)memchr("School21Sc", '3', 8));
  ck_assert_uint_eq((long unsigned int)s21_memchr("School21Sc", 'S', 9),
                    (long unsigned int)memchr("School21Sc", 'S', 9));
}
END_TEST
/*------------------------s21_memcmp---------------------*/
START_TEST(s21_memcmp_test) {
  ck_assert_int_eq(s21_memcmp("School21", "School42", 7) < 0,
                   memcmp("School21", "School42", 7) < 0);
  ck_assert_int_eq(s21_memcmp("vGyiig\0", "vbvcnj\0", 5) > 0,
                   memcmp("vGyiig\0", "vbvcnj\0", 5) > 0);
  ck_assert_int_eq(s21_memcmp("isrgf uesyrfo UYEWGU duf", "\0", 2) < 0,
                   memcmp("isrgf uesyrfo UYEWGU duf", "\0", 2) < 0);
  ck_assert_int_eq(s21_memcmp("isrgf uesyrfo UYEWGU duf", "\0", 0) < 0,
                   memcmp("isrgf uesyrfo UYEWGU duf", "\0", 0) < 0);
}
END_TEST
/*------------------------s21_memcpy---------------------*/

START_TEST(s21_memcpy_test) {
  char destination[20] = "";
  char where[30] = "Supernova";
  ck_assert_str_eq(s21_memcpy(destination, "Mirage", 3),
                   memcpy(destination, "Mirage", 3));
  ck_assert_str_eq(s21_memcpy(destination, "Mirage", 7),
                   memcpy(destination, "Mirage", 7));
  ck_assert_str_eq(s21_memcpy(where, "Galaxy", 6), memcpy(where, "Galaxy", 6));
  ck_assert_str_eq(s21_memcpy(where, "Galaxy", 0), memcpy(where, "Galaxy", 0));
  char test_1[10] = "dfghdtrt";
  char test_2[] = "  ";
  char test_3[20] = "$$$$$#@";
  char test_4[] = "Ldjgoe";
  char test_5[30] = "";
  char test_6[] = "2323";
  char test_7[] = "123\0123";

  ck_assert_str_eq(s21_memcpy(test_1, test_2, 2), memcpy(test_1, test_2, 2));
  ck_assert_str_eq(s21_memcpy(test_3, test_4, 6), memcpy(test_3, test_4, 6));
  ck_assert_str_eq(s21_memcpy(test_5, test_6, 4), memcpy(test_5, test_6, 4));
  ck_assert_str_eq(s21_memcpy(test_5, test_7, 6), memcpy(test_5, test_7, 6));
}
END_TEST
/*------------------------s21_memmove---------------------*/
START_TEST(s21_memmove_test) {
  s21_size_t n = 4;

  char dest_cover[] = "1234567";
  char *src_cover = dest_cover + 2;
  ck_assert_str_eq(memmove(dest_cover, src_cover, n),
                   s21_memmove(dest_cover, src_cover, n));

  char s[] = "abcdefghijklm";
  char *p1 = s;
  char *p2 = s + 3;
  ck_assert_str_eq(s21_memmove(p2, p1, 6), memmove(p2, p1, 6));
  p2 = s + 4;
  ck_assert_str_eq(s21_memmove(p2, p1, 10), memmove(p2, p1, 10));
  p2 = s + 1;

  ck_assert_str_eq(s21_memmove(p2, p1, 9), memmove(p2, p1, 9));
  char str[50] = "Hello";
  ck_assert_str_eq(s21_memmove(str, str + 2, 2), memmove(str, str + 2, 2));
}
END_TEST
/*------------------------s21_memset---------------------*/
START_TEST(s21_memset_test) {
  unsigned char test1[10] = "1234357890";
  unsigned char test2[10] = "hello";
  ck_assert_uint_eq((unsigned long)s21_memset(test1, '1', 10),
                    (unsigned long)memset(test1, '1', 10));
  ck_assert_uint_eq((unsigned long)s21_memset(test1, '3', 10),
                    (unsigned long)memset(test1, '3', 10));
  ck_assert_uint_eq((unsigned long)s21_memset(test1, '/', 8),
                    (unsigned long)memset(test1, '/', 8));
  ck_assert_uint_eq((unsigned long)s21_memset(test1, '9', 0),
                    (unsigned long)memset(test1, '9', 0));
  ck_assert_uint_eq((unsigned long)s21_memset(test1, '0', 4),
                    (unsigned long)memset(test1, '0', 4));
  ck_assert_uint_eq((unsigned long)s21_memset(test2, '1', 3),
                    (unsigned long)memset(test2, '1', 3));
}
/*------------------------s21_strlen---------------------*/
START_TEST(s21_strlen_test) {
  ck_assert_int_eq(s21_strlen("School21School21_School42"),
                   strlen("School21School21_School42"));
  ck_assert_int_eq(s21_strlen(""), strlen(""));
  ck_assert_int_eq(s21_strlen("School"), strlen("School"));
  ck_assert_int_eq(s21_strlen("346\0r4g\0"), strlen("346\0r4g\0"));
  ck_assert_int_eq(s21_strlen("      "), strlen("      "));
}
END_TEST
/*------------------------s21_strcpy---------------------*/
START_TEST(s21_strcpy_test) {
  char test_1[] = "346\0r4g\0";
  char test_2[] = "Hello,";
  char test_3[] = "8888";
  char test_4[] = "Hello, World!\0";
  char test_5[128] = "";
  char test_6[] = "sddsf3\088";
  ck_assert_str_eq(s21_strcpy(test_1, test_2), strcpy(test_1, test_2));
  ck_assert_str_eq(s21_strcpy(test_2, test_3), strcpy(test_2, test_3));
  ck_assert_str_eq(s21_strcpy(test_4, test_5), strcpy(test_4, test_5));
  ck_assert_str_eq(s21_strcpy(test_5, test_4), strcpy(test_5, test_4));
  ck_assert_str_eq(s21_strcpy(test_6, test_5), strcpy(test_6, test_5));
}
END_TEST
/*------------------------s21_strncpy---------------------*/
START_TEST(s21_strncpy_test) {
  char dest[] = "567";
  char src[] = "132";
  char dest1[] = "";
  char src1[] = "abc";
  char dest2[] = "34566";
  char src2[] = "567";
  char dest3[] = "Okno, lampochka";
  char src3[] = "potolok";
  char dest4[] = "\n/f\f/n";
  char src4[] = "\0\n";
  char dest5[] = "Duck Tales, woo";
  char dest6[] = "\ngg";
  char src6[] = "\0\nhhlove";
  ck_assert_str_eq(s21_strncpy(dest1, dest1, 1), strncpy(dest1, dest1, 1));
  ck_assert_str_eq(s21_strncpy(dest2, src2, 0), strncpy(dest2, src2, 0));
  ck_assert_str_eq(s21_strncpy(dest, src, 4), strncpy(dest, src, 4));
  ck_assert_str_eq(s21_strncpy(dest1, src1, 0), strncpy(dest1, src1, 0));

  ck_assert_str_eq(s21_strncpy(dest3, src3, 8), strncpy(dest3, src3, 8));
  ck_assert_str_eq(s21_strncpy(dest4, src4, 2), strncpy(dest4, src4, 2));
  ck_assert_str_eq(s21_strncpy(dest5, src, 4), strncpy(dest5, src, 4));
  ck_assert_str_eq(s21_strncpy(dest5, dest2, 7), strncpy(dest5, dest2, 7));
  ck_assert_str_eq(s21_strncpy(dest6, src6, 3), strncpy(dest6, src6, 3));
}
END_TEST

/*------------------------s21_strcmp---------------------*/
START_TEST(s21_strcmp_test) {
  ck_assert_int_eq(s21_strcmp("shit48447", "school21") > 0,
                   strcmp("shit48447", "school21") > 0);
  ck_assert_int_eq(s21_strcmp("School21School21_School42", "Moscow") > 0,
                   strcmp("School21School21_School42", "Moscow") > 0);
  ck_assert_int_eq(s21_strcmp("shit48447", "Moscow") > 0,
                   strcmp("shit48447", "Moscow") > 0);
}
END_TEST
/*------------------------s21_strncmp---------------------*/
START_TEST(s21_strncmp_test) {
  ck_assert_int_eq(s21_strncmp("school42", "school21", 4) == 0,
                   strncmp("school42", "school21", 4) == 0);
  ck_assert_int_eq(s21_strncmp("shit48447", "school21", 6) > 0,
                   strncmp("shit48447", "school21", 6) > 0);
  ck_assert_int_eq(s21_strncmp("shit48447", "school21", 0),
                   strncmp("shit48447", "school21", 0));
}
END_TEST
/*------------------------s21_strpbrk---------------------*/
START_TEST(s21_strpbrk_test) {
  ck_assert_ptr_eq(strpbrk("\0", "Non scholae sed vitae discimus"),
                   s21_strpbrk("\0", "Non scholae sed vitae discimus"));
  ck_assert_ptr_eq(strpbrk("Non scholae sed vitae discimus", "ed"),
                   s21_strpbrk("Non scholae sed vitae discimus", "ed"));
  ck_assert_ptr_eq(strpbrk(".Q|..QT.WERTY, , , |", ".,dj|.."),
                   s21_strpbrk(".Q|..QT.WERTY, , , |", ".,dj|.."));
  ck_assert_ptr_eq(strpbrk(" \n\0\0", ".Q|..QT.WERTY"),
                   s21_strpbrk(" \n\0\0", ".Q|..QT.WERTY"));
  ck_assert_ptr_eq(strpbrk(".Q|..QT\n.WERT\0Y", " \n\0\0"),
                   s21_strpbrk(".Q|..QT\n.WERT\0Y", " \n\0\0"));
  ck_assert_ptr_eq(strpbrk("Non scholae", "\0"),
                   s21_strpbrk("Non scholae", "\0"));
  ck_assert_ptr_eq(strpbrk("fufufufufu", "fufufufufu"),
                   s21_strpbrk("fufufufufu", "fufufufufu"));
  ck_assert_ptr_eq(strpbrk("fufufufufu", "ttt"),
                   s21_strpbrk("fufufufufu", "ttt"));
  ck_assert_ptr_eq(strpbrk("", "fufufufufu"), s21_strpbrk("", "fufufufufu"));
  ck_assert_ptr_eq(strpbrk(" ", "fufufufufu"), s21_strpbrk(" ", "fufufufufu"));
  ck_assert_ptr_eq(strpbrk("fufufufufu", " "), s21_strpbrk("fufufufufu", " "));
}
END_TEST
/*------------------------s21_strchr---------------------*/
START_TEST(s21_strchr_test) {
  char str[] = "Ab absurdo";
  int c = 10;
  ck_assert_ptr_eq(s21_strchr(str, c), strchr(str, c));
  char str1[] = "Ab \0absurdo\0";
  int b = 0;
  ck_assert_ptr_eq(s21_strchr(str1, b), strchr(str1, b));
  ck_assert_ptr_eq(s21_strchr(str, b), strchr(str, b));
  char new[] = "k";
  int d = 'a';
  ck_assert_ptr_eq(s21_strchr(new, d), strchr(new, d));
  char newnew[] = "\naaa\0a";
  ck_assert_ptr_eq(s21_strchr(newnew, d), strchr(newnew, d));
  char newnewnew[] = "";
  ck_assert_ptr_eq(s21_strchr(newnewnew, d), strchr(newnewnew, d));
  ck_assert_ptr_eq(s21_strchr(str, d), strchr(str, d));
  char string[] = "fhfhAjfA||./dowoje//d,,..|";
  int t = '/';
  int g = '|';
  ck_assert_ptr_eq(s21_strchr(string, t), strchr(string, t));
  ck_assert_ptr_eq(s21_strchr(string, g), strchr(string, g));
}
END_TEST
/*------------------------s21_strrchr---------------------*/
START_TEST(s21_strrchr_test) {
  char string[] = "fhfhAjfA||./dowoje//d,,..|";
  int t = '/';
  int g = '|';
  ck_assert_ptr_eq(s21_strrchr(string, t), strrchr(string, t));
  ck_assert_ptr_eq(s21_strrchr(string, g), strrchr(string, g));
  int d = 'a';
  char newnew[] = "\naaa\0a";
  ck_assert_ptr_eq(s21_strrchr(newnew, d), strrchr(newnew, d));

  char str[] = "Ab absurdo";
  int c = 10;
  ck_assert_ptr_eq(s21_strrchr(str, c), strrchr(str, c));
  char str1[] = "Ab \0absurdo\0";
  int b = 0;
  ck_assert_ptr_eq(s21_strrchr(str1, b), strrchr(str1, b));
  ck_assert_ptr_eq(s21_strrchr(str, b), strrchr(str, b));
  char new[] = "k";
  ck_assert_ptr_eq(s21_strrchr(new, d), strrchr(new, d));
}
END_TEST
/*------------------------s21_strspn---------------------*/
START_TEST(s21_strspn_test) {
  char string[] = "fhfhAjfA||./dowoje//d,,..|";
  char symbols[] = "/abcdef.,";
  char symbols_neg[] = "3287432764";
  char str[] = "Hello world\0dg234asfd76";
  char sym[] = "\0";
  char sym_n[] = "\n";
  char space[] = "   ";
  char nothing[] = "";
  char d[] = "d";
  ck_assert_int_eq(strspn(string, symbols), s21_strspn(string, symbols));
  ck_assert_int_eq(strspn(string, symbols_neg),
                   s21_strspn(string, symbols_neg));
  ck_assert_int_eq(strspn(str, sym), s21_strspn(str, sym));
  ck_assert_int_eq(strspn(str, sym_n), s21_strspn(str, sym_n));
  ck_assert_int_eq(strspn(string, nothing), s21_strspn(string, nothing));
  ck_assert_int_eq(strspn(str, space), s21_strspn(str, space));
  ck_assert_int_eq(strspn(string, space), s21_strspn(string, space));
  ck_assert_int_eq(strspn(string, d), s21_strspn(string, d));
  ck_assert_int_eq(strspn(str, symbols_neg), s21_strspn(str, symbols_neg));
}
END_TEST
/*------------------------s21_strcspn--------------------*/
START_TEST(s21_strcspn_test) {
  char test1[] = "fhfhAjfA||./dowoje//d,,..|";
  char test2[] = "/abcdef.,";
  char test3[] = "3287432764";
  char test4[] = "Hello world\0dg234asfd76";
  char test5[] = "\0";
  char test6[] = "%%\\#";
  char test7[] = "   ";
  char test8[] = "1234567890";
  ck_assert_uint_eq(s21_strcspn(test1, test2), strcspn(test1, test2));
  ck_assert_uint_eq(s21_strcspn(test3, test4), strcspn(test3, test4));
  ck_assert_uint_eq(s21_strcspn(test3, test5), strcspn(test3, test5));
  ck_assert_uint_eq(s21_strcspn(test3, test6), strcspn(test3, test6));
  ck_assert_uint_eq(s21_strcspn(test3, test7), strcspn(test3, test7));
  ck_assert_uint_eq(s21_strcspn(test4, test8), strcspn(test4, test8));
  ck_assert_uint_eq(s21_strcspn(test2, test7), strcspn(test2, test7));
}
END_TEST
/*------------------------s21_strcat---------------------*/
START_TEST(s21_strcat_test) {
  char test1[50] = "A majore ad minus\0";
  char test3[50] = "\0";
  char *new_str_1 = s21_strcat(test1, test3);
  ck_assert_str_eq(new_str_1, strcat(test1, test3));

  char dest[30] = "School21";
  char src[30] = "School42";
  char *new_str = s21_strcat(dest, src);
  ck_assert_str_eq(new_str, strcat(dest, src));

  char dest1[40] = "shfbvoiesb\0hvosubhvoiehbvohebv\0\0";
  char src1[30] = "";
  char *new_str1 = s21_strcat(dest1, src1);
  char *new_str2 = s21_strcat(dest1, src1);
  ck_assert_str_eq(new_str1, strcat(dest1, src1));
  ck_assert_str_eq(new_str2, strcat(dest1, src1));
}
END_TEST
/*------------------------s21_strtok---------------------*/
START_TEST(s21_strtok_test) {
  char s1[] = "Helllllllo,      worllllllllllld! And lother people      ";
  char s2[] = "Helllllllo,      worllllllllllld! And lother people      ";
  char s3[] = "Come here";
  char s4[] = "Come here";
  char s5[] = "l";
  char s6[] = " ";

  ck_assert_str_eq(strtok(s1, s5), s21_strtok(s2, s5));
  for (int i = 0; i < 5; i++) {
    ck_assert_pstr_eq(strtok(S21_NULL, s6), s21_strtok(S21_NULL, s6));
  }
  ck_assert_pstr_eq(strtok(s3, s6), s21_strtok(s4, s6));
  ck_assert_pstr_eq(strtok(S21_NULL, s6), s21_strtok(S21_NULL, s6));
  ck_assert_pstr_eq(strtok(S21_NULL, s6), s21_strtok(S21_NULL, s6));
  char str111[40] = "qwerty";
  char str222[40] = "1234/5678/92046/";
  char strochka[40] = "||.|WER|T.Y|W";
  char separ[30] = "||/.";
  char sym[40] = "W";
  char string[40] = "./||.QWERTYNOTEBOOK..//.";
  ck_assert_pstr_eq(s21_strtok(str111, separ), strtok(str111, separ));
  ck_assert_pstr_eq(s21_strtok(str222, separ), strtok(str222, separ));
  ck_assert_pstr_eq(s21_strtok(strochka, separ), strtok(strochka, separ));
  ck_assert_pstr_eq(s21_strtok(strochka, sym), strtok(strochka, sym));
  ck_assert_pstr_eq(s21_strtok(string, separ), strtok(string, separ));
  ck_assert_pstr_eq(s21_strtok(separ, sym), strtok(separ, sym));
  ck_assert_pstr_eq(s21_strtok(string, separ), strtok(string, separ));
  /*------------------------------------------------------------------*/
  char str1[] = "Hello,       world! And other people";
  char str2[] = "Hello,       world! And other people";
  char str3[] = "RossiaLuxembourgPoland";
  char str4[] = "RossiaLuxembourgPoland";
  char str5[] = " o";

  ck_assert_pstr_eq(strtok(str1, str5), s21_strtok(str2, str5));
  for (int i = 0; i < 5; i++) {
    ck_assert_pstr_eq(strtok(S21_NULL, str5), s21_strtok(S21_NULL, str5));
  }

  ck_assert_pstr_eq(strtok(str3, str5), s21_strtok(str4, str5));
  for (int i = 0; i < 5; i++) {
    ck_assert_pstr_eq(strtok(S21_NULL, str5), s21_strtok(S21_NULL, str5));
  }
  /*------------------------------------------------------------------*/
  char sep3[] = ".//&";

  char *ptr1, *ptr2;
  ptr1 = strtok(str1, str5);
  ptr2 = s21_strtok(str2, str5);

  while (ptr1 != S21_NULL) {
    ck_assert_pstr_eq(ptr1, ptr2);
    ptr1 = strtok(S21_NULL, sep3);
    ptr2 = s21_strtok(S21_NULL, sep3);
  }
  /*------------------------------------------------------------------*/
  //   char s1[] = "Hello,      worllllllllllld! And lother people      ";
  //   char s2[] = "Hello,      worllllllllllld! And lother people      ";
  //   char s3[] = "School21";
  //   char s4[] = "School21";
  //   char s5[] = "q";

  //   ck_assert_pstr_eq(strtok(s3, s5), s21_strtok(s4, s5));
  //   for (int i = 0; i < 5; i++) {
  //     ck_assert_pstr_eq(strtok(s3, s5), s21_strtok(s4, s5));
  //   }

  //   ck_assert_pstr_eq(strtok(s1, s5), s21_strtok(s2, s5));
  //   for (int i = 0; i < 5; i++) {
  //     ck_assert_pstr_eq(strtok(S21_NULL, s5), s21_strtok(S21_NULL, s5));
  //   }
}
END_TEST
/*------------------------s21_strstr---------------------*/
START_TEST(s21_strstr_test) {
  char test1[30] = "A majore ad minus house";
  char test2[30] = "house";
  char test3[30] = "&";
  char test5[] = "";
  char test4[] = "shfbvoiesb\0hvosubhvoiehbvohebv\0\0";
  char test6[] = "\0";
  char test7[] = "voies";
  char test8[] = "abc";

  ck_assert_ptr_eq(strstr(test1, test2), s21_strstr(test1, test2));
  ck_assert_ptr_eq(strstr(test1, test3), s21_strstr(test1, test3));
  ck_assert_ptr_eq(strstr(test2, test8), s21_strstr(test2, test8));
  ck_assert_ptr_eq(strstr(test2, test3), s21_strstr(test2, test3));
  ck_assert_ptr_eq(strstr(test7, test6), s21_strstr(test7, test6));
  ck_assert_ptr_eq(strstr(test6, test7), s21_strstr(test6, test7));
  ck_assert_ptr_eq(strstr(test4, test5), s21_strstr(test4, test5));
}
END_TEST
/*------------------------s21_strncat---------------------*/
START_TEST(s21_strncat_test) {
  char test1[30] = "house";
  char test2[30] = "A majore ad minus";
  ck_assert_str_eq(strncat(test1, test2, 3), s21_strncat(test1, test2, 3));

  char str_1[100] = "Hello";
  char str_2[100] = " World";
  ck_assert_str_eq(strncat(str_1, str_2, 3), s21_strncat(str_1, str_2, 3));

  char str_3[100] = "\0";
  char str_4[100] = "quit";
  ck_assert_str_eq(strncat(str_3, str_4, 13), s21_strncat(str_3, str_4, 13));

  char str_5[100] = "\n";
  char str_6[100] = "\0frihiufeief";
  ck_assert_str_eq(strncat(str_5, str_6, 9), s21_strncat(str_5, str_6, 9));

  char str_7[100] = "refrigerator";
  char str_8[100] = "\0";
  ck_assert_str_eq(strncat(str_7, str_8, 2), s21_strncat(str_7, str_8, 2));

  char str_9[100] = "cats";
  char str_10[100] = "  4 \n";
  ck_assert_str_eq(strncat(str_9, str_10, 5), s21_strncat(str_9, str_10, 5));

  char str_11[100] = "23 ";
  char str_12[100] = "123";
  ck_assert_str_eq(strncat(str_11, str_12, 0), s21_strncat(str_11, str_12, 0));

  char str_13[100] = " 0 ";
  char str_14[100] = "qwer";
  ck_assert_str_eq(strncat(str_13, str_14, 0 + 2),
                   s21_strncat(str_13, str_14, 0 + 2));

  char str_15[100] = "90";
  char str_16[100] = "error";
  ck_assert_str_eq(strncat(str_15, str_16, 4 - 1),
                   s21_strncat(str_15, str_16, 4 - 1));

  char str_17[100] = "trtrtrt";
  char str_18[100] = "puckKK";
  ck_assert_str_eq(strncat(str_17, str_18, 2 * 2),
                   s21_strncat(str_17, str_18, 2 * 2));

  char s1[255] = "mnhfg";
  char s2[255] = "g";
  ck_assert_pstr_eq(strncat(s1, s2, 6), s21_strncat(s1, s2, 6));
}
END_TEST

START_TEST(test_to_lower_1) {
  char s1[30] = "hello, world!";
  char s3[] = "hELLO, WORLD!";
  char *s2 = s21_to_lower(s3);
  ck_assert_pstr_eq(s1, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_to_lower_2) {
  char s1[30] = "\nh\t\\g123123";
  char s3[] = "\nH\t\\G123123";
  char *s2 = s21_to_lower(s3);
  ck_assert_pstr_eq(s1, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_to_lower_3) {
  char s1[30] = "already lower";
  char s3[] = "already lower";
  char *s2 = s21_to_lower(s3);
  ck_assert_pstr_eq(s1, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_to_lower_4) {
  char s1[30] = "";
  char s3[] = "";
  char *s2 = s21_to_lower(s3);
  ck_assert_pstr_eq(s1, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_to_lower_5) {
  char s1[30] = "abcdefghijklmnopqrstuvwxyz";
  char s3[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  char *s2 = s21_to_lower(s3);
  ck_assert_pstr_eq(s1, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_to_lower_6) {
  char s1[30] = "_?};!234";
  char s3[] = "_?};!234";
  char *s2 = s21_to_lower(s3);
  ck_assert_pstr_eq(s1, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_to_lower_7) {
  char *s1 = S21_NULL;
  char *s3 = S21_NULL;
  char *s2 = s21_to_lower(s3);
  ck_assert_pstr_eq(s1, s2);
  if (s2) free(s2);
}
END_TEST
/*------------------------s21_to_upper---------------------*/
START_TEST(s21_to_upper_test) {
  char *new_str = s21_to_upper("School21+Powered_by_Sber3747477");
  if (new_str) {
    ck_assert_str_eq(new_str, "SCHOOL21+POWERED_BY_SBER3747477");
    free(new_str);
  }
  new_str = s21_to_upper("hello world");
  if (new_str) {
    ck_assert_str_eq(new_str, "HELLO WORLD");
    free(new_str);
  }
}
END_TEST
/*------------------------s21_to_lower------------------------*/
START_TEST(s21_to_lower_test) {
  char *new_str = s21_to_lower("SCHOOL21+POWERED_BY_SBER3747477");
  if (new_str) {
    ck_assert_str_eq(new_str, "school21+powered_by_sber3747477");
    free(new_str);
  }
  new_str = s21_to_lower("HELLO WORLD");
  if (new_str) {
    ck_assert_str_eq(new_str, "hello world");
    free(new_str);
  }
}
END_TEST
/*------------------------s21_insert---------------------*/
START_TEST(s21_insert_test) {
  char *src = "BornToCode";
  char *str = "PoweredBySber";
  char *new_str = s21_insert(src, str, 5);
  if (new_str) {
    ck_assert_str_eq(new_str, "BornTPoweredBySberoCode");
    free(new_str);
  }

  new_str = s21_insert(src, "", 16);
  ck_assert(new_str == S21_NULL);

  new_str = s21_insert("Hello,world", "", 4);
  if (new_str) {
    ck_assert_str_eq(new_str, "Hello,world");
    free(new_str);
  }

  new_str = s21_insert("", "", 0);
  if (new_str) {
    ck_assert_str_eq(new_str, "");
    free(new_str);
  }

  new_str = s21_insert(src, str, 0);
  if (new_str) {
    ck_assert_str_eq(new_str, "PoweredBySberBornToCode");
    free(new_str);
  }
}
END_TEST
/*------------------------s21_trim---------------------*/
START_TEST(s21_trim_test) {
  char *test_str;
  char *str_to_trim2 = "&&*$#fgh+ty++00";
  char *format_str = "&*#0+";
  test_str = s21_trim(str_to_trim2, format_str);
  if (test_str) {
    ck_assert_str_eq(test_str, "$#fgh+ty");
    free(test_str);
  }

  char *str = "Ab000cd0";
  char *trim_ch = "003";
  char *got = s21_trim(str, trim_ch);
  if (got) {
    ck_assert_str_eq(got, "Ab000cd");
    free(got);
  }

  char *trimmed_str;
  char *str_to_trim = " \n   Hello, world!  !\n";
  trimmed_str = s21_trim(str_to_trim, " H!\nd");
  if (trimmed_str) {
    ck_assert_str_eq(trimmed_str, "ello, worl");
    free(trimmed_str);
  }

  char *empty_str = "";
  trimmed_str = s21_trim(empty_str, S21_NULL);
  if (trimmed_str) {
    ck_assert_str_eq(trimmed_str, "");
    free(trimmed_str);
  }

  trimmed_str = s21_trim(empty_str, " \n\0");
  if (trimmed_str) {
    ck_assert_str_eq(trimmed_str, "");
    free(trimmed_str);
  }

  char *empty_format = "";

  char *trim_str;
  trim_str = s21_trim(S21_NULL, empty_format);
  if (trim_str) {
    ck_assert(trim_str == S21_NULL);
    free(trim_str);
  }

  char *str_to_trim21 = "xxx Hello, world! xxx ---";
  char *format_strr = "x -";
  trimmed_str = s21_trim(str_to_trim21, format_strr);
  if (trimmed_str) {
    ck_assert_str_eq(trimmed_str, "Hello, world!");
    free(trimmed_str);
  }

  char *fgot;
  char *stre = "&* !!sc21 * **";
  fgot = s21_trim(stre, "* &!");
  ck_assert_str_eq(fgot, "sc21");
  free(fgot);

  char *space;
  space = s21_trim(S21_NULL, "");
  ck_assert(space == S21_NULL);

  char *spacex = S21_NULL;
  spacex = s21_trim(S21_NULL, "");
  ck_assert(spacex == S21_NULL);

  char *resultt;
  char str45[] = "Sberschool21university";
  char trim_char[] = "21uni";
  char expected[] = "Sberschool21university";
  resultt = s21_trim(str45, trim_char);
  if (resultt) {
    ck_assert_str_eq(resultt, expected);
    free(resultt);
  }

  char *strr = "&&*$#fgh+ty++00";
  char trimmed_ch[] = "&*#0+";
  char expectedly[] = "$#fgh+ty";
  char *gotten = (char *)s21_trim(strr, trimmed_ch);
  ck_assert_str_eq(gotten, expectedly);
  free(gotten);

  char *trimmed_str_new3;
  char *str_to_trim_1 = " Hello, world!  !\n";
  trimmed_str_new3 = s21_trim(str_to_trim_1, "\n");
  if (trimmed_str_new3) {
    ck_assert_str_eq(trimmed_str_new3, " Hello, world!  !");
    free(trimmed_str_new3);
  }
}
END_TEST

/*------------------------s21_strerror---------------------*/
START_TEST(s21_strerror_test) {
  int i = -20000;
  char *original;
  original = strerror(i);
  char *result;
  result = s21_strerror(i);

  ck_assert_str_eq(original, result);

  i = -453653;
  original = strerror(i);
  result = s21_strerror(i);
  ck_assert_str_eq(original, result);

  i = 453653;
  original = strerror(i);
  result = s21_strerror(i);
  ck_assert_str_eq(original, result);

  i = 453;
  char *original5 = strerror(i);
  char *result5 = s21_strerror(i);
  ck_assert_str_eq(original5, result5);

  int j = -678;
  char *original1 = strerror(j);
  char *result1 = s21_strerror(j);
  ck_assert_str_eq(original1, result1);

  char *original3;
  char *result3;

  for (int i = 0; i < 50; i++) {
    original3 = strerror(i);
    result3 = s21_strerror(i);
    ck_assert_str_eq(original3, result3);
  }

  for (int i = -600; i < -400; i++) {
    original3 = strerror(i);
    result3 = s21_strerror(i);
    ck_assert_str_eq(original3, result3);
  }

  for (int i = 400; i < 600; i++) {
    original3 = strerror(i);
    result3 = s21_strerror(i);
    ck_assert_str_eq(original3, result3);
  }
}
END_TEST

/*------------------------s21_sscanf---------------------*/
START_TEST(s21_sscanf_c_test) {
  char *format = "%c";
  char *string = "\n";
  char a1 = 0, a2 = 0, a3 = 0, b1 = 0, b2 = 0, b3 = 0;
  int res1 = s21_sscanf(string, format, &a1);
  int res2 = sscanf(string, format, &b1);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, b1 = 0, b2 = 0, b3 = 0;
  string = "      1\0";
  res1 = s21_sscanf(string, format, &a1);
  res2 = sscanf(string, format, &b1);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, b1 = 0, b2 = 0, b3 = 0;
  string = "\0b";
  res1 = s21_sscanf(string, format, &a1);
  res2 = sscanf(string, format, &b1);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, b1 = 0, b2 = 0, b3 = 0;
  format = "%c %c %c";
  string = "1   3";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3);
  res2 = sscanf(string, format, &b1, &b2, &b3);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, b1 = 0, b2 = 0, b3 = 0;
  string = "    ";
  res1 = s21_sscanf(string, format, &a1, &a2);
  res2 = sscanf(string, format, &b1, &b2);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  // ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, b1 = 0, b2 = 0, b3 = 0;

  string = "\\n\t";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3);
  res2 = sscanf(string, format, &b1, &b2, &b3);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, b1 = 0, b2 = 0, b3 = 0;
  string = "";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3);
  res2 = sscanf(string, format, &b1, &b2, &b3);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, b1 = 0, b2 = 0, b3 = 0;
  string = " sa";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3);
  res2 = sscanf(string, format, &b1, &b2, &b3);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, b1 = 0, b2 = 0, b3 = 0;
  string = "     \n     1     2\t3";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3);
  res2 = sscanf(string, format, &b1, &b2, &b3);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, b1 = 0, b2 = 0, b3 = 0;
  format = "%c%c %c";
  string = "     \n     1     2\t3";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3);
  res2 = sscanf(string, format, &b1, &b2, &b3);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, b1 = 0, b2 = 0, b3 = 0;
  format = "%*c%c%c";
  string = "123.243";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3);
  res2 = sscanf(string, format, &b1, &b2, &b3);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, b1 = 0, b2 = 0, b3 = 0;
  format = "%10c%c%c";
  string = "     \n     1     2\t3";
  res2 = sscanf(string, format, &b1, &b2, &b3);
  res1 = s21_sscanf(string, format, &a1, &a2, &a3);

  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(res1, res2);

  // a1 = 0, a2 = 0, a3 = 0, b1 = 0, b2 = 0, b3 = 0;
  // format = "%*s %c %c ";
  // string = "     \n     1     2\t3";
  // res2 = sscanf(string, format, &b1, &b2, &b3);
  // res1 = s21_sscanf(string, format, &a1, &a2, &a3);
  // ck_assert_int_eq(a1, b1);
  // ck_assert_int_eq(a2, b2);
  // ck_assert_int_eq(a3, b3);
  // ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, b1 = 0, b2 = 0, b3 = 0;
  char a4 = 0, b4 = 0;
  format = "%c%c%c%c";
  string = "\\\n\t\t\t";
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);

  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  // a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  // format = "%c%*c%c%c";
  // string = "1234";
  // res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  // res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  // ck_assert_int_eq(a1, b1);
  // ck_assert_int_eq(a2, b2);
  // ck_assert_int_eq(a3, b3);
  // ck_assert_int_eq(res1, res2);

  // a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  // format = "%c%2c%c%c";
  // string = "1234";

  // res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  // res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  // ck_assert_int_eq(a1, b1);
  // ck_assert_int_eq(a2, b2);
  // ck_assert_int_eq(a3, b3);
  // ck_assert_int_eq(a4, b4);
  // ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%c%*c%c%*c";
  string = "1124\n580 234";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%c  %c   %c    %c";
  string = "1  2   3    4";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%c  %c   %c    %c";
  string = "1    2        3        4";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%c %c %c %c";
  string = "1234";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%c%*c%c%*c";
  string = "sdlgk;asjgl;skadjgla;sdgjasgdakl;sdga";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 49;
  format = "%2c";
  string = "112";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(s21_sscanf_hd_test) {
  char *format = "%hd";
  char *string = "0";
  short int a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  int res1 = s21_sscanf(string, format, &a1);
  int res2 = sscanf(string, format, &b1);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(res1, res2);

  a1 = 0, b1 = 0;
  format = "%hd";
  string = "-19214097";
  res1 = s21_sscanf(string, format, &a1);
  res2 = sscanf(string, format, &b1);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(res1, res2);

  a1 = 0, b1 = 0;
  format = "%hd";
  string = "123456789";
  res1 = s21_sscanf(string, format, &a1);
  res2 = sscanf(string, format, &b1);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(res1, res2);

  a1 = 0, b1 = 0;
  format = "%hd";
  string = "999";
  res1 = s21_sscanf(string, format, &a1);
  res2 = sscanf(string, format, &b1);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%hd%hd%hd%hd";
  string = "891 78 -1 +2";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "-";
  string = "891 78 -1 +2";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%hd%hd%hd%hd";
  string = "nothing";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%hd%hd%hd%hd";
  string = "";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%hd%hd%hd%hd";
  string = "8910237598 7198235 710987235 98275239857";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%hd%*hd%hd%hd%*hd%hd";
  string = "8910237598 7198235 710987235 98275239857";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%hd%hd%hd%hd";
  string = "1111 125 --1 +++2";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%hd%hd%hd%hd";
  string = "0 01 10 1";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  char a5 = 0, b5 = 0;
  format = "%hd%hd%c%hd%hd";
  string = "12345 12345 - -99099 +123 -3331020";
  res1 = s21_sscanf(string, format, &a1, &a2, &a5, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b5, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(a5, b5);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%hd%hd%hd%hd";
  string = "--------0 10 20 30";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%hd%hd%hd%hd";
  string = "a10";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(s21_sscanf_ld_test) {
  char *format = "%ld";
  char *string = "0";
  long int a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  int res1 = s21_sscanf(string, format, &a1);
  int res2 = sscanf(string, format, &b1);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(res1, res2);

  a1 = 0, b1 = 0;
  format = "%ld";
  string = "-19214097";
  res1 = s21_sscanf(string, format, &a1);
  res2 = sscanf(string, format, &b1);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(res1, res2);

  a1 = 0, b1 = 0;
  format = "%ld";
  string = "123456789";
  res1 = s21_sscanf(string, format, &a1);
  res2 = sscanf(string, format, &b1);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(res1, res2);

  a1 = 0, b1 = 0;
  format = "%ld";
  string = "999";
  res1 = s21_sscanf(string, format, &a1);
  res2 = sscanf(string, format, &b1);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%ld%ld%ld%ld";
  string = "891 78 -1 +2";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "-";
  string = "891 78 -1 +2";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%ld%ld%ld%ld";
  string = "nothing";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%ld%ld%ld%ld";
  string = "";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%ld%ld%ld%ld";
  string = "8910237598 7198235 710987235 98275239857";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%ld%*ld%ld%ld%*1ld%ld";
  string = "8910237598 7198235 710987235 98275239857";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%ld%ld%ld%ld";
  string = "1234";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%ld%ld%ld%ld";
  string = "1000000000000001";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%ld%*ld%ld%ld%*ld%ld";
  string = "999 1 888 777 1 666";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%*ld %ld %*ld %ld";
  string = "999 1 888 777";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%*ld%ld%*ld%ld";
  string = "999 1 888 777";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%ld%ld%ld%ld";
  string = "1111 125 --1 +++2";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%ld%ld%ld%ld";
  string = "0 01 10 1";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  char a5 = 0, b5 = 0;
  format = "%ld %ld %c %ld %ld";
  string = "12345 -12345 -99099 +123 -3331020";
  res1 = s21_sscanf(string, format, &a1, &a2, &a5, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b5, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(a5, b5);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%ld%ld%ld%ld";
  string = "--------0 10 20 30";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%ld%ld%ld%ld";
  string = "a10";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(s21_sscanf_hu_test) {
  char *format = "%hu";
  char *string = "0";
  unsigned short int a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0,
                     b4 = 0;
  int res1 = s21_sscanf(string, format, &a1);
  int res2 = sscanf(string, format, &b1);
  ck_assert_uint_eq(a1, b1);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, b1 = 0, b2 = 0;
  unsigned short c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  const char str[] = "-1337 +21 --5008 3000";
  const char fstr[] = "%hu %hu %hu %hu";

  int16_t res11 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res22 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res11, res22);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);

  a1 = 0, b1 = 0;
  format = "%hu";
  string = "-19214097";
  res1 = s21_sscanf(string, format, &a1);
  res2 = sscanf(string, format, &b1);
  ck_assert_uint_eq(a1, b1);
  ck_assert_int_eq(res1, res2);

  a1 = 0, b1 = 0;
  format = "%hu";
  string = "123456789";
  res1 = s21_sscanf(string, format, &a1);
  res2 = sscanf(string, format, &b1);
  ck_assert_uint_eq(a1, b1);
  ck_assert_int_eq(res1, res2);

  a1 = 0, b1 = 0;
  format = "%hu";
  string = "999";
  res1 = s21_sscanf(string, format, &a1);
  res2 = sscanf(string, format, &b1);
  ck_assert_uint_eq(a1, b1);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%hu%hu%hu%hu";
  string = "891 78 -1 +2";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_uint_eq(a1, b1);
  ck_assert_uint_eq(a2, b2);
  ck_assert_uint_eq(a3, b3);
  ck_assert_uint_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%1hu%10hu%5hu%3hu";
  string = "891 78 -1 +2";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_uint_eq(a1, b1);
  ck_assert_uint_eq(a2, b2);
  ck_assert_uint_eq(a3, b3);
  ck_assert_uint_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%1hu%10hu%5hu%3hu";
  string = "-891 78 -1 +2";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_uint_eq(a1, b1);
  ck_assert_uint_eq(a2, b2);
  ck_assert_uint_eq(a3, b3);
  ck_assert_uint_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%hu%1hu%hu%hu";
  string = "999 +-888 777 666";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_uint_eq(a1, b1);
  ck_assert_uint_eq(a2, b2);
  ck_assert_uint_eq(a3, b3);
  ck_assert_uint_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "-";
  string = "891 78 -1 +2";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_uint_eq(a1, b1);
  ck_assert_uint_eq(a2, b2);
  ck_assert_uint_eq(a3, b3);
  ck_assert_uint_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%hu%hu%hu%hu";
  string = "nothing";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_uint_eq(a1, b1);
  ck_assert_uint_eq(a2, b2);
  ck_assert_uint_eq(a3, b3);
  ck_assert_uint_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%hu%hu%hu%hu";
  string = "";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_uint_eq(a1, b1);
  ck_assert_uint_eq(a2, b2);
  ck_assert_uint_eq(a3, b3);
  ck_assert_uint_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%hu%hu%hu%hu";
  string = "8910237598 7198235 710987235 98275239857";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_uint_eq(a1, b1);
  ck_assert_uint_eq(a2, b2);
  ck_assert_uint_eq(a3, b3);
  ck_assert_uint_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%3hu%*hu%hu%1hu";
  string = "8910237598 7198235 710987235 98275239857";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_uint_eq(a1, b1);
  ck_assert_uint_eq(a2, b2);
  ck_assert_uint_eq(a3, b3);
  ck_assert_uint_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%hu%hu%hu%hu";
  string = "1234";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_uint_eq(a1, b1);
  ck_assert_uint_eq(a2, b2);
  ck_assert_uint_eq(a3, b3);
  ck_assert_uint_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%1hu%5hu%9hu%1hu";
  string = "1000000000000001";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_uint_eq(a1, b1);
  ck_assert_uint_eq(a2, b2);
  ck_assert_uint_eq(a3, b3);
  ck_assert_uint_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%hu%*hu%hu%hu";
  string = "999 1 888 777";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_uint_eq(a1, b1);
  ck_assert_uint_eq(a2, b2);
  ck_assert_uint_eq(a3, b3);
  ck_assert_uint_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%*hu %hu %*hu %hu";
  string = "999 1 888 777";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_uint_eq(a1, b1);
  ck_assert_uint_eq(a2, b2);
  ck_assert_uint_eq(a3, b3);
  ck_assert_uint_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%16hu%1hu%*hu%1hu%1hu";
  string = "999 1 888 777 1";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_uint_eq(a1, b1);
  ck_assert_uint_eq(a2, b2);
  ck_assert_uint_eq(a3, b3);
  ck_assert_uint_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%15hu%hu%hu%3hu";
  string = "1111";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_uint_eq(a1, b1);
  ck_assert_uint_eq(a2, b2);
  ck_assert_uint_eq(a3, b3);
  ck_assert_uint_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%15hu%hu%hu%3hu";
  string = "1111 999 888 777";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_uint_eq(a1, b1);
  ck_assert_uint_eq(a2, b2);
  ck_assert_uint_eq(a3, b3);
  ck_assert_uint_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%hu%hu%hu%hu";
  string = "1111 125 --1 +++2";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_uint_eq(a1, b1);
  ck_assert_uint_eq(a2, b2);
  ck_assert_uint_eq(a3, b3);
  ck_assert_uint_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%3hu%3hu%3hu%3hu";
  string = "++1 --1 ++1 --1";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_uint_eq(a1, b1);
  ck_assert_uint_eq(a2, b2);
  ck_assert_uint_eq(a3, b3);
  ck_assert_uint_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%15hu%1hu%1hu%3hu";
  string = "+1537 -1 +25 449";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_uint_eq(a1, b1);
  ck_assert_uint_eq(a2, b2);
  ck_assert_uint_eq(a3, b3);
  ck_assert_uint_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%2hu%1hu%1hu%1hu";
  string = "+0 -0 -0 -0";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_uint_eq(a1, b1);
  ck_assert_uint_eq(a2, b2);
  ck_assert_uint_eq(a3, b3);
  ck_assert_uint_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%hu%hu%hu%hu";
  string = "0 01 10 1";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_uint_eq(a1, b1);
  ck_assert_uint_eq(a2, b2);
  ck_assert_uint_eq(a3, b3);
  ck_assert_uint_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%3hu%3hu%3hu%3hu";
  string = "+10-10+10-10";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_uint_eq(a1, b1);
  ck_assert_uint_eq(a2, b2);
  ck_assert_uint_eq(a3, b3);
  ck_assert_uint_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  char a5 = 0, b5 = 0;
  format = "%hu%hu%c%hu%hu";
  string = "12345 -12345 -99099 +123 -3331020";
  res1 = s21_sscanf(string, format, &a1, &a2, &a5, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b5, &b3, &b4);
  ck_assert_uint_eq(a1, b1);
  ck_assert_uint_eq(a2, b2);
  ck_assert_uint_eq(a3, b3);
  ck_assert_uint_eq(a4, b4);
  ck_assert_uint_eq(a5, b5);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%hu%hu%hu%hu";
  string = "--------0 10 20 30";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_uint_eq(a1, b1);
  ck_assert_uint_eq(a2, b2);
  ck_assert_uint_eq(a3, b3);
  ck_assert_uint_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%hu%hu%hu%hu";
  string = "a10";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_uint_eq(a1, b1);
  ck_assert_uint_eq(a2, b2);
  ck_assert_uint_eq(a3, b3);
  ck_assert_uint_eq(a4, b4);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(s21_sscanf_lu_test) {
  char *format = "%lu";
  char *string = "0";
  unsigned long int a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0,
                    b4 = 0;
  int res1 = s21_sscanf(string, format, &a1);
  int res2 = sscanf(string, format, &b1);
  ck_assert_uint_eq(a1, b1);
  ck_assert_int_eq(res1, res2);

  a1 = 0, b1 = 0;
  format = "%lu";
  string = "-19214097";
  res1 = s21_sscanf(string, format, &a1);
  res2 = sscanf(string, format, &b1);
  ck_assert_uint_eq(a1, b1);
  ck_assert_int_eq(res1, res2);

  a1 = 0, b1 = 0;
  format = "%lu";
  string = "123456789";
  res1 = s21_sscanf(string, format, &a1);
  res2 = sscanf(string, format, &b1);
  ck_assert_uint_eq(a1, b1);
  ck_assert_int_eq(res1, res2);

  a1 = 0, b1 = 0;
  format = "%lu";
  string = "999";
  res1 = s21_sscanf(string, format, &a1);
  res2 = sscanf(string, format, &b1);
  ck_assert_uint_eq(a1, b1);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%lu%lu%lu%lu";
  string = "891 78 -1 +2";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_uint_eq(a1, b1);
  ck_assert_uint_eq(a2, b2);
  ck_assert_uint_eq(a3, b3);
  ck_assert_uint_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%1hu%10hu%5hu%3hu";
  string = "891 78 -1 +2";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_uint_eq(a1, b1);
  ck_assert_uint_eq(a2, b2);
  ck_assert_uint_eq(a3, b3);
  ck_assert_uint_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%1hu%10hu%5hu%3hu";
  string = "-891 78 -1 +2";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_uint_eq(a1, b1);
  ck_assert_uint_eq(a2, b2);
  ck_assert_uint_eq(a3, b3);
  ck_assert_uint_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%lu%1hu%lu%lu";
  string = "999 +-888 777 666";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_uint_eq(a1, b1);
  ck_assert_uint_eq(a2, b2);
  ck_assert_uint_eq(a3, b3);
  ck_assert_uint_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "-";
  string = "891 78 -1 +2";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_uint_eq(a1, b1);
  ck_assert_uint_eq(a2, b2);
  ck_assert_uint_eq(a3, b3);
  ck_assert_uint_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%lu%lu%lu%lu";
  string = "nothing";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_uint_eq(a1, b1);
  ck_assert_uint_eq(a2, b2);
  ck_assert_uint_eq(a3, b3);
  ck_assert_uint_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%lu%lu%lu%lu";
  string = "";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_uint_eq(a1, b1);
  ck_assert_uint_eq(a2, b2);
  ck_assert_uint_eq(a3, b3);
  ck_assert_uint_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%lu%lu%lu%lu";
  string = "8910237598 7198235 710987235 98275239857";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_uint_eq(a1, b1);
  ck_assert_uint_eq(a2, b2);
  ck_assert_uint_eq(a3, b3);
  ck_assert_uint_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%3lu%*lu%lu%lu";
  string = "8910237598 7198235 710987235 98275239857";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_uint_eq(a1, b1);
  ck_assert_uint_eq(a2, b2);
  ck_assert_uint_eq(a3, b3);
  ck_assert_uint_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%1hu%1hu%1hu%1hu";
  string = "1234";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_uint_eq(a1, b1);
  ck_assert_uint_eq(a2, b2);
  ck_assert_uint_eq(a3, b3);
  ck_assert_uint_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%1hu%5hu%9hu%1hu";
  string = "1000000000000001";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_uint_eq(a1, b1);
  ck_assert_uint_eq(a2, b2);
  ck_assert_uint_eq(a3, b3);
  ck_assert_uint_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%1hu%*lu%1hu%1hu";
  string = "999 1 888 777";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_uint_eq(a1, b1);
  ck_assert_uint_eq(a2, b2);
  ck_assert_uint_eq(a3, b3);
  ck_assert_uint_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%1hu%lu%*lu%1hu";
  string = "999 1 888 777";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_uint_eq(a1, b1);
  ck_assert_uint_eq(a2, b2);
  ck_assert_uint_eq(a3, b3);
  ck_assert_uint_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%16hu%1hu%*lu%1hu";
  string = "999 1 888 777";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_uint_eq(a1, b1);
  ck_assert_uint_eq(a2, b2);
  ck_assert_uint_eq(a3, b3);
  ck_assert_uint_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%15hu%lu%lu%3hu";
  string = "1111";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_uint_eq(a1, b1);
  ck_assert_uint_eq(a2, b2);
  ck_assert_uint_eq(a3, b3);
  ck_assert_uint_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%15hu%lu%lu%3hu";
  string = "1111 999 888 777";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_uint_eq(a1, b1);
  ck_assert_uint_eq(a2, b2);
  ck_assert_uint_eq(a3, b3);
  ck_assert_uint_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%lu%lu%lu%lu";
  string = "1111 125 --1 +++2";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_uint_eq(a1, b1);
  ck_assert_uint_eq(a2, b2);
  ck_assert_uint_eq(a3, b3);
  ck_assert_uint_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%3hu%3hu%3hu%3hu";
  string = "++1 --1 ++1 --1";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_uint_eq(a1, b1);
  ck_assert_uint_eq(a2, b2);
  ck_assert_uint_eq(a3, b3);
  ck_assert_uint_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%15hu%1hu%1hu%3hu";
  string = "+1537 -1 +25 449";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_uint_eq(a1, b1);
  ck_assert_uint_eq(a2, b2);
  ck_assert_uint_eq(a3, b3);
  ck_assert_uint_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%2hu%1hu%1hu%1hu";
  string = "+0 -0 -0 -0";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_uint_eq(a1, b1);
  ck_assert_uint_eq(a2, b2);
  ck_assert_uint_eq(a3, b3);
  ck_assert_uint_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%lu%lu%lu%lu";
  string = "0 01 10 1";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_uint_eq(a1, b1);
  ck_assert_uint_eq(a2, b2);
  ck_assert_uint_eq(a3, b3);
  ck_assert_uint_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%3hu%3hu%3hu%3hu";
  string = "+10-10+10-10";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_uint_eq(a1, b1);
  ck_assert_uint_eq(a2, b2);
  ck_assert_uint_eq(a3, b3);
  ck_assert_uint_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  char a5 = 0, b5 = 0;
  format = "%lu%lu%c%lu%lu";
  string = "12345 -12345 -99099 +123 -3331020";
  res1 = s21_sscanf(string, format, &a1, &a2, &a5, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b5, &b3, &b4);
  ck_assert_uint_eq(a1, b1);
  ck_assert_uint_eq(a2, b2);
  ck_assert_uint_eq(a3, b3);
  ck_assert_uint_eq(a4, b4);
  ck_assert_uint_eq(a5, b5);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%lu%lu%lu%lu";
  string = "--------0 10 20 30";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_uint_eq(a1, b1);
  ck_assert_uint_eq(a2, b2);
  ck_assert_uint_eq(a3, b3);
  ck_assert_uint_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%lu";
  string = "a10";
  res1 = s21_sscanf(string, format, &a1);
  res2 = sscanf(string, format, &b1);
  ck_assert_uint_eq(a1, b1);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(s21_sscanf_u_test) {
  char *format = "%u";
  char *string = "0";
  unsigned int a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  int res1 = s21_sscanf(string, format, &a1);
  int res2 = sscanf(string, format, &b1);
  ck_assert_uint_eq(a1, b1);
  ck_assert_int_eq(res1, res2);

  a1 = 0, b1 = 0;
  format = "%u";
  string = "-19214097";
  res1 = s21_sscanf(string, format, &a1);
  res2 = sscanf(string, format, &b1);
  ck_assert_uint_eq(a1, b1);
  ck_assert_int_eq(res1, res2);

  a1 = 0, b1 = 0;
  format = "%u";
  string = "123456789";
  res1 = s21_sscanf(string, format, &a1);
  res2 = sscanf(string, format, &b1);
  ck_assert_uint_eq(a1, b1);
  ck_assert_int_eq(res1, res2);

  a1 = 0, b1 = 0;
  format = "%u";
  string = "999";
  res1 = s21_sscanf(string, format, &a1);
  res2 = sscanf(string, format, &b1);
  ck_assert_uint_eq(a1, b1);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%u%u%u%u";
  string = "891 78 -1 +2";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_uint_eq(a1, b1);
  ck_assert_uint_eq(a2, b2);
  ck_assert_uint_eq(a3, b3);
  ck_assert_uint_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%1hu%10hu%5hu%3hu";
  string = "891 78 -1 +2";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_uint_eq(a1, b1);
  ck_assert_uint_eq(a2, b2);
  ck_assert_uint_eq(a3, b3);
  ck_assert_uint_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%3hu%*u%u%u";
  string = "8910237598 7198235 710987235 98275239857";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_uint_eq(a1, b1);
  ck_assert_uint_eq(a2, b2);
  ck_assert_uint_eq(a3, b3);
  ck_assert_uint_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%1hu%1hu%1hu%1hu";
  string = "1234";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_uint_eq(a1, b1);
  ck_assert_uint_eq(a2, b2);
  ck_assert_uint_eq(a3, b3);
  ck_assert_uint_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%1hu%5hu%9hu%1hu";
  string = "1000000000000001";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_uint_eq(a1, b1);
  ck_assert_uint_eq(a2, b2);
  ck_assert_uint_eq(a3, b3);
  ck_assert_uint_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%1hu%*u%1hu%1hu";
  string = "999 1 888 777";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_uint_eq(a1, b1);
  ck_assert_uint_eq(a2, b2);
  ck_assert_uint_eq(a3, b3);
  ck_assert_uint_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%1hu%u%*u%1hu";
  string = "999 1 888 777";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_uint_eq(a1, b1);
  ck_assert_uint_eq(a2, b2);
  ck_assert_uint_eq(a3, b3);
  ck_assert_uint_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%16hu%1hu%*u%1hu";
  string = "999 1 888 777";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_uint_eq(a1, b1);
  ck_assert_uint_eq(a2, b2);
  ck_assert_uint_eq(a3, b3);
  ck_assert_uint_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%15hu%u%u%3hu";
  string = "1111";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_uint_eq(a1, b1);
  ck_assert_uint_eq(a2, b2);
  ck_assert_uint_eq(a3, b3);
  ck_assert_uint_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%15hu%u%u%3hu";
  string = "1111 999 888 777";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_uint_eq(a1, b1);
  ck_assert_uint_eq(a2, b2);
  ck_assert_uint_eq(a3, b3);
  ck_assert_uint_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%u%u%u%u";
  string = "1111 125 --1 +++2";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_uint_eq(a1, b1);
  ck_assert_uint_eq(a2, b2);
  ck_assert_uint_eq(a3, b3);
  ck_assert_uint_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%3hu%3hu%3hu%3hu";
  string = "++1 --1 ++1 --1";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_uint_eq(a1, b1);
  ck_assert_uint_eq(a2, b2);
  ck_assert_uint_eq(a3, b3);
  ck_assert_uint_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%15hu%1hu%1hu%3hu";
  string = "+1537 -1 +25 449";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_uint_eq(a1, b1);
  ck_assert_uint_eq(a2, b2);
  ck_assert_uint_eq(a3, b3);
  ck_assert_uint_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%2hu%1hu%1hu%1hu";
  string = "+0 -0 -0 -0";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_uint_eq(a1, b1);
  ck_assert_uint_eq(a2, b2);
  ck_assert_uint_eq(a3, b3);
  ck_assert_uint_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%u%u%u%u";
  string = "0 01 10 1";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_uint_eq(a1, b1);
  ck_assert_uint_eq(a2, b2);
  ck_assert_uint_eq(a3, b3);
  ck_assert_uint_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%3hu%3hu%3hu%3hu";
  string = "+10-10+10-10";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_uint_eq(a1, b1);
  ck_assert_uint_eq(a2, b2);
  ck_assert_uint_eq(a3, b3);
  ck_assert_uint_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  char a5 = 0, b5 = 0;
  format = "%u%u%c%u%u";
  string = "12345 -12345 -99099 +123 -3331020";
  res1 = s21_sscanf(string, format, &a1, &a2, &a5, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b5, &b3, &b4);
  ck_assert_uint_eq(a1, b1);
  ck_assert_uint_eq(a2, b2);
  ck_assert_uint_eq(a3, b3);
  ck_assert_uint_eq(a4, b4);
  ck_assert_uint_eq(a5, b5);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%u%u%u%u";
  string = "--------0 10 20 30";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_uint_eq(a1, b1);
  ck_assert_uint_eq(a2, b2);
  ck_assert_uint_eq(a3, b3);
  ck_assert_uint_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%u%u%u%u";
  string = "a10";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_uint_eq(a1, b1);
  ck_assert_uint_eq(a2, b2);
  ck_assert_uint_eq(a3, b3);
  ck_assert_uint_eq(a4, b4);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(s21_sscanf_different_shit_test) {
  // long long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  // const char str[] = "100500 -600 +700 123";
  // const char fstr[] = "%lli %lld %lld %lli";

  // int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  // int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  // ck_assert_int_eq(res1, res2);
  // ck_assert_int_eq(a1, a2);
  // ck_assert_int_eq(b1, b2);
  // ck_assert_int_eq(c1, c2);
  // ck_assert_int_eq(d1, d2);

  long long a1 = 0, a2 = 0, c1 = 0, c2 = 0;
  char b1 = 0, b2 = 0, d1 = 0, d2 = 0;
  const char str[] = "100500 -600 +700 +400";
  const char fstr[] = "%lli %c %lli %c";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(s21_sscanf_d_test) {
  char *format = "%d";
  char *string = "0";
  int a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  int res1 = s21_sscanf(string, format, &a1);
  int res2 = sscanf(string, format, &b1);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(res1, res2);

  a1 = 0, b1 = 0;
  format = "%d";
  string = "-19214097";
  res1 = s21_sscanf(string, format, &a1);
  res2 = sscanf(string, format, &b1);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(res1, res2);

  a1 = 0, b1 = 0;
  format = "%d";
  string = "123456789";
  res1 = s21_sscanf(string, format, &a1);
  res2 = sscanf(string, format, &b1);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(res1, res2);

  a1 = 0, b1 = 0;
  format = "%d";
  string = "999";
  res1 = s21_sscanf(string, format, &a1);
  res2 = sscanf(string, format, &b1);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%d%d%d%d";
  string = "891 78 -1 +2";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%1d%10d%5d%3d";
  string = "891 78 -1 +2";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%1d%10d%5d%3d";
  string = "-891 78 -1 +2";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%d%1d%d%d";
  string = "999 +-888 777 666";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "-";
  string = "891 78 -1 +2";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%d%d%d%d";
  string = "nothing";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%d%d%d%d";
  string = "";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%d%d%d%d";
  string = "8910237598 7198235 710987235 98275239857";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%3d%*d%d%d";
  string = "8910237598 7198235 710987235 98275239857";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%1d%1d%1d%1d";
  string = "1234";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%1d%5d%9d%1d";
  string = "1000000000000001";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%1d%*d%1d%1d";
  string = "999 1 888 777 1 666";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%*d%d%*d%1d";
  string = "999 1 888 777";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%16d%1d%*d%1d";
  string = "999 1 888 777 1 666";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%15d %d %d %3d";
  string = "1 1 1 1";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%15d%d%d%3d";
  string = "1111 999 888 777 389 89102 98124";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%d%d%d%d";
  string = "1111 125 --1 +++2";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%3d%3d%3d%3d";
  string = "++1 --1 ++1 --1";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%15d%1d%1d%3d";
  string = "+1537 -1 +25 449";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%2d%1d%1d%1d";
  string = "+0 -0 -0 -0";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%d%d%d%d";
  string = "0 01 10 1";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%3d%3d%3d%3d";
  string = "+10-10+10-10";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%d%d%d%d";
  string = "12345 -12345 -99099 +123";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%d%d%d%d";
  string = "--------0 10 20 30";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%d%d%d%d";
  string = "a10";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a4 = 0, b1 = 0, b4 = 0;
  char a22 = 0, b22 = 0, a33 = 0, b33 = 0;
  format = "%d  %c  %c %d";
  string = "44444  5  56 5665";
  res1 = s21_sscanf(string, format, &a1, &a22, &a33, &a4);
  res2 = sscanf(string, format, &b1, &b22, &b33, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a22, b22);
  ck_assert_int_eq(a33, b33);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_EOF1) {
  char fstr[] = "%d";
  char str[] = "        ";

  int16_t res1 = s21_sscanf(str, fstr, 0);
  int16_t res2 = sscanf(str, fstr, 100);
  ck_assert_int_eq(res1, res2);
}
END_TEST

// START_TEST(sscanf_EOF2) {
//   char fstr[] = "%d ";
//   char str[] = "               ";
//   int16_t a1 = 0, a2 = 0;

//   int16_t res1 = s21_sscanf(str, fstr, &a1);
//   int16_t res2 = sscanf(str, fstr, &a2);
//   ck_assert_int_eq(res1, res2);
// }
// END_TEST

START_TEST(sscanf_EOF3) {
  char fstr[] = "%d ";
  char str[] = "  ";
  int16_t a1 = 0, a2 = 0;

  int16_t res1 = s21_sscanf(str, fstr, &a1);
  int16_t res2 = sscanf(str, fstr, &a2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_only_chars1) {
  char fstr[] = "%c %c %c %c";
  char str[] = "   a     b c d";
  int16_t a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  ;

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);

  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_only_chars2) {
  char fstr[] = "%c%c%c%c";
  char str[] = "abcd";
  int16_t a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  ;

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);

  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_only_chars3) {
  char fstr[] = "%c %c %c      %c";
  char str[] = "1 a 3   c           ";
  int16_t a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  ;

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_only_chars4) {
  char fstr[] = "%c %c %c %c";
  char str[] = "   000 0    ";
  int16_t a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);

  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_only_chars5) {
  char fstr[] = "%c %c %c %c";
  char str[] = "tttt";
  int16_t a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);

  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_special_symbols_as_chars1) {
  char fstr[] = "%c%c%c%c";
  char str[] = "\\\n\t\t\t";
  int16_t a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_special_symbols_as_chars2) {
  char fstr[] = "%c %c %c %c";
  char str[] = "z ' ' /";
  int16_t a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_special_symbols_as_chars3) {
  char fstr[] = "%c%*c%c%c";
  char str[] = "ABCD";
  int16_t a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0;

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1);

  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
}
END_TEST

START_TEST(sscanf_chars_flags1) {
  char fstr[] = "%c %c %c %c";
  char str[] = "z *'@";
  int16_t a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_chars_flags2) {
  char fstr[] = "%1c %c %c %0c";
  char str[] = "z *'@";
  int16_t a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_chars_flags3) {
  char fstr[] = "%c %c %c %c";
  char str[] = "z *'@";
  int16_t a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_chars_flags4) {
  char fstr[] = "%c %c %c %c";
  char str[] = "z *'@";
  int16_t a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_chars_flags5) {
  char fstr[] = "%*c%*c%*c%c";
  char str[] = "abcde";
  int16_t a1 = 0, a2 = 0;

  int16_t res1 = s21_sscanf(str, fstr, &a1);
  int16_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(sscanf_chars_aster1) {
  char fstr[] = "%*c%*c%*c%*c";
  char str[] = "   c ";
  int16_t a1 = 0, a2 = 0;

  int16_t res1 = s21_sscanf(str, fstr, &a1);
  int16_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(sscanf_chars_aster2) {
  char fstr[] = "%*c%*c%*c%c";
  char str[] = "abcd ";
  int16_t a1 = 0, a2 = 0;

  int16_t res1 = s21_sscanf(str, fstr, &a1);
  int16_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(sscanf_only_ints1) {
  long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  const char fstr[] = "%ld %ld %ld %ld";
  const char str[] = "555 666 777 888";

  int32_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int32_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_only_ints2) {
  int16_t a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  const char str[] = "1337 21 5008 3000";
  const char fstr[] = "%hd %hd %hd %hd";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_only_ints3) {
  long long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  const char str[] = "1337 21 5008 300004";
  const char fstr[] = "%lld %lld %lld %lld";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_ints_nwidth1) {
  long long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  const char str[] = "1337 21 5008 300004";
  const char fstr[] = "%1lld %3lld %1lld %4lld";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_ints_nwidth2) {
  long long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  const char str[] = "1337";
  const char fstr[] = "%1lld %1lld %1lld %1lld";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_ints_nwidth3) {
  long long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  const char str[] = "100000000000000005";
  const char fstr[] = "%3lld%lld%1lld%5lld";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_ints_nwidth4) {
  long long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  const char str[] = "1337";
  const char fstr[] = "%15lld %1lld %1lld %1lld";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_ints_astwidth1) {
  long long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0;
  const char str[] = "1337123123 1 123412341234 1 999999 0";
  const char fstr[] = "%*d %lld %*d %lld %*d %lld";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
}
END_TEST

START_TEST(sscanf_ints_astwidth2) {
  long long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  const char str[] = "1337";
  const char fstr[] = "%15lld %1lld %1lld %1lld";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_signed_ints1) {
  long long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  const char str[] = "11337 ++3 -5 ------4";
  const char fstr[] = "%lld %lld %lld %lld";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_signed_ints2) {
  long long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  const char str[] = "-1337 +1 -1 -1";
  const char fstr[] = "%15lld %1lld %1lld %5lld";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_signed_ints3) {
  long long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  const char str[] = "-0 +0 +0 -0";
  const char fstr[] = "%2lld %1lld %1lld %1lld";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_signed_ints4) {
  long long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  const char str[] = "1 01 10 0";
  const char fstr[] = "%lld %lld %lld %lld";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_i_int1) {
  long long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  const char str[] = "300 500 -600 +700";
  const char fstr[] = "%lli %lli %lli %lli";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_i_int2) {
  long long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  const char str[] = "300500-600+700 111";
  const char fstr[] = "%lli %lld %lld %lli";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_i_int3) {
  long long a1 = 0, a2 = 0, c1 = 0, c2 = 0;
  char b1 = 0, b2 = 0, d1 = 0, d2 = 0;
  const char str[] = "300500-600+700+400";
  const char fstr[] = "%lli%c%lli%c";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_i_int4) {
  long long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  const char str[] = "  55555 f f f5555555 ddd   4    3    1 ";
  const char fstr[] = "%lli %lld %lld %lli";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_i_oct1) {
  long long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  const char str[] = "  055555 0f 0f 0f5555555 0ddd   4    3    1 ";
  const char fstr[] = "%lli %lld %lld %lli";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_i_oct2) {
  long long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  const char str[] = "  055555 0f 0f 0f5555555 0ddd   4    3    1 ";
  const char fstr[] = "%lli %lld %lld %lli";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_i_hex1) {
  long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  const char str[] = "0xFFF 0xA123123 0x123123 0x0";
  const char fstr[] = "%li %ld %ld %li";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_i_hex2) {
  long long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  const char str[] = " 0xFFFF 0xf 0xf 0xf5555555 ddd   4    3    1 ";
  const char fstr[] = "%lli %lld %lld %lli";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_strings1) {
  char s1[BUFF_SIZE] = {'\0'};
  char s2[BUFF_SIZE] = {'\0'};
  char s3[BUFF_SIZE] = {'\0'};
  char s4[BUFF_SIZE] = {'\0'};

  char s5[BUFF_SIZE] = {'\0'};
  char s6[BUFF_SIZE] = {'\0'};
  char s7[BUFF_SIZE] = {'\0'};
  char s8[BUFF_SIZE] = {'\0'};

  const char str[] = "Aboba Floppa Keppa Shleppa Anuroba";
  const char fstr[] = "%s %s %s %s";

  int16_t res1 = s21_sscanf(str, fstr, s1, s2, s3, s4);
  int16_t res2 = sscanf(str, fstr, s5, s6, s7, s8);

  ck_assert_int_eq(res1, res2);

  ck_assert_str_eq(s1, s5);
  ck_assert_str_eq(s2, s6);
  ck_assert_str_eq(s3, s7);
  ck_assert_str_eq(s4, s8);
}
END_TEST

START_TEST(sscanf_strings_mixed3) {
  char s1[BUFF_SIZE] = {'\0'};
  char s2[BUFF_SIZE] = {'\0'};
  char s3[BUFF_SIZE] = {'\0'};
  char s4[BUFF_SIZE] = {'\0'};

  char s5[BUFF_SIZE] = {'\0'};
  char s6[BUFF_SIZE] = {'\0'};
  char s7[BUFF_SIZE] = {'\0'};
  char s8[BUFF_SIZE] = {'\0'};

  long long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;

  const char str[] = "Aboba 123 Floppa -3 Keppa 4444Shleppa 333Anuroba 3";
  const char fstr[] = "%s%ld%s%d%s%d%s";

  int16_t res1 = s21_sscanf(str, fstr, s1, &a1, s2, &b1, s3, &c1, s4, &d1);
  int16_t res2 = s21_sscanf(str, fstr, s5, &a2, s6, &b2, s7, &c2, s8, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);

  ck_assert_str_eq(s1, s5);
  ck_assert_str_eq(s2, s6);
  ck_assert_str_eq(s3, s7);
  ck_assert_str_eq(s4, s8);
}
END_TEST

START_TEST(sscanf_strings2) {
  char s1[BUFF_SIZE] = {'\0'};
  char s2[BUFF_SIZE] = {'\0'};
  char s3[BUFF_SIZE] = {'\0'};
  char s4[BUFF_SIZE] = {'\0'};

  char s5[BUFF_SIZE] = {'\0'};
  char s6[BUFF_SIZE] = {'\0'};
  char s7[BUFF_SIZE] = {'\0'};
  char s8[BUFF_SIZE] = {'\0'};

  const char str[] = "aboba\tshlepa\tasdfasdf\tasdfasdf";
  const char fstr[] = "%s%s%s%s";

  int16_t res1 = s21_sscanf(str, fstr, s1, s2, s3, s4);
  int16_t res2 = sscanf(str, fstr, s5, s6, s7, s8);

  ck_assert_int_eq(res1, res2);

  ck_assert_str_eq(s1, s5);
  ck_assert_str_eq(s2, s6);
  ck_assert_str_eq(s3, s7);
  ck_assert_str_eq(s4, s8);
}
END_TEST

START_TEST(sscanf_strings3) {
  char s1[BUFF_SIZE] = {'\0'};
  char s2[BUFF_SIZE] = {'\0'};
  char s3[BUFF_SIZE] = {'\0'};
  char s4[BUFF_SIZE] = {'\0'};

  char s5[BUFF_SIZE] = {'\0'};
  char s6[BUFF_SIZE] = {'\0'};
  char s7[BUFF_SIZE] = {'\0'};
  char s8[BUFF_SIZE] = {'\0'};

  const char str[] = "aboba\tkepaboba floppa shleppa koooppa ap p p p p";
  const char fstr[] = "%*s%*s%*s%*s";

  int16_t res1 = s21_sscanf(str, fstr);
  int16_t res2 = sscanf(str, fstr);

  ck_assert_int_eq(res1, res2);

  ck_assert_str_eq(s1, s5);
  ck_assert_str_eq(s2, s6);
  ck_assert_str_eq(s3, s7);
  ck_assert_str_eq(s4, s8);
}
END_TEST

START_TEST(sscanf_strings4) {
  char s1[BUFF_SIZE] = {'\0'};
  char s2[BUFF_SIZE] = {'\0'};
  char s3[BUFF_SIZE] = {'\0'};
  char s4[BUFF_SIZE] = {'\0'};

  char s5[BUFF_SIZE] = {'\0'};
  char s6[BUFF_SIZE] = {'\0'};
  char s7[BUFF_SIZE] = {'\0'};
  char s8[BUFF_SIZE] = {'\0'};

  const char str[] = "aboba\tshlepa\tasdfasdf\tasdfasdf";
  const char fstr[] = "%1s%1s%1s%1s";

  int16_t res1 = s21_sscanf(str, fstr, s1, s2, s3, s4);
  int16_t res2 = sscanf(str, fstr, s5, s6, s7, s8);

  ck_assert_int_eq(res1, res2);

  ck_assert_str_eq(s1, s5);
  ck_assert_str_eq(s2, s6);
  ck_assert_str_eq(s3, s7);
  ck_assert_str_eq(s4, s8);
}
END_TEST

START_TEST(sscanf_strings5) {
  char s1[BUFF_SIZE] = {'\0'};
  char s2[BUFF_SIZE] = {'\0'};
  char s3[BUFF_SIZE] = {'\0'};
  char s4[BUFF_SIZE] = {'\0'};

  char s5[BUFF_SIZE] = {'\0'};
  char s6[BUFF_SIZE] = {'\0'};
  char s7[BUFF_SIZE] = {'\0'};
  char s8[BUFF_SIZE] = {'\0'};

  const char str[] = "aboba\tshlepa\tasdfasdf\tasdfasdf";
  const char fstr[] = "%3s%3s%3s%3s";

  int16_t res1 = s21_sscanf(str, fstr, s1, s2, s3, s4);
  int16_t res2 = sscanf(str, fstr, s5, s6, s7, s8);

  ck_assert_int_eq(res1, res2);

  ck_assert_str_eq(s1, s5);
  ck_assert_str_eq(s2, s6);
  ck_assert_str_eq(s3, s7);
  ck_assert_str_eq(s4, s8);
}
END_TEST

START_TEST(sscanf_strings6) {
  char s1[BUFF_SIZE] = {'\0'};
  char s2[BUFF_SIZE] = {'\0'};
  char s3[BUFF_SIZE] = {'\0'};
  char s4[BUFF_SIZE] = {'\0'};

  char s5[BUFF_SIZE] = {'\0'};
  char s6[BUFF_SIZE] = {'\0'};
  char s7[BUFF_SIZE] = {'\0'};
  char s8[BUFF_SIZE] = {'\0'};

  const char str[] = "aboba\tshlepa\tasdfasdf\tasdfasdf";
  const char fstr[] = "%150s%1s%1s\t%3s";

  int16_t res1 = s21_sscanf(str, fstr, s1, s2, s3, s4);
  int16_t res2 = sscanf(str, fstr, s5, s6, s7, s8);

  ck_assert_int_eq(res1, res2);

  ck_assert_str_eq(s1, s5);
  ck_assert_str_eq(s2, s6);
  ck_assert_str_eq(s3, s7);
  ck_assert_str_eq(s4, s8);
}
END_TEST

START_TEST(sscanf_strings_mixed1) {
  unsigned long long int a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0;
  long long d1 = 0, d2 = 0;
  long double e1 = 0, e2 = 0;

  const char str[] =
      "4444444"
      "eeeeeee\teeeeeee";
  const char fstr[] = "%5s %1s %*s %*s %llu %s %llu %llu %lld %Lf %33s";

  char s1[BUFF_SIZE] = {'\0'};
  char s2[BUFF_SIZE] = {'\0'};
  char s3[BUFF_SIZE] = {'\0'};
  char s4[BUFF_SIZE] = {'\0'};
  char s5[BUFF_SIZE] = {'\0'};
  char s6[BUFF_SIZE] = {'\0'};
  char s7[BUFF_SIZE] = {'\0'};
  char s8[BUFF_SIZE] = {'\0'};
  char s9[BUFF_SIZE] = {'\0'};
  char s10[BUFF_SIZE] = {'\0'};

  int16_t res1 = s21_sscanf(str, fstr, s7, s9, &a1, s5, &b1, &c1, &d1, &e1, s1);
  int16_t res2 = sscanf(str, fstr, s8, s10, &a2, s6, &b2, &c2, &d2, &e2, s2);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(s1, s2);
  ck_assert_str_eq(s3, s4);
  ck_assert_str_eq(s5, s6);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_strings_mixed2) {
  int d1 = 0, d2 = 0, b1 = 0, b2 = 0, a1 = 0, a2 = 0;
  long long v1, v2;

  const char str[] = "1 1 1 1 1 -1";
  const char fstr[] = "%1s %5d %1s %1s %d %lld %d";

  char s1[BUFF_SIZE] = {'\0'};
  char s2[BUFF_SIZE] = {'\0'};
  char s3[BUFF_SIZE] = {'\0'};
  char s4[BUFF_SIZE] = {'\0'};
  char s5[BUFF_SIZE] = {'\0'};
  char s6[BUFF_SIZE] = {'\0'};

  int16_t res1 = s21_sscanf(str, fstr, s1, &a1, s2, s3, &b1, &v1, &d1);
  int16_t res2 = sscanf(str, fstr, s4, &a2, s5, s6, &b2, &v2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(s1, s2);
  ck_assert_str_eq(s3, s4);
  ck_assert_str_eq(s5, s6);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_n1) {
  long long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  int32_t n1 = 0, n2 = 0;

  const char str[BUFF_SIZE] = "50 160 70 80";
  const char fstr[BUFF_SIZE] = "%lli %lli %n %lli %lli";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &n1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &n2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(n1, n2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_n2) {
  int n1 = 0, n2 = 0;

  char s1[BUFF_SIZE] = {'\0'};
  char s2[BUFF_SIZE] = {'\0'};
  char s3[BUFF_SIZE] = {'\0'};
  char s5[BUFF_SIZE] = {'\0'};
  char s6[BUFF_SIZE] = {'\0'};
  char s7[BUFF_SIZE] = {'\0'};

  const char str[] = "cbobErobM fl? asdfasdflkasdf asdfasdf asdfasdf 88888";
  const char fstr[] = "%s %s %n %s";

  int32_t res1 = s21_sscanf(str, fstr, s1, s2, &n1, s3);
  int32_t res2 = sscanf(str, fstr, s5, s6, &n2, s7);

  ck_assert_int_eq(res1, res2);

  ck_assert_int_eq(n1, n2);
  ck_assert_str_eq(s1, s5);
  ck_assert_str_eq(s2, s6);
  ck_assert_str_eq(s3, s7);
}
END_TEST

START_TEST(sscanf_n3) {
  int n1 = 0, n2 = 0;

  const char str[BUFF_SIZE] = "50 60 70 80";
  const char fstr[BUFF_SIZE] = "%n";

  int16_t res1 = s21_sscanf(str, fstr, &n1);
  int16_t res2 = sscanf(str, fstr, &n2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(sscanf_floats1) {
  long double a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;

  const char str[] = "53.1 -4.1135 41.3333 +2.0001";
  const char fstr[] = "%Lf %Lf %Lf %Lf";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_double_eq(a1, a2);
  ck_assert_double_eq(b1, b2);
  ck_assert_double_eq(c1, c2);
  ck_assert_double_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_floats2) {
  double a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;

  const char str[] = "0.00001 -4123123 4. ";
  const char fstr[] = "%lf %lf %lf %lf";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_double_eq(a1, a2);
  ck_assert_double_eq(b1, b2);
  ck_assert_double_eq(c1, c2);
  ck_assert_double_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_floats3) {
  float a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;

  const char str[] = ". . . .";
  const char fstr[] = "%f %f %f %f";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_double_eq(a1, a2);
  ck_assert_double_eq(b1, b2);
  ck_assert_double_eq(c1, c2);
  ck_assert_double_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_floats4) {
  long double a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;

  const char str[] = "513.41 -4.14135 414.3333 +112.0001";
  const char fstr[] = "%Lf %Lf %Lf %Lf";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_double_eq(a1, a2);
  ck_assert_double_eq(b1, b2);
  ck_assert_double_eq(c1, c2);
  ck_assert_double_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_floats_sci1) {
  float a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;

  const char str[] = "1.4441 1.e+4 -3.31e-4 0.444e-5";
  const char fstr[] = "%G %G %G %G";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_double_eq(a1, a2);
  ck_assert_double_eq(b1, b2);
  ck_assert_double_eq(c1, c2);
  ck_assert_double_eq(d1, d2);
}
END_TEST

// START_TEST(sscanf_floats_sci2) {
//   float a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;

//   const char str[] = "inf 1.e+4 NaN 0.444e-5";
//   const char fstr[] = "%G %G %G %G";

//   int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
//   int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

//   ck_assert_int_eq(res1, res2);
//   ck_assert_ldouble_eq(a1, a2);
//   // Unfortunately, assertions for inf do not work correctly in libcheck
//   // ck_assert_ldouble_infinite(a1);
//   // ck_assert_ldouble_infinite(a2);
//   ck_assert_double_eq(b1, b2);
//   ck_assert_float_nan(c1);
//   ck_assert_float_nan(c2);
//   ck_assert_double_eq(d1, d2);
// }
// END_TEST

START_TEST(sscanf_upeer_hex_base_version) {
  uint32_t a1, a2;
  const char str[] = "F";
  const char fstr[] = "%X";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(sscanf_upeer_hex_overflow) {
  uint32_t a1, a2;
  const char str[] = "0xFFFFFFFF";
  const char fstr[] = "%X";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(sscanf_upeer_hex_0x) {
  uint32_t a1, a2;
  const char str[] = "0x";
  const char fstr[] = "%X";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(sscanf_upeer_hex_0X) {
  uint32_t a1, a2;
  const char str[] = "0X";
  const char fstr[] = "%X";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(sscanf_upeer_hex_empty) {
  uint32_t a1, a2;
  const char str[] = "";
  const char fstr[] = "%X";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_upeer_hex_fail) {
  uint32_t a1, a2;
  const char str[] = "qF";
  const char fstr[] = "%X";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_upeer_hex_spaces_tabs_sns) {
  uint32_t a1, a2;
  const char str[] = "          \n             \n     F";
  const char fstr[] = "%X";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(sscanf_upeer_hex_short) {
  uint16_t a1, a2;
  const char str[] = "F";
  const char fstr[] = "%hX";
  uint16_t res1 = s21_sscanf(str, fstr, &a1);
  uint16_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(sscanf_upeer_hex_long) {
  unsigned long int a1, a2;
  const char str[] = "F";
  const char fstr[] = "%lX";
  uint16_t res1 = s21_sscanf(str, fstr, &a1);
  uint16_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(sscanf_upeer_hex_longlong) {
  unsigned long long int a1, a2;
  const char str[] = "F";
  const char fstr[] = "%llX";
  uint16_t res1 = s21_sscanf(str, fstr, &a1);
  uint16_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(sscanf_upeer_hex_2x) {
  uint32_t a1, a2;
  const char str[] = "0xFF0x0xFFF 0xFFxFF";
  const char fstr[] = "%X";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(sscanf_upeer_hex_star) {
  const char str[] = "0xFF0x0xFFF 0xFFxFF";
  const char fstr[] = "%*X";
  uint32_t res1 = s21_sscanf(str, fstr);
  uint32_t res2 = sscanf(str, fstr);

  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_upeer_hex_nohex) {
  uint32_t a1, a2;
  const char str[] = "tqwqpl";
  const char fstr[] = "%X";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_upeer_hex_lower) {
  uint32_t a1, a2;
  const char str[] = "abcdef";
  const char fstr[] = "%X";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(sscanf_upeer_hex_sign) {
  uint32_t a1, a2;
  const char str[] = "-f";
  const char fstr[] = "%X";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(sscanf_lower_hex_base_version) {
  uint32_t a1, a2;
  const char str[] = "f";
  const char fstr[] = "%x";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(sscanf_lower_hex_overflow) {
  uint32_t a1, a2;
  const char str[] = "0xfffffffffffffffffff";
  const char fstr[] = "%x";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(sscanf_lower_hex_0x) {
  uint32_t a1, a2;
  const char str[] = "0x";
  const char fstr[] = "%x";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(sscanf_lower_hex_0X) {
  uint32_t a1, a2;
  const char str[] = "0X";
  const char fstr[] = "%x";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(sscanf_lower_hex_empty) {
  uint32_t a1, a2;
  const char str[] = "";
  const char fstr[] = "%x";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_lower_hex_fail) {
  uint32_t a1, a2;
  const char str[] = "qF";
  const char fstr[] = "%x";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_lower_hex_spaces_tabs_sns) {
  uint32_t a1, a2;
  const char str[] = "          \n             \n     F";
  const char fstr[] = "%x";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(sscanf_lower_hex_short) {
  uint16_t a1, a2;
  const char str[] = "ff";
  const char fstr[] = "%hx";
  uint16_t res1 = s21_sscanf(str, fstr, &a1);
  uint16_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(sscanf_lower_hex_long) {
  unsigned long int a1, a2;
  const char str[] = "ff";
  const char fstr[] = "%lx";
  uint16_t res1 = s21_sscanf(str, fstr, &a1);
  uint16_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(sscanf_lower_hex_longlong) {
  unsigned long long int a1, a2;
  const char str[] = "faaaaaaaaaf";
  const char fstr[] = "%llx";
  uint16_t res1 = s21_sscanf(str, fstr, &a1);
  uint16_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(a1, a2);
}
END_TEST

START_TEST(sscanf_lower_hex_2x) {
  uint32_t a1, a2;
  const char str[] = "0xFF0x0xFFF 0xFFxFF";
  const char fstr[] = "%x";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(sscanf_lower_hex_star) {
  const char str[] = "0xFF0x0xFFF 0xFFxFF";
  const char fstr[] = "%*x";
  uint32_t res1 = s21_sscanf(str, fstr);
  uint32_t res2 = sscanf(str, fstr);

  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_lower_hex_nohex) {
  uint32_t a1, a2;
  const char str[] = "tqwqpl";
  const char fstr[] = "%x";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_lower_hex_lower) {
  uint32_t a1, a2;
  const char str[] = "abcdef";
  const char fstr[] = "%x";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(sscanf_lower_hex_sign) {
  uint32_t a1, a2;
  const char str[] = "-f";
  const char fstr[] = "%x";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(sscanf_lower_hex_len) {
  uint32_t a1, a2;
  const char str[] = "123531FFF";
  const char fstr[] = "%2x";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(sscanf_octal_0X) {
  uint32_t a1, a2;
  const char str[] = "0X";
  const char fstr[] = "%o";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(sscanf_octal_0x) {
  uint32_t a1, a2;
  const char str[] = "0x";
  const char fstr[] = "%o";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(sscanf_octal_empty) {
  uint32_t a1, a2;
  const char str[] = "";
  const char fstr[] = "%o";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_octal_fail) {
  uint32_t a1, a2;
  const char str[] = "q1";
  const char fstr[] = "%o";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_octal_overflow) {
  uint32_t a1, a2;
  const char str[] = "0x7777777777777777777777";
  const char fstr[] = "%o";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(sscanf_octal_spaces_tabs_sns) {
  uint32_t a1, a2;
  const char str[] = "          \n             \n     5";
  const char fstr[] = "%o";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(sscanf_octal_short) {
  uint16_t a1, a2;
  const char str[] = "12";
  const char fstr[] = "%ho";
  uint16_t res1 = s21_sscanf(str, fstr, &a1);
  uint16_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(sscanf_octal_long) {
  unsigned long int a1, a2;
  const char str[] = "57234";
  const char fstr[] = "%lo";
  uint16_t res1 = s21_sscanf(str, fstr, &a1);
  uint16_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(sscanf_octal_longlong) {
  unsigned long long int a1, a2;
  const char str[] = "12356226137";
  const char fstr[] = "%llo";
  uint16_t res1 = s21_sscanf(str, fstr, &a1);
  uint16_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(sscanf_octal_2x) {
  uint32_t a1, a2;
  const char str[] = "0x12320x213x123213";
  const char fstr[] = "%o";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(sscanf_octal_star) {
  const char str[] = "521561612";
  const char fstr[] = "%*o";
  uint32_t res1 = s21_sscanf(str, fstr);
  uint32_t res2 = sscanf(str, fstr);

  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_octal_lower) {
  uint32_t a1, a2;
  const char str[] = "01234567";
  const char fstr[] = "%o";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(sscanf_octal_sign) {
  uint32_t a1, a2;
  const char str[] = "-66";
  const char fstr[] = "%o";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(sscanf_octal_len) {
  uint32_t a1, a2;
  const char str[] = "123531";
  const char fstr[] = "%2o";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(sscanf_octal_base_version) {
  uint32_t a1, a2;
  const char str[] = "777";
  const char fstr[] = "%o";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(sscanf_buff1) {
  int32_t a1, a2;
  int32_t b1, b2;
  const char str[] = "12 keppa 12";
  const char fstr[] = "%d keppa %d";
  int32_t res1 = s21_sscanf(str, fstr, &a1, &b1);
  int32_t res2 = sscanf(str, fstr, &a2, &b2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
}
END_TEST

START_TEST(sscanf_buff2) {
  int32_t a1, a2;
  int32_t b1, b2;
  const char str[] = "12keppa12";
  const char fstr[] = "%dkeppa%d";
  int32_t res1 = s21_sscanf(str, fstr, &a1, &b1);
  int32_t res2 = sscanf(str, fstr, &a2, &b2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
}
END_TEST

START_TEST(sscanf_pointer1) {
  int *a1 = 0, *a2 = 0, *b1 = 0, *b2 = 0, *c1 = 0, *c2 = 0, *d1 = 0, *d2 = 0;
  const char str[] = "0xFFFF 0xAAAA 0x7123 0xBBC1FF";
  const char fstr[] = "%p %p %p %p";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_ptr_eq(a1, a2);
  ck_assert_ptr_eq(b1, b2);
  ck_assert_ptr_eq(c1, c2);
  ck_assert_ptr_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_pointer2) {
  int *a1 = 0, *a2 = 0, *b1 = 0, *b2 = 0, *c1 = 0, *c2 = 0, *d1 = 0, *d2 = 0;
  const char str[] = "0xFFFF 0xAAAA 0x7123 0xBBC1FF";
  const char fstr[] = "%p %p %p %p";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_ptr_eq(a1, a2);
  ck_assert_ptr_eq(b1, b2);
  ck_assert_ptr_eq(c1, c2);
  ck_assert_ptr_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_pointer3) {
  int *a1 = 0, *a2 = 0, *b1 = 0, *b2 = 0, *c1 = 0, *c2 = 0, *d1 = 0, *d2 = 0;
  const char str[] = "0xFFFF 0xAAAA 0x7123 0xBBC1FF";
  const char fstr[] = "%p %p %p %p";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_ptr_eq(a1, a2);
  ck_assert_ptr_eq(b1, b2);
  ck_assert_ptr_eq(c1, c2);
  ck_assert_ptr_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_pointer4) {
  int *a1 = 0, *a2 = 0, *b1 = 0, *b2 = 0, *c1 = 0, *c2 = 0, *d1 = 0, *d2 = 0;
  const char str[] = "0xFFFF 0xAAAA 0x7123 0xBBC1FF";
  const char fstr[] = "%p %p %p %p";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_ptr_eq(a1, a2);
  ck_assert_ptr_eq(b1, b2);
  ck_assert_ptr_eq(c1, c2);
  ck_assert_ptr_eq(d1, d2);
}
END_TEST
START_TEST(sscanf_buff3) {
  int32_t a1, a2;
  int32_t b1 = 0, b2 = 0;
  const char str[] = "12keppa12";
  const char fstr[] = "%dkeppa%d";
  int32_t res1 = s21_sscanf(str, fstr, &a1, &b1);
  int32_t res2 = sscanf(str, fstr, &a2, &b2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
}
END_TEST

START_TEST(sscanf_octal_nohex) {
  uint32_t a1, a2;
  const char str[] = "tqwqpl";
  const char fstr[] = "%o";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_perc1) {
  int32_t a1, a2;
  int32_t b1 = 0, b2 = 0;
  int32_t c1 = 0, c2 = 0;
  const char str[] = "12 % 13 % 14";
  const char fstr[] = "%d %% %d %% %d";
  int32_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1);
  int32_t res2 = sscanf(str, fstr, &a2, &b2, &c2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
}
END_TEST

START_TEST(sscanf_perc2) {
  int32_t a1, a2;
  int32_t b1 = 0, b2 = 0;
  int32_t c1 = 0, c2 = 0;
  const char str[] = "12%13%14";
  const char fstr[] = "%d%%%d%%%d";
  int32_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1);
  int32_t res2 = sscanf(str, fstr, &a2, &b2, &c2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
}
END_TEST

START_TEST(sscanf_perc3) {
  int32_t a1 = 0, a2 = 0;

  const char str[] = "%%%16";
  const char fstr[] = "%%%%%%%d";
  int32_t res1 = s21_sscanf(str, fstr, &a1);
  int32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(sscanf_perc4) {
  const char str[] = "%%%";
  const char fstr[] = "%%%%%%";
  int32_t res1 = s21_sscanf(str, fstr);
  int32_t res2 = sscanf(str, fstr);

  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_perc5) {
  int32_t a1 = 0, a2 = 0;
  int32_t b1 = 0, b2 = 0;

  const char str[] = "%%123%888";
  const char fstr[] = "%%%%%d%%%d";
  int32_t res1 = s21_sscanf(str, fstr, &a1, &b1);
  int32_t res2 = sscanf(str, fstr, &a2, &b2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
}
END_TEST

START_TEST(sscanf_mixed_ptrs1) {
  int *a1 = 0, *a2 = 0, *b1 = 0, *b2 = 0, *c1 = 0, *c2 = 0, *d1 = 0, *d2 = 0;

  const char str[] = "0xFFFF 0xAAA 7123 0xBBC1FF";
  const char fstr[] = "%p %p %p %p";

  int32_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int32_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_ptr_eq(a1, a2);
  ck_assert_ptr_eq(b1, b2);
  ck_assert_ptr_eq(c1, c2);
  ck_assert_ptr_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_mixed_ptrs2) {
  char *a1 = 0, *a2 = 0, *b1 = 0, *b2 = 0, *c1 = 0, *c2 = 0, *d1 = 0, *d2 = 0;

  const char str[] = "0x4 0x3 0x2 0x1";
  const char fstr[] = "%p %p %p %p";

  int32_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int32_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_ptr_eq(a1, a2);
  ck_assert_ptr_eq(b1, b2);
  ck_assert_ptr_eq(c1, c2);
  ck_assert_ptr_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_mixed_ptrs3) {
  int *a1 = 0, *a2 = 0, *b1 = 0, *b2 = 0, *c1 = 0, *c2 = 0, *d1 = 0, *d2 = 0;

  const char str[] = "03033 0333 0123 0123 0x123 0xFFFFF 0xBBC1FF";
  const char fstr[] = "%p %p %p %p";

  int32_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int32_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_ptr_eq(a1, a2);
  ck_assert_ptr_eq(b1, b2);
  ck_assert_ptr_eq(c1, c2);
  ck_assert_ptr_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_mixed_ptrs4) {
  int *a1 = 0, *a2 = 0, *b1 = 0, *b2 = 0, *c1 = 0, *c2 = 0, *d1 = 0, *d2 = 0;

  const char str[] = "0xABCDEF 0xAAA 7123 0xBBC1FF";
  const char fstr[] = "%p %p %p %p";

  int32_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int32_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_ptr_eq(a1, a2);
  ck_assert_ptr_eq(b1, b2);
  ck_assert_ptr_eq(c1, c2);
  ck_assert_ptr_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_mixed_ptrs5) {
  int *a1 = 0, *a2 = 0, *b1 = 0, *b2 = 0, *c1 = 0, *c2 = 0, *d1 = 0, *d2 = 0;

  const char str[] = "NULL";
  const char fstr[] = "%p %p %p %p";

  int32_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int32_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_ptr_eq(a1, a2);
  ck_assert_ptr_eq(b1, b2);
  ck_assert_ptr_eq(c1, c2);
  ck_assert_ptr_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_c_2) {
  char format[] = "%c";
  char str[] = "\t\n\n  1 \n  \t";
  char c1, c2;

  int16_t res1 = s21_sscanf(str, format, &c1);
  int16_t res2 = sscanf(str, format, &c2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(c1, c2);
}
END_TEST

START_TEST(sscanf_spec_c_4) {
  char format[] = "%c";
  char str[] = "\t\n\n   \n  \ta";
  char c1, c2;
  int16_t res1 = s21_sscanf(str, format, &c1);
  int16_t res2 = sscanf(str, format, &c2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(c1, c2);
}
END_TEST

START_TEST(sscanf_spec_c_5) {
  char format[] = "%c%c%c";
  char str[] = "\t\n\n  123 \n  \t";
  char c11, c12, c13, c21, c22, c23;

  int16_t res1 = s21_sscanf(str, format, &c11, &c12, &c13);
  int16_t res2 = sscanf(str, format, &c21, &c22, &c23);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(c11, c21);
  ck_assert_int_eq(c12, c22);
  ck_assert_int_eq(c13, c23);
}
END_TEST

START_TEST(sscanf_spec_c_6) {
  char format[] = "%c %c \t%c";
  char str[] = "\t\n\n  1    2 3 \n  \t";
  char c11, c12, c13, c21, c22, c23;

  int16_t res1 = s21_sscanf(str, format, &c11, &c12, &c13);
  int16_t res2 = sscanf(str, format, &c21, &c22, &c23);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(c11, c21);
  ck_assert_int_eq(c12, c22);
  ck_assert_int_eq(c13, c23);
}
END_TEST

START_TEST(sscanf_spec_c_7) {
  char format[] = "%c %c \t%c";
  char str[] = "\t\n\n  123 \n  \t";
  char c11, c12, c13, c21, c22, c23;

  int16_t res1 = s21_sscanf(str, format, &c11, &c12, &c13);
  int16_t res2 = sscanf(str, format, &c21, &c22, &c23);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(c11, c21);
  ck_assert_int_eq(c12, c22);
  ck_assert_int_eq(c13, c23);
}
END_TEST

START_TEST(sscanf_spec_c_8) {
  char format[] = "%c %*c \t%c";
  char str[] = "\t\n\n  123 \n  \t";
  char c11, c12, c21, c22;

  int16_t res1 = s21_sscanf(str, format, &c11, &c12);
  int16_t res2 = sscanf(str, format, &c21, &c22);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(c11, c21);
  ck_assert_int_eq(c12, c22);
}
END_TEST

START_TEST(sscanf_spec_hd_1) {
  char format[] = "%hd";
  char str[] = "123";
  short d1, d2;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_hd_2) {
  char format[] = "%hd";
  char str[] = "-123";
  short d1, d2;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_hd_3) {
  char format[] = "%hd";
  char str[] = "+123";
  short d1, d2;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_hd_4) {
  char format[] = "%3hd";
  char str[] = "-123";
  short d1, d2;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_hd_5) {
  char format[] = "%4hd";
  char str[] = "-123";
  short d1, d2;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_hd_6) {
  char format[] = "%10hd";
  char str[] = "-123";
  short d1, d2;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_hd_7) {
  char format[] = "%1hd";
  char str[] = "-123";
  short d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_hd_8) {
  char format[] = "%3hd";
  char str[] = "+123";
  short d1, d2;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_hd_9) {
  char format[] = "%4hd";
  char str[] = "+123";
  short d1, d2;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_hd_10) {
  char format[] = "%10hd";
  char str[] = "+123";
  short d1, d2;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_hd_11) {
  char format[] = "%1hd";
  char str[] = "+123";
  short d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_hd_12) {
  char format[] = "%*1hd";
  char str[] = "+123";
  short d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_hd_13) {
  char format[] = "%*hd";
  char str[] = "123";
  short d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_hd_14) {
  char format[] = "%hd";
  char str[] = "2147483647";
  short d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_hd_15) {
  char format[] = "%hd";
  char str[] = "+2147483648";
  short d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_hd_16) {
  char format[] = "%hd";
  char str[] = "214743483648";
  short d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_hd_17) {
  char format[] = "%hd";
  char str[] = "-2147483648";
  short d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_hd_18) {
  char format[] = "%hd";
  char str[] = "-2147483649";
  short d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_hd_19) {
  char format[] = "%hd";
  char str[] = "-214748364239";
  short d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_hd_20) {
  char format[] = "%hd";
  char str[] = "−9223372036854775808";
  short d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_hd_21) {
  char format[] = "%hd";
  char str[] = "−9223372036854775809";
  short d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_hd_22) {
  char format[] = "%hd";
  char str[] = "−922337203685477582309";
  short d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_hd_23) {
  char format[] = "%hd";
  char str[] = "9223372036854775807";
  short d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_hd_24) {
  char format[] = "%hd";
  char str[] = "9223372036854775808";
  short d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_hd_25) {
  char format[] = "%hd";
  char str[] = "922337203685477582309";
  short d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_d_1) {
  char format[] = "%d";
  char str[] = "123";
  int d1, d2;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_d_2) {
  char format[] = "%d";
  char str[] = "-123";
  int d1, d2;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_d_3) {
  char format[] = "%d";
  char str[] = "+123";
  int d1, d2;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_d_4) {
  char format[] = "%3d";
  char str[] = "-123";
  int d1, d2;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_d_5) {
  char format[] = "%4d";
  char str[] = "-123";
  int d1, d2;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_d_6) {
  char format[] = "%10d";
  char str[] = "-123";
  int d1, d2;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_d_7) {
  char format[] = "%1d";
  char str[] = "-123";
  int d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_d_8) {
  char format[] = "%3d";
  char str[] = "+123";
  int d1, d2;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_d_9) {
  char format[] = "%4d";
  char str[] = "+123";
  int d1, d2;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_d_10) {
  char format[] = "%10d";
  char str[] = "+123";
  int d1, d2;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_d_11) {
  char format[] = "%1d";
  char str[] = "+123";
  int d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_d_12) {
  char format[] = "%*1d";
  char str[] = "+123";
  int d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_d_13) {
  char format[] = "%*d";
  char str[] = "123";
  int d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_d_14) {
  char format[] = "%d";
  char str[] = "2147483647";
  int d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_d_15) {
  char format[] = "%d";
  char str[] = "+2147483648";
  int d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_d_16) {
  char format[] = "%d";
  char str[] = "214743483648";
  int d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_d_17) {
  char format[] = "%d";
  char str[] = "-2147483648";
  int d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_d_18) {
  char format[] = "%d";
  char str[] = "-2147483649";
  int d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_d_19) {
  char format[] = "%d";
  char str[] = "-214748364239";
  int d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_d_20) {
  char format[] = "%d";
  char str[] = "−9223372036854775808";
  int d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_d_21) {
  char format[] = "%d";
  char str[] = "−9223372036854775809";
  int d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_d_22) {
  char format[] = "%d";
  char str[] = "−922337203685477582309";
  int d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_d_23) {
  char format[] = "%d";
  char str[] = "9223372036854775807";
  int d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_ld_1) {
  char format[] = "%ld";
  char str[] = "123";
  long int d1, d2;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_ld_2) {
  char format[] = "%ld";
  char str[] = "-123";
  long int d1, d2;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_ld_3) {
  char format[] = "%ld";
  char str[] = "+123";
  long int d1, d2;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_ld_4) {
  char format[] = "%3ld";
  char str[] = "-123";
  long int d1, d2;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_ld_5) {
  char format[] = "%4ld";
  char str[] = "-123";
  long int d1, d2;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_ld_6) {
  char format[] = "%10ld";
  char str[] = "-123";
  long int d1, d2;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_ld_7) {
  char format[] = "%1ld";
  char str[] = "-123";
  long int d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_ld_8) {
  char format[] = "%3ld";
  char str[] = "+123";
  long int d1, d2;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_ld_9) {
  char format[] = "%4ld";
  char str[] = "+123";
  long int d1, d2;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_ld_10) {
  char format[] = "%10ld";
  char str[] = "+123";
  long int d1, d2;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_ld_11) {
  char format[] = "%1ld";
  char str[] = "+123";
  long int d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_ld_12) {
  char format[] = "%*1ld";
  char str[] = "+123";
  long int d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_ld_13) {
  char format[] = "%*ld";
  char str[] = "123";
  long int d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_ld_14) {
  char format[] = "%ld";
  char str[] = "2147483647";
  long int d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_ld_15) {
  char format[] = "%ld";
  char str[] = "+2147483648";
  long int d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_ld_16) {
  char format[] = "%ld";
  char str[] = "214743483648";
  long int d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_ld_17) {
  char format[] = "%ld";
  char str[] = "-2147483648";
  long int d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_ld_18) {
  char format[] = "%ld";
  char str[] = "-2147483649";
  long int d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_ld_19) {
  char format[] = "%ld";
  char str[] = "-214748364239";
  long int d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_ld_20) {
  char format[] = "%ld";
  char str[] = "−9223372036854775808";
  long int d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_ld_21) {
  char format[] = "%ld";
  char str[] = "−9223372036854775809";
  long int d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_ld_22) {
  char format[] = "%ld";
  char str[] = "−922337203685477582309";
  long int d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_ld_23) {
  char format[] = "%ld";
  char str[] = "9223372036854775807";
  long int d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_ld_24) {
  char format[] = "%ld";
  char str[] = "-9223372036854775808";
  long int d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_ld_25) {
  char format[] = "%ld";
  char str[] = "-922337203685477582309";
  long int d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_ld_26) {
  char format[] = "%ld";
  char str[] = "9223372036854775808";
  long int d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_ld_27) {
  char format[] = "%ld";
  char str[] = "922337203685477582309";
  long int d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_n_1) {
  char format[] = "%n";
  char str[] = "Ilyusha";
  int n1 = 0, n2 = 0;

  int16_t res1 = s21_sscanf(str, format, &n1);
  int16_t res2 = sscanf(str, format, &n2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(sscanf_spec_n_2) {
  char format[] = "%d %n";
  char str[] = "80 Ilyusha";
  int d1 = 0, d2 = 0;
  int n1 = 0, n2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &n1);
  int16_t res2 = sscanf(str, format, &d2, &n2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(sscanf_spec_n_3) {
  char format[] = "%d %d %n %d %d %d";
  char str[] = "80 50 70 371 327";
  int d1 = 0, d2 = 0;
  int dd1 = 0, dd2 = 0;
  int f1 = 0, f2 = 0;
  int ff1 = 0, ff2 = 0;
  int k1 = 0, k2 = 0;
  int n1 = 0, n2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &dd1, &n1, &f1, &ff1, &k1);
  int16_t res2 = sscanf(str, format, &d2, &dd2, &n2, &f2, &ff2, &k2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(dd1, dd2);
  ck_assert_int_eq(f1, f2);
  ck_assert_int_eq(ff1, ff2);
  ck_assert_int_eq(k1, k2);
  ck_assert_int_eq(n1, n2);
}
END_TEST

// START_TEST(sscanf_spec_n_4) {
//   char format[] = "Hello%n";
//   char str[] = "Hello";
//   int n1 = 0, n2 = 0;

//   int16_t res1 = s21_sscanf(str, format, &n1);
//   int16_t res2 = sscanf(str, format, &n2);
//   ck_assert_int_eq(res1, res2);
//   ck_assert_int_eq(n1, n2);
// }
// END_TEST

START_TEST(sscanf_spec_n_5) {
  char format[] = "%d %n %d %n %d %d %n %d";
  char str[] = "80 50 70 371 327";
  int d1 = 0, d2 = 0;
  int dd1 = 0, dd2 = 0;
  int f1 = 0, f2 = 0;
  int ff1 = 0, ff2 = 0;
  int k1 = 0, k2 = 0;
  int hn1 = 0, hn2 = 0;
  int hhn1 = 0, hhn2 = 0;
  int n1 = 0, n2 = 0;

  int16_t res1 =
      s21_sscanf(str, format, &d1, &hn1, &dd1, &hhn1, &f1, &ff1, &n1, &k1);
  int16_t res2 =
      sscanf(str, format, &d2, &hn2, &dd2, &hhn2, &f2, &ff2, &n2, &k2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(dd1, dd2);
  ck_assert_int_eq(f1, f2);
  ck_assert_int_eq(ff1, ff2);
  ck_assert_int_eq(k1, k2);
  ck_assert_int_eq(n1, n2);
  ck_assert_int_eq(hn1, hn2);
  ck_assert_int_eq(hhn1, hhn2);
}
END_TEST

START_TEST(sscanf_spec_n_6) {
  char format[] = "%d %ln %d %lln %d %d %lln %d";
  char str[] = "3263 225 724 38 482";
  int d1 = 0, d2 = 0;
  int dd1 = 0, dd2 = 0;
  int f1 = 0, f2 = 0;
  int ff1 = 0, ff2 = 0;
  int k1 = 0, k2 = 0;
  long int hn1 = 0, hn2 = 0;
  long long int hhn1 = 0, hhn2 = 0;
  long long int n1 = 0, n2 = 0;

  int16_t res1 =
      s21_sscanf(str, format, &d1, &hn1, &dd1, &hhn1, &f1, &ff1, &n1, &k1);
  int16_t res2 =
      sscanf(str, format, &d2, &hn2, &dd2, &hhn2, &f2, &ff2, &n2, &k2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(dd1, dd2);
  ck_assert_int_eq(f1, f2);
  ck_assert_int_eq(ff1, ff2);
  ck_assert_int_eq(k1, k2);
  ck_assert_int_eq(n1, n2);
  ck_assert_int_eq(hn1, hn2);
  ck_assert_int_eq(hhn1, hhn2);
}
END_TEST

START_TEST(sscanf_spec_n_7) {
  char format[] = "%%%c";
  char str[] = "%p";
  char d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_n_8) {
  char format[] = "%s %n %s %n %s %s %s %n";
  char str[] = "Hello, my name is Jinny";
  char s1[30], s2[30], s3[30], s4[30], s5[30], s6[30], s7[30], s8[30], s9[30],
      s10[30];
  int n1 = 0, n2 = 0;
  int hn1 = 0, hn2 = 0;
  int hhn1 = 0, hhn2 = 0;

  int16_t res1 =
      s21_sscanf(str, format, &s1, &hn1, &s3, &hhn1, &s5, &s7, &s9, &n1);
  int16_t res2 =
      sscanf(str, format, &s2, &hn2, &s4, &hhn2, &s6, &s8, &s10, &n2);
  ck_assert_int_eq(res1, res2);
  ck_assert_pstr_eq(s1, s2);
  ck_assert_pstr_eq(s3, s4);
  ck_assert_pstr_eq(s5, s6);
  ck_assert_pstr_eq(s7, s8);
  ck_assert_pstr_eq(s9, s10);
  ck_assert_int_eq(n1, n2);
  ck_assert_int_eq(hn1, hn2);
  ck_assert_int_eq(hhn1, hhn2);
}
END_TEST

START_TEST(sscanf_spec_n_9) {
  char format[] = "%lf %lf %lf %lf %n %lf";
  char str[] = "0.0 66.34 9877.66 1.99 0.999";
  long double d1 = 0, d2 = 0;
  long double dd1 = 0, dd2 = 0;
  long double f1 = 0, f2 = 0;
  long double ff1 = 0, ff2 = 0;
  long double k1 = 0, k2 = 0;
  int n1 = 0, n2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &dd1, &f1, &ff1, &n1, &k1);
  int16_t res2 = sscanf(str, format, &d2, &dd2, &f2, &ff2, &n2, &k2);
  ck_assert_ldouble_eq(res1, res2);
  ck_assert_ldouble_eq(d1, d2);
  ck_assert_ldouble_eq(dd1, dd2);
  ck_assert_ldouble_eq(f1, f2);
  ck_assert_ldouble_eq(ff1, ff2);
  ck_assert_ldouble_eq(k1, k2);
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(sscanf_spec_n_10) {
  char format[] = "%s %s";
  char str[] = "hi \t\n";
  char s1[20], s2[20] = {0}, s3[20], s4[20] = {0};

  int16_t res1 = s21_sscanf(str, format, s1, s2);
  int16_t res2 = sscanf(str, format, s3, s4);
  ck_assert_ldouble_eq(res1, res2);
  ck_assert_pstr_eq(s1, s3);
  ck_assert_pstr_eq(s2, s4);
}
END_TEST

START_TEST(sscanf_empty_1) {
  char format[] = "%d";
  char str[] = "";
  int p1, p2;

  int16_t res1 = s21_sscanf(str, format, &p1);
  int16_t res2 = sscanf(str, format, &p2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_empty_2) {
  char format[] = "%d";
  char str[] = "     ";
  int p1, p2;

  int16_t res1 = s21_sscanf(str, format, &p1);
  int16_t res2 = sscanf(str, format, &p2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_empty_3) {
  char format[] = "%d";
  char str[] = "\n";
  int p1, p2;

  int16_t res1 = s21_sscanf(str, format, &p1);
  int16_t res2 = sscanf(str, format, &p2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_empty_4) {
  char format[] = "%d";
  char str[] = "\t";
  int p1, p2;

  int16_t res1 = s21_sscanf(str, format, &p1);
  int16_t res2 = sscanf(str, format, &p2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_empty_5) {
  char format[] = "%d";
  char str[] = "\t\n\n   \n  \t";
  int p1, p2;

  int16_t res1 = s21_sscanf(str, format, &p1);
  int16_t res2 = sscanf(str, format, &p2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_empty_6) {
  char format[] = "";
  char str[] = "\t\n\n   \n  \t";
  int p1, p2;

  int16_t res1 = s21_sscanf(str, format, &p1);
  int16_t res2 = sscanf(str, format, &p2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_empty_7) {
  char format[] = "\t";
  char str[] = "\t\n\n   \n  \t";
  int p1, p2;

  int16_t res1 = s21_sscanf(str, format, &p1);
  int16_t res2 = sscanf(str, format, &p2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_p_1) {
  char format[] = "%p";
  char str[] = "0xAAAA";
  int *p1 = 0, *p2 = 0;

  int16_t res1 = s21_sscanf(str, format, &p1);
  int16_t res2 = sscanf(str, format, &p2);
  ck_assert_int_eq(res1, res2);
  ck_assert_ptr_eq(p1, p2);
}
END_TEST

START_TEST(sscanf_spec_p_2) {
  char format[] = "%5p";
  char str[] = "0xAAAA";
  int *p1 = 0, *p2 = 0;

  int16_t res1 = s21_sscanf(str, format, &p1);
  int16_t res2 = sscanf(str, format, &p2);
  ck_assert_int_eq(res1, res2);
  ck_assert_ptr_eq(p1, p2);
}
END_TEST

START_TEST(sscanf_spec_p_3) {
  char format[] = "%p";
  char str[] = "0xFFFFFF";
  int *p1 = 0, *p2 = 0;

  int16_t res1 = s21_sscanf(str, format, &p1);
  int16_t res2 = sscanf(str, format, &p2);
  ck_assert_int_eq(res1, res2);
  ck_assert_ptr_eq(p1, p2);
}
END_TEST

START_TEST(sscanf_spec_p_4) {
  char format[] = "%p";
  char str[] = "0x0000";
  int *p1 = 0, *p2 = 0;

  int16_t res1 = s21_sscanf(str, format, &p1);
  int16_t res2 = sscanf(str, format, &p2);
  ck_assert_int_eq(res1, res2);
  ck_assert_ptr_eq(p1, p2);
}
END_TEST

START_TEST(sscanf_spec_p_5) {
  char format[] = "%p";
  char str[] = "0xA2361598";
  int *p1 = 0, *p2 = 0;
  int16_t res1 = s21_sscanf(str, format, &p1);
  int16_t res2 = sscanf(str, format, &p2);
  ck_assert_int_eq(res1, res2);
  ck_assert_ptr_eq(p1, p2);
}
END_TEST

START_TEST(sscanf_spec_p_6) {
  char format[] = "%p";
  char str[] = "0x34567hjk";
  int *p1 = 0, *p2 = 0;

  int16_t res1 = s21_sscanf(str, format, &p1);
  int16_t res2 = sscanf(str, format, &p2);
  ck_assert_int_eq(res1, res2);
  ck_assert_ptr_eq(p1, p2);
}
END_TEST

START_TEST(sscanf_spec_p_7) {
  char format[] = "%p";
  char str[] = "0x34567hjk678";
  int *p1 = 0, *p2 = 0;

  int16_t res1 = s21_sscanf(str, format, &p1);
  int16_t res2 = sscanf(str, format, &p2);
  ck_assert_int_eq(res1, res2);
  ck_assert_ptr_eq(p1, p2);
}
END_TEST

START_TEST(sscanf_spec_p_8) {
  char format[] = "%p";
  char str[] = "0x34ABcd68";
  int *p1 = 0, *p2 = 0;

  int16_t res1 = s21_sscanf(str, format, &p1);
  int16_t res2 = sscanf(str, format, &p2);
  ck_assert_int_eq(res1, res2);
  ck_assert_ptr_eq(p1, p2);
}
END_TEST

START_TEST(sscanf_spec_p_10) {
  char format[] = "%5p";
  char str[] = "0x237481";
  int *p1 = 0, *p2 = 0;

  int16_t res1 = s21_sscanf(str, format, &p1);
  int16_t res2 = sscanf(str, format, &p2);
  ck_assert_int_eq(res1, res2);
  ck_assert_ptr_eq(p1, p2);
}
END_TEST

START_TEST(sscanf_spec_p_11) {
  char format[] = "%6p";
  char str[] = "0xdksajh";
  int *p1 = 0, *p2 = 0;

  int16_t res1 = s21_sscanf(str, format, &p1);
  int16_t res2 = sscanf(str, format, &p2);
  ck_assert_int_eq(res1, res2);
  ck_assert_ptr_eq(p1, p2);
}
END_TEST

START_TEST(sscanf_spec_p_12) {
  char format[] = "%6p";
  char str[] = "0xAGAGUIY";
  int *p1 = 0, *p2 = 0;

  int16_t res1 = s21_sscanf(str, format, &p1);
  int16_t res2 = sscanf(str, format, &p2);
  ck_assert_int_eq(res1, res2);
  ck_assert_ptr_eq(p1, p2);
}
END_TEST

START_TEST(sscanf_spec_p_13) {
  char format[] = "%p";
  char str[] = "0xAGAGUIYUYGFSV";
  int *p1 = 0, *p2 = 0;

  int16_t res1 = s21_sscanf(str, format, &p1);
  int16_t res2 = sscanf(str, format, &p2);
  ck_assert_int_eq(res1, res2);
  ck_assert_ptr_eq(p1, p2);
}
END_TEST

START_TEST(sscanf_spec_p_14) {
  char format[] = "%p";
  char str[] = "0xAA64BB";
  int *p1 = 0, *p2 = 0;

  int16_t res1 = s21_sscanf(str, format, &p1);
  int16_t res2 = sscanf(str, format, &p2);
  ck_assert_int_eq(res1, res2);
  ck_assert_ptr_eq(p1, p2);
}
END_TEST

START_TEST(sscanf_spec_p_15) {
  char format[] = "%p";
  char str[] = "0xGGH7TY";
  int *p1 = 0, *p2 = 0;

  int16_t res1 = s21_sscanf(str, format, &p1);
  int16_t res2 = sscanf(str, format, &p2);
  ck_assert_int_eq(res1, res2);
  ck_assert_ptr_eq(p1, p2);
}
END_TEST

START_TEST(sscanf_spec_real_1) {
  char format[] = "%f %f %f";
  char str[] = "123 +198 -87";
  float d1, d2;
  float q1, q2;
  float z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_float_eq(d1, d2);
  ck_assert_float_eq(q1, q2);
  ck_assert_float_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_real_2) {
  char format[] = "%fg %f w%fx";
  char str[] = "75g +19.8w -87.x";
  float d1 = 0, d2 = 0;
  float q1 = 0, q2 = 0;
  float z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_float_eq(d1, d2);
  ck_assert_float_eq(q1, q2);
  ck_assert_float_eq(z1, z2);
}
END_TEST

// START_TEST(sscanf_spec_real_3) {
//   char format[] = "%f %f %f %f";
//   char str[] = "NAN nan -INF +inf";
//   float d1, d2;
//   float q1, q2;
//   float z1, z2;
//   float w1, w2;

//   int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1, &w1);
//   int16_t res2 = sscanf(str, format, &d2, &q2, &z2, &w2);
//   ck_assert_int_eq(res1, res2);
//   ck_assert_float_nan(d1);
//   ck_assert_float_nan(d2);
//   ck_assert_float_nan(q1);
//   ck_assert_float_nan(q2);
//   ck_assert_float_eq(z1, z2);
// }
// END_TEST

START_TEST(sscanf_spec_real_4) {
  char format[] = "%f";
  char str[] = "Nap";
  float d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_float_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_real_5) {
  char format[] = "%f";
  char str[] = "Np";
  float d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_float_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_real_6) {
  char format[] = "%f";
  char str[] = "iNd";
  float d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_float_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_real_7) {
  char format[] = "%f";
  char str[] = "id";
  float d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_float_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_real_8) {
  char format[] = "%f %f %f %f";
  char str[] = "34.56e3 83.2e-4 .43e+1 +2.43e3";
  float d1, d2;
  float q1, q2;
  float z1, z2;
  float w1, w2;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1, &w1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2, &w2);
  ck_assert_int_eq(res1, res2);
  ck_assert_float_eq(d1, d2);
  ck_assert_float_eq(q1, q2);
  ck_assert_float_eq(z1, z2);
  ck_assert_float_eq(w1, w2);
}
END_TEST

START_TEST(sscanf_spec_real_9) {
  char format[] = "%1f %1f %2f %1f";
  char str[] = "34.5+6e3 83.2e-4 .43e+1 +2.43e3";
  float d1, d2;
  float q1, q2;
  float z1, z2;
  float w1 = 0, w2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1, &w1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2, &w2);
  ck_assert_int_eq(res1, res2);
  ck_assert_float_eq(d1, d2);
  ck_assert_float_eq(q1, q2);
  ck_assert_float_eq(z1, z2);
  ck_assert_float_eq(w1, w2);
}
END_TEST

START_TEST(sscanf_spec_real_10) {
  char format[] = "%*f %7f";
  char str[] = "34.56e+3 83.2e-4";
  float d1 = 0, d2 = 0;
  float q1 = 0, q2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1);
  int16_t res2 = sscanf(str, format, &d2, &q2);
  ck_assert_int_eq(res1, res2);
  ck_assert_float_eq(d1, d2);
  ck_assert_float_eq(q1, q2);
}
END_TEST

START_TEST(sscanf_spec_real_11) {
  char format[] = "%fr %7f p";
  char str[] = "34.5r 83.2ep4";
  float d1, d2;
  float q1 = 0, q2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1);
  int16_t res2 = sscanf(str, format, &d2, &q2);
  ck_assert_int_eq(res1, res2);
  ck_assert_float_eq(d1, d2);
  ck_assert_float_eq(q1, q2);
}
END_TEST

START_TEST(sscanf_spec_real_12) {
  char format[] = "%1f %1f %1f %1f";
  char str[] = "34 32. +45.e +23E3 -0.3e4";
  float d1, d2;
  float q1 = 0, q2 = 0;
  float z1 = 0, z2 = 0;
  float w1 = 0, w2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1, &w1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2, &w2);
  ck_assert_int_eq(res1, res2);
  ck_assert_float_eq(d1, d2);
  ck_assert_float_eq(q1, q2);
  ck_assert_float_eq(z1, z2);
  ck_assert_float_eq(w1, w2);
}
END_TEST

START_TEST(sscanf_spec_real_13) {
  char format[] = "%2f %2f %2f %2f";
  char str[] = "34 3. +45.e +23E3 -0.3e4";
  float d1, d2;
  float q1 = 0, q2 = 0;
  float z1 = 0, z2 = 0;
  float w1 = 0, w2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1, &w1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2, &w2);
  ck_assert_int_eq(res1, res2);
  ck_assert_float_eq(d1, d2);
  ck_assert_float_eq(q1, q2);
  ck_assert_float_eq(z1, z2);
  ck_assert_float_eq(w1, w2);
}
END_TEST

START_TEST(sscanf_spec_real_14) {
  char format[] = "%3f %3f %4f %3f";
  char str[] = "34 3. +45.e +23E3 -0.3e4";
  float d1, d2;
  float q1 = 0, q2 = 0;
  float z1 = 0, z2 = 0;
  float w1 = 0, w2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1, &w1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2, &w2);
  ck_assert_int_eq(res1, res2);
  ck_assert_float_eq(d1, d2);
  ck_assert_float_eq(q1, q2);
  ck_assert_float_eq(z1, z2);
  ck_assert_float_eq(w1, w2);
}
END_TEST

START_TEST(sscanf_spec_real_15) {
  char format[] = "%4f %4f %4f %4f";
  char str[] = "34 3. +45.e +23E3 -0.3e4";
  float d1, d2;
  float q1 = 0, q2 = 0;
  float z1 = 0, z2 = 0;
  float w1 = 0, w2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1, &w1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2, &w2);
  ck_assert_int_eq(res1, res2);
  ck_assert_float_eq(d1, d2);
  ck_assert_float_eq(q1, q2);
  ck_assert_float_eq(z1, z2);
  ck_assert_float_eq(w1, w2);
}
END_TEST

START_TEST(sscanf_spec_real_18) {
  char format[] = "%f %fx %2f1 %2fx %*f %*f";
  char str[] = "1.1 2.x 1.1 2.x 1.1 2.x";
  float d1, d2;
  float q1 = 0, q2 = 0;
  float z1 = 0, z2 = 0;
  float w1 = 0, w2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1, &w1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2, &w2);
  ck_assert_int_eq(res1, res2);
  ck_assert_float_eq(d1, d2);
  ck_assert_float_eq(q1, q2);
  ck_assert_float_eq(z1, z2);
  ck_assert_float_eq(w1, w2);
}
END_TEST

START_TEST(sscanf_spec_real_19) {
  char format[] = "%f %4f %5fq %6f %*f q%*f";
  char str[] = "1.3e1 1.4eq2 1.3e1q 1.4 1.3eq 1.4e2";
  float d1, d2;
  float q1 = 0, q2 = 0;
  float z1 = 0, z2 = 0;
  float w1 = 0, w2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1, &w1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2, &w2);
  ck_assert_int_eq(res1, res2);
  ck_assert_float_eq(d1, d2);
  ck_assert_float_eq(q1, q2);
  ck_assert_float_eq(z1, z2);
  ck_assert_float_eq(w1, w2);
}
END_TEST

START_TEST(sscanf_spec_ho_1) {
  char format[] = "%ho%ho%ho";
  char str[] = "123 +198 -87";
  unsigned short d1, d2;
  unsigned short q1, q2;
  unsigned short z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_ho_2) {
  char format[] = "%ho%ho%ho";
  char str[] = "123 +1564 -1723";
  unsigned short d1 = 0, d2 = 0;
  unsigned short q1 = 0, q2 = 0;
  unsigned short z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_ho_3) {
  char format[] = "%1ho %1ho %1ho";
  char str[] = "1 +04 -3723";
  unsigned short d1 = 0, d2 = 0;
  unsigned short q1 = 0, q2 = 0;
  unsigned short z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_ho_4) {
  char format[] = "%2ho %2ho %2ho";
  char str[] = "0123 +04 -3723";
  unsigned short d1 = 0, d2 = 0;
  unsigned short q1 = 0, q2 = 0;
  unsigned short z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_ho_5) {
  char format[] = "%3ho %3ho %3ho";
  char str[] = "0123 +04 -3723";
  unsigned short d1 = 0, d2 = 0;
  unsigned short q1 = 0, q2 = 0;
  unsigned short z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_ho_6) {
  char format[] = "%*ho %*ho %*ho";
  char str[] = "0123 +04 -3723";
  unsigned short d1 = 0, d2 = 0;
  unsigned short q1 = 0, q2 = 0;
  unsigned short z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_o_1) {
  char format[] = "%o%o%o";
  char str[] = "123 +198 -87";
  unsigned int d1, d2;
  unsigned int q1, q2;
  unsigned int z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_o_2) {
  char format[] = "%o%o%o";
  char str[] = "123 +1564 -1723";
  unsigned int d1 = 0, d2 = 0;
  unsigned int q1 = 0, q2 = 0;
  unsigned int z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_o_3) {
  char format[] = "%1o %1o %1o";
  char str[] = "1 +04 -3723";
  unsigned int d1 = 0, d2 = 0;
  unsigned int q1 = 0, q2 = 0;
  unsigned int z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_o_4) {
  char format[] = "%2o %2o %2o";
  char str[] = "0123 +04 -3723";
  unsigned int d1 = 0, d2 = 0;
  unsigned int q1 = 0, q2 = 0;
  unsigned int z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_o_5) {
  char format[] = "%3o %3o %3o";
  char str[] = "0123 +04 -3723";
  unsigned int d1 = 0, d2 = 0;
  unsigned int q1 = 0, q2 = 0;
  unsigned int z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_o_6) {
  char format[] = "%*o %*o %*o";
  char str[] = "0123 +04 -3723";
  unsigned int d1 = 0, d2 = 0;
  unsigned int q1 = 0, q2 = 0;
  unsigned int z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_lo_1) {
  char format[] = "%lo%lo%lo";
  char str[] = "123 +198 -87";
  unsigned long int d1, d2;
  unsigned long int q1, q2;
  unsigned long int z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_lo_2) {
  char format[] = "%lo%lo%lo";
  char str[] = "123 +1564 -1723";
  unsigned long int d1 = 0, d2 = 0;
  unsigned long int q1 = 0, q2 = 0;
  unsigned long int z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_lo_3) {
  char format[] = "%1lo %1lo %1lo";
  char str[] = "1 +04 -3723";
  unsigned long int d1 = 0, d2 = 0;
  unsigned long int q1 = 0, q2 = 0;
  unsigned long int z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_lo_4) {
  char format[] = "%2lo %2lo %2lo";
  char str[] = "0123 +04 -3723";
  unsigned long int d1 = 0, d2 = 0;
  unsigned long int q1 = 0, q2 = 0;
  unsigned long int z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_lo_5) {
  char format[] = "%3lo %3lo %3lo";
  char str[] = "0123 +04 -3723";
  unsigned long int d1 = 0, d2 = 0;
  unsigned long int q1 = 0, q2 = 0;
  unsigned long int z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_lo_6) {
  char format[] = "%*lo %*lo %*lo";
  char str[] = "0123 +04 -3723";
  unsigned long int d1 = 0, d2 = 0;
  unsigned long int q1 = 0, q2 = 0;
  unsigned long int z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_hx_1) {
  char format[] = "%hx%hx%hx";
  char str[] = "123 +198 -87";
  unsigned short d1, d2;
  unsigned short q1, q2;
  unsigned short z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_hx_2) {
  char format[] = "%hx%hx%hx";
  char str[] = "12a3 +156B4 -17C23";
  unsigned short d1 = 0, d2 = 0;
  unsigned short q1 = 0, q2 = 0;
  unsigned short z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_hx_3) {
  char format[] = "%hx%hx";
  char str[] = "0 +0x";
  unsigned short d1 = 0, d2 = 0;
  unsigned short q1 = 0, q2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1);
  int16_t res2 = sscanf(str, format, &d2, &q2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
}
END_TEST

START_TEST(sscanf_spec_hx_4) {
  char format[] = "%hx%hx%hx";
  char str[] = "0 -0XABC -0X";
  unsigned short d1 = 0, d2 = 0;
  unsigned short q1 = 0, q2 = 0;
  unsigned short z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_hx_5) {
  char format[] = "%hx%hx%hx";
  char str[] = "0abc4 -0XABC 0x";
  unsigned short d1 = 0, d2 = 0;
  unsigned short q1 = 0, q2 = 0;
  unsigned short z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_hx_6) {
  char format[] = "%1hx %1hx %1hx";
  char str[] = "1a +04 -3723";
  unsigned short d1 = 0, d2 = 0;
  unsigned short q1 = 0, q2 = 0;
  unsigned short z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_hx_7) {
  char format[] = "%1hx %1hx %1hx";
  char str[] = "1a 0x -3723";
  unsigned short d1 = 0, d2 = 0;
  unsigned short q1 = 0, q2 = 0;
  unsigned short z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_hx_8) {
  char format[] = "%2hx %2hx %2hx";
  char str[] = "1a bc 0x -3723";
  unsigned short d1 = 0, d2 = 0;
  unsigned short q1 = 0, q2 = 0;
  unsigned short z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_hx_9) {
  char format[] = "%2hx %2hx %2hx";
  char str[] = "1a bCc 0x -3723";
  unsigned short d1 = 0, d2 = 0;
  unsigned short q1 = 0, q2 = 0;
  unsigned short z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_hx_10) {
  char format[] = "%3hx %3hx %3hx";
  char str[] = "0x123 0X4 -37x23";
  unsigned short d1 = 0, d2 = 0;
  unsigned short q1 = 0, q2 = 0;
  unsigned short z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_hx_11) {
  char format[] = "%*hx %*hx %*hx";
  char str[] = "0x123 +04 -372f3";
  unsigned short d1 = 0, d2 = 0;
  unsigned short q1 = 0, q2 = 0;
  unsigned short z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_x_1) {
  char format[] = "%x%x%x";
  char str[] = "123 +198 -87";
  unsigned int d1, d2;
  unsigned int q1, q2;
  unsigned int z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_x_2) {
  char format[] = "%x%x%x";
  char str[] = "12a3 +156B4 -17C23";
  unsigned int d1 = 0, d2 = 0;
  unsigned int q1 = 0, q2 = 0;
  unsigned int z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_x_3) {
  char format[] = "%x%x";
  char str[] = "0 +0x";
  unsigned int d1 = 0, d2 = 0;
  unsigned int q1 = 0, q2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1);
  int16_t res2 = sscanf(str, format, &d2, &q2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
}
END_TEST

START_TEST(sscanf_spec_x_4) {
  char format[] = "%x%x%x";
  char str[] = "0 -0XABC -0X";
  unsigned int d1 = 0, d2 = 0;
  unsigned int q1 = 0, q2 = 0;
  unsigned int z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_x_5) {
  char format[] = "%x%x%x";
  char str[] = "0abc4 -0XABC 0x";
  unsigned int d1 = 0, d2 = 0;
  unsigned int q1 = 0, q2 = 0;
  unsigned int z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_x_6) {
  char format[] = "%1x %1x %1x";
  char str[] = "1a +04 -3723";
  unsigned int d1 = 0, d2 = 0;
  unsigned int q1 = 0, q2 = 0;
  unsigned int z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_x_7) {
  char format[] = "%1x %1x %1x";
  char str[] = "1a 0x -3723";
  unsigned int d1 = 0, d2 = 0;
  unsigned int q1 = 0, q2 = 0;
  unsigned int z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_x_8) {
  char format[] = "%2x %2x %2x";
  char str[] = "1a bc 0x -3723";
  unsigned int d1 = 0, d2 = 0;
  unsigned int q1 = 0, q2 = 0;
  unsigned int z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_x_9) {
  char format[] = "%2x %2x %2x";
  char str[] = "1a bCc 0x -3723";
  unsigned int d1 = 0, d2 = 0;
  unsigned int q1 = 0, q2 = 0;
  unsigned int z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_x_10) {
  char format[] = "%3x %3x %3x";
  char str[] = "0x123 0X4 37x23";
  unsigned int d1 = 0, d2 = 0;
  unsigned int q1 = 0, q2 = 0;
  unsigned int z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_x_11) {
  char format[] = "%*x %*x %*x";
  char str[] = "0x123 +04 -372f3";
  unsigned int d1 = 0, d2 = 0;
  unsigned int q1 = 0, q2 = 0;
  unsigned int z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_lx_1) {
  char format[] = "%lx%lx%lx";
  char str[] = "123 +198 -87";
  unsigned long int d1, d2;
  unsigned long int q1, q2;
  unsigned long int z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_lx_2) {
  char format[] = "%lx%lx%lx";
  char str[] = "12a3 +156B4 -17C23";
  unsigned long int d1 = 0, d2 = 0;
  unsigned long int q1 = 0, q2 = 0;
  unsigned long int z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_lx_3) {
  char format[] = "%lx%lx";
  char str[] = "0 +0x";
  unsigned long int d1 = 0, d2 = 0;
  unsigned long int q1 = 0, q2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1);
  int16_t res2 = sscanf(str, format, &d2, &q2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
}
END_TEST

START_TEST(sscanf_spec_lx_4) {
  char format[] = "%lx%lx%lx";
  char str[] = "0 -0XABC -0X";
  unsigned long int d1 = 0, d2 = 0;
  unsigned long int q1 = 0, q2 = 0;
  unsigned long int z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_lx_5) {
  char format[] = "%lx%lx%lx";
  char str[] = "0abc4 -0XABC 0x";
  unsigned long int d1 = 0, d2 = 0;
  unsigned long int q1 = 0, q2 = 0;
  unsigned long int z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_lx_6) {
  char format[] = "%1lx %1lx %1lx";
  char str[] = "1a +04 -3723";
  unsigned long int d1 = 0, d2 = 0;
  unsigned long int q1 = 0, q2 = 0;
  unsigned long int z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_lx_7) {
  char format[] = "%1lx %1lx %1lx";
  char str[] = "1a 0x -3723";
  unsigned long int d1 = 0, d2 = 0;
  unsigned long int q1 = 0, q2 = 0;
  unsigned long int z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_lx_8) {
  char format[] = "%2lx %2lx %2lx";
  char str[] = "1a bc 0x -3723";
  unsigned long int d1 = 0, d2 = 0;
  unsigned long int q1 = 0, q2 = 0;
  unsigned long int z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_lx_9) {
  char format[] = "%2lx %2lx %2lx";
  char str[] = "1a bCc 0x -3723";
  unsigned long int d1 = 0, d2 = 0;
  unsigned long int q1 = 0, q2 = 0;
  unsigned long int z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_lx_10) {
  char format[] = "%3lx %3lx %3lx";
  char str[] = "0x123 0X4 37x23";
  unsigned long int d1 = 0, d2 = 0;
  unsigned long int q1 = 0, q2 = 0;
  unsigned long int z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_lx_11) {
  char format[] = "%*lx %*lx %*lx";
  char str[] = "0x123 +04 -372f3";
  unsigned long int d1 = 0, d2 = 0;
  unsigned long int q1 = 0, q2 = 0;
  unsigned long int z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_hi_dec_1) {
  char format[] = "%hi%hi%hi";
  char str[] = "123 +198 -87";
  unsigned short d1, d2;
  unsigned short q1, q2;
  unsigned short z1, z2;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_hi_dec_2) {
  char format[] = "%hi %hi %hi";
  char str[] = "123 +198 -87";
  unsigned short d1, d2;
  unsigned short q1, q2;
  unsigned short z1, z2;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_hi_dec_3) {
  char format[] = "%1hi %1hi %1hi";
  char str[] = "13 +137 -8";
  unsigned short d1, d2;
  unsigned short q1, q2;
  unsigned short z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_hi_dec_4) {
  char format[] = "%2hi %2hi %2hi";
  char str[] = "13 +137 -8";
  unsigned short d1, d2;
  unsigned short q1, q2;
  unsigned short z1, z2;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_hi_dec_5) {
  char format[] = "%3hi %3hi %3hi";
  char str[] = "13 +137 -8";
  unsigned short d1, d2;
  unsigned short q1, q2;
  unsigned short z1, z2;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_hi_dec_6) {
  char format[] = "%30hi %24hi %21hi";
  char str[] = "13 +137 -8";
  unsigned short d1, d2;
  unsigned short q1, q2;
  unsigned short z1, z2;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_hi_dec_7) {
  char format[] = "%hi %hi %hi %hi";
  char str[] = "2147483647 +2147483648 -2147483648 -2147483649";
  unsigned short d1, d2;
  unsigned short q1, q2;
  unsigned short z1, z2;
  unsigned short w1, w2;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1, &w1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2, &w2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
  ck_assert_uint_eq(w1, w2);
}
END_TEST

START_TEST(sscanf_spec_hi_dec_8) {
  char format[] = "%hi %hi %hi %hi";
  char str[] =
      "9223372036854775807 +9223372036854775808 -9223372036854775808 "
      "-9223372036854775809";
  unsigned short d1, d2;
  unsigned short q1, q2;
  unsigned short z1, z2;
  unsigned short w1, w2;
  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1, &w1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2, &w2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
  ck_assert_uint_eq(w1, w2);
}
END_TEST

START_TEST(sscanf_spec_hi_oct_1) {
  char format[] = "%hi%hi%hi";
  char str[] = "0123 +0198 -087";
  unsigned short d1, d2;
  unsigned short q1, q2;
  unsigned short z1, z2;
  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_hi_oct_2) {
  char format[] = "%hi %hi %hi";
  char str[] = "0123 +0198 -087";
  unsigned short d1, d2;
  unsigned short q1, q2;
  unsigned short z1, z2;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_hi_oct_3) {
  char format[] = "%1hi %1hi %1hi";
  char str[] = "013 +0137 -08";
  unsigned short d1, d2;
  unsigned short q1, q2;
  unsigned short z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_hi_oct_4) {
  char format[] = "%2hi %2hi %2hi";
  char str[] = "013 +0137 -08";
  unsigned short d1, d2;
  unsigned short q1, q2;
  unsigned short z1, z2;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_hi_oct_5) {
  char format[] = "%3hi %3hi %3hi";
  char str[] = "013 +0137 -08";
  unsigned short d1, d2;
  unsigned short q1, q2;
  unsigned short z1, z2;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_hi_oct_6) {
  char format[] = "%30hi %24hi %21hi";
  char str[] = "013 +0137 -08";
  unsigned short d1, d2;
  unsigned short q1, q2;
  unsigned short z1, z2;
  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_hi_oct_7) {
  char format[] = "%hi %hi %hi %hi";
  char str[] = "037777777777 +040000000000 -040000000000 -040000000001";
  unsigned short d1, d2;
  unsigned short q1, q2;
  unsigned short z1, z2;
  unsigned short w1, w2;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1, &w1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2, &w2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
  ck_assert_uint_eq(w1, w2);
}
END_TEST

START_TEST(sscanf_spec_hi_oct_8) {
  char format[] = "%hi %hi %hi %hi";
  char str[] =
      "01777777777777777777777 +02000000000000000000000 "
      "-02000000000000000000000 -02000000000000000000001";
  unsigned short d1, d2;
  unsigned short q1, q2;
  unsigned short z1, z2;
  unsigned short w1, w2;
  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1, &w1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2, &w2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
  ck_assert_uint_eq(w1, w2);
}
END_TEST

START_TEST(sscanf_spec_hi_hex_1) {
  char format[] = "%hi%hi%hi";
  char str[] = "0x123 +0X198 -0x87";
  unsigned short d1, d2;
  unsigned short q1, q2;
  unsigned short z1, z2;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_hi_hex_2) {
  char format[] = "%hi %hi %hi";
  char str[] = "0X123 +0x198 -0X87";
  unsigned short d1, d2;
  unsigned short q1, q2;
  unsigned short z1, z2;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_hi_hex_3) {
  char format[] = "%hi %hi %hi";
  char str[] = "0X13 +0x137 -0x8";
  unsigned short d1 = 0, d2 = 0;
  unsigned short q1 = 0, q2 = 0;
  unsigned short z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_hi_hex_5) {
  char format[] = "%hi %hi %hi";
  char str[] = "0x13 +0x137 -0x8";
  unsigned short d1, d2;
  unsigned short q1, q2;
  unsigned short z1, z2;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_hi_hex_6) {
  char format[] = "%30hi %24hi %21hi";
  char str[] = "0x13 +0x1a -0x8";
  unsigned short d1, d2;
  unsigned short q1, q2;
  unsigned short z1, z2;
  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_hi_hex_7) {
  char format[] = "%hi %hi %hi %hi";
  char str[] = "0xffffffff +0xffffffeab -0xFfFfffFf -0x39cdb3aa";
  unsigned short d1, d2;
  unsigned short q1, q2;
  unsigned short z1, z2;
  unsigned short w1, w2;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1, &w1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2, &w2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
  ck_assert_uint_eq(w1, w2);
}
END_TEST

START_TEST(sscanf_spec_hi_hex_8) {
  char format[] = "%hi %hi %hi %hi";
  char str[] =
      "0xFFFFFFFFFFFFFFFF 0x8000000000000000 -0xFFFFFFFFFFFFFFFF "
      "-0x348923848239742389328";
  unsigned short d1, d2;
  unsigned short q1, q2;
  unsigned short z1, z2;
  unsigned short w1, w2;
  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1, &w1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2, &w2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
  ck_assert_uint_eq(w1, w2);
}
END_TEST

START_TEST(sscanf_spec_i_dec_1) {
  char format[] = "%i%i%i";
  char str[] = "123 +198 -87";
  unsigned int d1, d2;
  unsigned int q1, q2;
  unsigned int z1, z2;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_i_dec_2) {
  char format[] = "%i %i %i";
  char str[] = "123 +198 -87";
  unsigned int d1, d2;
  unsigned int q1, q2;
  unsigned int z1, z2;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_i_dec_3) {
  char format[] = "%1i %1i %1i";
  char str[] = "13 +137 -8";
  unsigned int d1, d2;
  unsigned int q1, q2;
  unsigned int z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_i_dec_4) {
  char format[] = "%2i %2i %2i";
  char str[] = "13 +137 -8";
  unsigned int d1, d2;
  unsigned int q1, q2;
  unsigned int z1, z2;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_i_dec_5) {
  char format[] = "%3i %3i %3i";
  char str[] = "13 +137 -8";
  unsigned int d1, d2;
  unsigned int q1, q2;
  unsigned int z1, z2;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_i_dec_6) {
  char format[] = "%30i %24i %21i";
  char str[] = "13 +137 -8";
  unsigned int d1, d2;
  unsigned int q1, q2;
  unsigned int z1, z2;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_i_dec_7) {
  char format[] = "%i %i %i %i";
  char str[] = "2147483647 +2147483648 -2147483648 -2147483649";
  unsigned int d1, d2;
  unsigned int q1, q2;
  unsigned int z1, z2;
  unsigned int w1, w2;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1, &w1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2, &w2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
  ck_assert_uint_eq(w1, w2);
}
END_TEST

START_TEST(sscanf_spec_i_dec_8) {
  char format[] = "%i %i %i %i";
  char str[] =
      "9223372036854775807 +9223372036854775808 -9223372036854775808 "
      "-9223372036854775809";
  unsigned int d1, d2;
  unsigned int q1, q2;
  unsigned int z1, z2;
  unsigned int w1, w2;
  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1, &w1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2, &w2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
  ck_assert_uint_eq(w1, w2);
}
END_TEST

START_TEST(sscanf_spec_i_oct_1) {
  char format[] = "%i%i%i";
  char str[] = "0123 +0198 -087";
  unsigned int d1, d2;
  unsigned int q1, q2;
  unsigned int z1, z2;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_i_oct_2) {
  char format[] = "%i %i %i";
  char str[] = "0123 +0198 -087";
  unsigned int d1, d2;
  unsigned int q1, q2;
  unsigned int z1, z2;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_i_oct_3) {
  char format[] = "%1i %1i %1i";
  char str[] = "013 +0137 -08";
  unsigned int d1, d2;
  unsigned int q1, q2;
  unsigned int z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_i_oct_4) {
  char format[] = "%2i %2i %2i";
  char str[] = "013 +0137 -08";
  unsigned int d1, d2;
  unsigned int q1, q2;
  unsigned int z1, z2;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_i_oct_5) {
  char format[] = "%3i %3i %3i";
  char str[] = "013 +0137 -08";
  unsigned int d1, d2;
  unsigned int q1, q2;
  unsigned int z1, z2;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_i_oct_6) {
  char format[] = "%30i %24i %21i";
  char str[] = "013 +0137 -08";
  unsigned int d1, d2;
  unsigned int q1, q2;
  unsigned int z1, z2;
  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_i_oct_7) {
  char format[] = "%i %i %i %i";
  char str[] = "037777777777 +040000000000 -040000000000 -040000000001";
  unsigned int d1, d2;
  unsigned int q1, q2;
  unsigned int z1, z2;
  unsigned int w1, w2;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1, &w1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2, &w2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
  ck_assert_uint_eq(w1, w2);
}
END_TEST

START_TEST(sscanf_spec_i_oct_8) {
  char format[] = "%i %i %i %i";
  char str[] =
      "01777777777777777777777 +02000000000000000000000 "
      "-02000000000000000000000 -02000000000000000000001";
  unsigned int d1, d2;
  unsigned int q1, q2;
  unsigned int z1, z2;
  unsigned int w1, w2;
  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1, &w1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2, &w2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
  ck_assert_uint_eq(w1, w2);
}
END_TEST

START_TEST(sscanf_spec_i_hex_1) {
  char format[] = "%i%i%i";
  char str[] = "0x123 +0X198 -0x87";
  unsigned int d1, d2;
  unsigned int q1, q2;
  unsigned int z1, z2;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_i_hex_2) {
  char format[] = "%i %i %i";
  char str[] = "0X123 +0x198 -0X87";
  unsigned int d1, d2;
  unsigned int q1, q2;
  unsigned int z1, z2;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_i_hex_3) {
  char format[] = "%i %i %i";
  char str[] = "0X13 +0x137 -0x8";
  int d1 = 0, d2 = 0;
  int q1 = 0, q2 = 0;
  int z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(q1, q2);
  ck_assert_int_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_i_hex_5) {
  char format[] = "%i %i %i";
  char str[] = "0x13 +0x137 -0x8";
  unsigned int d1, d2;
  unsigned int q1, q2;
  unsigned int z1, z2;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_i_hex_6) {
  char format[] = "%30i %24i %21i";
  char str[] = "0x13 +0x1a -0x8";
  unsigned int d1, d2;
  unsigned int q1, q2;
  unsigned int z1, z2;
  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_i_hex_7) {
  char format[] = "%i %i %i %i";
  char str[] = "0xffffffff +0xffffffeab -0xFfFfffFf -0x39cdb3aa";
  unsigned int d1, d2;
  unsigned int q1, q2;
  unsigned int z1, z2;
  unsigned int w1, w2;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1, &w1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2, &w2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
  ck_assert_uint_eq(w1, w2);
}
END_TEST

START_TEST(sscanf_spec_i_hex_8) {
  char format[] = "%i %i %i %i";
  char str[] =
      "0xFFFFFFFFFFFFFFFF 0x8000000000000000 -0xFFFFFFFFFFFFFFFF "
      "-0x348923848239742389328";
  unsigned int d1, d2;
  unsigned int q1, q2;
  unsigned int z1, z2;
  unsigned int w1, w2;
  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1, &w1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2, &w2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
  ck_assert_uint_eq(w1, w2);
}
END_TEST

START_TEST(sscanf_spec_li_dec_1) {
  char format[] = "%li%li%li";
  char str[] = "123 +198 -87";
  unsigned long int d1, d2;
  unsigned long int q1, q2;
  unsigned long int z1, z2;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_li_dec_2) {
  char format[] = "%li %li %li";
  char str[] = "123 +198 -87";
  unsigned long int d1, d2;
  unsigned long int q1, q2;
  unsigned long int z1, z2;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_li_dec_3) {
  char format[] = "%1li %1li %1li";
  char str[] = "13 +137 -8";
  unsigned long int d1, d2;
  unsigned long int q1, q2;
  unsigned long int z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_li_dec_4) {
  char format[] = "%2li %2li %2li";
  char str[] = "13 +137 -8";
  unsigned long int d1, d2;
  unsigned long int q1, q2;
  unsigned long int z1, z2;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_li_dec_5) {
  char format[] = "%3li %3li %3li";
  char str[] = "13 +137 -8";
  unsigned long int d1, d2;
  unsigned long int q1, q2;
  unsigned long int z1, z2;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_li_dec_6) {
  char format[] = "%30li %24li %21li";
  char str[] = "13 +137 -8";
  unsigned long int d1, d2;
  unsigned long int q1, q2;
  unsigned long int z1, z2;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_li_dec_7) {
  char format[] = "%li %li %li %li";
  char str[] = "2147483647 +2147483648 -2147483648 -2147483649";
  unsigned long int d1, d2;
  unsigned long int q1, q2;
  unsigned long int z1, z2;
  unsigned long int w1, w2;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1, &w1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2, &w2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
  ck_assert_uint_eq(w1, w2);
}
END_TEST

START_TEST(sscanf_spec_li_dec_8) {
  char format[] = "%li %li %li %li";
  char str[] =
      "9223372036854775807 +9223372036854775808 -9223372036854775808 "
      "-9223372036854775809";
  unsigned long int d1, d2;
  unsigned long int q1, q2;
  unsigned long int z1, z2;
  unsigned long int w1, w2;
  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1, &w1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2, &w2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
  ck_assert_uint_eq(w1, w2);
}
END_TEST

START_TEST(sscanf_spec_li_oct_1) {
  char format[] = "%li%li%li";
  char str[] = "0123 +0198 -087";
  unsigned long int d1, d2;
  unsigned long int q1, q2;
  unsigned long int z1, z2;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_li_oct_2) {
  char format[] = "%li %li %li";
  char str[] = "0123 +0198 -087";
  unsigned long int d1, d2;
  unsigned long int q1, q2;
  unsigned long int z1, z2;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_li_oct_3) {
  char format[] = "%1li %1li %1li";
  char str[] = "013 +0137 -08";
  unsigned long int d1, d2;
  unsigned long int q1, q2;
  unsigned long int z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_li_oct_4) {
  char format[] = "%2li %2li %2li";
  char str[] = "013 +0137 -08";
  unsigned long int d1, d2;
  unsigned long int q1, q2;
  unsigned long int z1, z2;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_li_oct_5) {
  char format[] = "%3li %3li %3li";
  char str[] = "013 +0137 -08";
  unsigned long int d1, d2;
  unsigned long int q1, q2;
  unsigned long int z1, z2;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_li_oct_6) {
  char format[] = "%30li %24li %21li";
  char str[] = "013 +0137 -08";
  unsigned long int d1, d2;
  unsigned long int q1, q2;
  unsigned long int z1, z2;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_li_oct_7) {
  char format[] = "%li %li %li %li";
  char str[] = "037777777777 +040000000000 -040000000000 -040000000001";
  unsigned long int d1, d2;
  unsigned long int q1, q2;
  unsigned long int z1, z2;
  unsigned long int w1, w2;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1, &w1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2, &w2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
  ck_assert_uint_eq(w1, w2);
}
END_TEST

START_TEST(sscanf_spec_li_oct_8) {
  char format[] = "%li %li %li %li";
  char str[] =
      "01777777777777777777777 +02000000000000000000000 "
      "-02000000000000000000000 -02000000000000000000001";
  unsigned long int d1, d2;
  unsigned long int q1, q2;
  unsigned long int z1, z2;
  unsigned long int w1, w2;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1, &w1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2, &w2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
  ck_assert_uint_eq(w1, w2);
}
END_TEST

START_TEST(sscanf_spec_li_hex_1) {
  char format[] = "%li%li%li";
  char str[] = "0x123 +0X198 -0x87";
  unsigned long int d1, d2;
  unsigned long int q1, q2;
  unsigned long int z1, z2;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_li_hex_2) {
  char format[] = "%li %li %li";
  char str[] = "0X123 +0x198 -0X87";
  unsigned long int d1, d2;
  unsigned long int q1, q2;
  unsigned long int z1, z2;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_li_hex_3) {
  char format[] = "%li %li %li";
  char str[] = "0X13 +0x137 -0x8";
  unsigned long int d1 = 0, d2 = 0;
  unsigned long int q1 = 0, q2 = 0;
  unsigned long int z1 = 0, z2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_li_hex_5) {
  char format[] = "%li %li %li";
  char str[] = "0x13 +0x137 -0x8";
  unsigned long int d1, d2;
  unsigned long int q1, q2;
  unsigned long int z1, z2;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_li_hex_6) {
  char format[] = "%30li %24li %21li";
  char str[] = "0x13 +0x1a -0x8";
  unsigned long int d1, d2;
  unsigned long int q1, q2;
  unsigned long int z1, z2;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_spec_li_hex_7) {
  char format[] = "%li %li %li %li";
  char str[] = "0xffffffff +0xffffffeab -0xFfFfffFf -0x39cdb3aa";
  unsigned long int d1, d2;
  unsigned long int q1, q2;
  unsigned long int z1, z2;
  unsigned long int w1, w2;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1, &w1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2, &w2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
  ck_assert_uint_eq(w1, w2);
}
END_TEST

START_TEST(sscanf_spec_li_hex_8) {
  char format[] = "%li %li %li %li";
  char str[] =
      "0xFFFFFFFFFFFFFFFF 0x8000000000000000 0xFFFFFFFFFFFFFFFF "
      "-0x348923848239742389328";
  unsigned long int d1, d2;
  unsigned long int q1, q2;
  unsigned long int z1, z2;
  unsigned long int w1, w2;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1, &w1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2, &w2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
  ck_assert_uint_eq(w1, w2);
}
END_TEST

START_TEST(test_sscanf_int) {
  int x, y;
  int result = s21_sscanf("123 456", "%d %d", &x, &y);
  ck_assert_int_eq(result, 2);
  ck_assert_int_eq(x, 123);
  ck_assert_int_eq(y, 456);
}
END_TEST

START_TEST(test_sscanf_float) {
  float x, y;
  int result = s21_sscanf("3.14 -1.23", "%f %f", &x, &y);
  ck_assert_int_eq(result, 2);
  ck_assert_float_eq_tol(x, 3.14, 0.01);
  ck_assert_float_eq_tol(y, -1.23, 0.01);
}
END_TEST

START_TEST(test_sscanf_string) {
  char x[20], y[20];
  int result = s21_sscanf("hello world", "%s %s", x, y);
  ck_assert_int_eq(result, 2);
  ck_assert_str_eq(x, "hello");
  ck_assert_str_eq(y, "world");
}
END_TEST

START_TEST(test_sscanf_skip_whitespaces) {
  char x[20];
  int result = s21_sscanf(" abc ", "%s", x);
  ck_assert_int_eq(result, 1);
  ck_assert_str_eq(x, "abc");
}
END_TEST

START_TEST(test_sscanf_mixed_type) {
  int x;
  float y;
  char z[20];
  int result = s21_sscanf("123 4.56 hello", "%d %f %s", &x, &y, z);
  ck_assert_int_eq(result, 3);
  ck_assert_int_eq(x, 123);
  ck_assert_float_eq_tol(y, 4.56, 0.01);
  ck_assert_str_eq(z, "hello");
}
END_TEST

START_TEST(test_sscanf_width_specifier) {
  char x[20], y[20];
  int result = s21_sscanf("hello world", "%5s %5s", x, y);
  ck_assert_int_eq(result, 2);
  ck_assert_str_eq(x, "hello");
  ck_assert_str_eq(y, "world");
}
END_TEST

START_TEST(test_sscanf_n_assignment) {
  int x, y;
  int result = s21_sscanf("123 456", "%d%n %d", &x, &y, &y);
  ck_assert_int_eq(result, 2);
  ck_assert_int_eq(x, 123);
  ck_assert_int_eq(y, 456);
}
END_TEST

START_TEST(s21_sscanf_test_17_o_option) {
  uint32_t a1, a2;
  const char str[] = "          \n             \n     5";
  const char fstr[] = "%o";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}

END_TEST

START_TEST(s21_sscanf_test_18_o_option) {
  uint16_t a1, a2;
  const char str[] = "12";
  const char fstr[] = "%ho";
  uint16_t res1 = s21_sscanf(str, fstr, &a1);
  uint16_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(s21_sscanf_test_19_u_option) {
  unsigned short a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  const char str[] = "-1337 +21 --5008 3000";
  const char fstr[] = "%hu %hu %hu %hu";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(test_sscanf_spec_i_int1) {
  long long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  const char str[] = "100 500 -600 +700";
  const char fstr[] = "%lli %lli %lli %lli";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(test_sscanf_spec_i_int2) {
  long long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  const char str[] = "100500-600+700 123";
  const char fstr[] = "%lli %lld %lld %lli";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(test_sscanf_spec_i_int3) {
  long long a1 = 0, a2 = 0, c1 = 0, c2 = 0;
  char b1 = 0, b2 = 0, d1 = 0, d2 = 0;
  const char str[] = "100500-600+700+400";
  const char fstr[] = "%lli%c%lli%c";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(test_sscanf_oct) {
  long long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  const char str[] = "  055555 0f 0f 0f5555555 0ddd   4    3    1 ";
  const char fstr[] = "%llo %lld %lld %lli";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(test_sscanf_hex) {
  long long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  const char str[] = " 63DD 0xf 0xf 0xf5555555 ddd   4    3    1 ";
  const char fstr[] = "%lli %lld %lld %lli";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(test_1_sscanf) {
  char s[20] = "03polina";
  int g = 0;
  char first[10] = {0};
  char format[5] = "%d %s";
  s21_sscanf(s, format, &g, first);
  char a[20] = "03polina";
  int m = 0;
  char second[10] = {0};
  char format2[5] = "%d %s";
  sscanf(a, format2, &m, second);
  ck_assert_int_eq(g, m);
  ck_assert_str_eq(first, second);
}
END_TEST

START_TEST(test_2_sscanf) {
  char s[20] = "-84543";
  int g = 0;
  char format[10] = "-84543";
  s21_sscanf(s, format, &g);
  char a[20] = "-84543";
  int m = 0;
  char format2[10] = "-84543";
  sscanf(a, format2, &m);
  ck_assert_int_eq(g, m);
}
END_TEST
START_TEST(test_3_sscanf) {
  char s[20] = "   03 polina";
  char g = 0;
  char first[10] = {0};
  char format[5] = "%s %s";
  s21_sscanf(s, format, &g, first);
  char a[20] = "   03 polina";
  char m = 0;
  char second[10] = {0};
  char format2[5] = "%s %s";
  sscanf(a, format2, &m, second);
  ck_assert_int_eq(g, m);
  ck_assert_str_eq(first, second);
}
END_TEST
START_TEST(test_4_sscanf) {
  char s[20] = "   03polina";
  int g = 0;
  char first[10] = {0};
  char format[5] = "%i %s";
  s21_sscanf(s, format, &g, first);
  char a[20] = "   03polina";
  int m = 0;
  char second[10] = {0};
  char format2[5] = "%i %s";
  sscanf(a, format2, &m, second);
  ck_assert_int_eq(g, m);
  ck_assert_str_eq(first, second);
}
END_TEST
START_TEST(test_5_sscanf) {
  char s[] = "0-3           polina";
  int g = 0;
  char first[10] = {0};
  char format[] = "%i %s";
  s21_sscanf(s, format, &g, first);
  char a[] = "0-3           polina";
  int m = 0;
  char second[10] = {0};
  char format2[] = "%i %s";
  sscanf(a, format2, &m, second);
  ck_assert_int_eq(g, m);
  ck_assert_str_eq(first, second);
}
END_TEST
START_TEST(test_6_sscanf) {
  char s[20] = "0-3polina";
  int g = 0;
  char first[10] = {0};
  char format[10] = "%i %s";
  s21_sscanf(s, format, &g, first);
  char a[20] = "0-3polina";
  int m = 0;
  char second[10] = {0};
  char format2[10] = "%i %s";
  sscanf(a, format2, &m, second);
  ck_assert_int_eq(g, m);
  ck_assert_str_eq(first, second);
}
END_TEST
START_TEST(test_7_sscanf) {
  char s[20] = "0303polina";
  int g = 0;
  char first[10] = {0};
  char format[5] = "%o %s";
  s21_sscanf(s, format, &g, first);
  char a[20] = "0303polina";
  int m = 0;
  char second[10] = {0};
  char format2[5] = "%o %s";
  sscanf(a, format2, &m, second);
  ck_assert_int_eq(g, m);
  ck_assert_str_eq(first, second);
}
END_TEST
START_TEST(test_8_sscanf) {
  char s[20] = "0a-3polina";
  int g = 0;
  char first[10] = {0};
  char format[5] = "%o %s";
  s21_sscanf(s, format, &g, first);
  char a[20] = "0a-3polina";
  int m = 0;
  char second[10] = {0};
  char format2[5] = "%o %s";
  sscanf(a, format2, &m, second);
  ck_assert_int_eq(g, m);
  ck_assert_str_eq(first, second);
}
END_TEST
START_TEST(test_9_sscanf) {
  char s[20] = "0a-3polina";
  int g = 0;
  char first[10] = {0};
  char format[10] = "%i %s";
  s21_sscanf(s, format, &g, first);
  char a[20] = "0a-3polina";
  int m = 0;
  char second[10] = {0};
  char format2[10] = "%i %s";
  sscanf(a, format2, &m, second);
  ck_assert_int_eq(g, m);
  ck_assert_str_eq(first, second);
}
END_TEST
START_TEST(test_10_sscanf) {
  char s[32] = "   &^ 0     a-3polina";
  int g = 0;
  char first[10] = {0};
  char format[10] = "%d %s";
  s21_sscanf(s, format, &g, first);
  char a[32] = "   &^ 0     a-3polina";
  int m = 0;
  char second[10] = {0};
  char format2[10] = "%d %s";
  sscanf(a, format2, &m, second);
  ck_assert_int_eq(g, m);
  ck_assert_str_eq(first, second);
}
END_TEST
START_TEST(test_11_sscanf) {
  char s[20] = "-3267.5e3lalaley";
  int g = 0;
  char first[10] = {0};
  char format[10] = "%e %s";
  s21_sscanf(s, format, &g, first);
  char a[20] = "-3267.5e3lalaley";
  int m = 0;
  char second[10] = {0};
  char format2[10] = "%e %s";
  sscanf(a, format2, &m, second);
  ck_assert_int_eq(g, m);
  ck_assert_str_eq(first, second);
}
END_TEST
START_TEST(test_12_sscanf) {
  char s[20] = "-3267.5e3";
  int g = 0;
  char first[10] = {0};
  char format[10] = "%e";
  s21_sscanf(s, format, &g);
  char a[20] = "-3267.5e3";
  int m = 0;
  char second[10] = {0};
  char format2[10] = "%e";
  sscanf(a, format2, &m);
  ck_assert_int_eq(g, m);
  ck_assert_str_eq(first, second);
}
END_TEST
START_TEST(test_13_sscanf) {
  char s[20] = "0a-3polina";
  int g = 0;
  char first[10] = {0};
  char format[10] = "%o %s";
  s21_sscanf(s, format, &g, first);
  char a[20] = "0a-3polina";
  int m = 0;
  char second[10] = {0};
  char format2[10] = "%o %s";
  sscanf(a, format2, &m, second);
  ck_assert_int_eq(g, m);
  ck_assert_str_eq(first, second);
}
END_TEST
START_TEST(test_14_sscanf) {
  char s[20] = "0a-3polina";
  int g = 0;
  char first[10] = {0};
  char format[10] = "  %i %s";
  s21_sscanf(s, format, &g, first);
  char a[20] = "0a-3polina";
  int m = 0;
  char second[10] = {0};
  char format2[10] = "  %i %s";
  sscanf(a, format2, &m, second);
  ck_assert_int_eq(g, m);
  ck_assert_str_eq(first, second);
}
END_TEST
START_TEST(test_15_sscanf) {
  char s[20] = "-0ABDf3";
  int g = 0;
  char first[10] = {0};
  char format[10] = "%i";
  s21_sscanf(s, format, &g, first);
  char a[20] = "-0ABDf3";
  int m = 0;
  char second[10] = {0};
  char format2[10] = "%i";
  sscanf(a, format2, &m, second);
  ck_assert_int_eq(g, m);
  ck_assert_str_eq(first, second);
}
END_TEST
START_TEST(test_16_sscanf) {
  char s[20] = "-0ABDf3";
  int g = 0;
  char first[10] = {0};
  char format[10] = "%li";
  s21_sscanf(s, format, &g, first);
  char a[20] = "-0ABDf3";
  int m = 0;
  char second[10] = {0};
  char format2[10] = "%+li";
  sscanf(a, format2, &m, second);
  ck_assert_int_eq(g, m);
  ck_assert_str_eq(first, second);
}
END_TEST
START_TEST(test_17_sscanf) {
  char s[20] = "-0AB4 Df3";
  int g = 0;
  char first[10] = {0};
  char format[10] = "%i %s";
  s21_sscanf(s, format, &g, first);
  char a[20] = "-0AB4 Df3";
  int m = 0;
  char second[10] = {0};
  char format2[10] = "%i %s";
  sscanf(a, format2, &m, second);
  ck_assert_int_eq(g, m);
  ck_assert_str_eq(first, second);
}
END_TEST
START_TEST(test_18_sscanf) {
  char s[20] = "-0ABDf3";
  int g = 0;
  char first[10] = {0};
  char format[10] = "+i";
  s21_sscanf(s, format, &g, first);
  char a[20] = "-0ABDf3";
  int m = 0;
  char second[10] = {0};
  char format2[10] = "+i";
  sscanf(a, format2, &m, second);
  ck_assert_int_eq(g, m);
  ck_assert_str_eq(first, second);
}
END_TEST
START_TEST(test_19_sscanf) {
  char s[20] = "-0ABDf3";
  int g = 0;
  char first[10] = {0};
  char format[10] = "";
  s21_sscanf(s, format, &g, first);
  char a[20] = "-0ABDf3";
  int m = 0;
  char second[10] = {0};
  char format2[10] = "";
  sscanf(a, format2, &m, second);
  ck_assert_int_eq(g, m);
  ck_assert_str_eq(first, second);
}
END_TEST
START_TEST(test_20_sscanf) {
  char s[20] = "-%$^@!$%#";
  int g = 0;
  char first[10] = {0};
  char format[10] = "%c";
  s21_sscanf(s, format, &g, first);
  char a[20] = "-%$^@!$%#";
  int m = 0;
  char second[10] = {0};
  char format2[10] = "%c";
  sscanf(a, format2, &m, second);
  ck_assert_int_eq(g, m);
  ck_assert_str_eq(first, second);
}
END_TEST
START_TEST(test_21_sscanf) {
  char s[20] = "-%$^@!$%#";
  char g = 0;
  char first[10] = {0};
  char format[10] = "%c";
  s21_sscanf(s, format, &g, first);
  char a[20] = "-%$^@!$%#";
  char m = 0;
  char second[10] = {0};
  char format2[10] = "%c";
  sscanf(a, format2, &m, second);
  ck_assert_int_eq(g, m);
  ck_assert_str_eq(first, second);
}
END_TEST
START_TEST(test_22_sscanf) {
  char s[20] = "-0afb231.46";
  int g = 0;
  char first[10] = {0};
  char format[10] = "%i %3f";
  s21_sscanf(s, format, &g, first);
  char a[20] = "-0afb231.46";
  int m = 0;
  char second[10] = {0};
  char format2[10] = "%i %.3f";
  sscanf(a, format2, &m, second);
  ck_assert_int_eq(g, m);
  ck_assert_str_eq(first, second);
}
END_TEST
START_TEST(test_23_sscanf) {
  char s[20] = "-0afb231.46";
  int g = 0;
  char first[10] = {0};
  char format[10] = "%i%3f";
  s21_sscanf(s, format, &g, first);
  char a[20] = "-0afb231.46";
  int m = 0;
  char second[10] = {0};
  char format2[10] = "%i%.3f";
  sscanf(a, format2, &m, second);
  ck_assert_int_eq(g, m);
  ck_assert_str_eq(first, second);
}
END_TEST
START_TEST(test_24_sscanf) {
  char s[20] = "-056371.46";
  int g = 0;
  char first[10] = {0};
  char format[10] = "%i %e";
  s21_sscanf(s, format, &g, first);
  char a[20] = "-056371.46";
  int m = 0;
  char second[10] = {0};
  char format2[10] = "%i %e";
  sscanf(a, format2, &m, second);
  ck_assert_int_eq(g, m);
  ck_assert_str_eq(first, second);
}
END_TEST
START_TEST(test_25_sscanf) {
  char s[20] = "-056371.46lalala";
  int g = 0;
  char first[10] = {0};
  char third[10] = {0};
  char format[10] = "%i %e %s";
  s21_sscanf(s, format, &g, first, third);
  char a[20] = "-056371.46lalala";
  int m = 0;
  char second[10] = {0};
  char third2[10] = {0};
  char format2[10] = "%i %e %s";
  sscanf(a, format2, &m, second, third2);
  ck_assert_int_eq(g, m);
  ck_assert_str_eq(first, second);
  ck_assert_str_eq(third, third2);
}
END_TEST
START_TEST(test_26_sscanf) {
  char s[20] = "-563d71lol";
  int g = 0;
  char first[10] = {0};
  char format[10] = "%x %s";
  s21_sscanf(s, format, &g, first);
  char a[20] = "-563d71lol";
  int m = 0;
  char second[10] = {0};
  char format2[10] = "%x %s";
  sscanf(a, format2, &m, second);
  ck_assert_int_eq(g, m);
  ck_assert_str_eq(first, second);
}
END_TEST
START_TEST(test_27_sscanf) {
  char s[20] = "-5AB71lol";
  int g = 0;
  int g1 = 0;
  char format[10] = "%X %s";
  s21_sscanf(s, format, &g, &g1);
  char a[20] = "-5AB71lol";
  int m = 0;
  int m1 = 0;
  char format2[10] = "%X %s";
  sscanf(a, format2, &m, &m1);
  ck_assert_int_eq(g, m);
  ck_assert_int_eq(g1, m1);
}
END_TEST
START_TEST(test_28_sscanf) {
  char s[20] = "-5AB71lol";
  int g = 0;
  char first[10] = {0};
  char format[10] = "%X %hd";
  s21_sscanf(s, format, &g, first);
  char a[20] = "-5AB71lol";
  int m = 0;
  char second[10] = {0};
  char format2[10] = "%X %hd";
  sscanf(a, format2, &m, second);
  ck_assert_int_eq(g, m);
  ck_assert_str_eq(first, second);
}
END_TEST
START_TEST(test_29_sscanf) {
  char s[20] = "-5AB71 56.4";
  int g = 0;
  int g1 = 0;
  char format[10] = "%4X %3f";
  s21_sscanf(s, format, &g, &g1);
  char a[20] = "-5AB71 56.4";
  int m = 0;
  int m1 = 0;
  char format2[10] = "%4X %3f";
  sscanf(a, format2, &m, &m1);
  ck_assert_int_eq(g, m);
  ck_assert_int_eq(g1, m1);
}
END_TEST
START_TEST(test_30_sscanf) {
  char s[20] = "-5AB71 56.4";
  int g = 0;
  int g1 = 0;
  char format[10] = "%33f";
  s21_sscanf(s, format, &g, &g1);
  char a[20] = "-5AB71 56.4";
  int m = 0;
  int m1 = 0;
  char format2[10] = "%33f";
  sscanf(a, format2, &m, &m1);
  ck_assert_int_eq(g, m);
  ck_assert_int_eq(g1, m1);
}
END_TEST
START_TEST(test_31_sscanf) {
  char s[20] = "-5AB71 56.4";
  int g = 0;
  int g1 = 0;
  char format[10] = "%X %3f";
  s21_sscanf(s, format, &g, &g1);
  char a[20] = "-5AB71 56.4";
  int m = 0;
  int m1 = 0;
  char format2[10] = "%X %3f";
  sscanf(a, format2, &m, &m1);
  ck_assert_int_eq(g, m);
  ck_assert_int_eq(g1, m1);
}
END_TEST

START_TEST(test_33_sscanf) {
  char s[20] = "-5AB71 56.4";
  int g = 0;
  int g1 = 0;
  char format[10] = "%*X %*f";
  s21_sscanf(s, format, &g, &g1);
  char a[20] = "-5AB71 56.4";
  int m = 0;
  int m1 = 0;
  char format2[10] = "%*X %*f";
  sscanf(a, format2, &m, &m1);
  ck_assert_int_eq(g, m);
  ck_assert_int_eq(g1, m1);
}
END_TEST
START_TEST(test_34_sscanf) {
  char s[20] = "-84543";
  int g = 0;
  char format[10] = "%i";
  s21_sscanf(s, format, &g);
  char a[20] = "-84543";
  int m = 0;
  char format2[10] = "%i";
  sscanf(a, format2, &m);
  ck_assert_int_eq(g, m);
}
END_TEST
START_TEST(test_35_sscanf) {
  char s[20] = "0x84543";
  int g = 0;
  char format[10] = "%u";
  s21_sscanf(s, format, &g);
  char a[20] = "0x84543";
  int m = 0;
  char format2[10] = "%u";
  sscanf(a, format2, &m);
  ck_assert_int_eq(g, m);
}
END_TEST

START_TEST(sscanf_spec_d_24) {
  char format[] = "%d";
  char str[] = "9223372036854775808";
  int d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_spec_d_25) {
  char format[] = "%d";
  char str[] = "922337203685477582309";
  int d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

// START_TEST(C_SPECIFIER) {
//   char format[] = "%c";
//   char string[] = "\n";
//   char a1 = 0, a2 = 0, a3 = 0, b1 = 0, b2 = 0, b3 = 0;
//   int res1 = s21_sscanf(string, format, &a1);
//   int res2 = sscanf(string, format, &b1);
//   ck_assert_int_eq(a1, b1);
//   ck_assert_int_eq(res1, res2);

//   a1 = 0, a2 = 0, a3 = 0, b1 = 0, b2 = 0, b3 = 0;
//  string[] = "      1\0";
//   res1 = s21_sscanf(string, format, &a1);
//   res2 = sscanf(string, format, &b1);
//   ck_assert_int_eq(a1, b1);
//   ck_assert_int_eq(res1, res2);

//   a1 = 0, a2 = 0, a3 = 0, b1 = 0, b2 = 0, b3 = 0;
//   string[] = "\0b";
//   res1 = s21_sscanf(string, format, &a1);
//   res2 = sscanf(string, format, &b1);
//   ck_assert_int_eq(a1, b1);
//   ck_assert_int_eq(res1, res2);

//   a1 = 0, a2 = 0, a3 = 0, b1 = 0, b2 = 0, b3 = 0;
//   format = "%c %c %c";
//   string[] = "1   3";
//   res1 = s21_sscanf(string, format, &a1, &a2, &a3);
//   res2 = sscanf(string, format, &b1, &b2, &b3);
//   ck_assert_int_eq(a1, b1);
//   ck_assert_int_eq(a2, b2);
//   ck_assert_int_eq(a3, b3);
//   ck_assert_int_eq(res1, res2);

//   a1 = 0, a2 = 0, a3 = 0, b1 = 0, b2 = 0, b3 = 0;
//   string[] = "  ";
//   res1 = s21_sscanf(string, format, &a1, &a2, &a3);
//   res2 = sscanf(string, format, &b1, &b2, &b3);
//   ck_assert_int_eq(a1, b1);
//   ck_assert_int_eq(a2, b2);
//   ck_assert_int_eq(a3, b3);
//   ck_assert_int_eq(res1, res2);

//   a1 = 0, a2 = 0, a3 = 0, b1 = 0, b2 = 0, b3 = 0;
//   string[] = "\\n\t";
//   res1 = s21_sscanf(string, format, &a1, &a2, &a3);
//   res2 = sscanf(string, format, &b1, &b2, &b3);
//   ck_assert_int_eq(a1, b1);
//   ck_assert_int_eq(a2, b2);
//   ck_assert_int_eq(a3, b3);
//   ck_assert_int_eq(res1, res2);

//   a1 = 0, a2 = 0, a3 = 0, b1 = 0, b2 = 0, b3 = 0;
// string[] = "";
//   res1 = s21_sscanf(string, format, &a1, &a2, &a3);
//   res2 = sscanf(string, format, &b1, &b2, &b3);
//   ck_assert_int_eq(a1, b1);
//   ck_assert_int_eq(a2, b2);
//   ck_assert_int_eq(a3, b3);
//   ck_assert_int_eq(res1, res2);

//   a1 = 0, a2 = 0, a3 = 0, b1 = 0, b2 = 0, b3 = 0;
//  string[] = " sa";
//   res1 = s21_sscanf(string, format, &a1, &a2, &a3);
//   res2 = sscanf(string, format, &b1, &b2, &b3);
//   ck_assert_int_eq(a1, b1);
//   ck_assert_int_eq(a2, b2);
//   ck_assert_int_eq(a3, b3);
//   ck_assert_int_eq(res1, res2);

//   a1 = 0, a2 = 0, a3 = 0, b1 = 0, b2 = 0, b3 = 0;
// string[] = "     \n     1     2\t3";
//   res1 = s21_sscanf(string, format, &a1, &a2, &a3);
//   res2 = sscanf(string, format, &b1, &b2, &b3);
//   ck_assert_int_eq(a1, b1);
//   ck_assert_int_eq(a2, b2);
//   ck_assert_int_eq(a3, b3);
//   ck_assert_int_eq(res1, res2);

//   a1 = 0, a2 = 0, a3 = 0, b1 = 0, b2 = 0, b3 = 0;
//   format[] = "%c%c %c";
// string[] = "     \n     1     2\t3";
//   res1 = s21_sscanf(string, format, &a1, &a2, &a3);
//   res2 = sscanf(string, format, &b1, &b2, &b3);
//   ck_assert_int_eq(a1, b1);
//   ck_assert_int_eq(a2, b2);
//   ck_assert_int_eq(a3, b3);
//   ck_assert_int_eq(res1, res2);

//   a1 = 0, a2 = 0, a3 = 0, b1 = 0, b2 = 0, b3 = 0;
//   format[] = "%*c%c%c";
// string[] = "123.243";
//   res1 = s21_sscanf(string, format, &a1, &a2, &a3);
//   res2 = sscanf(string, format, &b1, &b2, &b3);
//   ck_assert_int_eq(a1, b1);
//   ck_assert_int_eq(a2, b2);
//   ck_assert_int_eq(a3, b3);
//   ck_assert_int_eq(res1, res2);

//   a1 = 0, a2 = 0, a3 = 0, b1 = 0, b2 = 0, b3 = 0;
//   format[] = "%10c%c%c %c";
// string[]= "     \n     1     2\t3";
//   res1 = s21_sscanf(string, format, &a1, &a2, &a3);
//   res2 = sscanf(string, format, &b1, &b2, &b3);
//   ck_assert_int_eq(a1, b1);
//   ck_assert_int_eq(a2, b2);
//   ck_assert_int_eq(a3, b3);
//   ck_assert_int_eq(res1, res2);

//   a1 = 0, a2 = 0, a3 = 0, b1 = 0, b2 = 0, b3 = 0;
//   format[] = "%*s %c %c %c";
// string[] = "     \n     1     2\t3";
//   res1 = s21_sscanf(string, format, &a1, &a2, &a3);
//   res2 = sscanf(string, format, &b1, &b2, &b3);
//   ck_assert_int_eq(a1, b1);
//   ck_assert_int_eq(a2, b2);
//   ck_assert_int_eq(a3, b3);
//   ck_assert_int_eq(res1, res2);

//   a1 = 0, a2 = 0, a3 = 0, b1 = 0, b2 = 0, b3 = 0;
//   char a4 = 0, b4 = 0;
//   format[] = "%c%c%c%c";
// string[] = "\\\n\t\t\t";
//   res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
//   res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
//   ck_assert_int_eq(a1, b1);
//   ck_assert_int_eq(a2, b2);
//   ck_assert_int_eq(a3, b3);
//   ck_assert_int_eq(a4, b4);
//   ck_assert_int_eq(res1, res2);

//   a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
//   format[] = "%c%*c%c%c";
// string[] = "1234";
//   res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
//   res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
//   ck_assert_int_eq(a1, b1);
//   ck_assert_int_eq(a2, b2);
//   ck_assert_int_eq(a3, b3);
//   ck_assert_int_eq(res1, res2);

//   a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
//   format = "%c%*c%c%c";
//   string[] = "1234";
//   res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
//   res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
//   ck_assert_int_eq(a1, b1);
//   ck_assert_int_eq(a2, b2);
//   ck_assert_int_eq(a3, b3);
//   ck_assert_int_eq(a4, b4);
//   ck_assert_int_eq(res1, res2);

//   a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
//   format[] = "%c%*c%c%*c %c";
// string[] = "1124\n580 234";
//   res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
//   res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
//   ck_assert_int_eq(a1, b1);
//   ck_assert_int_eq(a2, b2);
//   ck_assert_int_eq(a3, b3);
//   ck_assert_int_eq(a4, b4);
//   ck_assert_int_eq(res1, res2);

//   a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
//   format[] = "%c  %c   %c    %c";
// string[]= "1  2   3    4";
//   res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
//   res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
//   ck_assert_int_eq(a1, b1);
//   ck_assert_int_eq(a2, b2);
//   ck_assert_int_eq(a3, b3);
//   ck_assert_int_eq(a4, b4);
//   ck_assert_int_eq(res1, res2);

//   a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
//   format[] = "%c  %c   %c    %c";
// string[]= "1    2        3        4";
//   res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
//   res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
//   ck_assert_int_eq(a1, b1);
//   ck_assert_int_eq(a2, b2);
//   ck_assert_int_eq(a3, b3);
//   ck_assert_int_eq(a4, b4);
//   ck_assert_int_eq(res1, res2);

//   a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
//   format[] = "%c %c %c %c";
// string[] = "1234";
//   res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
//   res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
//   ck_assert_int_eq(a1, b1);
//   ck_assert_int_eq(a2, b2);
//   ck_assert_int_eq(a3, b3);
//   ck_assert_int_eq(a4, b4);
//   ck_assert_int_eq(res1, res2);

//   a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
//   format[] = "%c%*c%c%*c%*c%3c%c";
// string[]= "sdlgk;asjgl;skadjgla;sdgjasgdakl;sdga";
//   res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
//   res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
//   ck_assert_int_eq(a1, b1);
//   ck_assert_int_eq(a2, b2);
//   ck_assert_int_eq(a3, b3);
//   ck_assert_int_eq(a4, b4);
//   ck_assert_int_eq(res1, res2);

//   a1 = 0, a2 = 49;
//   format[] = "%2c";
// string[] = "112";
//   res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
//   ck_assert_int_eq(a1, a2);
// }
// END_TEST

START_TEST(I_SPECIFIER_SHORTINT) {
  char *format = "%hi";
  char *string = "0";
  short int a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  int res1 = s21_sscanf(string, format, &a1);
  int res2 = sscanf(string, format, &b1);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(res1, res2);

  a1 = 0, b1 = 0;
  format = "%hi";
  string = "-19214097";
  res1 = s21_sscanf(string, format, &a1);
  res2 = sscanf(string, format, &b1);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(res1, res2);

  a1 = 0, b1 = 0;
  format = "%hi";
  string = "123456789";
  res1 = s21_sscanf(string, format, &a1);
  res2 = sscanf(string, format, &b1);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(res1, res2);

  a1 = 0, b1 = 0;
  format = "%hi";
  string = "999";
  res1 = s21_sscanf(string, format, &a1);
  res2 = sscanf(string, format, &b1);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%hi%hi%hi%hi";
  string = "891 78 -1 +2";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%1hlli%10hlli%5hlli%3hlli";
  string = "-891 78 -1 +2";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%hi%1hlli%hi%hi";
  string = "999 +-888 777 666";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "-";
  string = "891 78 -1 +2";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%hi%hi%hi%hi";
  string = "nothing";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%hi%hi%hi%hi";
  string = "";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%hi%hi%hi%hi";
  string = "8910237598 7198235 710987235 98275239857";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%hi%hi%hi%hi";
  string = "1111 125 --1 +++2";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%3hlli%3hlli%3hlli%3hlli";
  string = "++1 --1 ++1 --1";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%hi%hi%hi%hi";
  string = "0 01 10 1";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  char a5 = 0, b5 = 0;
  format = "%hi%hi%c%hi%hi";
  string = "12345-12345-99099+123-3331020";
  res1 = s21_sscanf(string, format, &a1, &a2, &a5, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b5, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(a5, b5);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%hi%hi%hi%hi";
  string = "--------0 10 20 30";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%hi%hi%hi%hi";
  string = "a10";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(I_SPECIFIER_LONGINT) {
  char *format = "%li";
  char *string = "0";
  long int a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  int res1 = s21_sscanf(string, format, &a1);
  int res2 = sscanf(string, format, &b1);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(res1, res2);

  a1 = 0, b1 = 0;
  format = "%li";
  string = "-19214097";
  res1 = s21_sscanf(string, format, &a1);
  res2 = sscanf(string, format, &b1);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(res1, res2);

  a1 = 0, b1 = 0;
  format = "%li";
  string = "123456789";
  res1 = s21_sscanf(string, format, &a1);
  res2 = sscanf(string, format, &b1);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(res1, res2);

  a1 = 0, b1 = 0;
  format = "%li";
  string = "999";
  res1 = s21_sscanf(string, format, &a1);
  res2 = sscanf(string, format, &b1);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%li%li%li%li";
  string = "891 78 -1 +2";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%1hlli%10hlli%5hlli%3hlli";
  string = "-891 78 -1 +2";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%li%1hlli%li%li";
  string = "999 +-888 777 666";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "-";
  string = "891 78 -1 +2";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%li%li%li%li";
  string = "nothing";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%li%li%li%li";
  string = "";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%li%li%li%li";
  string = "8910237598 7198235 710987235 98275239857";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%li%li%li%li";
  string = "1111 125 --1 +++2";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%3hlli%3hlli%3hlli%3hlli";
  string = "++1 --1 ++1 --1";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%li%li%li%li";
  string = "0 01 10 1";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  char a5 = 0, b5 = 0;
  format = "%li%li%c%li%li";
  string = "12345-12345-99099+123-3331020";
  res1 = s21_sscanf(string, format, &a1, &a2, &a5, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b5, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(a5, b5);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%li%li%li%li";
  string = "--------0 10 20 30";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%li%li%li%li";
  string = "a10";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(I_SPECIFIER_INT) {
  char *format = "%i";
  char *string = "0";
  int a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  int res1 = s21_sscanf(string, format, &a1);
  int res2 = sscanf(string, format, &b1);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(res1, res2);

  a1 = 0, b1 = 0;
  format = "%i";
  string = "-19214097";
  res1 = s21_sscanf(string, format, &a1);
  res2 = sscanf(string, format, &b1);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(res1, res2);

  a1 = 0, b1 = 0;
  format = "%i";
  string =
      "12345678912345678912345678123456789123456789123456789123456789v123456789"
      "123456789123456789123456789123456789123456789912345678912345678912345678"
      "912345678912345678912345678912345678912345678912345678912345678912345678"
      "9123456789123456789123456789123456789123456789";
  res1 = s21_sscanf(string, format, &a1);
  res2 = sscanf(string, format, &b1);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(res1, res2);

  a1 = 0, b1 = 0;
  format = "%i";
  string = "999";
  res1 = s21_sscanf(string, format, &a1);
  res2 = sscanf(string, format, &b1);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%i%i%i%i";
  string = "891 78 -1 +2";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%1hlli%10hlli%5hlli%3hlli";
  string = "-891 78 -1 +2";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%i%1hlli%i%i";
  string = "999 +-888 777 666";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "-";
  string = "891 78 -1 +2";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%i%i%i%i";
  string = "nothing";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%i%i%i%i";
  string = "";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%i%i%i%i";
  string = "8910237598 7198235 710987235 98275239857";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%i%i%i%i";
  string = "1111 125 --1 +++2";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%3hlli%3hlli%3hlli%3hlli";
  string = "++1 --1 ++1 --1";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%i%i%i%i";
  string = "0 01 10 1";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  char a5 = 0, b5 = 0;
  format = "%i%i%c%i%i";
  string = "12345-12345-99099+123-3331020";
  res1 = s21_sscanf(string, format, &a1, &a2, &a5, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b5, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(a5, b5);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%i%i%i%i";
  string = "--------0 10 20 30";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%i%i%i%i";
  string = "a10";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  format = "%*i   %*i %*i%*6i";
  string = "0x10 125 012 0x125";
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(I_SPECIFIER_HEX) {
  char *format = "%i%i%i%i";
  char *string = "0x 0xFFFFFFFF 0xffffffff 123 125 999";
  int a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  int res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  int res2 = sscanf(string, format, &b1, &b2, &b3, &b4);

  format = "%i%i%i%i";
  string = "0x99 125 042 335";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%i%i%i%i";
  string = "0xAAAAAAAA 0xaaaaaaaa 012 35";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%i%i%i%i";
  string = "0xabcdef 0xABCDEF 0x1 0x2";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%i%i%i%i";
  string = "";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%i%i%i%i";
  string = "gf 123 55 88";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%i%i%i%i";
  string = "\n\t a\0";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%i%i%i%i";
  string = "0xFF0x0x1 0x2x030x3a 1a2 3e5";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%*x %i %*i %i";
  string = "abcdef feabc ffffff aaaaaa bbbbbbb cccccc";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%i%i%i%i";
  string = "tttt";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%2i%100i%1i%5i";
  string = "ABCDEF abcdef ABCDEF abcdef";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%i%i%i%i";
  string = "0x0000000000000000 0x9999999999999 0xFFFFFFFFFFFF 0x12393285012735";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%i%i%i%i";
  string = "-0xf +0x1 -2e -2eeeeee+e123";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(I_SPECIFIER_SHORTHEX) {
  char *format = "%hi%hi%hi%hi";
  char *string = "0x 0xFFFFFFFF 0xffffffff 123 125 999";
  short int a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  int res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  int res2 = sscanf(string, format, &b1, &b2, &b3, &b4);

  format = "%hi%hi%hi%hi";
  string = "0x99 125 042 335";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%hi%hi%hi%hi";
  string = "0xAAAAAAAA 0xaaaaaaaa 012 35";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%hi%hi%hi%hi";
  string = "0xabcdef 0xABCDEF 0x1 0x2";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%hi%hi%hi%hi";
  string = "0X 2X 3X 4X";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);

  format = "%hi%hi%hi%hi";
  string = "";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%hi%hi%hi%hi";
  string = "gf 123 55 88";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%hi%hi%hi%hi";
  string = "\n\t a\0";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%hi%hi%hi%hi";
  string = "0xFF0x0x1 0x2x030x3a 1a2 3e5";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%*x %hi %*i %hi";
  string = "abcdef feabc ffffff aaaaaa bbbbbbb cccccc";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%hi%hi%hi%hi";
  string = "tttt";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%2i%100i%1i%5i";
  string = "ABCDEF abcdef ABCDEF abcdef";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%hi%hi%hi%hi";
  string = "0x0000000000000000 0x9999999999999 0xFFFFFFFFFFFF 0x12393285012735";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%hi%hi%hi%hi";
  string = "-0xf +0x1 -1e -1eeeeee+e123";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(I_SPECIFIER_LONGHEX) {
  char *format = "%li%li%li%li";
  char *string = "0x 0xFFFFFFFF 0xffffffff 123 125 999";
  long int a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  int res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  int res2 = sscanf(string, format, &b1, &b2, &b3, &b4);

  format = "%li%li%li%li";
  string = "0x99 125 042 335";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%li%li%li%li";
  string = "0xAAAAAAAA 0xaaaaaaaa 012 35";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  // format = "%li%li%1li%1li";
  // string = "0xabcdef 0xABCDEF 0x1 0x2";
  // a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  // res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  // res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  // ck_assert_int_eq(a1, b1);
  // ck_assert_int_eq(a2, b2);
  // ck_assert_int_eq(a3, b3);
  // ck_assert_int_eq(a4, b4);
  // ck_assert_int_eq(res1, res2);

  format = "%li%li%li%li";
  string = "0X 2X 3X 4X";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);

  format = "%li%li%li%li";
  string = "";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%li%li%li%li";
  string = "gf 123 55 88";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%li%li%li%li";
  string = "\n\t a\0";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%li%li%li%li";
  string = "0xFF0x0x1 0x2x030x3a 1a2 3e5";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%*x %li %*i %li";
  string = "abcdef feabc ffffff aaaaaa ";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%li%li%li%li";
  string = "tttt";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%2i%100i%1i%5i";
  string = "ABCDEF abcdef ABCDEF abcdef";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%li%li%li%li";
  string = "0x0000000000000000 0x9999999999999 0xFFFFFFFFFFFF 0x12393285012735";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%li%li%li%li";
  string = "-0xf +0x1 -2e -2eeeeee+e123";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(I_SPECIFIER_OCT) {
  char *format = "%i%i%i%i";
  char *string = "";
  int a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  int res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  int res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%i%i%i%i";
  string = "088 0123 099 072";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%i%i%i%i";
  string = "0999 0999 0999 0999";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%i%i%i%i";
  string = "0123 0456 0789 000";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%i%i%i%i";
  string = "01299 03378 045 0092";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%i%i%i%i";
  string = "0x7777777777777 012 013 014 015 016 017 018";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%i%i%i%i";
  string = "0x 0x 0x 0x";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  // ck_assert_int_eq(res1, res2);

  format = "%i%i%i%i";
  string = "0X 0X 0X 0X";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  // ck_assert_int_eq(res1, res2);

  format = "%i%i%i%i";
  string = "o234 012 013 014";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%i%i%i%i";
  string = "\n       \t\t\t\n      05\02";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%i%i%i%i";
  string = "0123456 099999999999999999 07777777777777 0888888888888888";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%i%i%i%i";
  string = "0x100x200x300x40";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%i%i%i%i";
  string = "0x100 0x200 0x300 0x40";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%*o%i%i%*o";
  string = "10 0x20 0x30 40";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%i%i%i%i";
  string = "a b c d";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%i%i%i%i";
  string = "0x100x200x300x40";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%i%i%i%i";
  string = "-0x120 +0x10 -0x15 -010";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(I_SPECIFIER_SHORTOCT) {
  char *format = "%hi%hi%hi%hi";
  char *string = "";
  short int a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  int res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  int res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%hi%hi%hi%hi";
  string = "088 0123 099 072";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%hi%hi%hi%hi";
  string = "0999 0999 0999 0999";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%hi%hi%hi%hi";
  string = "0123 0456 0789 000";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%hi%hi%hi%hi";
  string = "01299 03378 045 0092";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%hi%hi%hi%hi";
  string = "0x7777777777777 012 013 014 015 016 017 018";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%hi%hi%hi%hi";
  string = "0x4 0x4 0x4 0x4";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%hi%hi%hi%hi";
  string = "0X4 0X4 0X4 0X4";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%hi%hi%hi%hi";
  string = "o234 012 013 014";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%hi%hi%hi%hi";
  string = "\n       \t\t\t\n      05\02";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%hi%hi%hi%hi";
  string = "0123456 099999999999999999 07777777777777 0888888888888888";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%hi%hi%hi%hi";
  string = "0x100x200x300x40";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%4hi%4hi%1hi%4hi";
  string = "0x100 x200 x300 x40";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%*o %hi %hi %*o";
  string =
      "1000000000000000000000 0x1000000000000000000000 "
      "0x1000000000000000000000 0x1000000000000000000000";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%hi%hi%hi%hi";
  string = "a b c d e f";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%hi%hi%hi%hi";
  string = "0x100x200x300x40";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%hi%hi%hi%hi";
  string = "-0x120 +0x10 -0x15 -010";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(I_SPECIFIER_LONGOCT) {
  char *format = "%li%li%li%li";
  char *string = "";
  long int a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  int res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  int res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%li%li%li%li";
  string = "088 0123 099 072";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%li%li%li%li";
  string = "0999 0999 0999 0999";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%li%li%li%li";
  string = "0123 0456 0789 000";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%li%li%li%li";
  string = "01299 03378 045 0092";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%li%li%li%li";
  string = "0x7777777777777 012 013 014 015 016 017 018";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%li%li%li%li";
  string = "0x 0x 0x 0x";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  // ck_assert_int_eq(res1, res2);

  format = "%li%li%li%li";
  string =
      "0X1000000000000000000000 0X1000000000000000000000 "
      "0X1000000000000000000000 0X1000000000000000000000";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%li%li%li%li";
  string = "o234 012 013 014";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%li%li%li%li";
  string = "\n       \t\t\t\n      05\02";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%li%li%li%li";
  string = "0123456 099999999999999999 07777777777777 0888888888888888";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%li%li%li%li";
  string = "0x100x200x300x40";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%4li%4li%1li%4li";
  string =
      "0x1001000000000000000000000 x2001000000000000000000000 "
      "x3001000000000000000000000 x401000000000000000000000 ";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%*o %li %li %*o";
  string = "010 0x30 0x52 048";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%li%li%li%li";
  string = "a b c d e f";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%li%li%li%li";
  string = "0x100x200x300x40";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%li%li%li%li";
  string = "-0x120 +0x10 -0x15 -010";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(G_SPECIFIER_FLOAT) {
  char *format = "%g%g%g%g";
  char *string = "1.2 2.4 3.6 4.8";
  float a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  int res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  int res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_float_eq(a1, b1);
  ck_assert_float_eq(a2, b2);
  ck_assert_float_eq(a3, b3);
  ck_assert_float_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%g%g%g%g";
  string = "1.2 2.4 3.6 4.8";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_float_eq(a1, b1);
  ck_assert_float_eq(a2, b2);
  ck_assert_float_eq(a3, b3);
  ck_assert_float_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%g%g%g%g";
  string = "0.0000001 -1 2.5 .1 125";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_float_eq(a1, b1);
  ck_assert_float_eq(a2, b2);
  ck_assert_float_eq(a3, b3);
  ck_assert_float_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%*g%g%g%2g";
  string = "1.2 2.4 3.6 4.8";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_float_eq(a1, b1);
  ck_assert_float_eq(a2, b2);
  ck_assert_float_eq(a3, b3);
  ck_assert_float_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%g%g%g%g";
  string = "1.2e+4 2.4e-4 3.6e4 0.1382e+7";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_float_eq(a1, b1);
  ck_assert_float_eq(a2, b2);
  ck_assert_float_eq(a3, b3);
  ck_assert_float_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%g%g%g%g";
  string = "1.2 2.4 3.6 4.8";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_float_eq(a1, b1);
  ck_assert_float_eq(a2, b2);
  ck_assert_float_eq(a3, b3);
  ck_assert_float_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%g%g%g%g";
  string = "2e4 2.3e+10 2.5e-10 --+";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_float_eq(a1, b1);
  ck_assert_float_eq(a2, b2);
  ck_assert_float_eq(a3, b3);
  ck_assert_float_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%g%g%g%g";
  string = "2.5e+3";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_float_eq(a1, b1);
  ck_assert_float_eq(a2, b2);
  ck_assert_float_eq(a3, b3);
  ck_assert_float_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%g%g%g%g";
  string = "";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_float_eq(a1, b1);
  ck_assert_float_eq(a2, b2);
  ck_assert_float_eq(a3, b3);
  ck_assert_float_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%g%g%g%g";
  string = ".1 +.2 -.3 ..4";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_float_eq(a1, b1);
  ck_assert_float_eq(a2, b2);
  ck_assert_float_eq(a3, b3);
  ck_assert_float_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%g%g%g%g";
  string = "1. 2. 3. 4.";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_float_eq(a1, b1);
  ck_assert_float_eq(a2, b2);
  ck_assert_float_eq(a3, b3);
  ck_assert_float_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%g%g%g%g";
  string = "-1e-10 -1.25e+0 2.5e-1 3";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_float_eq(a1, b1);
  ck_assert_float_eq(a2, b2);
  ck_assert_float_eq(a3, b3);
  ck_assert_float_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%2g%10g%6g%1g";
  string = "-1e-10 -1.25e+0 2.5e-1 3";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_float_eq(a1, b1);
  ck_assert_float_eq(a2, b2);
  ck_assert_float_eq(a3, b3);
  ck_assert_float_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%1g%1g%1g%1g";
  string = "-1e-10 -1.25e+0 2.5e-1 3";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_float_eq(a1, b1);
  ck_assert_float_eq(a2, b2);
  ck_assert_float_eq(a3, b3);
  ck_assert_float_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%2g%3g%5g%10g";
  string = "-1e-10 -1.25e+0 2.5e-1 3";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_float_eq(a1, b1);
  ck_assert_float_eq(a2, b2);
  ck_assert_float_eq(a3, b3);
  ck_assert_float_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%15g%3g%6g%2g";
  string = "-1e-10 -1.25e+0 2.5e-1 3";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_float_eq(a1, b1);
  ck_assert_float_eq(a2, b2);
  ck_assert_float_eq(a3, b3);
  ck_assert_float_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%g";
  string = "2.5e+500";
  a1 = 0, b1 = 0;
  res1 = s21_sscanf(string, format, &a1);
  res2 = sscanf(string, format, &b1);
  ck_assert_float_eq(a1, b1);
  ck_assert_int_eq(res1, res2);

  format = "%g";
  string =
      "12849812851."
      "3827601239854791203958127859123895012"
      "37512835127351238950871235709123587127385912938502173519280357891235e-4";
  a1 = 0, b1 = 0;
  res1 = s21_sscanf(string, format, &a1);
  res2 = sscanf(string, format, &b1);
  ck_assert_float_eq(a1, b1);
  ck_assert_int_eq(res1, res2);

  format = "%g";
  string =
      "999999999999999999999999999999999999999999999999999999999999999999999999"
      "99999999999999999999999999e+30";
  a1 = 0, b1 = 0;
  res1 = s21_sscanf(string, format, &a1);
  res2 = sscanf(string, format, &b1);
  ck_assert_float_eq(a1, b1);
  ck_assert_int_eq(res1, res2);

  // format = "%g%g%g%g";
  // string = "nan -nan inf -inf";
  // a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  // res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  // res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  // ck_assert_float_nan(a1);
  // ck_assert_float_nan(a2);
  // ck_assert_float_infinite(a3);
  // ck_assert_float_infinite(a4);
  // ck_assert_float_nan(b1);
  // ck_assert_float_nan(b2);
  // ck_assert_float_infinite(b3);
  // ck_assert_float_infinite(b4);
  // ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(EOF1) {
  char fstr[] = "%d";
  char str[] = "        ";

  int16_t res1 = s21_sscanf(str, fstr, 0);
  int16_t res2 = sscanf(str, fstr, 100);
  ck_assert_int_eq(res1, res2);
}
END_TEST

// START_TEST(EOF2) {
//   char fstr[] = "%d ";
//   char str[] = "               ";
//   int16_t a1 = 0, a2 = 0;

//   int16_t res1 = s21_sscanf(str, fstr, &a1);
//   int16_t res2 = sscanf(str, fstr, &a2);
//   ck_assert_int_eq(res1, res2);
// }
// END_TEST

START_TEST(EOF3) {
  char fstr[] = "%d ";
  char str[] = "  ";
  int16_t a1 = 0, a2 = 0;

  int16_t res1 = s21_sscanf(str, fstr, &a1);
  int16_t res2 = sscanf(str, fstr, &a2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(only_chars1) {
  char fstr[] = "%c %c %c %c";
  char str[] = "   a     b c d";
  int16_t a1 = 0, a2 = 5, b1 = 0, b2 = 5, c1 = 0, c2 = 5, d1 = 0, d2 = 5;

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);

  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(only_chars2) {
  char fstr[] = "%c%c%c%c";
  char str[] = "abcd";
  int16_t a1 = 0, a2 = 5, b1 = 0, b2 = 5, c1 = 0, c2 = 5, d1 = 0, d2 = 5;

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);

  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(only_chars3) {
  char fstr[] = "%c %c %c      %c";
  char str[] = "1 a 3   c           ";
  int16_t a1 = 0, a2 = 5, b1 = 0, b2 = 5, c1 = 0, c2 = 5, d1 = 0, d2 = 5;

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(only_chars4) {
  char fstr[] = "%c %c %c %c";
  char str[] = "   000 0    ";
  int16_t a1 = 0, a2 = 5, b1 = 0, b2 = 5, c1 = 0, c2 = 5, d1 = 0, d2 = 5;

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);

  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(only_chars5) {
  char fstr[] = "%c %c %c %c";
  char str[] = "tttt";
  int16_t a1 = 0, a2 = 5, b1 = 0, b2 = 5, c1 = 0, c2 = 5, d1 = 0, d2 = 5;

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);

  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(special_symbols_as_chars1) {
  char fstr[] = "%c%c%c%c";
  char str[] = "\\\n\t\t\t";
  int16_t a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(special_symbols_as_chars2) {
  char fstr[] = "%c %c %c %c";
  char str[] = "z ' ' /";
  int16_t a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(special_symbols_as_chars3) {
  char fstr[] = "%c%*c%c%c";
  char str[] = "ABCD";
  int16_t a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0;

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1);

  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
}
END_TEST

START_TEST(chars_flags1) {
  char fstr[] = "%c %c %c %c";
  char str[] = "z *'@";
  int16_t a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(chars_flags2) {
  char fstr[] = "%1c %c %c %0c";
  char str[] = "z *'@";
  int16_t a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(chars_flags3) {
  char fstr[] = "%c %c %c %c";
  char str[] = "z *'@";
  int16_t a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(chars_flags4) {
  char fstr[] = "%c %c %c %c";
  char str[] = "z *'@";
  int16_t a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(chars_flags5) {
  char fstr[] = "%*c%*c%*c%c";
  char str[] = "abcde";
  int16_t a1 = 0, a2 = 0;

  int16_t res1 = s21_sscanf(str, fstr, &a1);
  int16_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(chars_aster1) {
  char fstr[] = "%*c%*c%*c%*c";
  char str[] = "   c ";
  int16_t a1 = 0, a2 = 0;

  int16_t res1 = s21_sscanf(str, fstr, &a1);
  int16_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(chars_aster2) {
  char fstr[] = "%*c%*c%*c%c";
  char str[] = "abcd ";
  int16_t a1 = 0, a2 = 0;

  int16_t res1 = s21_sscanf(str, fstr, &a1);
  int16_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(only_ints1) {
  long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  const char fstr[] = "%ld %ld %ld %ld";
  const char str[] = "555 666 777 888";

  int32_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int32_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(only_ints2) {
  int16_t a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  const char str[] = "1337 21 5008 3000";
  const char fstr[] = "%hd %hd %hd %hd";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(only_ints3) {
  long long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  const char str[] = "1337 21 5008 300004";
  const char fstr[] = "%lld %lld %lld %lld";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(ints_nwidth1) {
  long long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  const char str[] = "1337 21 5008 300004";
  const char fstr[] = "%1lld %3lld %1lld %4lld";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(ints_nwidth2) {
  long long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  const char str[] = "1337";
  const char fstr[] = "%1lld %1lld %1lld %1lld";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(ints_nwidth3) {
  long long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  const char str[] = "100000000000000005";
  const char fstr[] = "%3lld%lld%1lld%5lld";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(ints_nwidth4) {
  long long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  const char str[] = "1337";
  const char fstr[] = "%15lld %1lld %1lld %1lld";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(ints_astwidth1) {
  long long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0;
  const char str[] = "1337123123 1 123412341234 1 999999 0";
  const char fstr[] = "%*d %lld %*d %lld %*d %lld";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
}
END_TEST

START_TEST(ints_astwidth2) {
  long long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  const char str[] = "1337";
  const char fstr[] = "%15lld %1lld %1lld %1lld";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(ints_astwidth3) {
  long long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  const char str[] = "1337";
  const char fstr[] = "%15lld %1lld %1lld %1lld";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(ints_astwidth4) {
  long long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  const char str[] = "1337";
  const char fstr[] = "%15lld %1lld %1lld %1lld";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(signed_ints1) {
  long long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  const char str[] = "11337 ++3 -5 ------4";
  const char fstr[] = "%lld %lld %lld %lld";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(signed_ints2) {
  long long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  const char str[] = "-1337 +1 -1 -1";
  const char fstr[] = "%15lld %1lld %1lld %5lld";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(signed_ints3) {
  long long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  const char str[] = "-0 +0 +0 -0";
  const char fstr[] = "%2lld %1lld %1lld %1lld";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(signed_ints4) {
  long long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  const char str[] = "1 01 10 0";
  const char fstr[] = "%lld %lld %lld %lld";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(spec_i_int1) {
  long long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  const char str[] = "300 500 -600 +700";
  const char fstr[] = "%lli %lli %lli %lli";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(spec_i_int2) {
  long long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  const char str[] = "300500-600+700 111";
  const char fstr[] = "%lli %lld %lld %lli";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(spec_i_int3) {
  long long a1 = 0, a2 = 0, c1 = 0, c2 = 0;
  char b1 = 0, b2 = 0, d1 = 0, d2 = 0;
  const char str[] = "300500-600+700+400";
  const char fstr[] = "%lli%c%lli%c";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(spec_i_int4) {
  long long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  const char str[] = "  55555 f f f5555555 ddd   4    3    1 ";
  const char fstr[] = "%lli %lld %lld %lli";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(spec_i_hex1) {
  long long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  const char str[] = "0xFFF 0xA123123 0x123123 0x0";
  const char fstr[] = "%lli %lld %lld %lli";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(spec_i_hex2) {
  long long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  const char str[] = " 0xFFFF 0xf 0xf 0xf5555555 ddd   4    3    1 ";
  const char fstr[] = "%lli %lld %lld %lli";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(spec_i_oct1) {
  long long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  const char str[] = "  055555 0f 0f 0f5555555 0ddd   4    3    1 ";
  const char fstr[] = "%lli %lld %lld %lli";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(spec_i_oct2) {
  long long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  const char str[] = "  055555 0f 0f 0f5555555 0ddd   4    3    1 ";
  const char fstr[] = "%lli %lld %lld %lli";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

/* [%s] */

START_TEST(strings1) {
  char s1[BUFF_SIZE] = {'\0'};
  char s2[BUFF_SIZE] = {'\0'};
  char s3[BUFF_SIZE] = {'\0'};
  char s4[BUFF_SIZE] = {'\0'};

  char s5[BUFF_SIZE] = {'\0'};
  char s6[BUFF_SIZE] = {'\0'};
  char s7[BUFF_SIZE] = {'\0'};
  char s8[BUFF_SIZE] = {'\0'};

  const char str[] = "Aboba Floppa Keppa Shleppa Anuroba";
  const char fstr[] = "%s %s %s %s";

  int16_t res1 = s21_sscanf(str, fstr, s1, s2, s3, s4);
  int16_t res2 = sscanf(str, fstr, s5, s6, s7, s8);

  ck_assert_int_eq(res1, res2);

  ck_assert_str_eq(s1, s5);
  ck_assert_str_eq(s2, s6);
  ck_assert_str_eq(s3, s7);
  ck_assert_str_eq(s4, s8);
}
END_TEST

START_TEST(strings_mixed3) {
  char s1[BUFF_SIZE] = {'\0'};
  char s2[BUFF_SIZE] = {'\0'};
  char s3[BUFF_SIZE] = {'\0'};
  char s4[BUFF_SIZE] = {'\0'};

  char s5[BUFF_SIZE] = {'\0'};
  char s6[BUFF_SIZE] = {'\0'};
  char s7[BUFF_SIZE] = {'\0'};
  char s8[BUFF_SIZE] = {'\0'};

  long long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;

  const char str[] = "Aboba 123 Floppa -3 Keppa 4444Shleppa 333Anuroba 3";
  const char fstr[] = "%s%ld%s%d%s%d%s";

  int16_t res1 = s21_sscanf(str, fstr, s1, &a1, s2, &b1, s3, &c1, s4, &d1);
  int16_t res2 = s21_sscanf(str, fstr, s5, &a2, s6, &b2, s7, &c2, s8, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);

  ck_assert_str_eq(s1, s5);
  ck_assert_str_eq(s2, s6);
  ck_assert_str_eq(s3, s7);
  ck_assert_str_eq(s4, s8);
}
END_TEST

START_TEST(strings2) {
  char s1[BUFF_SIZE] = {'\0'};
  char s2[BUFF_SIZE] = {'\0'};
  char s3[BUFF_SIZE] = {'\0'};
  char s4[BUFF_SIZE] = {'\0'};

  char s5[BUFF_SIZE] = {'\0'};
  char s6[BUFF_SIZE] = {'\0'};
  char s7[BUFF_SIZE] = {'\0'};
  char s8[BUFF_SIZE] = {'\0'};

  const char str[] = "aboba\tshlepa\tasdfasdf\tasdfasdf";
  const char fstr[] = "%s%s%s%s";

  int16_t res1 = s21_sscanf(str, fstr, s1, s2, s3, s4);
  int16_t res2 = sscanf(str, fstr, s5, s6, s7, s8);

  ck_assert_int_eq(res1, res2);

  ck_assert_str_eq(s1, s5);
  ck_assert_str_eq(s2, s6);
  ck_assert_str_eq(s3, s7);
  ck_assert_str_eq(s4, s8);
}
END_TEST

START_TEST(strings3) {
  char s1[BUFF_SIZE] = {'\0'};
  char s2[BUFF_SIZE] = {'\0'};
  char s3[BUFF_SIZE] = {'\0'};
  char s4[BUFF_SIZE] = {'\0'};

  char s5[BUFF_SIZE] = {'\0'};
  char s6[BUFF_SIZE] = {'\0'};
  char s7[BUFF_SIZE] = {'\0'};
  char s8[BUFF_SIZE] = {'\0'};

  const char str[] = "aboba\tkepaboba floppa shleppa koooppa ap p p p p";
  const char fstr[] = "%*s%*s%*s%*s";

  int16_t res1 = s21_sscanf(str, fstr);
  int16_t res2 = sscanf(str, fstr);

  ck_assert_int_eq(res1, res2);

  ck_assert_str_eq(s1, s5);
  ck_assert_str_eq(s2, s6);
  ck_assert_str_eq(s3, s7);
  ck_assert_str_eq(s4, s8);
}
END_TEST

START_TEST(strings4) {
  char s1[BUFF_SIZE] = {'\0'};
  char s2[BUFF_SIZE] = {'\0'};
  char s3[BUFF_SIZE] = {'\0'};
  char s4[BUFF_SIZE] = {'\0'};

  char s5[BUFF_SIZE] = {'\0'};
  char s6[BUFF_SIZE] = {'\0'};
  char s7[BUFF_SIZE] = {'\0'};
  char s8[BUFF_SIZE] = {'\0'};

  const char str[] = "aboba\tshlepa\tasdfasdf\tasdfasdf";
  const char fstr[] = "%1s%1s%1s%1s";

  int16_t res1 = s21_sscanf(str, fstr, s1, s2, s3, s4);
  int16_t res2 = sscanf(str, fstr, s5, s6, s7, s8);

  ck_assert_int_eq(res1, res2);

  ck_assert_str_eq(s1, s5);
  ck_assert_str_eq(s2, s6);
  ck_assert_str_eq(s3, s7);
  ck_assert_str_eq(s4, s8);
}
END_TEST

START_TEST(strings5) {
  char s1[BUFF_SIZE] = {'\0'};
  char s2[BUFF_SIZE] = {'\0'};
  char s3[BUFF_SIZE] = {'\0'};
  char s4[BUFF_SIZE] = {'\0'};

  char s5[BUFF_SIZE] = {'\0'};
  char s6[BUFF_SIZE] = {'\0'};
  char s7[BUFF_SIZE] = {'\0'};
  char s8[BUFF_SIZE] = {'\0'};

  const char str[] = "aboba\tshlepa\tasdfasdf\tasdfasdf";
  const char fstr[] = "%3s%3s%3s%3s";

  int16_t res1 = s21_sscanf(str, fstr, s1, s2, s3, s4);
  int16_t res2 = sscanf(str, fstr, s5, s6, s7, s8);

  ck_assert_int_eq(res1, res2);

  ck_assert_str_eq(s1, s5);
  ck_assert_str_eq(s2, s6);
  ck_assert_str_eq(s3, s7);
  ck_assert_str_eq(s4, s8);
}
END_TEST

START_TEST(strings6) {
  char s1[BUFF_SIZE] = {'\0'};
  char s2[BUFF_SIZE] = {'\0'};
  char s3[BUFF_SIZE] = {'\0'};
  char s4[BUFF_SIZE] = {'\0'};

  char s5[BUFF_SIZE] = {'\0'};
  char s6[BUFF_SIZE] = {'\0'};
  char s7[BUFF_SIZE] = {'\0'};
  char s8[BUFF_SIZE] = {'\0'};

  const char str[] = "aboba\tshlepa\tasdfasdf\tasdfasdf";
  const char fstr[] = "%150s%1s%1s\t%3s";

  int16_t res1 = s21_sscanf(str, fstr, s1, s2, s3, s4);
  int16_t res2 = sscanf(str, fstr, s5, s6, s7, s8);

  ck_assert_int_eq(res1, res2);

  ck_assert_str_eq(s1, s5);
  ck_assert_str_eq(s2, s6);
  ck_assert_str_eq(s3, s7);
  ck_assert_str_eq(s4, s8);
}
END_TEST

// strings_mixed1

START_TEST(strings_mixed1) {
  unsigned long long int a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0;
  long long d1 = 0, d2 = 0;
  long double e1 = 0, e2 = 0;

  const char str[] =
      "4444444"
      "eeeeeee\teeeeeee";
  const char fstr[] = "%5s %1s %*s %*s %llu %s %llu %llu %lld %Lf %33s";

  char s1[BUFF_SIZE] = {'\0'};
  char s2[BUFF_SIZE] = {'\0'};
  char s3[BUFF_SIZE] = {'\0'};
  char s4[BUFF_SIZE] = {'\0'};
  char s5[BUFF_SIZE] = {'\0'};
  char s6[BUFF_SIZE] = {'\0'};
  char s7[BUFF_SIZE] = {'\0'};
  char s8[BUFF_SIZE] = {'\0'};
  char s9[BUFF_SIZE] = {'\0'};
  char s10[BUFF_SIZE] = {'\0'};

  int16_t res1 = s21_sscanf(str, fstr, s7, s9, &a1, s5, &b1, &c1, &d1, &e1, s1);
  int16_t res2 = sscanf(str, fstr, s8, s10, &a2, s6, &b2, &c2, &d2, &e2, s2);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(s1, s2);
  ck_assert_str_eq(s3, s4);
  ck_assert_str_eq(s5, s6);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(strings_mixed2) {
  int d1 = 0, d2 = 0, b1 = 0, b2 = 0, a1 = 0, a2 = 0;
  long long v1, v2;

  const char str[] = "1 1 1 1 1 -1";
  const char fstr[] = "%1s %5d %1s %1s %d %lld %d";

  char s1[BUFF_SIZE] = {'\0'};
  char s2[BUFF_SIZE] = {'\0'};
  char s3[BUFF_SIZE] = {'\0'};
  char s4[BUFF_SIZE] = {'\0'};
  char s5[BUFF_SIZE] = {'\0'};
  char s6[BUFF_SIZE] = {'\0'};

  int16_t res1 = s21_sscanf(str, fstr, s1, &a1, s2, s3, &b1, &v1, &d1);
  int16_t res2 = sscanf(str, fstr, s4, &a2, s5, s6, &b2, &v2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(s1, s2);
  ck_assert_str_eq(s3, s4);
  ck_assert_str_eq(s5, s6);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(uint1) {
  unsigned short a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  const char str[] = "-1337 +21 --5008 3000";
  const char fstr[] = "%hu %hu %hu %hu";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_uint_eq(res1, res2);
  ck_assert_uint_eq(a1, a2);
  ck_assert_uint_eq(b1, b2);
  ck_assert_uint_eq(c1, c2);
  ck_assert_uint_eq(d1, d2);
}
END_TEST

START_TEST(uint2) {
  unsigned long long int a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0,
                         d2 = 0;
  const char str[] = "-1337 233333331 5008 3000";
  const char fstr[] = "%1llu %2llu %5llu %4llu";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(uint4) {
  unsigned short a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  const char str[] = "-1337 +21 --5008 3000";
  const char fstr[] = "%hu %hu %hu %hu";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(uint5) {
  unsigned short a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  const char str[] = "-1337 +21 --5008 3000";
  const char fstr[] = "%hu %hu %hu %hu";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(uint6) {
  unsigned short a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  const char str[] = "-1337 +21 --5008 3000";
  const char fstr[] = "%hu %hu %hu %hu";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(G_SPECIFIER_DOUBLE) {
  char *format = "%lg%lg%lg%lg";
  char *string = "1.2 2.4 3.6 4.8";
  double a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  int res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  int res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_double_eq(a1, b1);
  ck_assert_double_eq(a2, b2);
  ck_assert_double_eq(a3, b3);
  ck_assert_double_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%lg%lg%lg%lg";
  string = "1.2 2.4 3.6 4.8";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_double_eq(a1, b1);
  ck_assert_double_eq(a2, b2);
  ck_assert_double_eq(a3, b3);
  ck_assert_double_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%lg%lg%lg%lg";
  string = "0.0000001 -1 2.5 .1 125";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_double_eq(a1, b1);
  ck_assert_double_eq(a2, b2);
  ck_assert_double_eq(a3, b3);
  ck_assert_double_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%lg%lg%lg%lg";
  string = ". . . .";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_double_eq(a1, b1);
  ck_assert_double_eq(a2, b2);
  ck_assert_double_eq(a3, b3);
  ck_assert_double_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%*lg%lg%lg%2lg";
  string = "1.2 2.4 3.6 1.1";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_double_eq(a1, b1);
  ck_assert_double_eq(a2, b2);
  ck_assert_double_eq(a3, b3);
  ck_assert_double_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%lg%lg%lg%lg";
  string = "1.2e+4 2.4e-4 3.6e4 0.182e+7";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_double_eq(a1, b1);
  ck_assert_double_eq(a2, b2);
  ck_assert_double_eq(a3, b3);
  ck_assert_double_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%lg%lg%lg%lg";
  string = "1.2 2.4 3.6 4.8";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_double_eq(a1, b1);
  ck_assert_double_eq(a2, b2);
  ck_assert_double_eq(a3, b3);
  ck_assert_double_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%lg%lg%lg%lg";
  string = "2e4 2.3e+10 2.5e-10 -+";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_double_eq(a1, b1);
  ck_assert_double_eq(a2, b2);
  ck_assert_double_eq(a3, b3);
  ck_assert_double_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%lg%lg%lg%lg";
  string = "2.5e+3 ++ -- ++";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_double_eq(a1, b1);
  ck_assert_double_eq(a2, b2);
  ck_assert_double_eq(a3, b3);
  ck_assert_double_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%lg%lg%lg%lg";
  string = "";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_double_eq(a1, b1);
  ck_assert_double_eq(a2, b2);
  ck_assert_double_eq(a3, b3);
  ck_assert_double_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%lg%lg%lg%lg";
  string = ".1 +.2 -.2 ..4";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_double_eq(a1, b1);
  ck_assert_double_eq(a2, b2);
  ck_assert_double_eq(a3, b3);
  ck_assert_double_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%lg%lg%lg%lg";
  string = "1. 2. 3. 4.";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_double_eq(a1, b1);
  ck_assert_double_eq(a2, b2);
  ck_assert_double_eq(a3, b3);
  ck_assert_double_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%lg%lg%lg%lg";
  string = "-1e-10 -1.25e+0 2.5e-1 3";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_double_eq(a1, b1);
  ck_assert_double_eq(a2, b2);
  ck_assert_double_eq(a3, b3);
  ck_assert_double_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%2lg%10lg%6lg%1lg";
  string = "-1e-10 -1.25e+0 2.5e-1 3";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_double_eq(a1, b1);
  ck_assert_double_eq(a2, b2);
  ck_assert_double_eq(a3, b3);
  ck_assert_double_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%1lg%1lg%1lg%1lg";
  string = "-1e-10 -1.25e+1 2.5e-1 3";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_double_eq(a1, b1);
  ck_assert_double_eq(a2, b2);
  ck_assert_double_eq(a3, b3);
  ck_assert_double_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%2lg%3lg%5lg%10lg";
  string = "-1e-10 -1.25e+0 2.5e-1 3";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_double_eq(a1, b1);
  ck_assert_double_eq(a2, b2);
  ck_assert_double_eq(a3, b3);
  ck_assert_double_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%15lg%3lg%6lg%2lg";
  string = "-1e-10 -1.25e+0 2.5e-1 3";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_double_eq(a1, b1);
  ck_assert_double_eq(a2, b2);
  ck_assert_double_eq(a3, b3);
  ck_assert_double_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%g";
  string = "2.5e+500";
  a1 = 0, b1 = 0;
  res1 = s21_sscanf(string, format, &a1);
  res2 = sscanf(string, format, &b1);
  ck_assert_double_eq(a1, b1);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(G_SPECIFIER_LONGDOUBLE) {
  char *format = "%Lg%Lg%Lg%Lg";
  char *string = "1.5 2.5 3.5 4.5";
  long double a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  int res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  int res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_ldouble_eq(a1, b1);
  ck_assert_ldouble_eq(a2, b2);
  ck_assert_ldouble_eq(a3, b3);
  ck_assert_ldouble_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%Lg%Lg%Lg%Lg";
  string = "1.5 2.5 3.5 4.5";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_ldouble_eq(a1, b1);
  ck_assert_ldouble_eq(a2, b2);
  ck_assert_ldouble_eq(a3, b3);
  ck_assert_ldouble_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%Lg%Lg%Lg%Lg";
  string = "3.5 -1 2.5 .5 125";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_ldouble_eq(a1, b1);
  ck_assert_ldouble_eq(a2, b2);
  ck_assert_ldouble_eq(a3, b3);
  ck_assert_ldouble_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%Lg%Lg%Lg%Lg";
  string = ". . . .";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_ldouble_eq(a1, b1);
  ck_assert_ldouble_eq(a2, b2);
  ck_assert_ldouble_eq(a3, b3);
  ck_assert_ldouble_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%*Lg%Lg%Lg%2Lg";
  string = "1.5 2.5 3.5 4.5";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_ldouble_eq(a1, b1);
  ck_assert_ldouble_eq(a2, b2);
  ck_assert_ldouble_eq(a3, b3);
  ck_assert_ldouble_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%Lg%Lg%Lg%Lg";
  string = "1.5e+4 5 3.5e4 4.5e";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_ldouble_eq(a1, b1);
  ck_assert_ldouble_eq(a2, b2);
  ck_assert_ldouble_eq(a3, b3);
  ck_assert_ldouble_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%Lg%Lg%Lg%Lg";
  string = "1.5 2.5 3.5 4.5";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_ldouble_eq(a1, b1);
  ck_assert_ldouble_eq(a2, b2);
  ck_assert_ldouble_eq(a3, b3);
  ck_assert_ldouble_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%Lg%Lg%Lg";
  string = "2e4 2.3e+10 2.5e+10";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3);
  res2 = sscanf(string, format, &b1, &b2, &b3);
  ck_assert_ldouble_eq(a1, b1);
  ck_assert_ldouble_eq(a2, b2);
  ck_assert_ldouble_eq(a3, b3);
  ck_assert_int_eq(res1, res2);

  format = "%Lg%Lg%Lg%Lg";
  string = "2.5e+3 ++ -- ++";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_ldouble_eq(a1, b1);
  ck_assert_ldouble_eq(a2, b2);
  ck_assert_ldouble_eq(a3, b3);
  ck_assert_ldouble_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%Lg%Lg%Lg%Lg";
  string = "";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_ldouble_eq(a1, b1);
  ck_assert_ldouble_eq(a2, b2);
  ck_assert_ldouble_eq(a3, b3);
  ck_assert_ldouble_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%Lg%Lg%Lg%Lg";
  string = ".5 +.5 -.5 ..5";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_ldouble_eq(a1, b1);
  ck_assert_ldouble_eq(a2, b2);
  ck_assert_ldouble_eq(a3, b3);
  ck_assert_ldouble_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%Lg%Lg%Lg%Lg";
  string = "1. 2. 3. 4.";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_ldouble_eq(a1, b1);
  ck_assert_ldouble_eq(a2, b2);
  ck_assert_ldouble_eq(a3, b3);
  ck_assert_ldouble_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%Lg%Lg%Lg";
  string = "-1e+10 -1.25e+2 2.5e-1 3";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3);
  res2 = sscanf(string, format, &b1, &b2, &b3);
  ck_assert_ldouble_eq(a1, b1);
  ck_assert_ldouble_eq(a2, b2);
  ck_assert_ldouble_eq(a3, b3);
  ck_assert_int_eq(res1, res2);

  format = "%2Lg%10Lg%6Lg%1Lg";
  string = "-1e-10 -1.25e+0 2.5e-1 3";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_ldouble_eq(a1, b1);
  ck_assert_ldouble_eq(a2, b2);
  ck_assert_ldouble_eq(a3, b3);
  ck_assert_ldouble_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%1Lg%1Lg%1Lg%1Lg";
  string = "-1e-10 -1.25e+0 2.5e-1 3";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_ldouble_eq(a1, b1);
  ck_assert_ldouble_eq(a2, b2);
  ck_assert_ldouble_eq(a3, b3);
  ck_assert_ldouble_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%2Lg%3Lg%5Lg%10Lg";
  string = "-1e-10 -1.25e+0 2.5e-1 3";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_ldouble_eq(a1, b1);
  ck_assert_ldouble_eq(a2, b2);
  ck_assert_ldouble_eq(a3, b3);
  ck_assert_ldouble_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%15Lg%3Lg%6Lg%2Lg";
  string = "-1e+10 -1.25e+0 2.5e+1 3";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_ldouble_eq(a1, b1);
  ck_assert_ldouble_eq(a2, b2);
  ck_assert_ldouble_eq(a3, b3);
  ck_assert_ldouble_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%g";
  string = "2.5e+500";
  a1 = 0, b1 = 0;
  res1 = s21_sscanf(string, format, &a1);
  res2 = sscanf(string, format, &b1);
  ck_assert_ldouble_eq(a1, b1);
  ck_assert_int_eq(res1, res2);

  format = "%g";
  string = "12849812851.4";
  a1 = 0, b1 = 0;
  res1 = s21_sscanf(string, format, &a1);
  res2 = sscanf(string, format, &b1);
  ck_assert_ldouble_eq(a1, b1);
  ck_assert_int_eq(res1, res2);

  format = "%g";
  string =
      "999999999999999999999999999999999999999999999999999999999999999999999999"
      "99999999999999999999999999e+30";
  a1 = 0, b1 = 0;
  res1 = s21_sscanf(string, format, &a1);
  res2 = sscanf(string, format, &b1);
  ck_assert_ldouble_eq(a1, b1);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(O_SPECIFIER_USHORTOCT) {
  char *format = "%ho%ho%ho%ho";
  char *string = "";
  unsigned short int a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0,
                     b4 = 0;
  int res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  int res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%ho%ho%ho%ho";
  string = "088 0123 099 072";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%ho%ho%ho%ho";
  string = "0999 0999 0999 0999";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%ho%ho%ho%ho";
  string = "0123 0456 0789 000";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%ho%ho%ho%ho";
  string = "01299 03378 045 0092";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%ho%ho%ho%ho";
  string = "0x77777777777777777777777777777777777 012 013 014 015 016 017 018";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%ho%ho%ho%ho";
  string = "0x 0x 0x 0x";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%ho%ho%ho%ho";
  string = "0X 0X 0X 0X";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%ho%ho%ho%ho";
  string = "o234 012 013 014";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%ho%ho%ho%ho";
  string = "\n       \t\t\t\n      05\02";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%ho%ho%ho%ho";
  string = "0123456 099999999999999999 07777777777777 0888888888888888";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%ho%ho%ho%ho";
  string = "100 200 300 40";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%4ho%4ho%1ho%4ho";
  string = "0100 0200 0300 040";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%*o%ho%ho%*o ";
  string = "010 020 030 040";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%ho%ho%ho%ho";
  string = "a b c d";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%ho%ho%ho%ho";
  string = "010 020 030 040";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%ho%ho%ho%ho";
  string = "-0120 +010 -015 -010";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(O_SPECIFIER_ULONGOCT) {
  char *format = "%lo%lo%lo%lo";
  char *string = "";
  long int a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  int res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  int res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%lo%lo%1lo%lo";
  string = "088 0123 099 072";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%lo%1lo%1lo%1lo";
  string = "0999 0999 0999 0999";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%lo%lo%lo%lo";
  string = "0123 0456 0789 000";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%lo%lo%lo%lo";
  string = "01299 03378 045 0092";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%1lo%lo%lo%lo";
  string = "0x77777777777777 012 013 014 015 016 017 018";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%lo%lo%lo%lo";
  string = "0x 0x 0x 0x";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%lo%lo%lo%lo";
  string = "0X 0X 0X 0X";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%lo%lo%lo%lo";
  string = "o234 012 013 014";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%lo%lo%lo%lo";
  string = "\n       \t\t\t\n      05\02";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%lo%lo%lo%lo";
  string = "0123456 099999999999999999 07777777777777 0888888888888888";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%lo%lo%lo%lo";
  string = "010020030040";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%4lo%4lo%1lo%4lo";
  string = "010020030040";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%*o%lo%lo%*o%lo%lo";
  string = "01002003040 010 030 052 048";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%lo%lo%lo%lo";
  string = "a b c d e f";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%lo%lo%lo%lo";
  string = "01009999 20099 30099  4099";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%lo%lo%lo%lo";
  string = "-0120 +010 -015 -010";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(O_SPECIFIER_UOCT) {
  char *format = "%o%o%o%o";
  char *string = "";
  int a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  int res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  int res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%o%o%o%o";
  string = "088 0123 099 072";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%o%o%o%o";
  string = "0999 0999 0999 0999";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%o%o%o%o";
  string = "0123 0456 0789 000";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%o%o%o%o";
  string = "01299 03378 045 0092";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%o%o%o%o";
  string = "0x77777777777777777777777777777777777 012 013 014 015 016 017 018";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%o%o%o%o";
  string = "0x 0x 0x 0x";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%o%o%o%o";
  string = "0X 0X 0X 0X";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%o%o%o%o";
  string = "o234 012 013 014";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%o%o%o%o";
  string = "\n       \t\t\t\n      05\02";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%o%o%o%o";
  string = "0123456 099999999999999999 07777777777777 0888888888888888";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%o%o%o%o";
  string = "0x100x200x300x40";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%4o%4o%1o%4o";
  string = "0x100x200x300x40";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%*o%o%o%*o";
  string = "010 030 052 048";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%o%o%o%o";
  string = "a b c d";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%o%o%o%o";
  string = "0x100x200x300x40";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%o%o%o%o";
  string = "-0x120 +0x10 -0x15 -010";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(S_SPECIFIER1) {
  char *format = "%s %s %s %s";
  char *string = "string1 string2 string3 string4 string5";
  char string1[10] = {0};
  char string2[10] = {0};
  char string3[10] = {0};
  char string4[10] = {0};
  char string5[10] = {0};
  char string6[10] = {0};
  char string7[10] = {0};
  char string8[10] = {0};
  int res1 = s21_sscanf(string, format, string1, string2, string3, string4);
  int res2 = sscanf(string, format, string5, string6, string7, string8);
  ck_assert_str_eq(string1, string5);
  ck_assert_str_eq(string2, string6);
  ck_assert_str_eq(string3, string7);
  ck_assert_str_eq(string4, string8);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(S_SPECIFIER2) {
  char *format = "%s%s%s%s";
  char *string = "string1 string2 string3 string4 string5";
  char string1[10] = {0};
  char string2[10] = {0};
  char string3[10] = {0};
  char string4[10] = {0};
  char string5[10] = {0};
  char string6[10] = {0};
  char string7[10] = {0};
  char string8[10] = {0};
  int res1 = s21_sscanf(string, format, string1, string2, string3, string4);
  int res2 = sscanf(string, format, string5, string6, string7, string8);
  ck_assert_str_eq(string1, string5);
  ck_assert_str_eq(string2, string6);
  ck_assert_str_eq(string3, string7);
  ck_assert_str_eq(string4, string8);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(S_SPECIFIER3) {
  char *format = "%s   %s     %s     %s";
  char *string = "string1 string2 string3 string4 string5";
  char string1[10] = {0};
  char string2[10] = {0};
  char string3[10] = {0};
  char string4[10] = {0};
  char string5[10] = {0};
  char string6[10] = {0};
  char string7[10] = {0};
  char string8[10] = {0};
  int res1 = s21_sscanf(string, format, string1, string2, string3, string4);
  int res2 = sscanf(string, format, string5, string6, string7, string8);
  ck_assert_str_eq(string1, string5);
  ck_assert_str_eq(string2, string6);
  ck_assert_str_eq(string3, string7);
  ck_assert_str_eq(string4, string8);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(S_SPECIFIER4) {
  char *format = "%s%s%s%s";
  char *string = "string1\nstring2 string3\tstr\0ing4string5";
  char string1[10] = {0};
  char string2[10] = {0};
  char string3[10] = {0};
  char string4[10] = {0};
  char string5[10] = {0};
  char string6[10] = {0};
  char string7[10] = {0};
  char string8[10] = {0};
  int res1 = s21_sscanf(string, format, string1, string2, string3, string4);
  int res2 = sscanf(string, format, string5, string6, string7, string8);
  ck_assert_str_eq(string1, string5);
  ck_assert_str_eq(string2, string6);
  ck_assert_str_eq(string3, string7);
  ck_assert_str_eq(string4, string8);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(S_SPECIFIER5) {
  char *format = "%s%*s%s  %*s %s%s %*s";
  char *string =
      "string1 string2 string3 string4 string5 string6 string7 string8 string9 "
      "string10";
  char string1[10] = {0};
  char string2[10] = {0};
  char string3[10] = {0};
  char string4[10] = {0};
  char string5[10] = {0};
  char string6[10] = {0};
  char string7[10] = {0};
  char string8[10] = {0};
  int res1 = s21_sscanf(string, format, string1, string2, string3, string4);
  int res2 = sscanf(string, format, string5, string6, string7, string8);
  ck_assert_str_eq(string1, string5);
  ck_assert_str_eq(string2, string6);
  ck_assert_str_eq(string3, string7);
  ck_assert_str_eq(string4, string8);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(S_SPECIFIER6) {
  char *format = "%s%*s%s%s  %*s%s    %*s";
  char *string = "1 2 3 4 5 6 7 8";
  char string1[10] = {0};
  char string2[10] = {0};
  char string3[10] = {0};
  char string4[10] = {0};
  char string5[10] = {0};
  char string6[10] = {0};
  char string7[10] = {0};
  char string8[10] = {0};
  int res1 = s21_sscanf(string, format, string1, string2, string3, string4);
  int res2 = sscanf(string, format, string5, string6, string7, string8);
  ck_assert_str_eq(string1, string5);
  ck_assert_str_eq(string2, string6);
  ck_assert_str_eq(string3, string7);
  ck_assert_str_eq(string4, string8);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(S_SPECIFIER7) {
  char *format = "%1s%2s%3s%4s";
  char *string = "string1 string2 string3 string4 string5";
  char string1[10] = {0};
  char string2[10] = {0};
  char string3[10] = {0};
  char string4[10] = {0};
  char string5[10] = {0};
  char string6[10] = {0};
  char string7[10] = {0};
  char string8[10] = {0};
  int res1 = s21_sscanf(string, format, string1, string2, string3, string4);
  int res2 = sscanf(string, format, string5, string6, string7, string8);
  ck_assert_str_eq(string1, string5);
  ck_assert_str_eq(string2, string6);
  ck_assert_str_eq(string3, string7);
  ck_assert_str_eq(string4, string8);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(S_SPECIFIER8) {
  char *format = "%4s%3s%2s%1s";
  char *string = "string1 string2 string3 string4 string5";
  char string1[10] = {0};
  char string2[10] = {0};
  char string3[10] = {0};
  char string4[10] = {0};
  char string5[10] = {0};
  char string6[10] = {0};
  char string7[10] = {0};
  char string8[10] = {0};
  int res1 = s21_sscanf(string, format, string1, string2, string3, string4);
  int res2 = sscanf(string, format, string5, string6, string7, string8);
  ck_assert_str_eq(string1, string5);
  ck_assert_str_eq(string2, string6);
  ck_assert_str_eq(string3, string7);
  ck_assert_str_eq(string4, string8);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(S_SPECIFIER9) {
  char *format = "%s%3s%s%6s";
  char *string = "string1 string2 string3 string4 string5";
  char string1[10] = {0};
  char string2[10] = {0};
  char string3[10] = {0};
  char string4[10] = {0};
  char string5[10] = {0};
  char string6[10] = {0};
  char string7[10] = {0};
  char string8[10] = {0};
  int res1 = s21_sscanf(string, format, string1, string2, string3, string4);
  int res2 = sscanf(string, format, string5, string6, string7, string8);
  ck_assert_str_eq(string1, string5);
  ck_assert_str_eq(string2, string6);
  ck_assert_str_eq(string3, string7);
  ck_assert_str_eq(string4, string8);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(S_SPECIFIER10) {
  char *format = "%1s%1s%1s%1s";
  char *string =
      "string1 string2 string3 string4 string5 string7 string8 string9 "
      "string10";
  char string1[10] = {0};
  char string2[10] = {0};
  char string3[10] = {0};
  char string4[10] = {0};
  char string5[10] = {0};
  char string6[10] = {0};
  char string7[10] = {0};
  char string8[10] = {0};
  int res1 = s21_sscanf(string, format, string1, string2, string3, string4);
  int res2 = sscanf(string, format, string5, string6, string7, string8);
  ck_assert_str_eq(string1, string5);
  ck_assert_str_eq(string2, string6);
  ck_assert_str_eq(string3, string7);
  ck_assert_str_eq(string4, string8);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(S_SPECIFIER11) {
  char *format = "%10s%15s%20s%30s";
  char *string =
      "string1\tstring2\nstring3      string4\0string5 string7 string8 string9 "
      "string10";
  char string1[10] = {0};
  char string2[10] = {0};
  char string3[10] = {0};
  char string4[10] = {0};
  char string5[10] = {0};
  char string6[10] = {0};
  char string7[10] = {0};
  char string8[10] = {0};
  int res1 = s21_sscanf(string, format, string1, string2, string3, string4);
  int res2 = sscanf(string, format, string5, string6, string7, string8);
  ck_assert_str_eq(string1, string5);
  ck_assert_str_eq(string2, string6);
  ck_assert_str_eq(string3, string7);
  ck_assert_str_eq(string4, string8);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(S_SPECIFIER12) {
  char *format = "%100s%200s%300s%400s";
  char *string =
      "string1 string2 string3 string4 string5 string7 string8 string9 "
      "string10";
  char string1[10] = {0};
  char string2[10] = {0};
  char string3[10] = {0};
  char string4[10] = {0};
  char string5[10] = {0};
  char string6[10] = {0};
  char string7[10] = {0};
  char string8[10] = {0};
  int res1 = s21_sscanf(string, format, string1, string2, string3, string4);
  int res2 = sscanf(string, format, string5, string6, string7, string8);
  ck_assert_str_eq(string1, string5);
  ck_assert_str_eq(string2, string6);
  ck_assert_str_eq(string3, string7);
  ck_assert_str_eq(string4, string8);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(errorrrr_u) {
  unsigned int a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  char format[] = "%u%u%u%u";
  char string[] = "8910237598 7198235 710987235 98275239857";
  int res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  int res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_uint_eq(a1, b1);
  ck_assert_uint_eq(a2, b2);
  ck_assert_uint_eq(a3, b3);
  ck_assert_uint_eq(a4, b4);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(X_SPECIFIER_USHORTHEX) {
  char *format = "%hx%hx%hx%hx";
  char *string = "0x 0xFFFFFFFF 0xffffffff 123 125 999";
  unsigned short int a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0,
                     b4 = 0;
  int res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  int res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  // ck_assert_int_eq(a2, b2);
  // ck_assert_int_eq(a3, b3);
  // ck_assert_int_eq(a4, b4);
  // ck_assert_int_eq(res1, res2);

  format = "%hx%hx%hx%hx";
  string = "0x99 125 042 335";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%hx%hx%hx%hx";
  string = "0xAAAAAAAA 0xaaaaaaaa 012 35";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%hx%hx%i%i";
  string = "0xabcdef 0xABCDEF 0x1 0x2";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%hx%hx%hx%hx";
  string = "0X 2X 3X 4X";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);

  format = "%hx%hx%hx%hx";
  string = "";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%hx%hx%hx%hx";
  string = "gf 123 55 88";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%hx%hx%hx%hx";
  string = "\n\t a\0";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%hx%hx%hx%hx";
  string = "0xFF0x0x1 0x2x030x3a 1a2 3e5";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%*x %hx %*x %hx";
  string = "abcdef feabc ffffff aaaaaa bbbbbbb cccccc";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%hx%hx%hx%hx";
  string = "tttt";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%hx%hx%hx%hx";
  string = "-a +b -cdef -fff";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%2i%100i%1i%5i";
  string = "ABCDEF abcdef ABCDEF abcdef";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%hx%hx%hx%hx";
  string = "0x0000000000000000 0x9999999999999 0xFFFFFFFFFFFF 0x12393285012735";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%hx%hx%hx%hx";
  string = "-0xf +0x1 -e -eeeeee+e123";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(X_SPECIFIER_ULONGHEX) {
  char *format = "%lx%lx%lx%lx";
  char *string = "0x 0xFFFFFFFF 0xffffffff 123 125 999";
  unsigned long int a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0,
                    b4 = 0;
  int res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  int res2 = sscanf(string, format, &b1, &b2, &b3, &b4);

  format = "%lx%lx%lx%lx";
  string = "0x99 125 042 335";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%lx%lx%lx%lx";
  string = "0xAAAAAAAA 0xaaaaaaaa 012 35";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%lx%lx%x%x";
  string = "0xabcdef 0xABCDEF 0x1 0x2";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%lx%lx%lx%lx";
  string = "0X 2X 3X 4X";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);

  format = "%lx%lx%lx%lx";
  string = "";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%lx%lx%lx%lx";
  string = "gf 123 55 88";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%lx%lx%lx%lx";
  string = "\n\t a\0";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%lx%lx%lx%lx";
  string = "0xFF0x0x1 0x2x030x3a 1a2 3e5";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%*x %lx %*x %lx";
  string = "abcdef feabc ffffff aaaaaa bbbbbbb cccccc";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%lx%lx%lx%lx";
  string = "tttt";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%lx%lx%lx%lx";
  string = "-a +b -cdef -fff";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%2i%100i%1i%5i";
  string = "ABCDEF abcdef ABCDEF abcdef";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%lx%lx%lx%lx";
  string = "0x0000000000000000 0x9999999999999 0xFFFFFFFFFFFF 0x12393285012735";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%lx%lx%lx%lx";
  string = "-0xf +0x1 -e -eeeeee+e123";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(X_SPECIFIER_UHEX) {
  char *format = "%x%x%x%x";
  char *string = "0x 0xFFFFFFFF 0xffffffff 123 125 999";
  unsigned int a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  int res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  int res2 = sscanf(string, format, &b1, &b2, &b3, &b4);

  format = "%x%x%x%x";
  string = "0x99 125 042 335";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%x%x%x%x";
  string = "0xAAAAAAAA 0xaaaaaaaa 012 35";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%x%x%i%i";
  string = "0xabcdef 0xABCDEF 0x1 0x2";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%x%x%x%x";
  string = "0X 2X 3X 4X";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);

  format = "%x%x%x%x";
  string = "";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%x%x%x%x";
  string = "gf 123 55 88";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%x%x%x%x";
  string = "\n\t a\0";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%x%x%x%x";
  string = "0xFF0x0x1 0x2x030x3a 1a2 3e5";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%*x %x %*x %x";
  string = "abcdef feabc ffffff aaaaaa bbbbbbb cccccc";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%x%x%x%x";
  string = "tttt";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%x%x%x%x";
  string = "-a +b -cdef -fff";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%2i%100i%1i%5i";
  string = "ABCDEF abcdef ABCDEF abcdef";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%x%x%x%x";
  string = "0x0000000000000000 0x9999999999999 0xFFFFFFFFFFFF 0x12393285012735";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%x%x%x%x";
  string = "-0xf +0x1 -e -eeeeee+e123";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%*x%*x%*x    %*x";
  string = "0xf 0x1 0x 0x123";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(P_SPECIFIER1) {
  char *format = "%p%p%p%p";
  char *string = "0x123 0xAAAA 0xfffffff 0x9821238";
  int *a1 = 0, *a2 = 0, *a3 = 0, *a4 = 0, *b1 = 0, *b2 = 0, *b3 = 0, *b4 = 0;
  int res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  int res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_ptr_eq(a1, b1);
  ck_assert_ptr_eq(a2, b2);
  ck_assert_ptr_eq(a3, b3);
  ck_assert_ptr_eq(a4, b4);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(P_SPECIFIER2) {
  char *format = "%p%p%p%p";
  char *string = "0x1 0x2 0x3 0x4 0x5 0x6";
  int *a1 = 0, *a2 = 0, *a3 = 0, *a4 = 0, *b1 = 0, *b2 = 0, *b3 = 0, *b4 = 0;
  int res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  int res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_ptr_eq(a1, b1);
  ck_assert_ptr_eq(a2, b2);
  ck_assert_ptr_eq(a3, b3);
  ck_assert_ptr_eq(a4, b4);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(P_SPECIFIER3) {
  char *format = "%p%p%p%p";
  char *string = "+12 99 +128 33 55";
  int *a1 = 0, *a2 = 0, *a3 = 0, *a4 = 0, *b1 = 0, *b2 = 0, *b3 = 0, *b4 = 0;
  int res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  int res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_ptr_eq(a1, b1);
  ck_assert_ptr_eq(a2, b2);
  ck_assert_ptr_eq(a3, b3);
  ck_assert_ptr_eq(a4, b4);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(P_SPECIFIER4) {
  char *format = "%p%p%p%p";
  char *string = "015 016 017 018";
  int *a1 = 0, *a2 = 0, *a3 = 0, *a4 = 0, *b1 = 0, *b2 = 0, *b3 = 0, *b4 = 0;
  int res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  int res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_ptr_eq(a1, b1);
  ck_assert_ptr_eq(a2, b2);
  ck_assert_ptr_eq(a3, b3);
  ck_assert_ptr_eq(a4, b4);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(N_SPECIFIER) {
  char *format = "%d%d%n%d%d%n";
  char *string = "12 345 67 891 0 92 1 2 3 84 8 5 5423 134 464 ";
  int a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  int n1 = 0, n2 = 0, n3 = 0, n4 = 0;
  int res1 = s21_sscanf(string, format, &a1, &a2, &n1, &a3, &a4, &n2);
  int res2 = sscanf(string, format, &b1, &b2, &n3, &b3, &b4, &n4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(n1, n3);
  ck_assert_int_eq(n2, n4);
  ck_assert_int_eq(res1, res2);

  format = "%s %s      %n  %s    %s";
  string = "slkdgfsd jgdsla;gk as;ldg jasd;gl kasdjg ;alsdg jasgds";
  n1 = 0, n2 = 0;
  char string1[10] = {0};
  char string2[10] = {0};
  char string3[10] = {0};
  char string4[10] = {0};
  char string5[10] = {0};
  char string6[10] = {0};
  char string7[10] = {0};
  char string8[10] = {0};
  res1 = s21_sscanf(string, format, string1, string2, &n1, string3, string4);
  res2 = sscanf(string, format, string5, string6, &n2, string7, string8);
  ck_assert_str_eq(string1, string5);
  ck_assert_str_eq(string2, string6);
  ck_assert_str_eq(string3, string7);
  ck_assert_str_eq(string4, string8);
  ck_assert_int_eq(n1, n2);
  ck_assert_int_eq(res1, res2);

  format = "%n";
  string = "sd56fk. sj12ggdflk -sdjfk+123 sjkdl fd";
  n1 = 0, n2 = 0;
  res1 = s21_sscanf(string, format, &n1);
  res2 = sscanf(string, format, &n2);
  ck_assert_int_eq(n1, n2);
  ck_assert_int_eq(res1, res2);

  format = "   %c%n  %c %c    %n%c";
  string = "sdlkf sdf bv81 2k 283 mkals98f 123    as";
  n1 = 0, n2 = 0, n3 = 0, n4 = 0;
  char c1 = 0, c2 = 0, c3 = 0, c4 = 0, c5 = 0, c6 = 0, c7 = 0, c8 = 0;
  res1 = s21_sscanf(string, format, &c1, &n1, &c2, &c3, &n2, &c4);
  res2 = sscanf(string, format, &c5, &n3, &c6, &c7, &n4, &c8);
  ck_assert_int_eq(c1, c5);
  ck_assert_int_eq(c2, c6);
  ck_assert_int_eq(c3, c7);
  ck_assert_int_eq(c4, c8);
  ck_assert_int_eq(n1, n3);
  ck_assert_int_eq(n2, n4);
  ck_assert_int_eq(res1, res2);

  int v1 = 0, v2 = 0, v3 = 0, v4 = 0;
  short int q1, q2;
  long int q3, q4;
  format = "%d%ln%d%hn";
  string = "128948 0124 8190284";
  res1 = s21_sscanf(string, format, &v1, &q3, &v3, &q1);
  res2 = sscanf(string, format, &v2, &q4, &v4, &q2);
  ck_assert_int_eq(v1, v2);
  ck_assert_int_eq(q3, q4);
  ck_assert_int_eq(v3, v4);
  ck_assert_int_eq(q1, q2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(PERCENT_SPECIFIER) {
  char *format = "%d%%%d%d%%%d";
  char *string = "125 % 389 92 % 10";
  int a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  int res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  int res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%d%%%d%d%%%d";
  string = "10%20 30% 125 98";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%%%d%%%d%d%%%d";
  string = "%125 % 389 92 % 10";
  a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a2, b2);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(res1, res2);

  format = "%%%%";
  string = "%%";
  res1 = s21_sscanf(string, format, 0);
  res2 = sscanf(string, format, 0);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(s21_memchr_tests_case) {
  char *str = "string";
  char *str1 = "0123456789";
  char *str2 = "Hello world";
  ck_assert_str_eq(memchr(str, 's', 6), s21_memchr(str, 's', 6));
  ck_assert_str_eq(memchr(str, 'g', 100), s21_memchr(str, 'g', 100));
  ck_assert_str_eq(memchr(str1, '6', 10), s21_memchr(str1, '6', 10));
  ck_assert_str_eq(memchr(str2, 101, 10), s21_memchr(str2, 101, 10));
}
END_TEST

START_TEST(s21_memcmp_tests_case_1) {
  char *str = "Hello world";
  char *str1 = "Hello world";
  ck_assert_int_eq(memcmp(str, str1, 2), s21_memcmp(str, str1, 2));
}
END_TEST

START_TEST(s21_memcmp_tests_case_2) {
  char *str = "Hellaworld";
  char *str1 = "Helloworld";
  ck_assert_int_eq(memcmp(str, str1, 120), s21_memcmp(str, str1, 120));
}
END_TEST

START_TEST(s21_memcmp_tests_case_3) {
  char *str = "Hello\0wo\0ld";
  char *str1 = "Hello\0wo\0ld";
  ck_assert_int_eq(memcmp(str, str1, 6), s21_memcmp(str, str1, 6));
}
END_TEST

START_TEST(s21_memcmp_tests_case_4) {
  char *str = "Helo\0wo\0ld";
  char *str1 = "Hello\0wo\0ld";
  ck_assert_int_eq(memcmp(str, str1, 8), s21_memcmp(str, str1, 8));
}
END_TEST

START_TEST(s21_memcmp_tests_case_5) {
  char *str = "Hello\0w2\0ld";
  char *str1 = "Hello\0wo\0ld";
  ck_assert_int_eq(memcmp(str, str1, 8), s21_memcmp(str, str1, 8));
}
END_TEST

START_TEST(s21_memcmp_tests_case_6) {
  char *str = "\0Hallo\0w2\0ld";
  char *str1 = "\0Hello\0wo\0ld";
  ck_assert_int_eq(memcmp(str, str1, 15), s21_memcmp(str, str1, 15));
}
END_TEST

START_TEST(s21_memcmp_tests_case_7) {
  char *str = "\0\0\0";
  char *str1 = "\0\0\0";
  ck_assert_int_eq(memcmp(str, str1, 2), s21_memcmp(str, str1, 2));
}
END_TEST

START_TEST(s21_memcmp_tests_case_8) {
  char *str = "\0";
  char *str1 = "\0";
  ck_assert_int_eq(memcmp(str, str1, 0), s21_memcmp(str, str1, 0));
}
END_TEST

START_TEST(s21_memcmp_tests_case_9) {
  char *str = "";
  char *str1 = "";
  ck_assert_int_eq(memcmp(str, str1, 1), s21_memcmp(str, str1, 1));
}
END_TEST

START_TEST(s21_memcmp_tests_case_10) {
  char *str = "\0";
  char *str1 = " ";
  ck_assert_int_eq(memcmp(str, str1, 6), s21_memcmp(str, str1, 6));
}
END_TEST

START_TEST(s21_memcpy_tests_case) {
  char dest1[15] = "1234567890";
  char dest2[15] = "1234567890";
  char src[10] = "asdfdads";
  memcpy(dest1, src, 10);
  s21_memcpy(dest2, src, 10);
  ck_assert_str_eq(dest1, dest2);

  char dest12[15] = "1234567890";
  char dest22[15] = "1234567890";
  memcpy(dest12, src, 1);
  s21_memcpy(dest22, src, 1);
  ck_assert_str_eq(dest12, dest22);
}
END_TEST

START_TEST(s21_memset_tests_case) {
  char dest1[15] = "1234567890";
  char dest2[15] = "1234567890";
  memset(dest1, '1', 10);
  s21_memset(dest2, '1', 10);
  ck_assert_str_eq(dest1, dest2);
}
END_TEST

START_TEST(s21_strchr_tests_case_1) {
  char *str = "Hello world";
  ck_assert_str_eq(strchr(str, 'e'), s21_strchr(str, 'e'));
  ck_assert_str_eq(strchr(str, 'H'), s21_strchr(str, 'H'));
  ck_assert_str_eq(strchr(str, '\0'), s21_strchr(str, '\0'));
}
END_TEST

START_TEST(s21_strchr_tests_case_2) {
  char *str = "01234";
  ck_assert_str_eq(strchr(str, '0'), s21_strchr(str, '0'));
  ck_assert_str_eq(strchr(str, '4'), s21_strchr(str, '4'));
}
END_TEST

START_TEST(s21_strlen_tests_case_2) {
  char str1[] = "abc.defghij.kl";
  char str2[] = "./i";
  char str3[] = "abc.defghij.kl  addsa adsasd";
  char str4[] =
      "dajskljasd asd isadlj j dasdouisadousd ioas d,jads lkjaklsdj aei a ";
  ck_assert_int_eq(strlen(str1), s21_strlen(str1));
  ck_assert_int_eq(strlen(str2), s21_strlen(str2));
  ck_assert_int_eq(strlen(str3), s21_strlen(str3));
  ck_assert_int_eq(strlen(str4), s21_strlen(str4));
}
END_TEST

START_TEST(s21_strcpy_tests_case) {
  char dest1[15] = "1234567890";
  char dest2[15] = "1234567890";
  char src[10] = "abcdsfsda";
  strcpy(dest1, src);
  s21_strcpy(dest2, src);
  ck_assert_str_eq(dest1, dest2);
}
END_TEST

START_TEST(s21_strncpy_tests_case) {
  char dest1[15] = "";
  char dest2[15] = "";
  char src[15] = "ljkamfdng";
  s21_strncpy(dest2, src, 3);
  strncpy(dest1, src, 15);
  s21_strncpy(dest2, src, 15);
  ck_assert_str_eq(dest1, dest2);
}
END_TEST

START_TEST(s21_strcmp_tests_case_1) {
  char *str = "Hello world";
  char *str1 = "Hello world";
  ck_assert_int_eq(strcmp(str, str1), s21_strcmp(str, str1));
}
END_TEST

START_TEST(s21_strcmp_tests_case_2) {
  char *str = "Hellaworld";
  char *str1 = "Helloworld";
  ck_assert_int_eq(strcmp(str, str1), s21_strcmp(str, str1));
}
END_TEST

START_TEST(s21_strcmp_tests_case_3) {
  char *str = "Hello\0wo\0ld";
  char *str1 = "Hello\0wo\0ld";
  ck_assert_int_eq(strcmp(str, str1), s21_strcmp(str, str1));
}
END_TEST

START_TEST(s21_strcmp_tests_case_4) {
  char *str = "Helo\0wo\0ld";
  char *str1 = "Hello\0wo\0ld";
  ck_assert_int_eq(strcmp(str, str1), s21_strcmp(str, str1));
}
END_TEST

START_TEST(s21_strcmp_tests_case_5) {
  char *str = "Hello\0w2\0ld";
  char *str1 = "Hello\0wo\0ld";
  ck_assert_int_eq(strcmp(str, str1), s21_strcmp(str, str1));
}
END_TEST

START_TEST(s21_strcmp_tests_case_6) {
  char *str = "\0Hello\0w2\0ld";
  char *str1 = "\0Hello\0wo\0ld";
  ck_assert_int_eq(strcmp(str, str1), s21_strcmp(str, str1));
}
END_TEST

START_TEST(s21_strcmp_tests_case_7) {
  char *str = "\0\0\0";
  char *str1 = "\0\0\0";
  ck_assert_int_eq(strcmp(str, str1), s21_strcmp(str, str1));
}
END_TEST

START_TEST(s21_strcmp_tests_case_8) {
  char *str = "\0";
  char *str1 = "\0";
  ck_assert_int_eq(strcmp(str, str1), s21_strcmp(str, str1));
}
END_TEST

START_TEST(s21_strcmp_tests_case_9) {
  char *str = "";
  char *str1 = "";
  ck_assert_int_eq(strcmp(str, str1), s21_strcmp(str, str1));
}
END_TEST

START_TEST(s21_strcmp_tests_case_10) {
  char *str = "\0";
  char *str1 = " ";
  ck_assert_int_eq(strcmp(str, str1), s21_strcmp(str, str1));
}
END_TEST

START_TEST(s21_strncmp_tests_case_1) {
  char *str = "Hello world";
  char *str1 = "Hello world";
  ck_assert_int_eq(strncmp(str, str1, 2), s21_strncmp(str, str1, 2));
}
END_TEST

START_TEST(s21_strncmp_tests_case_2) {
  char *str = "Hellaworld";
  char *str1 = "Helloworld";
  ck_assert_int_eq(strncmp(str, str1, 120), s21_strncmp(str, str1, 120));
}
END_TEST

START_TEST(s21_strncmp_tests_case_3) {
  char *str = "Hello\0wo\0ld";
  char *str1 = "Hello\0wo\0ld";
  ck_assert_int_eq(strncmp(str, str1, 6), s21_strncmp(str, str1, 6));
}
END_TEST

START_TEST(s21_strncmp_tests_case_4) {
  char *str = "Helo\0wo\0ld";
  char *str1 = "Hello\0wo\0ld";
  ck_assert_int_eq(strncmp(str, str1, 8), s21_strncmp(str, str1, 8));
}
END_TEST

START_TEST(s21_strncmp_tests_case_5) {
  char *str = "Hello\0w2\0ld";
  char *str1 = "Hello\0wo\0ld";
  ck_assert_int_eq(strncmp(str, str1, 8), s21_strncmp(str, str1, 8));
}
END_TEST

START_TEST(s21_strncmp_tests_case_6) {
  char *str = "\0Hallo\0w2\0ld";
  char *str1 = "\0Hello\0wo\0ld";
  ck_assert_int_eq(strncmp(str, str1, 15), s21_strncmp(str, str1, 15));
}
END_TEST

START_TEST(s21_strncmp_tests_case_7) {
  char *str = "\0\0\0";
  char *str1 = "\0\0\0";
  ck_assert_int_eq(strncmp(str, str1, 2), s21_strncmp(str, str1, 2));
}
END_TEST

START_TEST(s21_strncmp_tests_case_8) {
  char *str = "\0";
  char *str1 = "\0";
  ck_assert_int_eq(strncmp(str, str1, 0), s21_strncmp(str, str1, 0));
}
END_TEST

START_TEST(s21_strncmp_tests_case_9) {
  char *str = "";
  char *str1 = "";
  ck_assert_int_eq(strncmp(str, str1, 1), s21_strncmp(str, str1, 1));
}
END_TEST

START_TEST(s21_strncmp_tests_case_10) {
  char *str = "\0";
  char *str1 = " ";
  ck_assert_int_eq(strncmp(str, str1, 6), s21_strncmp(str, str1, 6));
}
END_TEST

START_TEST(s21_strstr_tests_case_1) {
  char *str = "Hello world";
  char *find = "el";
  ck_assert_str_eq(strstr(str, find), s21_strstr(str, find));
}
END_TEST

START_TEST(s21_strstr_tests_case_2) {
  char *str = "Hello world";
  char *find = "\0";
  ck_assert_str_eq(strstr(str, find), s21_strstr(str, find));
}
END_TEST

START_TEST(s21_strstr_tests_case_3) {
  char *str = "Hello world";
  char *find = "d";
  ck_assert_str_eq(strstr(str, find), s21_strstr(str, find));
}
END_TEST

START_TEST(s21_strstr_tests_case_4) {
  char *str = "Hello world";
  char *find = "Hello world";
  ck_assert_str_eq(strstr(str, find), s21_strstr(str, find));
}
END_TEST

START_TEST(s21_strstr_tests_case_5) {
  char *str = "012345678";
  char *find = "56";
  ck_assert_str_eq(strstr(str, find), s21_strstr(str, find));
}
END_TEST

START_TEST(s21_strstr_tests_case_6) {
  char *str = "!@#$%^&*(";
  char *find = "$%";
  ck_assert_str_eq(strstr(str, find), s21_strstr(str, find));
}
END_TEST

START_TEST(s21_strcat_tests_case_1) {
  char str_des1[30] = "Hello world";
  char str_des2[30] = "Hello world";
  char str1[] = "Hello world";
  ck_assert_str_eq(strcat(str_des1, str1), s21_strcat(str_des2, str1));
}
END_TEST

START_TEST(s21_strcat_tests_case_2) {
  char str_des1[30] = "Hello world";
  char str_des2[30] = "Hello world";
  char str1[] = "Helloworld";
  ck_assert_str_eq(strcat(str_des1, str1), s21_strcat(str_des2, str1));
}
END_TEST

START_TEST(s21_strcat_tests_case_3) {
  char str[30] = "Hello\0wo\0ld";
  char str1[] = "Hello\0wo\0ld";
  ck_assert_str_eq(strcat(str, str1), s21_strcat(str, str1));
}
END_TEST

START_TEST(s21_strcat_tests_case_4) {
  char str[30] = "Helo\0wo\0ld";
  char str1[] = "Hello\0wo\0ld";
  ck_assert_str_eq(strcat(str, str1), s21_strcat(str, str1));
}
END_TEST

START_TEST(s21_strcat_tests_case_5) {
  char str[30] = "Hello\0w2\0ld";
  char str1[] = "Hello\0wo\0ld";
  ck_assert_str_eq(strcat(str, str1), s21_strcat(str, str1));
}
END_TEST

START_TEST(s21_strcat_tests_case_6) {
  char str[30] = "\0Hello\0w2\0ld";
  char str1[] = "\0Hello\0wo\0ld";
  ck_assert_str_eq(strcat(str, str1), s21_strcat(str, str1));
}
END_TEST

START_TEST(s21_strcat_tests_case_7) {
  char str[30] = "\0\0\0";
  char str1[] = "\0\0\0";
  ck_assert_str_eq(strcat(str, str1), s21_strcat(str, str1));
}
END_TEST

START_TEST(s21_strcat_tests_case_8) {
  char str[30] = "\0";
  char str1[] = "\0";
  ck_assert_str_eq(strcat(str, str1), s21_strcat(str, str1));
}
END_TEST

START_TEST(s21_strcat_tests_case_9) {
  char str[30] = "";
  char str1[] = "";
  ck_assert_str_eq(strcat(str, str1), s21_strcat(str, str1));
}
END_TEST

START_TEST(s21_strcat_tests_case_10) {
  char str[30] = "\0";
  char str1[] = " ";
  ck_assert_str_eq(strcat(str, str1), s21_strcat(str, str1));
}
END_TEST

START_TEST(s21_strncat_tests_case_1) {
  char str[30] = "Hello world";
  char str1[] = "Hello world";
  ck_assert_str_eq(strncat(str, str1, 5), s21_strncat(str, str1, 5));
}
END_TEST

START_TEST(s21_strncat_tests_case_2) {
  char str[100] = "Hellaworld";
  char str1[] = "Helloworld";
  ck_assert_str_eq(strncat(str, str1, 29), s21_strncat(str, str1, 29));
}
END_TEST

START_TEST(s21_strncat_tests_case_3) {
  char str[30] = "Hello\0wo\0ld";
  char str1[] = "Hello\0wo\0ld";
  ck_assert_str_eq(strncat(str, str1, 0), s21_strncat(str, str1, 0));
}
END_TEST

START_TEST(s21_strncat_tests_case_4) {
  char str[30] = "Helo\0wo\0ld";
  char str1[] = "Hello\0wo\0ld";
  ck_assert_str_eq(strncat(str, str1, 20), s21_strncat(str, str1, 20));
}
END_TEST

START_TEST(s21_strncat_tests_case_5) {
  char str[30] = "Hello\0w2\0ld";
  char str1[] = "Hello\0wo\0ld";
  ck_assert_str_eq(strncat(str, str1, 6), s21_strncat(str, str1, 6));
}
END_TEST

START_TEST(s21_strncat_tests_case_6) {
  char str[30] = "\0Hello\0w2\0ld";
  char str1[] = "\0Hello\0wo\0ld";
  ck_assert_str_eq(strncat(str, str1, 6), s21_strncat(str, str1, 6));
}
END_TEST

START_TEST(s21_strncat_tests_case_7) {
  char str[30] = "\0\0\0";
  char str1[] = "\0\0\0";
  ck_assert_str_eq(strncat(str, str1, 6), s21_strncat(str, str1, 6));
}
END_TEST

START_TEST(s21_strncat_tests_case_8) {
  char str[30] = "\0";
  char str1[] = "\0";
  ck_assert_str_eq(strncat(str, str1, 3), s21_strncat(str, str1, 3));
}
END_TEST

START_TEST(s21_strncat_tests_case_9) {
  char str[30] = "";
  char str1[] = "";
  ck_assert_str_eq(strncat(str, str1, 2), s21_strncat(str, str1, 2));
}
END_TEST

START_TEST(s21_strncat_tests_case_10) {
  char str[30] = "\0";
  char str1[] = " ";
  ck_assert_str_eq(strncat(str, str1, 1), s21_strncat(str, str1, 1));
}
END_TEST

START_TEST(s21_strpbrk_tests_case_1) {
  char *str = "Hello world";
  char *find = "world";
  ck_assert_str_eq(strpbrk(str, find), s21_strpbrk(str, find));
}
END_TEST

START_TEST(s21_strpbrk_tests_case_2) {
  char *str = "Hello world";
  char *find = "H";
  ck_assert_str_eq(strpbrk(str, find), s21_strpbrk(str, find));
}
END_TEST

START_TEST(s21_strpbrk_tests_case_3) {
  char *str = "Hello world";
  char *find = "he";
  ck_assert_str_eq(strpbrk(str, find), s21_strpbrk(str, find));
}
END_TEST

START_TEST(s21_strpbrk_tests_case_4) {
  char *str = "Hello world";
  char *find = "d\n";
  ck_assert_str_eq(strpbrk(str, find), s21_strpbrk(str, find));
}
END_TEST

START_TEST(s21_strpbrk_tests_case_5) {
  char *str = "School21";
  char *find = "21";
  ck_assert_str_eq(strpbrk(str, find), s21_strpbrk(str, find));
}
END_TEST

START_TEST(s21_strrchr_tests_case_1) {
  char *str = "Hello world";
  ck_assert_str_eq(strrchr(str, 'l'), s21_strrchr(str, 'l'));
}
END_TEST

START_TEST(s21_strrchr_tests_case_2) {
  char *str = "Hello world";
  ck_assert_str_eq(strrchr(str, '\0'), s21_strrchr(str, '\0'));
}
END_TEST

START_TEST(s21_strrchr_tests_case_3) {
  char *str = "Hello world";
  ck_assert_str_eq(strrchr(str, 'H'), s21_strrchr(str, 'H'));
}
END_TEST

START_TEST(s21_strrchr_tests_case_4) {
  char *str = "School21";
  ck_assert_str_eq(strrchr(str, '2'), strrchr(str, '2'));
}
END_TEST

START_TEST(s21_strrchr_tests_case_5) {
  char *str = "9990009";
  ck_assert_str_eq(strrchr(str, '9'), s21_strrchr(str, '9'));
}
END_TEST

START_TEST(s21_strcspn_tests_case) {
  char str1[] = "abc.defghij.kl";
  char str2[] = "./i";
  char str3[] = "..abc.defghij.kl  addsa adsasd";
  char str4[] =
      "dajskljasd asd isadlj j dasdouisadousd ioas d,jads lkjaklsdj aei a ";
  char str5[] = ".////iiii/.....////iiiiiid///";
  char str6[] = "";
  ck_assert_int_eq(strcspn(str1, str2), s21_strcspn(str1, str2));
  ck_assert_int_eq(strcspn(str2, str2), s21_strcspn(str2, str2));
  ck_assert_int_eq(strcspn(str3, str2), s21_strcspn(str3, str2));
  ck_assert_int_eq(strcspn(str4, str2), s21_strcspn(str4, str2));
  ck_assert_int_eq(strcspn(str5, str2), s21_strcspn(str5, str2));
  ck_assert_int_eq(strcspn(str1, str6), s21_strcspn(str1, str6));
}
END_TEST

START_TEST(s21_strtok_tests_case) {
  char str1[] = "abc.defghij.kl.aasddsaasd";
  char str2[] = "./i";
  char str3[] = "abc.defghij.kl.aasddsaasd";
  ck_assert_pstr_eq(strtok(str1, str2), s21_strtok(str3, str2));
  ck_assert_pstr_eq(strtok(S21_NULL, str2), s21_strtok(S21_NULL, str2));
  ck_assert_pstr_eq(strtok(S21_NULL, str2), s21_strtok(S21_NULL, str2));
  ck_assert_pstr_eq(strtok(S21_NULL, ""), s21_strtok(S21_NULL, ""));
}
END_TEST

START_TEST(s21_strspn_tests_case) {
  char str1[] = "abc.defghij.kl";
  char str2[] = "./i";
  char str3[] = "..abc.defghij.kl  addsa adsasd";
  char str4[] =
      "dajskljasd asd isadlj j dasdouisadousd ioas d,jads lkjaklsdj aei a ";
  char str5[] = ".////iiii/.....////iiiiiid///";
  char str6[] = "";
  ck_assert_int_eq(strspn(str1, str2), s21_strspn(str1, str2));
  ck_assert_int_eq(strspn(str2, str2), s21_strspn(str2, str2));
  ck_assert_int_eq(strspn(str3, str2), s21_strspn(str3, str2));
  ck_assert_int_eq(strspn(str4, str2), s21_strspn(str4, str2));
  ck_assert_int_eq(strspn(str5, str2), s21_strspn(str5, str2));
  ck_assert_int_eq(strspn(str1, str6), s21_strspn(str1, str6));
}
END_TEST

START_TEST(s21_str_insert_tests_case) {
  char str1[] = "1234890";
  char str2[] = "567";
  char *str = S21_NULL;
  str = (char *)s21_insert(str1, str2, 4);
  ck_assert_pstr_eq(str, "1234567890");
  free(str);
  str = s21_insert(str1, str2, 100500);
  ck_assert_pstr_eq(str, S21_NULL);
  free(str);
  str = s21_insert(str1, str2, -2);
  ck_assert_pstr_eq(str, S21_NULL);
  free(str);
  str = s21_insert("", str2, 0);
  ck_assert_pstr_eq(str, "567");
  free(str);
  str = s21_insert("", "", 0);
  ck_assert_pstr_eq(str, "");
  // free(str);
  str = s21_insert(str1, "", 4);
  ck_assert_pstr_eq(str, "1234890");
  free(str);
}
END_TEST

START_TEST(s21_str_to_lower_tests_case) {
  char str1[] = "ONCHLJBaYV";
  char str2[] = "KvCfcdgBBb";
  char str3[] = "czhEwtIGDI";
  char str4[] = "12345678";
  char str5[] = "\0abc";
  void *str;
  str = s21_to_lower(str1);
  ck_assert_pstr_eq(str, "onchljbayv");
  free(str);
  str = s21_to_lower(str2);
  ck_assert_pstr_eq(str, "kvcfcdgbbb");
  free(str);
  str = s21_to_lower(str3);
  ck_assert_pstr_eq(str, "czhewtigdi");
  free(str);
  str = s21_to_lower(str4);
  ck_assert_pstr_eq(str, "12345678");
  free(str);
  str = s21_to_lower(str5);
  ck_assert_pstr_eq(str, "");
  free(str);
}
END_TEST

START_TEST(s21_str_to_upper_tests_case) {
  char str1[] = "ONCHLJBaYV";
  char str2[] = "KvCfcdgBBb";
  char str3[] = "czhEwtIGDI";
  char str4[] = "12345678";
  char str5[] = "\0abc";
  void *str;
  str = s21_to_upper(str1);
  ck_assert_pstr_eq(str, "ONCHLJBAYV");
  free(str);
  str = s21_to_upper(str2);
  ck_assert_pstr_eq(str, "KVCFCDGBBB");
  free(str);
  str = s21_to_upper(str3);
  ck_assert_pstr_eq(str, "CZHEWTIGDI");
  free(str);
  str = s21_to_upper(str4);
  ck_assert_pstr_eq(str, "12345678");
  free(str);
  str = s21_to_upper(str5);
  ck_assert_pstr_eq(str, "");
  free(str);
}
END_TEST

START_TEST(s21_str_trim_tests_case) {
  void *str;
  str = s21_trim("12345678", "127");
  ck_assert_pstr_eq(str, "345678");
  free(str);
  str = s21_trim("abracadabra", "ab");
  ck_assert_pstr_eq(str, "racadabr");
  free(str);
  str = s21_trim("", "456");
  ck_assert_pstr_eq(str, "");
  str = s21_trim("AAAAAAAAAA", "A");
  ck_assert_pstr_eq(str, "");
  str = s21_trim("keep trying", "12345678");
  ck_assert_pstr_eq(str, "keep trying");
  free(str);
  str = s21_trim("            remove spaces        ", " ");
  ck_assert_pstr_eq(str, "remove spaces");
  free(str);
  str = s21_trim("u dare change me?", "");
  ck_assert_pstr_eq(str, "u dare change me?");
  free(str);
}
END_TEST

START_TEST(U_notwork) {
  unsigned short int a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0,
                     b4 = 0;
  char format[] = "%1hu%10hu%5hu%3hu";
  char string[] = "-891 78 -1 +2";
  int res1 = s21_sscanf(string, format, &a1, &a2, &a3, &a4);
  int res2 = sscanf(string, format, &b1, &b2, &b3, &b4);
  ck_assert_uint_eq(a1, b1);
  ck_assert_uint_eq(a2, b2);
  ck_assert_uint_eq(a3, b3);
  ck_assert_uint_eq(a4, b4);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sprintf_simple_int) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "This is a simple value %d";
  int val = 69;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_precise_int) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%.5i";
  int val = 69;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_width_int) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%5d";
  int val = 69;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_minus_width_int) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%-5i";
  int val = 69;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_plus_width_int) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%+12d";
  int val = 69;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_padding_int) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%012i";
  int val = 69;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_star_precision_int) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%0.*i";
  int val = 69;
  ck_assert_int_eq(s21_sprintf(str1, format, 5, val),
                   sprintf(str2, format, 5, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_many_flags_many_ints) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char format[] = "%0.*i %d %4.*i %013d %d";
  int val = 69;
  ck_assert_int_eq(
      s21_sprintf(str1, format, 5, val, -10431, 13, 5311, 0, -581813581),
      sprintf(str2, format, 5, val, -10431, 13, 5311, 0, -581813581));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_flags_long_int) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%+5.31li";
  long int val = 698518581899;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_flags_short_int) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%-16.9hi";
  short int val = 6958;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_flags_another_long_int) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%0.*ld";
  long val = 8581385185;
  ck_assert_int_eq(s21_sprintf(str1, format, 5, val),
                   sprintf(str2, format, 5, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_zero_precision_zero_int) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%.0d";
  int val = 0;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_space_flag_int) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "% d";
  int val = 0;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_unsigned_val) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%u";
  unsigned int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_unsigned_val_width) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%15u";
  unsigned int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_unsigned_val_flags) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%-16u";
  unsigned int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_unsigned_val_precision) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%.51u";
  unsigned int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_unsigned_val_many_flags) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "% 5.51u";
  unsigned int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_unsigned_val_short) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%hu";
  unsigned short int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_unsigned_val_long) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%lu";
  unsigned long int val = 949149114140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_unsigned_val_many) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%lu, %u, %hu, %.5u, %5.u";
  unsigned long int val = 949149114140;
  ck_assert_int_eq(
      s21_sprintf(str1, format, val, 14, 1441, 14414, 9681),
      sprintf(str2, format, val, (unsigned)14, (unsigned short)1441,
              (unsigned)14414, (unsigned)9681));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_octal_width) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%15o";
  int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_octal_flags) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%-16o";
  int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_octal_precision) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%.51o";
  int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_octal_many_flags) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%-5.51o";
  int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_octal_zero) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%o";
  ck_assert_int_eq(s21_sprintf(str1, format, 0), sprintf(str2, format, 0));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_octal_hash) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%#o";
  int val = 57175;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_octal_short) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%hd";
  short int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_octal_long) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%lo";
  long int val = 949149114140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_octal_many) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%lo, %o, %ho, %.5o, %5.o";
  long int val = 949149114140;
  ck_assert_int_eq(
      s21_sprintf(str1, format, val, 14, 1441, 14414, 9681),
      sprintf(str2, format, val, (unsigned)14, (unsigned short)1441,
              (unsigned)14414, (unsigned)9681));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_octal) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%lo";
  long int val = 84518;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_unsigned_zero) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%u";
  ck_assert_int_eq(s21_sprintf(str1, format, 0),
                   sprintf(str2, format, (unsigned)0));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_hex_width) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%5x";
  unsigned val = 858158158;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_hex_flags) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%#-10x";
  unsigned val = 858158158;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_hex_precision) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%.15x";
  unsigned val = 858158158;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_hex_many) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%#-10x%x%X%#x%#X%5.5x";
  unsigned val = 858158158;
  ck_assert_int_eq(s21_sprintf(str1, format, val, val, val, val, val, val),
                   sprintf(str2, format, val, val, val, val, val, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_hex_many_flags) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%#-5.10x";
  unsigned val = 858158158;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_hex_zero) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%#x";
  unsigned val = 0;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_hex_huge) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%#x";
  unsigned val = 18571;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_hex_short) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%#hx";
  unsigned short val = 12352;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_hex_long) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%#lx";
  unsigned long val = 18571757371571;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_hex_one_longer_width) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%#2x";
  unsigned val = 1;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_hex_two_longer_width) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%#30x";
  unsigned val = 1;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_one_char) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%c";
  char val = 'X';
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(sprintf_one_precision) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%.5c";
  char val = 'c';
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_one_flags) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "% -5c";
  char val = 'c';
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_one_width) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%15c";
  char val = 'c';
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_one_many) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%-5.3c%c%c%c%c Hello! ABOBA";
  char val = 'c';
  ck_assert_int_eq(s21_sprintf(str1, format, val, 'c', 'a', 'b', 'b'),
                   sprintf(str2, format, val, 'c', 'a', 'b', 'b'));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_one_many_flags) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%-5.3c";
  char val = 'c';
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_string) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%s";
  char *val = "I LOVE STRINGS AND TESTS AND SCHOOL21 NO JOKE";
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_string_precision) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%.15s";
  char *val = "I LOVE STRINGS AND TESTS AND SCHOOL21 NO JOKE";
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_string_width) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%15s";
  char *val = "69 IS MY FAVORITE NUMBER";
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_string_flags) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%-15.9s";
  char *val = "69 IS MY FAVORITE NUMBER";
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_string_long) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%s";
  char *val =
      "69 IS MY FAVORITE NUMBER THIS IS SUPPOSED TO BE A VERY LONG STRING";
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_string_many) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%s%s%s%s";
  char *val =
      "69 IS MY FAVORITE NUMBER THIS IS SUPPOSED TO BE A VERY LONG STRING";
  char *s1 = "";
  char *s2 = "87418347813748913749871389480913";
  char *s3 = "HAHAABOBASUCKER";
  ck_assert_int_eq(s21_sprintf(str1, format, val, s1, s2, s3),
                   sprintf(str2, format, val, s1, s2, s3));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_ptr) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%p";
  ck_assert_int_eq(s21_sprintf(str1, format, format),
                   sprintf(str2, format, format));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_ptr_width) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%15p";
  ck_assert_int_eq(s21_sprintf(str1, format, format),
                   sprintf(str2, format, format));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_ptr_precision) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%.5p";
  ck_assert_int_eq(s21_sprintf(str1, format, format),
                   sprintf(str2, format, format));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_null_ptr) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%p";
  char *ptr = s21_NULL;
  ck_assert_int_eq(s21_sprintf(str1, format, ptr), sprintf(str2, format, ptr));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_string_width_huge) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *val = "kjafdiuhfjahfjdahf";
  char *format = "%120s";
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_n_specifier) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  int ret = 0;
  char *format = "Hello, my sexy little aboba abobushka abobina %n";
  ck_assert_int_eq(s21_sprintf(str1, format, &ret),
                   sprintf(str2, format, &ret));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_float_precision) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%Lf";
  long double val = 513515.131513515151351;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_float_width) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%10Lf";
  long double val = 15.35;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_float_precision_zero) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%.0Lf";
  long double val = 15.35;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_float_precision_empty) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%.Lf";
  long double val = 15.35;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_float_precision_huge) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%.15Lf";
  long double val = 15.35;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_float_precision_huge_negative) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%.15Lf";
  long double val = -15.35581134;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_float_huge) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%Lf";
  long double val = 72537572375.1431341;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_float_flags) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "% f";
  float val = 0;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_float_many) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "% .0f %.lf %Lf %f %lf %Lf";
  float val = 0;
  double val1 = 0;
  long double val2 = 3515315.153151;
  float val3 = 5.5;
  double val4 = 9851.51351;
  long double val5 = 95919539159.53151351131;
  ck_assert_int_eq(s21_sprintf(str1, format, val, val1, val2, val3, val4, val5),
                   sprintf(str2, format, val, val1, val2, val3, val4, val5));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_e_precision) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%.17Le";
  long double val = 15.35;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_e_precision_zero) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%.0Le";
  long double val = 15.35;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_e_precision_empty) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%.Le";
  long double val = 15.000009121;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(sprintf_e_precision_huge) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%.15Le";
  long double val = 0.000000000000000123;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_e_precision_huge_negative) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%.15Le";
  long double val = -15.35581134;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_e_huge) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%Le";
  long double val = 72537572375.1431341;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_e_flags) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%015E";
  float val = 0;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_e_width) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%15e";
  float val = 0;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_e_many) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "% .0e %.le %Le %e %le %Le";
  float val = 0;
  double val1 = 0;
  long double val2 = 3515315.153151;
  float val3 = 5.5;
  double val4 = 0.094913941;
  long double val5 = 95919539159.53151351131;
  ck_assert_int_eq(s21_sprintf(str1, format, val, val1, val2, val3, val4, val5),
                   sprintf(str2, format, val, val1, val2, val3, val4, val5));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_E_int) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%.17LE";
  long double val = 4134121;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_all_empty) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  ck_assert_int_eq(s21_sprintf(str1, "abc"), sprintf(str2, "abc"));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_empty_format_and_parameters) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "abc"), sprintf(str2, "abc"));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_one_char) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%c", '\t'), sprintf(str2, "%c", '\t'));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_many_char) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%c%c%c%c%c", '\t', '\n', '0', 'S', 's'),
                   sprintf(str2, "%c%c%c%c%c", '\t', '\n', '0', 'S', 's'));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_one_string) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%s", "Drop Sega PLS"),
                   sprintf(str2, "%s", "Drop Sega PLS"));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_many_string) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(
      s21_sprintf(str1, "%s%s%s%s%s", "Drop", " ", "Sega", " ", "PLS"),
      sprintf(str2, "%s%s%s%s%s", "Drop", " ", "Sega", " ", "PLS"));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_one_dec) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%d", 666), sprintf(str2, "%d", 666));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_many_dec) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%d%d%d%d", -999, 0, 666, -100),
                   sprintf(str2, "%d%d%d%d", -999, 0, 666, -100));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_one_int) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%i", -0), sprintf(str2, "%i", -0));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_many_int) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%i%i%i%i", -999, 0, 666, -100),
                   sprintf(str2, "%i%i%i%i", -999, 0, 666, -100));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_one_float) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  ck_assert_int_eq(s21_sprintf(str1, "%f", 0.0001),
                   sprintf(str2, "%f", 0.0001));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_many_float) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  ck_assert_int_eq(
      s21_sprintf(str1, "%f%f%f%f", -999.666, 0.0001, 666.999, -100.001),
      sprintf(str2, "%f%f%f%f", -999.666, 0.0001, 666.999, -100.001));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_one_unsigned_dec) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  ck_assert_int_eq(s21_sprintf(str1, "%u", 100),
                   sprintf(str2, "%u", (unsigned)100));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_many_unsigned_dec) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%u%u%u%u", 999, 0, 666, 100),
                   sprintf(str2, "%u%u%u%u", (unsigned)999, (unsigned)0,
                           (unsigned)666, (unsigned)100));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_one_char_with_alignment_left) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%8c", '\t'), sprintf(str2, "%8c", '\t'));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_one_char_with_alignment_right) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%-8c", '\t'),
                   sprintf(str2, "%-8c", '\t'));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_many_char_with_alignment) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(
      s21_sprintf(str1, "%3c%-11c%10c%-2c%c", '\t', '\n', '0', 'S', 's'),
      sprintf(str2, "%3c%-11c%10c%-2c%c", '\t', '\n', '0', 'S', 's'));

  ck_assert_str_eq(str1, str2);
}
END_TEST

// START HEX TEST
START_TEST(sprintf_test_one_hex_lower) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  ck_assert_int_eq(s21_sprintf(str1, "%x", (unsigned)INT32_MIN),
                   sprintf(str2, "%x", (unsigned)INT32_MIN));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%x", 0), sprintf(str2, "%x", 0));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%x", INT32_MAX),
                   sprintf(str2, "%x", INT32_MAX));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_one_hex_upper) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%X", (unsigned)INT32_MIN),
                   sprintf(str2, "%X", (unsigned)INT32_MIN));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%X", 0), sprintf(str2, "%x", 0));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%X", INT32_MAX),
                   sprintf(str2, "%X", INT32_MAX));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_many_hex_lower) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(
      s21_sprintf(str1, "%x%x%x%x%x", 12340987, 135, 0, -1230, -123213123),
      sprintf(str2, "%x%x%x%x%x", 12340987, 135, 0, -1230, -123213123));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_many_hex_upper) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(
      s21_sprintf(str1, "%X%X%X%X%X", 12340987, 135, 0, -1230, -123213123),
      sprintf(str2, "%X%X%X%X%X", 12340987, 135, 0, -1230, -123213123));
  ck_assert_str_eq(str1, str2);
}
END_TEST
// END HEX TEST

// START HEX WITH ALIGNMENT
START_TEST(sprintf_test_one_hex_lower_with_alignment_left) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%-3x", (unsigned)INT32_MIN),
                   sprintf(str2, "%-3x", (unsigned)INT32_MIN));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%-3x", 0), sprintf(str2, "%-3x", 0));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%-3x", INT32_MAX),
                   sprintf(str2, "%-3x", INT32_MAX));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_one_hex_lower_with_alignment_right) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%13x", (unsigned)INT32_MIN),
                   sprintf(str2, "%13x", (unsigned)INT32_MIN));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%13x", 0), sprintf(str2, "%13x", 0));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%13x", INT32_MAX),
                   sprintf(str2, "%13x", INT32_MAX));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_one_hex_upper_with_alignment_left) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%-60X", INT32_MIN),
                   sprintf(str2, "%-60X", (unsigned)INT32_MIN));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%-60X", 0), sprintf(str2, "%-60X", 0));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%-60X", INT32_MAX),
                   sprintf(str2, "%-60X", INT32_MAX));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_one_hex_upper_with_alignment_right) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%7X", (unsigned)INT32_MIN),
                   sprintf(str2, "%7X", (unsigned)INT32_MIN));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%7X", 0), sprintf(str2, "%7X", 0));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%7X", INT32_MAX),
                   sprintf(str2, "%7X", INT32_MAX));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_many_hex_lower_with_alignment) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(
      s21_sprintf(str1, "%2x%-7x%9x%11x%0x", 12340987, 100, 0, 1, -666999),
      sprintf(str2, "%2x%-7x%9x%11x%0x", 12340987, 100, 0, 1, -666999));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_many_hex_upper_with_alignment) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  ck_assert_int_eq(
      s21_sprintf(str1, "%2X%-7X%9X%11X%0X", 12340987, 100, 0, 1, -666999),
      sprintf(str2, "%2X%-7X%9X%11X%0X", 12340987, 100, 0, 1, -666999));
  ck_assert_str_eq(str1, str2);
}
END_TEST
// START HEX WITH ALIGNMENT

// START HEX TEST WITH #
START_TEST(sprintf_test_one_hex_with_hashtag) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%#x", INT32_MIN),
                   sprintf(str2, "%#x", (unsigned)INT32_MIN));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%#x", 0), sprintf(str2, "%#x", 0));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%#x", INT32_MAX),
                   sprintf(str2, "%#x", INT32_MAX));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_one_hex_upper_with_hashtag) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%#X", INT32_MIN),
                   sprintf(str2, "%#X", (unsigned)INT32_MIN));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%#X", 0), sprintf(str2, "%#X", 0));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%#X", INT32_MAX),
                   sprintf(str2, "%#X", INT32_MAX));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_many_hex_lower_with_hashtag_and_alignm) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(
      s21_sprintf(str1, "%#x%#x%3x%#32x%#-1x", 87, 1222224535, -13, -0,
                  123213123),
      sprintf(str2, "%#x%#x%3x%#32x%#-1x", 87, 1222224535, -13, -0, 123213123));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_many_hex_upper_with_hashtag_and_alignm) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(
      s21_sprintf(str1, "%#X%#X%3X%#32X%#-1X", 87, 1222224535, -13, -0,
                  123213123),
      sprintf(str2, "%#X%#X%3X%#32X%#-1X", 87, 1222224535, -13, -0, 123213123));
  ck_assert_str_eq(str1, str2);
}
END_TEST
// END HEX TEST WITH #

// START HEX TEST with width *
START_TEST(sprintf_test_one_hex_lower_with_width_star) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%*x", 11, INT32_MIN),
                   sprintf(str2, "%*x", 11, (unsigned)INT32_MIN));
  ck_assert_str_eq(str1, str2);

  ck_assert_int_eq(s21_sprintf(str1, "%*x", 11, 0),
                   sprintf(str2, "%*x", 11, 0));
  ck_assert_str_eq(str1, str2);

  ck_assert_int_eq(s21_sprintf(str1, "%*x", 11, INT32_MAX),
                   sprintf(str2, "%*x", 11, INT32_MAX));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_one_hex_upper_with_width_star) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%*X", 11, INT32_MIN),
                   sprintf(str2, "%*X", 11, (unsigned)INT32_MIN));
  ck_assert_str_eq(str1, str2);

  ck_assert_int_eq(s21_sprintf(str1, "%*X", 11, 0),
                   sprintf(str2, "%*X", 11, 0));
  ck_assert_str_eq(str1, str2);

  ck_assert_int_eq(s21_sprintf(str1, "%*X", 11, INT32_MAX),
                   sprintf(str2, "%*X", 11, INT32_MAX));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_many_hex_lower_with_width_star_and_align_and_hashtag) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%#*x%*x%-12x%3x%*x", 9, 127312897, 0, -1,
                               199, -123978, 3, -1251),
                   sprintf(str2, "%#*x%*x%-12x%3x%*x", 9, 127312897, -0, -1,
                           199, -123978, 3, -1251));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_many_hex_upper_with_width_star) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%#*X%*X%-12X%3X%*X", 9, 127312897, 0, -1,
                               199, -123978, 3, -1251),
                   sprintf(str2, "%#*X%*X%-12X%3X%*X", 9, 127312897, 0, -1, 199,
                           -123978, 3, -1251));
  ck_assert_str_eq(str1, str2);
}
END_TEST
// END HEX TEST WITH Width *

// START HEX TEST WITH precision
START_TEST(sprintf_test_one_hex_lower_with_precision) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  int a = s21_sprintf(str1, "%*.6x", 11, 0);
  int b = sprintf(str2, "%*.6x", 11, 0);
  ck_assert_int_eq(a, b);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_one_hex_upper_with_precision) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  int a = s21_sprintf(str1, "%*.6X", 11, INT32_MIN);
  int b = sprintf(str2, "%*.6X", 11, (unsigned)INT32_MIN);
  ck_assert_int_eq(a, b);
  ck_assert_str_eq(str1, str2);
}
END_TEST

// END HEX TEST WITH precision

// START HEX TEST WITH Length

START_TEST(sprintf_test_sprintf1) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%10ld";

  ck_assert_int_eq(s21_sprintf(str1, format, 1), sprintf(str2, format, 1));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf2) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%1.1f";

  ck_assert_int_eq(s21_sprintf(str1, format, 1.1), sprintf(str2, format, 1.1));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf3) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%8.3c";

  ck_assert_int_eq(s21_sprintf(str1, format, 'a'), sprintf(str2, format, 'a'));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf4) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%+5.5d aboba";

  int val = 10000;
  int a = s21_sprintf(str1, format, val);
  int b = sprintf(str2, format, val);
  ck_assert_int_eq(a, b);

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf6) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%7.7f";

  ck_assert_int_eq(s21_sprintf(str1, format, 11.123456),
                   sprintf(str2, format, 11.123456));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf7) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%7.4s";

  ck_assert_int_eq(s21_sprintf(str1, format, "aboba floppa"),
                   sprintf(str2, format, "aboba floppa"));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf8) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%6.6u";

  ck_assert_int_eq(s21_sprintf(str1, format, 12341151),
                   sprintf(str2, format, 12341151));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf9) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%li%ld%lu";

  ck_assert_int_eq(s21_sprintf(str1, format, 666666666666, 777, 111),
                   sprintf(str2, format, 666666666666, 777, 111));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf10) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%hi%hd%hu";

  ck_assert_int_eq(s21_sprintf(str1, format, 666, -777, 111),
                   sprintf(str2, format, 666, -777, 111));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf11) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%+li%+lu%+d%+lf";

  ck_assert_int_eq(s21_sprintf(str1, format, -123, 321, -5555, -1213.123),
                   sprintf(str2, format, -123, 321, -5555, -1213.123));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf12) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%-11.11li%-35.5lu%-3.5ld%33.19Lf";
  long double k = 333.33213;

  ck_assert_int_eq(
      s21_sprintf(str1, format, 66666666666, 5555555555, 44444444444, k),
      sprintf(str2, format, 66666666666, 5555555555, 44444444444, k));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf14) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "% 0.0li% 0.0lu% 0.0ld % 0.0lf";

  ck_assert_int_eq(s21_sprintf(str1, format, 1, 222, 33333333333, -166513.1232),
                   sprintf(str2, format, 1, 222, 33333333333, -166513.1232));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf15) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "% 0.0hi% 0.0hu% 0.0hd % 0.0hf";

  ck_assert_int_eq(s21_sprintf(str1, format, 1, 222, 33333333333, -166513.1232),
                   sprintf(str2, format, 1, 222, 33333333333, -166513.1232));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf16) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "% c";

  ck_assert_int_eq(s21_sprintf(str1, format, 'a'), sprintf(str2, format, 'a'));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf17) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "% s";

  ck_assert_int_eq(s21_sprintf(str1, format, "aboba likes floppa"),
                   sprintf(str2, format, "aboba likes floppa"));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf18) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "% s% c";

  ck_assert_int_eq(s21_sprintf(str1, format, "", 'f'),
                   sprintf(str2, format, "", 'f'));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf19) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%210s";

  ck_assert_int_eq(s21_sprintf(str1, format, "AHHAHAHA\0AHHAHAHAH"),
                   sprintf(str2, format, "AHHAHAHA\0AHHAHAHAH"));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf20) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%-115s";

  ck_assert_int_eq(s21_sprintf(str1, format, "Nick her"),
                   sprintf(str2, format, "Nick her"));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf24) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%+2.1c%+4.2d%+5.4i%+10.2f%+55.55s%+1.1u";

  ck_assert_int_eq(
      s21_sprintf(str1, format, 'f', 21, 42, 666.666,
                  "Lorem ipsum dolor sit amet. Aut quam ducimus.", 11),
      sprintf(str2, format, 'f', 21, 42, 666.666,
              "Lorem ipsum dolor sit amet. Aut quam ducimus.", 11));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf25) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%.f";

  ck_assert_int_eq(s21_sprintf(str1, format, 121.123),
                   sprintf(str2, format, 121.123));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf26) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%%";

  ck_assert_int_eq(s21_sprintf(str1, format), sprintf(str2, format));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf27) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%%%%%%%%";

  ck_assert_int_eq(s21_sprintf(str1, format), sprintf(str2, format));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf28) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  int n1;
  int n2;
  int a = s21_sprintf(str1, "%d%n", 123, &n1);
  int b = sprintf(str2, "%d%n", 123, &n2);

  ck_assert_int_eq(a, b);
  ck_assert_int_eq(n1, n2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf29) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%-.f";

  ck_assert_int_eq(s21_sprintf(str1, format, 111.111),
                   sprintf(str2, format, 111.111));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf30) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%-.1d";

  ck_assert_int_eq(s21_sprintf(str1, format, 111), sprintf(str2, format, 111));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf31) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%e";
  double x = 111;
  ck_assert_int_eq(s21_sprintf(str1, format, x), sprintf(str2, format, x));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf32) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%e%e%e%e";

  ck_assert_int_eq(s21_sprintf(str1, format, 11.111, 222.2222, 666., -555.125),
                   sprintf(str2, format, 11.111, 222.2222, 666., -555.125));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf33) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%Le";
  long double x = 122.1231;

  ck_assert_int_eq(s21_sprintf(str1, format, x), sprintf(str2, format, x));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf35) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%.10e";

  ck_assert_int_eq(s21_sprintf(str1, format, 111.184314818),
                   sprintf(str2, format, 111.184314818));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf36) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%5.3e%3.2e%lf";

  ck_assert_int_eq(s21_sprintf(str1, format, 0.000111, 111.555, 1.999),
                   sprintf(str2, format, 0.000111, 111.555, 1.999));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf37) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%E";

  ck_assert_int_eq(s21_sprintf(str1, format, 0.666666),
                   sprintf(str2, format, 0.666666));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf38) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%E%E%E";

  ck_assert_int_eq(s21_sprintf(str1, format, 0.0000999, 111.9999, 6.666),
                   sprintf(str2, format, 0.0000999, 111.9999, 6.666));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf39) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%e ABOBA %Lf %Lf %Le";
  long double c = 848181;
  long double a = 0.00000001;
  long double b = 1111111.11;
  ck_assert_int_eq(s21_sprintf(str1, format, 123.123, a, b, c),
                   sprintf(str2, format, 123.123, a, b, c));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf40) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%#e Floppa %#E%#f";

  ck_assert_int_eq(s21_sprintf(str1, format, 123.111, 0.0000999, 0.555),
                   sprintf(str2, format, 123.111, 0.0000999, 0.555));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf41) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%.Lf";
  long double a = 7.9418438184;

  ck_assert_int_eq(s21_sprintf(str1, format, a), sprintf(str2, format, a));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf42) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%#5p";
  int a = 5;
  ck_assert_int_eq(s21_sprintf(str1, format, &a), sprintf(str2, format, &a));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf43) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%.5o";

  ck_assert_int_eq(s21_sprintf(str1, format, 12345),
                   sprintf(str2, format, 12345));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf44) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%#5lX";
  long hex = 314818438141;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_g_trailing_zero) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%g";
  double hex = 0.50300;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_g_large) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%g";
  double hex = 5131.43141;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_g_small) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%g";
  double hex = 0.123000;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_g_precision) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%.5g";
  double hex = 0.123000;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_g_precision_zero) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%.0g";
  double hex = 0.123000;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_g_precision_missing) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%.g";
  double hex = 0.123000;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_g_many_zeroes_in_front) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%.g";
  double hex = 0.0004;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_g_one_zero) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%g";
  double hex = 0;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_g_zero) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%.5g";
  double hex = 0;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_g_mantiss) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%g";
  double hex = 0.0000005;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_g_mantiss_flags) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%5.8g";
  double hex = 0.0000005;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_g_short_no_mantiss) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%g";
  double hex = 0.005;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_LG) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%LG";
  long double hex = 0.000005;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_g_many) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%LG %g %G %Lg %.5g";
  long double hex = 0.000005;
  double hex1 = 41.1341;
  double hex2 = 848.9000;
  long double hex3 = 0.0843;
  double hex4 = 0.0005;
  double hex5 = 0.8481481;
  ck_assert_int_eq(s21_sprintf(str1, format, hex, hex1, hex2, hex3, hex4, hex5),
                   sprintf(str2, format, hex, hex1, hex2, hex3, hex4, hex5));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_width_char) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "This is a simple wide char %5c";
  char w = 'c';
  int a = s21_sprintf(str1, format, w);
  int b = sprintf(str2, format, w);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(a, b);
}

int main() {
  Suite *s = suite_create("s21_string");
  TCase *tc = tcase_create("s21_string");
  SRunner *sr = srunner_create(s);
  int number_failed;
  suite_add_tcase(s, tc);
  tcase_add_test(tc, strlen_1);
  tcase_add_test(tc, strlen_2);
  tcase_add_test(tc, strlen_3);
  tcase_add_test(tc, strcat_1);
  tcase_add_test(tc, strcat_2);
  tcase_add_test(tc, strcat_3);
  tcase_add_test(tc, strcmp_1);
  tcase_add_test(tc, strcmp_2);
  tcase_add_test(tc, strcmp_3);
  tcase_add_test(tc, strncat_1);
  tcase_add_test(tc, strncat_2);
  tcase_add_test(tc, strncat_3);
  tcase_add_test(tc, strncmp_1);
  tcase_add_test(tc, strncmp_2);
  tcase_add_test(tc, strncmp_3);
  tcase_add_test(tc, strerror_1);
  tcase_add_test(tc, memcmp_1);
  tcase_add_test(tc, memcmp_2);
  tcase_add_test(tc, memcmp_3);
  tcase_add_test(tc, memset_1);
  tcase_add_test(tc, memset_2);
  tcase_add_test(tc, memset_3);
  tcase_add_test(tc, strcpy_1);
  tcase_add_test(tc, strcpy_2);
  tcase_add_test(tc, strcpy_3);
  tcase_add_test(tc, strncpy_1);
  tcase_add_test(tc, strncpy_2);
  tcase_add_test(tc, strncpy_3);
  tcase_add_test(tc, memcpy_1);
  tcase_add_test(tc, memcpy_2);
  tcase_add_test(tc, memcpy_3);
  tcase_add_test(tc, memcpy_4);
  tcase_add_test(tc, memmove_1);
  tcase_add_test(tc, memmove_2);
  tcase_add_test(tc, memmove_3);
  tcase_add_test(tc, memmove_4);
  tcase_add_test(tc, memchr_1);
  tcase_add_test(tc, memchr_2);
  tcase_add_test(tc, memchr_3);
  tcase_add_test(tc, strchr_1);
  tcase_add_test(tc, strchr_2);
  tcase_add_test(tc, strchr_3);
  tcase_add_test(tc, strrchr_1);
  tcase_add_test(tc, strrchr_2);
  tcase_add_test(tc, strrchr_3);
  tcase_add_test(tc, strrchr_4);
  tcase_add_test(tc, strrchr_5);
  tcase_add_test(tc, strcspn_1);
  tcase_add_test(tc, strcspn_2);
  tcase_add_test(tc, strcspn_3);
  tcase_add_test(tc, strspn_1);
  tcase_add_test(tc, strspn_2);
  tcase_add_test(tc, strspn_3);
  tcase_add_test(tc, strpbrk_1);
  tcase_add_test(tc, strpbrk_2);
  tcase_add_test(tc, strpbrk_3);
  tcase_add_test(tc, strstr_1);
  tcase_add_test(tc, strstr_2);
  tcase_add_test(tc, strstr_3);
  tcase_add_test(tc, strtok_1);
  tcase_add_test(tc, strtok_2);
  tcase_add_test(tc, strtok_3);
  tcase_add_test(tc, to_upper_1);
  tcase_add_test(tc, to_upper_2);
  tcase_add_test(tc, to_lower_1);
  tcase_add_test(tc, to_lower_2);
  tcase_add_test(tc, insert_1);
  tcase_add_test(tc, insert_2);
  tcase_add_test(tc, insert_3);
  tcase_add_test(tc, trim_1);
  tcase_add_test(tc, strlen_empty);
  tcase_add_test(tc, strlen_abosal);
  tcase_add_test(tc, strlen_num);
  tcase_add_test(tc, strlen_string);
  tcase_add_test(tc, strlen_abosal_no_dal);
  tcase_add_test(tc, strlen_dai_mne_pen);
  tcase_add_test(tc, strlen_Floppy_disk);
  tcase_add_test(tc, strlen_floppa);
  tcase_add_test(tc, strlen_kot_Vasily);
  tcase_add_test(tc, strlen_Russky_kot_Shlepa);

  tcase_add_test(tc, strncat_all_empty);
  tcase_add_test(tc, strncat_zero_byte);
  tcase_add_test(tc, strncat_empty_src);
  tcase_add_test(tc, strncat_cd_abosa);
  tcase_add_test(tc, strncat_string);
  tcase_add_test(tc, strncat_BIGFLOPPA);
  tcase_add_test(tc, strncat_BIGFLOPPA2);
  tcase_add_test(tc, strncat_BIGFLOPPA3);
  tcase_add_test(tc, strncat_BIGFLOPPA4);
  tcase_add_test(tc, strncat_zero_char);

  tcase_add_test(tc, strncmp_empty);
  tcase_add_test(tc, strncmp_floppa_);
  tcase_add_test(tc, strncmp__floppa);
  tcase_add_test(tc, strncmp_floppa_floppa);
  tcase_add_test(tc, strncmp_floppa_floppa_zero_byte);
  tcase_add_test(tc, strncmp_floppa_floppa_one_byte);

  tcase_add_test(tc, strrchr_empty);
  tcase_add_test(tc, strrchr_floppy_);
  tcase_add_test(tc, strrchr__floppy);
  tcase_add_test(tc, strrchr_poki_doki_o);
  tcase_add_test(tc, strrchr_poki_doki_i);
  tcase_add_test(tc, strrchr_poki_doki_p);
  tcase_add_test(tc, strrchr_find_big_P);
  tcase_add_test(tc, strrchr_find_zero);

  tcase_add_test(tc, strpbrk_empty);
  tcase_add_test(tc, strpbrk_floppy_);
  tcase_add_test(tc, strpbrk__floppy);
  tcase_add_test(tc, strpbrk_poki_doki_o);
  tcase_add_test(tc, strpbrk_poki_doki_i);
  tcase_add_test(tc, strpbrk_poki_doki_p);
  tcase_add_test(tc, strpbrk_find_big_P);
  tcase_add_test(tc, strpbrk_find_zero);

  tcase_add_test(tc, strspn_empty);
  tcase_add_test(tc, strspn_gora_);
  tcase_add_test(tc, strspn__gora);
  tcase_add_test(tc, strspn_any_register);
  tcase_add_test(tc, strspn_num_num);
  tcase_add_test(tc, strspn_long_num_num);
  tcase_add_test(tc, strspn_num_long_num);
  tcase_add_test(tc, strspn_any_num);
  tcase_add_test(tc, strspn_num_with_letter);
  tcase_add_test(tc, strspn_num_with_letter2);
  tcase_add_test(tc, strspn_basic_test);
  tcase_add_test(tc, strspn_any_sim);
  tcase_add_test(tc, strspn_upper_letter);
  tcase_add_test(tc, strspn_lower_letter);
  tcase_add_test(tc, strspn_not_uniq_sim);

  tcase_add_test(tc, strstr_empty_string_haystack_and_needle);
  tcase_add_test(tc, strstr_empty_string_haystack);
  tcase_add_test(tc, strstr_empty_string_needle);
  tcase_add_test(tc, strstr_toxic_test);
  tcase_add_test(tc, strstr_not_word_in_haystack);
  tcase_add_test(tc, strstr_words_with_any_register);
  tcase_add_test(tc, strstr_repeated_words);
  tcase_add_test(tc, strstr_word_at_end);
  tcase_add_test(tc, strstr_one_simbol_in_needle_and_haystack);
  tcase_add_test(tc, strstr_one_simbol_in_needle);
  tcase_add_test(tc, strstr_one_simbol_in_haystack);

  tcase_add_test(tc, strtok_correct_token_string);
  tcase_add_test(tc, strtok_unary_delimiters);
  tcase_add_test(tc, strtok_no_delims);
  tcase_add_test(tc, strtok_too_many_uses_non_segfault);
  tcase_add_test(tc, strtok_even_n_of_delims);
  tcase_add_test(tc, strtok_odd_n_of_delims);
  tcase_add_test(tc, strtok_mixed_n_of_delims);
  tcase_add_test(tc, strtok_hard_mixed);
  tcase_add_test(tc, strtok_mixed_hard_incorrect);
  tcase_add_test(tc, strtok_very_hard_mixed);

  tcase_add_test(tc, strncpy_empty);
  tcase_add_test(tc, strncpy_zero_byte);
  tcase_add_test(tc, strncpy_empty_src);
  tcase_add_test(tc, strncpy_one_byte);
  tcase_add_test(tc, strncpy_two_byte);
  tcase_add_test(tc, strncpy_string);

  tcase_add_test(tc, strcspn_empty);
  tcase_add_test(tc, strcspn_gora_);
  tcase_add_test(tc, strcspn__gora);
  tcase_add_test(tc, strcspn_any_register);
  tcase_add_test(tc, strcspn_num_num);
  tcase_add_test(tc, strcspn_long_num_num);
  tcase_add_test(tc, strcspn_num_long_num);
  tcase_add_test(tc, strcspn_any_num);
  tcase_add_test(tc, strcspn_num_with_letter);
  tcase_add_test(tc, strcspn_num_with_letter2);
  tcase_add_test(tc, strcspn_basic_test);
  tcase_add_test(tc, strcspn_any_sim);
  tcase_add_test(tc, strcspn_upper_letter);
  tcase_add_test(tc, strcspn_lower_letter);
  tcase_add_test(tc, strcspn_not_uniq_sim);

  tcase_add_test(tc, strcmp_Heloboba_Heloboba);
  tcase_add_test(tc, strcmp_HEloboba_Heloboba);
  tcase_add_test(tc, strcmp_Hel0boba_Helob0ba);
  tcase_add_test(tc, strcmp_Heloboba_);
  tcase_add_test(tc, strcmp__Heloboba);
  tcase_add_test(tc, strcmp_Heloboba);
  tcase_add_test(tc, strcmp_empty);
  tcase_add_test(tc, strcmp_only_num);

  tcase_add_test(tc, strchr_abobasnutsa_find_a);
  tcase_add_test(tc, strchr_abobasnutAsa_find_A);
  tcase_add_test(tc, strchr_abobasnutA1sa_find_1);
  tcase_add_test(tc, strchr_abobasnutAsa_find_Z);
  tcase_add_test(tc, strchr_abobasnutAsa_find_3);
  tcase_add_test(tc, strchr_empty_src);

  tcase_add_test(tc, strcpy_aboba_floppa);
  tcase_add_test(tc, strcpy__floppa);
  tcase_add_test(tc, strcpy_aboba_);
  tcase_add_test(tc, strcpy_empty);
  tcase_add_test(tc, strcpy_empty_num);
  tcase_add_test(tc, strcpy_hello);
  tcase_add_test(tc, strcpy_over_string);
  tcase_add_test(tc, strcpy_hard_test);

  tcase_add_test(tc, strcat_Hello_aboba);
  tcase_add_test(tc, strcat_zero_first);
  tcase_add_test(tc, strcat_zero_last);
  tcase_add_test(tc, strcat_any_letters_with_register);
  tcase_add_test(tc, strcat_any_letters_with_register_and_num);
  tcase_add_test(tc, strcat_any_letters_with_register_and_num_and_sim);

  tcase_add_test(tc, to_lower_test1);
  tcase_add_test(tc, to_lower_test2);
  tcase_add_test(tc, to_lower_test3);
  tcase_add_test(tc, to_lower_test4);
  tcase_add_test(tc, to_lower_test5);

  tcase_add_test(tc, trim_all_empty);
  tcase_add_test(tc, trim_str_empty);
  tcase_add_test(tc, trim_empty);
  tcase_add_test(tc, trim_and_str_eq);
  tcase_add_test(tc, trim_test1);
  tcase_add_test(tc, trim_test2);
  tcase_add_test(tc, trim_test3);
  tcase_add_test(tc, trim_test4);
  tcase_add_test(tc, trim_test5);
  tcase_add_test(tc, trim_empty_spaces);
  tcase_add_test(tc, trim_null_ptr_trim_chars);

  tcase_add_test(tc, to_upper_test1);
  tcase_add_test(tc, to_upper_test2);
  tcase_add_test(tc, to_upper_test3);
  tcase_add_test(tc, to_upper_test4);
  tcase_add_test(tc, to_upper_test5);

  tcase_add_test(tc, memcpy_hate_test);
  tcase_add_test(tc, memcpy_zero_test_string);
  tcase_add_test(tc, memcpy_any_empty);
  tcase_add_test(tc, memcpy_zero_test_string_with_register);
  tcase_add_test(tc, memcpy_zero_test_num);
  tcase_add_test(tc, memcpy_one_byte_string);
  tcase_add_test(tc, memcpy_one_byte_string_with_register);
  tcase_add_test(tc, memcpy_one_byte_num);
  tcase_add_test(tc, memcpy_basic_long_string);
  tcase_add_test(tc, memcpy_long_string_with_register);
  tcase_add_test(tc, memcpy_long_string_with_register_and_num);
  tcase_add_test(tc, memcpy_long_string_with_register_and_num_and_simbol);

  tcase_add_test(tc, memmove_empty_dest_and_src);
  tcase_add_test(tc, memmove_empty_dest);
  tcase_add_test(tc, memmove_empty_src);
  tcase_add_test(tc, memmove_write_in_left);
  tcase_add_test(tc, memmove_write_in_right);
  tcase_add_test(tc, memmove_write_in_mid);
  tcase_add_test(tc, memmove_overlap_write_in_left);
  tcase_add_test(tc, memmove_overlap_write_in_right);
  tcase_add_test(tc, memmove_overlap_write_in_mid);
  tcase_add_test(tc, memmove_zero_test_string);
  tcase_add_test(tc, memmove_any_empty);
  tcase_add_test(tc, memmove_zero_test_string_with_register);
  tcase_add_test(tc, memmove_zero_test_num);
  tcase_add_test(tc, memmove_one_byte_string);
  tcase_add_test(tc, memmove_one_byte_string_with_register);
  tcase_add_test(tc, memmove_one_byte_num);
  tcase_add_test(tc, memmove_basic_long_string);
  tcase_add_test(tc, memmove_long_string_with_register);
  tcase_add_test(tc, memmove_long_string_with_register_and_num);
  tcase_add_test(tc, memmove_long_string_with_register_and_num_and_simbol);
  tcase_add_test(tc, memmove_ints);
  tcase_add_test(tc, memmove_floats);
  tcase_add_test(tc, memmove_long_doubels);

  tcase_add_test(tc, memset_aboba_test);
  tcase_add_test(tc, memset_zero_byte);
  tcase_add_test(tc, memset_empty);
  tcase_add_test(tc, memset_replace_on_register_sim);
  tcase_add_test(tc, memset_replace_on_register_num);
  tcase_add_test(tc, memset_long_string);

  tcase_add_test(tc, memcmp_zero_byte);
  tcase_add_test(tc, memcmp_first_byte_in_string);
  tcase_add_test(tc, memcmp_register_test);
  tcase_add_test(tc, memcmp_zero_byte_in_num);
  tcase_add_test(tc, memcmp_first_byte_in_num);
  tcase_add_test(tc, memcmp_two_byte_in_num);
  tcase_add_test(tc, memcmp_two_byte_long_two_num);
  tcase_add_test(tc, memcmp_two_byte_long_first_num);
  tcase_add_test(tc, memcmp_eq_long_string);
  tcase_add_test(tc, memcmp_not_eq_long_string);

  tcase_add_test(tc, memchr_empty_str);
  tcase_add_test(tc, memchr_find_zero_in_string);
  tcase_add_test(tc, memchr_find_simbol_in_string_in_start);
  tcase_add_test(tc, memchr_find_simbol_in_string_in_end);
  tcase_add_test(tc, memchr_find_num_in_string_in_mid);
  tcase_add_test(tc, memchr_find_num_in_array_num);
  tcase_add_test(tc, memchr_find_float_in_array);
  tcase_add_test(tc, memchr_easy_test_string);

  tcase_add_test(tc, insert_test1);
  tcase_add_test(tc, insert_test2);
  tcase_add_test(tc, insert_test3);
  tcase_add_test(tc, insert_test4);
  tcase_add_test(tc, insert_test5);

  tcase_add_test(tc, s21_memchr_test);
  tcase_add_test(tc, s21_memcmp_test);
  tcase_add_test(tc, s21_strlen_test);
  tcase_add_test(tc, s21_strcpy_test);
  tcase_add_test(tc, s21_strcmp_test);
  tcase_add_test(tc, s21_strncmp_test);
  tcase_add_test(tc, s21_to_upper_test);
  tcase_add_test(tc, s21_to_lower_test);
  tcase_add_test(tc, s21_insert_test);
  tcase_add_test(tc, s21_trim_test);
  tcase_add_test(tc, s21_memcpy_test);
  tcase_add_test(tc, s21_memmove_test);
  tcase_add_test(tc, s21_memset_test);
  tcase_add_test(tc, s21_strcat_test);
  tcase_add_test(tc, s21_strncat_test);
  tcase_add_test(tc, s21_strpbrk_test);
  tcase_add_test(tc, s21_strncpy_test);
  tcase_add_test(tc, s21_strerror_test);
  tcase_add_test(tc, s21_strchr_test);
  tcase_add_test(tc, s21_strrchr_test);
  tcase_add_test(tc, s21_strspn_test);
  tcase_add_test(tc, s21_strcspn_test);
  tcase_add_test(tc, s21_strstr_test);
  tcase_add_test(tc, s21_strtok_test);
  tcase_add_test(tc, s21_sscanf_c_test);
  tcase_add_test(tc, s21_sscanf_d_test);
  tcase_add_test(tc, s21_sscanf_hd_test);
  tcase_add_test(tc, s21_sscanf_ld_test);
  tcase_add_test(tc, s21_sscanf_hu_test);
  tcase_add_test(tc, s21_sscanf_lu_test);
  tcase_add_test(tc, s21_sscanf_u_test);
  tcase_add_test(tc, s21_sscanf_different_shit_test);
  tcase_add_test(tc, test_to_lower_1);
  tcase_add_test(tc, test_to_lower_2);
  tcase_add_test(tc, test_to_lower_3);
  tcase_add_test(tc, test_to_lower_4);
  tcase_add_test(tc, test_to_lower_5);
  tcase_add_test(tc, test_to_lower_6);
  tcase_add_test(tc, test_to_lower_7);

  tcase_add_test(tc, sscanf_spec_n_1);
  tcase_add_test(tc, sscanf_spec_n_2);
  tcase_add_test(tc, sscanf_spec_n_3);
  tcase_add_test(tc, sscanf_spec_n_5);
  tcase_add_test(tc, sscanf_spec_n_6);
  tcase_add_test(tc, sscanf_spec_n_7);
  tcase_add_test(tc, sscanf_spec_n_8);
  tcase_add_test(tc, sscanf_spec_n_9);
  tcase_add_test(tc, sscanf_spec_n_10);

  tcase_add_test(tc, sscanf_spec_ho_1);
  tcase_add_test(tc, sscanf_spec_ho_2);
  tcase_add_test(tc, sscanf_spec_ho_3);
  tcase_add_test(tc, sscanf_spec_ho_4);
  tcase_add_test(tc, sscanf_spec_ho_5);
  tcase_add_test(tc, sscanf_spec_ho_6);
  tcase_add_test(tc, sscanf_spec_o_1);
  tcase_add_test(tc, sscanf_spec_o_2);
  tcase_add_test(tc, sscanf_spec_o_3);
  tcase_add_test(tc, sscanf_spec_o_4);
  tcase_add_test(tc, sscanf_spec_o_5);
  tcase_add_test(tc, sscanf_spec_o_6);
  tcase_add_test(tc, sscanf_spec_lo_1);
  tcase_add_test(tc, sscanf_spec_lo_2);
  tcase_add_test(tc, sscanf_spec_lo_3);
  tcase_add_test(tc, sscanf_spec_lo_4);
  tcase_add_test(tc, sscanf_spec_lo_5);
  tcase_add_test(tc, sscanf_spec_lo_6);

  tcase_add_test(tc, sscanf_spec_hx_1);
  tcase_add_test(tc, sscanf_spec_hx_2);
  tcase_add_test(tc, sscanf_spec_hx_3);
  tcase_add_test(tc, sscanf_spec_hx_4);
  tcase_add_test(tc, sscanf_spec_hx_5);
  tcase_add_test(tc, sscanf_spec_hx_6);
  tcase_add_test(tc, sscanf_spec_hx_7);
  tcase_add_test(tc, sscanf_spec_hx_8);
  tcase_add_test(tc, sscanf_spec_hx_9);
  tcase_add_test(tc, sscanf_spec_hx_10);
  tcase_add_test(tc, sscanf_spec_hx_11);
  tcase_add_test(tc, sscanf_spec_x_1);
  tcase_add_test(tc, sscanf_spec_x_2);
  tcase_add_test(tc, sscanf_spec_x_3);
  tcase_add_test(tc, sscanf_spec_x_4);
  tcase_add_test(tc, sscanf_spec_x_5);
  tcase_add_test(tc, sscanf_spec_x_6);
  tcase_add_test(tc, sscanf_spec_x_7);
  tcase_add_test(tc, sscanf_spec_x_8);
  tcase_add_test(tc, sscanf_spec_x_9);
  tcase_add_test(tc, sscanf_spec_x_10);
  tcase_add_test(tc, sscanf_spec_x_11);
  tcase_add_test(tc, sscanf_spec_lx_1);
  tcase_add_test(tc, sscanf_spec_lx_2);
  tcase_add_test(tc, sscanf_spec_lx_3);
  tcase_add_test(tc, sscanf_spec_lx_4);
  tcase_add_test(tc, sscanf_spec_lx_5);
  tcase_add_test(tc, sscanf_spec_lx_6);
  tcase_add_test(tc, sscanf_spec_lx_7);
  tcase_add_test(tc, sscanf_spec_lx_8);
  tcase_add_test(tc, sscanf_spec_lx_9);
  tcase_add_test(tc, sscanf_spec_lx_10);
  tcase_add_test(tc, sscanf_spec_lx_11);

  tcase_add_test(tc, sscanf_spec_c_2);
  tcase_add_test(tc, sscanf_spec_c_4);
  tcase_add_test(tc, sscanf_spec_c_5);
  tcase_add_test(tc, sscanf_spec_c_6);
  tcase_add_test(tc, sscanf_spec_c_7);
  tcase_add_test(tc, sscanf_spec_c_8);

  tcase_add_test(tc, sscanf_spec_hd_1);
  tcase_add_test(tc, sscanf_spec_hd_2);
  tcase_add_test(tc, sscanf_spec_hd_3);
  tcase_add_test(tc, sscanf_spec_hd_4);
  tcase_add_test(tc, sscanf_spec_hd_5);
  tcase_add_test(tc, sscanf_spec_hd_6);
  tcase_add_test(tc, sscanf_spec_hd_7);
  tcase_add_test(tc, sscanf_spec_hd_8);
  tcase_add_test(tc, sscanf_spec_hd_9);
  tcase_add_test(tc, sscanf_spec_hd_10);
  tcase_add_test(tc, sscanf_spec_hd_11);
  tcase_add_test(tc, sscanf_spec_hd_12);
  tcase_add_test(tc, sscanf_spec_hd_13);
  tcase_add_test(tc, sscanf_spec_hd_14);
  tcase_add_test(tc, sscanf_spec_hd_15);
  tcase_add_test(tc, sscanf_spec_hd_16);
  tcase_add_test(tc, sscanf_spec_hd_17);
  tcase_add_test(tc, sscanf_spec_hd_18);
  tcase_add_test(tc, sscanf_spec_hd_19);
  tcase_add_test(tc, sscanf_spec_hd_20);
  tcase_add_test(tc, sscanf_spec_hd_21);
  tcase_add_test(tc, sscanf_spec_hd_22);
  tcase_add_test(tc, sscanf_spec_hd_23);
  tcase_add_test(tc, sscanf_spec_hd_24);
  tcase_add_test(tc, sscanf_spec_hd_25);

  tcase_add_test(tc, sscanf_spec_d_1);
  tcase_add_test(tc, sscanf_spec_d_2);
  tcase_add_test(tc, sscanf_spec_d_3);
  tcase_add_test(tc, sscanf_spec_d_4);
  tcase_add_test(tc, sscanf_spec_d_5);
  tcase_add_test(tc, sscanf_spec_d_6);
  tcase_add_test(tc, sscanf_spec_d_7);
  tcase_add_test(tc, sscanf_spec_d_8);
  tcase_add_test(tc, sscanf_spec_d_9);
  tcase_add_test(tc, sscanf_spec_d_10);
  tcase_add_test(tc, sscanf_spec_d_11);
  tcase_add_test(tc, sscanf_spec_d_12);
  tcase_add_test(tc, sscanf_spec_d_13);
  tcase_add_test(tc, sscanf_spec_d_14);
  tcase_add_test(tc, sscanf_spec_d_15);
  tcase_add_test(tc, sscanf_spec_d_16);
  tcase_add_test(tc, sscanf_spec_d_17);
  tcase_add_test(tc, sscanf_spec_d_18);
  tcase_add_test(tc, sscanf_spec_d_19);
  tcase_add_test(tc, sscanf_spec_d_20);
  tcase_add_test(tc, sscanf_spec_d_21);
  tcase_add_test(tc, sscanf_spec_d_22);
  tcase_add_test(tc, sscanf_spec_d_23);

  tcase_add_test(tc, sscanf_spec_ld_1);
  tcase_add_test(tc, sscanf_spec_ld_2);
  tcase_add_test(tc, sscanf_spec_ld_3);
  tcase_add_test(tc, sscanf_spec_ld_4);
  tcase_add_test(tc, sscanf_spec_ld_5);
  tcase_add_test(tc, sscanf_spec_ld_6);
  tcase_add_test(tc, sscanf_spec_ld_7);
  tcase_add_test(tc, sscanf_spec_ld_8);
  tcase_add_test(tc, sscanf_spec_ld_9);
  tcase_add_test(tc, sscanf_spec_ld_10);
  tcase_add_test(tc, sscanf_spec_ld_11);
  tcase_add_test(tc, sscanf_spec_ld_12);
  tcase_add_test(tc, sscanf_spec_ld_13);
  tcase_add_test(tc, sscanf_spec_ld_14);
  tcase_add_test(tc, sscanf_spec_ld_15);
  tcase_add_test(tc, sscanf_spec_ld_16);
  tcase_add_test(tc, sscanf_spec_ld_17);
  tcase_add_test(tc, sscanf_spec_ld_18);
  tcase_add_test(tc, sscanf_spec_ld_19);
  tcase_add_test(tc, sscanf_spec_ld_20);
  tcase_add_test(tc, sscanf_spec_ld_21);
  tcase_add_test(tc, sscanf_spec_ld_22);
  tcase_add_test(tc, sscanf_spec_ld_23);
  tcase_add_test(tc, sscanf_spec_ld_24);
  tcase_add_test(tc, sscanf_spec_ld_25);
  tcase_add_test(tc, sscanf_spec_ld_26);
  tcase_add_test(tc, sscanf_spec_ld_27);

  tcase_add_test(tc, sscanf_empty_1);
  tcase_add_test(tc, sscanf_empty_2);
  tcase_add_test(tc, sscanf_empty_3);
  tcase_add_test(tc, sscanf_empty_4);
  tcase_add_test(tc, sscanf_empty_5);
  tcase_add_test(tc, sscanf_empty_6);
  tcase_add_test(tc, sscanf_empty_7);

  tcase_add_test(tc, sscanf_spec_p_1);
  tcase_add_test(tc, sscanf_spec_p_2);
  tcase_add_test(tc, sscanf_spec_p_3);
  tcase_add_test(tc, sscanf_spec_p_4);
  tcase_add_test(tc, sscanf_spec_p_5);
  tcase_add_test(tc, sscanf_spec_p_6);
  tcase_add_test(tc, sscanf_spec_p_7);
  tcase_add_test(tc, sscanf_spec_p_8);
  tcase_add_test(tc, sscanf_spec_p_10);
  tcase_add_test(tc, sscanf_spec_p_11);
  tcase_add_test(tc, sscanf_spec_p_12);
  tcase_add_test(tc, sscanf_spec_p_13);
  tcase_add_test(tc, sscanf_spec_p_14);
  tcase_add_test(tc, sscanf_spec_p_15);

  tcase_add_test(tc, sscanf_spec_real_1);
  tcase_add_test(tc, sscanf_spec_real_2);
  // tcase_add_test(tc, sscanf_spec_real_3);
  tcase_add_test(tc, sscanf_spec_real_4);
  tcase_add_test(tc, sscanf_spec_real_5);
  tcase_add_test(tc, sscanf_spec_real_6);
  tcase_add_test(tc, sscanf_spec_real_7);
  tcase_add_test(tc, sscanf_spec_real_8);
  tcase_add_test(tc, sscanf_spec_real_9);
  tcase_add_test(tc, sscanf_spec_real_10);
  tcase_add_test(tc, sscanf_spec_real_11);
  tcase_add_test(tc, sscanf_spec_real_12);
  tcase_add_test(tc, sscanf_spec_real_13);
  tcase_add_test(tc, sscanf_spec_real_14);
  tcase_add_test(tc, sscanf_spec_real_15);
  tcase_add_test(tc, sscanf_spec_real_18);
  tcase_add_test(tc, sscanf_spec_real_19);

  tcase_add_test(tc, sscanf_spec_i_dec_1);
  tcase_add_test(tc, sscanf_spec_i_dec_2);
  tcase_add_test(tc, sscanf_spec_i_dec_3);
  tcase_add_test(tc, sscanf_spec_i_dec_4);
  tcase_add_test(tc, sscanf_spec_i_dec_5);
  tcase_add_test(tc, sscanf_spec_i_dec_6);
  tcase_add_test(tc, sscanf_spec_i_dec_7);
  tcase_add_test(tc, sscanf_spec_i_dec_8);

  tcase_add_test(tc, sscanf_spec_i_oct_1);
  tcase_add_test(tc, sscanf_spec_i_oct_2);
  tcase_add_test(tc, sscanf_spec_i_oct_3);
  tcase_add_test(tc, sscanf_spec_i_oct_4);
  tcase_add_test(tc, sscanf_spec_i_oct_5);
  tcase_add_test(tc, sscanf_spec_i_oct_6);
  tcase_add_test(tc, sscanf_spec_i_oct_7);
  tcase_add_test(tc, sscanf_spec_i_oct_8);

  tcase_add_test(tc, sscanf_spec_i_hex_1);
  tcase_add_test(tc, sscanf_spec_i_hex_2);
  tcase_add_test(tc, sscanf_spec_i_hex_3);
  tcase_add_test(tc, sscanf_spec_i_hex_5);
  tcase_add_test(tc, sscanf_spec_i_hex_6);
  tcase_add_test(tc, sscanf_spec_i_hex_7);
  tcase_add_test(tc, sscanf_spec_i_hex_8);

  tcase_add_test(tc, sscanf_spec_hi_dec_1);
  tcase_add_test(tc, sscanf_spec_hi_dec_2);
  tcase_add_test(tc, sscanf_spec_hi_dec_3);
  tcase_add_test(tc, sscanf_spec_hi_dec_4);
  tcase_add_test(tc, sscanf_spec_hi_dec_5);
  tcase_add_test(tc, sscanf_spec_hi_dec_6);
  tcase_add_test(tc, sscanf_spec_hi_dec_7);
  tcase_add_test(tc, sscanf_spec_hi_dec_8);

  tcase_add_test(tc, sscanf_spec_hi_oct_1);
  tcase_add_test(tc, sscanf_spec_hi_oct_2);
  tcase_add_test(tc, sscanf_spec_hi_oct_3);
  tcase_add_test(tc, sscanf_spec_hi_oct_4);
  tcase_add_test(tc, sscanf_spec_hi_oct_5);
  tcase_add_test(tc, sscanf_spec_hi_oct_6);
  tcase_add_test(tc, sscanf_spec_hi_oct_7);
  tcase_add_test(tc, sscanf_spec_hi_oct_8);

  tcase_add_test(tc, sscanf_spec_hi_hex_1);
  tcase_add_test(tc, sscanf_spec_hi_hex_2);
  tcase_add_test(tc, sscanf_spec_hi_hex_3);
  tcase_add_test(tc, sscanf_spec_hi_hex_5);
  tcase_add_test(tc, sscanf_spec_hi_hex_6);
  tcase_add_test(tc, sscanf_spec_hi_hex_7);
  tcase_add_test(tc, sscanf_spec_hi_hex_8);

  tcase_add_test(tc, sscanf_spec_li_dec_1);
  tcase_add_test(tc, sscanf_spec_li_dec_2);
  tcase_add_test(tc, sscanf_spec_li_dec_3);
  tcase_add_test(tc, sscanf_spec_li_dec_4);
  tcase_add_test(tc, sscanf_spec_li_dec_5);
  tcase_add_test(tc, sscanf_spec_li_dec_6);
  tcase_add_test(tc, sscanf_spec_li_dec_7);
  tcase_add_test(tc, sscanf_spec_li_dec_8);

  tcase_add_test(tc, sscanf_spec_li_oct_1);
  tcase_add_test(tc, sscanf_spec_li_oct_2);
  tcase_add_test(tc, sscanf_spec_li_oct_3);
  tcase_add_test(tc, sscanf_spec_li_oct_4);
  tcase_add_test(tc, sscanf_spec_li_oct_5);
  tcase_add_test(tc, sscanf_spec_li_oct_6);
  tcase_add_test(tc, sscanf_spec_li_oct_7);
  tcase_add_test(tc, sscanf_spec_li_oct_8);

  tcase_add_test(tc, sscanf_spec_li_hex_1);
  tcase_add_test(tc, sscanf_spec_li_hex_2);
  tcase_add_test(tc, sscanf_spec_li_hex_3);
  tcase_add_test(tc, sscanf_spec_li_hex_5);
  tcase_add_test(tc, sscanf_spec_li_hex_6);
  tcase_add_test(tc, sscanf_spec_li_hex_7);
  tcase_add_test(tc, sscanf_spec_li_hex_8);

  tcase_add_test(tc, test_sscanf_int);
  tcase_add_test(tc, test_sscanf_float);
  tcase_add_test(tc, test_sscanf_string);
  tcase_add_test(tc, test_sscanf_skip_whitespaces);
  tcase_add_test(tc, test_sscanf_mixed_type);
  tcase_add_test(tc, test_sscanf_width_specifier);
  tcase_add_test(tc, test_sscanf_n_assignment);
  tcase_add_test(tc, test_sscanf_spec_i_int1);
  tcase_add_test(tc, test_sscanf_spec_i_int2);
  tcase_add_test(tc, test_sscanf_spec_i_int3);
  tcase_add_test(tc, test_sscanf_oct);
  tcase_add_test(tc, test_sscanf_hex);
  tcase_add_test(tc, s21_sscanf_test_17_o_option);
  tcase_add_test(tc, s21_sscanf_test_18_o_option);
  tcase_add_test(tc, s21_sscanf_test_19_u_option);

  tcase_add_test(tc, test_1_sscanf);
  tcase_add_test(tc, test_2_sscanf);
  tcase_add_test(tc, test_3_sscanf);
  tcase_add_test(tc, test_4_sscanf);
  tcase_add_test(tc, test_5_sscanf);
  tcase_add_test(tc, test_6_sscanf);
  tcase_add_test(tc, test_7_sscanf);
  tcase_add_test(tc, test_8_sscanf);
  tcase_add_test(tc, test_9_sscanf);
  tcase_add_test(tc, test_10_sscanf);
  tcase_add_test(tc, test_11_sscanf);
  tcase_add_test(tc, test_12_sscanf);
  tcase_add_test(tc, test_13_sscanf);
  tcase_add_test(tc, test_14_sscanf);
  tcase_add_test(tc, test_15_sscanf);
  tcase_add_test(tc, test_16_sscanf);
  tcase_add_test(tc, test_17_sscanf);
  tcase_add_test(tc, test_18_sscanf);
  tcase_add_test(tc, test_19_sscanf);
  tcase_add_test(tc, test_20_sscanf);
  tcase_add_test(tc, test_21_sscanf);
  tcase_add_test(tc, test_22_sscanf);
  tcase_add_test(tc, test_23_sscanf);
  tcase_add_test(tc, test_24_sscanf);
  tcase_add_test(tc, test_25_sscanf);
  tcase_add_test(tc, test_26_sscanf);
  tcase_add_test(tc, test_27_sscanf);
  tcase_add_test(tc, test_28_sscanf);
  tcase_add_test(tc, test_29_sscanf);
  tcase_add_test(tc, test_30_sscanf);
  tcase_add_test(tc, test_31_sscanf);
  tcase_add_test(tc, test_33_sscanf);
  tcase_add_test(tc, test_34_sscanf);
  tcase_add_test(tc, test_35_sscanf);
  tcase_add_test(tc, sscanf_spec_d_24);
  tcase_add_test(tc, sscanf_spec_d_25);
  tcase_add_test(tc, I_SPECIFIER_SHORTINT);
  tcase_add_test(tc, I_SPECIFIER_LONGINT);
  tcase_add_test(tc, I_SPECIFIER_INT);
  tcase_add_test(tc, I_SPECIFIER_SHORTHEX);
  tcase_add_test(tc, I_SPECIFIER_LONGHEX);
  tcase_add_test(tc, I_SPECIFIER_OCT);
  tcase_add_test(tc, I_SPECIFIER_SHORTOCT);
  tcase_add_test(tc, I_SPECIFIER_LONGOCT);
  tcase_add_test(tc, I_SPECIFIER_HEX);

  tcase_add_test(tc, G_SPECIFIER_FLOAT);
  tcase_add_test(tc, G_SPECIFIER_DOUBLE);
  tcase_add_test(tc, G_SPECIFIER_LONGDOUBLE);
  tcase_add_test(tc, O_SPECIFIER_USHORTOCT);
  tcase_add_test(tc, O_SPECIFIER_ULONGOCT);
  tcase_add_test(tc, O_SPECIFIER_UOCT);
  tcase_add_test(tc, X_SPECIFIER_USHORTHEX);
  tcase_add_test(tc, X_SPECIFIER_ULONGHEX);
  tcase_add_test(tc, X_SPECIFIER_UHEX);
  tcase_add_test(tc, P_SPECIFIER1);
  tcase_add_test(tc, P_SPECIFIER2);
  tcase_add_test(tc, P_SPECIFIER3);
  tcase_add_test(tc, P_SPECIFIER4);
  tcase_add_test(tc, N_SPECIFIER);
  tcase_add_test(tc, PERCENT_SPECIFIER);
  tcase_add_test(tc, EOF1);
  // tcase_add_test(tc, EOF2);
  tcase_add_test(tc, EOF3);
  tcase_add_test(tc, only_chars1);
  tcase_add_test(tc, only_chars2);
  tcase_add_test(tc, only_chars3);
  tcase_add_test(tc, only_chars4);
  tcase_add_test(tc, only_chars5);
  tcase_add_test(tc, special_symbols_as_chars1);
  tcase_add_test(tc, special_symbols_as_chars2);
  tcase_add_test(tc, special_symbols_as_chars3);

  tcase_add_test(tc, chars_flags1);  // Precision flags lead to fail
  tcase_add_test(tc, chars_flags2);  // Width flags do nothing (if <= 1)
  tcase_add_test(
      tc, chars_flags3);  // Demonstrates how (*) works. * - ignore the char
  tcase_add_test(tc, chars_flags4);  // Length flags do nothing
  tcase_add_test(tc, chars_flags5);  // * flags - ignores char
  // Test cases specifically for (%*c), as this is very important concept
  tcase_add_test(tc, chars_aster1);
  tcase_add_test(tc, chars_aster2);

  // // Length (h, l, ll)
  tcase_add_test(tc, only_ints1);
  tcase_add_test(tc, only_ints2);
  tcase_add_test(tc, only_ints3);
  // // Width (N)
  tcase_add_test(tc, ints_nwidth1);
  tcase_add_test(tc, ints_nwidth2);
  tcase_add_test(tc, ints_nwidth3);
  tcase_add_test(tc, ints_nwidth4);
  // // Width (*)
  tcase_add_test(tc, ints_astwidth1);
  tcase_add_test(tc, ints_astwidth2);
  tcase_add_test(tc, ints_astwidth3);
  tcase_add_test(tc, ints_astwidth4);
  // // Negative & positive ints
  tcase_add_test(tc, signed_ints1);
  tcase_add_test(tc, signed_ints2);
  tcase_add_test(tc, signed_ints3);
  tcase_add_test(tc, signed_ints4);

  // // // [%i] Specifier. It may be INT, OCT, HEX

  tcase_add_test(tc, spec_i_int1);
  tcase_add_test(tc, spec_i_int2);
  // // Mixed with chars & ints
  tcase_add_test(tc, spec_i_int3);
  tcase_add_test(tc, spec_i_int4);

  tcase_add_test(tc, spec_i_oct1);
  tcase_add_test(tc, spec_i_oct2);
  tcase_add_test(tc, spec_i_hex1);
  tcase_add_test(tc, spec_i_hex2);

  tcase_add_test(tc, strings1);
  tcase_add_test(tc, strings2);
  tcase_add_test(tc, strings3);
  tcase_add_test(tc, strings4);
  tcase_add_test(tc, strings5);
  tcase_add_test(tc, strings6);
  tcase_add_test(tc, uint1);
  tcase_add_test(tc, uint2);
  // tcase_add_test(tc, uint3);
  tcase_add_test(tc, uint4);
  tcase_add_test(tc, uint5);
  tcase_add_test(tc, uint6);
  tcase_add_test(tc, strings_mixed1);
  tcase_add_test(tc, strings_mixed2);
  tcase_add_test(tc, strings_mixed3);

  tcase_add_test(tc, sscanf_EOF1);
  // tcase_add_test(tc, sscanf_EOF2);
  tcase_add_test(tc, sscanf_EOF3);
  tcase_add_test(tc, sscanf_only_chars1);
  tcase_add_test(tc, sscanf_only_chars2);
  tcase_add_test(tc, sscanf_only_chars3);
  tcase_add_test(tc, sscanf_only_chars4);
  tcase_add_test(tc, sscanf_only_chars5);
  tcase_add_test(tc, sscanf_special_symbols_as_chars1);
  tcase_add_test(tc, sscanf_special_symbols_as_chars2);
  tcase_add_test(tc, sscanf_special_symbols_as_chars3);

  tcase_add_test(tc, sscanf_chars_flags1);  // Precision flags lead to fail
  tcase_add_test(tc, sscanf_chars_flags2);  // Width flags do nothing (if <= 1)
  tcase_add_test(
      tc,
      sscanf_chars_flags3);  // Demonstrates how (*) works. * - ignore the char
  tcase_add_test(tc, sscanf_chars_flags4);  // Length flags do nothing
  tcase_add_test(tc, sscanf_chars_flags5);  // * flags - ignores char
  // // Test cases specifically for (%*c), as this is very important concept
  tcase_add_test(tc, sscanf_chars_aster1);
  tcase_add_test(tc, sscanf_chars_aster2);

  // // [%d]/[%i]
  // // [Width]: * - skip token, (N) - read N chars as a number
  // // [Precision]: Not applicable to int, considered as UB

  // // Length (h, l, ll)
  tcase_add_test(tc, sscanf_only_ints1);
  tcase_add_test(tc, sscanf_only_ints2);
  tcase_add_test(tc, sscanf_only_ints3);
  // // Width (N)
  tcase_add_test(tc, sscanf_ints_nwidth1);
  tcase_add_test(tc, sscanf_ints_nwidth2);
  tcase_add_test(tc, sscanf_ints_nwidth3);
  tcase_add_test(tc, sscanf_ints_nwidth4);
  // // Width (*)
  tcase_add_test(tc, sscanf_ints_astwidth1);
  tcase_add_test(tc, sscanf_ints_astwidth2);
  // // Negative & positive ints
  tcase_add_test(tc, sscanf_signed_ints1);
  tcase_add_test(tc, sscanf_signed_ints2);
  tcase_add_test(tc, sscanf_signed_ints3);
  tcase_add_test(tc, sscanf_signed_ints4);

  // // // [%i] Specifier. It may be INT, OCT, HEX
  tcase_add_test(tc, sscanf_spec_i_int1);
  tcase_add_test(tc, sscanf_spec_i_int2);
  // // Mixed with chars & ints
  tcase_add_test(tc, sscanf_spec_i_int3);
  tcase_add_test(tc, sscanf_spec_i_int4);

  tcase_add_test(tc, sscanf_spec_i_oct1);
  tcase_add_test(tc, sscanf_spec_i_oct2);
  tcase_add_test(tc, sscanf_spec_i_hex1);
  tcase_add_test(tc, sscanf_spec_i_hex2);

  // // [%s]
  // // Width: (N) - parses N chars, (*) - пропустить строку
  // // OUT: res = 4 (корректно парсит все в разные строки)
  // // int res = sscanf("abobashlepafloppakoppa", "%5s %6s %6s %4s", s1, s2,
  // // s3,
  // // s4); Precision, length - not applicable
  tcase_add_test(tc, sscanf_strings1);
  tcase_add_test(tc, sscanf_strings2);
  tcase_add_test(tc, sscanf_strings3);
  tcase_add_test(tc, sscanf_strings4);
  tcase_add_test(tc, sscanf_strings5);
  tcase_add_test(tc, sscanf_strings6);

  tcase_add_test(tc, sscanf_strings_mixed1);
  tcase_add_test(tc, sscanf_strings_mixed2);
  tcase_add_test(tc, sscanf_strings_mixed3);

  // // [%f] [%g] [%G]
  // // Width: (N) - parses N chars, (*) - пропустить строку
  // // Precision: take it into account while parsing AFTER (.)
  // // Length - l - long
  tcase_add_test(tc, sscanf_floats1);
  tcase_add_test(tc, sscanf_floats2);
  tcase_add_test(tc, sscanf_floats3);
  tcase_add_test(tc, sscanf_floats4);

  tcase_add_test(tc, sscanf_floats_sci1);

  // // [%n] specifier
  tcase_add_test(tc, sscanf_n1);
  tcase_add_test(tc, sscanf_n2);
  tcase_add_test(tc, sscanf_n3);

  tcase_add_test(tc, sscanf_upeer_hex_base_version);
  tcase_add_test(tc, sscanf_upeer_hex_overflow);
  tcase_add_test(tc, sscanf_upeer_hex_0x);
  tcase_add_test(tc, sscanf_upeer_hex_0X);
  tcase_add_test(tc, sscanf_upeer_hex_empty);
  tcase_add_test(tc, sscanf_upeer_hex_fail);
  tcase_add_test(tc, sscanf_upeer_hex_spaces_tabs_sns);
  tcase_add_test(tc, sscanf_upeer_hex_short);
  tcase_add_test(tc, sscanf_upeer_hex_long);
  tcase_add_test(tc, sscanf_upeer_hex_longlong);
  tcase_add_test(tc, sscanf_upeer_hex_2x);
  tcase_add_test(tc, sscanf_upeer_hex_star);
  tcase_add_test(tc, sscanf_upeer_hex_nohex);
  tcase_add_test(tc, sscanf_upeer_hex_lower);
  tcase_add_test(tc, sscanf_upeer_hex_sign);

  tcase_add_test(tc, sscanf_lower_hex_base_version);
  tcase_add_test(tc, sscanf_lower_hex_overflow);
  tcase_add_test(tc, sscanf_lower_hex_0x);
  tcase_add_test(tc, sscanf_lower_hex_0X);
  tcase_add_test(tc, sscanf_lower_hex_empty);
  tcase_add_test(tc, sscanf_lower_hex_fail);
  tcase_add_test(tc, sscanf_lower_hex_spaces_tabs_sns);
  tcase_add_test(tc, sscanf_lower_hex_short);
  tcase_add_test(tc, sscanf_lower_hex_long);
  tcase_add_test(tc, sscanf_lower_hex_longlong);
  tcase_add_test(tc, sscanf_lower_hex_2x);
  tcase_add_test(tc, sscanf_lower_hex_star);
  tcase_add_test(tc, sscanf_lower_hex_nohex);
  tcase_add_test(tc, sscanf_lower_hex_lower);
  tcase_add_test(tc, sscanf_lower_hex_sign);
  tcase_add_test(tc, sscanf_lower_hex_len);

  tcase_add_test(tc, sscanf_octal_base_version);
  tcase_add_test(tc, sscanf_octal_overflow);
  tcase_add_test(tc, sscanf_octal_0x);
  tcase_add_test(tc, sscanf_octal_0X);
  tcase_add_test(tc, sscanf_octal_empty);
  tcase_add_test(tc, sscanf_octal_fail);
  tcase_add_test(tc, sscanf_octal_spaces_tabs_sns);
  tcase_add_test(tc, sscanf_octal_short);
  tcase_add_test(tc, sscanf_octal_long);
  tcase_add_test(tc, sscanf_octal_longlong);
  tcase_add_test(tc, sscanf_octal_2x);
  tcase_add_test(tc, sscanf_octal_star);
  tcase_add_test(tc, sscanf_octal_nohex);
  tcase_add_test(tc, sscanf_octal_lower);
  tcase_add_test(tc, sscanf_octal_sign);
  tcase_add_test(tc, sscanf_octal_len);

  tcase_add_test(tc, sscanf_pointer1);
  tcase_add_test(tc, sscanf_pointer2);
  tcase_add_test(tc, sscanf_pointer3);
  tcase_add_test(tc, sscanf_pointer4);

  tcase_add_test(tc, sscanf_buff1);
  tcase_add_test(tc, sscanf_buff2);
  tcase_add_test(tc, sscanf_buff3);

  tcase_add_test(tc, sscanf_perc1);
  tcase_add_test(tc, sscanf_perc2);
  tcase_add_test(tc, sscanf_perc3);
  tcase_add_test(tc, sscanf_perc4);
  tcase_add_test(tc, sscanf_perc5);

  tcase_add_test(tc, sscanf_mixed_ptrs1);
  tcase_add_test(tc, sscanf_mixed_ptrs2);
  tcase_add_test(tc, sscanf_mixed_ptrs3);
  tcase_add_test(tc, sscanf_mixed_ptrs4);
  tcase_add_test(tc, sscanf_mixed_ptrs5);

  tcase_add_test(tc, S_SPECIFIER1);
  tcase_add_test(tc, S_SPECIFIER2);
  tcase_add_test(tc, S_SPECIFIER3);
  tcase_add_test(tc, S_SPECIFIER4);
  tcase_add_test(tc, S_SPECIFIER5);
  tcase_add_test(tc, S_SPECIFIER6);
  tcase_add_test(tc, S_SPECIFIER7);
  tcase_add_test(tc, S_SPECIFIER8);
  tcase_add_test(tc, S_SPECIFIER9);
  tcase_add_test(tc, S_SPECIFIER10);
  tcase_add_test(tc, S_SPECIFIER11);
  tcase_add_test(tc, S_SPECIFIER12);
  tcase_add_test(tc, errorrrr_u);
  tcase_add_test(tc, U_notwork);

  tcase_add_test(tc, s21_memchr_tests_case);
  tcase_add_test(tc, s21_memcmp_tests_case_1);
  tcase_add_test(tc, s21_memcmp_tests_case_2);
  tcase_add_test(tc, s21_memcmp_tests_case_3);
  tcase_add_test(tc, s21_memcmp_tests_case_4);
  tcase_add_test(tc, s21_memcmp_tests_case_5);
  tcase_add_test(tc, s21_memcmp_tests_case_6);
  tcase_add_test(tc, s21_memcmp_tests_case_7);
  tcase_add_test(tc, s21_memcmp_tests_case_8);
  tcase_add_test(tc, s21_memcmp_tests_case_9);
  tcase_add_test(tc, s21_memcmp_tests_case_10);
  tcase_add_test(tc, s21_memcpy_tests_case);
  tcase_add_test(tc, s21_memset_tests_case);
  tcase_add_test(tc, s21_strchr_tests_case_1);
  tcase_add_test(tc, s21_strchr_tests_case_2);
  tcase_add_test(tc, s21_strlen_tests_case_2);

  tcase_add_test(tc, s21_strcpy_tests_case);
  tcase_add_test(tc, s21_strncpy_tests_case);
  tcase_add_test(tc, s21_strcmp_tests_case_1);
  tcase_add_test(tc, s21_strcmp_tests_case_2);
  tcase_add_test(tc, s21_strcmp_tests_case_3);
  tcase_add_test(tc, s21_strcmp_tests_case_4);
  tcase_add_test(tc, s21_strcmp_tests_case_5);
  tcase_add_test(tc, s21_strcmp_tests_case_6);
  tcase_add_test(tc, s21_strcmp_tests_case_7);
  tcase_add_test(tc, s21_strcmp_tests_case_8);
  tcase_add_test(tc, s21_strcmp_tests_case_9);
  tcase_add_test(tc, s21_strcmp_tests_case_10);
  tcase_add_test(tc, s21_strncmp_tests_case_1);
  tcase_add_test(tc, s21_strncmp_tests_case_2);
  tcase_add_test(tc, s21_strncmp_tests_case_3);
  tcase_add_test(tc, s21_strncmp_tests_case_4);
  tcase_add_test(tc, s21_strncmp_tests_case_5);
  tcase_add_test(tc, s21_strncmp_tests_case_6);
  tcase_add_test(tc, s21_strncmp_tests_case_7);
  tcase_add_test(tc, s21_strncmp_tests_case_8);
  tcase_add_test(tc, s21_strncmp_tests_case_9);
  tcase_add_test(tc, s21_strncmp_tests_case_10);
  tcase_add_test(tc, s21_strstr_tests_case_1);
  tcase_add_test(tc, s21_strstr_tests_case_2);
  tcase_add_test(tc, s21_strstr_tests_case_3);
  tcase_add_test(tc, s21_strstr_tests_case_4);
  tcase_add_test(tc, s21_strstr_tests_case_5);
  tcase_add_test(tc, s21_strstr_tests_case_6);
  tcase_add_test(tc, s21_strcat_tests_case_1);
  tcase_add_test(tc, s21_strcat_tests_case_2);
  tcase_add_test(tc, s21_strcat_tests_case_3);
  tcase_add_test(tc, s21_strcat_tests_case_4);
  tcase_add_test(tc, s21_strcat_tests_case_5);
  tcase_add_test(tc, s21_strcat_tests_case_6);
  tcase_add_test(tc, s21_strcat_tests_case_7);
  tcase_add_test(tc, s21_strcat_tests_case_8);
  tcase_add_test(tc, s21_strcat_tests_case_9);
  tcase_add_test(tc, s21_strcat_tests_case_10);
  tcase_add_test(tc, s21_strncat_tests_case_1);
  tcase_add_test(tc, s21_strncat_tests_case_2);
  tcase_add_test(tc, s21_strncat_tests_case_3);
  tcase_add_test(tc, s21_strncat_tests_case_4);
  tcase_add_test(tc, s21_strncat_tests_case_5);
  tcase_add_test(tc, s21_strncat_tests_case_6);
  tcase_add_test(tc, s21_strncat_tests_case_7);
  tcase_add_test(tc, s21_strncat_tests_case_8);
  tcase_add_test(tc, s21_strncat_tests_case_9);
  tcase_add_test(tc, s21_strncat_tests_case_10);
  tcase_add_test(tc, s21_strpbrk_tests_case_1);
  tcase_add_test(tc, s21_strpbrk_tests_case_2);
  tcase_add_test(tc, s21_strpbrk_tests_case_3);
  tcase_add_test(tc, s21_strpbrk_tests_case_4);
  tcase_add_test(tc, s21_strpbrk_tests_case_5);
  tcase_add_test(tc, s21_strrchr_tests_case_1);
  tcase_add_test(tc, s21_strrchr_tests_case_2);
  tcase_add_test(tc, s21_strrchr_tests_case_3);
  tcase_add_test(tc, s21_strrchr_tests_case_4);
  tcase_add_test(tc, s21_strrchr_tests_case_5);

  tcase_add_test(tc, s21_strcspn_tests_case);
  tcase_add_test(tc, s21_strtok_tests_case);
  tcase_add_test(tc, s21_str_insert_tests_case);
  tcase_add_test(tc, s21_strtok_tests_case);
  tcase_add_test(tc, s21_strspn_tests_case);

  tcase_add_test(tc, s21_str_to_lower_tests_case);
  tcase_add_test(tc, s21_str_to_upper_tests_case);
  tcase_add_test(tc, s21_str_trim_tests_case);

  tcase_add_test(tc, sprintf_simple_int);
  tcase_add_test(tc, sprintf_precise_int);
  tcase_add_test(tc, sprintf_width_int);
  tcase_add_test(tc, sprintf_minus_width_int);
  tcase_add_test(tc, sprintf_plus_width_int);
  tcase_add_test(tc, sprintf_padding_int);
  tcase_add_test(tc, sprintf_star_precision_int);
  tcase_add_test(tc, sprintf_many_flags_many_ints);
  tcase_add_test(tc, sprintf_flags_long_int);
  tcase_add_test(tc, sprintf_flags_short_int);
  tcase_add_test(tc, sprintf_flags_another_long_int);
  tcase_add_test(tc, sprintf_zero_precision_zero_int);
  tcase_add_test(tc, sprintf_space_flag_int);
  tcase_add_test(tc, sprintf_unsigned_val);
  tcase_add_test(tc, sprintf_unsigned_val_width);
  tcase_add_test(tc, sprintf_unsigned_val_flags);
  tcase_add_test(tc, sprintf_unsigned_val_precision);
  tcase_add_test(tc, sprintf_unsigned_val_many_flags);
  tcase_add_test(tc, sprintf_unsigned_val_short);
  tcase_add_test(tc, sprintf_unsigned_val_long);
  tcase_add_test(tc, sprintf_unsigned_val_many);

  tcase_add_test(tc, sprintf_octal_width);
  tcase_add_test(tc, sprintf_octal_flags);
  tcase_add_test(tc, sprintf_octal_precision);
  tcase_add_test(tc, sprintf_octal_many_flags);
  tcase_add_test(tc, sprintf_octal_short);
  tcase_add_test(tc, sprintf_octal_long);
  tcase_add_test(tc, sprintf_octal_many);
  tcase_add_test(tc, sprintf_octal);
  tcase_add_test(tc, sprintf_octal_zero);
  tcase_add_test(tc, sprintf_octal_hash);
  tcase_add_test(tc, sprintf_unsigned_zero);
  tcase_add_test(tc, sprintf_hex_width);
  tcase_add_test(tc, sprintf_hex_flags);
  tcase_add_test(tc, sprintf_hex_precision);
  tcase_add_test(tc, sprintf_hex_many);
  tcase_add_test(tc, sprintf_hex_many_flags);
  tcase_add_test(tc, sprintf_hex_zero);
  tcase_add_test(tc, sprintf_hex_huge);
  tcase_add_test(tc, sprintf_hex_short);
  tcase_add_test(tc, sprintf_hex_long);
  tcase_add_test(tc, sprintf_hex_one_longer_width);
  tcase_add_test(tc, sprintf_hex_two_longer_width);
  tcase_add_test(tc, sprintf_one_char);
  tcase_add_test(tc, sprintf_one_precision);
  tcase_add_test(tc, sprintf_one_flags);
  tcase_add_test(tc, sprintf_one_width);
  tcase_add_test(tc, sprintf_one_many);
  tcase_add_test(tc, sprintf_one_many_flags);
  tcase_add_test(tc, sprintf_string);
  tcase_add_test(tc, sprintf_string_precision);
  tcase_add_test(tc, sprintf_string_width);
  tcase_add_test(tc, sprintf_string_flags);
  tcase_add_test(tc, sprintf_string_long);
  tcase_add_test(tc, sprintf_string_many);
  tcase_add_test(tc, sprintf_ptr);
  tcase_add_test(tc, sprintf_ptr_width);
  tcase_add_test(tc, sprintf_ptr_precision);
  tcase_add_test(tc, sprintf_null_ptr);
  tcase_add_test(tc, sprintf_n_specifier);
  tcase_add_test(tc, sprintf_string_width_huge);
  tcase_add_test(tc, sprintf_float_precision);
  tcase_add_test(tc, sprintf_float_width);
  tcase_add_test(tc, sprintf_float_precision_zero);
  tcase_add_test(tc, sprintf_float_precision_empty);
  tcase_add_test(tc, sprintf_float_precision_huge);
  tcase_add_test(tc, sprintf_float_precision_huge_negative);
  tcase_add_test(tc, sprintf_float_huge);
  tcase_add_test(tc, sprintf_float_flags);
  tcase_add_test(tc, sprintf_float_many);
  tcase_add_test(tc, sprintf_e_precision);
  tcase_add_test(tc, sprintf_e_precision_zero);
  tcase_add_test(tc, sprintf_e_precision_empty);
  tcase_add_test(tc, sprintf_e_precision_huge);
  tcase_add_test(tc, sprintf_e_precision_huge_negative);
  tcase_add_test(tc, sprintf_e_huge);
  tcase_add_test(tc, sprintf_e_many);
  tcase_add_test(tc, sprintf_e_width);
  tcase_add_test(tc, sprintf_e_flags);
  tcase_add_test(tc, sprintf_E_int);
  tcase_add_test(tc, sprintf_all_empty);
  tcase_add_test(tc, sprintf_empty_format_and_parameters);
  tcase_add_test(tc, sprintf_test_one_char);
  tcase_add_test(tc, sprintf_test_many_char);
  tcase_add_test(tc, sprintf_test_one_string);
  tcase_add_test(tc, sprintf_test_many_string);
  tcase_add_test(tc, sprintf_test_one_dec);
  tcase_add_test(tc, sprintf_test_many_dec);
  tcase_add_test(tc, sprintf_test_one_int);
  tcase_add_test(tc, sprintf_test_many_int);
  tcase_add_test(tc, sprintf_test_one_float);
  tcase_add_test(tc, sprintf_test_many_float);
  tcase_add_test(tc, sprintf_test_one_unsigned_dec);
  tcase_add_test(tc, sprintf_test_many_unsigned_dec);
  tcase_add_test(tc, sprintf_test_one_char_with_alignment_left);
  tcase_add_test(tc, sprintf_test_one_char_with_alignment_right);
  tcase_add_test(tc, sprintf_test_many_char_with_alignment);
  tcase_add_test(tc, sprintf_test_one_hex_lower);
  tcase_add_test(tc, sprintf_test_one_hex_upper);
  tcase_add_test(tc, sprintf_test_many_hex_lower);
  tcase_add_test(tc, sprintf_test_many_hex_upper);
  tcase_add_test(tc, sprintf_test_one_hex_lower_with_alignment_left);
  tcase_add_test(tc, sprintf_test_one_hex_lower_with_alignment_right);
  tcase_add_test(tc, sprintf_test_one_hex_upper_with_alignment_left);
  tcase_add_test(tc, sprintf_test_one_hex_upper_with_alignment_right);
  tcase_add_test(tc, sprintf_test_many_hex_lower_with_alignment);
  tcase_add_test(tc, sprintf_test_many_hex_upper_with_alignment);
  tcase_add_test(tc, sprintf_test_one_hex_with_hashtag);
  tcase_add_test(tc, sprintf_test_one_hex_upper_with_hashtag);
  tcase_add_test(tc, sprintf_test_many_hex_lower_with_hashtag_and_alignm);
  tcase_add_test(tc, sprintf_test_many_hex_upper_with_hashtag_and_alignm);
  tcase_add_test(tc, sprintf_test_one_hex_lower_with_width_star);
  tcase_add_test(tc, sprintf_test_one_hex_upper_with_width_star);
  tcase_add_test(
      tc, sprintf_test_many_hex_lower_with_width_star_and_align_and_hashtag);
  tcase_add_test(tc, sprintf_test_many_hex_upper_with_width_star);
  tcase_add_test(tc, sprintf_test_one_hex_lower_with_precision);
  tcase_add_test(tc, sprintf_test_one_hex_upper_with_precision);
  tcase_add_test(tc, sprintf_test_sprintf1);
  tcase_add_test(tc, sprintf_test_sprintf2);
  tcase_add_test(tc, sprintf_test_sprintf3);
  tcase_add_test(tc, sprintf_test_sprintf4);
  tcase_add_test(tc, sprintf_test_sprintf6);
  tcase_add_test(tc, sprintf_test_sprintf7);
  tcase_add_test(tc, sprintf_test_sprintf8);
  tcase_add_test(tc, sprintf_test_sprintf9);
  tcase_add_test(tc, sprintf_test_sprintf10);
  tcase_add_test(tc, sprintf_test_sprintf11);
  tcase_add_test(tc, sprintf_test_sprintf12);
  tcase_add_test(tc, sprintf_test_sprintf14);
  tcase_add_test(tc, sprintf_test_sprintf15);
  tcase_add_test(tc, sprintf_test_sprintf16);
  tcase_add_test(tc, sprintf_test_sprintf17);
  tcase_add_test(tc, sprintf_test_sprintf18);
  tcase_add_test(tc, sprintf_test_sprintf19);
  tcase_add_test(tc, sprintf_test_sprintf20);
  tcase_add_test(tc, sprintf_test_sprintf24);
  tcase_add_test(tc, sprintf_test_sprintf25);
  tcase_add_test(tc, sprintf_test_sprintf28);
  tcase_add_test(tc, sprintf_test_sprintf29);
  tcase_add_test(tc, sprintf_test_sprintf30);
  tcase_add_test(tc, sprintf_test_sprintf31);
  tcase_add_test(tc, sprintf_test_sprintf32);
  tcase_add_test(tc, sprintf_test_sprintf33);
  tcase_add_test(tc, sprintf_test_sprintf35);
  tcase_add_test(tc, sprintf_test_sprintf36);
  tcase_add_test(tc, sprintf_test_sprintf37);
  tcase_add_test(tc, sprintf_test_sprintf38);
  tcase_add_test(tc, sprintf_test_sprintf39);
  tcase_add_test(tc, sprintf_test_sprintf40);
  tcase_add_test(tc, sprintf_test_sprintf41);
  tcase_add_test(tc, sprintf_test_sprintf42);
  tcase_add_test(tc, sprintf_test_sprintf43);
  tcase_add_test(tc, sprintf_test_sprintf44);
  tcase_add_test(tc, sprintf_test_sprintf26);
  tcase_add_test(tc, sprintf_test_sprintf27);
  tcase_add_test(tc, sprintf_g_trailing_zero);
  tcase_add_test(tc, sprintf_g_large);
  tcase_add_test(tc, sprintf_g_small);
  tcase_add_test(tc, sprintf_g_precision);
  tcase_add_test(tc, sprintf_g_precision_zero);
  tcase_add_test(tc, sprintf_g_precision_missing);
  tcase_add_test(tc, sprintf_g_many_zeroes_in_front);
  tcase_add_test(tc, sprintf_g_one_zero);
  tcase_add_test(tc, sprintf_g_mantiss);
  tcase_add_test(tc, sprintf_g_mantiss_flags);
  tcase_add_test(tc, sprintf_g_short_no_mantiss);
  tcase_add_test(tc, sprintf_LG);
  tcase_add_test(tc, sprintf_g_many);
  tcase_add_test(tc, sprintf_g_zero);
  tcase_add_test(tc, sprintf_width_char);

  srunner_run_all(sr, CK_NOFORK);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);

  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
