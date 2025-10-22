CC = g++

CFLAGS = -c

TARGET_FILE = stack.exe

TARGET_DIR = ./build/

all: setup

setup: $(TARGET_DIR)main.o $(TARGET_DIR)stack.o $(TARGET_DIR)stack_operations.o
	$(CC) $(TARGET_DIR)main.o $(TARGET_DIR)stack.o $(TARGET_DIR)stack_operations.o -o $(TARGET_DIR)$(TARGET_FILE)

$(TARGET_DIR)main.o: main.cpp stack.h
	mkdir -p $(TARGET_DIR)
	$(CC) $(CFLAGS) main.cpp -o $(TARGET_DIR)main.o

$(TARGET_DIR)stack.o: stack.cpp stack_operations.cpp stack.h
	mkdir -p $(TARGET_DIR)
	$(CC) $(CFLAGS) stack.cpp -o $(TARGET_DIR)stack.o

$(TARGET_DIR)stack_operations.o: stack_operations.cpp
	mkdir -p $(TARGET_DIR)
	$(CC) $(CFLAGS) stack_operations.cpp -o $(TARGET_DIR)stack_operations.o

asm: asm.cpp asm_codes.h
	$(CC) $(CFLAGS) asm.cpp -o asm.exe

run:
	$(TARGET_DIR)$(TARGET_FILE) asmb.txt

clean:
	rm -f $(TARGET_DIR)*.o *.exe $(TARGET_DIR)$(TARGET_FILE)

.PHONY: clean all setup run