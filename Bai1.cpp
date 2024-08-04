#include <iostream>
using namespace std;

int BinarySearch(int a[], int n, int x) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (a[mid] == x)
            return mid;  // Tìm thấy x trong a tại vị trí mid
        else if (a[mid] < x)
            left = mid + 1;  // Tìm kiếm bên phải
        else
            right = mid - 1;  // Tìm kiếm bên trái
    }
    return -1;  // Không tìm thấy x trong a
}

int main() {
    int a[] = { 7, 9, 13, 17, 27, 30, 31, 35, 38, 40 };
    int n = sizeof(a) / sizeof(a[0]);

    int valuesToFind[] = { 17, 35, 40, 23, 10, 36 };

    for (int i = 0; i < 6; i++) {
        int result = BinarySearch(a, n, valuesToFind[i]);
        if (result != -1)
            cout << "tim thay " << valuesToFind[i] << " tai vi tri: " << result << endl;
        else
            cout << "Khong tim thay " << valuesToFind[i] << endl;
    }
    return 0;
}
