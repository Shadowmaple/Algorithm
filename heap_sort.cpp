# include <iostream>
using namespace std;

// 构建大根堆
void heapBuild(int *num, int size) {
    for (int i = 1; i < size; i++) {
        int index = i;
        int parentIndex = (index - 1) / 2;
        while (num[index] > num[parentIndex]) {
            swap(num[index], num[parentIndex]);
            index = parentIndex;
            parentIndex = (index - 1) / 2;
        }
    }
}

// 向下调整，大根堆
void heapUpdate(int *num, int size) {
    int index = 0, leftIndex = 1, rightIndex = 2;
    int maxIndex;

    while (leftIndex < size) {
        if (rightIndex < size && num[rightIndex] > num[leftIndex])
            maxIndex = rightIndex;
        else
            maxIndex = leftIndex;
        // maxIndex = num[leftIndex] > num[rightIndex] ? leftIndex : rightIndex;

        if (num[maxIndex] < num[index]) break;

        swap(num[index], num[maxIndex]);
        index = maxIndex;
        leftIndex = index * 2 + 1;
        rightIndex = index * 2 + 2;
    }
}

// 堆排序
void heapSort(int *num, int size) {
    // 初始建堆
    heapBuild(num, size);

    while (size > 1) {
        swap(num[size - 1], num[0]);
        // 调整至大根堆
        heapUpdate(num, --size);
    }
}

int main() {
    int num[] = {2, 5, 1, 6, 22, 12, 4, 3};
    heapSort(num, 8);

    for (int i = 0; i < 8; i++)
        cout << num[i] << " ";
    cout << endl;

    return 0;
}