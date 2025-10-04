#include <stdio.h>

int main() {
    int n, key, i;

    scanf("%d", &n);
    int arr[n];

    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    scanf("%d", &key);

    for (i = 0; i < n; i++) {
        if (arr[i] == key) {
            printf("%d\n", i);
            return 0;
        }
    }

    printf("Not found\n");
    return 0;
}