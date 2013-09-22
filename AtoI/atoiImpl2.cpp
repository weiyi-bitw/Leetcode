/*
 * =====================================================================================
 *
 *       Filename:  atoiImpl.cpp
 *
 *    Description:  68 ms
 *
 *        Version:  1.0
 *        Created:  09/19/2013 03:54:11 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Wei-Yi Cheng (weiyi-bitw), ninpy.weiyi@gmail.com
 *   Organization:  Columbia University
 *
 * =====================================================================================
 */

#include <iostream>
#include <stack>
#include <climits>

using namespace std;

class Solution
{
  public:
	int atoi(const char *str){
		const char* ptr = str;
		int sign = 1;
		stack<int> stk;
		while(*ptr == ' ') ptr++;
		if(*ptr == '-'){
			sign = -1;
			ptr++;
		}else if(*ptr=='+'){
			ptr++;
		}
		while(*ptr){
			if(*ptr > '9' || *ptr < '0') break;
			stk.push(*ptr - '0');
			ptr++;
		}
		int factor = 1;
		int out = 0;
		bool overflow = false;
		int diff = INT_MAX;
		int ratio = INT_MAX;
		while(!stk.empty()){
			if(ratio < stk.top()){
				overflow = true;
				break;
			}
			int addition = stk.top() * factor;
			//cout << out << "\t" << diff << "\t" << addition << endl;
			if(diff < addition){
				overflow = true;
				break;
			}
			out += addition;
			diff -= addition;
			factor *= 10;
			ratio /= 10;
			stk.pop();
		}
		if(overflow)
			return sign > 0 ? INT_MAX : INT_MIN;
		return sign*out;
	}


};

int main()
{
	Solution sol;
	const char *str = "-2147483647";
	int k = sol.atoi(&str[0]);
	cout << k << endl;
	return 0;
}


