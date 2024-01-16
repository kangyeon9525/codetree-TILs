#include <iostream>
#include <vector>
#include <tuple>
#include <queue>

using namespace std;

const int MAX_N = 100000;
const int MAX_M = 100000;

vector<pair<int, int>> graph[MAX_N + 1];
priority_queue<pair<int, int>> pq;

int dist[MAX_N + 1];
bool visited[MAX_N + 1];

int main() {
    int n, m;
    cin >> n >> m;

    tuple<int, int, int> edges[MAX_M + 1];

    // 입력 받은 간선 정보
    for (int i = 1; i <= m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        edges[i] = make_tuple(x, y, z);
    }

    // 그래프를 인접리스트로 표현
    for (int i = 1; i <= m; i++) {
        int x, y, z;
        tie(x, y, z) = edges[i];
        graph[x].push_back(make_pair(y, z));
        graph[y].push_back(make_pair(x, z));
    }

    // 초기값 설정
    for (int i = 1; i <= n; i++)
        dist[i] = (int)1e9;

    // 시작 위치에는 dist 값을 0으로 설정
    dist[1] = 0;

    // 우선순위 큐에 시작점을 넣어줌
    pq.push(make_pair(0, 1));

    // 프림 알고리즘
    int ans = 0;
    while (!pq.empty()) {
        int min_dist, min_index;
        tie(min_dist, min_index) = pq.top();
        pq.pop();

        min_dist = -min_dist;

        if (visited[min_index])
            continue;

        visited[min_index] = true;
        ans += min_dist;

        for (int j = 0; j < (int)graph[min_index].size(); j++) {
            int target_index, target_dist;
            tie(target_index, target_dist) = graph[min_index][j];

            int new_dist = target_dist;
            if (dist[target_index] > new_dist) {
                dist[target_index] = new_dist;
                pq.push(make_pair(-new_dist, target_index));
            }
        }
    }

    cout << ans;
    return 0;
}