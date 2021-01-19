CC := gcc
OBJDIR := out
OBJS := $(OBJDIR)/matrix_functions.o $(OBJDIR)/matrix_io.o
SRCDIR := src
INCDIR := include
CFLAGS := -I${INCDIR} -std=c99 -Wall  -pedantic -Wextra
RM := rm

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

.PHONY : clean
clean :
	$(RM) -f *.exe
	$(RM) -f out/*.o
