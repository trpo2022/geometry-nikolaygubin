TARGET = bin/geometry
TARGET1 = bin/test
CC = gcc
CFLAGS = -I src/ -I thirdparty/ -Wall -Wextra -Werror -O0 -g
CPPFLAGS = -MMD
.PHONY : clean
.PHONY : test

$(TARGET) : ./obj/src/geometry/*.o ./obj/src/libgeometry/*.a 
	$(CC) $(CFLAGS) -o $@ $^ -lm

./obj/src/geometry/*.o : ./src/geometry/main.c
	$(CC) -c $(CFLAGS) -o $@ $<

./obj/src/libgeometry/*.a : ./obj/src/libgeometry/*.o ./obj/test/libtest/libtest.o
	ar rcs $@ $^

./obj/src/libgeometry/*.o : ./src/libgeometry/geometry.c 
	$(CC) -c $(CFLAGS) -o $@ $<

./obj/test/libtest/libtest.o : ./test/geometry_test.c
	$(CC) -c $(CFLAGS) -o $@ $<

$(TARGET1) : ./obj/src/libgeometry/*.a ./obj/test/libtest/libtest.o ./obj/test/test/main.o
	$(CC) $(CFLAGS) -o $@ $^ -lm

./obj/test/test/main.o : ./test/main.c
	$(CC) -c $(CFLAGS) -o $@ $^

test : $(TARGET1)
	$(TARGET1)

run :
	$(TARGET)

clean : 
	rm ./obj/src/geometry/*.o ./obj/src/libgeometry/*.a ./obj/src/libgeometry/*.o $(TARGET) ./obj/test/libtest/*.o $(TARGET1) ./obj/test/test/*.o
