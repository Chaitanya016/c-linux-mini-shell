	CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
INCLUDE = -Iinclude

SRC = $(wildcard src/*.c)
OBJ = $(SRC:.c=.o)

TARGET = minishell

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $(INCLUDE) $(OBJ) -o $(TARGET)

clean:
	rm -f src/*.o $(TARGET)


