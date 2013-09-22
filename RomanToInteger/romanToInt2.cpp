/*
 * =====================================================================================
 *
 *       Filename:  romanToInt.cpp
 *
 *    Description:  164 msec
 *
 *        Version:  1.0
 *        Created:  09/21/2013 09:17:44 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Wei-Yi Cheng (weiyi-bitw), ninpy.weiyi@gmail.com
 *   Organization:  Columbia University
 *
 * =====================================================================================
 */

#include <iostream>
#include <string>

using namespace std;

class Solution
{
  public:
	int romanToInt(string s){
		int n = s.size();
		int num = 0, i = 0;
		while(i < n){
			if(i < n-1){
				if( s[i+1] == 'V' && s[i] == 'I' ){
					num += 4; i += 2;
				}else if(s[i+1] == 'X' && s[i] == 'I'){
					num += 9; i += 2;
				}else if(s[i+1] == 'L' && s[i] == 'X'){
					num += 40; i += 2;
				}else if(s[i+1] == 'C' && s[i] == 'X'){
					num += 90; i += 2;
				}else if(s[i+1] == 'D' && s[i] == 'C'){
					num += 400; i += 2;
				}else if(s[i+1] == 'M' && s[i] == 'C'){
					num += 900; i += 2;
				}else{
					if(s[i] == 'I'){
						num += 1;
					}else if(s[i] == 'V'){
						num += 5;
					}else if(s[i] == 'X'){
						num += 10;
					}else if(s[i] == 'L'){
						num += 50;
					}else if(s[i] == 'C'){
						num += 100;
					}else if(s[i] == 'D'){
						num += 500;
					}else if(s[i] == 'M'){
						num += 1000;
					}
					i++;
				}
			}else{
				if(s[i] == 'I'){
					num += 1;
				}else if(s[i] == 'V'){
					num += 5;
				}else if(s[i] == 'X'){
					num += 10;
				}else if(s[i] == 'L'){
					num += 50;
				}else if(s[i] == 'C'){
					num += 100;
				}else if(s[i] == 'D'){
					num += 500;
				}else if(s[i] == 'M'){
					num += 1000;
				}
				i++;
			}
		}
		return num;
	}


};

int main()
{
	Solution sol;
	string r = "MMXIII";
	cout << sol.romanToInt(r) << endl;

	return 0;
}


