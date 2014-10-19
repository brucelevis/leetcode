/*
���뻷��CFree 5.0
���͵�ַ��http://blog.csdn.net/Snowwolf_Yang
*/
#include <iostream>
#include <vector>
#include <map>
using namespace std;
	
/*
˼·��һ����<int,int>map����ʼʱval����0
��ͷ��ʼ�������� 
key�����Ѿ�ɨ�����������val�Ǳ�ɨ�����������index+1����Ϊ���Ҫ�����ݴ�1��ʼ�� 
���Ӷ�ΪO��n�� 
*/
#if 1//map�� 
class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        map<int,int> mp;
        vector<int> out;
		int i = 0, size = numbers.size();
		for(i = 0;i<size;i++)
		{
			if(mp.count(target-numbers[i]) != 0)		//�ж� target-numbers[i]�Ƿ��Ѿ���map�� 
			{
				//printf("***mp[%d] = %d\n",numbers[i],i+1);				
				out.push_back(mp[target-numbers[i]]);	//���� 
				out.push_back(i+1);
				return out;
			}
			else										//�����ھ���map������� 
			{
				mp[numbers[i]] = i+1;//key = numbers[i],val=index+1
				//printf("mp[%d] = %d\n",numbers[i],i+1);
			}
		}
		return out;	 
    }
};
#elif 0//����   -
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
#elif 1//������� ----��ʱ������ȥ 
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

 

