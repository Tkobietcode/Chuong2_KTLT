#include <stdio.h>

#define MAX 100

void findEvenRows(int a[MAX][MAX], int m, int n) {
    printf("Cac dong chua toan gia tri chan la: ");
    for (int i = 0; i < m; i++) {
        int isEven = 1;
        for (int j = 0; j < n; j++) {
            if (a[i][j] % 2 != 0) {
                isEven = 0;
                break;
            }
        }
        if (isEven) {
            printf("%d ", i);
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

    findEvenRows(a, m, n);

    return 0;
}
