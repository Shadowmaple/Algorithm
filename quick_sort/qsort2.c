// 三路快排

# include <stdio.h>

void quickSort(int *a, int left, int right) {
    if (left >= right) return ;

    int i = left, j = right, mid = left;
    int key = a[i];
    while (mid <= j) {
        if (a[mid] < key) {
            int x = a[mid];
            a[mid] = a[i];
            a[i] = x;
            i++;
            mid++;
        } else if (a[mid] > key) {
            int x = a[mid];
            a[mid] = a[j];
            a[j] = x;
            j--;
        } else {
            mid++;
        }
    }
    quickSort(a, left, i - 1);
    quickSort(a, j + 1, right);
}

int main() {
    int a[] = {42, 12, 3, 3, 8, 11, 9, 23};
    quickSort(a, 0, 7);
    for (int i=0; i < 8; i++) {
        printf("%d%c", a[i], i==7 ? '\n':' ');
    }
    return 0;
}