.PHONY: s21_matrix.a s21_matrix_tests.c  gcov_report test clean

OS=$(shell uname)
BASE=*.c
TEST_C=tests/s21_matrix_check.c 
OBJS=s21_addition_function.o s21_arithmetic_matrix.o s21_comparison_matrix.o s21_create_and_delete_matrix.o s21_determinant_with_additons.o s21_others.o
GCC=gcc -std=c11 -Wall -Werror -Wextra #-fsanitize=address

# -- Main targets ---
LIB=s21_matrix.a
GCOV=gcov_report
TEST=test
CLEAN=clean

# -- Dependencie of OS ---
ifeq ($(OS), Linux)
	LINUX=-lsubunit
else
	VIEWHTML=open ./report/index.html
endif


all: $(CLEAN) $(LIB) $(TEST) $(GCOV)

$(LIB): $(OBJS)
	rm -rf $(LIB)
	ar rcs $(LIB) $(OBJS)
	ranlib $(LIB)

.c.o:
	$(GCC) -c -g -o $@ $<



$(TEST): $(LIB)
	$(GCC) $(TEST_C) -o $(TEST).out -L. $(LIB) -lcheck -lm $(LINUX)

ifeq ($(OS), Darwin)
	./$(TEST).out
else
	CK_FORK=no valgrind --vgdb=no --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose ./$(TEST).out
endif

$(GCOV): $(LIB)
	rm -rf *.o *.gcno *.gcda
	$(GCC) $(TEST_C) $(BASE) -o gcov --coverage -lcheck -lm $(LINUX) -L. $(LIB)
	./gcov
	lcov -t "gcov" -o $(GCOV).info --no-external -c -d .
	genhtml -o report $(GCOV).info
	$(VIEWHTML)

rebuild: $(CLEAN) all

$(CLEAN):
	rm -rf  *.gcno  *.inf *.info gcov *.gcda *.a test.out ./report *.o *.dSYM a.out tests/*.o

check:
	cp ../materials/linters/.clang-format .
	clang-format -n *.c *.h ./*/*.c ./*/*.h
	rm -f .clang-format