#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// Hàm nhập mảng a với n phần tử
void NhapMang(vector<int>& a, int n) {
    for (int i = 0; i < n; i++) {
        cout << "Nhap phan tu thu " << i + 1 << ": ";
        cin >> a[i];
    }
}

// Hàm xuất mảng a với n phần tử
void XuatMang(const vector<int>& a, int n) {
    cout << "Cac phan tu trong mang la: ";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

// Hàm tìm max/min của mảng
void TimMaxMin(const vector<int>& a, int n, int& maxVal, int& minVal) {
    maxVal = a[0];
    minVal = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] > maxVal) maxVal = a[i];
        if (a[i] < minVal) minVal = a[i];
    }
}

// Hàm đếm số phần tử chẵn/lẻ trong mảng
void DemChanLe(const vector<int>& a, int n, int& soChan, int& soLe) {
    soChan = 0;
    soLe = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 0)
            soChan++;
        else
            soLe++;
    }
}

// Hàm đếm số phần tử lớn hơn x
int DemLonHonX(const vector<int>& a, int n, int x) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] > x)
            count++;
    }
    return count;
}

// Hàm tính tổng các phần tử trong mảng
int TinhTong(const vector<int>& a, int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
    }
    return sum;
}

// Hàm xuất giá trị max/min kèm theo vị trí của giá trị đó trong mảng
void XuatMaxMinViTri(const vector<int>& a, int n) {
    int maxVal = a[0], minVal = a[0];
    int maxPos = 0, minPos = 0;
    for (int i = 1; i < n; i++) {
        if (a[i] > maxVal) {
            maxVal = a[i];
            maxPos = i;
        }
        if (a[i] < minVal) {
            minVal = a[i];
            minPos = i;
        }
    }
    cout << "Gia tri lon nhat la " << maxVal << " tai vi tri " << maxPos + 1 << endl;
    cout << "Gia tri nho nhat la " << minVal << " tai vi tri " << minPos + 1 << endl;
}

int main() {
    int n;
    cout << "Nhap so luong phan tu cua mang: ";
    cin >> n;

    vector<int> a(n);

    // 1. Nhập và xuất mảng
    NhapMang(a, n);
    XuatMang(a, n);

    // 3. Tìm max/min của mảng
    int maxVal, minVal;
    TimMaxMin(a, n, maxVal, minVal);
    cout << "Gia tri lon nhat trong mang: " << maxVal << endl;
    cout << "Gia tri nho nhat trong mang: " << minVal << endl;

    // 5. Đếm số phần tử chẵn/lẻ trong mảng
    int soChan, soLe;
    DemChanLe(a, n, soChan, soLe);
    cout << "So luong phan tu chan: " << soChan << endl;
    cout << "So luong phan tu le: " << soLe << endl;

    // 7. Đếm số phần tử lớn hơn x
    int x;
    cout << "Nhap gia tri x: ";
    cin >> x;
    int soLonHonX = DemLonHonX(a, n, x);
    cout << "So luong phan tu lon hon " << x << " la: " << soLonHonX << endl;

    // 9. Tính tổng các phần tử của mảng
    int tong = TinhTong(a, n);
    cout << "Tong cac phan tu trong mang: " << tong << endl;

    // 11. Xuất giá trị max/min kèm theo vị trí của giá trị đó trong mảng
    XuatMaxMinViTri(a, n);

    return 0;
}
