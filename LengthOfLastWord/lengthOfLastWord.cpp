/*
 * =====================================================================================
 *
 *       Filename:  lengthOfLastWord.cpp
 *
 *    Description:  20ms
 *
 *        Version:  1.0
 *        Created:  10/19/2013 04:30:54 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Wei-Yi Cheng (weiyi-bitw), wc2302@columbia.edu
 *   Organization:  
 *
 * =====================================================================================
 */

#include <iostream>

using namespace std;

class Solution{
  public:
	int lengthOfLastWord(const char *s){
		int l = 0;
		while(*s){
			if(*(s++) != ' ') ++l;
			else if(*s && *s != ' '){
				l = 0;
			}
		}
		return l;
	}

};

int main()
{
	char s[] = "b a ";
	Solution sol;
	cout << sol.lengthOfLastWord(s) << endl;

	return 0;
}


