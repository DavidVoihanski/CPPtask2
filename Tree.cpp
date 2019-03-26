#include "Tree.hpp"
using namespace std;
int Node::getValue(){
    return value;
}
void Node::setValue(int i){
    Node::value = i;
}
Node* Node::getLeft(){
    return Node::left;
}
Node* Node::getRight(){
    return Node::right;
}
Node* Node::getParent(){
    return Node::parent;
}
void Node::setLeft(Node* n){
    Node::left = n;
}
void Node::setRight(Node* n){
    Node::right = n;
}
void Node::setParent(Node*n){
    Node::parent = n;
}
Node::Node(){
    value = 0;
    Node::setLeft(NULL);
    Node::setRight(NULL);
    Node::setParent(NULL);
}
Node::~Node(){
    
}



Node* ariel::Tree::getRoot(){
    return root_;
}
//taken from https://gist.github.com/mycodeschool/9465a188248b624afdbf
Node* ariel::Tree::insert(int x, Node* t){
    if(t == NULL)
    {
        t = new Node;
        t->setValue(x);
        t->setLeft(NULL);
        t->setRight(NULL);
    }
    else if(x < t->getValue()){
        t->setLeft(insert(x, t->getLeft()));
        t->getLeft()->setParent(t);
    }
    else if(x > t->getValue()){
        t->setRight(insert(x, t->getRight()));
        t->getRight()->setParent(t);
    }
    return t;
}
void ariel::Tree::insert(int i){
    if(this->contains(i))throw std::invalid_argument( "Value given already exists!" );
    Node* temp = insert(i,ariel::Tree::getRoot());
    ariel::Tree::setRoot(temp);
    size_++;
}
int ariel::Tree::size(){
    return size_;
}
ariel::Tree::Tree(){
    ariel::Tree::root_ = NULL;
    size_ = 0;
}
void ariel::Tree::setRoot(Node* n){
    root_ = n;
}
void ariel::Tree::inorder(Node *root) {
	if(root == NULL) return;
	inorder(root->getLeft());       //Visit left subTree
    cout << root->getValue() << endl;
	inorder(root->getRight());      // Visit right subTree
}
//returns the Node containing the given value
Node* ariel::Tree::findNode(int i){
    Node* tempNode = root_;
    while(tempNode != NULL){
        int tempValue = tempNode->getValue();
        if(tempValue ==i)
            break; 
        if(i > tempValue)
            tempNode = tempNode->getRight();
        else if(i < tempValue)
            tempNode = tempNode->getLeft();
    }
    if(tempNode == NULL)return NULL;
    else return tempNode;
}
int ariel::Tree::parent(int i){
    if(!this->contains(i))throw std::invalid_argument( "Value given doesn't exists!" );
    Node* temp = findNode(i);
    temp = temp->getParent();
    if(temp == NULL) throw std::invalid_argument( "Parent is NULL!" );
    return temp->getValue();
}
int ariel::Tree::left(int i){
    if(!this->contains(i))throw std::invalid_argument( "Value given doesn't exists!" );
    Node* temp = findNode(i);
    temp = temp->getLeft();
    if(temp == NULL) throw std::invalid_argument( "Left is NULL!" );
    return temp->getValue();
}
int ariel::Tree::right(int i){
    if(!this->contains(i))throw std::invalid_argument( "Value given doesn't exists!" );
    Node* temp = findNode(i);
    temp = temp->getRight();
    if(temp == NULL) throw std::invalid_argument( "Right is NULL!" );
    return temp->getValue();
}
void ariel::Tree::remove(int i){
    if(!this->contains(i))throw std::invalid_argument( "Value given doesn't exist!" );
    root_ = remove(root_ , i);
    size_--;
}
//taken from https://gist.github.com/mycodeschool/9465a188248b624afdbf
Node* ariel::Tree::remove(Node* root, int data){
    if(root == NULL) return root; 
	else if(data < root->getValue()) root->setLeft(remove(root->getLeft(),data));
	else if (data > root->getValue()) root->setRight(remove(root->getRight(),data));
	// Wohoo... I found you, Get ready to be deleted	
	else {
		// Case 1:  No child
		if(root->getLeft() == NULL && root->getRight() == NULL) { 
			delete root;
			root = NULL;
		}
		//Case 2: One child 
		else if(root->getLeft() == NULL) {
			Node *temp = root;
			root = root->getRight();
			delete temp;
		}
		else if(root->getRight() == NULL) {
			Node *temp = root;
			root = root->getLeft();
			delete temp;
		}
		// case 3: 2 children
		else { 
			Node *temp = findMin(root->getRight());
			root->setValue(temp->getValue());
			root->setRight(remove(root->getRight(),temp->getValue()));
		}
	}
	return root;
}
Node* ariel::Tree::findMin(Node* root){
    while(root->getLeft() != NULL) root = root->getLeft();
	return root;
}
void ariel::Tree::print(){
    inorder(root_);
}
bool ariel::Tree::contains(int i){
    Node* temp = findNode(i);
    return temp != NULL;
}
int ariel::Tree::root(){
    if(root_ == NULL)throw std::invalid_argument("Root is NULL!");
    return root_->getValue();
}
    Node* ariel::Tree::makeEmpty(Node* t)
    {
        if(t == NULL)
            return NULL;
        {
            makeEmpty(t->getLeft());
            makeEmpty(t->getRight());
            delete t;
        }
        return NULL;
    }
ariel::Tree::~Tree(){
     root_ = makeEmpty(root_);
     size_ = 0;
}

