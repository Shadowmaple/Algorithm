# include <iostream>
using namespace std;

// 递归二分查找
int searchRecursion(int *num, int key, int left, int right) {
    if (left > right) return 0;

    int mid = (left + right) / 2;
    if (num[mid] == key) return mid;
    else if (num[mid] > key)
        return searchRecursion(num, key, left, mid - 1);
    else
        return searchRecursion(num, key, mid + 1, right);
}

// 非递归二分查找
int searchNoRecursion(int *num, int key, int size) {
    int left = 0, right = size - 1;

    while (left <= right) {
        int mid = (left + right) / 2;
        if (num[mid] == key) return mid;
        else if (num[mid] > key)
            right = mid - 1;
        else
            left = mid + 1;
    }
    return 0;
}

int main() {
    int a[] = {1,2,3,4,5};
    cout << searchRecursion(a, 4, 0, 4) << endl;
    cout << searchNoRecursion(a, 4, 5) << endl;

    return 0;
}