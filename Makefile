
default: build

build:
	gcc -o main.out main.c funkcje.c

run: build
	./main.out