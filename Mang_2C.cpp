#include <stdio.h>
#include <math.h>

#define MAX 100 

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

int main() 
{
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

  

    printf("Bai 2: Cac so hoan thien trong ma tran: ");
    int foundHoanThien = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (kiemTraSoHoanThien(a[i][j])) {
                printf("%d ", a[i][j]);
                foundHoanThien = 1;
            }
        }
    }
    if (!foundHoanThien) {
        printf("Khong co so hoan thien trong ma tran.\n");
    }
    else {
        printf("\n");
    }


   


    printf("Nhap dong k: ");
    scanf_s("%d", &k);
    if (k < 0 || k >= m) {
        printf("Dong k khong hop le.\n");
    }
    else {
        int sumDongK = 0;
        for (int j = 0; j < n; j++) {
            sumDongK += a[k][j];
        }
        printf("Bai 4: Tong gia tri tren dong %d: %d\n", k, sumDongK);
    }


   


    printf("Nhap gia tri x: ");
    scanf_s("%d", &x);
    int tanSuatX = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] == x) {
                tanSuatX++;
            }
        }
    }
    printf("Bai 6: Tan suat xuat hien cua %d trong ma tran: %d\n", x, tanSuatX);


    

    return 0;
}