PROGS = test1 test2 test3 container entry spin
all:
	${PROGS}
test1:
	gcc test1.c  -o test1 `pkg-config --cflags --libs gtk+-2.0`
test2:
	gcc test2.c  -o test2 `pkg-config --cflags --libs gtk+-3.0`
test3:
	gcc test3.c  -o test3 `pkg-config --cflags --libs gtk+-2.0`
container:
	gcc container.c  -o container `pkg-config --cflags --libs gtk+-2.0`
entry:
	gcc entry.c  -o entry `pkg-config --cflags --libs gtk+-2.0`
spin:
	gcc spin.c  -o spin `pkg-config --cflags --libs gtk+-2.0`
tree:
	gcc tree.c  -o tree `pkg-config --cflags --libs gtk+-2.0`
clean:
	rm -f ${PROGS}
