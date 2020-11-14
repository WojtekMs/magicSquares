#ifndef GENERATE_MAGIC_SQUARE
#define GENERATE_MAGIC_SQUARE

const int rows = 3;
const int cols = 3;

void printSquare(int square[rows][cols]);

int isSumInRowsEqualTo(int expectedSum, int square[rows][cols]);
int isSumInColsEqualTo(int expectedSum, int square[rows][cols]);

int areNumbersUnique(int square[rows][cols]);
int compare(const void* lhs, const void* rhs); //used by qsort
int rowUnique(int row[], int rowSize);

void randomizeSquare(int square[rows][cols]);
void setOccupiedNumbers(int occupiedNumbers[], int size);
int isOccupied(int value, int occupiedNumbers[], int size);

void generateMagicSquare(int square[][cols]);

#endif
