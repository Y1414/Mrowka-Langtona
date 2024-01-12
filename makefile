CC = gcc

all: 
	@$(CC) -o mrówka main.c read.c save.c ant.c grid.c -Wall
