#include <stdio.h>


int factorial(int n) {
    if (n == 0 || n == 1)
        return 1;
    else
        return n * factorial(n - 1);
}
void printPascalTriangle(int numRows) {
    int i, j;

    for (i = 0; i < numRows; i++) {
        for (j = 0; j <= i; j++) {
            
            printf("%d ", factorial(i) / (factorial(j) * factorial(i - j)));
        }
        printf("\n");
    }
}

int main() {
    int numRows;

    printf("Enter the number of rows for Pascal's Triangle: ");
    scanf("%d", &numRows);

    printf("Pascal's Triangle with %d rows:\n", numRows);
    printPascalTriangle(numRows);

    return 0;
}

