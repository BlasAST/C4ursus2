main.c: main.c prueba.a prueba.h
	gcc main.c prueba.a
prueba.a: prueba.o
	ar rcs prueba.a prueba.o
prueba.o: prueba.c prueba.h
	gcc -c prueba.c

clean:
	rm *.a *.o *.out