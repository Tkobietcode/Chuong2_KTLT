#include <stdio.h>

#define MAX 100

void findMinSumColumns(int a[MAX][MAX], int m, int n) {
    int colSum[MAX] = { 0 };
    int minSum = 0;

    // Tính tổng các cột
    for (int j = 0; j < n; j++) {
        for (int i = 0; i < m; i++) {
            colSum[j] += a[i][j];
        }
    }

    // Tìm tổng nhỏ nhất
    minSum = colSum[0];
    for (int j = 1; j < n; j++) {
        if (colSum[j] < minSum) {
            minSum = colSum[j];
        }
    }

    // Liệt kê các cột có tổng nhỏ nhất
    printf("Cac cot co tong nho nhat la: ");
    for (int j = 0; j < n; j++) {
        if (colSum[j] == minSum) {
            printf("%d ", j);
        }
    }
    printf("\n");
}

int main() {
    int m, n;
    int a[MAX][MAX];

    // Nhập kích thước ma trận
    printf("Nhap so hang va so cot: ");
    scanf("%d %d", &m, &n);

    // Nhập ma trận
    printf("Nhap ma tran:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    findMinSumColumns(a, m, n);

    return 0;
}
