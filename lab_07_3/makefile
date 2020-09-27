CC := gcc
CFLAGS := -std=c99 -Wall -Werror -pedantic -Wextra
OBJDIR := out
OBJS := $(OBJDIR)/functions.o $(OBJDIR)/input_output.o
SRCDIR := src
INCDIR := inc
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
	$(RM) *.exe
	cd out;	$(RM) *.o