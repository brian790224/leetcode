#include <cstdlib>
#include <iostream>
#include <cmath>

using namespace std;

class Solution {
public:
    bool isPowerOfThree(int n) {
		if(n < 1)
			return false;
		if( n == pow( 3, ceil(log10(n) / log10(3))))
			return true;
		else
			return false;
    }
};

int main(){
	Solution s;
	cout << s.isPowerOfThree(3) << endl;
	cout << s.isPowerOfThree(4) << endl;
	cout << s.isPowerOfThree(11) << endl;
	cout << s.isPowerOfThree(27) << endl;
}
