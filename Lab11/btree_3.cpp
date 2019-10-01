using namespace std;
#include<iostream>

template<class T>

class Node
    {
public:
        T data;
        Node* left;
        Node* right;

        Node()
        {
     
            left = NULL;
            right = NULL;
}
 
    };
   
    template<class T>
    class BinaryTree
    {

private:
Node<T> *root;
public:
        BinaryTree()
        {
            root = NULL;
        }
void insert(T newData, Node<T> *&root);
void display(Node<T> *&root);
void AddItem(T newData);
void PrintTree();
};

 template<class T>
      void  BinaryTree<T>::insert(T newData,Node<T> *&root)
        {
            if(root == NULL)
            {
              root = new Node<T>;
              root->data=newData;
                return;
            }

            if(newData < root->data)
                insert(newData, root->left);
            else
                insert(newData, root->right);
        }


template <class T>
        void BinaryTree<T>::display(Node<T> *&root)
        {
            if(root != NULL)
            {
                display(root->left);
                cout<< root->data<<" ";;
                display(root->right);
            }
        }

   
template <class T>
        void BinaryTree<T>::AddItem(T newData)
        {
            insert(newData, root);
        }

template <class T>
        void BinaryTree<T>::PrintTree()
        {
            display(root);
        }
   

    int main()
    {
        BinaryTree<int>bst;
        bst.AddItem(1);
        bst.AddItem(7);
        bst.AddItem(1);
        bst.AddItem(10);
        bst.AddItem(4);
        bst.PrintTree();
        return 0;
    }

