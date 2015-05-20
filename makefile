CC = g++
CPPFLAGS = -Wall -std=c++0x -g -I$(INCLUDE) -I$(SRC)
SRC = ./src
INCLUDE = ./include
BIN = ./bin
ALGS = backtrack

all:
	$(CC) $(CPPFLAGS) $(SRC)/main.cpp -o $(BIN)/main

install:
	mkdir -p $(BIN) build

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