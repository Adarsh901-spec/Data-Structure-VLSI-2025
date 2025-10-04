#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start;
    int end;
} Activity;

int compareActivities(const void *a, const void *b) {
    return ((Activity*)a)->end - ((Activity*)b)->end;
}

int main() {
    int n;
    scanf("%d", &n);

    int start[n];
    int end[n];
    Activity activities[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &start[i]);
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", &end[i]);
    }

    for (int i = 0; i < n; i++) {
        activities[i].start = start[i];
        activities[i].end = end[i];
    }

    qsort(activities, n, sizeof(Activity), compareActivities);

    int count = 0;
    int lastEndTime = 0;

    for (int i = 0; i < n; i++) {
        if (activities[i].start > lastEndTime) {
            count++;
            lastEndTime = activities[i].end;
        }
    }

    printf("%d\n", count);

    return 0;
}