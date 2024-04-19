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
};
bool checkBST(node *root, int key)
{
    if (root == NULL)
    {
        return false;
    }

    if (key < root->data)
    {
        return checkBST(root->left, key);
    }
    if (key > root->data)
    {
        return checkBST(root->right, key);
    }
    return true;
};

int main()
{
    node *root = NULL;
    root = insertBST(root, 5);
    insertBST(root, 1);
    insertBST(root, 3);
    insertBST(root, 4);
    insertBST(root, 2);
    insertBST(root, 7);

    if (checkBST)
    {
        cout << "tree is binary serch tree";
    }
    else
    {
        cout << "tree is  not  a binary serch tree";
    }
}
// result is :true