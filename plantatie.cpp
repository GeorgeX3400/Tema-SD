#include <bits/stdc++.h>
#define N 500
#define logN 9
using namespace std;

ifstream f("plantatie.in");
ofstream g("plantatie.out");

int n, m, a[N + 3][N + 3];
int maxValue[N + 3][N + 3][logN + 3], p;
    int l, c, lat;

int findMax(int lin1, int col1, int latura) {
    int lin2 = lin1 + latura - 1;
    int col2 = col1 + latura - 1;
    int k = int(log2(latura));
    int maxx = maxValue[lin1][col1][k];
    maxx =  max(maxx, maxValue[lin1][col2 - (1 << k) + 1][k]);
    maxx = max(maxx, maxValue[lin2 - (1 << k) + 1][col1][k]);
    maxx = max(maxx, maxValue[lin2 - (1 << k) + 1][col2 - (1 << k) + 1][k]);
    return maxx;
}



int main()
{
    f >> n >> m;
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) {
            f >> a[i][j];
        }
    }    
     p = int(log2(n));
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) {
            maxValue[i][j][0] = a[i][j];
        }
    }

    for(int k = 1; k <= p; ++k) {
        for(int i = 1; i + (1 << k) - 1 <= n; ++i) {
            for(int j = 1; j + (1  << k) - 1 <= n; ++j) {
                int max1 = maxValue[i][j][k - 1];
                int max2 = maxValue[i][j + (1 << (k - 1))][k - 1];
                int max3 = maxValue[i + (1 << (k - 1))][j][k - 1];
                int max4 = maxValue[i + (1 << (k - 1))][j + (1 << (k - 1))][k - 1];
                maxValue[i][j][k] = max(max(max1, max2), max(max3, max4));
            }
        }
    }
    for(int i = 1; i <= m; ++i) {
        f >> l >> c >> lat;
        g << findMax(l, c, lat) << "\n";
    }

    return 0;
}