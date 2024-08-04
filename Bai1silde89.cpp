#include <stdio.h>

#define MAX 100

// Hàm tính tổng các phần tử trên đường chéo chính
int sumMainDiagonal(int matrix[MAX][MAX], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += matrix[i][i];
    }
    return sum;
}

int main() {
    int n;
    int matrix[MAX][MAX];

    // Nhập kích thước ma trận
    printf("Nhap kich thuoc ma tran vuong (n x n): ");
    scanf("%d", &n);

    // Nhập ma trận
    printf("Nhap ma tran:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Tính tổng các phần tử trên đường chéo chính
    int sum = sumMainDiagonal(matrix, n);
    printf("Tong cac phan tu tren duong cheo chinh: %d\n", sum);

    return 0;
}
