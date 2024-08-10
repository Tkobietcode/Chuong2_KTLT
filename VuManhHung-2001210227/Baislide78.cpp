#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#define MAX 100

// Hàm kiểm tra số nguyên tố
bool kiemTraSoNguyenTo(int num) {
    if (num <= 1) return false;
    if (num <= 3) return true;
    if (num % 2 == 0 || num % 3 == 0) return false;
    for (int i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) return false;
    }
    return true;
}

// Hàm kiểm tra chữ số đầu tiên của số nguyên
int layChuSoDauTien(int num) {
    while (num >= 10) num /= 10;
    return num;
}

// Bài 1: Tính tổng các phần tử có chữ số đầu là chữ số lẻ
int tongChuSoDauLe(int mat[MAX][MAX], int m, int n) {
    int tong = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (layChuSoDauTien(abs(mat[i][j])) % 2 != 0) {
                tong += mat[i][j];
            }
        }
    }
    return tong;
}

// Bài 3: Tính tổng các phần tử lớn hơn trị tuyệt đối của phần tử liền sau nó
int tongLonHonTriTuyetDoiSau(int mat[MAX][MAX], int m, int n) {
    int tong = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (mat[i][j] > abs(mat[i][j + 1])) {
                tong += mat[i][j];
            }
        }
    }
    return tong;
}

// Bài 5: Tính tổng các giá trị nằm trên biên của ma trận
int tongBien(int mat[MAX][MAX], int m, int n) {
    int tong = 0;
    // Hàng đầu
    for (int j = 0; j < n; j++) tong += mat[0][j];
    // Hàng cuối
    for (int j = 0; j < n; j++) tong += mat[m - 1][j];
    // Cột trái (trừ các góc)
    for (int i = 1; i < m - 1; i++) tong += mat[i][0];
    // Cột phải (trừ các góc)
    for (int i = 1; i < m - 1; i++) tong += mat[i][n - 1];
    return tong;
}

// Bài 7: Đếm số lượng các phần tử là số chẵn, số lẻ, số âm, số dương, số nguyên tố
void demLoaiPhanTu(int mat[MAX][MAX], int m, int n) {
    int chan = 0, le = 0, duong = 0, am = 0, nguyenTo = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int num = mat[i][j];
            if (num % 2 == 0) chan++;
            else le++;
            if (num > 0) duong++;
            else if (num < 0) am++;
            if (kiemTraSoNguyenTo(abs(num))) nguyenTo++;
        }
    }
    printf("Chan: %d\n", chan);
    printf("Le: %d\n", le);
    printf("Duong: %d\n", duong);
    printf("Am: %d\n", am);
    printf("Nguyen to: %d\n", nguyenTo);
}

int main() {
    int mat[MAX][MAX];
    int m, n;

    // Nhập kích thước ma trận
    printf("Nhap so hang va so cot: ");
    scanf("%d %d", &m, &n);

    // Nhập giá trị ma trận
    printf("Nhap cac gia tri cua ma tran:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &mat[i][j]);
        }
    }

    // Thực hiện các bài toán
    printf("Tong cac phan tu co chu so dau la chu so le: %d\n", tongChuSoDauLe(mat, m, n));

    printf("Tong cac phan tu lon hon tri tuyet doi cua phan tu lien sau no: %d\n", tongLonHonTriTuyetDoiSau(mat, m, n));

    printf("Tong cac phan tu nam tren bien caa ma tran: %d\n", tongBien(mat, m, n));

    demLoaiPhanTu(mat, m, n);

    return 0;
}
