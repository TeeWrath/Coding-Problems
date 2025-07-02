#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int data)
    {
        val = data;
        left = right = nullptr;
    }
};

TreeNode *insertIntoBST(TreeNode *root, int val)
{
    if (!root)
        return new TreeNode(val);
    TreeNode *cur = root;
    while (true)
    {
        if (cur->val <= val)
        {
            if (cur->right != nullptr)
                cur = cur->right;
            else
            {
                cur->right = new TreeNode(val);
                break;
            }
        }
        else
        {
            if (cur->left != nullptr)
                cur = cur->left;
            else
            {
                cur->left = new TreeNode(val);
                break;
            }
        }
    }
    return root;
}

TreeNode *createBST()
{
    int rt;
    cout << "Enter root value: ";
    cin >> rt;
    TreeNode *root = new TreeNode(rt);
    while (true)
    {
        cout << "Enter whole numeric value: ";
        int value;
        cin >> value;
        if (value == -1)
            break;
        root = insertIntoBST(root, value);
    }

    return root;
}

void printBST(TreeNode *root)
{
    if (!root)
        return;
    cout << root->val << " ";
    printBST(root->left);
    printBST(root->right);
}

class BSTIterator
{
public:
    TreeNode *pointer, *rt;
    BSTIterator(TreeNode *root)
    {
        if (!root)
            return;
        TreeNode* dummy;
        rt = dummy = root;
        while (dummy->left != nullptr)
        {
            dummy = dummy->left;
        }
        pointer = new TreeNode(dummy->val-1);
        pointer->right = dummy;
    }
    TreeNode *inordersuccesor(TreeNode *root, TreeNode *p)
    {
        TreeNode *successor = NULL;

        while (root)
        {
            if (p->val >= root->val)
                root = root->right;
            else
            {
                successor = root;
                root = root->left;
            }
        }

        return successor;
    }

    int next()
    {
        pointer = inordersuccesor(rt, pointer);
        return pointer != NULL ? pointer->val : -1;
    }

    bool hasNext()
    {
        return inordersuccesor(rt, pointer) != NULL;
    }
};

int main()
{
    TreeNode *root = createBST();
    BSTIterator bSTIterator = BSTIterator(root);
    while(bSTIterator.hasNext() != false){
        cout << bSTIterator.next() << endl;
        string s = bSTIterator.hasNext() == 1?"true" : "false";
        cout << s << endl;
    }
    return 0;
}