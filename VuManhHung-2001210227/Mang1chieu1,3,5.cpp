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

int demSoNguyenTo(int a[], int n) {
    int dem = 0;
    for (int i = 0; i < n; i++) {
        if (laSoNguyenTo(a[i])) {
            dem++;
        }
    }
    return dem;
}

int timViTriLonNhatCuoiCung(int a[], int n) {
    int giaTriLonNhat = a[0];
    int viTriLonNhat = 0;
    for (int i = 1; i < n; i++) {
        if (a[i] >= giaTriLonNhat) {
            giaTriLonNhat = a[i];
            viTriLonNhat = i;
        }
    }
    return viTriLonNhat;
}
bool laDayChanLeXenKe(int a[], int n) {
    for (int i = 1; i < n; i++) {
        if ((a[i - 1] % 2 == 0 && a[i] % 2 == 0) || (a[i - 1] % 2 != 0 && a[i] % 2 != 0)) {
            return false;
        }
    }
    return true;
}

int main() {
    int a[] = { 2, 3, 4, 5, 6, 7, 8, 9 };
    int n = sizeof(a) / sizeof(a[0]);

    cout << "So phan tu la so nguyen to: " << demSoNguyenTo(a, n) << endl;
    cout << "Vi tri cuoi cung cua phan tu lon nhat: " << timViTriLonNhatCuoiCung(a, n) << endl;
    cout << "Mang co phai day chan le xen ke: " << (laDayChanLeXenKe(a, n) ? "Co" : "Khong") << endl;

    return 0;
}
