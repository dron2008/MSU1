#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool check_recurrent(double c1, double c2, double c3, double b) {
    FILE *file = fopen("input_data.txt", "r");
    if (file == NULL) {
        printf("Ошибка: не удалось открыть файл input_data.txt\n");
        return false;
    }

    double a_prev, a_curr, a_next;

    if (fscanf(file, "%lf", &a_prev) != 1 || fscanf(file, "%lf", &a_curr) != 1) {
        fclose(file);
        return true;
    }

    bool satisfies = true;
    const double EPSILON = 1e-7;

    while (fscanf(file, "%lf", &a_next) == 1) {
        double val = c1 * a_next + c2 * a_curr + c3 * a_prev;

        if (fabs(val - b) > EPSILON) {
            satisfies = false;
            break;
        }

        a_prev = a_curr;
        a_curr = a_next;
    }

    fclose(file);
    return satisfies;
}

int main(void) {
    double c1, c2, c3, b;

    printf("Введите коэффициенты c1, c2, c3 и b через пробел: ");
    if (scanf("%lf %lf %lf %lf", &c1, &c2, &c3, &b) != 4) {
        printf("Ошибка ввода коэффициентов.\n");
        return 1;
    }

    bool result = check_recurrent(c1, c2, c3, b);

    if (result) {
        printf("Да, элементы последовательности удовлетворяют соотношению.\n");
    } else {
        printf("Нет, элементы НЕ удовлетворяют соотношению.\n");
    }

    return 0;
}
