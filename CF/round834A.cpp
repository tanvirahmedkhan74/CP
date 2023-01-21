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

int main()
{
    OnekFast;

    int t;
    std::cin >> t;

    std::string line;
    while (t--)
    {
        std::cin >> line;

        bool flag = true;

        if(line[0] != 'Y' && line[0] != 'e' && line[0] != 's'){
            flag = false;
        }

        for (int i = 0; i < line.length() - 1; i++)
        {
            if((line[i] == 'Y' && line[i+1] == 'e') || (line[i] == 'e' && line[i+1] == 's') || (line[i] == 's' && line[i+1] == 'Y')){
                continue;
            }else{
                flag = false;
                break;
            }
        }

        if (flag)
        {
            std::cout << "YES\n";
        }
        else
            std::cout << "NO\n";
    }
}