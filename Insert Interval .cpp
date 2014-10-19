/*
编译环境CFree 5.0
博客地址：http://blog.csdn.net/Snowwolf_Yang
*/

#include <iostream>
#include <vector>
using namespace std;

/**
 * Definition for an interval. */

	
struct Interval {
     int start;
     int end;
     Interval() : start(0), end(0) {}
     Interval(int s, int e) : start(s), end(e) {}
     
 };

class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        vector<Interval> ret;
		int size = intervals.size();
        //TODO size 1
        
        int i = 0;
        
		int start = 0, end = 0;
        for(i = 0;i<size;i++)
        {
        	if(intervals[i].start> newInterval.end)
        		break;
		}
		end = i;
		
		for(;i>=0;i--)
        {
        	if(i<size && intervals[i].end < newInterval.start)
        		break;
		}
		start = i;
		
		for(i = 0;i<=start;i++)//start之前的肯定是和新插入的 没有交集的 
		{
			ret.push_back(intervals[i]);
		}
		
		if(start + 1 < size && newInterval.start > intervals[start+1].start)
			newInterval.start = intervals[start+1].start;
			
		if(end>0 && newInterval.end < intervals[end-1].end)
			newInterval.end = intervals[end-1].end;
		
		ret.push_back(newInterval);
		
		for(i = end;i<size;i++)//end之后的肯定是和新插入的 没有交集的 
		{
			ret.push_back(intervals[i]);
		}
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
	intervals.push_back(Interval(4,7)); 
	intervals.push_back(Interval(8,10)); 
	intervals.push_back(Interval(12,16)); 	
	
	Solution so;
	vector<Interval> out = so.insert(intervals,Interval(4,9));
	
	vector<Interval> expect;
	expect.push_back(Interval(1,2)); 
	expect.push_back(Interval(3,10));
	expect.push_back(Interval(12,16)); 
	
	if(!equal(expect,out))
		printf("------------------------failed\n");
	else
		printf("------------------------passed\n");
}/**/

void test1()
{
	//[1,2],[3,5],[6,7],[8,10],[12,16]
	vector<Interval> intervals;
	intervals.push_back(Interval(1,2));
	intervals.push_back(Interval(6,7)); 	
	
	Solution so;
	vector<Interval> out = so.insert(intervals,Interval(3,4));
	
	vector<Interval> expect;
	expect.push_back(Interval(1,2)); 
	expect.push_back(Interval(3,4));
	expect.push_back(Interval(6,7)); 
	
	if(!equal(expect,out))
		printf("------------------------failed\n");
	else
		printf("------------------------passed\n");
}

void test2()
{
	//[1,2],[3,5],[6,7],[8,10],[12,16]
	vector<Interval> intervals;
	intervals.push_back(Interval(1,2)); 
	intervals.push_back(Interval(3,7)); 
	intervals.push_back(Interval(8,10)); 
	intervals.push_back(Interval(12,16)); 	
	
	Solution so;
	vector<Interval> out = so.insert(intervals,Interval(4,6));
	
	vector<Interval> expect;
	expect.push_back(Interval(1,2)); 
	expect.push_back(Interval(3,7));
	expect.push_back(Interval(8,10)); 
	expect.push_back(Interval(12,16)); 
	
	if(!equal(expect,out))
		printf("------------------------failed\n");
	else
		printf("------------------------passed\n");
}



void test3()
{
	//[1,2],[3,5],[6,7],[8,10],[12,16]
	vector<Interval> intervals;
	intervals.push_back(Interval(1,2)); 
	intervals.push_back(Interval(4,7)); 
	intervals.push_back(Interval(12,16)); 	
	
	Solution so;
	vector<Interval> out = so.insert(intervals,Interval(3,8));
	
	vector<Interval> expect;
	expect.push_back(Interval(1,2)); 
	expect.push_back(Interval(3,8));
	expect.push_back(Interval(12,16)); 
	
	if(!equal(expect,out))
		printf("------------------------failed\n");
	else
		printf("------------------------passed\n");
}
void test4()
{
	//[1,2],[3,5],[6,7],[8,10],[12,16]
	vector<Interval> intervals;
	intervals.push_back(Interval(4,7)); 
	intervals.push_back(Interval(12,16)); 	
	
	Solution so;
	vector<Interval> out = so.insert(intervals,Interval(1,2));
	
	vector<Interval> expect;
	expect.push_back(Interval(1,2)); 
	expect.push_back(Interval(4,7));
	expect.push_back(Interval(12,16)); 
	
	if(!equal(expect,out))
		printf("------------------------failed\n");
	else
		printf("------------------------passed\n");
}

/*
void test0()
{
	//[1,2],[3,5],[6,7],[8,10],[12,16]
	vector<Interval> intervals;
	intervals.push_back(Interval(1,2)); 
	intervals.push_back(Interval(3,5)); 
	intervals.push_back(Interval(4,7)); 
	intervals.push_back(Interval(8,10)); 
	intervals.push_back(Interval(12,16)); 	
	
	Solution so;
	vector<Interval> out = so.insert(intervals,Interval(4,9));
	
	vector<Interval> expect;
	expect.push_back(Interval(1,2)); 
	expect.push_back(Interval(3,10));
	expect.push_back(Interval(12,16)); 
	
	if(out != expect)
		printf("------------------------failed\n");
	else
		printf("------------------------passed\n");
}
void test0()
{
	//[1,2],[3,5],[6,7],[8,10],[12,16]
	vector<Interval> intervals;
	intervals.push_back(Interval(1,2)); 
	intervals.push_back(Interval(3,5)); 
	intervals.push_back(Interval(4,7)); 
	intervals.push_back(Interval(8,10)); 
	intervals.push_back(Interval(12,16)); 	
	
	Solution so;
	vector<Interval> out = so.insert(intervals,Interval(4,9));
	
	vector<Interval> expect;
	expect.push_back(Interval(1,2)); 
	expect.push_back(Interval(3,10));
	expect.push_back(Interval(12,16)); 
	
	if(out != expect)
		printf("------------------------failed\n");
	else
		printf("------------------------passed\n");
}
*/

int main()
{
	test0();
	test1();
	test2();
	test3();
	test4();
	return 0;
}