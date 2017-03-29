OBJS = a.o b.o c.o
#CFLAGS =

all: a.out
	@echo make all
d:
	touch a
	date >> a
	cat a
run: a.out
	./a.out
a.o: a.c
	gcc a.c -c
b.o: b.c
	@echo --compile b--
	gcc b.c -c
c.o: c.c
	gcc c.c -c
.c.o:
	gcc $< -c
a.out: $(OBJS)
	gcc $(OBJS)
clean:
	rm $(OBJS)
	rm a.out
