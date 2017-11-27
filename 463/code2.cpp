#include <cstdlib>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
		int landcount = 0, contiLandCount = 0;
		for( int i = 0; i < grid.size(); i++)
		{
			for( int j = 0; j < grid[0].size(); j++)
			{
				if(grid[i][j] == 1)
				{
					landcount++;
					if( i != 0 && grid[i - 1][j] == 1)
					{
						contiLandCount++;
					}
					if( j != 0 && grid[i][j - 1] == 1)
					{
						contiLandCount++;
					}
				}
			}
		}
		return 4 * landcount - 2 * contiLandCount;
    }
};

int main(){
	vector<vector<int>> grid(4);
	grid[0].push_back(0);
	grid[0].push_back(1);
	grid[0].push_back(0);
	grid[0].push_back(0);
	grid[1].push_back(1);
	grid[1].push_back(1);
	grid[1].push_back(1);
	grid[1].push_back(0);
	grid[2].push_back(0);
	grid[2].push_back(1);
	grid[2].push_back(0);
	grid[2].push_back(0);
	grid[3].push_back(1);
	grid[3].push_back(1);
	grid[3].push_back(0);
	grid[3].push_back(0);
	for( vector<vector<int>>::iterator it = grid.begin(); it != grid.end(); it++)
	{
		for( vector<int>::iterator it2 = (*it).begin(); it2 != (*it).end(); it2++)
		{
			cout << (*it2) << " ";
		}
		cout << endl;
	}
	Solution s;
	cout << s.islandPerimeter(grid) << endl;
}
