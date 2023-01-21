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

std::map<ll, ll> prime_factorization(ll n){
    std::map<ll, ll> factors;

    for(ll i=2; i <= n;i++){
        if(n % i == 0){
            factors[i] = 0;

            while(n % i == 0){
                factors[i] += 1;
                n /= i;
            }
        }
    }

    if(n != 1){
        factors[n] = 1;
    }

    return factors;
}

int main(){
    int t;
    std::cin >> t;

    while(t--){
        ll a, b;
        std::cin >> a >> b;

        std::map<ll, ll> pA, pB;

        pA = prime_factorization(a);
        pB = prime_factorization(b);

        for(auto a: pA){
            std::cout << a.first << " " << a.second << "\n";
        }

        for(auto b: pB){
            std::cout << b.first << " " << b.second << "\n";
        }

        int cnt = 0;

        for(auto item: pA){
            auto found = pB.find(item.first);

            if(found != pB.end()){
                cnt += (std::min(pB[item.first] , item.second) * 2);
            }
        }

        std::cout << cnt << "\n";
    }
}