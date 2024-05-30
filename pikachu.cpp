#include <fstream>
#include <iostream>
#include <vector>
#include <climits>
std::ifstream f("pikachu.in");
std::ofstream g("pikachu.out");

int n, k;
long long maxx = INT_MIN, minn = 0;

// timpul minim pt a aduce k nivele consecutive la nivelul target
long long timp(long long target, int k, const std::vector<long long> v) {
    long long current = 0, minn = LLONG_MAX;
    for (int i = 0; i < k; i += 1) {
        current += std::abs(v[i] - target);
    }
    for (int i = k; i < (int) v.size(); i += 1) {
        current += std::abs(v[i] - target);
        current -= std::abs(v[i - k] - target);

        minn = std::min(minn, current);
    }
    return minn;
}

int main() {
    f >> n >> k;
    std::vector<long long> v(n);

    for (int i = 0; i < n; i += 1) {
        f >> v[i]; maxx = std::max(maxx, v[i] + 1);
    }

    while (minn < maxx) {
        long long mid = (maxx + minn)/2;
        long long val1 = timp(mid, k, v);
        long long val2 = timp(mid + 1, k, v);
        if (val1 > val2) minn = mid + 1;
        else maxx = mid;
    }

    g << timp(minn, k, v);
    return 0;
}