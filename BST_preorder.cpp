#include <bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node *right;
    node *left;
    node(int val)
    {
        data = val;
        right = NULL;
        left = NULL;
    }
};
node *construct(int pre[], int *preidx, int key, int min, int max, int n)
{
    if (*preidx >= n)
        return NULL;
    node *root = NULL;
    if (key < max && key > min)
    {
        root = new node(key);
        *preidx = *preidx + 1;
    }
    if (*preidx < n)
        root->left = construct(pre, preidx, pre[*preidx], min, key, n);
    if (*preidx < n)
        root->right = construct(pre, preidx, pre[*preidx], key, max, n);
    return root;
}
void preorder(node *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    preorder(root->left);

    preorder(root->right);
}
int main()
{
    node *root = NULL;
    int pre[] = {7, 5, 4, 6, 8, 9};
    // inorder traversal of this tree will give us a dorted array
    int p = 0;
    int n = 6;
    root = construct(pre, &p, pre[0], INT_MIN, INT_MAX, n);
    preorder(root);
    return 0;
}