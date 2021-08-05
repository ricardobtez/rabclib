#!/usr/bin/make

# rabclib test Makefile.
# Author: Ricardo Benitez

INC_TEST = -iquote test/inc
_OBJS_MAIN_TEST = test_main.o
_OBJS_TEST = test_linked_list.o

OBJS_TEST = $(addprefix $(ODIR)/test/,$(_OBJS_TEST))
OBJS_TEST += $(addprefix $(ODIR)/test/,$(_OBJS_MAIN_TEST))

test_run : debug_obj init_test $(OBJS_TEST) init_bin_test
	@echo
	@echo \******************************
	@echo \* Start of unit testing
	@echo \******************************
	@echo
	@$(CC) $(OBJS_TEST) $(OBJS_DEBUG) -lcmocka -o bin/test/$(EX_NAME)
	@./bin/test/$(EX_NAME)

# Define a pattern rule that compiles every .c file into a .o file in its
# destination in the release folder
$(ODIR)/test/%.o : CPPFLAGS += -DDEBUG
$(ODIR)/test/%.o : $(TDIR)/%.c
	$(CC) -c $(CFLAGS) $(INC) $(INC_TEST) $(CPPFLAGS) $< -o $@

init_test :
	@if [ ! -d "$(ODIR)/test" ]; then \
		mkdir $(ODIR)/test; \
	fi
# Create the unit test generated files
	@python3 ./tools/generate_unit_tests.py

init_bin_test : init_bin
	@if [ ! -d bin/test ]; then \
		mkdir bin/test; \
	fi