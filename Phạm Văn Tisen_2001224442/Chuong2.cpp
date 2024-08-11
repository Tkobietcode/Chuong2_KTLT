#include <stdio.h>

// Hàm nhập mảng
void NhapMang(int a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Nhap phan tu a[%d]: ", i);
        scanf_s("%d", &a[i]);
    }
}

// Hàm xuất mảng
void XuatMang(int a[], int n) {
    printf("Mang vua nhap la: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}



//2 Hàm Interchange Sort (sắp xếp giảm dần)
// Sử dụng template để sắp xếp được nhiều kiểu dữ liệu khác nhau
template <typename T>
void InterchangeSort(T a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] < a[j]) {
                // Hoán đổi a[i] và a[j]
                T temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}



// 2. Xuất các phần tử mà từng chữ số của nó là số lẻ.
int KiemTraChuSoLe(int num) {
    while (num > 0) {
        int chuSo = num % 10;
        if (chuSo % 2 == 0) {
            return 0;
        }
        num /= 10;
    }
    return 1;
}

void XuatPhanTuChuSoLe(int a[], int n) {
    printf("Cac phan tu co toan chu so le la: ");
    for (int i = 0; i < n; i++) {
        if (KiemTraChuSoLe(a[i])) {
            printf("%d ", a[i]);
        }
    }
    printf("\n");
}



// 4  Kiểm tra mảng có toàn là số chẵn không?
int KiemTraMangToanChan(int a[], int n) {
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 != 0) {
            return 0;
        }
    }
    return 1;
}



// 2. Kiểm tra mảng có đối xứng hay không?
int KiemTraMangDoiXung(int a[], int n) {
    for (int i = 0; i < n / 2; i++) {
        if (a[i] != a[n - i - 1]) {
            return 0; // Nếu có 1 cặp phần tử không đối xứng, return false
        }
    }
    return 1; // Nếu tất cả đều đối xứng, return true
}





#define MAX_SIZE 100 // Định nghĩa kích thước tối đa

int main() {
    int n, x, max, min, soChan, soLe;
    int a[MAX_SIZE], b[MAX_SIZE], c[MAX_SIZE], d[MAX_SIZE * 2]; // Khai báo mảng với kích thước tối đa

    printf("Nhap so phan tu cua mang (n <= %d): ", MAX_SIZE);
    scanf_s("%d", &n);

    // Kiểm tra n hợp lệ
    if (n <= 0 || n > MAX_SIZE) {
        printf("So phan tu khong hop le.\n");
        return 1;
    }

    //1 Nhập và xuất mảng a
    NhapMang(a, n);
    XuatMang(a, n);

    

   
    // 2. Sắp xếp mảng a giảm dần bằng Interchange Sort
    printf("Mang a sau khi sap xep giam dan: ");
    InterchangeSort(a, n);
    XuatMang(a, n);

    

    // 2. Xuất các phần tử có toàn chữ số lẻ
    XuatPhanTuChuSoLe(a, n);

    

    // 4. Kiểm tra mảng toàn chẵn
    if (KiemTraMangToanChan(a, n)) {
        printf("Mang toan so chan.\n");
    }
    else {
        printf("Mang khong toan so chan.\n");
    }

    

    // 2. Kiểm tra mảng đối xứng
    if (KiemTraMangDoiXung(a, n)) {
        printf("Mang doi xung.\n");
    }
    else {
        printf("Mang khong doi xung.\n");
    }

  

    return 0;
}