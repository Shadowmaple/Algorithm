# include "iostream"
using namespace std;

class Num {
    private:
        int value;
    public:
        ~Num();
        void quickSort(Num a[], int left, int right) {
            if (left >= right) return ;
            int i = left, j = right;
            int key = a[left].value;
            while (i < j) {
                while (a[j].value >= key && j > i) j--;
                if (j > i)
                    a[i++] = a[j];
                while (a[i].value <= key && i < j) i++;
                if (i < j)
                    a[j--] = a[i];
            }
            a[i].value = key;
            quickSort(a, left, i);
            quickSort(a, i + 1, right);
        };
};
Num::~Num() {

}

int main() {
    int a[] = {42, 12, 3, 3, 8, 11, 9, 23};

    for (int i=0; i < 8; i++) {
        printf("%d%c", a[i], i==7 ? '\n':' ');
    }
    return 0;
}