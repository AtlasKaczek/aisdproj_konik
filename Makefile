
default: build

build:
	gcc -o main.out main.c

run: build
	./main.out