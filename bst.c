#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bst.h"


void add ( bst_node ** root, char *word ){
    if(*root == NULL)
    {
        bst_node *current = (bst_node*)malloc(sizeof(bst_node));
        current->data = word;
        current->left = NULL;
        current->right = NULL;
        *root = current;
    }
    /* Otherwise, recur down the tree */
    else if (strcmp(word, (*root)->data) < 0){
        add(&((*root)->left), word);
    }
    else{
        add(&((*root)->right), word);
    }
}


void inorder ( bst_node * root ) {
    if (root != NULL)
    {
        inorder(root->left);
        printf("%s ", root->data);
        inorder(root->right);
    }
}


bst_node * removeNode(bst_node *root, char *data) {
 if (root == NULL) {
     return NULL;
  }
  if (strcmp(data,root->data) < 0) {  // data is in the left sub tree.
      root->left = removeNode(root->left, data);
  }
  else if (strcmp(data,root->data) > 0) { // data is in the right sub tree.
      root->right = removeNode(root->right, data);
  }
  else {
     // node with only one child or no child
        if (root->left == NULL)
        {
            bst_node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            bst_node *temp = root->left;
            free(root);
            return temp;
        }

        // node with two children: Get the inorder successor (smallest
        // in the right subtree)
        bst_node* temp = smallest(root->right);
        root->data = temp->data;
        root->right = removeNode(root->right, temp->data);
  }
  return root; // parent node can update reference
}


bst_node *smallest(bst_node *root){
    while(root && root->left != NULL){
        root = root->left;
    }
    return root;
}

char * removeSmallest (bst_node ** root ){
     bst_node *smallestNode = smallest(*root);
     //printf("%s\n", ((removeNode((*root), smallestNode->data))->data));
     return (removeNode((*root), smallestNode->data))->data;
}

bst_node *largest(bst_node *root){
    while(root && root->right != NULL){
        root = root->right;
    }
    return root;
}


char * removeLargest ( bst_node ** root ){
    bst_node *largestNode = largest(*root);
    //printf("%s\n", ((removeNode((*root), largestNode->data))->data));
    return (removeNode((*root), largestNode->data))->data;
}




