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

std::vector<bool> isPrime;
std::vector<ll> primes;

void sieve(ll n){
    isPrime.assign(n+1, true);
    isPrime[0] = isPrime[1] = false;

    for(ll i=2;i*i <= n;i++){
        if(isPrime[i]){
            for(ll j= i*i ;j<=n; j += i){
                isPrime[j] = false;
            }
        }
    }

    for(int i=2;i<=n;i++){
        if(isPrime[i]) primes.push_back(i);
    }
}


int main(){
    OnekFast;
    int n, k;
    std::cin >> n >> k;

    sieve(n+1);
    int cnt = 0;

    for(int i=2;i<primes.size();i++){
        if(cnt == k) break;

        bool ok = false;

        int curr = primes[i];

        for(int j=i-1;j>0;j--){
            if(primes[j] + primes[j-1] + 1 == curr){
                ok = true;
                break;
            }
        }

        if(ok) cnt++;
    }

    if(cnt == k) std::cout << "YES\n";
    else std::cout << "NO\n";
}