#include <stdio.h>

#define MAX 100

// Hàm hoán đổi hai số nguyên
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}



// Bài 2: Sắp xếp các phần tử trong ma trận sao cho cột chẵn tăng cột lẻ giảm
void sapXepCotChanTangLeGiam(int a[][MAX], int m, int n) {
    for (int j = 0; j < n; j++) {
        // Sắp xếp tăng dần cho cột chẵn
        if (j % 2 == 0) {
            for (int i = 0; i < m - 1; i++) {
                for (int k = i + 1; k < m; k++) {
                    if (a[i][j] > a[k][j]) {
                        swap(&a[i][j], &a[k][j]);
                    }
                }
            }
        }
        // Sắp xếp giảm dần cho cột lẻ
        else {
            for (int i = 0; i < m - 1; i++) {
                for (int k = i + 1; k < m; k++) {
                    if (a[i][j] < a[k][j]) {
                        swap(&a[i][j], &a[k][j]);
                    }
                }
            }
        }
    }
}


// Hàm in ma trận
void inMaTran(int a[][MAX], int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int m, n;

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

    printf("\nMa tran ban dau:\n");
    inMaTran(a, m, n);

    // Bai 2:
    sapXepCotChanTangLeGiam(a, m, n);
    printf("\nBai 2: Ma tran sau khi sap xep cot chan tang, le giam:\n");
    inMaTran(a, m, n);

   
    return 0;
}