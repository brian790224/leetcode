#include <iostream>
#include <map>


using namespace std;

class Solution {
public:
	map<string,string> CodetoURL;
	int codeValue = 0;
	string codeString = "000000";
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        int tempCodeValue;

		codeValue++;
		tempCodeValue = codeValue;
		for( string::reverse_iterator rit = codeString.rbegin(); rit != codeString.rend(); rit++)
		{
			(*rit) = '0' + (tempCodeValue % 74);
			tempCodeValue = tempCodeValue / 74;
		}
		
		CodetoURL.insert(pair< string, string>( "http://tinyurl.com/" + codeString, longUrl));
        return "http://tinyurl.com/" + codeString; 
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return CodetoURL.find(shortUrl)->second; 
    }
};

int main(){
	Solution s;
	string shortURL;
	shortURL = s.encode("https://leetcode.com/problems/design-tinyurl");
	cout << shortURL << endl;
	cout << s.decode(shortURL) << endl;
}

