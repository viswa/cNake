.PHONY = all

CC = gcc
OBJS = main.c
OBJ_NAME = cnake
COMPILER_FLAGS = -Wall
LINKER_FLAGS = -lSDL2

all: main.c
	$(CC) $(OBJS) $(COMPILER_FLAGS) -o $(OBJ_NAME) $(LINKER_FLAGS)
