/*
 * =====================================================================================
 *
 *       Filename:  isMatch.cpp
 *
 *    Description:  76ms
 *    		source: http://discuss.leetcode.com/questions/222/wildcard-matching
 *
 *        Version:  1.0
 *        Created:  10/06/2013 10:47:21 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Wei-Yi Cheng (weiyi-bitw), wc2302@columbia.edu
 *   Organization:  
 *
 * =====================================================================================
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution{
  public:
    bool isMatch(const char *s, const char *p) {
	if(!*s && !*p) return true;
	const char *star_p = NULL, *star_s = NULL;
	while(*s){
		if(*p == '?' || *p == *s){
			++p; ++s;
		}else if(*p == '*'){
			while(*p == '*') ++p;
			if(!*p) return true;
			star_p = p;
			star_s = s;
		}else if((*p != *s || !*p) && star_p){
			s = ++star_s;
			p = star_p;
		}else{
			return false;
		}
	}
	while(*p){
		if(*p++ != '*') return false;
	}

	return true;
    }
};

int main()
{
	Solution sol;
	cout << sol.isMatch("aa", "a") << endl;
	return 0;
}


