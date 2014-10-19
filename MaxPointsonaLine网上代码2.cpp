#include <iostream>
#include <vector>
#include <map>

using namespace std;

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
        //�㼯��Ϊ��  
        if(points.empty()){  
            return 0;  
        }    
        int points_size = points.size();  
        //�㼯����ĿС��3�������ص㼯�ϴ�С  
        if(points_size <= 2){  
            return points_size;  
        }  
          
        //����ͨ��ĳ���б��-����Ŀ  
        map<double,int> lines;  
        int max_points = 0, total, vertical_num;  
        double k;  
        for(int i = 0; i < points_size-1; ++i){  
            lines.clear();  
            //total�������points[i]�����Ŀ  
            total = 1;  
            //б�ʲ�����ʱ������i֮��ĵ���Ŀ  
            vertical_num = 0;  
            for(int j = i+1; j < points_size; ++j){  //0......i֮ǰ�Ĳ������㣬��Ϊ line[ij]��j<=i�� �ϵĵ��Ѿ�ͳ�ƹ� 
                //����points[i]ʱ  
                if(points[i].x == points[j].x &&   
                   points[i].y == points[j].y){  
                    ++total;  
                    continue;  
                }  
                  
                //б�ʲ�����  
                if(points[i].x == points[j].x){  
                    ++vertical_num;  
                }else{  
                    k = (double)(points[i].y - points[j].y)/(points[i].x - points[j].x);  
                    if(lines.find(k) != lines.end()){  
                        ++lines[k];  
                    }else{  
                        lines[k] = 1;  
                    }  
                }  
            }  
              
            //�������ֵ  
            map<double,int>::iterator iter = lines.begin();  
            for(;iter != lines.end(); ++iter){  
                if(iter->second > vertical_num){  
                    vertical_num = iter->second;  
                }  
            }  
            vertical_num += total;  
            if(vertical_num > max_points){  
                max_points = vertical_num;  
            }  
        }  
          
        return max_points;  
    }  
};  

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
