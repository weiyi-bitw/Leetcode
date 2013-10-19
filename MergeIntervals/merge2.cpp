/*
 * =====================================================================================
 *
 *       Filename:  merge.cpp
 *
 *    Description:  64 ms
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

struct compareIntervals{
	bool operator() (Interval const& i1, Interval const& i2) const{
		if(i1.start == i2.start){
			return i1.end < i2.end;
		}else{
			return i1.start < i2.start;
		}
	}
};

class Solution{
  public:
	vector<Interval> merge(vector<Interval> &intervals){
		vector<Interval> out;
		int n = intervals.size();
		if(n < 1) return out;
		sort(intervals.begin(), intervals.end(), compareIntervals());
		Interval it(intervals[0].start, intervals[0].end);
		for(int i = 1; i < n; i++){
			if(intervals[i].start <= it.end && intervals[i].end > it.end){
				it.end = intervals[i].end;
			}else if(intervals[i].start > it.end){
				out.push_back(it);
				it.start = intervals[i].start;
				it.end = intervals[i].end;
			}
		}
		out.push_back(it);
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
