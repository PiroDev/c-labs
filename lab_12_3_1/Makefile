CC := gcc
INCDIR := lib/inc
CFLAGS := -I${INCDIR} -std=c99 -Wall -Werror -Wextra
RM := rm

ifeq ($(mode), debug)
	CFLAGS += -g3
endif

ifeq ($(mode), release)
	CFLAGS += -DNDEBUG -g0
endif

app.exe : main.c
	@if [ "$(lib-mode)" == "static" ]; then \
		cd lib; make static; \
		cd ..; \
		$(CC) $(CFLAGS) -L`pwd`/lib main.c -larray -o app.exe; \
	else \
		cd lib; make dynamic; \
		cd ..; \
		if [ "$(lib-mode)" == "module" ]; then \
			$(CC) $(CFLAGS) -DDYN_LINK main.c -ldl -o app.exe; \
		else \
			$(CC) $(CFLAGS) lib/libarray.so main.c -o app.exe; \
		fi \
	fi

.PHONY : clean
clean :
	$(RM) -f *.exe
	cd lib; make clean;
