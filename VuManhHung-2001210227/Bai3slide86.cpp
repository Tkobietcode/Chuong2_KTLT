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

void sortZigzagMatrix(int a[MAX][MAX], int n, int m, int ascending) {
    int temp[n * m];
    int index = 0;

    // Sao chép toàn bộ ma trận vào mảng tạm thời
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            temp[index++] = a[i][j];
        }
    }

    // Sắp xếp mảng tạm thời
    if (ascending) {
        qsort(temp, n * m, sizeof(int), compareAsc); // Sắp xếp tăng dần
    }
    else {
        qsort(temp, n * m, sizeof(int), compareDesc); // Sắp xếp giảm dần
    }

    // Ghi lại vào ma trận theo thứ tự zic-zac
    index = 0;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            for (int j = 0; j < m; j++) {
                a[i][j] = temp[index++];
            }
        }
        else {
            for (int j = m - 1; j >= 0; j--) {
                a[i][j] = temp[index++];
            }
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
    int n, m, choice;
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

    // Chọn sắp xếp tăng dần hay giảm dần
    printf("Nhap 1 de sap xep tang dan, 0 de sap xep giam dan: ");
    scanf("%d", &choice);

    // Sắp xếp ma trận
    sortZigzagMatrix(a, n, m, choice);

    // In ma trận đã sắp xếp
    printf("Ma tran sau khi sap xep:\n");
    printMatrix(a, n, m);

    return 0;
}
