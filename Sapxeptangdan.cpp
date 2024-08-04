#include <iostream>
#include <string>
using namespace std;

// Hàm hoán đổi giá trị 2 số nguyên
void swap(int& x, int& y) {
    int t = x;
    x = y;
    y = t;
}

// Hàm hoán đổi giá trị 2 số thực
void swap(float& x, float& y) {
    float t = x;
    x = y;
    y = t;
}
// Hàm hoán đổi giá trị 2 ký tự
void swap(char& x, char& y) {
    char t = x;
    x = y;
    y = t;
}

void swap(string& x, string& y) {
    string t = x;
    x = y;
    y = t;
}

// Hàm sắp xếp tăng dần theo Interchange Sort cho số nguyên
void interchangeSort(int a[], int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (a[i] > a[j])
                swap(a[i], a[j]); // hàm hoán đổi giá trị 2 số nguyên
}

void interchangeSort(float a[], int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (a[i] > a[j])
                swap(a[i], a[j]); // hàm hoán đổi giá trị 2 số thực
}

// Hàm sắp xếp tăng dần theo Interchange Sort cho ký tự
void interchangeSort(char a[], int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (a[i] > a[j])
                swap(a[i], a[j]); // hàm hoán đổi giá trị 2 ký tự
}

void interchangeSort(string a[], int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (a[i] > a[j])
                swap(a[i], a[j]); 
}
int main() {
    // Ví dụ sử dụng hàm sắp xếp cho mảng số nguyên
    int arrInt[] = { 5, 2, 9, 1, 5, 6 };
    int nInt = sizeof(arrInt) / sizeof(arrInt[0]);
    interchangeSort(arrInt, nInt);

    cout << "Mang so nguyen sau khi sap xep: ";
    for (int i = 0; i < nInt; i++) {
        cout << arrInt[i] << " ";
    }
    cout << endl;

    // Ví dụ sử dụng hàm sắp xếp cho mảng số thực
    float arrFloat[] = { 3.2, 1.4, 2.8, 0.9 };
    int nFloat = sizeof(arrFloat) / sizeof(arrFloat[0]);
    interchangeSort(arrFloat, nFloat);

    cout << "Mang so thuc sau khi sap xep: ";
    for (int i = 0; i < nFloat; i++) {
        cout << arrFloat[i] << " ";
    }
    cout << endl;

    // Ví dụ sử dụng hàm sắp xếp cho mảng ký tự
    char arrChar[] = { 'd', 'a', 'c', 'b' };
    int nChar = sizeof(arrChar) / sizeof(arrChar[0]);
    interchangeSort(arrChar, nChar);

    cout << "Mang ky tu sau khi sap xep: ";
    for (int i = 0; i < nChar; i++) {
        cout << arrChar[i] << " ";
    }
    cout << endl;

    // Ví dụ sử dụng hàm sắp xếp cho mảng chuỗi ký tự
    string arrString[] = { "Toi", "ten", "la", "Vu Manh Hung" };
    int nString = sizeof(arrString) / sizeof(arrString[0]);
    interchangeSort(arrString, nString);

    cout << "Mang chuoi ky tu sau khi sap xep: ";
    for (int i = 0; i < nString; i++) {
        cout << arrString[i] << " ";
    }
    cout << endl;

    return 0;
}
