/*
 * =====================================================================================
 *
 *       Filename:  maxArea.cpp
 *
 *    Description:  112 msec
 *
 *        Version:  1.0
 *        Created:  09/21/2013 12:00:27 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Wei-Yi Cheng (weiyi-bitw), ninpy.weiyi@gmail.com
 *   Organization:  Columbia University
 *
 * =====================================================================================
 */

#include <iostream>
#include <algorithm>

using namespace std;

class Solution
{
  public:
	int maxArea(vector<int> &height){
		int n = height.size();
		int maxArea = 0;
		int i = 0, j = n-1;
		while(i < j){
			int a = min(height[i], height[j]) * (j-i);
			maxArea = max(maxArea, a);
			if(height[i] > height[j]){
				j--;
			}else if(height[i] < height[j]){
				i++;
			}else{
				if(height[i+1] > height[j-1]){
					i++;
				}else{
					j--;
				}
			}
		}
		return maxArea;
	}
};



