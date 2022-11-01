#include <iostream>

#include <cstddef>
using namespace std;
template <typename T>
struct treeNode {
    T data;
    struct treeNode *left;
    struct treeNode *right;

};

// addNode function
// requires: a root and a value
// effects: adds a node to the tree whilst maintaining the specified condition
template <typename T>
void addNode(treeNode<T> *root, T data) {
    if (root == NULL)                       
    {
       root = new treeNode<T>;
       root->data = data;
       root->left = NULL;
       root->right = NULL;
    }
    else
    {
        if (root->left == NULL) {          
          root->left = new treeNode<T>;
          root->left->data = data;
          root->left->left = NULL;
          root->left->right = NULL;
        }
        else if (root->right == NULL) {    
          root->right = new treeNode<T>;
          root->right->data = data;
          root->right->left = NULL;
          root->right->right = NULL;
        }
        else {                              
            addNode(root->left, data);
        }
    }
}

// deleteNode function
// requires: a root and a value
// effects: deletes a node from the tree only if it's a leaf
template <typename T>
void deleteNode(treeNode<T> *root, T data) {
    if (root == NULL){
        return;
    }
    else{                                     

        if (root->left != NULL) {              

            if (root->left->data == data) {    

                if (root->left->left == NULL 
                    && root->left->right == NULL) {    

                    delete (root->left);
                    root->left = NULL;                  
                }
                
                else {                             
                        cout << "CANNOT DELETE NODE." << endl;
                }
            }
        
            else{                                   
                    deleteNode(root->left, data);
            }
        }

        if (root->right != NULL ) {                 

            if (root->right->data == data) {          

                if (root->right->left == NULL 
                    && root->right->right == NULL) {  

                        delete root->right;
                        root->right = NULL;
                }
            
                else {                                      
                        cout << "CANNOT DELETE NODE." << endl;
                }
            }
                
            else {                                      
                deleteNode(root->right, data);
            }
        }
    }
}

// treeSize function
// requires: a root
// effects: returns the size of the tree
template <typename T>
int treeSize(treeNode<T> *root) {
    if (root == NULL) {         
        return 0;
    }
    else                    
    {
      return 1 + treeSize(root->left) + treeSize(root->right);
    }
}


// subtreeSize function
// requires: a root and a value
// effects: returns the size of the subtree whose root is the node with the specified value
template <typename T>
int subtreeSize(treeNode<T> *root, T data) {
    if (root == NULL) {         
        return 0;
    }
    else {                          
        if (root->data == data) {   
            return treeSize(root);
        }
        else {                       
            return subtreeSize(root->left, data) + subtreeSize(root->right, data);
        }
    }
}


// postOrder function
// requires: a root
// effects: prints the tree in post-order
template <typename T>
void postOrderPrint(treeNode<T> *root) {
    if (root == NULL) {         
        return;
    }
    else {                              
        postOrderPrint(root->left);    
        postOrderPrint(root->right);   
        cout << root->data << endl;     
    }
}

// preOrder function
// requires: a root
// effects: prints the tree in pre-order
template <typename T>
void preOrderPrint(treeNode<T> *root) {
    if (root == NULL) {             
        return;
    }
    else {                              
        cout << root->data << endl;     
        preOrderPrint(root->left);     
        preOrderPrint(root->right);        
    }
}

// inOrder function
// requires: a root
// effects: prints the tree in-order
template <typename T>
void inOrderPrint(treeNode<T> *root) {
    if (root == NULL) {             //if the root is null, then we return
        return;
    }
    else {                          //print left subtree, print root, print right subtree
        inOrderPrint(root->left);  
        cout << root->data << endl; //print the root
        inOrderPrint(root->right);
    }
}

int main()
{
    cout << "INT TREE" << endl;
    treeNode<int> *root = new treeNode<int>;
    root->data = 1;
    root->left = NULL;
    root->right = NULL;

    addNode(root, 2);
    addNode(root, 3);
    addNode(root, 4);
    addNode(root, 5);
    addNode(root, 6);
    addNode(root, 7);
    addNode(root, 8);
    addNode(root, 9);
    addNode(root, 10);
    addNode(root, 11);
    addNode(root, 12);


    cout <<"Tree size: " << treeSize(root) << endl;
    cout << "Subtree size at 3: " << subtreeSize(root, 3) << endl; 
    
    cout << "postOrderPrint" << endl;
    postOrderPrint(root);
    cout << endl;

    cout << "preOrderPrint" << endl;
    preOrderPrint(root);
    cout << endl;

    cout << "inOrderPrint" << endl;
    inOrderPrint(root);
    cout << endl;

    cout << "Deleting Node 12" << endl;
    deleteNode(root, 12);

    cout <<"New Tree size: " << treeSize(root) << endl;    


    cout << endl;
    cout << "----------------" << endl;
    cout << endl;


    cout << "CHAR TREE" << endl;
    
    treeNode<char> *root2 = new treeNode<char>;
    root2->data = 'a';
    root2->left = NULL;
    root2->right = NULL;

    addNode(root2, 'b');
    addNode(root2, 'c');
    addNode(root2, 'd');
    addNode(root2, 'e');
    addNode(root2, 'f');
    addNode(root2, 'g');
    addNode(root2, 'h');
    addNode(root2, 'i');
    addNode(root2, 'j');
    addNode(root2, 'k');
    addNode(root2, 'l');
    
    cout <<"Tree size: " << treeSize(root2) << endl;

    cout << "Subtree size at c: " << subtreeSize(root2, 'j') << endl; 
    

    cout << "postOrderPrint" << endl;
    postOrderPrint(root2);
    cout << endl;

    cout << "preOrderPrint" << endl;
    preOrderPrint(root2);
    cout << endl;

    cout << "inOrderPrint" << endl;
    inOrderPrint(root2);
    cout << endl;

    cout << "Deleting Node 'l'" << endl;
    deleteNode(root2, 'l');


    cout <<"New Tree size: " << treeSize(root2) << endl;

    return 0;
  
}