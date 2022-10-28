#pragma once
#include "btree.h"
struct Node
{
    int data;
    int posinfile;
    Node* left;
    Node* right;
};

typedef Node* Tree;

Node* CreateNode(Film init)
{
    Node* p = new Node;
    fstream file("input1.dat", ios::out | ios::app);
    file.write((char*)&init, sizeof(init));
    p->posinfile = (int)file.tellg() - (int)sizeof(init);
    p->data = init.rate;
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

void AddNode(Tree& root, Node* node)
{
    if (root)
    {
        if (root->data == node->data)
            return;
        if (node->data < root->data)
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
        if (root->data == x)
            return root;
        if (x < root->data)
            return FindNode(root->left, x);
        return FindNode(root->right, x);
    }
    return NULL;
}

void PrintTree(Tree root)// print tree using LNR
{
    if (root)
    {
        PrintTree(root->left);
        cout << root->data << ' ';
        PrintTree(root->right);
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
        if (x > root->data)
            DeleteNode(root->right, x);
        else if (x < root->data)
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
//#pragma once
//#include "btree.h"
//struct Node
//{
//    Film data;
//    Node* left;
//    Node* right;
//};
//
//typedef Node* Tree;
//
//Node* CreateNode(Film init)
//{
//    Node* p = new Node;
//    p->data = init;
//    p->left = NULL;
//    p->right = NULL;
//    return p;
//}
//
//void CreateTree(Tree& root)
//{
//    root = NULL;
//}
//
//void DestroyTree(Tree& root)
//{
//    if (root)
//    {
//        DestroyTree(root->left);
//        DestroyTree(root->right);
//        delete root;
//    }
//}
//
//void AddNode(Tree& root, Node* node)
//{
//    if (root)
//    {
//        if (root->data.rate == node->data.rate)
//            return;
//        if (node->data.rate < root->data.rate)
//            AddNode(root->left, node);
//        else
//            AddNode(root->right, node);
//    }
//    else
//    {
//        root = node;
//    }
//}
//
//Node* FindNode(Tree root, int x)
//{
//    if (root)
//    {
//        if (root->data.rate == x)
//            return root;
//        if (x < root->data.rate)
//            return FindNode(root->left, x);
//        return FindNode(root->right, x);
//    }
//    return NULL;
//}
//
//void PrintTree(Tree root)// print tree using LNR
//{
//    if (root)
//    {
//        PrintTree(root->left);
//        cout << root->data.rate << ' ';
//        PrintTree(root->right);
//    }
//}
//
//void NLR(Tree root)
//{
//    if (root)
//    {
//        // Xử lý nút gốc (root)
//        NLR(root->left);
//        NLR(root->right);
//    }
//}
//
//void LNR(Tree root)
//{
//    if (root)
//    {
//        LNR(root->left);
//        // Xử lý nút gốc (root)
//        LNR(root->right);
//    }
//}
//
//void LRN(Tree root)
//{
//    if (root)
//    {
//        LRN(root->left);
//        LRN(root->right);
//        // Xử lý nút gốc (root)
//    }
//}
//
//void FindAndReplace1(Tree& p, Tree& tree)
//{
//    if (tree->left)
//        FindAndReplace1(p, tree->left);
//    else
//    {
//        p->data = tree->data;
//        p = tree;
//        tree = tree->right;
//    }
//}
//
//void FindAndReplace2(Tree& p, Tree& tree)
//{
//    if (tree->right)
//        FindAndReplace2(p, tree->right);
//    else
//    {
//        p->data = tree->data;
//        p = tree;
//        tree = tree->left;
//    }
//}
//
//void DeleteNode(Tree& root, int x)
//{
//    if (root)
//    {
//        if (x > root->data.rate)
//            DeleteNode(root->right, x);
//        else if (x < root->data.rate)
//            DeleteNode(root->left, x);
//        else
//        {
//            Node* p = root;
//            if (!root->left)
//                root = root->right;
//            else if (!root->right)
//                root = root->left;
//            else
//                FindAndReplace1(p, root->right);
//            // FindAndReplace2(p, root->left);
//            delete p;
//        }
//    }
//    else
//    {
//        cout << "Not found!\n";
//    }
//}







