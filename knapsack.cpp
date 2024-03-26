#include <stdio.h>
#include <stdlib.h>
struct Item {
    int value;
    int weight;
};
int compare(const void *a, const void *b) {
    double ratio_a = ((double)(((struct Item *)a)->value)) / (((struct Item *)a)->weight);
    double ratio_b = ((double)(((struct Item *)b)->value)) / (((struct Item *)b)->weight);
    return (ratio_b > ratio_a) - (ratio_b < ratio_a);
}
double fractionalKnapsack(int W, struct Item arr[], int n) {
    qsort(arr, n, sizeof(struct Item), compare);

    double totalValue = 0.0; 
    int currentWeight = 0;  
    for (int i = 0; i < n; i++) {
        if (currentWeight + arr[i].weight <= W) {
            totalValue += arr[i].value;
            currentWeight += arr[i].weight;
        }
        else {
            int remainingWeight = W - currentWeight;
            totalValue += arr[i].value * ((double)remainingWeight / arr[i].weight);
            break;
        }
    }

    return totalValue;
}

int main() {
    int W; 
    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &W);

    int n; 
    printf("Enter the number of items: ");
    scanf("%d", &n);

    struct Item arr[n]; 

    printf("Enter the value and weight of each item:\n");
    for (int i = 0; i < n; i++) {
        printf("Item %d: ", i + 1);
        scanf("%d %d", &arr[i].value, &arr[i].weight);
    }

    double maxValue = fractionalKnapsack(W, arr, n);
    printf("Maximum value in the knapsack: %.2lf\n", maxValue);

    return 0;
}

