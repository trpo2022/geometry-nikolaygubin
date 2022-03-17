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

int init_mas_digit(char *str, char *numbers, int *error)
{
    int i, k = 0;
    for (i = 0; i < N; i++) {
        if (str[i] == ')') {
            *error = 0;
            if ((str[i + 1] >= '0' && str[i + 1] <= '9') || (str[i + 2] >= '0' && str[i + 2] <= '9')) {
                *error = 2;
            }
            break;
        }
        if ((str[i] >= '0' && str[i] <= '9') || str[i] == '.' || str[i] == ',' || str[i] == ' ' || str[i] == '-') {
            numbers[k] = str[i];
            k += 1;
        }    
    }
    return k;
}

float init_coordinate(char *numbers, int *k, int len)
{
    float coord = 0, del = 10; // del - делитель разряда
    int j = *k;
    if (numbers[j] == '-') {
        j++;
        while (numbers[j] != '.' && numbers[j] != ' ' && numbers[j] != ',') {
            if (j == len) {
                coord = coord - 2 * coord;
                return coord;
            }
            coord *= 10;
            coord += (numbers[j] - '0');
            j++;
        }
        if (numbers[j] == '.') {
            j++;
            while (numbers[j] != ',' && numbers[j] != ' ') {
                coord += (numbers[j] - '0') / del;
                del *= 10;
                if (j == len) {
                    coord = coord - 2 * coord;
                    return coord;
                }
                j++;
            }
        }
        if (numbers[j] == ',') {
            j++;
        }
        j++;
        *k = j;
        coord = coord - 2 * coord;
        return coord;
    }

    else {
        while (numbers[j] != '.' && numbers[j] != ' ' && numbers[j] != ',') {
            if (j == len) {
                return coord;
            }
            coord *= 10;
            coord += (numbers[j] - '0');
            j++;
        }
        if (numbers[j] == '.') {
            j++;
            while (numbers[j] != ',' && numbers[j] != ' ') {
                coord += (numbers[j] - '0') / del;
                del *= 10;
                if (j == len) {
                    return coord;
                }
                j++;
            }
        }
        if (numbers[j] == ',') {
            j++;
        }
        j++;
        *k = j;
        return coord;
    }
}


int main()
{
    circle Circle;
    triangle Triangle;

    FILE* file = fopen("output.txt", "r");
    int i = 0, k = 0, number_of_figures, error = 1;
    char *str = NULL, *figure =  NULL, cir[7] = {"circle"}, tri[9] = {"triangle"}, numbers[N];

    printf("Enter the number figures : ");
    scanf("%d", &number_of_figures);

    for (i = 0; i < number_of_figures; i++) {
        str = malloc(N * sizeof(char));
        figure = malloc(N * sizeof(char));

        fgets(str, 100, file);
        init_figure(str, figure);


        if (check_fig(figure, cir) == true) {
            int len = init_mas_digit(str, numbers, &error);
            if (error == 1) {
                printf("Error at column %d: expected ')'", i + 1);
                printf("\n");
                continue;;
            }
            if (error == 2) {
                printf("Error at column %d: unexpected token", i + 1);
                printf("\n");
                continue;;
            }

            k = 0;
            Circle.mid.x = init_coordinate(numbers, &k, len);
            Circle.mid.y = init_coordinate(numbers, &k, len);

            Circle.rad = init_coordinate(numbers, &k, len) ;

            printf("%s(%.1f %.1f, %.1f)\n",
            figure, 
            Circle.mid.x, Circle.mid.y, 
            Circle.rad);
        }
        else if (check_fig(figure, tri) == true) {
            int len = init_mas_digit(str, numbers, &error);
            if (error == 1) {
                printf("Error at column %d: expected ')'", i + 1);
                printf("\n");
                continue;;
            }
            if (error == 2) {
                printf("Error at column %d: unexpected token", i + 1);
                printf("\n");
                continue;;
            }


            k = 0;
            Triangle.first.x = init_coordinate(numbers, &k, len);
            Triangle.first.y = init_coordinate(numbers, &k, len);

            Triangle.second.x = init_coordinate(numbers, &k, len);
            Triangle.second.y = init_coordinate(numbers, &k, len);

            Triangle.third.x = init_coordinate(numbers, &k, len);
            Triangle.third.y = init_coordinate(numbers, &k, len);

            Triangle.fourth.x = init_coordinate(numbers, &k, len);
            Triangle.fourth.y = init_coordinate(numbers, &k, len);

            if (Triangle.first.x == Triangle.fourth.x && Triangle.first.y == Triangle.fourth.y){
                printf("%s(%.1f %.1f, %.1f %.1f, %.1f %.1f, %.1f %.1f)\n", 
                figure,
                Triangle.first.x, Triangle.first.y, 
                Triangle.second.x, Triangle.second.y, 
                Triangle.third.x, Triangle.third.y, 
                Triangle.fourth.x, Triangle.fourth.y);   
            }
            else {
                printf("Error at column %d: the Triangle does not close\n", i + 1);
            }
        }
        else {
            printf("Error at column %d: expected 'circle' or 'triangle'\n", i + 1);
        }

        error = 1;
        free(str);
        free(figure);
    }

    fclose(file);

    return 0;
}