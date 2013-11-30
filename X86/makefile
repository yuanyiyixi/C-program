all:hello 
	make run
hello:hello.o
	ld hello.o -o hello
hello.o:hello.s
	as hello.s -o hello.o
run:
	objdump -D hello
	./hello
#	echo $?
