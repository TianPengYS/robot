CC=i586-mingw32msvc-gcc
#CC=gcc

objs=main.o sqlite3.o
libs=-lpthread -ldl

ifeq ($(CC), gcc)
exec=main
else
exec=main.exe
endif

$(exec):$(objs)
ifeq ($(CC), gcc)
	$(CC) -o $(exec) $(objs) $(libs) `pkg-config --libs gtk+-3.0`
else
	$(CC) -o $(exec) $(objs)
endif

ifeq ($(CC), gcc)
main.o:main.c
	$(CC) `pkg-config --cflags gtk+-3.0` -c main.c
endif

.phony:clean
clean:
	rm $(exec) $(objs)
