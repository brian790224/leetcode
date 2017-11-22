#include<iostream>
#include<cstdlib>
#include<string>

using namespace std;

class Solution {
public:
    int hammingDistance(int x, int y) {
		int lastBitX, lastBitY;
		int counter = 0;
    	for(int i = 0; i <= 32; i++)
		{
			lastBitX = x & 0x1;
			lastBitY = y & 0x1;
			if( ((lastBitX & lastBitY) == 0) && (((~lastBitX & ~lastBitY) & 0x1 ) != 0x1))
			{
				counter++;
			}
			x = x >> 1;
			y = y >> 1;
		}
		return counter;
    }
};

int main(){
	Solution s;
	cout << s.hammingDistance(1, 4) << endl;
}
