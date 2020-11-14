#include "generateMagicSquare.h"

#include <stdio.h>
#include <stdlib.h>

void generateMagicSquare(int square[][cols])
{
    int magicSum = (rows * (rows * rows + 1)) / 2;
    do {
        randomizeSquare(square);
    } while (!isMagicSquare(square, magicSum));
}

void randomizeSquare(int square[rows][cols])
{
    int occupiedNumbers[rows * cols];
    setOccupiedNumbers(occupiedNumbers, rows * cols);
    for (int row = 0, i = 0; row < rows; ++row) {
        for (int col = 0; col < cols; ++col, ++i) {
            // do {
                int index = rand() % (rows * cols) - i;
                square[row][col] = occupiedNumbers[index];
            // } while (isOccupied(square[row][col], occupiedNumbers, rows * cols));
            // occupiedNumbers[i] = square[row][col];
            swapNumbers(occupiedNumbers[rows * cols - 1 - i], occupiedNumbers[index]);
        }
    }
}

void setOccupiedNumbers(int occupiedNumbers[], int size)
{
    for (int i = 0; i < size; ++i) {
        occupiedNumbers[i] = i + 1;
    }
}

void swapNumbers(int lhs, int rhs) {
    int temp = lhs;
    lhs = rhs;
    rhs = temp;
}

int isOccupied(int value, int occupiedNumbers[], int size)
{
    for (int i = 0; i < size; ++i) {
        if (occupiedNumbers[i] == value) {
            return 1;  // false;
        }
    }
    return 0;  // true;
}

int isMagicSquare(int square[rows][cols], int magicSum) {
    return (isSumInRowsEqualTo(magicSum, square) && isSumInColsEqualTo(magicSum, square) && isSumInDiagonalsEqualTo(magicSum, square));
}

int isSumInRowsEqualTo(int expectedSum, int square[rows][cols])
{
    int actualSum = 0;
    for (int row = 0; row < rows; ++row) {
        for (int col = 0; col < cols; ++col) {
            actualSum += square[row][col];
        }
        if (actualSum != expectedSum) {
            return 0;  // false;
        }
        actualSum = 0;
    }
    return 1;  // true;
}

int isSumInColsEqualTo(int expectedSum, int square[rows][cols])
{
    int actualSum = 0;
    for (int col = 0; col < cols; ++col) {
        for (int row = 0; row < rows; ++row) {
            actualSum += square[row][col];
        }
        if (actualSum != expectedSum) {
            return 0;  // false;
        }
        actualSum = 0;
    }
    return 1;  // true;
}

int isSumInDiagonalsEqualTo(int expectedSum, int square[rows][cols])
{
    int actualSum = 0;
    for (int col = 0, row = 0; col < cols; ++col, ++row) {
        actualSum += square[row][col];
    }
    if (actualSum != expectedSum) {
        return 0;
    }
    actualSum = 0;
    for (int col = cols - 1, row = 0; row < rows; --col, ++row) {
        actualSum += square[row][col];
    }
    return actualSum == expectedSum;
}

void printSquare(int square[rows][cols])
{
    for (int row = 0; row < rows; ++row) {
        for (int col = 0; col < cols; ++col) {
            printf("%2i ", square[row][col]);
        }
        printf("\n");
    }
}

int areNumbersUnique(int square[rows][cols])
{
    for (int row = 0; row < rows; ++row) {
        qsort(square[row], cols, sizeof(int), compare);
        if (!rowUnique(square[row], cols)) {
            return 0;  // false;
        }
    }
    return 1;  // true;
}

int compare(const void* lhs, const void* rhs)
{
    int arg1 = *((const int*)lhs);
    int arg2 = *((const int*)rhs);

    if (arg1 < arg2)
        return -1;
    if (arg1 > arg2)
        return 1;
    return 0;
}

int rowUnique(int row[], int rowSize)
{
    for (int i = 0; i < rowSize - 1; ++i) {
        if (row[i] == row[i + 1]) {
            return 0;  // false;
        }
    }
    return 1;  // true;
}
