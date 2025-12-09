#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

void dfs(int v, const vector<vector<int>>& adj, vector<bool>& visited) {
    visited[v] = true;
    for (int u : adj[v]) {
        if (!visited[u]) {
            dfs(u, adj, visited);
        }
    }
}

int main() {
    ifstream fin("input.txt");
    int N, M;
    fin >> N >> M;

    vector<vector<int>> adj(N); // индексация с нуля
    for (int i = 0; i < M; i++) {
        int a, b;
        fin >> a >> b;
        a--; b--; // переводим в нужную индексацию
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<bool> visited(N, false);
    int components = 0;

    for (int i = 0; i < N; i++) {
        if (!visited[i]) {
            dfs(i, adj, visited);
            components++;
        }
    }
    ofstream fout("output.txt");
    fout << components << endl;
    return 0;
}
