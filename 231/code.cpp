#include <cstdlib>
#include <iostream>

using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
		if(n <= 0)
			return false;
		while( n > 0)
		{
			if( (n % 2 == 1) && (n > 1))
				return false;
			n = n >> 1;
		}
		return true;
    }
};

int main()
{
	Solution s;
	cout << s.isPowerOfTwo(1) << endl;
	cout << s.isPowerOfTwo(2) << endl;
	cout << s.isPowerOfTwo(3) << endl;
	cout << s.isPowerOfTwo(512) << endl;
}
