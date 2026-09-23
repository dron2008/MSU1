#include <stdio.h>
#include <stdbool.h>

bool are_all_equal(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        return false;
    }

    double first;
    if (fscanf(file, "%lf", &first) != 1) {
        fclose(file);
        return true;
    }

    double current;
    bool all_equal = true;

    while (fscanf(file, "%lf", &current) == 1) {
        if (current != first) {
            all_equal = false;
            break;
        }
    }

    fclose(file);
    return all_equal;
}

int main(void) {
    char filename[256];

    printf("Введите имя файла: ");
    if (scanf("%255s", filename) != 1) {
        return 1;
    }

    bool result = are_all_equal(filename);

    if (result) {
        printf("Да, все элементы последовательности равны между собой.\n");
    } else {
        printf("Нет, не все элементы равны (или файл не найден).\n");
    }

    return 0;
}
