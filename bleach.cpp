#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
std::ifstream f("bleach.in");
std::ofstream g("bleach.out");
std::vector<int> enemies(0);

long long n, k, x, maxx, currentSum;



int main() {
    f >> n >> k;
    while (f >> x) {
        enemies.push_back(x);
    }
    sort(enemies.begin(), enemies.end());
    currentSum = enemies[0];
    maxx = enemies[0];
    for(int i = 1; i < enemies.size(); i++) {
        maxx = std::max(maxx, enemies[i] - currentSum);
        currentSum += enemies[i];
    } 
    g << maxx;
}