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
        if(x.first == y.first) return x.second < y.second;
        return x.first > y.first;
    }
};

std::priority_queue<std::pair<int, int> , std::vector<std::pair<int, int>>, compare> it;
std::priority_queue<int , std::vector<int>, std::greater<int>> c;
int main() {
    f >> N >> M >> K;
    for(int i = 1; i <= M; i++){
        int x, y;
        f >> x >> y;
        it.push(std::make_pair(x, y));
    }
    int nrTimbre = 0, sum = 0;
    while(nrTimbre < N) {
        while(!it.empty() && it.top().first >= std::max(N - nrTimbre, K)){
            c.push(it.top().second);
            it.pop();
        }
        nrTimbre += K;
        sum += c.top();
        c.pop(); 
    }
    g << sum;
    return 0;
}