#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
		int answer = 0;
		sort( nums.begin(), nums.end());
		for(vector<int>::iterator it = nums.begin(); it != nums.end(); it++)
		{
			answer += *it;
			it++;
		}
		return answer;
    }
};

int main(){
	vector<int> test;
	test.push_back(1);
	test.push_back(4);
	test.push_back(3);
	test.push_back(2);
	Solution s;
	cout << s.arrayPairSum(test) << endl;
	return 0;
}
