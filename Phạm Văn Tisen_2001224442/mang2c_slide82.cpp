#include <stdio.h>
#include <math.h>
#include <limits.h>

#define MAX 100

// Ham kiem tra so nguyen to
int kiemTraSoNguyenTo(int n) {
    if (n < 2) {
        return 0;
    }
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

// Ham kiem tra so hoan thien
int kiemTraSoHoanThien(int n) {
    if (n < 2) {
        return 0;
    }
    int sum = 1;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            sum += i;
            if (i != n / i) {
                sum += n / i;
            }
        }
    }
    return sum == n;
}

// Ham tim tong cac phan tu cua mot cot
int tinhTongCot(int a[][MAX], int m, int n, int cot) {
    int cotSum = 0;
    for (int i = 0; i < m; i++) {
        cotSum += a[i][cot];
    }
    return cotSum;
}

// Ham tim so luong so hoan thien trong mot dong
int demSoHoanThienTrongDong(int a[][MAX], int n, int dong) {
    int soHoanThien = 0;
    for (int j = 0; j < n; j++) {
        if (kiemTraSoHoanThien(a[dong][j])) {
            soHoanThien++;
        }
    }
    return soHoanThien;
}

// Ham kiem tra xem mot dong co chua toan so chan hay khong
int kiemTraDongChan(int a[][MAX], int n, int dong) {
    for (int j = 0; j < n; j++) {
        if (a[dong][j] % 2 != 0) {
            return 0; // False
        }
    }
    return 1; // True
}

// Ham tim tan suat xuat hien cua mot gia tri trong ma tran
int timTanSuat(int a[][MAX], int m, int n, int giaTri) {
    int tanSuat = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] == giaTri) {
                tanSuat++;
            }
        }
    }
    return tanSuat;
}

// Ham tim so nguyen to nho nhat trong ma tran
int timSoNguyenToNhoNhat(int a[][MAX], int m, int n) {
    int minNguyenTo = INT_MAX;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (kiemTraSoNguyenTo(a[i][j]) && a[i][j] < minNguyenTo) {
                minNguyenTo = a[i][j];
            }
        }
    }
    return minNguyenTo;
}

// Ham tim phan tu lon nhat trong mot dong
int timMaxDong(int a[][MAX], int n, int dong) {
    int max = a[dong][0];
    for (int j = 1; j < n; j++) {
        if (a[dong][j] > max) {
            max = a[dong][j];
        }
    }
    return max;
}

// Ham tim phan tu nho nhat trong mot dong
int timMinDong(int a[][MAX], int n, int dong) {
    int min = a[dong][0];
    for (int j = 1; j < n; j++) {
        if (a[dong][j] < min) {
            min = a[dong][j];
        }
    }
    return min;
}

// Ham tim phan tu lon nhat trong mot cot
int timMaxCot(int a[][MAX], int m, int cot) {
    int max = a[0][cot];
    for (int i = 1; i < m; i++) {
        if (a[i][cot] > max) {
            max = a[i][cot];
        }
    }
    return max;
}

// Ham tim phan tu nho nhat trong mot cot
int timMinCot(int a[][MAX], int m, int cot) {
    int min = a[0][cot];
    for (int i = 1; i < m; i++) {
        if (a[i][cot] < min) {
            min = a[i][cot];
        }
    }
    return min;
}

int main() {
    int m, n, x, k;

    printf("Nhap so hang m cua ma tran (toi da %d): ", MAX);
    scanf_s("%d", &m);
    printf("Nhap so cot n cua ma tran (toi da %d): ", MAX);
    scanf_s("%d", &n);

    if (m > MAX || n > MAX || m <= 0 || n <= 0) {
        printf("Kich thuoc mang khong hop le!\n");
        return 1;
    }

    int a[MAX][MAX];

    printf("Nhap cac phan tu cua ma tran:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf_s("%d", &a[i][j]);
        }
    }

    

    // Bai 2: Liet ke cac dong co nhieu so hoan thien nhat trong ma tran.
    int maxSoHoanThien = 0;
    for (int i = 0; i < m; i++) {
        int soHoanThien = demSoHoanThienTrongDong(a, n, i);
        if (soHoanThien > maxSoHoanThien) {
            maxSoHoanThien = soHoanThien;
        }
    }
    printf("Bai 2: Cac dong co nhieu so hoan thien nhat (%d): ", maxSoHoanThien);
    for (int i = 0; i < m; i++) {
        if (demSoHoanThienTrongDong(a, n, i) == maxSoHoanThien) {
            printf("%d ", i);
        }
    }
    printf("\n");

    

    // Bai 4: Tim gia tri xuat hien nhieu nhat trong ma tran.
    int maxTanSuat = 0;
    int giaTriXuatHienNhieuNhat = a[0][0];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int tanSuat = timTanSuat(a, m, n, a[i][j]);
            if (tanSuat > maxTanSuat) {
                maxTanSuat = tanSuat;
                giaTriXuatHienNhieuNhat = a[i][j];
            }
        }
    }
    printf("Bai 4: Gia tri xuat hien nhieu nhat: %d (xuat hien %d lan)\n", giaTriXuatHienNhieuNhat, maxTanSuat);

    

    // Bai 6: Tim phan tu lon (nho) nhat trong dong thu k.
    printf("Nhap dong k: ");
    scanf_s("%d", &k);
    if (k < 0 || k >= m) {
        printf("Dong k khong hop le.\n");
    }
    else {
        int maxDongK = timMaxDong(a, n, k);
        int minDongK = timMinDong(a, n, k);
        printf("Bai 6: Phan tu lon nhat trong dong %d: %d\n", k, maxDongK);
        printf("Bai 6: Phan tu nho nhat trong dong %d: %d\n", k, minDongK);
    }

   

    return 0;
}