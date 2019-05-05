UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S), Linux)
	TEST_LIBS =-lcheck_pic -lpthread -lrt -lm
endif
ifeq ($(UNAME_S), Darwin)
	TEST_LIBS =-lcheck
endif

all: array test_array

array:
	$(CC) -g -c kadane.c ${LIBS}
	$(CC) -g -c heap.c ${LIBS}
	$(AR) rcs $@.a kadane.o heap.o

test_array: array
	$(CC) -g test_kadane.c array.a -o test_array $(TEST_LIBS)

test: test_array
	./test_array

clean:
	rm -f test_array *.o *.a

