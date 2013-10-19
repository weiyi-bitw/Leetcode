/*
 * =====================================================================================
 *
 *       Filename:  multiply.cpp
 *
 *    Description:  OJ: 32ms
 *
 *        Version:  1.0
 *        Created:  10/06/2013 10:21:26 PM
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
    string multiply(string num1, string num2) {
        int l1 = num1.size();
        int l2 = num2.size();
        int carry = 0;
	int digit = 0;
        string out = "";
        for(int k = 0; k < l1+l2; k++){
	    int m = carry;
            for(int i = 0; i < l1; i++){
                int j = k-i;
                if(j < l2 && j >= 0){
                    m += (num1[l1-i-1] - '0') * (num2[l2-j-1] - '0');
                }
            }
	    digit = m % 10;
	    carry = m / 10;
	    out += (char)(digit+'0');
        }
        // reverse string
        for(int k = 0; k < (l1+l2)/2; k++){
            char tmp = out[k];
            out[k] = out[l1+l2-k-1];
            out[l1+l2-k-1] = tmp;
        }
	// remove leading 0's
	int k;
	for( k = 0; k < (l1+l2)-1; k++){
		if(out[k] != '0') break;
	}
	out.erase(0, k);
        return out;
    }
};

int main()
{
	string n1 = "23";
	string n2 = "2";
	Solution sol;
	string m = sol.multiply(n1, n2);
	cout << m << endl;

	return 0;
}


