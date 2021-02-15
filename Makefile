CC=g++

CC_FLAGS=-W -Wall -pedantic -std=c++11

build: main

main: main.cpp Diretorio.cpp Diretorio.hpp Balde.cpp Balde.hpp
	$(CC) $(CC_FLAGS) -o $@ Diretorio.cpp Balde.cpp main.cpp

test: testes.cpp Balde.cpp Diretorio.cpp printbits.hpp
	$(CC) $(CC_FLAGS) -o $@ testes.cpp Balde.cpp Diretorio.cpp
