#include <iostream>
#include <vector>

unsigned long long cnt = 0;
int N;
int main()
{
	std::cin >> N;
	std::vector<int> v(N);
	std::vector<int> minLeft(N);

	for(int i = 0; i < N; i++) {
		std::cin >> v[i];
		if(i == 0)
			minLeft[i] = i;
		else if(v[i - 1] < v[i])
			minLeft[i] = i;
		else {
			int idx = minLeft[i - 1];
			while(idx > 0 && v[idx] >= v[i]){
				if(v[idx] >= v[i])
					idx = minLeft[idx] - 1;
				else
					break;
			}
			if(v[idx] < v[i])
				idx++;
			if(idx < 0)
				idx = 0;
			minLeft[i] = idx;
		}
	}

	int l = 0;
	while(l < N){
		cnt += l - minLeft[l];
			for(int i = 1; i < l - minLeft[l]; i++){
				if(l + i < N && minLeft[l + i] > l){
					cnt += l - minLeft[l] - i;
				}
				else break;
			}
		l++;
	}
	std::cout<<cnt;
}