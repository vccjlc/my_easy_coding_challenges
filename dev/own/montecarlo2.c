#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>

double calculatePiParallel(int n) {
    int pointsInsideCircle = 0;

    #pragma omp parallel for reduction(+:pointsInsideCircle)
    for (int i = 0; i < n; i++) {
        double x = (double)rand_r(&i) / RAND_MAX;
        double y = (double)rand_r(&i) / RAND_MAX;

        if (x * x + y * y <= 1) {
            pointsInsideCircle++;
        }
    }

    return 4.0 * pointsInsideCircle / n;
}

int main() {
    int n;
    printf("Enter the number of points: ");
    scanf("%d", &n);

    srand(time(NULL)); // Seed the random number generator

    double startTime = omp_get_wtime();
    double pi = calculatePiParallel(n);
    double endTime = omp_get_wtime();

    printf("Approximation of Pi: %f\n", pi);
    printf("Time taken: %f seconds\n", endTime - startTime);

    return 0;
}

