#include <iostream>
#include <cmath>
const int mod = 1000000007;
int n, v[100005], rmq[100005][18], power[100005];

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::cin >> n;
    for(int i = 1; i <= n; i++){
        std::cin >> v[i];
        rmq[i][0] = v[i];
    }

    power[0] = 1;
    power[1] = 2;
    for (int i = 2; i <= n; i++) {
            power[i] = 1LL * power[i-1] * 2 % mod;
    }
    for(int i = 1; i <= (int)std::log2(n); i++){
        for(int j = 1; j + (1 << i) - 1 <= n; j++){
            rmq[j][i] = std::max(rmq[j][i - 1], rmq[j+(1 << (i - 1))][i-1]);
        }
    }

    int q;
    std::cin>>q;

    for (int i = 1; i <= q; i++) {
        int l, r;
        std::cin >> l >> r;

        int dim = r - l + 1;
        int maxx = std::max(rmq[l][(int)std::log2(dim)], rmq[r-(1<<((int)std::log2(dim)))+1][(int)std::log2(dim)]);
        std::cout<<1LL * power[dim-1] * maxx % mod<<'\n';
    }

    return 0;
}