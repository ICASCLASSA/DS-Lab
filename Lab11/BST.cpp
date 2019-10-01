#include <iostream>
#include <cstdlib>

using namespace std;

template <class T>
class Node {
 public:
    T info;
    Node<T> *left;
    Node<T> *right;
};

template <class T>
class BST {
 public:
    Node<T> *root;

    void find(int, Node<T> **, Node<T> **);    
    void insert(Node<T> *, Node<T> *);

    void del(int);
    void case_a(Node<T> *,Node<T> *);
    void case_b(Node<T> *,Node<T> *);
    void case_c(Node<T> *,Node<T> *);

    void preorder(Node<T> *);
    void inorder(Node<T> *);
    void postorder(Node<T> *);
    bool printlevel(Node<T>* , int);
    void levelorder();

    void display(Node<T> *, int);

    BST() {
        root = NULL;
    }
};




int main() {
    int choice, num;
    BST<int> bst;
    Node<int> *temp;

    while (1) {
        cout << "\033[2J\033[1;1H";  // Internet Code, for Clearing Screen
        cout<<"\n\t\tOperations on BST\n";
        bst.display(bst.root,1);
        cout<<endl;
        cout<<"\n 1.Insert Element ";
        cout<<"\n 2.Delete Element ";
        cout<<"\n 3.Inorder Traversal";
        cout<<"\n 4.Preorder Traversal";
        cout<<"\n 5.Postorder Traversal";
        cout<<"\n 6.Levelorder Traversal";
        cout<<"\n 7.Display";
        cout<<"\n 8.Quit";
        cout<<"\n >>> ";
        cin>>choice;

        switch(choice) {
            case 1: temp = new Node<int>;
                    cout<<"\nEnter the number to be inserted : ";
    	            cin>>temp->info;
                    bst.insert(bst.root, temp);
                    break;

            case 2: if(bst.root == NULL) {
                        cout<<"\n\tTree is empty, nothing to delete"<<endl;
                        continue;
                    }
                    cout<<"\nEnter the number to be deleted : ";
                    cin>>num;
                    bst.del(num);
                    break;

            case 3: cout<<"\nInorder Traversal of BST:"<<endl;
                    bst.inorder(bst.root);
                    cout<<endl;
                    break;

        	case 4: cout<<"\nPreorder Traversal of BST:"<<endl;
                    bst.preorder(bst.root);
                    cout<<endl;
                    break;

            case 5: cout<<"\nPostorder Traversal of BST:"<<endl;
                    bst.postorder(bst.root);
                    cout<<endl;
                    break;

            case 6: cout<<"\nLevelorder Traversal of BST:"<<endl;
                    bst.levelorder();
                    cout<<endl;
                    break;

            case 7: cout<<"\nDisplay BST:"<<endl;
                    bst.display(bst.root, 1);
                    cout<<endl;
                    break;

            case 8: exit(1);

            default: cout<<"\n\t\tInvalid Menu Item, Try Again!";
        }
        cout<<"\n\t\t<ENTER ANY KEY TO CONTINUE>";
        cin.ignore();
        cin.get();
    }
}

 

template <class T>
void BST<T>::find(int item, Node<T> **par, Node<T> **loc) {
    Node<T> *ptr, *ptrsave;

    if (root == NULL) {
        *loc = NULL;
        *par = NULL;
        return;
    }

    if (item == root->info) {
        *loc = root;
        *par = NULL;
        return;
    }

    if (item < root->info)
        ptr = root->left;
    else
        ptr = root->right;

    ptrsave = root;

    while (ptr != NULL) {

        if (item == ptr->info) {
            *loc = ptr;
            *par = ptrsave;
            return;
        }

        ptrsave = ptr;

        if (item < ptr->info)
            ptr = ptr->left;
    	else
    	    ptr = ptr->right;
    }

    *loc = NULL;
    *par = ptrsave;
}

 

