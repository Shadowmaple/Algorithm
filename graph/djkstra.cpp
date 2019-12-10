// Dijkstra（迪杰斯特拉）算法，单源最短路径

# include <iostream>
# include <queue>
using namespace std;

# define NUM 5
# define INF 9999999

class Dijkstra {
private:
    int matrix[NUM][NUM];
    queue<int> q[NUM];    // 存储路径节点
public:
    Dijkstra(int num[][NUM]) {
        // 太粗暴了，有没有更好的方法？
        for(int i = 0; i < NUM; i++)
            for (int j = 0; j < NUM; j++)
                matrix[i][j] = num[i][j];
    };

    void run(int origin);
};

// origin为源点
void Dijkstra::run(int origin) {
    // dist为当前源点到节点的最短距离，flag为该节点的最短路径是否求得
    int dist[NUM] = {0}, flag[NUM] = {0};
    flag[origin] = 1;

    // 初始化，源点到各点的距离
    for (int i = 0; i < NUM; i++) {
        dist[i] = matrix[origin][i];
        q[i].push(origin);
    }

    for (int i = 0; i < NUM; i++) {
        // 当前最短的路径
        int min = INF, k;
        for (int j = 0; j < NUM; j++) {
            if (!flag[j] && dist[j] < min) {
                min = dist[j];
                k = j;
            }
        }
        flag[k] = 1;

        // 更新各点的最短路径
        for (int j = 0; j < NUM; j++) {
            if (flag[j] || matrix[k][j] == INF) continue;
            if (dist[j] > dist[k] + matrix[k][j]) {
                // 更新最短距离
                dist[j] = dist[k] + matrix[k][j];
                // 更新路径
                q[j] = q[k];
                q[j].push(k);
            }
        }
    }

    // 输出路径
    for (int i = 0; i < NUM; i++) {
        if (dist[i] == INF || i == origin) continue;

        while (!q[i].empty()) {
            cout << q[i].front() << "->";
            q[i].pop();
        }
        cout << i << ": " << dist[i] << endl;
    }
}

int main() {
    int matrix[NUM][NUM] = {
        0, 10, INF, 30, 100,
        INF, 0, 50, INF, INF,
        INF, INF, 0, INF, 10,
        INF, INF, 20, 0, 60,
        INF, INF, INF, INF, 0,
    };
    Dijkstra dij(matrix);

    dij.run(0);

    return 0;
}