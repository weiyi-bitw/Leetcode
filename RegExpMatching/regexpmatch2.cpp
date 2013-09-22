/*
 * =====================================================================================
 *
 *       Filename:  regexpmatch2.cpp
 *
 *    Description:  This solution treated '*' as wildcard. Not what the problem wants.
 *
 *        Version:  1.0
 *        Created:  09/21/2013 11:54:25 AM
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

class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        const char *ss = s;
                const char *pp = p;
                int m = 0, n = 0;
                while(*ss){
                        m++;
                        ss++;
                }
                while(*pp){
                        n++;
                        pp++;
                }
                bool* matchMem = new bool[(m+1)*(n+1)];
                bool** match = new bool*[m+1];
                for(int i = 0; i < m+1; i++)
                        match[i] = &matchMem[i*(n+1)];

                match[0][0] = 1;
                for(int j = 1; j < n+1; j++) match[0][j] = 0;
                for(int i = 1; i < m+1; i++){
                        match[i][0] = 0;
                        for(int j = 1; j < n+1; j++){
                                if(match[i-1][j-1] &&
                                        (s[i-1]==p[j-1] || s[i-1] == '.' || p[j-1]=='.' || s[i-1] == '*' || p[j-1]=='*')) match[i][j] = 1;
                                else if( (s[i-1]=='*' || p[j-1]=='*') && (match[i-1][j] || match[i][j-1])) match[i][j] = 1;
                                else if(match[i-1][j] && (s[i-2] == '*' && s[i-1] == p[j-1]) ) match[i][j] = 1;
                                else if(match[i][j-1] && (p[j-2] == '*' && s[i-1] == p[j-1])) match[i][j] = 1;
                                else match[i][j] = 0;
                        }
                }

             bool out = match[m][n];
                delete [] match;
                delete [] matchMem;
                return out;

    }
};

int main()
{
	Solution sol;
	cout << sol.isMatch("aabcabcd","a*bcd*") << endl;

	return 0;
}

