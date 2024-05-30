#include <iostream>
#include <fstream>
std::ifstream f("kami.in");
std::ofstream g("kami.out");
// std::ifstream f("in.txt");
// std::ofstream g("out.txt");
int vec[100005], N, M, type, x, y;
int maxx = 0;
int main(){
    f >> N;
    for (int i = 1; i <= N; i++) {
        f >> vec[i];
        maxx = std::max(maxx, vec[i]);
    }
    f >> M;
    for(int i = 1; i <= M; i++){
        f >> type;
        if (type == 0) {
            f >> x >> y;
            vec[x] = y;
        }
        else {
            f >> x;
            long long sum = vec[x];
            int level = x - 1;
            while (sum > vec[level] && level >= 1) {
                    sum += vec[level], level--;
                    if(sum > maxx) level = 0;
                }
            g << level << '\n';
        }
    }
}