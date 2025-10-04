#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int value;
    int weight;
    double ratio;
} Item;

int compareItems(const void *a, const void *b) {
    double ratioA = ((Item*)a)->ratio;
    double ratioB = ((Item*)b)->ratio;
    if (ratioA < ratioB) return 1;
    if (ratioA > ratioB) return -1;
    return 0;
}

int main() {
    int n, capacity;
    scanf("%d %d", &n, &capacity);

    Item items[n];
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &items[i].value, &items[i].weight);
        items[i].ratio = (double)items[i].value / items[i].weight;
    }

    qsort(items, n, sizeof(Item), compareItems);

    double totalValue = 0.0;
    int currentWeight = 0;

    for (int i = 0; i < n; i++) {
        if (currentWeight + items[i].weight <= capacity) {
            totalValue += items[i].value;
            currentWeight += items[i].weight;
        } else {
            int remainingCapacity = capacity - currentWeight;
            totalValue += items[i].ratio * remainingCapacity;
            currentWeight = capacity;
            break;
        }
    }

    printf("%.6f\n", totalValue);

    return 0;
}