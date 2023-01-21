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

void swap(int arr[], int i, int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int main(){
    OnekFast;
    int t;
    std::cin >> t;

    while(t--){
        int n;
        std::cin >> n;

        int arr[n];

        int max = -1;
        for(int i=0;i<n;i++){
            std::cin >> arr[i];
            max = std::max(max, arr[i]);
        }

        //

        std::vector<std::pair<int, int>> prevec(max + 1);
        for(int i=0;i<n;i++){
            if(i % 2 == 0){
                prevec[arr[i]].second += 1;
            }else prevec[arr[i]].first += 1;
        }

        std::sort(arr , arr + n);

        std::vector<std::pair<int, int>> postvec(max + 1);

        for(int i=0;i<n;i++){
            if(i % 2 == 0){
                postvec[arr[i]].second += 1;
            }else postvec[arr[i]].first += 1;
        }

        bool ok = true;

        for(int i=0;i<n;i++){
            if(prevec[arr[i]].first == postvec[arr[i]].first && prevec[arr[i]].second == postvec[arr[i]].second){
                continue;
            }else ok = false;
        }

        if(ok) std::cout << "YES\n";
        else std::cout << "NO\n";
    }
}