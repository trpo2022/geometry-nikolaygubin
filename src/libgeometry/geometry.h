#pragma once

#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 100

typedef struct {
    float x;
    float y;
} point;

typedef struct {
    point mid;
    float rad;
    float perimetr;
    float area;
} circle;

typedef struct {
    point first;
    point second;
    point third;
    point fourth;
    float perimetr;
    float area;
} triangle;

void init_figure(char* str, char* figure);

bool check_fig(char* figure, char* ex_fig);

int init_mas_digit(char* str, char* numbers, int* error);

float init_coordinate(char* numbers, int* k, int len);

float len_of_side(float x1, float y1, float x2, float y2);

int print_errors(int error, int i);

void perimetr_and_area_circle(circle* Circle);

void perimetr_and_area_triangle(triangle* Triangle);

void init_circle(
        circle* Circle, char* numbers, int* k, int len);

void init_triangle(
        triangle* Triangle, char* numbers, int* k, int len);
