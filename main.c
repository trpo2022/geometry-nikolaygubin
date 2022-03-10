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

bool check_fig(char *figure, char *ex_fig)
{
    if (strlen(figure) != strlen(ex_fig)) {
        return false;
    }
    for (int i = 0; i < strlen(ex_fig); i++) {
        if (figure[i] != ex_fig[i]) {
            return false;
        }
    }
    return true;
}

int init_mas_digit(char *str, char *numbers)
{
    int i, k = 0;
    for (i = 0; i < N; i++) {
        if (str[i] == ')') {
            break;
        }
        if ((str[i] >= '0' && str[i] <= '9') || str[i] == '.' || str[i] == ',' || str[i] == ' ' || str[i] == '-') {
            numbers[k] = str[i];
            k += 1;
        }    
    }
    return k;
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


        if (check_fig(figure, cir) == true) {
            int len = init_mas_digit(str, numbers);
        }
        else if (check_fig(figure, tri) == true) {
            int len = init_mas_digit(str, numbers);  
        }

        free(str);
        free(figure);
    }

    fclose(file);

    return 0;
}