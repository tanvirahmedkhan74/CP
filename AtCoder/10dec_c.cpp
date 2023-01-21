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
    ll n, t;

    std::cin >> n >> t;

    std::vector<ll> song(n+1, 0);
    ll temp;

    for(int i=1;i<=n;i++){
        std::cin >> temp;
        song[i] = song[i-1] + temp;
    }

    if(t > song[n]){
        t = t % song[n];
    }

    ll time , ans;
    for(int i=1;i<=n;i++){
        if(t <= song[i]){
            ans = i;
            time = (song[i] - song[i-1]) - (song[i] - t);
            break;
        }
    }

    std::cout << ans << " " << time << "\n";
}