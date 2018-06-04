CXX=g++
CXXFLAGS=-std=c++17 -Wall -Wextra -Werror -pedantic -O0 -g3 -I../include/
LDFLAGS=-lSDL2 -lpng

OBJS=main.o
BIN=app.out


all: $(BIN)
	$(CXX) $(LDFLAGS) -o $(BIN) $(OBJS)

$(BIN): $(OBJS)

clean:
	$(RM) $(OBJS) $(BIN)
