/*
 * =====================================================================================
 *
 *       Filename:  isMatch.cpp
 *
 *    Description:  324 ms
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
	int ns = 1;
	const char *ss = s;
	while(*ss){ns++; ss++;}
	int np = 1;
	const char *pp = p;
	while(*pp){if(*pp != '*') np++; pp++;}

	if(ns < np) return false;

	vector<vector<bool> > r(2, vector<bool>(ns, false));
	bool flag = 1;
	r[0][0] = true;
	do{ //*p
		int idx = 1;
		ss = s;
		if(*p == '*'){
			while(*p == '*') ++p;
			--p;
			r[flag][0] = r[!flag][0];
			for(; idx <= ns; idx++){
				if(r[!flag][idx] || r[flag][idx-1]) break;
				else r[flag][idx] = false;
			}
			for(; idx <= ns; idx++){
				r[flag][idx] = true;
			}
		}else{
			do{
				bool r_flag = false;
				if(*ss == *p || *p == '?'){
					r_flag = r[!flag][idx-1];
				}
				r[flag][idx] = r_flag;
				idx++; ss++;
			}while(*ss);
			r[flag][0] = false;
		}
		++p;
		flag = !flag;
	}while(*p);
	return r[!flag][ns-1];
    }
};

int main()
{
	Solution sol;
	cout << sol.isMatch("ab", "??") << endl;
	return 0;
}


