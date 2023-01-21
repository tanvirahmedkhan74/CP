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

std::vector<ll> lucky_prime(1001);

void seive_lucky_prime(){
    int idx = 1;

    int num = 30;
    while(idx < 1001){
        std::set<int> primes;
        int curr = num;

        for(ll i=2;i*i <= curr;i++){
            while(curr % i == 0){
                primes.insert(i);
                curr /= i;
            }
        }

        if(curr > 1) primes.insert(curr);

        if(primes.size() > 2) lucky_prime[idx++] = num;
        num++;
    }
}

int main(){
    OnekFast;
    seive_lucky_prime();

    int t;
    std::cin >> t;

    while(t--){
        int n;
        std::cin >> n;

        std::cout << lucky_prime[n] << "\n";
    }
}