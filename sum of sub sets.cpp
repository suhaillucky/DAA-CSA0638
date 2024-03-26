#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100
void printSubsets(int subset[], int subsetSize) {
    printf("{ ");
    for (int i = 0; i < subsetSize; i++) {
        printf("%d ", subset[i]);
    }
    printf("}\n");
}
void sumOfSubsets(int set[], int subset[], int n, int subsetSize, int sum, int target, int nextIndex) {
    if (sum == target) {
        printSubsets(subset, subsetSize);
        return;
    }

    for (int i = nextIndex; i < n; i++) {
        if (sum + set[i] <= target) {
            subset[subsetSize] = set[i];
            sumOfSubsets(set, subset, n, subsetSize + 1, sum + set[i], target, i + 1);
        }
    }
}

int main() {
    int n, set[MAX_SIZE], subset[MAX_SIZE];
    int target;

    printf("Enter the number of elements in the set: ");
    scanf("%d", &n);

    printf("Enter the elements of the set:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &set[i]);
    }

    printf("Enter the target sum: ");
    scanf("%d", &target);

    printf("Subsets whose elements sum up to %d:\n", target);
    sumOfSubsets(set, subset, n, 0, 0, target, 0);

    return 0;
}

