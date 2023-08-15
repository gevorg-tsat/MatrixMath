CC = gcc
CFLAGS = -std=c++17 -Wall -Werror -Wextra

all: s21_matrix_oop.a

s21_matrix_oop.a:
	$(CC) $(CFLAGS) -c s21_matrix_oop.cpp
	ar rcs s21_matrix_oop.a *.o
	ranlib s21_matrix_oop.a
	rm *.o

test: rebuild
	$(CC) $(CFLAGS) tests/*.cpp s21_matrix_oop.cpp -o test -lgtest
	./test
	rm test


clean:
	rm -rf s21_matrix_oop.a test *.o *.out

rebuild: 
	make clean
	make all
