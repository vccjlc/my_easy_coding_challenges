/*

Given n points on a 2D plane where points[i] = [xi, yi], Return the widest vertical area between two points such that no points are inside the area.

A vertical area is an area of fixed-width extending infinitely along the y-axis (i.e., infinite height). The widest vertical area is the one with the maximum width.

Note that points on the edge of a vertical area are not considered included in the area.

*/

#include <stdlib.h> // For qsort

// Comparator function for qsort
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int maxWidthOfVerticalArea(int** points, int pointsSize, int* pointsColSize) {
    int helperArray[pointsSize]; // No need for initialization here since you're setting all values in the loop
    for (int i = 0; i < pointsSize; ++i) {
        helperArray[i] = points[i][0]; // Assign x coordinate to helperArray
    }

    // Sort the helperArray to find the vertical areas
    qsort(helperArray, pointsSize, sizeof(int), compare);

    int maxWidth = 0; // Initialize maxWidth to 0
    // Iterate through sorted x coordinates to find the largest gap
    for (int i = 1; i < pointsSize; ++i) {
        int currentWidth = helperArray[i] - helperArray[i - 1];
        if (currentWidth > maxWidth) {
            maxWidth = currentWidth; // Update maxWidth if currentWidth is larger
        }
    }

    return maxWidth; // Return the widest vertical area
}

