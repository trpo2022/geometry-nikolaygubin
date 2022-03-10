#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
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

void init_figure(char *str, char *figure)
{
    for (int i = 0; str[i] != '('; i++) {
        figure[i] = str[i];
    }
}

int main()
{
    circle Circle;
    triangle Triangle;
    
    FILE* file = fopen("output.txt", "r");
    int i = 0, k = 0, number_of_figures;
    char *str = NULL, *figure =  NULL, cir[7] = {"circle"}, tri[9] = {"triangle"}, numbers[N];

    printf("Enter the number figures : ");
    scanf("%d", &number_of_figures);

    for (i = 0; i < number_of_figures; i++) {
        str = malloc(N * sizeof(char));
        figure = malloc(N * sizeof(char));

        fgets(str, 100, file);
        init_figure(str, figure);

        free(str);
        free(figure);
    }

    fclose(file);

    return 0;
}