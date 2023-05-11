CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -Werror -pedantic -Wno-gnu-binary-literal -fprofile-arcs -ftest-coverage
LIBS = s21_matrix.a
TESTS = s21_matrix_tests
C_FILES := $(wildcard *.c)
OBJ_FILES := $(C_FILES:.c=.o)

ifeq ($(OS), Darwin)
	TEST_LIBS = -lcheck -lrt -pthread -lsubunit -L/usr/lib/x86_64-linux-gnu/libsubunit.so -L/usr/lib/x86_64-linux-gnu/libcheck.a -lm
else
	TEST_LIBS = -lcheck -L /usr/bin/
endif


all: clean $(LIBS) gcov_report

clean:
	rm -rf  *.o *.gcda *.gcno *.gcov *.a *.info coverage_report check_s21_decimal a.out
clean_test:
	rm -rf s21_matrix_tests.c

test: $(TESTS) 
	./$(TESTS) 
s21_matrix.a: $(OBJ_FILES)
		ar rcs $@ $< $(OBJ_FILES)

s21_matrix.o: $(C_FILES) s21_matrix.h
	$(CC) $(CFLAGS) $(C_FILES) -fprofile-arcs -ftest-coverage -c $<

s21_matrix_tests.c:
	checkmk clean_mode=1 s21_matrix_tests.check > s21_matrix_tests.c 

s21_matrix_tests.o: s21_matrix_tests.c s21_matrix_tests.c s21_matrix.h 
	$(CC) $(CFLAGS)  -c $<

s21_matrix_tests: s21_matrix_tests.o s21_matrix.a
	$(CC) $(CFLAGS)  -o $@ $^ $(TEST_LIBS)


gcov_report: CFLAGS += -fprofile-arcs -ftest-coverage
gcov_report: test
	lcov --capture --directory . --output-file coverage.info
	genhtml coverage.info --output-directory coverage_report
	rm -f *.gcda *.gcno *.gcov
	open ./coverage_report/index.html