CC := gcc
SRC_DIR := src
INC_DIR := inc

CFLAGS := -std=c99 -I$(INC_DIR) -Wall -Werror -pedantic -Wextra

static : $(SRC_DIR)/*.c
	$(CC) $(CFLAGS) -c $(SRC_DIR)/*.c
	ar -crv libarray.a *.o
	ranlib libarray.a

dynamic : $(SRC_DIR)/*.c
	$(CC) $(CFLAGS) -fPIC -c $(SRC_DIR)/*.c
	$(CC) $(CFLAGS) -shared -o libarray.so *.o

.PHONY : clean
clean :
	$(RM) *.o *.so *.a