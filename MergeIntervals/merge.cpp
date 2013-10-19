/*
 * =====================================================================================
 *
 *       Filename:  merge.cpp
 *
 *    Description:  76 ms
 *    	source: http://discuss.leetcode.com/questions/233/merge-intervals
 *
 *        Version:  1.0
 *        Created:  10/19/2013 03:14:40 PM
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
#include <algorithm>

using namespace std;

struct Interval{
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};

bool compareInterval(const Interval & i1, const Interval & i2){
	return i1.start < i2.start;
}

class Solution{
  public:
	vector<Interval> merge(vector<Interval> &intervals){
		vector<Interval> out;
		int n = intervals.size();
		sort(intervals.begin(), intervals.end(), compareInterval);
		int i = 0;
		while(i < n){
			out.push_back(intervals[i++]);
			while(i < n && intervals[i].start <= out.back().end){
				out.back().end = max(out.back().end, intervals[i++].end);
			}
		}
		return out;
	}

};

ostream & operator<<(ostream& os, Interval it){
	os << "[" << it.start << "," << it.end << "]";
	return os;
}


int main()
{
	int points[] = {2, 3, 4, 5, 6, 7, 8, 9, 1, 10};
	vector<Interval> intervals;
	Solution sol;

	for(unsigned int i = 0; i < 5; i++){
		intervals.push_back(Interval(points[2*i], points[2*i+1]));
	}
	vector<Interval> out = sol.merge(intervals);
	for(unsigned int i = 0; i < out.size(); i++){
		cout << out[i] << endl;
	}

	return 0;
}
