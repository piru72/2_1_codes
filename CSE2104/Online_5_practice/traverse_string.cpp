// Task 2. Write a code for recursive pre-order,  inorder & post-order binary tree traversal

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    string data;
    Node *left;
    Node *right;

    Node(string x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

Node *root = NULL;

void create_tree()
{
    Node *book = new Node("book");
    Node *chapter_1 = new Node("chapter_1");
    Node *section_1_1 = new Node("section_1_1");
    Node *section_1_2 = new Node("section_1_2");
    Node *section_1_2_1 = new Node("section_1_2_1");
    Node *section_1_2_2 = new Node("section_1_2_2");
    Node *chapter_2 = new Node("chapter_2");
    Node *section_2_1 = new Node("section_2_1");
    Node *section_2_2 = new Node("section_2_2");
    Node *section_2_2_1 = new Node("section_2_2_1");
    Node *section_2_2_2 = new Node("section_2_2_2");

    book ->left = chapter_1;
    book ->right = chapter_2;
    chapter_1->left = section_1_1;
    chapter_1->right = section_1_2;
    section_1_2 ->left = section_1_2_1;
    section_1_2 ->right = section_1_2_2;

    chapter_2 ->left = section_2_1;
    chapter_2->right = section_2_2;
    section_2_2 -> left = section_2_2_1;
    section_2_2->right = section_2_2_2;     

    root = book;
}

void pre_order(Node *node)
{
    if (node == NULL)
        return;
    cout << node->data << "\n";
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
/*
Pre order:
2 7 1 6 5 10 9 8 3 4
In order:
1 7 5 6 10 2 9 3 8 4
Post order:
1 5 10 6 7 3 4 8 9 2
Level order:
2 7 9 1 6 8 5 10 3 4
*/

/*          2
        /       \
       7         9
      / \         \
     1   6         8
        / \       / \
        5  10     3   4

*/