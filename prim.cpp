#include<iostream>
using namespace std;
class Prims {
    private:
        int n;
        int cost[100][100];
        int parent[100];
        bool visited[100];

    public:
        Prims(int numVertices) {
            n = numVertices;
            for (int i = 0; i < n; i++) {
                parent[i] = -1;
                visited[i] = false;
                for (int j = 0; j < n; j++) {
                    cost[i][j] = INT_MAX;
                }
            }
        }

        void addEdge(int u, int v, int w) {
            cost[u][v] = w;
            cost[v][u] = w;
        }

        int findMinVertex(int key[]) {
            int minKey = INT_MAX, minIndex;
            for (int i = 0; i < n; i++) {
                if (!visited[i] && key[i] < minKey) {
                    minKey = key[i];
                    minIndex = i;
                }
            }
            return minIndex;
        }

        void primMST() {
            int key[n];
            for (int i = 0; i < n; i++) {
                key[i] = INT_MAX;
            }
            key[0] = 0;
            parent[0] = -1;

            for (int i = 0; i < n - 1; i++) {
                int u = findMinVertex(key);
                visited[u] = true;

                for (int v = 0; v < n; v++) {
                    if (cost[u][v] != INT_MAX && !visited[v] && cost[u][v] < key[v]) {
                        parent[v] = u;
                        key[v] = cost[u][v];
                    }
                }
            }

            for (int i = 1; i < n; i++) {
                cout << parent[i] << " - " << i << endl;
            }
        }
};
int main() {
    Prims p(3);
    p.addEdge(0, 1, 1);
    p.addEdge(0, 2, 4);
    p.addEdge(1, 2, 3);
   
    p.primMST();
    return 0;
}
