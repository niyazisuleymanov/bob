TARGET=main

all:
	gcc src/main.c src/read.c src/builtin.c src/parse.c src/execute.c -o $(TARGET)

clean:
	rm $(TARGET)