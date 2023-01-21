#include <bits/stdc++.h>

typedef long long int ll;

#define OnekFast std::ios_base::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0);
#define error 10e-8
#define PI 2 * std::acos(0.0)
#define digPos(n) std::fixed << std::setprecision(n)
#define CS(n) std::cout << "Case " << n << ": "
#define debug(arr)   \
    for (ll i : arr) \
    std::cout << i << " "

void printGraph(std::set<int> g[], char start)
{
    for (int i = 0; i <= (int(start) - 65); i++)
    {
        for (int j : g[i])
        {
            std::cout << j << " ";
        }
        std::cout << "\n";
    }
}

std::string dfs(int start, char max, bool visited[], std::set<int> g[]){
    std::stack<int> stck;
    std::string traverse = "";

    stck.push(start);
    //visited[start] = true;

    while(!stck.empty()){
        int curr = stck.top();
        stck.pop();

        //std::cout << char(curr + 65) << " ";
        

        if(!visited[curr]){
            traverse += char(curr + 65);
            visited[curr] = true;
            for(int ver: g[curr]){
                if(!visited[ver])
                stck.push(ver);
            }
        }
    }

    std::sort(traverse.begin(), traverse.end());
    return traverse;
}


void solve()
{
    int t;
    std::cin >> t;

    char start;

    std::string dump, vertex;

    while (t--)
    {   
        std::cin >> start;
        std::cin.ignore();

        std::set<int> g[27];

        while (std::getline(std::cin, vertex))
        {
            if (vertex.empty())
                break;
            
            int u, v;

            u = int(vertex[0]) - 65;
            v = int(vertex[1]) - 65;

            g[u].insert(v);
            g[v].insert(u);
        }

        std::set<std::string> maximals;
        std::string traverse;

        //printGraph(start);
        for(int i=0;i<int(start) - 65 + 1;i++){
            bool visited[int(start) - 65 + 1] = {0};
            traverse =  dfs(i, start, visited, g);
            //std::cout << traverse << "\n";

            maximals.insert(traverse);
        }

        std::cout << maximals.size() << "\n";

        if(t) std::cout << "\n"; 
    }
}


int main()
{
    OnekFast;
    solve();
}