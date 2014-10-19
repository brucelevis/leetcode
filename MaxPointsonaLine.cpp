/*
���뻷��CFree 5.0
���͵�ַ��http://blog.csdn.net/Snowwolf_Yang
*/

#include <iostream>
#include <vector>
#include <map>

using namespace std;

/*
���ܲ��� 
ע���������� 0���� 1���� 2���� �ص��㣬��б�ʵ� 
 
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
    	if(points.empty())//û��
			return 0;
		
		int points_size = points.size();
		if(points_size < 3)
			return points_size; //�����1����������㷵�ص��� 
		map<double,int> lines;
		
		int i = 0, j = 0, max_num = 0;
		int total_same = 1;//�� i �غϵĵ�ĸ���
		int total_inf = 0;//б�ʲ����ڵĵ���� 		ע���ʼֵ�� ������Ӧ��������� ����б����ͬ�ĵ��� 
		double k = 0;
		for(i = 0;i<points_size -1;i++)//i ���Ϊ points_size -2
		{
			lines.clear();//������Ҫ�ǵ�ÿһ�ζ���Ҫ��ʼ�� 
			 total_same = 1;
			 total_inf = 0;
			for(j = i + 1;j<points_size;j++)//j<=iʱ line[ij]�ǵĵ��Ѿ�ͳ�ƹ� 
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
			//�������ֵ
			map<double,int>::iterator it;
			for(it = lines.begin();it != lines.end();it++)
			{
				if(it->second > total_inf)
					total_inf = it->second;
			}
			//���� total_inf ��¼����ͬб���������ֵ
			if(max_num<total_inf + total_same)
				max_num = total_inf + total_same;
		} 
		return max_num;
	}
};//�����Ҫ�ǵüӷֺ� 

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

