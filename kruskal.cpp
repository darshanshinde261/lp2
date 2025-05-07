#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int V = 5; // Number of vertices

struct Edge {
    int u, v, w;
};

int parent[V];

int find(int i) {
    if (parent[i] == i) return i;
    return parent[i] = find(parent[i]);
}

void unionSet(int u, int v) {
    parent[find(u)] = find(v);
}

int main() {
    int graph[V][V] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    vector<Edge> edges;
    for (int i = 0; i < V; i++) {
        for (int j = i + 1; j < V; j++) {
            if (graph[i][j])
                edges.push_back({i, j, graph[i][j]});
        }
    }

    sort(edges.begin(), edges.end(), [](Edge a, Edge b) {
        return a.w < b.w;
    });

    for (int i = 0; i < V; i++) parent[i] = i;

    cout << "Edge \tWeight\n";
    for (auto e : edges) {
        if (find(e.u) != find(e.v)) {
            cout << e.u << " - " << e.v << "\t" << e.w << endl;
            unionSet(e.u, e.v);
        }
    }

    return 0;
}
