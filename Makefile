INCLUDE_DIR = include

PROGRAM = assembler
SOURCES = $(wildcard src/*/*.c) src/main.c
CFLAGS = -g -O0
LDFLAGS =

TESTS = $(patsubst test/%.c, %, $(wildcard test/test_*.c))
TEST_CFLAGS =
TEST_LDFLAGS = -lcheck

GEN_TABLES = $(addprefix $(INCLUDE_DIR)/tables/, gen_dest.h gen_comp.h gen_jump.h)

all: $(GEN_TABLES) $(PROGRAM)

$(PROGRAM): $(SOURCES)
	@$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $(SOURCES)

$(INCLUDE_DIR)/tables/gen_dest.h: $(INCLUDE_DIR)/tables/%.h: in/%
$(INCLUDE_DIR)/tables/gen_comp.h: $(INCLUDE_DIR)/tables/%.h: in/%
$(INCLUDE_DIR)/tables/gen_jump.h: $(INCLUDE_DIR)/tables/%.h: in/%
gen: $(GEN_TABLES)

$(GEN_TABLES):
	@mkdir -p $(INCLUDE_DIR)/tables
	@gperf $^ > $@

test_symbol_table: test_%: test/test_%.c src/symbol_table/%.c
test_parser: test_%: test/test_%.c src/parser/%.c
test_code_generator: test_%: test/test_%.c src/code_generator/%.c

$(TESTS):
	@$(CC) $(TEST_CFLAGS) $(TEST_LDFLAGS) -o $@ $+

test: $(GEN_TABLES) $(TESTS)
	@for test in $(TESTS); do \
		./$$test 2>/dev/null; \
	done

clean:
	@-rm -rf $(PROGRAM) $(TESTS) *.dSYM
	@-rm -rf $(INCLUDE_DIR)/tables

.PHONY: all test gen clean
