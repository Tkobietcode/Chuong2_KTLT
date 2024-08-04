#include <iostream>
using namespace std;

bool laSoNguyenTo(int n) {
    if (n <= 1) return false;
    if (n == 2) return true;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

bool kiemTraMangToanNguyenTo(int a[], int n) {
    for (int i = 0; i < n; i++) {
        if (!laSoNguyenTo(a[i])) {
            return false;
        }
    }
    return true;
}

enum KieuSapXep { TangDan, GiamDan, KhongTangKhongGiam };

KieuSapXep kiemTraSapXep(int a[], int n) {
    bool tangDan = true;
    bool giamDan = true;

    for (int i = 1; i < n; i++) {
        if (a[i] < a[i - 1]) {
            tangDan = false;
        }
        if (a[i] > a[i - 1]) {
            giamDan = false;
        }
    }

    if (tangDan) return TangDan;
    if (giamDan) return GiamDan;
    return KhongTangKhongGiam;
}

int main() {
    int a[] = { 2, 3, 5, 7, 11, 13 };
    int n = sizeof(a) / sizeof(a[0]);

    if (kiemTraMangToanNguyenTo(a, n)) {
        cout << "Mang chua toan so nguyen to" << endl;
    }
    else {
        cout << "Mang khong chua toan so nguyen to" << endl;
    }

    int b[] = { 1, 2, 3, 4, 5 };
    int m = sizeof(b) / sizeof(b[0]);

    KieuSapXep kq = kiemTraSapXep(b, m);

    switch (kq) {
    case TangDan:
        cout << "Mang tang dan" << endl;
        break;
    case GiamDan:
        cout << "Mang giam dan" << endl;
        break;
    case KhongTangKhongGiam:
        cout << "Mang khong tang khong giam" << endl;
        break;
    }

    return 0;
}
