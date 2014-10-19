 #include <iostream>
 #include <vector>
 using namespace std;
 
 
 class Solution {
public:
    vector<vector<int> > generate(int numRows) {
    	vector<vector<int> > ret;
        for(int i = 0;i<numRows;i++)
        {
        	vector<int> tmp;
        	if(i == 0)
        		tmp.push_back(1);
       		else if(i == 1)
       			tmp.push_back(1),tmp.push_back(1);
       		else
       		{
       			tmp.push_back(1);
       			for(int j = 0;j<i-1;j++)
       			{
       				tmp.push_back(ret[i-1][j]+ret[i-1][j+1]);
				}
				tmp.push_back(1);
		   	}
       		ret.push_back(tmp);
		}
		return ret;
    }
};

void printv(vector<vector<int> > num)
{
	for(int i = 0;i<num.size();i++)
	{
		for(int j = 0;j<num[i].size();j++)
		{
			printf("%d,",num[i][j]);
		}
		printf("\n");
	}
	printf("\n");	
}
 int main()
 {
 	Solution so;
 	printv(so.generate(5));
 	return 0;
 }
 
 