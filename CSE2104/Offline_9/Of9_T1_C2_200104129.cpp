// Task 1. Write a code for iterative pre-order, inorder, post-order and level order binary tree traversal

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

struct Tuples
{
    Node *p;
    int i;

    Tuples(Node *n, int x)
    {
        p = n;
        i = x;
    }
    void setI(int x)
    {
        i = x;
    }
    int getPVal()
    {
        return p->data;
    }
    Node *left()
    {
        return p->left;
    }
    Node *right()
    {
        return p->right;
    }
};

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
    stack<Tuples> st;
    Tuples t = Tuples(node, 1);
    st.push(t);

    while (!st.empty())
    {
        t = st.top();
        st.pop();

        if (t.p != NULL)
        {
            switch (t.i)
            {
            case 1:
            {
                t.setI(2);
                st.push(t);
                cout << t.getPVal() << " ";
                break;
            }
            case 2:
            {
                t.setI(3);
                st.push(t);
                Tuples leftT = Tuples(t.left(), 1);
                st.push(leftT);
                break;
            }
            case 3:
            {
                Tuples rightT = Tuples(t.right(), 1);
                st.push(rightT);
                break;
            }
            }
        }
    }
}

void in_order(Node *node)
{
}

void post_order(Node *node)
{
}

void level_order(Node *node)
{
}

int main()
{
    create_tree();

    cout << "Pre order:" << endl;
    pre_order(root);
    cout << endl;

    cout << "In order:" << endl;
    //in_order(root);
    cout << endl;

    cout << "Post order:" << endl;
    //post_order(root);
    cout << endl;

    cout << "Level order:" << endl;
    //level_order(root);
    cout << endl;
}
