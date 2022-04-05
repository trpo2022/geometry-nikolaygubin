TARGET = bin/geometry
CC = gcc
CFLAGS = -I/mnt/c/Users/Николай/.vscode/semak2/git/geometry-nikolaygubin/src/ -Wall -Wextra -Werror -O0 -g
CPPFLAGS = -MMD

$(TARGET) : ./obj/src/geometry/*.o ./obj/src/libgeometry/*.a
	$(CC) $(CFLAGS) -o $@ $^ -lm

./obj/src/geometry/*.o : ./src/geometry/main.c
	$(CC) -c $(CFLAGS) $(CPPFLAGS) -o $@ $<

./obj/src/libgeometry/*.a : ./obj/src/libgeometry/*.o 
	ar rcs $@ $^

./obj/src/libgeometry/*.o : ./src/libgeometry/geometry.c
	$(CC) -c $(CFLAGS) $(CPPFLAGS) -o $@ $<

run :
	bin/geometry

clean : 
	rm ./obj/src/geometry/*.d ./obj/src/geometry/*.o ./obj/src/libgeometry/*.d ./obj/src/libgeometry/*.a ./obj/src/libgeometry/*.o $(TARGET)

-include main.d hello.d
