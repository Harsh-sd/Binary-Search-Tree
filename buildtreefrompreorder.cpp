#include <iostream >
#include <climits >
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
node *consttree(int preorder[], int *preorderidx, int min, int max, int key, int n)
{
    if (*preorderidx >= n)
    {
        return NULL;
    }
    node *root = NULL;
    if (key > min && key < max)
    {
        root = new node(key);
        *preorderidx = *preorderidx + 1;

        if (*preorderidx < n)
        {
            root->left = consttree(preorder, preorderidx, min, key, preorder[*preorderidx], n);
        };
        if (*preorderidx < n)
        {
            root->right = consttree(preorder, preorderidx, key, max, preorder[*preorderidx], n);
        };
        return root;
    };
    return NULL;
};
void preorderprint(node *&root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preorderprint(root->left);
    preorderprint(root->right);
}
int main()
{
    int preorder[] = {10, 2, 1, 3, 11};
    int *preorderidx = new int(0); // Initialize with the address of an integer variable
    int n = 5;
    node *root = consttree(preorder, preorderidx, INT_MIN, INT_MAX, preorder[0], n);
    preorderprint(root);
    //  delete preorderidx; // Deallocate memory
    return 0;
}
// result :10 2 1 3 11