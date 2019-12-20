# include <iostream>
# include <queue>
using namespace std;

# define NUM 6

void BFS(int matrix[][NUM]) {
    bool visited[NUM] = {false};
    queue<int> q;

    for (int i = 0; i < NUM; i++) {
        if (visited[i]) continue;
        q.push(i);
        visited[i] = true;
        cout << i + 1 << ' ';
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (int j = 0; j < NUM; j++) {
                if (visited[j] || !matrix[v][j]) continue;
                cout << j + 1 << ' ';
                q.push(j);
                visited[j] = true;
            }
        }
    }
    cout << endl;
}

void BFS_with_origin_vector(int matrix[][NUM], int v) {
    bool visited[NUM] = {false};
    queue<int> q;
    q.push(v);
    visited[v] = true;
    cout << v + 1 << ' ';

    while (!q.empty()) {
        v = q.front();
		q.pop();
		for (int i = 0; i < NUM; i++) {
			if (visited[i] || !matrix[v][i]) continue;
			cout << i + 1 << ' ';
			q.push(i);
			visited[i] = true;
		}
	}
    cout << endl;

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

    BFS(matrix);

    int v;
    cout << "输入起点（从1开始）：";
    cin >> v;
    BFS_with_origin_vector(matrix, v - 1);

    return 0;
}
