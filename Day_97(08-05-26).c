#include <stdio.h>
#include <stdlib.h>

int cmpStart(const void *a, const void *b) {
    return ((int*)a)[0] - ((int*)b)[0];
}

int cmpEnd(const void *a, const void *b) {
    return (*(int*)a) - (*(int*)b);
}

int minMeetingRooms(int intervals[][2], int n) {
    int *start = (int*)malloc(n * sizeof(int));
    int *end = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        start[i] = intervals[i][0];
        end[i] = intervals[i][1];
    }

    qsort(start, n, sizeof(int), cmpEnd);
    qsort(end, n, sizeof(int), cmpEnd);

    int i = 0, j = 0;
    int rooms = 0, maxRooms = 0;

    while (i < n && j < n) {
        if (start[i] < end[j]) {
            rooms++;
            if (rooms > maxRooms)
                maxRooms = rooms;
            i++;
        } else {
            rooms--;
            j++;
        }
    }

    free(start);
    free(end);

    return maxRooms;
}

int main() {
    int n;
    scanf("%d", &n);

    int intervals[n][2];
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &intervals[i][0], &intervals[i][1]);
    }

    printf("%d\n", minMeetingRooms(intervals, n));

    return 0;
}