ifeq ($(OS),Windows_NT)
	EXT := .exe
else
	EXT := 
endif
CC = gcc
CFLAGS = -Wall -Wextra -g -O2 -Iinclude
SRC = $(shell find src -name "*.c")
OBJ = $(patsubst src/%.c,out/%.o,$(SRC))
TARGET = bin/proju$(EXT)
all: $(TARGET)
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ -lm
out/%.o: src/%.c 
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@ 
