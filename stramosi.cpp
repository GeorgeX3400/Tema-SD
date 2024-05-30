#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <fstream>

std::ifstream f("stramosi.in");
std::ofstream g("stramosi.out");
int N, M;
int stramosi [20][250001];

int main() {
    f >> N >> M;
    for(int i = 1; i <= N; i++) {
        f >> stramosi[0][i];
    }
    for(int i = 1; i <= 19; i++) {
        for(int j = 1; j <= N; j++) {
            stramosi[i][j] = stramosi[i-1][stramosi[i-1][j]];
        }
    }

    for(int i = 1; i <= M; i++){
        int x, y;
        f >> x >> y;
        int exp = 0;
        while(y) {
            if(y & 1) x = stramosi[exp][x];
            exp += 1;
            y /= 2;
        }
        g << x << '\n';
    }

    return 0;
}