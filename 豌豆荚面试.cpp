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
 
 #if 0
TreeNode *solve(TreeNode *root,TreeNode *&tail)
{
	if(root == NULL)
	{
		tail = NULL;
		return NULL;
	}
	
	TreeNode *tmpl=NULL, *tmpr=NULL, *tmpt = NULL;
	tmpl = solve(root->left,tmpt);
	tail = tmpt;
	tmpr = solve(root->right,tmpt);
	
	TreeNode *tmp = root;
	if(tmpl)
	{
		tmp->left = tmpl;
		//tmp = tmp->left;//////////////////////////////////////////////////
		tmp = tail;
	} 
	if(tmpr)
	{
		tmp->left = tmpr;
		tail = tmpt;
	}
	root->right = NULL;//////////////////////////////////
	if(tail == NULL) tail = root;
	return root;
}
 
TreeNode *getlist(TreeNode *root)
{
	if(root == NULL)
		return root;
	TreeNode *tail;
	return solve(root,tail);
}

void printlist(TreeNode *root)
{
	printf("\nreout\n");
	while(root)
	{
		printf("%d ",root->val);
		if(root->right) printf("error\n");
		root = root->left;
	}
	printf("\n");
} 
/*功能测试*/
void test0()
{
/*
				1
		2				5
	3		4		6		7
*/ 
	TreeNode node1(1);
	TreeNode node2(2);
	TreeNode node3(5);
	TreeNode node4(3);
	TreeNode node5(4);
	TreeNode node6(6);
	TreeNode node7(7);
	node1.left = &node2;
	node1.right = &node3;
	
	node2.left = &node4;
	node2.right = &node5;
	
	node3.left = &node6;
	node3.right = &node7;
	
	TreeNode *head = getlist(&node1);
	printlist(head);
}


/*功能测试*/
void test1()
{
/*
				1
		2			
	3			
*/ 
	TreeNode node1(1);
	TreeNode node2(2);
	TreeNode node3(3);
	node1.left = &node2;	
	node2.left = &node3;
	
	TreeNode *head = getlist(&node1);
	printlist(head);
}

/*功能测试*/
void test2()
{
/*
				1
		2				5
	3				6		7
								8
*/ 
	TreeNode node1(1);
	TreeNode node2(2);
	TreeNode node3(5);
	TreeNode node4(3);
	TreeNode node5(6);
	TreeNode node6(7);
	TreeNode node7(8);
	node1.left = &node2;
	node1.right = &node3;
	
	node2.left = &node4;
	
	node3.left = &node5;
	node3.right = &node6;
	
	node6.right = &node7;
	
	TreeNode *head = getlist(&node1);
	printlist(head);
}

#elif 1
TreeNode *solve(TreeNode *root,TreeNode *&tail)//头尾要弄好 
{
	if(root == NULL)
	{
		tail = NULL;
		return NULL;
	}
	
	TreeNode *tmpl=NULL, *tmpr=NULL, *tmpt = NULL;
	tmpl = solve(root->left,tmpt);
	tail = tmpt;
	tmpr = solve(root->right,tmpt);
	
	TreeNode *tmp = root;
	if(tmpl)
	{
		root->left = tail;
		tail->right = root;
		tail = root;
		tmp = tmpl;					//头结点的选取 
	} 
	else
	{
		tail = root;/////////////////////////
	} 
	if(tmpr)
	{
		tail->right = tmpr;
		tmpr->left = tail;
		tail = tmpt;
	}
	if(tail == NULL) tail = root;//尾结点 
	return tmp;
}
 
TreeNode *getlist(TreeNode *root)
{
	if(root == NULL)
		return root;
	TreeNode *tail;
	return solve(root,tail);
}

void printlist(TreeNode *root)
{
	printf("\nreout\n");
	while(root->right)
	{
		printf("%d ",root->val);
		root = root->right;
	}
	printf("%d\n",root->val);
	
	while(root)
	{
		printf("%d ",root->val);
		root = root->left;
	}
	printf("\n");
} 
/*功能测试*/
void test0()
{
/*
				1
		2				5
	3		4		6		7
*/ 
	TreeNode node1(1);
	TreeNode node2(2);
	TreeNode node3(5);
	TreeNode node4(3);
	TreeNode node5(4);
	TreeNode node6(6);
	TreeNode node7(7);
	node1.left = &node2;
	node1.right = &node3;
	
	node2.left = &node4;
	node2.right = &node5;
	
	node3.left = &node6;
	node3.right = &node7;
	
	TreeNode *head = getlist(&node1);
	printlist(head);
}


/*功能测试*/
void test1()
{
/*
				1
		2			
	3			
*/ 
	TreeNode node1(1);
	TreeNode node2(2);
	TreeNode node3(3);
	node1.left = &node2;	
	node2.left = &node3;
	
	TreeNode *head = getlist(&node1);
	printlist(head);
}

/*功能测试*/
void test2()
{
/*
				1
		2				5
	3				6		7
								8
*/ 
	TreeNode node1(1);
	TreeNode node2(2);
	TreeNode node3(5);
	TreeNode node4(3);
	TreeNode node5(6);
	TreeNode node6(7);
	TreeNode node7(8);
	node1.left = &node2;
	node1.right = &node3;
	
	node2.left = &node4;
	
	node3.left = &node5;
	node3.right = &node6;
	
	node6.right = &node7;
	
	TreeNode *head = getlist(&node1);
	printlist(head);
}


#endif
int main()
{
	test0();
	test1();
	test2();
	return 0;
}


