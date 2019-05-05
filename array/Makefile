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

test_kadane: array
	$(CC) -g test_kadane.c array.a -o test_kadane $(TEST_LIBS)

test_heap: array
	$(CC) -g test_heap.c array.a -o test_heap $(TEST_LIBS)

test: test_kadane test_heap
	./test_kadane && ./test_heap

clean:
	rm -f test_array *.o *.a

