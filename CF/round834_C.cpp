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
    int t;
    std::cin >> t;

    ll l, r, x, a, b;

    while(t--){
        std::cin >> l >> r >> x;
        std::cin >> a >> b;

        int ans = -1;

        if(a == b){
            ans = 0;
        }else if(std::abs(a-b) >= x) ans = 1;
        else if(b + x <= r){
            if(a < b) ans = 2;
            else{
                if(std::abs(a - (b+x)) < x && a + x <= r) ans = 3;
                else ans = 2;
            }
        }else if(b - x >= l){
            if(a > b) ans = 2;
            else{
                if(std::abs(a - (b-x)) < x && a - x >= l) ans = 3;
                else ans = 2;
            }
        }

        std::cout << ans << "\n";
    }
}