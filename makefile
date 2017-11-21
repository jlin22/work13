all : pie.c
	gcc pie.c
run : all
	./a.out
