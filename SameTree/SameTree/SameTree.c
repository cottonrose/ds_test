#include <stdio.h>

struct TreeNode
{
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
};
//�ж��������Ƿ�����ͬ��
bool isSameTree(struct TreeNode* p, struct TreeNode* q)
{
	if(p == NULL && q == NULL)
	{
		return true;
	}
	if(p == NULL || q == NULL)
	{
		return false;
	}
	return p->val == q->val
		&& isSameTree(p->left,q->left)
		&& isSameTree(p->right,q->right);
}
//�Գƶ�����
bool isMirror(struct TreeNode* p,struct TreeNode* q)
{
	if(p==NULL && q==NULL)
	{
		return true;
	}
	if(p==NULL || q==NULL)
	{
		return false;
	}
	return p->val == q->val
		&&isMirror(p->left,q->right)
		&&isMirror(p->right,q->left);
}
bool isSymmetric(struct TreeNode* root)
{
	return isMirror(root->left,root->right);
}