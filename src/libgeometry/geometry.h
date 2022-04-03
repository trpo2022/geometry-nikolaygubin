#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#define N 100

typedef struct 
{
    float x;
    float y;
} point;

typedef struct 
{
    point mid;
    float rad;    
}circle;

typedef struct 
{
    point first;
    point second;
    point third;
    point fourth;
} triangle;

void init_figure(char *str, char *figure);

bool check_fig(char *figure, char *ex_fig);

int init_mas_digit(char *str, char *numbers, int *error);

float init_coordinate(char *numbers, int *k, int len);

float len_of_side(float x1, float y1, float x2, float y2);