#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Hàm so sánh cho qsort
int compareAsc(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int compareDesc(const void* a, const void* b) {
    return (*(int*)b - *(int*)a);
}

void sortMatrix(int a[MAX][MAX], int n, int m) {
    for (int i = 0; i < n; i++) {
        int temp[m];

        // Sao chép dòng vào mảng tạm thời
        for (int j = 0; j < m; j++) {
            temp[j] = a[i][j];
        }

        // Sắp xếp mảng tạm thời
        if (i % 2 == 0) {
            qsort(temp, m, sizeof(int), compareAsc); // Dòng chẵn sắp xếp tăng dần
        }
        else {
            qsort(temp, m, sizeof(int), compareDesc); // Dòng lẻ sắp xếp giảm dần
        }

        // Ghi lại vào ma trận
        for (int j = 0; j < m; j++) {
            a[i][j] = temp[j];
        }
    }
}

void printMatrix(int a[MAX][MAX], int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n, m;
    int a[MAX][MAX];

    // Nhập kích thước ma trận
    printf("Nhap so hang va so cot: ");
    scanf("%d %d", &n, &m);

    // Nhập ma trận
    printf("Nhap ma tran:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    // Sắp xếp ma trận
    sortMatrix(a, n, m);

    // In ma trận đã sắp xếp
    printf("Ma tran sau khi sap xep:\n");
    printMatrix(a, n, m);

    return 0;
}
