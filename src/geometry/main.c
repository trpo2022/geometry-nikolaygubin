#include <libgeometry/geometry.h>

#include <stdio.h>

int main()
{
    FILE* file = fopen("input.txt", "r");
    int i = 0, k = 0, number_of_circles, number_of_triangles, number_of_figures,
        error = 1;
    char *str = NULL, *figure = NULL, cir[7] = {"circle"},
         tri[9] = {"triangle"}, numbers[N];

    printf("Enter the number circles : ");
    scanf("%d", &number_of_circles);
    printf("Enter the number triangles : ");
    scanf("%d", &number_of_triangles);

    circle Circle[number_of_circles];
    triangle Triangle[number_of_triangles];

    number_of_figures = number_of_circles + number_of_triangles;

    for (i = 0; i < number_of_figures; i++) {
        str = malloc(N * sizeof(char));
        figure = malloc(N * sizeof(char));

        fgets(str, 100, file);
        init_figure(str, figure);

        if (check_fig(figure, cir) == true) {
            int len = init_mas_digit(str, numbers, &error);
            if (print_errors(error, i) == -1) {
                continue;
            }

            k = 0;
            init_and_print_circle(&Circle[i], numbers, &k, len, figure);

            float circle_perimeter, circle_area;

            perimetr_and_area_circle(
                    &Circle[i], &circle_perimeter, &circle_area);

        } else if (check_fig(figure, tri) == true) {
            int len = init_mas_digit(str, numbers, &error);
            if (print_errors(error, i) == -1) {
                continue;
            }
            k = 0;
            init_and_print_triangle(&Triangle[i], numbers, &k, len, figure);

            float triangle_perimeter, triangle_area;

            perimetr_and_area_triangle(
                    &Triangle[i], &triangle_perimeter, &triangle_area);
        } else {
            printf("Error at column %d: expected 'circle' or 'triangle'\n",
                   i + 1);
        }

        error = 1;
        free(str);
        free(figure);
    }

    fclose(file);

    return 0;
}
