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
    else if (val < root->data)
    {
        root->left = insertBST(root->left, val);
    }
    return root;
}

node *searchBST(node *&root, int val)
{
    if (root == NULL || root->data == val)
    {
        return root;
    }
    if (val > root->data)
    {
        return searchBST(root->right, val);
    }
    return searchBST(root->left, val);
}

node *inordersuccess(node *root)
{
    node *curr = root;
    while (curr && curr->left != NULL)
    {
        curr = curr->left;
    }
    return curr;
}

node *deleteBST(node *root, int val)
{
    if (root == NULL)
    {
        return root;
    }

    if (val < root->data)
    {
        root->left = deleteBST(root->left, val);
    }
    else if (val > root->data)
    {
        root->right = deleteBST(root->right, val);
    }
    else
    {
        if (root->left == NULL)
        {
            node *temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL)
        {
            node *temp = root->left;
            delete root;
            return temp;
        }
        node *temp = inordersuccess(root->right);
        root->data = temp->data;
        root->right = deleteBST(root->right, temp->data);
    }
    return root;
}

void preorder(node *&root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
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
        cout << "val does not exist";
    }
    cout << endl;

    root = deleteBST(root, 5);
    preorder(root);
}
