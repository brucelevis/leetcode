/*
编译环境CFree 5.0
博客地址：http://blog.csdn.net/Snowwolf_Yang
*/

#include <iostream>
#include <vector>
using namespace std;


struct Interval {
     int start;
     int end;
     Interval() : start(0), end(0) {}
     Interval(int s, int e) : start(s), end(e) {}
     
 };


 /*
 首先按start 排序 
 设置一个start，end
 如果 end <  intervals[i].start 就可以把 (start,end),添加进去
 如果 end <  intervals[i].end 就把end更新为  intervals[i].end，也就是把 intervals[i]合并入(start,end)
 如果 end >= intervals[i].end 说明  intervals[i] 已经在  (start,end) 不用处理 
 
 */
	 bool comp(const Interval &a, const Interval &b)
	{  
	    if(a.start==b.start)return a.end<b.end;
	    return a.start<b.start;
	}
class Solution {
public:

	
    vector<Interval> merge(vector<Interval> &intervals) {
        vector<Interval> ret;
        int size = intervals.size();
        
        sort(intervals.begin(),intervals.end(),comp);
        
        if(size < 1) return ret;
        int start = intervals[0].start;
        int end = intervals[0].end;
        for(int i = 1;i<size;i++)
        {
        	if(end < intervals[i].start)
        	{
        		ret.push_back(Interval(start,end));
        		start = intervals[i].start;
        		end = intervals[i].end;
			}
			if(end < intervals[i].end)
				end = intervals[i].end;
		}
		ret.push_back(Interval(start,end));
		return ret;
    }
};
bool equal(const vector<Interval> &x,const vector<Interval> &y)
{
	if(x.size() != y.size())	return false;
	
	for(int i = 0;i<x.size();i++)
	{
		if(x[i].start != y[i].start || x[i].end != y[i].end)
			return false;
	}
	return true;
}
void test0()
{
	//[1,2],[3,5],[6,7],[8,10],[12,16]
	vector<Interval> intervals;
	intervals.push_back(Interval(1,2)); 
	intervals.push_back(Interval(3,5)); 
	intervals.push_back(Interval(3,7)); 
	intervals.push_back(Interval(8,10)); 
	intervals.push_back(Interval(9,16)); 	
	
	Solution so;
	vector<Interval> out = so.merge(intervals);
	
	vector<Interval> expect;
	expect.push_back(Interval(1,2)); 
	expect.push_back(Interval(3,7));
	expect.push_back(Interval(8,16)); 
	
	if(!equal(expect,out))
		printf("------------------------failed\n");
	else
		printf("------------------------passed\n");
}/**/

int main()
{
	test0();
	return 0;
}