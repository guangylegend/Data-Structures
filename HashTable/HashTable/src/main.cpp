#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

class cmp {
public:
	bool operator()(const vector<int>& a, const vector<int>& b) {
		return a[0]>b[0];
	}

};

int main() {
	priority_queue<vector<int>, vector<vector<int>>, cmp> pq;
	pq.push({ 5,1,2 });
	pq.push({ 4,1,1 });
	while (!pq.empty()) {
		auto tuple = pq.top();
		cout << tuple[0] << " " << tuple[1] << " " << tuple[2] << endl;
		pq.pop();
	}
	cin.get();
	return 0;
}