PROGRAM = assembler
SOURCES = $(wildcard src/*/*.c) src/main.c
CFLAGS = -g -O0
LDFLAGS =

TESTS = $(patsubst test/%.c, %, $(wildcard test/test_*.c))
TEST_CFLAGS =
TEST_LDFLAGS = -lcheck

all: $(PROGRAM)

$(PROGRAM): $(SOURCES) src/*/*.h
	@$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $(SOURCES)

test: $(TESTS)
	@./test_symbol_table

test_symbol_table: %: test/%.c src/symbol_table/symbol_table.c
	@$(CC) $(TEST_CFLAGS) $(TEST_LDFLAGS) -o $@ $+

clean:
	@-rm -rf $(PROGRAM) $(TESTS) *.dSYM

.PHONY: all test clean
