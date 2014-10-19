/*
编译环境CFree 5.0
博客地址：http://blog.csdn.net/Snowwolf_Yang
*/

#include <iostream>
#include <vector>
using namespace std;
struct TreeNode {
    int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 
 void printvec(vector<int > A, char *name)
{
	printf("%s:",name);
	for(int i = 0;i<A.size();i++)
	{
		printf("%d,",A[i]);
	}
	printf("\n");
}

void printvec(vector<int > A, int start,int end,char *name)
{
	printf("%s:",name);
	for(int i = start;i<=end;i++)
	{
		printf("%d,",A[i]);
	}
	printf("\n");
}
#if 1 //整理后的代码 
class Solution {
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    	int size = inorder.size();
		if(size == 0)  return NULL;
		return buildTreeCore(preorder,0,size - 1,inorder,0,size - 1);
    }
    //vector必须使用传引用，否则每一次递归都会进行一次复制，内存会超出 
    TreeNode *buildTreeCore(vector<int> &preorder,int prestart,int preend,vector<int> &inorder,int instart,int inend)
    {
    	if(prestart > preend)////////////////////////////////!!!!!!!!!!!!!!!!!!!
   			return NULL;
    	TreeNode *root = new TreeNode(preorder[prestart]);
    	if(prestart == preend) //这里可以加一个报错，如果最后剩一个如果两个vector中val不一样就错了  
			return root;
			
    	int pos = 0;	
		for(int i = instart;i<=inend;i++)
			if(inorder[i] == preorder[prestart])
			{ 
				pos = i;
				break;
			}
    	//开始和结束点需要计算清楚 
    	if(pos>instart)
			root->left =  buildTreeCore(preorder,prestart+1,prestart+(pos-instart),inorder,instart,pos-1);
    	if(inend>pos)
			root->right =  buildTreeCore(preorder,prestart+(pos-instart)+1,preend,inorder,pos+1,inend);
		return root;
	}
};
#elif 0
class Solution {
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    	int size = inorder.size();
		if(size == 0)  return NULL;
		return buildTreeCore(preorder,0,size - 1,inorder,0,size - 1);
    }
    //vector必须使用传引用，否则每一次递归都会进行一次复制，内存会超出 
    TreeNode *buildTreeCore(vector<int> &preorder,int prestart,int preend,vector<int> &inorder,int instart,int inend)
    {
    	//printvec(inorder,instart,inend,"inorder");
    	//printvec(postorder,poststart,postend,"postorder");
    	if(prestart > preend)////////////////////////////////!!!!!!!!!!!!!!!!!!!
    	{
    		//printf("ret NULL");
   			return NULL;
    	}
    	TreeNode *root = new TreeNode(preorder[prestart]);
    	if(prestart == preend) //这里可以加一个报错，如果最后剩一个如果两个vector中val不一样就错了   		
    	{
    		//printf("ret %d\n",root->val);
			return root;
    	}
		   	 
    	int pos = 0;	
		for(int i = instart;i<=inend;i++)
			if(inorder[i] == preorder[prestart])
			{ 
				pos = i;
				break;
			}
		//printf("pos = %d\n",pos);
		//printvec(inorder,instart,pos-1,"inorderL");
    	//printvec(postorder,poststart,poststart+(pos-instart)-1,"postorderL");
    	//开始和结束点需要计算清楚 
    	if(pos>instart)
		root->left =  buildTreeCore(preorder,prestart+1,prestart+(pos-instart),inorder,instart,pos-1);
		//printvec(inorder,pos+1,inend,"inorderR");
    	//printvec(postorder,poststart+(pos-instart),postend-1,"postorderR");
    	if(inend>pos)
		root->right =  buildTreeCore(preorder,prestart+(pos-instart)+1,preend,inorder,pos+1,inend);
		return root;
	}
};
#endif 
class Solution1 {
public:
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> out;
        if(root == NULL)
        	return out;
        
        vector<int> out1 = postorderTraversal(root->left);
        vector<int> out2 = postorderTraversal(root->right);
        
        out.insert(out.begin(),root->val); 					//中 
        out.insert(out.begin(),out2.begin(),out2.end());	//右 
        out.insert(out.begin(),out1.begin(),out1.end());	//左 
        return out;
    }
    vector<int> inorderTraversal(TreeNode *root) {
		vector<int> out;
        if(root == NULL)      	return out;
        	
        vector<int> outleft = inorderTraversal(root->left);	
        vector<int> outright = inorderTraversal(root->right);
		out.insert(out.begin(),outright.begin(),outright.end());		
		out.insert(out.begin(),root->val);	
		out.insert(out.begin(),outleft.begin(),outleft.end());
        return out;
    }
    vector<int> preorderTraversal(TreeNode *root) {//中左右 
        vector<int> out;
        if(root == NULL)
        	return out;
        	
        vector<int> out1 = preorderTraversal(root->left);
        vector<int> out2 = preorderTraversal(root->right);        
        
        out.insert(out.begin(),out2.begin(),out2.end());	//右 
        out.insert(out.begin(),out1.begin(),out1.end());	//左 
        out.insert(out.begin(),root->val); 					//中 
        
        return out;
    }
};

/*功能测试*/
void test0()
{
/*
				1
		2				3
	4		5		6		7
*/ 
	TreeNode node1(1);
	TreeNode node2(2);
	TreeNode node3(3);
	TreeNode node4(4);
	TreeNode node5(5);
	TreeNode node6(6);
	TreeNode node7(7);
	node1.left = &node2;
	node1.right = &node3;
	
	node2.left = &node4;
	node2.right = &node5;
	
	node3.left = &node6;
	node3.right = &node7;
	
	Solution1 so1;
	vector<int> outin = so1.inorderTraversal(&node1);
	vector<int> outpre = so1.preorderTraversal(&node1);
	vector<int> outpost = so1.postorderTraversal(&node1);
	
	printvec(outin,"outin");
	printvec(outpost,"outpost");
	Solution so;
	TreeNode * root = so.buildTree(outpre,outin);
	
	
	vector<int> outpost2 = so1.postorderTraversal(root);
	printvec(outpost,"outpost");
	printvec(outpost2,"outpost2");
	if(outpost == outpost2)
		printf("---------------------passed\n");
	else
		printf("---------------------failed\n");	
}
/*功能测试*/
void test1()
{
	int A1[]={2,1};
	vector<int> ino(A1,A1+sizeof(A1)/sizeof(int));
	int A2[]={2,1};
	vector<int> pos(A2,A2+sizeof(A2)/sizeof(int));
	
	Solution so;
	TreeNode * root = so.buildTree(ino,pos);
	
	Solution1 so1;
	vector<int> outpre2 = so1.preorderTraversal(root);
	printvec(outpre2,"outpre2");
	if(1)
		printf("---------------------passed\n");
	else
		printf("---------------------failed\n");	
}
int main()
{
	test0();
	//test1();
	return 0;
}