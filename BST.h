#ifndef WEATHER_PROJECT_BST_H
#define WEATHER_PROJECT_BST_H
#include "iostream"
#include "fstream"
template <typename T>
struct BSTNode{
    int key;
    T data;
    BSTNode<T> *left, *right;

    /*
    ** Header: setData(T data)
    ** Sets data
    ** Pre:
    ** Post:
    ** Return:
    */
    void setData(T data){
        this->data= data;
    }
    /*
    ** Header: setLeft(BSTNode<T> obj)
    ** Sets node to left
    ** Pre:
    ** Post:
    ** Return:
    */
    void setLeft(BSTNode<T> obj){
        left = obj;
    }
    /*
    ** Header: setRight(BSTNode<T> obj)
    ** Sets node to right
    ** Pre:
    ** Post:
    ** Return:
    */
    void setRight(BSTNode<T> obj){
        right = obj;
    }
    /*
    ** Header: getLeft()
    ** Returns node of left child
    ** Pre:
    ** Post:
    ** Return: BSTNode for left child
    */
    BSTNode<T>* getLeft(){
        return left;
    }
    /*
    ** Header: getRight()
    ** Returns node of right child
    ** Pre:
    ** Post:
    ** Return: BSTNode for right child
    */
    BSTNode<T>* getRight(){
        return right;
    }
    /*
    ** Header: getData()
    ** Returns data of the node
    ** Pre:
    ** Post:
    ** Return: value of T datatype
    */
    T getData(){
        return this->data;
    }
};

template <typename T>
BSTNode<T> *root;

template <typename T>
class BST{
private:
    int count;

public:

    BST();
    ~BST();
    void print(std::ofstream& outstream);
    void Postorder(BSTNode<T> *node, std::ofstream& outstream);
    void Preorder(BSTNode<T> *node, std::ofstream& outstream);
    void Inorder(BSTNode<T> *node, std::ofstream& outstream);
    void insert(T data, int key);
    void insertHelper(T key, BSTNode<T>* leaf,int k);
    void Search(int data, std::ofstream& outstream);
    void SearchHelper(BSTNode<T>* node, int data, std::ofstream& outstream);
    void remove(int data, std::ofstream& outstream);
    void breadthFirst(BSTNode<T>* root, int level, std::ofstream& outstream);
    void breadthFirst(std::ofstream& outstream);
    int getCount();
    void setCount(int num);
    BSTNode<T> * removeHelper(int data, BSTNode<T>* node, std::ofstream& outstream);
    BSTNode<T> * findMin(BSTNode<T>* node);
    void Inorder(std::ofstream& outstream) {Inorder(root<T>, outstream);}
    void Preorder(std::ofstream& outstream){Preorder(root<T>, outstream);}
    void Postorder(std::ofstream& outstream){Postorder(root<T>, outstream);}
    void destroyTree(BSTNode<T> *node);
    bool isEmpty();
    void printDhelper(BSTNode<T> *root, int space, std::ofstream& outstream);
    void printD(BSTNode<T> *root, std::ofstream& outstream);
    void printD(std::ofstream& outstream);


};

template<typename T>
void BST<T>::printD(std::ofstream& outstream){
    printD(root<T>, outstream);
}

template<typename T>
void BST<T>::printDhelper(BSTNode<T> *root, int space, std::ofstream& outstream){
    if (root == NULL)
        return;
    space += count;
    printDhelper(root->right, space, outstream);

    std::cout<<std::endl;
    outstream<<std::endl;
    for (int i = count; i < space; i++) {
        std::cout << " ";
        outstream << " ";
    }
        std::cout << root->key << "\n";
        outstream << root->key << "\n";

    printDhelper(root->left, space, outstream);
}

template<typename T>
void BST<T>::printD(BSTNode<T> *root, std::ofstream& outstream)
{
    printDhelper(root, 0, outstream);
}

/*
** Header: breadthFirst(std::ofstream& outstream)
** Starts breadthFirst operation
** Pre: reference of ofstream object - outstream
** Post:
** Return:
*/
template <typename T>
void BST<T>:: breadthFirst(std::ofstream& outstream)
{
    int h = getCount();
    for(int i=1; i<=h; i++)
        breadthFirst(root<T>, i, outstream);
}

