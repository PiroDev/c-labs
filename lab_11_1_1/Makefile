CC := gcc
OBJDIR := out
OBJS := $(OBJDIR)/string_functions.o $(OBJDIR)/my_stdio.o
SRCDIR := src
INCDIR := include
CFLAGS := -I${INCDIR} -std=c99 -Wall -Werror -pedantic -Wextra
RM := rm
CHECKFLAGS := -lcheck -lpthread -lrt
UNIT_TESTS_DIR := unit_tests

ifeq ($(mode), debug)
	CFLAGS += -g3
endif

ifeq ($(mode), release)
	CFLAGS += -DNDEBUG -g0
endif

$(OBJDIR)/%.o : $(SRCDIR)/%.c $(INCDIR)/*.h
	mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

unit: unit_tests.exe
	./unit_tests.exe

unit_tests.exe: $(OBJDIR)/string_functions.o $(OBJDIR)/my_stdio.o $(OBJDIR)/check_string_functions.o $(OBJDIR)/check_my_stdio.o $(OBJDIR)/check_main.o
	$(CC) -o unit_tests.exe $^ $(CHECKFLAGS)

$(OBJDIR)/check_%.o : $(UNIT_TESTS_DIR)/check_%.c $(UNIT_TESTS_DIR)/check_test_suites.h
	mkdir -p out;
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY : clean
clean :
	$(RM) -f *.exe
	$(RM) -f out/*.o
