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

// Hàm tìm max/min
void TimMinMax(int a[], int n, int* max, int* min) {
    *max = *min = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] > *max) {
            *max = a[i];
        }
        if (a[i] < *min) {
            *min = a[i];
        }
    }
}



// Hàm tìm kiếm phần tử x (trả về vị trí đầu tiên tìm thấy)
int TimKiem(int a[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (a[i] == x) {
            return i;
        }
    }
    return -1; // Không tìm thấy
}



// 6. Đếm trên a có bao nhiêu phần tử lớn hơn x
int DemPhanTuLonHonX(int a[], int n, int x) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] > x) {
            count++;
        }
    }
    return count;
}



// Tìm số nguyên tố
int LaSoNguyenTo(int num) {
    if (num <= 1) {
        return 0; 
    }
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}
//  Xuất các số nguyên tố trong a
void XuatSoNguyenTo(int a[], int n) {
    printf("Cac so nguyen to trong mang: ");
    for (int i = 0; i < n; i++) {
        if (LaSoNguyenTo(a[i])) {
            printf("%d ", a[i]);
        }
    }
    printf("\n");
}



// 10. Xuất các phần tử ở vị trí chẵn/vị trí lẻ trong a
void XuatPhanTuViTriChanLe(int a[], int n) {
    printf("Cac phan tu o vi tri chan: ");
    for (int i = 0; i < n; i += 2) {
        printf("%d ", a[i]);
    }
    printf("\n");

    printf("Cac phan tu o vi tri le: ");
    for (int i = 1; i < n; i += 2) {
        printf("%d ", a[i]);
    }
    printf("\n");
}



// 12. Ghep 2 day tang dan
void GhepDayTangDan(int b[], int m, int c[], int n, int a[]) {
    int i = 0, j = 0, k = 0;
    while (i < m && j < n) {
        if (b[i] <= c[j]) {
            a[k++] = b[i++];
        }
        else {
            a[k++] = c[j++];
        }
    }
    while (i < m) {
        a[k++] = b[i++];
    }
    while (j < n) {
        a[k++] = c[j++];
    }
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

    /*2 Tìm max/min*/
    TimMinMax(a, n, &max, &min);
    printf("Phan tu lon nhat: %d\n", max);
    printf("Phan tu nho nhat: %d\n", min);

    

    //4 Tìm kiếm phần tử x
    printf("Nhap phan tu can tim: ");
    scanf_s("%d", &x);

    int viTri = TimKiem(a, n, x);
    if (viTri != -1) {
        printf("Tim thay %d tai vi tri: %d\n", x, viTri);
    }
    else {
        printf("Khong tim thay %d trong mang\n", x);
    }


    // 6. Đếm phần tử lớn hơn x
    printf("Nhap x: ");
    scanf_s("%d", &x);
    int soPhanTuLonHon = DemPhanTuLonHonX(a, n, x);
    printf("So phan tu lon hon %d la: %d\n", x, soPhanTuLonHon);

 

    // 8. Xuất số nguyên tố
    XuatSoNguyenTo(a, n);


    // 10. Xuất phần tử vị trí chẵn/lẻ
    XuatPhanTuViTriChanLe(a, n);



    // 12. Ghep 2 day tang dan
    int m;
    printf("Nhap so phan tu cua mang b (m <= %d): ", MAX_SIZE);
    scanf_s("%d", &m);

    


   

    return 0;
}