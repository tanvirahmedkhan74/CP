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


std::vector<bool> summation(200000, false);

void sieve(){
    ll sum = 0;
    for(int i=1;i<500;i++){
        sum += i;
        summation[sum] = true;
    }
}

int main(){
    OnekFast
    sieve();

    int t;
    std::cin >> t;


    while(t--){
        int m, s;
        std::cin >> m >> s;
        std::map<int, int> vec;

        ll sum = 0;
        int temp;

        bool flag = true;

        int big = -1;

        for(int i=0;i<m;i++){
            std::cin >> temp;
            big = std::max(big, temp);

            sum += temp;
        }

         if(((big)*(big - 1)/2) > (sum + s)) flag = false;

        if(flag && summation[sum + s]){
            std::cout << "YES\n";
        }else std::cout << "NO\n";
    }
}