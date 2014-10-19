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
        //点集合为空  
        if(points.empty()){  
            return 0;  
        }    
        int points_size = points.size();  
        //点集合数目小于3个，返回点集合大小  
        if(points_size <= 2){  
            return points_size;  
        }  
          
        //保存通过某点的斜率-点数目  
        map<double,int> lines;  
        int max_points = 0, total, vertical_num;  
        double k;  
        for(int i = 0; i < points_size-1; ++i){  
            lines.clear();  
            //total保存等于points[i]点的数目  
            total = 1;  
            //斜率不存在时，除了i之外的点数目  
            vertical_num = 0;  
            for(int j = i+1; j < points_size; ++j){  //0......i之前的不用再算，因为 line[ij]（j<=i） 上的点已经统计过 
                //等于points[i]时  
                if(points[i].x == points[j].x &&   
                   points[i].y == points[j].y){  
                    ++total;  
                    continue;  
                }  
                  
                //斜率不存在  
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
              
            //更新最大值  
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
