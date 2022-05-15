#include <iostream>
#include <vector>
#include <queue>

#define MAX_VERTEX 10        // 정점의 최대 개수 
#define INFINITY 10000000    // 무한

using namespace std;

vector<int> dijkstra_algo(int start, int Vertex, vector<pair<int, int> > adj[]) {
    vector<int> dist(Vertex, INFINITY);    // 모두 무한으로 초기화 

    priority_queue<pair<int, int> > pq;

    dist[start] = 0;
    pq.push(make_pair(0, start));    // 시작 정점 방문 

    while (!pq.empty()) {
        int distance = -pq.top().first;    //경유한 정점까지의 비용
        int current = pq.top().second;     //경유한 정점의 번호
        pq.pop();

        for (int i = 0; i < adj[current].size(); i++) {                 // 현재 경유한 정점에서 간선이 있는 주변 정점 조사 
            int next = adj[current][i].first;                            
            int next_distance = distance + adj[current][i].second;      // 경유한 현재 정점에서 다음 정점을 갈때 비용 
            if (next_distance < dist[next]) {                           // 더 적은 비용의 거리로 업데이트 
                dist[next] = next_distance;
                pq.push(make_pair(-next_distance, next));               // 우선순위 큐에 저장 
            }
        }
    }

    return dist;
}

int main()
{
    int Vertex, Edge;
    vector<pair<int, int> > adj[MAX_VERTEX];
    cout << "[입력] 정점의 개수(최대 10개) : ";
    cin >> Vertex;

    cout << "[입력] 간선의 개수 : ";
    cin >> Edge;

    for (int i = 0; i < Edge; i++) {
        int from, to, distance;
        cout << "[입력] 그래프 입력(정점-정점-가중치): ";
        cin >> from >> to >> distance;
        adj[from].push_back(make_pair(to, distance));
        adj[to].push_back(make_pair(from, distance));
    }

    printf("\n**************************************************************\n");
    printf("\n**          Dijkstra‘s shortest path 알고리즘 결과         **\n");
    printf("\n**                     (시작 정점: 0번 정점)                **\n");
    printf("\n**************************************************************\n");

    vector<int> dist = dijkstra_algo(0, Vertex, adj);
    for (int i = 0; i < Vertex; i++) {
        printf("0번 정점에서 %d번 정점까지 최단거리 : %d\n", i, dist[i]);
    }
    return 0;
}
