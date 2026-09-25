CC := cc
CPPFLAGS :=
CFLAGS := -std=c11 -Wall -Wextra -Wpedantic -g
LDFLAGS :=
LDLIBS :=

COMMON_OBJECTS := book.jliotta.o list.jliotta.o
TARGETS := test list-unit-tests
OBJECTS := $(COMMON_OBJECTS) csvreader.o test.o list-unit-tests.o
DEPS := $(OBJECTS:.o=.d)

.PHONY: all check clean

all: $(TARGETS)

test: test.o $(COMMON_OBJECTS)
	$(CC) $(LDFLAGS) $^ $(LDLIBS) -o $@

list-unit-tests: list-unit-tests.o csvreader.o $(COMMON_OBJECTS)
	$(CC) $(LDFLAGS) $^ $(LDLIBS) -o $@

%.o: %.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -MMD -MP -c $< -o $@

check: list-unit-tests
	./list-unit-tests

clean:
	$(RM) $(TARGETS) $(OBJECTS) $(DEPS)

-include $(DEPS)
