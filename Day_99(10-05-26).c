#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int position;
    int speed;
    double time;
} Car;

int cmp(const void *a, const void *b) {
    Car *c1 = (Car*)a;
    Car *c2 = (Car*)b;
    return c2->position - c1->position; // descending order
}

int carFleet(int target, int position[], int speed[], int n) {
    Car cars[n];

    for (int i = 0; i < n; i++) {
        cars[i].position = position[i];
        cars[i].speed = speed[i];
        cars[i].time = (double)(target - position[i]) / speed[i];
    }

    qsort(cars, n, sizeof(Car), cmp);

    int fleets = 0;
    double currTime = 0.0;

    for (int i = 0; i < n; i++) {
        if (cars[i].time > currTime) {
            fleets++;
            currTime = cars[i].time;
        }
    }

    return fleets;
}

int main() {
    int n, target;
    scanf("%d %d", &target, &n);

    int position[n], speed[n];

    for (int i = 0; i < n; i++)
        scanf("%d", &position[i]);

    for (int i = 0; i < n; i++)
        scanf("%d", &speed[i]);

    printf("%d\n", carFleet(target, position, speed, n));

    return 0;
}