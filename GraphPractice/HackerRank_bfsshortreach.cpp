#include <bits/stdc++.h>
 
typedef long long int ll;
 using namespace std;

#define OnekFast std::ios_base::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0);
#define error 10e-8
#define PI 2 * std::acos(0.0)
#define digPos(n) std::fixed << std::setprecision(n)
#define CS(n) std::cout << "Case " << n << ": "
#define debug(arr)   \
    for (ll i : arr) \
    std::cout << i << " "

void bfs(std::vector<int> g[], int start, int n){
    std::queue<int> que;

    int depth[n+1] = {};
    bool visited[n+1] = {0};

    int level = 0;

    que.push(start);
	depth[start]=0;
    while(!que.empty()){
        int curr = que.front();
        que.pop();

        if(!visited[curr]){
            visited[curr] = true;

            if(g[curr].size() != 0){
                level++;
                for(int j: g[curr]){
                    if(!visited[j]){
                        que.push(j);

                        if(depth[j] == 0) depth[j] = (depth[curr]+1);
                    }
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(i == start) continue;
        if(depth[i] == 0) std::cout << -1 << " ";
        else std::cout << depth[i]*6 << " ";
    }
    std::cout << "\n";
}

int main(){
	  
	// #ifndef ONLINE_JUDGE  
	// 	   freopen("input.txt", "r", stdin); 
	// 	   freopen("output.txt", "w",stdout);
	// #endif
    OnekFast;
    int q;
    std::cin >> q;

    while(q--){
        int n, m;
        std::cin >> n >> m;

        std::vector<int> g[n+1];

        int u, v;

        for(int i=0;i<m;i++){
            std::cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        int start;
        std::cin >> start;

        bfs(g, start, n);
    }
}