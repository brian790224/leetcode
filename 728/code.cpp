#include<iostream>
#include<vector>
#include<cstdlib>
#include<string>

using namespace std;

class Solution {
public:
	vector<int> selfDividingNumbers(int left, int right) {
    	vector<int> answer;
		string valueToString;
		unsigned int temp, foundCounter;
		for(int value = left; value <= right; value++)
		{
			foundCounter = 0;
			valueToString = to_string(value);
			for(string::iterator it = valueToString.begin(); it != valueToString.end(); it++)
			{
				temp = *it - '0';
			    //cout << temp << endl;
				if( temp == 0 )
				{
					break;
				}
				else if( value % temp != 0)
				{
					break;
				}
				foundCounter++;
			}
			if( foundCounter == valueToString.size() )
			{
				answer.push_back(value);
			}
		}
		return answer;
	}
};

int main(){
	Solution s;
	vector<int> answer = s.selfDividingNumbers(1, 22);
	for (vector<int>::iterator it = answer.begin() ; it != answer.end(); ++it)
    	cout << ' ' << *it;
	cout << endl;
	return 0;
}
