/*
 * =====================================================================================
 *
 *       Filename:  countAndSay.cpp
 *
 *    Description:  OJ: 16ms
 *
 *
 *        Version:  1.0
 *        Created:  10/06/2013 12:26:55 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Wei-Yi Cheng (weiyi-bitw), wc2302@columbia.edu
 *   Organization:  
 *
 * =====================================================================================
 */

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        if(n == 1) return "1";
        string s = countAndSay(n-1);
        int k = s.size();
        string out = "";
        char d = s[0];
        int cnt = 1;
        for(int i = 1; i < k; i++){
            if(s[i] == d){
                cnt++;
            }else{
                out += (char)(cnt + '0');
                out += d;
                d = s[i];
                cnt = 1 ;
            }
        }
        out += (char)(cnt + '0');
        out += d;
	return out;
    }
};

int main(){
	Solution sol;
	cout << sol.countAndSay(5) << endl;

	return 0;

}
