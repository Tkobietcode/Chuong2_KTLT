#include <stdio.h>
#include <string.h>

#define MAX_N 100

struct SinhVien {
    int stt;
    char maSo[15];
    char hoTen[50];
    float diemTieuLuan;
    float diemThi;
    float diemTongKet;
};

// 1. Hàm nhập/xuất danh sách sinh viên
void NhapSinhVien(struct SinhVien* sv) {
    printf("Nhap ma so sinh vien: ");
    scanf_s(" %[^\n]", sv->maSo, 15);
    printf("Nhap ho ten sinh vien: ");
    scanf_s(" %[^\n]", sv->hoTen, 50);
    printf("Nhap diem tieu luan: ");
    scanf_s("%f", &sv->diemTieuLuan);
    printf("Nhap diem thi ket thuc mon: ");
    scanf_s("%f", &sv->diemThi);
    sv->diemTongKet = 0.3 * sv->diemTieuLuan + 0.7 * sv->diemThi;
}

void NhapDanhSachSinhVien(struct SinhVien a[], int n) {
    for (int i = 0; i < n; i++) {
        a[i].stt = i + 1;
        printf("\nNhap thong tin cho sinh vien thu %d:\n", a[i].stt);
        NhapSinhVien(&a[i]);
    }
}

void XuatSinhVien(struct SinhVien sv) {
    printf("%-5d%-15s%-30s%-15.2f%-15.2f%-15.2f\n", sv.stt, sv.maSo, sv.hoTen,
        sv.diemTieuLuan, sv.diemThi, sv.diemTongKet);
}

void XuatDanhSachSinhVien(struct SinhVien a[], int n) {
    printf("\n%-5s%-15s%-30s%-15s%-15s%-15s\n", "STT", "Ma so", "Ho ten",
        "Diem TL", "Diem thi", "Diem tong ket");
    for (int i = 0; i < n; i++) {
        XuatSinhVien(a[i]);
    }
}

// 2. Hàm tính điểm tổng kết
void TinhDiemTongKet(struct SinhVien a[], int n) {
    for (int i = 0; i < n; i++) {
        a[i].diemTongKet = 0.3 * a[i].diemTieuLuan + 0.7 * a[i].diemThi;
    }
}

// 3. Hàm tìm sinh viên có điểm tổng kết cao nhất/thấp nhất
void TimSinhVienDiemCaoNhat(struct SinhVien a[], int n) {
    float max = a[0].diemTongKet;
    int indexMax = 0;
    for (int i = 1; i < n; i++) {
        if (a[i].diemTongKet > max) {
            max = a[i].diemTongKet;
            indexMax = i;
        }
    }
    printf("\nSinh vien co diem tong ket cao nhat:\n");
    XuatSinhVien(a[indexMax]);
}

void TimSinhVienDiemThapNhat(struct SinhVien a[], int n) {
    float min = a[0].diemTongKet;
    int indexMin = 0;
    for (int i = 1; i < n; i++) {
        if (a[i].diemTongKet < min) {
            min = a[i].diemTongKet;
            indexMin = i;
        }
    }
    printf("\nSinh vien co diem tong ket thap nhat:\n");
    XuatSinhVien(a[indexMin]);
}

// 4. Hàm đếm sinh viên đạt/không đạt
void DemSinhVienDatKhongDat(struct SinhVien a[], int n) {
    int soSVDat = 0, soSVKhongDat = 0;
    for (int i = 0; i < n; i++) {
        if (a[i].diemTongKet >= 5) {
            soSVDat++;
        }
        else {
            soSVKhongDat++;
        }
    }
    printf("\nSo sinh vien dat: %d\n", soSVDat);
    printf("So sinh vien khong dat: %d\n", soSVKhongDat);
}

// 5. Hàm quy đổi điểm từ hệ 10 sang hệ 4
void QuyDoiDiemHe4(struct SinhVien* sv) {
    int diemHe10 = (int)(sv->diemTongKet * 10);
    int diemHe4 = 0, i = 1;

    while (diemHe10 != 0) {
        diemHe4 += (diemHe10 % 4) * i;
        diemHe10 /= 4;
        i *= 10;
    }
    printf("Diem tong ket he 4 cua sinh vien %s la: %d\n", sv->hoTen, diemHe4);
}

