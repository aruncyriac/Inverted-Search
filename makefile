OBJ:= $(patsubst %.c,%.o,$(wildcard *.c))
inverted.exe: $(OBJ)
	gcc -o $@ $^
clean:
	rm *.o
	rm *.exe
