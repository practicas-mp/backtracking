CC = g++
CPPFLAGS = -Wall -std=c++0x -g -I$(INCLUDE) -I$(SRC)
INCLUDE = ./include
OBJ = ./obj
SRC = ./src
BIN = ./bin
ALGS = backtrack bb

all: $(OBJ)/Player.o
	$(CC) $(CPPFLAGS) $(SRC)/main.cpp $^ -o $(BIN)/main

install:
	mkdir -p $(BIN) $(OBJ) build

$(OBJ)/Player.o: $(SRC)/structures/Player.cpp
	$(CC) $(CPPFLAGS) -o $@ -c $<

# $(ALGS): %: $(SRC)/algorithms/%.cpp
# 	$(CC) $(CPPFLAGS) $(SRC)/algorithms/$@.cpp -o $(BIN)/$@

pdf: build/memoir.pdf

build/memoir.pdf: memoir.tex
	pdflatex memoir.tex 
	mkdir -p build
	mv memoir.pdf build/memoir.pdf

clean:
	rm -f $(OBJ)/*

mrproper: clean
	rm -fR $(BIN)/* $(DOC)/doxygen

.PHONY: all clean mrproper doc pdf compare