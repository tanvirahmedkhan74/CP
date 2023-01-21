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

std::vector<bool> prime;

void sieve(ll n){
    prime.assign(n+1, true);

    prime[0] = prime[1] = false;

    for(ll i=2; i*i<=n;i++){
        if(prime[i]){
            for(ll j= i*i;j<=n;j+=i){
                prime[j] = false;
            }
        }
    }
}

int main(){
    sieve(1299709  + 1);

    OnekFast;

    ll n;
    std::cin >> n;

    while(n != 0){
        int cnt = 0;
    
        ll left , right;
        left = right = n;

        if(!prime[n]){
            while(!prime[left]){
                left--;
            }

            while(!prime[right]){
                right++;
            }

            cnt = right - left;
        }

        std::cout << cnt << "\n";
        std::cin >> n;
        
    }
}