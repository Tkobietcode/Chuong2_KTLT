#include <stdio.h>

#define MAX 100

// Hàm tính tổng các phần tử phía trên đường chéo chính
int sumAboveMainDiagonal(int matrix[MAX][MAX], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            sum += matrix[i][j];
        }
    }
    return sum;
}

int main() {
    int n;
    int matrix[MAX][MAX];

    // Nhập kích thước ma trận
    printf("Nhap kich thuoc ma tran vuong (n x n): ");
    scanf("%d", &n);

    // Kiểm tra kích thước hợp lệ
    if (n <= 0 || n > MAX) {
        printf("Kich thuoc ma tran khong hop le. Vui long nhap lai.\n");
        return 1; // Kết thúc chương trình với mã lỗi
    }

    // Nhập ma trận
    printf("Nhap ma tran:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Tính tổng các phần tử phía trên đường chéo chính
    int sum = sumAboveMainDiagonal(matrix, n);
    printf("Tong cac phan tu phia tren duong cheo chinh: %d\n", sum);

    return 0;
}
