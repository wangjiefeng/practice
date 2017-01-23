PROGS = test1
all:
	${PROGS}
test1:
	gcc test1.c  -o test1 `pkg-config --cflags --libs gtk+-2.0`
clean:
	rm -f ${PROGS}
