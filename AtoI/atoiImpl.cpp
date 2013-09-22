/*
 * =====================================================================================
 *
 *       Filename:  atoiImpl.cpp
 *
 *    Description:  32 ms
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
#include <climits>

using namespace std;

class Solution
{
  public:
	int atoi(const char *str){
		const char* ptr = str;
		int sign = 1;
		while(*ptr == ' ') ptr++;
		if(*ptr == '-'){
			sign = -1;
			ptr++;
		}else if(*ptr=='+'){
			ptr++;
		}
		int num = 0;
		bool overflow = false;
		int const multiplyThreshold = INT_MAX / 10;
		while(*ptr){
			if(*ptr > '9' || *ptr < '0') break;
			if(multiplyThreshold < num){ 
				overflow = true;
				break;
			}
			num *= 10 ;
			int digit = *ptr - '0';
			if(INT_MAX - num < digit){
				overflow = true;
				break;
			}
			num += digit;
			ptr++;
		}
		if(overflow)
			return sign > 0 ? INT_MAX : INT_MIN;
		return sign*num;
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


