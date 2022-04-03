#include <libgeometry/geometry.h>

int main()
{
    circle Circle;
    triangle Triangle;

    FILE* file = fopen("input.txt", "r");
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

            float circle_perimeter = 2 * M_PI * Circle.rad, circle_area = M_PI * pow(Circle.rad, 2);
            printf("Perimetr = %.1f\nArea = %.1f\n\n", circle_perimeter, circle_area);
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

            float first_side = len_of_side(Triangle.first.x, Triangle.first.y, Triangle.second.x, Triangle.second.y);
            float second_side = len_of_side(Triangle.second.x, Triangle.second.y, Triangle.third.x, Triangle.third.y);
            float third_side = len_of_side(Triangle.third.x, Triangle.third.y, Triangle.fourth.x, Triangle.fourth.y);
            float polu_perimeter = (first_side + second_side + third_side) / 2;

            float triangle_perimeter = polu_perimeter * 2, triangle_area = sqrt(polu_perimeter * (polu_perimeter - first_side)\
            * (polu_perimeter - second_side) * (polu_perimeter - third_side));
            printf("Perimetr = %.1f\nArea = %.1f\n\n", triangle_perimeter, triangle_area);
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