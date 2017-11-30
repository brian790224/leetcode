#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> disappearedNumbers;
    vector<int> findDisappearedNumbers(vector<int>& nums) {
		int temp;
		for( unsigned int i = 0; i < nums.size(); i++)
		{
			temp = abs(nums[i]) - 1;
			if( nums[temp] > 0)
				nums[temp] = nums[temp] * (-1);
		}
		for( unsigned int i = 0; i < nums.size(); i++)
		{
			if( nums[i] > 0)
				disappearedNumbers.push_back(i + 1);
		}

		return disappearedNumbers;
    }
};

int main(){
	vector<int> temp;
	vector<int> answer;
	temp.push_back(4);
	temp.push_back(3);
	temp.push_back(2);
	temp.push_back(7);
	temp.push_back(8);
	temp.push_back(2);
	temp.push_back(3);
	temp.push_back(1);
	Solution s;
	answer = s.findDisappearedNumbers(temp);
	for( vector<int>::iterator it = answer.begin(); it != answer.end(); it++)
	{
		cout << *it << endl;
	}
}
