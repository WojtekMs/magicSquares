#ifndef GENERATE_MAGIC_SQUARE
#define GENERATE_MAGIC_SQUARE

extern const int rows;
extern const int cols;

void printSquare(int square[rows][cols]);

int isSumInRowsEqualTo(int expectedSum, int square[rows][cols]);
int isSumInColsEqualTo(int expectedSum, int square[rows][cols]);
int isSumInDiagonalsEqualTo(int expectedSum, int square[rows][cols]);

int areNumbersUnique(int square[rows][cols]);
int compare(const void* lhs, const void* rhs); //used by qsort
int rowUnique(int row[], int rowSize);

void randomizeSquare(int square[rows][cols]);
void setOccupiedNumbers(int occupiedNumbers[], int size);
int isOccupied(int value, int occupiedNumbers[], int size);
void swapNumbers(int lhs, int rhs);

void generateMagicSquare(int square[][cols]);
int isMagicSquare(int square[rows][cols], int magicSum);

#endif
