#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bst.h"

typedef int (*comparer)(char, char);


/*
    create a new node
*/
bst_node *newNode(char data)
{
    bst_node *new_node = (bst_node*)malloc(sizeof(bst_node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}


void add ( bst_node ** root, char * word ) {
    if(root == NULL)
    {
        root = create_node(data);
    }
    addRecurse(root, compare, data);

}

 void addRecurse(bst_node **node, comparer compare, char data){

    bst_node ** current;


    /* Otherwise, recur down the tree */
    if (compare(data,node->data) < 0){
        if(node->left == NULL){
            current = create_node(data);
            node->left = current;
        }
        else{
            node->left  = addRecurse(node->left, compare, data);
        }
    }
    else{
        if(node->right == NULL){
            current = create_node(data);
            node->right = current;
        }
        else{

            node->right = addRecurse(node->right, compare, data);
        }
    }
 }


void inorder ( bst_node * root ) {
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d \n", root->data);
        inorder(root->right);
    }
}


char * remove(struct bst_node **root, int data) {
  if (root == NULL) {
     return NULL;
  }
  if (data < root->data) {  // data is in the left sub tree.
      root->left = remove(root->left, data);
  } else if (data > root->data) { // data is in the right sub tree.
      root->right = remove(root->right, data);
  } else {
     // case 1: no children
     if (root->left == NULL && root->right == NULL) {
        free(root); // wipe out the memory, in C, use free function
        root = NULL;
     }
     // case 2: one child (right)
     else if (root->left == NULL) {
        struct bst_node *temp = root; // save current node as a backup
        root = root->right;
        free(temp);
     }
     // case 3: one child (left)
     else if (root->right == NULL) {
        struct Node *temp = root; // save current node as a backup
        root = root->left;
        free(temp);
     }
     // case 4: two children
     else {
        struct bst_node *temp = smallest(root->right); // find minimal value of right sub tree
        root->data = temp->data; // duplicate the node
        root->right = remove(root->right, temp->data); // delete the duplicate node
     }
  }
  return root->data; // parent node can update reference
}

bst_node *smallest(bst_node **root){
    if(root == NULL){
        return root;
    }
    else{
        return smallest(root->left);
    }
    return root;
}

char * removeSmallest (bst_node ** root ){
    if(root == NULL){
        return root;
    }
    else{
        return remove(smallest(root), root->data);
    }
}

bst_node *largest(bst_node **root){
    if(root == NULL){
        return root;
    }
    else{
        return largest(root->right);
    }
    return root;
}


char * removeLargest (  bst_node ** root ){

     if(root == NULL){
        return root;
    }
    else{
        return remove(largest(root), root->data);
    }
}




