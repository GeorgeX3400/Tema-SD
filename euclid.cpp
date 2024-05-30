#include <fstream>
#include <vector>

std::ifstream f("euclid.in");
std::ofstream g("euclid.out");

int T;
int M, N, h, w; 
std::vector<std::vector<int>> mat;

int gcd(int a, int b) {
    if(b == 0) return a;
    return gcd(b, a%b);
}

int queryRes() {
    int maxGcd = 0;
    for(int l = 0; l < M - h + 1; ++l) {
        for(int c = 0; c < N - w + 1; ++c) {
            int currentGcd = mat[l][c];
            for(int i = l; i < l + h - 1 && currentGcd > maxGcd; i++) {
                for(int j = c; j < c + w - 1 && currentGcd > maxGcd; j++) {
                    currentGcd = gcd(currentGcd, mat[i][j]);
                }
            }
            maxGcd = std::max(maxGcd, currentGcd);
        }
    }
    return maxGcd;
}

int main() {
    f >> T;
    for(int i = 1; i <= T; ++i) {
        f >> M >> N >> h >> w;
        mat.resize(M);
        for(int i = 0; i < M; ++i) {
            mat[i].resize(N);
        }        
        for(int i = 0; i < M; ++i) {
            for(int j = 0; j < N; ++j) {
                f >> mat[i][j];
            }
        }
        g << "Case #" << i << ": " << queryRes() << "\n";
    }
    return 0;
}