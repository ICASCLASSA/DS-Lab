#include <iostream>
#include <cstdlib>
using namespace std;
template<class T>
class node
{ public:
node<T>* l;
node<T>* r;
T data;
};
template<class T>
class BinarySearchTree
{
public:
node<T> *root;
BinarySearchTree()
{
root=NULL;
}
bool isEmpty() const { return root==NULL; }
void print_inorder();
void inorder(node<T>*);
void print_preorder();
void preorder(node<T>*);
void print_postorder();
void postorder(node<T>*);
bool printlevel(node<T>*, int);
void levelorder();
void insert(T);
};


template <class T>
void BinarySearchTree<T>::insert(T d)
{
node<T> *t;
node<T> *parent;
t= new node<T>;
t->data = d;
t->l = NULL;
t->r = NULL;
parent = NULL;
if(isEmpty()) root = t;
else
{
node<T> *curr;
curr = root;
while(curr)
{
parent = curr;
if(t->data > curr->data) curr = curr->r;
else curr = curr->l;
}

if(t->data < parent->data)
parent->l = t;
else
parent->r = t;
}
}
template<class T>
void BinarySearchTree<T>::print_inorder()
{
inorder(root);
}

template<class T>
void BinarySearchTree<T>::inorder(node<T> *p)
{
if(p != NULL)
{
if(p->l) inorder(p->l);
cout<<" "<<p->data<<" ";
if(p->r) inorder(p->r);
}
else return;
}
template<class T>
void BinarySearchTree<T>::print_preorder()
{
preorder(root);
}
template<class T>
void BinarySearchTree<T>::preorder(node<T> *p)
{
if(p != NULL)
{
cout<<" "<<p->data<<" ";
if(p->l) preorder(p->l);
if(p->r) preorder(p->r);
}
else return;
}
template<class T>
void BinarySearchTree<T>::print_postorder()
{
postorder(root);
}

template<class T>
void BinarySearchTree<T>::postorder(node<T> *p)
{
if(p != NULL)
{
if(p->l) postorder(p->l);
if(p->r) postorder(p->r);
cout<<" "<<p->data<<" ";
}
else return;
}
template<class T>
bool BinarySearchTree<T>:: printlevel(node<T> *root, int level)
{

    if (root == NULL)
        return false;

    if (level == 1)
    {
        cout << root->data << " ";

        return true;
    }

    bool left = printlevel(root->l, level - 1);
    bool right = printlevel(root->r, level - 1);

    return left || right;
}
template<class T>
void BinarySearchTree<T>:: levelorder()
{
    int level = 1;

    while (printlevel(root, level))
        level++;
}

int main()
{
BinarySearchTree<int> b;
int ch;
int tmp;
while(1)
{
cout<<endl<<endl;
cout<<" Binary Search Tree Operations "<<endl;
cout<<" 1. Insertion/Creation "<<endl;
cout<<" 2. In-Order Traversal "<<endl;
cout<<" 3. Pre-Order Traversal "<<endl;
cout<<" 4. Post-Order Traversal "<<endl;
cout<<" 5. level-order traversal "<<endl;
cout<<" 6. exit "<<endl;
cout<<" Enter your choice : ";
cin>>ch;
switch(ch)
{
case 1 : cout<<" Enter data to be inserted : ";
cin.ignore(1);
cin>>tmp;
b.insert(tmp);
break;
case 2 : cout<<endl;
cout<<" In-Order Traversal "<<endl;
b.print_inorder();
break;
case 3 : cout<<endl;
cout<<" Pre-Order Traversal "<<endl;
b.print_preorder();
break;
case 4 : cout<<endl;
cout<<" Post-Order Traversal "<<endl;
b.print_postorder();
break;
case 5 : cout<<endl;
cout<<" Level-Order Traversal "<<endl;
b.levelorder();
case 6 : cout<<endl;
cout<<" exit" <<endl;
return 0;
break;
}
}
}
