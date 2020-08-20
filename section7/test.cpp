// Copyright (c) 2020 by Chrono
//
// g++ test.cpp -std=c++11 -o a.out;./a.out
// g++ test.cpp -std=c++14 -o a.out;./a.out
// g++ test.cpp -std=c++14 -I../common -o a.out;./a.out

#include <iostream>
#include <list>
using namespace std;

//#include "std.hpp"

struct TreeNode
{
    struct TreeNode* left_children,* right_children;
    int data;
};

static TreeNode* createBinayTree(list<int> &inputList) {
    TreeNode * node = NULL;
    if (inputList.empty()){
        return NULL;
    }

    int data = inputList.front();
    inputList.pop_front();
    node = new TreeNode;
    node->data = data;
    node->left_children = createBinayTree(inputList);
    node->right_children = createBinayTree(inputList);

    return node; 
}

static void preOrderTraveral(TreeNode* node) {
    if (node == NULL) {
        return;
    }
    cout << node->data << endl;
    preOrderTraveral(node->left_children);
    preOrderTraveral(node->right_children);
}
int main()
{
    list<int> inputlist{3,2,9,0,0,10,0,0,8,0,4};
    TreeNode* treeNode = createBinayTree(inputlist);
    cout << "前序遍历：" << endl;
    preOrderTraveral(treeNode);

}
