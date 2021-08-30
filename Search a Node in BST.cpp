#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    node *left;
    Node *right;
    Node(int x)
    {
        data=x;
        left=NULL;
        right=NULL;
    }
};
bool search(Node *root,int x);
Node *insert(Node *tree,int val)
{
    if(tree==NULL)
        return new Node(val);
    if(val<tree->data)
        tree->left=insert(tree->left,val);
    else if(val>tree->data)
        tree->right=insert(tree->right,val);
    return tree;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        Node *root=NULL;
        int n;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            int k;
            cin>>k;
            root=insert(root,k);
        }
        int x;
        cin>>x;
        cout<<search(root,x);
        cout<<endl;
    }
}
bool search(Node *root,int x)
{
    if(root==NULL)
        return false;
    if(root->data==x)
        return true;
    else if(root->data>x)
        insert(root->left,x);
    else if(root->data<x)
        insert(root->right,x);
    else return false;
}

