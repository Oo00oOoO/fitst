#include <iostream>
using namespace std;
enum Color
{
    RED,
    BLACK
};

template <typename T>
struct Node
{
    T key;
    Node<T> *parent;
    Node<T> *left;
    Node<T> *right;
    Color color;

    Node(T k) : key(k), parent(nullptr), left(nullptr), right(nullptr), color(RED) {}
};

template <typename T>
class RedBlackTree
{
private:
    Node<T> *root;

    void leftRotate(Node<T> *x)
    {
        Node<T> *y = x->right;
        x->right = y->left;
        if (y->left != nullptr)
        {
            y->left->parent = x;
        }
        y->parent = x->parent;
        if (x->parent == nullptr)
        {
            root = y;
        }
        else if (x == x->parent->left)
        {
            x->parent->left = y;
        }
        else
        {
            x->parent->right = y;
        }
        y->left = x;
        x->parent = y;
    }
    void rightRotate(Node<T> *x)
    {
        Node<T> *y = x->left;
        x->left = y->right;
        if (y->right != nullptr)
        {
            y->right->parent = x;
        }
        y->parent = x->parent;
        if (x->parent == nullptr)
        {
            root = y;
        }
        else if (x->parent->left == x)
        {
            x->parent->left = y;
        }
        else
        {
            x->parent->right == y;
        }
        y->right = x;
        x->parent = y;
    }

    void insertFixup(Node<T> *z)
    {
        while (z->parent != nullptr && z->parent->color == RED)
        {
            if (z->parent == z->parent->parent->left)
            {
                Node<T> *y = z->parent->parent->right;
                if (y != nullptr && y->color == RED)
                {
                    z->parent->color = BLACK;
                    y->color = BLACK;
                    z->parent->parent->color = RED;
                    z = z->parent->parent;
                }
                else
                {
                    if (z == z->parent->right)
                    {
                        z = z->parent;
                        leftRotate(z);
                    }
                    z->parent->color = BLACK;
                    z->parent->parent->color = RED;
                    rightRotate(z->parent->parent);
                }
            }
            else
            {
                Node<T> *y = z->parent->parent->left;
                if (y != nullptr && y->color == RED)
                {
                    z->parent->color = BLACK;
                    y->color = BLACK;
                    z->parent->parent->color = RED;
                    z = z->parent->parent;
                }
                else
                {
                    if (z == z->parent->left)
                    {
                        z = z->parent;
                        rightRotate(z);
                    }
                    z->parent->color = BLACK;
                    z->parent->parent->color = RED;
                    leftRotate(z->parent->parent);
                }
            }
        }
        root->color = BLACK;
    }

    void insertNode(Node<T> *z)
    {
        Node<T> *y = nullptr;
        Node<T> *x = root;

        while (x != nullptr)
        {
            y = x;
            if (z->key < x->key)
            {
                x = x->left;
            }
            else
            {
                x = x->right;
            }
        }

        z->parent = y;
        if (y == nullptr)
        {
            root = z;
        }
        else if (z->key < y->key)
        {
            y->left = z;
        }
        else
        {
            y->right = z;
        }
        insertFixup(z);
    }

public:
    RedBlackTree() : root(nullptr) {}
    void insert(T key)
    {
        Node<T> *z = new Node<T>(key);
        insertNode(z);
    }

    void inorderTraversal(Node<T> *x)
    {
        if (x != nullptr)
        {
            inorderTraversal(x->left);
            cout << x->key << " ";
            inorderTraversal(x->right);
        }
    }

    void inorder()
    {
        inorderTraversal(root);
    }
};

int main()
{
    RedBlackTree<int> rbTree;
    rbTree.insert(10);
    rbTree.insert(5);
    rbTree.insert(15);
    rbTree.insert(3);
    rbTree.insert(7);
    for (int i = 0; i <= 10; ++i)
    {
        rbTree.insert(i);
        rbTree.insert(20 - i);
    }
    cout << "Inorder traversal: ";
    rbTree.inorder();
    cout << endl;
    return 0;
}
