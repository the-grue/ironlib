CFLAGS += -I ../include

VPATH += ../src

.PHONY: all
all: printf-test

printf-test: printf-test.o -lc

printf-test.o: printf-test.c

.PHONY: clean
clean:
	$(RM) printf-test printf-test.o

.PHONY: test
test:
	./printf-test

.PHONY: install
install:
