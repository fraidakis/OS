# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -pedantic

# File names and executables
SRCS = fork.c pipe.c kill.c pid_to_file.c add.c
TARGETS = fork pipe kill pid_to_file add

# Default target
all: $(TARGETS)

# Build each target directly from .c files
fork: fork.c
	$(CC) $(CFLAGS) -o $@ $<

pipe: pipe.c
	$(CC) $(CFLAGS) -o $@ $<

kill: kill.c
	$(CC) $(CFLAGS) -o $@ $<

pid_to_file: pid_to_file.c
	$(CC) $(CFLAGS) -o $@ $<

add: add.c
	$(CC) $(CFLAGS) -o $@ $<

# Clean up executables
clean:
	rm -f $(TARGETS)

# Phony targets
.PHONY: all clean
