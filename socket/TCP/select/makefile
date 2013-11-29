all:
	gcc server-select.c wrap.c -o server
	gcc m-client.c wrap.c -o client

.PHONY:clean

clean:
	-rm server
	-rm client
