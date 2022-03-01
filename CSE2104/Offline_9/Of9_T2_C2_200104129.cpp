// Task 2. Write a code for recursive pre-order,  inorder & post-order binary tree traversal

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

Node *root = NULL;

void create_tree()
{
    Node *two = new Node(2);
    Node *seven = new Node(7);
    Node *nine = new Node(9);
    Node *one = new Node(1);
    Node *six = new Node(6);
    Node *five = new Node(5);
    Node *ten = new Node(10);
    Node *eight = new Node(8);
    Node *three = new Node(3);
    Node *four = new Node(4);

    two->left = seven;
    two->right = nine;
    seven->left = one;
    seven->right = six;
    six->left = five;
    six->right = ten;
    nine->right = eight;
    eight->left = three;
    eight->right = four;

    root = two;
}

void pre_order(Node *node)
{
    if (node == NULL)
        return;
    cout << node->data << " ";
    pre_order(node->left);
    pre_order(node->right);
}

void in_order(Node *node)
{
    if (node == NULL)
        return;
    in_order(node->left);
    cout << node->data << " ";
    in_order(node->right);
}

void post_order(Node *node)
{
    if (node == NULL)
        return;
    post_order(node->left);
    post_order(node->right);
    cout << node->data << " ";
}

int main()
{
    create_tree();

    cout << "Pre order:" << endl;
    pre_order(root);
    cout << endl;

    cout << "In order:" << endl;
    in_order(root);
    cout << endl;

    cout << "Post order:" << endl;
    post_order(root);
    cout << endl;

    return 0;
}
