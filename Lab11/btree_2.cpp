#include <iostream>
#include <cstdlib>
using namespace std;
template<class T>
class BinarySearchTree
{
private:
struct tree_node
{
tree_node* left;
tree_node* right;
T data;
};
tree_node* root;
public:
BinarySearchTree()
{
root = NULL;
}
bool isEmpty() const { return root==NULL; }
void print_inorder();
void inorder(tree_node*);
void print_preorder();
void preorder(tree_node*);
void print_postorder();
void postorder(tree_node*);
void insert(T);
void remove(T);
bool search(T);
};


template <class T>
void BinarySearchTree<T>::insert(T d)
{
tree_node* t = new tree_node;
tree_node* parent;
t->data = d;
t->left = NULL;
t->right = NULL;
parent = NULL;
if(isEmpty()) root = t;
else
{
tree_node* curr;
curr = root;
while(curr)
{
parent = curr;
if(t->data > curr->data) curr = curr->right;
else curr = curr->left;
}

if(t->data < parent->data)
parent->left = t;
else
parent->right = t;
}
}
template <class T>
bool BinarySearchTree<T>::search(T d)
{
bool found = false;
if(isEmpty())
{
cout<<" This Tree is empty! "<<endl;
return false;
}
tree_node* curr;
tree_node* parent;
curr = root;
parent = (tree_node*)NULL;
while(curr != NULL)
{
if(curr->data == d)
{
found = true;
break;
}
else
{
parent = curr;
if(d>curr->data) curr = curr->right;
else curr = curr->left;
}
}
if(!found)
{
cout<<" Data not found! "<<endl;
}
else
{
cout<<" Data found! "<<endl;
}

return found;
}

template <class T>
void BinarySearchTree<T>::remove(T d)
{
bool found = false;
if(isEmpty())
{
cout<<" This Tree is empty! "<<endl;
return;
}
tree_node* curr;
tree_node* parent;
curr = root;
parent = (tree_node*)NULL;
while(curr != NULL)
{
if(curr->data == d)
{
found = true;
break;
}
else
{
parent = curr;
if(d>curr->data) curr = curr->right;
else curr = curr->left;
}
}
if(!found)
{
cout<<" Data not found! "<<endl;
return;
}

if((curr->left == NULL && curr->right != NULL)|| (curr->left != NULL
&& curr->right == NULL))
{
if(curr->left == NULL && curr->right != NULL)
{
if(parent->left == curr)
{
parent->left = curr->right;
delete curr;
}
else
{
parent->right = curr->right;
delete curr;
}
}
else
{
if(parent->left == curr)
{
parent->left = curr->left;
delete curr;
}
else
{
parent->right = curr->left;
delete curr;
}
}
return;
}

if( curr->left == NULL && curr->right == NULL)
{
if (parent == NULL)
{
delete curr;

} else
if(parent->left == curr) parent->left = NULL;
else parent->right = NULL;
delete curr;
return;
}


if (curr->left != NULL && curr->right != NULL)
{
tree_node* chkr;
chkr = curr->right;
if((chkr->left == NULL) && (chkr->right == NULL))
{
curr = chkr;
delete chkr;
curr->right = NULL;
}
else
{

if((curr->right)->left != NULL)
{
tree_node* lcurr;
tree_node* lcurrp;
lcurrp = curr->right;
lcurr = (curr->right)->left;
while(lcurr->left != NULL)
{
lcurrp = lcurr;
lcurr = lcurr->left;
}
curr->data = lcurr->data;
delete lcurr;
lcurrp->left = NULL;
}
else
{
tree_node* tmp;
tmp = curr->right;
curr->data = tmp->data;
curr->right = tmp->right;
delete tmp;
}

}
return;
}

}
template<class T>
void BinarySearchTree<T>::print_inorder()
{
inorder(root);
}
template<class T>
void BinarySearchTree<T>::inorder(tree_node* p)
{
if(p != NULL)
{
if(p->left) inorder(p->left);
cout<<" "<<p->data<<" ";
if(p->right) inorder(p->right);
}
else return;
}
template<class T>
void BinarySearchTree<T>::print_preorder()
{
preorder(root);
}
template<class T>
void BinarySearchTree<T>::preorder(tree_node* p)
{
if(p != NULL)
{
cout<<" "<<p->data<<" ";
if(p->left) preorder(p->left);
if(p->right) preorder(p->right);
}
else return;
}
template<class T>
void BinarySearchTree<T>::print_postorder()
{
postorder(root);
}

template<class T>
void BinarySearchTree<T>::postorder(tree_node* p)
{
if(p != NULL)
{
if(p->left) postorder(p->left);
if(p->right) postorder(p->right);
cout<<" "<<p->data<<" ";
}
else return;
}

int main()
{
BinarySearchTree<int> b;
int ch;
int tmp,tmp1;
while(1)
{
cout<<endl<<endl;
cout<<" Binary Search Tree Operations "<<endl;
cout<<" ----------------------------- "<<endl;
cout<<" 1. Insertion/Creation "<<endl;
cout<<" 2. In-Order Traversal "<<endl;
cout<<" 3. Pre-Order Traversal "<<endl;
cout<<" 4. Post-Order Traversal "<<endl;
cout<<" 5. Removal "<<endl;
cout<<" 6. Search "<<endl;
cout<<" 7. Exit "<<endl;
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
cout<<" -------------------"<<endl;
b.print_inorder();
break;
case 3 : cout<<endl;
cout<<" Pre-Order Traversal "<<endl;
cout<<" -------------------"<<endl;
b.print_preorder();
break;
case 4 : cout<<endl;
cout<<" Post-Order Traversal "<<endl;
cout<<" --------------------"<<endl;
b.print_postorder();
break;
case 5 : cout<<" Enter data to be deleted : ";
cin.clear();
cin.ignore(1);
cin>>tmp1;
b.remove(tmp1);
break;
case 6 : cout<<" Enter data to be searched : ";
cin.ignore(1);
cin>>tmp;
b.search(tmp);
break;
case 7 : system("pause");
return 0;
break;
}
}
}