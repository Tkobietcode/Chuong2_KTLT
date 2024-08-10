#include <stdio.h>
#include <limits.h>

#define MAX 100

int isPrime(int num) {
    if (num <= 1) return 0;
    if (num == 2) return 1;
    if (num % 2 == 0) return 0;
    for (int i = 3; i * i <= num; i += 2) {
        if (num % i == 0) return 0;
    }
    return 1;
}

void findMinPrime(int a[MAX][MAX], int m, int n) {
    int minPrime = INT_MAX;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (isPrime(a[i][j]) && a[i][j] < minPrime) {
                minPrime = a[i][j];
            }
        }
    }

    if (minPrime == INT_MAX) {
        printf("Khong co so nguyen to trong ma tran.\n");
    }
    else {
        printf("So nguyen to nho nhat trong ma tran la: %d\n", minPrime);
    }
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

    findMinPrime(a, m, n);

    return 0;
}
