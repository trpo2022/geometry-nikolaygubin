#include <libgeometry/geometry.h>

#include <ctest.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

CTEST(figure, test1)
{
    char str[] = "triangle((-3.0 -2, -1 0.0, -3.0 2.0, -3 -2))",
         *figure = malloc(sizeof(char) * 10);

    init_figure(str, figure);

    char tri[] = "triangle";

    ASSERT_STR(tri, figure);
}

CTEST(digit, test1)
{
    int error = 0;
    char *numbers = malloc(sizeof(char) * 100),
         str[] = "triangle((-3.0 -2, -1 0.0, -3.0 2.0, -3 -2))";
    int len = init_mas_digit(str, numbers, &error);

    char nums[] = "-3.0 -2, -1 0.0, -3.0 2.0, -3 -2";
    int exp_len = strlen(nums);

    ASSERT_EQUAL(exp_len, len);
    ASSERT_STR(nums, numbers);
}

CTEST(area_and_perimetr, test1)
{
    float x1 = -3, x2 = -3, y1 = 2, y2 = -2;
    float real = len_of_side(x1, y1, x2, y2);

    float exp = 4;

    ASSERT_DBL_NEAR(exp, real);
}
CTEST(area_and_perimetr, test2)
{
    circle Circle; // circle(0 0, 1.5)
    Circle.mid.x = 0;
    Circle.mid.y = 0;
    Circle.rad = 1.5;

    perimetr_and_area_circle(&Circle);

    float perimetr = 9.4248, area = 7.0686;

    ASSERT_DBL_NEAR(Circle.perimetr, perimetr);
    ASSERT_DBL_NEAR(Circle.area, area);
}
CTEST(area_and_perimetr, test3)
{
    triangle Triangle; // triangle((-3.0 -2, -1 0.0, -3.0 2.0, -3 -2))

    Triangle.first.x = -3;
    Triangle.first.y = -2;

    Triangle.second.x = -1;
    Triangle.second.y = 0;

    Triangle.third.x = -3;
    Triangle.third.y = 2;

    Triangle.fourth.x = -3;
    Triangle.fourth.y = -2;

    perimetr_and_area_triangle(&Triangle);

    float perimetr = 9.6569, area = 4;

    ASSERT_DBL_NEAR(Triangle.perimetr, perimetr);
    ASSERT_DBL_NEAR(Triangle.area, area);
}

CTEST(init_struct, test1)
{
    circle Circle; // circle(0 0, 1.5)
    char numbers[100] = "0 0, 1.5";
    int k = 0, len = strlen(numbers);
    init_circle(&Circle, numbers, &k, len);

    float x = 0, y = 0, rad = 1.5;

    ASSERT_DBL_NEAR(Circle.mid.x, x);
    ASSERT_DBL_NEAR(Circle.mid.y, y);
    ASSERT_DBL_NEAR(Circle.rad, rad);
}
CTEST(init_struct, test2)
{
    triangle Triangle; // triangle((-3.0 -2, -1 0.0, -3.0 2.0, -3 -2))
    char numbers[100] = "-3.0 -2, -1 0.0, -3.0 2.0, -3 -2";
    int k = 0, len = strlen(numbers);
    init_triangle(&Triangle, numbers, &k, len);

    float x1 = -3, y1 = -2, x2 = -1, y2 = 0, x3 = -3, y3 = 2, x4 = -3, y4 = -2;

    ASSERT_DBL_NEAR(Triangle.first.x, x1);
    ASSERT_DBL_NEAR(Triangle.first.y, y1);
    ASSERT_DBL_NEAR(Triangle.second.x, x2);
    ASSERT_DBL_NEAR(Triangle.second.y, y2);
    ASSERT_DBL_NEAR(Triangle.third.x, x3);
    ASSERT_DBL_NEAR(Triangle.third.y, y3);
    ASSERT_DBL_NEAR(Triangle.fourth.x, x4);
    ASSERT_DBL_NEAR(Triangle.fourth.y, y4);
}
