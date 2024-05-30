#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
#include <utility>
std::ifstream f("proc2.in");
std::ofstream g("proc2.out");

struct compare {
    bool operator() (std::pair<int, int> x, std::pair<int, int> y){
        return x.first > y.first;
    }
};

std::priority_queue<int, std::vector<int>, std::greater<int>> processors;
std::priority_queue<std::pair<int,int>, std::vector<std::pair<int, int>> , compare> tasks;
int N, M, s, d;

int main() {
    f >> N >> M;
    for(int i = 1; i <= N; i++) processors.push(i);
    for(int i = 1; i <= M; i++) {
        f >> s >> d;
        std::cout << s << ":\n";
        int x = 0;
        while(!tasks.empty() && tasks.top().first <= s){
            std::cout << tasks.top().second << '\n';
            x++;
            processors.push(tasks.top().second);
            tasks.pop();
        }
        std::cout << x << '\n';
        g << processors.top() << '\n';
        tasks.push({s + d, processors.top()});
        std:: cout << s + d << " " << processors.top() << '\n';
        processors.pop();
    }
    while(!tasks.empty()) {
        std::cout << tasks.top().first << " " << tasks.top().second << '\n';
        tasks.pop();
    }
    return 0;
}
