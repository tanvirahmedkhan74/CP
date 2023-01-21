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

    int t;
    std::cin >> t;

    while(t--){
        int n;
        std::cin >> n;

        std::vector<ll> arr1(n), arr2(n);
        ll max_a = -1, max_i = 0;

        for(int i=0;i<n;i++){
            std::cin >> arr1[i];

            max_a = std::max(max_a, arr1[i]);
            if(max_a == arr1[i]) max_i = i;
        }

        for(int i=0;i<n;i++){
            std::cin >> arr2[i];
        }

        bool flag = true;

        ll max_diff = max_a - arr2[max_i];

        std::vector<ll> diff_arr;

        if(max_diff < 0){
            flag = false;
        }else{
            for(int i=0;i<n;i++){
            int diff;

            if(arr1[i] == 0 && arr2[i] == 0) continue;

            if(arr2[i] == 0){
                if(arr1[i] > max_diff){
                    flag = false;
                    break;
                }
            }else{
                if(arr1[i] - arr2[i] != max_diff){
                    flag = false;
                    break;
                }
            }
        }

        }

        if(flag){
            std::cout << "YES\n";
        }else std::cout << "NO\n";
    }
}