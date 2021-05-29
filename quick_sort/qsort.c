# include <stdio.h>

void quickSort(int *a, int left, int right) {
    if (left >= right) return ;

    int i = left, j = right;
    int key = a[i];
    while (i < j) {
        while (a[j] >= key && j > i) j--;
        if (i < j)
            a[i++] = a[j];

        while (a[i] <= key && i < j) i++;
        if (i < j)
            a[j--] = a[i];
    }
    a[i] = key;

    quickSort(a, left, i - 1);
    quickSort(a, i + 1, right);
}

int main() {
    int a[] = {42, 12, 3, 3, 8, 11, 9, 23};
    quickSort(a, 0, 7);
    for (int i=0; i < 8; i++) {
        printf("%d%c", a[i], i==7 ? '\n':' ');
    }
    return 0;
}
