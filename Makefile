.PHONY = all clean

CC = gcc
SRCS = $(shell find -name "*.c")
OBJ_NAME = cnake
COMPILER_FLAGS = -Wall
LINKER_FLAGS = -lSDL2

all: $(SRCS)
	$(CC) $(SRCS) $(COMPILER_FLAGS) -o $(OBJ_NAME) $(LINKER_FLAGS)

clean:
	rm cnake
