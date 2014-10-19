/*
编译环境CFree 5.0
博客地址：http://blog.csdn.net/Snowwolf_Yang
*/

#include <iostream>
#include <vector>
#include <map>

using namespace std;

/*
功能测试 
注意特殊输入 0个点 1个点 2个点 重叠点，无斜率点 
 
*/
/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
struct Point {
	int x;
	int y;
	Point() : x(0), y(0) {}
	Point(int a, int b) : x(a), y(b) {}
	};
class Solution { 	
public:  
    int maxPoints(vector<Point> &points) { 
    	if(points.empty())//没点
			return 0;
		
		int points_size = points.size();
		if(points_size < 3)
			return points_size; //如果是1个点或两个点返回点数 
		map<double,int> lines;
		
		int i = 0, j = 0, max_num = 0;
		int total_same = 1;//和 i 重合的点的个数
		int total_inf = 0;//斜率不存在的点个数 		注意初始值。 最后点数应该是起点数 加上斜率相同的点数 
		double k = 0;
		for(i = 0;i<points_size -1;i++)//i 最大为 points_size -2
		{
			lines.clear();//这里需要记得每一次都需要初始化 
			 total_same = 1;
			 total_inf = 0;
			for(j = i + 1;j<points_size;j++)//j<=i时 line[ij]是的点已经统计过 
			{
				if(points[i].x == points[j].x && points[i].y == points[j].y)
				{
					total_same++;
					continue;
				}			
				if(points[i].x == points[j].x)
				{
					total_inf++; 
				}
				else
				{
					k = (double)(points[i].y - points[j].y)/(points[i].x - points[j].x);
					++lines[k]; 
				}				
			}
			//更新最大值
			map<double,int>::iterator it;
			for(it = lines.begin();it != lines.end();it++)
			{
				if(it->second > total_inf)
					total_inf = it->second;
			}
			//这里 total_inf 记录了相同斜率数的最大值
			if(max_num<total_inf + total_same)
				max_num = total_inf + total_same;
		} 
		return max_num;
	}
};//类后面要记得加分号 

int main()
{
	int i = 0;
	int tmppoint[5][2] = {{1,2},{1,2},{1,2},{3,2},{1,3}} ;
	vector<Point> points;
	
	for(i=0;i<5;i++)
	{
		points.push_back(Point(tmppoint[i][0],tmppoint[i][1]));
	}
	
	Solution so;
	
	cout<<"maxPoint = "<<so.maxPoints(points)<<endl;
	
	return 0;
} 

