#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include <queue>
#include <algorithm>

std::ifstream f("timbre.in");
std::ofstream g("timbre.out");
int N, M, K;

struct compare {
    bool operator() (std::pair<int, int> x, std::pair<int, int> y){
        return x.second > y.second;
    }
};

std::priority_queue<std::pair<int, int> , std::vector<std::pair<int, int>>, compare> timbre;
int main() {
    f >> N >> M >> K;
    for(int i = 1; i <= M; i++){
        int x, y;
        f >> x >> y;
        timbre.push({x, y});
    }
    int nrTimbre = 0, sum = 0;
    while(nrTimbre < N) {
        nrTimbre += std::min(timbre.top().first, K);
        sum += timbre.top().second;
        timbre.pop();
    }
    g << sum;
    return 0;
}