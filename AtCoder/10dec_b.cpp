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

bool is_upper(char c){
    return (c >= 'A' && c <= 'Z');
}

bool is_numeric(char c){
    int t = c - '0';
    return (t >= 0 && t <= 9);
}
int main(){
    OnekFast;
    std::string s;
    std::cin >> s;

    bool ok = true;

    std::string num = "";

    if(s.length() != 8){
        ok = false;
    }else{
        for(int i=0;i<s.length();i++){
            if(i == 0 || i == 7){
                if(!is_upper(s[i])){
                    ok = false;
                    break;
                }
            }else{
                if(!is_numeric(s[i])){
                    ok = false;
                    break;
                }else{
                    num += s[i];
                }
            }
        }

        if(ok){
            ll temp = std::stoi(num);

            if(temp >= 100000 && temp <= 999999){
                ok = true;
            }else ok = false;
        }
    }
    if(ok) std::cout << "Yes\n";
    else std::cout << "No\n";
}