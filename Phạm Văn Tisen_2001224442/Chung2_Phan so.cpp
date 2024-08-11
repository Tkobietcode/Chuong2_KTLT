#include <stdio.h>

// Khai báo cấu trúc phân số
struct PhanSo {
    int tuSo;
    int mauSo;
};

// 1. Viết hàm nhập vào phân số
void NhapPhanSo(struct PhanSo* ps) {
    do {
        printf("Nhap tu so: ");
        scanf_s("%d", &(ps->tuSo));
        printf("Nhap mau so (khac 0): ");
        scanf_s("%d", &(ps->mauSo));
        if (ps->mauSo == 0) {
            printf("Mau so phai khac 0. Vui long nhap lai.\n");
        }
    } while (ps->mauSo == 0);
}

// 2. Viết hàm xuất phân số
void XuatPhanSo(struct PhanSo ps) {
    printf("%d/%d", ps.tuSo, ps.mauSo);
}


// 4. Viết hàm tối giản phân số
int UCLN(int a, int b) {
    while (b != 0) {
        int temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

void ToiGianPhanSo(struct PhanSo* ps) {
    int ucln = UCLN(ps->tuSo, ps->mauSo);
    ps->tuSo /= ucln;
    ps->mauSo /= ucln;
}



int main() {
    struct PhanSo ps1, ps2, ps;

    printf("Nhap phan so thu nhat:\n");
    NhapPhanSo(&ps1);

    printf("Nhap phan so thu hai:\n");
    NhapPhanSo(&ps2);

    printf("Phan so thu nhat: ");
    XuatPhanSo(ps1);
    printf("\n");

    printf("Phan so thu hai: ");
    XuatPhanSo(ps2);
    printf("\n");

    printf("Toi gian hai phan so:");
    ToiGianPhanSo(&ps);
    printf("\n");
    

   

    return 0;
}