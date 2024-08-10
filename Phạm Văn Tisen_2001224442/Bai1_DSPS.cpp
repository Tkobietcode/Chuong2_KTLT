#include <stdio.h>

#define MAX_N 50

// Cấu trúc phân số
struct PhanSo {
    int tuSo;
    int mauSo;
};

// 1. Hàm nhập danh sách các phân số
void NhapDanhSachPhanSo(struct PhanSo a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Nhap phan so thu %d:\n", i + 1);
        do {
            printf("Tu so: ");
            scanf_s("%d", &a[i].tuSo);
            printf("Mau so (khac 0): ");
            scanf_s("%d", &a[i].mauSo);
            if (a[i].mauSo == 0) {
                printf("Mau so phai khac 0. Vui long nhap lai.\n");
            }
        } while (a[i].mauSo == 0);
    }
}

// 2. Hàm xuất danh sách các phân số
void XuatDanhSachPhanSo(struct PhanSo a[], int n) {
    printf("Danh sach phan so:\n");
    for (int i = 0; i < n; i++) {
        printf("%d/%d ", a[i].tuSo, a[i].mauSo);
    }
    printf("\n");
}

// Hàm UCLN để dùng cho việc rút gọn phân số
int UCLN(int a, int b) {
    while (b != 0) {
        int temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

// Hàm rút gọn phân số
void RutGonPhanSo(struct PhanSo* ps) {
    int ucln = UCLN(ps->tuSo, ps->mauSo);
    ps->tuSo /= ucln;
    ps->mauSo /= ucln;
}




// 4. Tính tổng và tích các phân số
struct PhanSo TinhTongPhanSo(struct PhanSo a[], int n) {
    struct PhanSo tong = { 0, 1 }; // Khởi tạo phân số tổng bằng 0/1
    for (int i = 0; i < n; i++) {
        tong.tuSo = tong.tuSo * a[i].mauSo + a[i].tuSo * tong.mauSo;
        tong.mauSo = tong.mauSo * a[i].mauSo;
        RutGonPhanSo(&tong);
    }
    return tong;
}

struct PhanSo TinhTichPhanSo(struct PhanSo a[], int n) {
    struct PhanSo tich = { 1, 1 }; // Khởi tạo phân số tích bằng 1/1
    for (int i = 0; i < n; i++) {
        tich.tuSo *= a[i].tuSo;
        tich.mauSo *= a[i].mauSo;
        RutGonPhanSo(&tich);
    }
    return tich;
}




// 6. Sắp xếp mảng tăng/giảm dần (ví dụ sử dụng Interchange Sort)
void InterchangeSortTangDan(struct PhanSo a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if ((double)a[i].tuSo / a[i].mauSo > (double)a[j].tuSo / a[j].mauSo) {
                struct PhanSo temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}

void InterchangeSortGiamDan(struct PhanSo a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if ((double)a[i].tuSo / a[i].mauSo < (double)a[j].tuSo / a[j].mauSo) {
                struct PhanSo temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}

int main() {
    struct PhanSo a[MAX_N];
    int n;

    do {
        printf("Nhap so luong phan so (n <= %d): ", MAX_N);
        scanf_s("%d", &n);
        if (n <= 0 || n > MAX_N) {
            printf("So luong phan so khong hop le. Vui long nhap lai.\n");
        }
    } while (n <= 0 || n > MAX_N);

    NhapDanhSachPhanSo(a, n);
    XuatDanhSachPhanSo(a, n);

    
    // Tính và xuất tổng và tích các phân số
    struct PhanSo tong = TinhTongPhanSo(a, n);
    printf("Tong cac phan so: %d/%d\n", tong.tuSo, tong.mauSo);

    struct PhanSo tich = TinhTichPhanSo(a, n);
    printf("Tich cac phan so: %d/%d\n", tich.tuSo, tich.mauSo);



    // Sắp xếp mảng và in kết quả
    InterchangeSortTangDan(a, n);
    printf("Mang sau khi sap xep tang dan: ");
    XuatDanhSachPhanSo(a, n);

    InterchangeSortGiamDan(a, n);
    printf("Mang sau khi sap xep giam dan: ");
    XuatDanhSachPhanSo(a, n);

    return 0;
}