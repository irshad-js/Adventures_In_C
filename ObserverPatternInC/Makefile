CC=gcc
CFLAGS=-I.
DEPS = Subject.h Observer.h unity.h unity_fixture.h unity_fixture_internals.h unity_internals.h unity_memory.h
#OBJ = main.o BaseClass.o DerivedClass.o
OBJ = main.o Subject.o Observer.o unity.o unity_fixture.o unity_memory.o

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