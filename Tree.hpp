#include <iostream>


class Node{
    int value;
    Node* left;
    Node* right;
    Node* parent;
    public:
    int getValue();
    void setValue(int x);
    Node* getLeft();
    Node* getRight();
    Node* getParent();
    void setParent(Node* t);
    void setRight(Node* t);
    void setLeft(Node* t);
    Node();
    ~Node();
    };
namespace ariel{
    class Tree{
        private:
        int size_;
        Node* root_;
        Node* insert(int x, Node* t);
        void inorder(Node *n);
        Node* getRoot();
        Node* findNode(int i);
        Node* remove(Node* n, int i);
        Node* findMin(Node* root);
        void setRoot(Node* n);
        Node* makeEmpty(Node* t);
        public:
        int root();
        void insert(int i);
        void remove(int i);
        int size();
        bool contains(int i);
        int parent(int i);
        int right(int i);
        int left(int i);
        void print();
        Tree();
        ~Tree();
    };
}