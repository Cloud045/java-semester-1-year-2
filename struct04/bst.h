#pragma once
#include <iostream>
using namespace std;
struct Data
{
    string name;
    int number;
};
struct Node
{
    Data data;
    Node* left;
    Node* right;
};

typedef Node* Tree;

Node* CreateNode(Data init)
{
    Node* p = new Node;
    p->data = init;
    p->left = NULL;
    p->right = NULL;
    return p;
}

void CreateTree(Tree& root)
{
    root = NULL;
}

void DestroyTree(Tree& root)
{
    if (root)
    {
        DestroyTree(root->left);
        DestroyTree(root->right);
        delete root;
    }
}
void CoppyTree(Tree& oldroot,Tree& newroot)
{
    if (oldroot)
    {
        newroot=oldroot;
        CoppyTree(oldroot->left,newroot->left);
        CoppyTree(oldroot->right,newroot->right);
    }
}

void AddNode(Tree& root, Node* node)
{
    if (root)
    {
        if (root->data.number == node->data.number)
            return;
        if (node->data.number < root->data.number)
            AddNode(root->left, node);
        else
            AddNode(root->right, node);
    }
    else
    {
        root = node;
    }
}

Node* FindNode(Tree root, int x)
{
    if (root)
    {
        if (root->data.number == x)
            return root;
        if (x < root->data.number)
            return FindNode(root->left, x);
        return FindNode(root->right, x);
    }
    return NULL;
}
int FindNodeHadElementMoreThan3(Tree root,int ok)
{
    if (root)
    {
        if (root->data.number >= 3)
            return (1+FindNodeHadElementMoreThan3(root->right,0)+ FindNodeHadElementMoreThan3(root->left,1));
        return FindNodeHadElementMoreThan3(root->left, 0);
    }
    return 0;
}

void PrintTree(Tree root,int t,string direct)// print tree using LNR
{
    if (root)
    {
        for (int i = 1; i <= t; ++i) cout << "\t";
        cout<<"<"<<direct<<">:" << root->data.name << "," << root->data.number << "\n";
        PrintTree(root->left,t+1,"left");
        PrintTree(root->right,t+1,"right");
    }
}

void NLR(Tree root)
{
    if (root)
    {
        // Xử lý nút gốc (root)
        NLR(root->left);
        NLR(root->right);
    }
}

void LNR(Tree root)
{
    if (root)
    {
        LNR(root->left);
        // Xử lý nút gốc (root)
        LNR(root->right);
    }
}

void LRN(Tree root)
{
    if (root)
    {
        LRN(root->left);
        LRN(root->right);
        // Xử lý nút gốc (root)
    }
}

void FindAndReplace1(Tree& p, Tree& tree)
{
    if (tree->left)
        FindAndReplace1(p, tree->left);
    else
    {
        p->data = tree->data;
        p = tree;
        tree = tree->right;
    }
}

void FindAndReplace2(Tree& p, Tree& tree)
{
    if (tree->right)
        FindAndReplace2(p, tree->right);
    else
    {
        p->data = tree->data;
        p = tree;
        tree = tree->left;
    }
}

void DeleteNode(Tree& root, int x)
{
    if (root)
    {
        if (x > root->data.number)
            DeleteNode(root->right, x);
        else if (x < root->data.number)
            DeleteNode(root->left, x);
        else
        {
            Node* p = root;
            if (!root->left)
                root = root->right;
            else if (!root->right)
                root = root->left;
            else
                FindAndReplace1(p, root->right);
            // FindAndReplace2(p, root->left);
            delete p;
        }
    }
    else
    {
        cout << "Not found!\n";
    }
}