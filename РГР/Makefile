# Project: Afanasev_shifr

CXX      = g++
CC       = gcc
OBJ      = main.o fileutils.o binary.o gronsfeld.o vigenere.o auth.o menu.o
LINKOBJ  = main.o fileutils.o binary.o gronsfeld.o vigenere.o auth.o menu.o
LIBS     = 
CXXFLAGS = -Wall -std=c++11
CFLAGS   = -Wall
BIN      = Afanasev_shifr
RM       = rm -f

.PHONY: all all-before all-after clean clean-custom

all: all-before $(BIN) all-after

clean: clean-custom
	${RM} $(OBJ) $(BIN)

$(BIN): $(OBJ)
	$(CXX) $(LINKOBJ) -o $(BIN) $(LIBS)

main.o: main.cpp
	$(CXX) -c main.cpp -o main.o $(CXXFLAGS)

fileutils.o: fileutils.cpp
	$(CXX) -c fileutils.cpp -o fileutils.o $(CXXFLAGS)

binary.o: binary.cpp
	$(CXX) -c binary.cpp -o binary.o $(CXXFLAGS)

gronsfeld.o: gronsfeld.cpp
	$(CXX) -c gronsfeld.cpp -o gronsfeld.o $(CXXFLAGS)

vigenere.o: vigenere.cpp
	$(CXX) -c vigenere.cpp -o vigenere.o $(CXXFLAGS)

auth.o: auth.cpp
	$(CXX) -c auth.cpp -o auth.o $(CXXFLAGS)

menu.o: menu.cpp
	$(CXX) -c menu.cpp -o menu.o $(CXXFLAGS)
