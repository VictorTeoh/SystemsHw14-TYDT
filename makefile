all: controller.o
	gcc -o controller controller.o

controller.o: controller.c
	gcc -c controller.c

run: all
	./controller

clean:
	rm -rf *.o *~ controller
