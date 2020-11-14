#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "generateMagicSquare.h"

int main()
{
    int magicSum = (rows * (rows*rows + 1)) / 2;
    srand((unsigned int)time(NULL));
    int square[rows][cols];

    generateMagicSquare(square);
    printSquare(square);
    printf("------------------------\n");

    printf(isSumInColsEqualTo(magicSum, square) ? "true\n" : "false\n");
    printf(isSumInRowsEqualTo(magicSum, square) ? "true\n" : "false\n");
    printf(isSumInDiagonalsEqualTo(magicSum, square) ? "true\n" : "false\n");
    printf(areNumbersUnique(square) ? "true\n" : "false\n");

}
