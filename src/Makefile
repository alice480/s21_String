CFLAGS = -Wall -Wextra -Werror -std=c11
STRINGFUNC = $(SOURCES:.c=.o)
SOURCES = s21_strlen.c s21_strcmp.c s21_strcpy.c s21_strtok.c s21_strncmp.c s21_sprintf.c s21_memmove.c s21_to_upper.c s21_sscanf.c s21_to_lower.c s21_insert.c s21_memchr.c s21_memcmp.c s21_memcpy.c s21_memset.c s21_strcat.c s21_strrchr.c s21_strncpy.c s21_strncat.c s21_strpbrk.c s21_strstr.c s21_strerror.c s21_trim.c s21_strspn.c s21_strcspn.c s21_strchr.c
TESTS = string_tests.o
S21STRINGLIB = s21_string.a

UNAME = $(shell uname -s)
FLAGS = 
ifeq ($(UNAME), Linux)
	FLAGS += -lcheck_pic -lm -lsubunit -lrt -lpthread
else
	FLAGS += -lcheck
endif
all: test
%.o: %.c
	gcc $(CFLAG) -c $^ -o $@

test: $(TESTS) $(S21STRINGLIB)
	gcc $^ -o test $(FLAGS)
	rm -rf *.o
	./test

$(TESTS): $(TESTS:.o=.c)
	gcc -Wall -std=c11 -c $^  -o $@
	
%.a: $(STRINGFUNC)
	ar rc $(S21STRINGLIB) $^
	ranlib $(S21STRINGLIB)

rebuild: clean all

gcov_report: clean $(TESTS)
	gcc -o test $(TESTS) --coverage $(SOURCES) -lcheck -lm
	./test
	lcov -t "a.out" -o test.info -c -d .
	genhtml -o report test.info
	open ./report/index.html
	rm -rf test *.o *.a *gcda *gcno *info

clean:
	rm -rf test *.o *.a *gcda report *gcno *info
