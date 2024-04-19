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
node *sortedArray(int arr[], int start, int end)
{
    if (start > end)
    {
        return NULL;
    }
    int mid = (start + end) / 2;
    node *root = new node(arr[mid]);
    root->left = sortedArray(arr, start, mid - 1);
    root->right = sortedArray(arr, mid + 1, end);
    return root;
};
void preorder(node *root)
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
    int arr[] = {10, 20, 30, 40, 50};
    int n = sizeof arr / sizeof arr[0];
    node *root = sortedArray(arr, 0, n - 1);
    preorder(root);
    cout << endl;
    return 0;
}
// result is:30 10 20 40 50
