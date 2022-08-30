#include<bits/stdc++.h>
using namespace std;

class BinaryTree
{
public:
    int data;
    BinaryTree* LeftChild;
    BinaryTree* RighChild;

    BinaryTree(int val)
    {
        data = val;
        LeftChild = NULL;
        RighChild = NULL;
    }

};

void specePrint(int lavel)
{
    for(int i = 0; i< lavel; i++)
    {
        cout<<"   ";
    }
}

void printTree(BinaryTree* root, int lavel)
{
    if(root == NULL)
    {
        return;
    }
    if(root->LeftChild == NULL && root->RighChild == NULL)
    {
        cout<<root->data<<endl;
        return;
    }
    else
    {
        cout<<endl;
        specePrint(lavel);
        cout<<"Root: "<<root->data<<endl;
    }

    if(root->LeftChild != NULL)
    {
        specePrint(lavel);
        cout<<"Left: ";
        printTree(root->LeftChild, lavel+1);
    }

    if(root->RighChild != NULL)
    {

        specePrint(lavel);
        cout<<"Right: ";
        printTree(root->RighChild, lavel+1);
    }


}


void inOrder(BinaryTree* root, string &chk){

     if(root == NULL)
        return;

    inOrder(root->LeftChild, chk);
    chk += to_string(root->data);
    inOrder(root->RighChild, chk);

}


void preOrder(BinaryTree* root, string &chk){

     if(root == NULL)
        return;

    chk += to_string(root->data);
    preOrder(root->LeftChild, chk);
    preOrder(root->RighChild, chk);

}

void postOrder(BinaryTree* root, string &chk){

     if(root == NULL)
        return;

    postOrder(root->LeftChild, chk);
    postOrder(root->RighChild, chk);
    chk += to_string(root->data);

}




int main()
{

    int n;
    cin>>n;
    BinaryTree* allNodes[n];

    for(int i = 0; i < n; i++)
    {
        allNodes[i] = new BinaryTree(-1);
    }

    for(int i = 0; i < n; i++)
    {
        int val, left, right;
        cin>>val>>left>>right;
        allNodes[i]->data = val;

        if(left != -1)
        {
            allNodes[i]->LeftChild = allNodes[left];
        }
        if(right != -1)
        {
            allNodes[i]->RighChild = allNodes[right];
        }

    }


     printTree(allNodes[0], 0);
     string inordereTraversal = "";
     inOrder(allNodes[0], inordereTraversal);
     cout<<"Inorder Traversal :"<<inordereTraversal<<endl;

     string preordereTraversal = "";
     preOrder(allNodes[0], preordereTraversal);
     cout<<"preorder Traversal :"<<preordereTraversal<<endl;

     string postordereTraversal = "";
     postOrder(allNodes[0], postordereTraversal);
     cout<<"Postorder Traversal :"<<postordereTraversal<<endl;

    return 0;
}
/*
9
0 1 2
1 3 4
2 5 6
3 -1 -1
4 -1 -1
5 7 8
6 -1 -1
7 -1 -1
8 -1 -1

*/

/*

5
1 2 3
2 4 5
3 -1 -1
4 -1 -1
5 -1 -1


*/


// g++ -o BinaryTreeImplementation.exe BinaryTreeImplementation.cpp
