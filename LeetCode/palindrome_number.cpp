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


bool isPalindrome(int x) {
    int temp = x;
    long long int rev = 0;

    while(temp){
        rev = (rev * 10) + (temp % 10);
        temp /= 10;
    }

    return rev == x;
}

int main(){
    std::cout << isPalindrome(1234567899);
}