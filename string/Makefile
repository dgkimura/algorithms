UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S), Linux)
	TEST_LIBS =-lcheck_pic -lpthread -lrt -lm
endif
ifeq ($(UNAME_S), Darwin)
	TEST_LIBS =-lcheck
endif

all: string test_kmp test_manacher

string:
	$(CC) -g -c manacher.c ${LIBS}
	$(CC) -g -c kmp.c ${LIBS}
	$(AR) rcs $@.a manacher.o kmp.o

test_kmp: string
	$(CC) -g test_kmp.c string.a -o test_kmp $(TEST_LIBS)

test_manacher: string
	$(CC) -g test_manacher.c string.a -o test_manacher $(TEST_LIBS)

test: test_kmp test_manacher
	./test_kmp && ./test_manacher

clean:
	rm -f test_kmp *.o *.a
