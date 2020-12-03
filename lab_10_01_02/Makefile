CC := gcc
OBJDIR := out
OBJS := $(OBJDIR)/list.o $(OBJDIR)/list_functions.o $(OBJDIR)/polynom.o $(OBJDIR)/polynom_functions.o $(OBJDIR)/polynom_io.o
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

app.exe : $(OBJS) $(OBJDIR)/main.o
	$(CC) $(CFLAGS) $^ -o $@

$(OBJDIR)/%.o : $(SRCDIR)/%.c $(INCDIR)/*.h
	mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

unit: unit_tests.exe
	./unit_tests.exe

unit_tests.exe: $(OBJDIR)/list.o $(OBJDIR)/list_functions.o $(OBJDIR)/polynom.o $(OBJDIR)/polynom_functions.o $(OBJDIR)/check_polynom_functions.o $(OBJDIR)/check_main.o
	$(CC) -o unit_tests.exe $^ $(CHECKFLAGS)

$(OBJDIR)/check_%.o : $(UNIT_TESTS_DIR)/check_%.c $(UNIT_TESTS_DIR)/check_test_suites.h
	mkdir -p out;
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY : clean
clean :
	$(RM) -f *.exe
	$(RM) -f out/*.o
