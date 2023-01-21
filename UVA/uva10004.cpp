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

std::vector<int> g[201];

void dfs(int start){
    std::stack<int> st;
    bool visited[201] = {0};
    int color[201] = {0};

    bool colorable = true;

    st.push(start);
    while(colorable && !st.empty()){
        int top = st.top();
        st.pop();

        if(!visited[top]){
            visited[top] = true;
            for(int v: g[top]){
                if(visited[v] && v == top) continue;
                if(visited[v]){
                    //std::cout << v << "\n";
                    colorable = false;
                    break;
                }else st.push(v);
            }
        }
    }

    if(colorable) std::cout << "BICOLORABLE.\n";
    else std::cout << "NOT BICOLORABLE.\n";
}

void printGraph(std::vector<int> g[], char start, int n)
{
    for (int i = 0; i <= n; i++)
    {
        std::cout << i << "-> ";
        for (int j : g[i])
        {
            std::cout << j << " ";
        }
        std::cout << "\n";
    }
}

int main(){
    int n;

    std::cin >> n;

    while(n != 0){
        g->clear();

        int m;
        std::cin >> m;

        int u, v;
        for(int i=0;i<m;i++){
            std::cin >> u >> v;

            g[u].push_back(v);
            g[v].push_back(u);
        }

        //printGraph(g, 0, n);
        
        dfs(0);
        std::cin >> n;
    }
}