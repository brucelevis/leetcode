/*
编译环境CFree 5.0
博客地址：http://blog.csdn.net/Snowwolf_Yang
*/
#include <iostream>
#include <vector>
#include <map>
using namespace std;
	
/*
思路做一个从<int,int>map，开始时val都是0
从头开始遍历数据 
key就是已经扫描过的整数，val是被扫描过的整数的index+1（因为输出要求数据从1开始） 
复杂度为O（n） 
*/
#if 1//map法 
class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        map<int,int> mp;
        vector<int> out;
		int i = 0, size = numbers.size();
		for(i = 0;i<size;i++)
		{
			if(mp.count(target-numbers[i]) != 0)		//判断 target-numbers[i]是否已经在map中 
			{
				//printf("***mp[%d] = %d\n",numbers[i],i+1);				
				out.push_back(mp[target-numbers[i]]);	//返回 
				out.push_back(i+1);
				return out;
			}
			else										//不存在就在map中添加项 
			{
				mp[numbers[i]] = i+1;//key = numbers[i],val=index+1
				//printf("mp[%d] = %d\n",numbers[i],i+1);
			}
		}
		return out;	 
    }
};
#elif 0//排序法   -
struct Node
{
    int num, pos;
};
bool cmp(Node a, Node b)
{
    return a.num < b.num;
}
class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> result;
        vector<Node> array;
        for (int i = 0; i < numbers.size(); i++)
        {
            Node temp;
            temp.num = numbers[i];
            temp.pos = i;
            array.push_back(temp);
        }

        sort(array.begin(), array.end(), cmp);
        for (int i = 0, j = array.size() - 1; i != j;)
        {
            int sum = array[i].num + array[j].num;
            if (sum == target)
            {
                if (array[i].pos < array[j].pos)
                {
                    result.push_back(array[i].pos + 1);
                    result.push_back(array[j].pos + 1);
                } else
                {
                    result.push_back(array[j].pos + 1);
                    result.push_back(array[i].pos + 1);
                }
                break;
            } else if (sum < target)
            {
                i++;
            } else if (sum > target)
            {
                j--;
            }
        }
        return result;
    }
};
#elif 1
class Solution {
public:
	struct Node
	{
		int num, idx;
		Node(int _num = 0, int _idx = 0):num(_num),idx(_idx){}
		bool operator < (const Node& orh) const
		{   
			if(num == orh.num)
				return idx < orh.idx;
			else return num < orh.num;
		}
	};
    vector<int> twoSum(vector<int> &numbers, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        //step 0. get an arry record the num and index of every element
        //step 1. sort the array and then 
        //step 2. enumerate every element numbers[i] in the array
        //step 3. using binary search to find if there is an element equal to target-numbers[i]
        //Time complexity Analysis: O(nlgn)
        
        vector<Node> nodes(numbers.size());//step 0
        for(int i = 0; i < numbers.size(); ++i)
            nodes[i] = Node(numbers[i], i);
            
        sort(nodes.begin(), nodes.end());//step 1
        for(int i = 0; i < nodes.size(); ++i)//step 2
        {
            int v2 = target-nodes[i].num;
            //step 3
            int l = min(i+1, (int)nodes.size()-1);
            int r = nodes.size()-1;
            while(l <= r)
            {
                int mid = (l+r)/2;
                if(nodes[mid].num > v2)
                    r = mid-1;
                else if(nodes[mid].num == v2)
                {
                    vector<int> twoSum(2);
                    twoSum[0] = min(nodes[i].idx+1, nodes[mid].idx+1); twoSum[1] = max(nodes[i].idx+1, nodes[mid].idx+1);
                    return twoSum;
                }
                else l = mid+1;
            }
        }
    }
}; 
#elif 1//暴力穷举 ----超时，过不去 
class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) 
    {
        vector<int>output;
        int i,j;
        for(i=0;i<numbers.size()-1;i++)
        {
            for(j=numbers.size()-1;j>i;j--)
            {
                if(numbers[i]+numbers[j]==target)
                {
                    output.push_back(i+1);
                    output.push_back(j+1);
                    return output;
                }
            }
        }
        return output;
    }
};
#endif 

void test0()
{
	int arr[] = {0,1,2,3,4,5,6,7,8,9};
	vector<int> numbers (arr, arr + sizeof(arr) / sizeof(int) );
	Solution so;
	vector<int> out = so.twoSum(numbers, 7);
	if(out.size() >= 2 && arr[out[0]-1] + arr[out[1]-1] == 7 && out[0] < out[1])
	{
		printf("arr[%d] = %d, arr[%d] = %d\n",out[0]-1,arr[out[0]-1],out[1]-1,arr[out[1]-1]);
		printf("------------------------passed\n");
	}
	else
	{
		printf("arr[%d] = %d, arr[%d] = %d\n",out[0]-1,arr[out[0]-1],out[1]-1,arr[out[1]-1]);
		printf("------------------------failed\n");
	}
}
void test1()
{
	int arr[] = {3,2,4};
	vector<int> numbers (arr, arr + sizeof(arr) / sizeof(int) );
	Solution so;
	vector<int> out = so.twoSum(numbers, 6);
	if(out.size() == 2 && arr[out[0]-1] + arr[out[1]-1] == 6 && out[0] < out[1])
	{
		printf("arr[%d] = %d, arr[%d] = %d\n",out[0]-1,arr[out[0]-1],out[1]-1,arr[out[1]-1]);
		printf("------------------------passed\n");
	}
	else
	{
		printf("arr[%d] = %d, arr[%d] = %d\n",out[0]-1,arr[out[0]-1],out[1]-1,arr[out[1]-1]);
		printf("------------------------failed\n");
	}
}
int main()
{
	test0();
	test1();
	
	return 0;
}

 

