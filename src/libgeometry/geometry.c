#include <libgeometry/geometry.h>

void init_figure(char* str, char* figure)
{
    for (int i = 0; str[i] != '('; i++) {
        figure[i] = str[i];
    }
}

bool check_fig(char* figure, char* ex_fig)
{
    if (strlen(figure) != strlen(ex_fig)) {
        return false;
    }
    for (long unsigned int i = 0; i < strlen(ex_fig); i++) {
        if (figure[i] != ex_fig[i]) {
            return false;
        }
    }
    return true;
}

int init_mas_digit(char* str, char* numbers, int* error)
{
    int i, k = 0;
    for (i = 0; i < N; i++) {
        if (str[i] == ')') {
            *error = 0;
            if ((str[i + 1] >= '0' && str[i + 1] <= '9')
                || (str[i + 2] >= '0' && str[i + 2] <= '9')) {
                *error = 2;
            }
            break;
        }
        if ((str[i] >= '0' && str[i] <= '9') || str[i] == '.' || str[i] == ','
            || str[i] == ' ' || str[i] == '-') {
            numbers[k] = str[i];
            k += 1;
        }
    }
    return k;
}

float init_coordinate(char* numbers, int* k, int len)
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

float len_of_side(float x1, float y1, float x2, float y2)
{
    float first_katet, second_katet, hypotenuse;

    if (x2 > x1) {
        first_katet = x2 - x1;
    } else {
        first_katet = x1 - x2;
    }

    if (y2 > y1) {
        second_katet = y2 - y1;
    } else {
        second_katet = y1 - y2;
    }
    hypotenuse = sqrt(pow(first_katet, 2) + pow(second_katet, 2));

    return hypotenuse;
}

int print_errors(int error, int i)
{
    if (error == 1) {
        printf("Error at column %d: expected ')'", i + 1);
        printf("\n");
        return -1;
    }
    if (error == 2) {
        printf("Error at column %d: unexpected token", i + 1);
        printf("\n");
        return -1;
    }

    return 0;
}

void perimetr_and_area_circle(circle* Circle)
{
    float circle_perimeter = 2 * M_PI * Circle->rad;
    float circle_area = M_PI * pow(Circle->rad, 2);
    Circle->perimetr = circle_perimeter;
    Circle->area = circle_area;
}

void perimetr_and_area_triangle(triangle* Triangle)
{
    float first_side = len_of_side(
            Triangle->first.x,
            Triangle->first.y,
            Triangle->second.x,
            Triangle->second.y);
    float second_side = len_of_side(
            Triangle->second.x,
            Triangle->second.y,
            Triangle->third.x,
            Triangle->third.y);
    float third_side = len_of_side(
            Triangle->third.x,
            Triangle->third.y,
            Triangle->fourth.x,
            Triangle->fourth.y);

    float polu_perimeter = (first_side + second_side + third_side) / 2;

    float triangle_perimeter = polu_perimeter * 2;
    float triangle_area = sqrt(
            polu_perimeter * (polu_perimeter - first_side)
            * (polu_perimeter - second_side) * (polu_perimeter - third_side));
    Triangle->perimetr = triangle_perimeter;
    Triangle->area = triangle_area;
}

void init_circle(circle* Circle, char* numbers, int* k, int len)
{
    Circle->mid.x = init_coordinate(numbers, k, len);
    Circle->mid.y = init_coordinate(numbers, k, len);

    Circle->rad = init_coordinate(numbers, k, len);
}

void init_triangle(triangle* Triangle, char* numbers, int* k, int len)
{
    Triangle->first.x = init_coordinate(numbers, k, len);
    Triangle->first.y = init_coordinate(numbers, k, len);

    Triangle->second.x = init_coordinate(numbers, k, len);
    Triangle->second.y = init_coordinate(numbers, k, len);

    Triangle->third.x = init_coordinate(numbers, k, len);
    Triangle->third.y = init_coordinate(numbers, k, len);

    Triangle->fourth.x = init_coordinate(numbers, k, len);
    Triangle->fourth.y = init_coordinate(numbers, k, len);
}
