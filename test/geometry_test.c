#include <libgeometry/geometry.h>

#include <stdio.h>
#include <ctest.h>
#include <stdlib.h>


CTEST(figure, test1) {
    char str[] = "triangle((-3.0 -2, -1 0.0, -3.0 2.0, -3 -2))", *figure = malloc(sizeof(char) * 10);

    init_figure(str, figure);

    char tri[] = "triangle";

    ASSERT_STR(tri, figure);
}



CTEST(digit, test1) {
    int error = 0;
    char* numbers = malloc(sizeof(char) * 100), str[] = "triangle((-3.0 -2, -1 0.0, -3.0 2.0, -3 -2))"; 
    int len = init_mas_digit(str, numbers, &error);

    char nums[] = "-3.0 -2, -1 0.0, -3.0 2.0, -3 -2";

    ASSERT_EQUAL(32, len);
    ASSERT_STR(nums, numbers);
}


CTEST(area_and_perimetr, test1) {
    
}
CTEST(area_and_perimetr, test2) {
    
}
CTEST(area_and_perimetr, test3) {
    
}


CTEST(init_struct, test1) {
    
}
CTEST(init_struct, test2) {
    
}
