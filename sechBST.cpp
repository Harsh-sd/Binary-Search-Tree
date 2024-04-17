#include <iostream>

using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};
node *insertBST(node *&root, int val)
{
    if (root == NULL)
    {
        return new node(val);
    }
    if (val > root->data)
    {
        root->right = insertBST(root->right, val);
    }
    if (val < root->data)
    {
        root->left = insertBST(root->left, val);
    }
    return root;
}
node *searchBST(node *&root, int val)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == val)
    {
        return root;
    }
    if (val > root->data)
    {
        return searchBST(root->right, val);
    }
    if (val < root->data)
    {
        return searchBST(root->left, val);
    }
}

int main()
{
    node *root = NULL;
    root = insertBST(root, 5);
    insertBST(root, 1);
    insertBST(root, 3);
    insertBST(root, 4);
    insertBST(root, 2);
    insertBST(root, 7);
    if (searchBST(root, 9))
    {
        cout << "val exists";
    }
    else
    {
        cout << "val does not exists";
    }
}
// result :5 1 3 4 2 7