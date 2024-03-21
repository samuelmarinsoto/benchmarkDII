CC = clang++
CFLAGS = -std=c++11 -Wall -Wextra
LDFLAGS = -pthread

SRC = main.cpp
EXEC = benchmark

all: $(EXEC)

$(EXEC): $(SRC)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $(SRC)

clean:
	rm -f $(EXEC)

.PHONY: all clean
