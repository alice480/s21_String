CC=gcc -std=c11 -D_GNU_SOURCE
CFLAGS=-c -Wall -Wextra -Werror
TEST_FLAGS=-lcheck -lpthread
GCOV_FLAGS=--coverage -Wall -Wextra -Werror

OS:=$(shell uname -s)
ifeq ($(OS), Linux)
	TEST_FLAGS += -lrt -lsubunit -lm
	CC += -D OS_LINUX
endif

ifeq ($(OS), Darwin)
    CC += -D OS_MAC
endif

SOURCES=$(wildcard s21_*.c)
OBJECTS=$(SOURCES:.c=.o)
TESTS_SOURCES= ./tests/test.c $(wildcard ./tests/test_cases/*.c)
TESTS_OBJECTS=$(TESTS_SOURCES:.c=.o)
EXECUTABLE=s21_string

.PHONY: all rebuild style test gcov_report

all: s21_string.a test gcov_report


$(EXECUTABLE): $(OBJECTS)
	$(CC) $^ -o $@

.c.o:
	$(CC) $(CFLAGS) $< -o $@

s21_string.a: $(OBJECTS)
	ar -rcs s21_string.a $(OBJECTS)
	ranlib s21_string.a

test: $(TESTS_OBJECTS) s21_string.a
	$(CC) $^ -o test $(TEST_FLAGS)
	./test

gcov_report: $(TESTS_OBJECTS)
	$(CC) $(GCOV_FLAGS) $(TESTS_OBJECTS) $(SOURCES) $(TEST_FLAGS) -o test
	./test
	gcov *.gcno
	lcov -t "test" -o test.info -c -d . --rc lcov_branch_coverage=1
	genhtml -o report test.info --rc lcov_branch_coverage=1
	open report/index.html

style:
	cp ../materials/linters/.clang-format ./
	clang-format -n *.c *.h
	clang-format -n tests/*.c tests/*.h
	clang-format -n tests/test_cases/*.c
	rm .clang-format

rebuild: clean all


clean:
	rm -rf ./tests/*.o ./tests/test_cases/*.o $(EXECUTABLE) test *.o
	rm -rf *.gcno *.gcov *.gcda *.info ../*.h.gch report s21_string.a
