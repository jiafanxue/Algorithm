/*
Question:
	Given a pattern and a string str. find if str follows the same pattern.

	e.g.
		pattern = "abba", str = "dog cat cat dog" should return true.
		pattern = "abba", str = "dog cat cat fish" should return false.
		pattern = "aaaa", str = "dog cat cat dog" should return false.
		pattern = "abba", str = "dog dog dog dog" should return false.
*/
#include <iostream>
#include <map>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <set>
using namespace std;

class Solution {
public:
    // bool wordPattern(string pattern, string str) {
    //     istringstream ss(str);
    //     string word;
    //     unordered_map<char, string> bmap;
    //     unordered_map<string, char> rbmap;

    //     for(char c : pattern) {
    //     	if(!(getline(ss, word, ' '))) {
    //     		return false;
    //     	}
    //     	if(bmap.emplace(c, word).first->second != word) {
    //     		return false;
    //     	}
    //     	if(rbmap.emplace(word, c).first->second != c) {
    //     		return false;
    //     	}
    //     }

    //     return !getline(ss, word, ' ');
    // }

    bool wordPattern(string pattern, string str) {
    	istringstream strcin(str);
        string s;
        vector<string> vs;
        while(strcin >> s) vs.push_back(s);
        if (pattern.size() != vs.size()) return false;
        map<string, char> s2c;
        map<char, string> c2s;
        for (unsigned i = 0; i < vs.size(); ++i) {
            if (s2c[vs[i]] == 0 && c2s[pattern[i]] == "") { 
                s2c[vs[i]] = pattern[i]; 
                c2s[pattern[i]] = vs[i]; 
                continue; 
            }
            if (s2c[vs[i]] != pattern[i]) return false;
        }
        return true;
    }
};

int main(int argc, char const *argv[])
{
	string pattern;
	string str;

	cin >> pattern >> str;

	Solution su;
	if(su.wordPattern(pattern, str)) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}

	return 0;
}