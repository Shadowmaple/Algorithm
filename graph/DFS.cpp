# include <iostream>
# include <stack>
using namespace std;

# define NUM 6

bool visited[NUM] = {false};

// 递归
void DFS(int matrix[][NUM], int v) {
    visited[v] = true;
    cout << v + 1;

    for (int i = 0; i < NUM; i++) {
        if (visited[i] || !matrix[v][i]) continue;
        cout << '-';
        DFS(matrix, i);
    }
}

// 非递归
void DFS_2(int matrix[][NUM], int v) {
    stack<int> sk;
    sk.push(v);
    bool visited[NUM] = {false};
    visited[v] = true;
    cout << v + 1 << ' ';

    // sum 为剩余未遍历的节点数
    int i = 0, sum = NUM - 1;
    while (sum > 0 || !sk.empty()) {
        // 超出范围，回溯
        if (i >= NUM) {
            v = sk.top();
            sk.pop();
            i = 0;
            continue;
        }
        // 已访问的节点，或无边
        if (visited[i] || !matrix[v][i]) {
            i++;
            continue;
        }
        // 找到节点
        cout << i + 1 << ' ';
        visited[i] = true;
        sk.push(i);
        sum--;
        v = i;
        i = 0;
    }
}

int main() {
    int matrix[][NUM] = {
        0,1,1,1,0,0,
        1,0,0,0,1,0,
        1,0,0,0,1,0,
        1,0,0,0,0,1,
        0,1,1,0,0,0,
        0,0,0,1,0,0
    };
    int v;
    cin >> v;

    // 输入的节点从1开始
    DFS(matrix, v - 1);
    cout << endl;

    DFS_2(matrix, v - 1);
    cout << endl;

    return 0;
}