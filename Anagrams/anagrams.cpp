/*
 * =====================================================================================
 *
 *       Filename:  anagrams.cpp
 *
 *    Description:  240 ms
 *
 *        Version:  1.0
 *        Created:  10/14/2013 10:22:30 PM
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
#include <string>
#include <map>
#include <algorithm>

using namespace std;

class Solution{
  public:
	vector<string> anagrams(vector<string> &strs){
		vector<string> out;
		map<string, vector<string> > dict;
		int n = strs.size();
		for(int i = 0; i < n; i++){
			string k = strs[i];
			sort(k.begin(), k.end());
			dict[k].push_back(strs[i]);
		}
		map<string, vector<string> >::iterator it;
		for(it = dict.begin(); it != dict.end(); it++){
			if(it->second.size() > 1){
				for(unsigned int k = 0; k < it->second.size(); k++){
					out.push_back(it->second[k]);
				}
			}
		}
		return out;
	}
};

int main()
{
	return 0;
}
