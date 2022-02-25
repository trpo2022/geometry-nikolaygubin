#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE* file = fopen("output.txt", "r");
    int a = 0, b = 0;
    int i = 0, k = 0, N = 100, number_of_figures;
    char *str = NULL, cir[] = {"circle"}, tri[] = {"triangle"}, numbers[N];

    printf("Enter the number figures : ");
    scanf("%d", &number_of_figures);

    for (i = 0; i < number_of_figures; i++) {
        str = malloc(N * sizeof(char));
        fgets(str, 100, file);

        if (strstr(str, cir) != NULL) {
            for (int p = 0; p < N; p++) {
                if (str[p] == 41) {
                    break;
                }
                if ((str[p] >= 48 && str[p] <= 57) || str[p] == 44 || str[p] == 46 || str[p] == 32 || str[p] == 45) {
                    k++;
                    numbers[k] = str[p];
                    if (a == 0) {
                        printf("circle(");
                        a++;
                    }
                    printf("%c", numbers[k]);
                }
            }
            a = 0;
            if (b == 0) {
                printf(")");
                b++;
            }
            printf("\n");
            b = 0;
        } else if (strstr(str, tri) != NULL) {
            for (int p = 0; p < N - 1; p++) {
                if (str[p] == 41) {
                    break;
                }
                if ((str[p] >= 48 && str[p] <= 57) || str[p] == 44 || str[p] == 46 || str[p] == 32 || str[p] == 45) {
                    k++;
                    numbers[k] = str[p];
                    if (a == 0) {
                        printf("triangle((");
                        a++;
                    }
                    printf("%c", numbers[k]);
                }
            }
            a = 0;
            if (b == 0) {
                printf("))");
                b++;
            }
            printf("\n");
            b = 0;
        }
    }

    printf("\n");
    free(str);

    fclose(file);

    return 0;
}