#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10005

typedef struct {
    int difficulty;
    int profit;
} Job;

int compareJobs(const void *a, const void *b) {
    return ((Job*)a)->difficulty - ((Job*)b)->difficulty;
}

int compareWorkers(const void *a, const void *b) {
    return *(int*)a - *(int*)b;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    Job jobs[MAX_SIZE];
    int difficulty[MAX_SIZE];
    int profit[MAX_SIZE];
    int worker[MAX_SIZE];

    for (int i = 0; i < n; i++) {
        scanf("%d", &difficulty[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &profit[i]);
    }
    for (int i = 0; i < m; i++) {
        scanf("%d", &worker[i]);
    }

    for (int i = 0; i < n; i++) {
        jobs[i].difficulty = difficulty[i];
        jobs[i].profit = profit[i];
    }

    qsort(jobs, n, sizeof(Job), compareJobs); // Sort jobs by difficulty
    qsort(worker, m, sizeof(int), compareWorkers); // Sort workers by ability

    int maxProfit = 0;
    int bestProfit = 0;
    int jobIndex = 0;

    for (int i = 0; i < m; i++) {
        while (jobIndex < n && jobs[jobIndex].difficulty <= worker[i]) {
            if (jobs[jobIndex].profit > bestProfit) {
                bestProfit = jobs[jobIndex].profit;
            }
            jobIndex++;
        }
        maxProfit += bestProfit;
    }

    printf("%d\n", maxProfit);

    return 0;
}