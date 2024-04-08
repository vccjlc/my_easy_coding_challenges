// 1. Sorting an array of integers in ascending order

#include <stdio.h>
#include <stdlib.h>

int compareInts(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int arr[] = {10, 5, 15, 12, 90, 55};
    int n = sizeof(arr) / sizeof(arr[0]);

    qsort(arr, n, sizeof(int), compareInts);

    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}


// 2. Sorting an array of integers in descending order

#include <stdio.h>
#include <stdlib.h>

int compareIntsDesc(const void* a, const void* b) {
    return (*(int*)b - *(int*)a); // Note the change in order compared to the ascending version
}

int main() {
    int arr[] = {10, 5, 15, 12, 90, 55};
    int n = sizeof(arr) / sizeof(arr[0]);

    qsort(arr, n, sizeof(int), compareIntsDesc);

    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}


// 3. Sorting an array of C strings (array of char*) in lexicographical order

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compareStrings(const void* a, const void* b) {
    const char* sa = *(const char**)a;
    const char* sb = *(const char**)b;
    return strcmp(sa, sb);
}

int main() {
    char* arr[] = {"banana", "apple", "orange", "mango"};
    int n = sizeof(arr) / sizeof(arr[0]);

    qsort(arr, n, sizeof(char*), compareStrings);

    for(int i = 0; i < n; i++) {
        printf("%s ", arr[i]);
    }

    return 0;
}


// 4. Sorting a struct array by a float field

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[50];
    float score;
} Student;

int compareScores(const void* a, const void* b) {
    float scoreA = ((Student*)a)->score;
    float scoreB = ((Student*)b)->score;
    return (scoreA > scoreB) - (scoreA < scoreB); // Safe comparison for floating point
}

int main() {
    Student students[] = {{"John", 92.5}, {"Alice", 88.0}, {"Bob", 91.2}};
    int n = sizeof(students) / sizeof(students[0]);

    qsort(students, n, sizeof(Student), compareScores);

    for(int i = 0; i < n; i++) {
        printf("%s: %.1f\n", students[i].name, students[i].score);
    }

    return 0;
}

