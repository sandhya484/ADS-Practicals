#include<iostream>
#include<queue>
using namespace std;

int G[10][10], n, visited[10];

// DFS using adjacency matrix
void DFS(int v) {
    cout << v << " ";
    visited[v] = 1;

    for(int i = 1; i <= n; i++) {
        if(G[v][i] == 1 && visited[i] == 0)
            DFS(i);
    }
}

// BFS using adjacency list logic (matrix used for simplicity)
void BFS(int v) {
    queue<int> q;
    q.push(v);
    visited[v] = 1;

    while(!q.empty()) {
        int x = q.front(); q.pop();
        cout << x << " ";

        for(int i = 1; i <= n; i++) {
            if(G[x][i] == 1 && visited[i] == 0) {
                q.push(i);
                visited[i] = 1;
            }
        }
    }
}

int main() {
    int edges, u, v, start;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter number of edges: ";
    cin >> edges;

    // input graph
    for(int i = 0; i < edges; i++) {
        cout << "Enter edge (u v): ";
        cin >> u >> v;
        G[u][v] = 1;
        G[v][u] = 1; // undirected graph
    }

    // DFS
    cout << "\nDFS starting node: ";
    cin >> start;

    for(int i=1;i<=n;i++) visited[i]=0;
    DFS(start);

    // BFS
    cout << "\nBFS starting node: ";
    cin >> start;

    for(int i=1;i<=n;i++) visited[i]=0;
    BFS(start);

    return 0;
}
