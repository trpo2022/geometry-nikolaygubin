#include <libgeometry/geometry.h>

#include <stdio.h>

int main()
{
    FILE* file = fopen("input.txt", "r");
    int i = 0, k = 0, m = 0, n = 0, number_of_circles, number_of_triangles, number_of_figures,
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
            init_circle(&Circle[m], numbers, &k, len);

            perimetr_and_area_circle(&Circle[m]);
            m++;

        } else if (check_fig(figure, tri) == true) {
            int len = init_mas_digit(str, numbers, &error);
            if (print_errors(error, i) == -1) {
                continue;
            }
            k = 0;
            init_triangle(&Triangle[n], numbers, &k, len);

            perimetr_and_area_triangle(&Triangle[n]);
            n++;
        } else {
            printf("Error at column %d: expected 'circle' or 'triangle'\n",
                   i + 1);
        }

        error = 1;
        free(str);
        free(figure);
    }

    fclose(file);

    for (int i = 0; i < number_of_triangles; i++) {
        if (Triangle->first.x == Triangle->fourth.x
        && Triangle->first.y == Triangle->fourth.y) {
        printf("%d. %s(%.1f %.1f, %.1f %.1f, %.1f %.1f, %.1f %.1f)\n\tperimetr = %.1f\n\tarea = %.1f\n",
        i + 1,
        tri,
        Triangle[i].first.x,
        Triangle[i].first.y,
        Triangle[i].second.x,
        Triangle[i].second.y,
        Triangle[i].third.x,
        Triangle[i].third.y,
        Triangle[i].fourth.x,
        Triangle[i].fourth.y,
        Triangle[i].perimetr,
        Triangle[i].area);
        } else {
            printf("Triangle not a closed\n");
            continue;
        } 
        int x = Circle[0].rad;
        printf("intersects:\n\t");
        if ((x >= Triangle[i].first.x && x >= Triangle[i].first.y) || (x >= Triangle[i].second.x && x >= Triangle[i].second.y) || (x >= Triangle[i].third.x && x >= Triangle[i].third.y)) {
           printf("%d. circle\n\n", 1);
        }
    }

    for (int i = 0; i < number_of_circles; i++) {
        printf("%d. %s(%.1f %.1f, %.1f)\n\tperimetr = %.1f\n\tarea = %.1f\n",
        i + 1,
        cir,
        Circle[i].mid.x,
        Circle[i].mid.y,
        Circle[i].rad,
        Circle[i].perimetr,
        Circle[i].area);
        int x = Circle[0].rad;
        printf("intersects:\n");
        for (int i = 0; i < number_of_triangles; i++) {
            if ((x >= Triangle[i].first.x && x >= Triangle[i].first.y) || (x >= Triangle[i].second.x && x >= Triangle[i].second.y) || (x >= Triangle[i].third.x && x >= Triangle[i].third.y)) {
                putchar('\t');
                printf("%d. triangle\n", i + 1);
            }
        }
    }

    return 0;
}
