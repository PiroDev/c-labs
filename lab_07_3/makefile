CC := gcc
CFLAGS := -std=c99 -Wall -Werror -pedantic -Wextra
OBJDIR := out
OBJS := $(OBJDIR)/functions.o $(OBJDIR)/input_output.o
SRCDIR := src
INCDIR := inc
RM := rm
CHECKFLAGS := -lcheck -lpthread -lrt
UNIT_TESTS_DIR := unit_tests

ifeq ($(mode), debug)
	CFLAGS += -g3
endif

ifeq ($(mode), release)
	CFLAGS += -DNDEBUG -g0
endif

app.exe : $(OBJS) $(OBJDIR)/main.o
	$(CC) $(CFLAGS) $^ -o $@

$(OBJDIR)/%.o : $(SRCDIR)/%.c $(INCDIR)/*.h
	mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

unit: $(OBJDIR)/functions.o $(OBJDIR)/check_functions.o $(OBJDIR)/check_main.o
	$(CC) -o unit_tests.exe $^ $(CHECKFLAGS)
	./unit_tests.exe

$(OBJDIR)/check_%.o : $(UNIT_TESTS_DIR)/check_%.c $(UNIT_TESTS_DIR)/test_suites.h
	mkdir -p out;
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY : clean
clean :
	$(RM) -f *.exe
	$(RM) -f out/*.o