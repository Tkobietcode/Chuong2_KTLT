#include <iostream>
#include <algorithm> // Thư viện hỗ trợ sắp xếp
using namespace std;

int BinarySearch(char a[], int n, char x) {
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
    char a[] = { 'Z', 'R', 'L', 'K', 'H', 'F', 'E', 'C', 'A' };
    int n = sizeof(a) / sizeof(a[0]);

    // Sắp xếp dãy ký tự theo thứ tự tăng dần
    sort(a, a + n);

    char valuesToFind[] = { 'R', 'C', 'D', 'Q' };

    for (int i = 0; i < 4; i++) {
        int result = BinarySearch(a, n, valuesToFind[i]);
        if (result != -1)
            cout << "Tim Thay " << valuesToFind[i] << " Tai vi tri: " << result << endl;
        else
            cout << "Khong tim thay " << valuesToFind[i] << endl;
    }

    return 0;
}
