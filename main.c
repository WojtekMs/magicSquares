#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "generateMagicSquare.h"

int rows;
int cols;

int main()
{
    int squareSize = 0;
    srand((unsigned int)time(NULL));
    printf("Please enter the size of the square: ");
    scanf("%d", &squareSize);
    cols = rows = squareSize;
    int magicSum = (rows * (rows*rows + 1)) / 2;
    int (*square)[cols] = malloc(sizeof(int[rows][cols]));
    generateMagicSquare(square);
    printSquare(square);
    printf("------------------------\n");

    printf(isSumInColsEqualTo(magicSum, square) ? "true\n" : "false\n");
    printf(isSumInRowsEqualTo(magicSum, square) ? "true\n" : "false\n");
    printf(isSumInDiagonalsEqualTo(magicSum, square) ? "true\n" : "false\n");
    printf(areNumbersUnique(square) ? "true\n" : "false\n");

    free(square);

}
