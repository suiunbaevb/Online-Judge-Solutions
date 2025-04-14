#include <bits/stdc++.h>

using namespace std;

class node;

struct node {
    int value;
    node *left;
    node *right;
};

// Return the sum of all values in the tree, including the root
int sumTheTreeValues(node *root) {
    if (!root) {
        return 0;
    }
    return root->value + sumTheTreeValues(root->left) + sumTheTreeValues(root->right);
}


int main() {
    node easyNode = {10, new node{1, nullptr, nullptr}, new node{2, nullptr, nullptr}};
    int a = sumTheTreeValues(&easyNode);
    cout << a;
    return 0;
}

//Describe(SimpleTests)
//        {
//                It(Easy)
//                {
//                    node easyNode = {10, new node {1, nullptr, nullptr}, new node {2, nullptr, nullptr}};
//                    Assert::That(sumTheTreeValues(&easyNode), Equals(13));
//                }
//
//                It(Unbalanced)
//                {
//                    node unbalancedNode = {11, new node {0, nullptr, nullptr}, new node {0, nullptr, new node {1, nullptr, nullptr}}};
//                    Assert::That(sumTheTreeValues(&unbalancedNode), Equals(12));
//                }
//        };