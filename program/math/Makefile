

TEST_SRCS = test_algebra.c
ELFS = $(sort $(patsubst %c, %elf, $(TEST_SRCS) ))

CFLAGS = -Wall -I./ 
LDFLAGS = -lm

all:run_tests

run_tests: $(ELFS)
	@echo 'Running tests...'
	@./$(ELFS)


%.elf: %.c
	@$(CC) $(CFLAGS) $< $(LDFLAGS) -o $@
	@echo 'CC $<'

clean:
	rm -f $(ELFS)

.PHONY: test