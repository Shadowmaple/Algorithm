// 三路快排

# include <iostream>
using namespace std;

void quickSort(int *num, int left, int right) {
    if (left >= right) return ;

    int key = num[left];
    int i = left, j = right + 1;
    int mid = i + 1;
    while (mid < j) {
        if (num[mid] < key) {
            swap(num[mid], num[++i]);
            mid++;
        } else if (num[mid] > key) {
            swap(num[mid], num[--j]);
        } else mid++;
    }
    swap(num[left], num[i]);
    quickSort(num, left, i);
    quickSort(num, j, right);
}

int main() {
    int num[] = {9, 8, 1, 12, 3, 5, 4, 12, 5, 14};
    quickSort(num, 0, 9);

    for (int i = 0; i < 9; i++)
        printf("%d ", num[i]);
    putchar('\n');

    return 0;
}