#include<iostream>
#include<algorithm>
#include<vector>
#include<list>

using namespace std;

int main() {
	list<int> vec{ 1,2,3,4,5,6 };
	for (int num : vec)cout << num << " ";
	cout << endl;
	vec.back()++;
	/*for (auto iter = vec.begin(); iter != vec.end();iter++) {
		if (!(*iter & 1)) {
			int num = *iter;
			iter = vec.insert(iter,num);
			iter++;
		}
	}*/
	for (int num : vec)cout << num << " ";
	cout << endl;
	cin.get();
	return 0;
}