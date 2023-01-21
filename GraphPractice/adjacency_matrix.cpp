#include <bits/stdc++.h>



int main(){
    int n, m;
    std::cin >> n >> m;

    int graph[n+1][n+1];

    int v1, v2, edge;
    for(int i=0;i<m;i++){
        std::cin >> v1 >> v2;

        graph[v1][v2] = 1;
        graph[v2][v1] = 1;
    }
}