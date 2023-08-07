#цель: зависимость
#[tab] команда


BIN = PhoneBook_DinMem
SOURCES = main.c
HEADERS = main.h
CC := gcc

all:
	$(CC) $(SOURCES) -o $(BIN).out
$(BIN): $(HEADERS)

run: all
	./$(BIN).out

#clean:
#	rm -rf $(BIN) *.o $(BIN).out



















