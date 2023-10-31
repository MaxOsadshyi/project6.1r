#include <iostream>
#include <ctime>
#include <cstdlib>
#include <Windows.h>

const int ARRAY_SIZE = 23;
const int LOWER_BOUND = 4;
const int UPPER_BOUND = 68;

// Функція для створення та заповнення масиву випадковими числами
void createArray(int array[], int size, int lower, int upper, int index = 0) {
    if (index < size) {
        array[index] = rand() % (upper - lower + 1) + lower;
        createArray(array, size, lower, upper, index + 1);
    }
}

// Функція для обчислення кількості та суми елементів, які відповідають критерію
void SumArray(int array[], int size, int& count, int& sum, int index = 0) {
    if (index < size) {
        if (array[index] % 2 != 0 && array[index] % 13 != 0) {
            count++;
            sum += array[index];
        }
        SumArray(array, size, count, sum, index + 1);
    }
}

// Функція для заміни елементів, які відповідають критерію, нулями
void ZeroFun(int array[], int size, int index = 0) {
    if (index < size) {
        if (array[index] % 2 != 0 && array[index] % 13 != 0) {
            array[index] = 0;
        }
        ZeroFun(array, size, index + 1);
    }
}

// Функція для виведення масиву на екран
void printArray(int array[], int size, int index = 0) {
    if (index < size) {
        std::cout << array[index] << ' ';
        printArray(array, size, index + 1);
    }
    else {
        std::cout << std::endl;
    }
}

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    srand(time(nullptr));

    int r[ARRAY_SIZE];

    createArray(r, ARRAY_SIZE, LOWER_BOUND, UPPER_BOUND);
    std::cout << "Згенерований масив: ";
    printArray(r, ARRAY_SIZE);

    int count = 0, sum = 0;
    SumArray(r, ARRAY_SIZE, count, sum);
    std::cout << "Кількість елементів, що задовольняють критерію: " << count << std::endl;
    std::cout << "Сума таких елементів: " << sum << std::endl;

    ZeroFun(r, ARRAY_SIZE);
    std::cout << "Модифікований масив: ";
    printArray(r, ARRAY_SIZE);

    return 0;
}