template <class T>
void BST<T>::insert(Node<T> *tree, Node<T> *newNode) {

    if (root == NULL) {

        root = new Node<T>;
        root->info = newNode->info;
        root->left = NULL;
        root->right = NULL;
        cout<<"Root Node<T> is Added"<<endl;
        return;
    }

    if (tree->info == newNode->info) {
        cout<<"Element already in the tree"<<endl;
        return;
    }

    if (tree->info > newNode->info) {
        if (tree->left != NULL) {
            insert(tree->left, newNode);
    	}
    	else {
            tree->left = newNode;
            (tree->left)->left = NULL;
            (tree->left)->right = NULL;
            cout<<"Node<T> Added To Left"<<endl;
            return;
        }
    }
    else {
        if (tree->right != NULL) {
            insert(tree->right, newNode);
        }
        else {
            tree->right = newNode;
            (tree->right)->left = NULL;
            (tree->right)->right = NULL;
            cout<<"Node<T> Added To Right"<<endl;
            return;
        }	

    }

}

template <class T>
void BST<T>::del(int item) {
    Node<T> *parent, *location;

    if (root == NULL) {
        cout<<"Tree empty"<<endl;
        return;
    }

    find(item, &parent, &location);

    if (location == NULL) {
        cout<<"Item not present in tree"<<endl;
        return;
    }

    if (location->left == NULL && location->right == NULL)
        case_a(parent, location);
    if (location->left != NULL && location->right == NULL)
        case_b(parent, location);
    if (location->left == NULL && location->right != NULL)
        case_b(parent, location);
    if (location->left != NULL && location->right != NULL)
        case_c(parent, location);

    free(location);
}

template <class T>
void BST<T>::case_a(Node<T> *par, Node<T> *loc ) {

    if (par == NULL)

    {

        root = NULL;

    }

    else

    {

        if (loc == par->left)

            par->left = NULL;

        else

            par->right = NULL;

    }
}

template <class T>
void BST<T>::case_b(Node<T> *par, Node<T> *loc) {

    Node<T> *child;

    if (loc->left != NULL)

        child = loc->left;

    else

        child = loc->right;

    if (par == NULL)

    {

        root = child;

    }

    else

    {

        if (loc == par->left)

            par->left = child;

        else

            par->right = child;

    }
}

template <class T>
void BST<T>::case_c(Node<T> *par, Node<T> *loc) {

    Node<T> *ptr, *ptrsave, *suc, *parsuc;

    ptrsave = loc;

    ptr = loc->right;

    while (ptr->left != NULL)

    {

        ptrsave = ptr;

        ptr = ptr->left;

    }

    suc = ptr;

    parsuc = ptrsave;

    if (suc->left == NULL && suc->right == NULL)

        case_a(parsuc, suc);

    else

        case_b(parsuc, suc);

    if (par == NULL)

    {

        root = suc;

    }

    else

    {

        if (loc == par->left)

            par->left = suc;

        else

            par->right = suc;

    }

    suc->left = loc->left;

    suc->right = loc->right;
}

 

template <class T>
void BST<T>::preorder(Node<T> *ptr) {
    if (root == NULL) {
        cout<<"Tree is empty"<<endl;
        return;
    }

    if (ptr != NULL) {
        cout<<ptr->info<<"  ";
        preorder(ptr->left);
        preorder(ptr->right);
    }
}

template <class T>
void BST<T>::inorder(Node<T> *ptr) {
    if (root == NULL) {
        cout<<"Tree is empty"<<endl;
        return;
    }

    if (ptr != NULL) {
        inorder(ptr->left);
        cout<<ptr->info<<"  ";
        inorder(ptr->right);
    }
}

template <class T>
void BST<T>::postorder(Node<T> *ptr) {
    if (root == NULL) {
        cout<<"Tree is empty"<<endl;
        return;
    }

    if (ptr != NULL) {
        postorder(ptr->left);
        postorder(ptr->right);
        cout<<ptr->info<<"  ";
    }
}

template <class T>
bool BST<T>::printlevel(Node<T> *root, int level) {

    if (root == NULL)
        return false;

    if (level == 1) {
        cout << root->info << " ";
        return true;
    }

    bool left = printlevel(root->left, level - 1);
    bool right = printlevel(root->right, level - 1);

    return left || right;
}

template <class T>
void BST<T>::levelorder() {
    int level = 1;
    while (printlevel(root, level)) {
        cout<<" | ";
        level++;
    }
}


template <class T>
void BST<T>::display(Node<T> *ptr, int level) {
    int i;

    if (ptr != NULL) {
        display(ptr->right, level+1);
        cout<<endl;

        if (ptr == root)
            cout<<"Root->:  ";
        else
            for (i = 0;i < level;i++)
                cout<<"       ";

        cout<<ptr->info;
        display(ptr->left, level+1);
    }
}
