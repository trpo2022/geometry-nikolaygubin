TARGET = bin/geometry
TARGET1 = bin/test
CC = gcc
CFLAGS = -I src/ -I thirdparty/ -Wall -Wextra -Werror -O0 -g
CPPFLAGS = -MMD
.PHONY : test

$(TARGET) : ./obj/src/geometry/main.o ./obj/src/libgeometry/libgeo.a 
	$(CC) $(CFLAGS) -o $@ $^ -lm

./obj/src/geometry/main.o : ./src/geometry/main.c
	$(CC) -c $(CFLAGS) $(CPPFLAGS) -o $@ $<

./obj/src/libgeometry/libgeo.a : ./obj/src/libgeometry/geometry.o
	ar rcs $@ $^

./obj/src/libgeometry/geometry.o : ./src/libgeometry/geometry.c
	$(CC) -c $(CFLAGS) $(CPPFLAGS) -o $@ $<

$(TARGET1) : ./obj/src/libgeometry/libgeo.a ./obj/test/libtest/ltest.o ./obj/test/test/main.o ./obj/src/libgeometry/geometry.o
	$(CC) $(CFLAGS) -o $@ $^ -lm

./obj/test/libtest/ltest.o : ./test/geometry_test.c 
	$(CC) -c $(CFLAGS) $(CPPFLAGS) -o $@ $<

./obj/test/test/main.o : ./test/main.c
	$(CC) -c $(CFLAGS) -o $@ $^

test : $(TARGET1)
	$(TARGET1)

run :
	$(TARGET)

clean : 
	rm $(TARGET) $(TARGET1) ./obj/src/geometry/main.o ./obj/src/libgeometry/libgeo.a ./obj/src/libgeometry/geometry.o ./obj/src/libgeometry/geometry.d ./obj/src/geometry/main.d ./obj/test/libtest/ltest.d ./obj/test/libtest/ltest.o ./obj/test/test/main.o   

-include ./obj/src/geometry/main.d ./obj/src/libgeometry/*.d ./obj/test/libtest/*.d ./obj/test/libtest/*.d
