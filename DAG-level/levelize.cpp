#include <bits/stdc++.h>
using namespace std;

int levelize(int n, vector<vector<int>>& edges)
{
    vector<vector<int>> snks(n, vector<int>());
    vector<int> indeg(n);
    for (auto edge : edges) {
        snks[edge[0]].push_back(edge[1]);
        indeg[edge[1]]++;
    }
    vector<int> level(n);
    queue<int> todo;
    for (int i = 0; i < n; i++) {
        if (indeg[i] == 0)
            todo.push(i);
    }
    if (todo.size() == 0)
        return -1;
    int lvl = 0;
    int count = todo.size();
    while (todo.size() > 0) {
        lvl++;
        int s = todo.size();
        for (int k = 0; k < s; k++) {
            int c = todo.front();
            todo.pop();
            for (int snk : snks[c]) {
                if (--indeg[snk] == 0) {
                    level[snk] = lvl;
                    todo.push(snk);
                    count++;
                }
            }
        }
    }
    if (count < n)
        return -1;
    return lvl;
}

int main() 
{
    int n;
    cin >> n;
   	int m;
    cin >> m;
    vector<vector<int>> edges;
    while (m--) {
    	int a, b;
	    cin >> a;
        cin >> b;
        edges.push_back({a, b});
    }
    cout << "n = " << n << endl;
    int max_lvl = levelize(n, edges);
    cout << max_lvl << endl;
    return 0;
}
