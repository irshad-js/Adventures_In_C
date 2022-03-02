CC=gcc
CFLAGS=-I.
DEPS = BaseClass.h DerivedClass.h
#OBJ = main.o BaseClass.o DerivedClass.o
OBJ = main.o BaseClass.o DerivedClass.o

build: target

complete: clean target run

%.o: %.c $(DEPS)
	$(CC) -c -g -o $@ $< $(CFLAGS)

target: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	powershell " Remove-Item *.exe"
	powershell " Remove-Item *.o"

run:
	powershell " .\target"