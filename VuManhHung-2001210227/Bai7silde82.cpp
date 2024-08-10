#include <stdio.h>
#include <limits.h>

#define MAX 100

void findMinMaxInColumn(int a[MAX][MAX], int m, int n, int k, int* min, int* max) {
    *min = INT_MAX;
    *max = INT_MIN;

    for (int i = 0; i < m; i++) {
        if (a[i][k] < *min) {
            *min = a[i][k];
        }
        if (a[i][k] > *max) {
            *max = a[i][k];
        }
    }
}

int main() {
    int m, n, k;
    int a[MAX][MAX];
    int min, max;

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

    // Nhập chỉ số cột k
    printf("Nhap chi so cot k: ");
    scanf("%d", &k);

    if (k < 0 || k >= n) {
        printf("Chi so cot k khong hop le.\n");
        return 1;
    }

    findMinMaxInColumn(a, m, n, k, &min, &max);

    printf("Phan tu nho nhat trong cot %d la: %d\n", k, min);
    printf("Phan tu lon nhat trong cot %d la: %d\n", k, max);

    return 0;
}