void QuyDoiDiemDanhSachHe4(struct SinhVien a[], int n) {
    printf("\nDiem tong ket he 4:\n");
    for (int i = 0; i < n; i++) {
        QuyDoiDiemHe4(&a[i]);
    }
}

// 6. Hàm sắp xếp danh sách sinh viên
void SapXepTangDanTheoDiem(struct SinhVien a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i].diemTongKet > a[j].diemTongKet) {
                struct SinhVien temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
    printf("\nDanh sach sinh vien sau khi sap xep tang dan theo diem tong ket:\n");
    XuatDanhSachSinhVien(a, n);
}

void SapXepGiamDanTheoDiem(struct SinhVien a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i].diemTongKet < a[j].diemTongKet) {
                struct SinhVien temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
    printf("\nDanh sach sinh vien sau khi sap xep giam dan theo diem tong ket:\n");
    XuatDanhSachSinhVien(a, n);
}

// 7. Hàm tính điểm trung bình của tất cả các sinh viên
float TinhDiemTrungBinh(struct SinhVien a[], int n) {
    float tongDiem = 0;
    for (int i = 0; i < n; i++) {
        tongDiem += a[i].diemTongKet;
    }
    return tongDiem / n;
}

// 8. Hàm ghi dữ liệu sinh viên ra file txt
void GhiFile(struct SinhVien a[], int n, const char* tenFile) {
    FILE* f;
    fopen_s(&f, tenFile, "w");

    if (f == NULL) {
        printf("Loi mo file!\n");
        return;
    }

    fprintf(f, "%-5s%-15s%-30s%-15s%-15s%-15s\n", "STT", "Ma so", "Ho ten",
        "Diem TL", "Diem thi", "Diem tong ket");
    for (int i = 0; i < n; i++) {
        fprintf(f, "%-5d%-15s%-30s%-15.2f%-15.2f%-15.2f\n", a[i].stt, a[i].maSo, a[i].hoTen,
            a[i].diemTieuLuan, a[i].diemThi, a[i].diemTongKet);
    }

    fclose(f);
    printf("\nDa ghi thong tin sinh vien ra file %s\n", tenFile);
}


int main() {
    struct SinhVien danhSachSinhVien[MAX_N];
    int soLuongSinhVien;

    do {
        printf("Nhap so luong sinh vien: ");
        scanf_s("%d", &soLuongSinhVien);
        if (soLuongSinhVien <= 0 || soLuongSinhVien > MAX_N) {
            printf("So luong sinh vien khong hop le!\n");
        }
    } while (soLuongSinhVien <= 0 || soLuongSinhVien > MAX_N);

    NhapDanhSachSinhVien(danhSachSinhVien, soLuongSinhVien);
    TinhDiemTongKet(danhSachSinhVien, soLuongSinhVien);
    XuatDanhSachSinhVien(danhSachSinhVien, soLuongSinhVien);

    TimSinhVienDiemCaoNhat(danhSachSinhVien, soLuongSinhVien);
    TimSinhVienDiemThapNhat(danhSachSinhVien, soLuongSinhVien);

    DemSinhVienDatKhongDat(danhSachSinhVien, soLuongSinhVien);

    QuyDoiDiemDanhSachHe4(danhSachSinhVien, soLuongSinhVien);

    SapXepTangDanTheoDiem(danhSachSinhVien, soLuongSinhVien);
    SapXepGiamDanTheoDiem(danhSachSinhVien, soLuongSinhVien);

    float diemTrungBinh = TinhDiemTrungBinh(danhSachSinhVien, soLuongSinhVien);
    printf("\nDiem trung binh cua tat ca cac sinh vien la: %.2f\n", diemTrungBinh);

    GhiFile(danhSachSinhVien, soLuongSinhVien, "danhsachsinhvien.txt");

    return 0;
}