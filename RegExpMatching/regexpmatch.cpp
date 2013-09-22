/*
 * =====================================================================================
 *
 *       Filename:  regexpmatch.cpp
 *
 *    Description:  source: http://leetcode.com/2011/09/regular-expression-matching.html
 *
 *        Version:  1.0
 *        Created:  09/19/2013 08:31:28 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Wei-Yi Cheng (weiyi-bitw), ninpy.weiyi@gmail.com
 *   Organization:  Columbia University
 *
 * =====================================================================================
 */

#include <iostream>
#include <assert.h>

using namespace std;

class Solution
{
  public:
	bool isMatch(const char *s, const char *p){
		assert(s && p);
		if(*p == '\0') return *s == '\0';
		if(*(p+1) != '*'){
			assert(*p != '*');
			return ((*p == *s) || (*p=='.' && *s != '\0')) && isMatch(s+1, p+1);
		}
		while((*p==*s)||(*p=='.' && *s != '\0')){
			if(isMatch(s, p+2)) return true;
			s++;
		}
		return isMatch(s, p+2);
	}
};

int main()
{
	Solution sol;
	cout << sol.isMatch("aab","c*a*b") << endl;
	
	return 0;
}




