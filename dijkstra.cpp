#include <stdio.h>
#include <limits.h>
#include<iostream>
using namespace std;
#define V 4
class shortestPath{
public:
int minDistance(int dist[], bool sptSet[]) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}

void dijkstra(int graph[V][V], int src) {
    int dist[V];
    bool sptSet[V];

    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        sptSet[i] = false;
    }

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, sptSet);
        sptSet[u] = true;

        for (int v = 0; v < V; v++)
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX
                && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    cout<<"Vertex \t Distance from Source\n";
    for (int i = 0; i < V; i++)
        cout<<"\n"<< i<<"\t"<< dist[i];
}
};
int main() {
	shortestPath s;
	cout<<"new"<<endl;
    int graph[V][V] = { { 0, 1, 2, 1 },
                        { 1, 0, 0, 1 },
                        { 2, 0, 0, 1 },
                        { 0, 1, 1, 1 },
                        };

    s.dijkstra(graph, 0);

    return 0;
}