/*
** Header: breadthFirst(BSTNode<T>* node, int level, std::ofstream& outstream)
** Executes recursive breadthFirst operation
** Pre: pointer to BSTNode object - node, int value - level, reference of ofstream object - outstream
** Post: Print data of node if level is 1
** Return:
*/
template <typename T>
void BST<T>::breadthFirst(BSTNode<T>* node, int level, std::ofstream& outstream)
{
    if(node == NULL)
        return;
    if(level == 1) {
        outstream << node->data << " ";
        std::cout << node->data << " ";
    }
    else if (level > 1)
    {
        breadthFirst(node->left, level-1, outstream);
        breadthFirst(node->right, level-1, outstream);
    }
}

/*
** Header: print(std::ofstream& outstream)
** Print BST by executing breadthFirst, Inorder, Preorder, and Postorder operations
** Pre: reference of ofstream object - outstream
** Post: Prints the results of the operations to standard output
** Return:
*/
template <typename T>
void BST<T>::print(std::ofstream& outstream){//
    //std::cout<<"Breadth-First: ";
    //outstream<<"\nBreadth-First: ";
    //breadthFirst(outstream);
    std::cout<<"\nInorder: ";
    outstream<<"\nInorder: ";
    Inorder(outstream);//outstream
    //std::cout<<"\nPreorder: ";
    //outstream<<"\nPreorder: ";
    //Preorder(outstream);
    //std::cout<<"\nPostorder: ";
    //outstream<<"\nPostorder: ";
    //Postorder(outstream);
    //outstream<<"\n";
}

/*
** Header: getCount()
** Returns the number of nodes in BST
** Pre:
** Post:
** Return: int value
*/
template <typename T>
int BST<T>::getCount() {
    return count;
}

/*
** Header: setCount(int num)
** Add int value to count
** Pre: int value to be added - num
** Post: Add num to count
** Return:
*/
template <typename T>
void BST<T>::setCount(int num)
{
    this->count += num;
}

/*
** Header: insert(T data)
** Insert data to BST
** Pre: data of T type to be inserted - data
** Post: Increment count by 1
** Return:
*/
template <typename T>
void BST<T>::insert(T data,int key)
{
    setCount(1);
    if(root<T>!=NULL)
        insertHelper(data, root<T>, key);
    else
    {
        root<T> = new BSTNode<T>;
        root<T>->data = data;
        root<T>->left=NULL;
        root<T>->right=NULL;
        root<T>->key = key;
    }
    //std::cout<<data<<" has been added to the Tree."<<std::endl;
}

/*
** Header: insertHelper(T key, BSTNode<T> *leaf)
** Excute recursive inserting operation
** Pre: data of T type to be inserted - key, A pointer to BSTNode object - leaf
** Post:
** Return:
*/
template <typename T>
void BST<T>::insertHelper(T key, BSTNode<T> *leaf, int k)
{
    if(key< leaf->data)
    {
        if(leaf->left!=NULL)
            insertHelper(key, leaf->left, k);
        else
        {
            leaf->left=new BSTNode<T>;
            leaf->left->data=key;
            leaf->left->key = k;
            leaf->left->left=NULL;
            leaf->left->right=NULL;
        }
    }
    else if(key >= leaf->data)
    {
        if(leaf->right!=NULL)
            insertHelper(key, leaf->right, k);
        else
        {
            leaf->right=new BSTNode<T>;
            leaf->right->data=key;
            leaf->right->key = k;
            leaf->right->left=NULL;
            leaf->right->right=NULL;
        }
    }
}

/*
** Header: BST()
** Default constructor for BST
** Pre:
** Post: Set root to NULL and count to 0
** Return:
*/
template <typename T>
BST<T>::BST() {
    root<T> = NULL;
    count = 0;
}

/*
** Header: remove(T data)
** Remove data from BST
** Pre: data of T type - data
** Post: Decrement count by 1
** Return:
*/
template <typename T>
void BST<T>:: remove(int data, std::ofstream& outstream) {
    setCount(-1);
    Search(data, outstream);
    root<T> = removeHelper(data, root<T>, outstream);
}

/*
** Header: removeHelper(T data, BSTNode<T>* node)
** Excute recursive removing operation from BST
** Pre: value of T type - data, A pointer to BSTNode object - node
** Post:
** Return:
*/
template <typename T>
BSTNode<T>* BST<T>::removeHelper(int data, BSTNode<T>* node, std::ofstream& outstream) {
    BSTNode<T>* temp;
    if(node == NULL)
        return NULL;
    else if(data < node->key)
        node->left = removeHelper(data, node->left, outstream);
    else if(data > node->key)
        node->right = removeHelper(data, node->right, outstream);
    else if(node->left && node->right)
    {
        temp = findMin(node->right);
        node->data = temp->data;
        node->key = temp->key;
        node->right = removeHelper(node->key, node->right, outstream);
    }
    else
    {
        temp = node;
        if(node->left == NULL)
            node = node->right;
        else if(node->right == NULL)
            node = node->left;
        delete temp;
        std::cout<<data<<" has been deleted."<<std::endl;
        outstream<<data<<" has been deleted."<<std::endl;
    }
    return node;
}

