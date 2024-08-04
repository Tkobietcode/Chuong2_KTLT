#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#define MAX 100

// Hàm kiểm tra số nguyên tố
bool isPrime(int num) {
    if (num <= 1) return false;
    if (num <= 3) return true;
    if (num % 2 == 0 || num % 3 == 0) return false;
    for (int i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) return false;
    }
    return true;
}

// Hàm kiểm tra chữ số đầu tiên của số nguyên
int getFirstDigit(int num) {
    while (num >= 10) num /= 10;
    return num;
}

// Bài 1: Tính tổng các phần tử có chữ số đầu là chữ số lẻ
int sumOddFirstDigit(int mat[MAX][MAX], int m, int n) {
    int sum = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (getFirstDigit(abs(mat[i][j])) % 2 != 0) {
                sum += mat[i][j];
            }
        }
    }
    return sum;
}

// Bài 3: Tính tổng các phần tử lớn hơn trị tuyệt đối của phần tử liền sau nó
int sumGreaterThanNextAbs(int mat[MAX][MAX], int m, int n) {
    int sum = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (mat[i][j] > abs(mat[i][j + 1])) {
                sum += mat[i][j];
            }
        }
    }
    return sum;
}

// Bài 5: Tính tổng các giá trị nằm trên biên của ma trận
int sumBorder(int mat[MAX][MAX], int m, int n) {
    int sum = 0;
    // Top row
    for (int j = 0; j < n; j++) sum += mat[0][j];
    // Bottom row
    for (int j = 0; j < n; j++) sum += mat[m - 1][j];
    // Left column (excluding corners)
    for (int i = 1; i < m - 1; i++) sum += mat[i][0];
    // Right column (excluding corners)
    for (int i = 1; i < m - 1; i++) sum += mat[i][n - 1];
    return sum;
}

// Bài 7: Đếm số lượng các phần tử là số chẵn, số lẻ, số âm, số dương, số nguyên tố
void countTypes(int mat[MAX][MAX], int m, int n) {
    int even = 0, odd = 0, positive = 0, negative = 0, prime = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int num = mat[i][j];
            if (num % 2 == 0) even++;
            else odd++;
            if (num > 0) positive++;
            else if (num < 0) negative++;
            if (isPrime(abs(num))) prime++;
        }
    }
    printf("Even: %d\n", even);
    printf("Odd: %d\n", odd);
    printf("Positive: %d\n", positive);
    printf("Negative: %d\n", negative);
    printf("Prime: %d\n", prime);
}

int main() {
    int mat[MAX][MAX];
    int m, n;

    // Nhập kích thước ma trận
    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &m, &n);

    // Nhập giá trị ma trận
    printf("Enter the matrix values:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &mat[i][j]);
        }
    }

    // Thực hiện các bài toán
    printf("Sum of elements with odd first digit: %d\n", sumOddFirstDigit(mat, m, n));

    printf("Sum of elements greater than absolute value of next element: %d\n", sumGreaterThanNextAbs(mat, m, n));

    printf("Sum of border elements: %d\n", sumBorder(mat, m, n));

    countTypes(mat, m, n);

    return 0;
}
