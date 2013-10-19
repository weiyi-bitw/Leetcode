/*
 * =====================================================================================
 *
 *       Filename:  insert.cpp
 *
 *    Description:  68 ms
 *
 *        Version:  1.0
 *        Created:  10/19/2013 03:53:15 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Wei-Yi Cheng (weiyi-bitw), wc2302@columbia.edu
 *   Organization:  
 *
 * =====================================================================================
 */

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

struct Interval{
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};

class Solution{
  public:
	int getInsertionPoint(vector<Interval> & intervals, Interval & newInterval){
		int k = newInterval.start;
		int n = intervals.size();
		int l = 0;
		int r = n-1;
		while(l <= r){
			int mid = (l+r)/2;
			if(intervals[mid].start == k) return mid;
			if(intervals[mid].start < k)
				l = mid+1;
			else
				r = mid-1;
		}
		return l;
	}
	vector<Interval> insert(vector<Interval> & intervals, Interval newInterval){
		int n = intervals.size();
		vector<Interval> out;
		if(n < 1){ 
			out.push_back(newInterval);
			return out;
		}
		int p = getInsertionPoint(intervals, newInterval);
		cout << p << endl;
		intervals.insert(intervals.begin() + p, newInterval);
		int i = 0;
		while(i < n+1){
			out.push_back(intervals[i++]);
			while(i < n+1 && intervals[i].start <= out.back().end){
				out.back().end = max(intervals[i++].end, out.back().end);
			}
		}
		return out;
	}

};

ostream & operator <<(ostream &os, Interval & it){
	os << "[" << it.start << "," << it.end << "]" ;
	return os;
}


int main()
{
	int points[] = {1, 5};
	vector<Interval> intervals;
	Solution sol;

	for(unsigned int i = 0; i < 1; i++){
		intervals.push_back(Interval(points[2*i], points[2*i+1]));
	}
	Interval ni = Interval(2, 3);
	vector<Interval> out = sol.insert(intervals, ni);
	for(unsigned int i = 0; i < out.size(); i++){
		cout << out[i] << endl;
	}

	return 0;
}
