#include <stdio.h>

#define MAX 100

// Bài 2: Tính tổng các phần tử nằm trên đường chéo phụ.
int tinhTongDuongCheoPhu(int a[][MAX], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i][n - 1 - i];
    }
    return sum;
}

// Bài 4: Tính tổng các phần tử nằm phía trên đường chéo phụ.
int tinhTongPhiaTrenDuongCheoPhu(int a[][MAX], int n) {
    int sum = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            sum += a[i][j];
        }
    }
    return sum;
}

int main() {
    int n, a[MAX][MAX];

    printf("Nhap kich thuoc ma tran vuong n (toi da %d): ", MAX);
    scanf_s("%d", &n);

    if (n <= 0 || n > MAX) {
        printf("Kich thuoc khong hop le!\n");
        return 1;
    }

    printf("Nhap cac phan tu cua ma tran:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf_s("%d", &a[i][j]);
        }
    }

    // In kết quả
    // Bai 2
    printf("Tong cac phan tu tren duong cheo phu: %d\n", tinhTongDuongCheoPhu(a, n));
    // Bai 4
    printf("Tong cac phan tu phia tren duong cheo phu: %d\n", tinhTongPhiaTrenDuongCheoPhu(a, n));

    return 0;
}