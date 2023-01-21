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

int main(){
    OnekFast;
    std::map<int, std::pair<std::string, int>> score;

    int t;
    std::cin >> t;

    while(t--){
        int n;
        std::cin >> n;

        std::string name;
        int s, p;

        for(int i=0;i<n;i++){
            std::cin >> name >> s >> p;

            auto found = score.find(s);

            if(found != score.end()){
                if(found->second.second > p){
                    score[s] = std::make_pair(name, p);
                }else continue;
            }else score[s] = std::make_pair(name, p);
        }

        auto winner = score.end();
        winner--;

        std::cout << winner->second.first << "\n";
        score.clear();
    }
}