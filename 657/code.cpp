#include <iostream>
#include <cstdlib>

using namespace std;

class Solution {
public:
    bool judgeCircle(string moves) {
		int horizontal = 0, vertical = 0;
		int moveCount = moves.size();
		for( string::iterator it = moves.begin(); it != moves.end(); it++)
		{
			switch(*it)
			{
				case 'R':
					horizontal++;
					break;
				case 'L':
					horizontal--;
					break;
				case 'U':
					vertical++;
					break;
				case 'D':
					vertical--;
					break;
				default:
					break;
			}
			moveCount--;
			if(abs(horizontal) + abs(vertical) > moveCount)
				return false;
		}
		return true;
    }
};

int main(){
	Solution s;
	cout << s.judgeCircle("UD") << endl;
	cout << s.judgeCircle("LL") << endl;
	return 0;
}