/*
** Header: findMin(BSTNode<T>* node)
** Find minimum value in BST
** Pre:A pointer to BSTNode object - node
** Post:
** Return: A pointer to minimum BSTNode object
*/
template <typename T>
BSTNode<T>* BST<T>:: findMin(BSTNode<T>* node)
{
    if(node == NULL)
        return NULL;
    else if(node->left == NULL)
        return node;
    else
        return findMin(node->left);
}

/*
** Header: Search(T data)
** Search node that have ceratin data in BST
** Pre: value of T type - data
** Post:
** Return:
*/
template <typename T>
void BST<T> :: Search(int data, std::ofstream& outstream){
    SearchHelper(root<T>, data, outstream);
}

/*
** Header: SearchHelper(BSTNode<T> *node, T data)
** Excutes recurisve searching operations in BST
** Pre: A pointer to BSTNode object - node, value of T type - data
** Post:
** Return:
*/
template <typename T>
void BST<T> :: SearchHelper(BSTNode<T> *node, int data, std::ofstream& outstream){
    if(node==NULL)
    {
        std::cout<<"\n"<<data<<" not found!"<<std::endl;
        outstream<<"\n"<<data<<" not found!"<<std::endl;
        setCount(1);
        return;
    }
    if(data > node->key)
    {
        SearchHelper(node->right,data, outstream);
    }
    else if(data < node->key)
    {
        SearchHelper(node->left,data, outstream);
    }
    else
    {
        std::cout<<node->key<<" found: ";
        std::cout<<node->data;
        outstream<<node->key<<" found: ";
        outstream<<node->data;
    }
}


/*
** Header: Inorder(BSTNode<T> *node, std::ofstream& outstream)
** Excutes recurisve inorder operations in BST
** Pre: A pointer to BSTNode object - node, reference of ofstream object - outstream
** Post:
** Return:
*/
template <typename T>
void BST<T> :: Inorder(BSTNode<T> *node, std::ofstream& outstream)//,
{
    if(node==NULL)
    {
        return;
    }
    Inorder(node->left, outstream);//,
    std::cout<<node->key<<" ";
    outstream<<node->key<<" ";
    Inorder(node->right, outstream);//,
}

/*
** Header: Preorder(BSTNode<T> *node, std::ofstream& outstream)
** Excutes recurisve preorder operations in BST
** Pre: A pointer to BSTNode object - node, reference of ofstream object - outstream
** Post:
** Return:
*/
template <typename T>
void BST<T>::Preorder(BSTNode<T> *node, std::ofstream& outstream)
{
    if(node==NULL)
    {
        return;
    }
    std::cout<<node->data<<" ";
    outstream<<node->data<<" ";
    Preorder(node->left, outstream);
    Preorder(node->right, outstream);
}

/*
** Header: Postorder(BSTNode<T> *node, std::ofstream& outstream)
** Excutes recurisve postorder operations in BST
** Pre: A pointer to BSTNode object - node, reference of ofstream object - outstream
** Post:
** Return:
*/
template <typename T>
void BST<T>:: Postorder(BSTNode<T> *node, std::ofstream& outstream)
{
    if(node==NULL)
    {
        return;
    }
    Postorder(node->left, outstream);
    Postorder(node->right, outstream);
    std::cout<<node->data<<" ";
    outstream<<node->data<<" ";
}

/*
** Header: ~BST()
** Destroy BST and increment count by 1
** Pre:
** Post: BST is destroyed
** Return:
*/
template <typename T>
BST<T>::~BST(){
    setCount(1);
    destroyTree(root<T>);
}

/*
** Header: destroyTree(BSTNode<T> *node)
** Deletes node recursively
** Pre: A pointer to BSTNode object - node
** Post: BST is destroyed
** Return:
*/
template <typename T>
void BST<T>::destroyTree(BSTNode<T> *node)
{
    if (node)
    {
        destroyTree(node->left);
        destroyTree(node->right);
        delete node;
    }
}

/*
** Header: isEmpty()
** Returns whether BST is empty
** Pre:
** Post:
** Return: True if BST is empty and false if BST is not empty
*/
template <typename T>
bool BST<T>::isEmpty()
{
    return (root<T>->left == nullptr && root<T>->right == nullptr);
}
#endif //WEATHERPROJECT_BST_H
