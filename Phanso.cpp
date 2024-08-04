#include <iostream>
using namespace std;

struct PhanSo {
    int tuSo;
    int mauSo;
};

void nhapPhanSo(PhanSo& ps) {
    cout << "Nhap tu so: ";
    cin >> ps.tuSo;
    cout << "Nhap mau so: ";
    cin >> ps.mauSo;
}

bool kiemTraMauSoKhacKhong(PhanSo ps) {
    return ps.mauSo != 0;
}

PhanSo tongPhanSo(PhanSo ps1, PhanSo ps2) {
    PhanSo ketQua;
    ketQua.tuSo = ps1.tuSo * ps2.mauSo + ps2.tuSo * ps1.mauSo;
    ketQua.mauSo = ps1.mauSo * ps2.mauSo;
    return ketQua;
}

PhanSo hieuPhanSo(PhanSo ps1, PhanSo ps2) {
    PhanSo ketQua;
    ketQua.tuSo = ps1.tuSo * ps2.mauSo - ps2.tuSo * ps1.mauSo;
    ketQua.mauSo = ps1.mauSo * ps2.mauSo;
    return ketQua;
}

PhanSo tichPhanSo(PhanSo ps1, PhanSo ps2) {
    PhanSo ketQua;
    ketQua.tuSo = ps1.tuSo * ps2.tuSo;
    ketQua.mauSo = ps1.mauSo * ps2.mauSo;
    return ketQua;
}

PhanSo thuongPhanSo(PhanSo ps1, PhanSo ps2) {
    PhanSo ketQua;
    ketQua.tuSo = ps1.tuSo * ps2.mauSo;
    ketQua.mauSo = ps1.mauSo * ps2.tuSo;
    return ketQua;
}

void xuatPhanSo(PhanSo ps) {
    cout << ps.tuSo << "/" << ps.mauSo;
}

int main() {
    PhanSo ps1, ps2;

    cout << "Nhap phan so thu nhat:" << endl;
    nhapPhanSo(ps1);
    if (!kiemTraMauSoKhacKhong(ps1)) {
        cout << "Mau so phai khac 0!" << endl;
        return 1;
    }

    cout << "Nhap phan so thu hai:" << endl;
    nhapPhanSo(ps2);
    if (!kiemTraMauSoKhacKhong(ps2)) {
        cout << "Mau so phai khac 0!" << endl;
        return 1;
    }

    PhanSo tong = tongPhanSo(ps1, ps2);
    PhanSo hieu = hieuPhanSo(ps1, ps2);
    PhanSo tich = tichPhanSo(ps1, ps2);
    PhanSo thuong = thuongPhanSo(ps1, ps2);

    cout << "Tong hai phan so: ";
    xuatPhanSo(tong);
    cout << endl;

    cout << "Hieu hai phan so: ";
    xuatPhanSo(hieu);
    cout << endl;

    cout << "Tich hai phan so: ";
    xuatPhanSo(tich);
    cout << endl;

    cout << "Thuong hai phan so: ";
    xuatPhanSo(thuong);
    cout << endl;

    return 0;
}
