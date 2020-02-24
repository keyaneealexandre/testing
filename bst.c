#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bst.h"

///typedef char (*comparer)(char, char);//used to compare two chars


//printf("-2");
void add ( bst_node ** root, char *word ){
    //printf("here in add");
    if(*root == NULL)
    {
        bst_node *current = (bst_node*)malloc(sizeof(bst_node));
        //strcpy(root->data, word);
        current->data = word;
        current->left = NULL;
        current->right = NULL;
       // printf("%s\n", current->data);
        *root = current;
        //return;
        //printf("%s\n", (*root)->data);
    }
    /* Otherwise, recur down the tree */
    else if (strcmp(word, (*root)->data) < 0){
        //strcpy(current->left, add(current->left, word));
        //root = &(*root)->left;
        add(&((*root)->left), word);
    }
    else{
        //strcpy(current->right, add(current->right, word));
        //root = &(*root)->right;
        add(&((*root)->right), word);
    }
    //return node;
}


void inorder ( bst_node * root ) {
    if (root != NULL)
    {
        inorder(root->left);
        printf("%s\n", root->data);
        inorder(root->right);
    }
}


bst_node * removeNode(bst_node *root, char *data) {
 if (root == NULL) {
     return NULL;
  }
  if (strcmp(data,root->data) < 0) {  // data is in the left sub tree.
      root->left = removeNode(root->left, data);
  } else if (strcmp(data,root->data) > 0) { // data is in the right sub tree.
      root->right = removeNode(root->right, data);
  } else {
     // case 1: no children
     if (root->left == NULL && root->right == NULL) {
        free(root); // wipe out the memory, in C, use free function
        root = NULL;
     }
     // case 2: one child (right)
     else if (root->left == NULL) {
        bst_node *temp = root; // save current node as a backup
        root = root->right;
        free(temp);
     }
     // case 3: one child (left)
     else if (root->right == NULL) {
        bst_node *temp = root; // save current node as a backup
        root = root->left;
        free(temp);
     }
     // case 4: two children
     else {
        bst_node *temp = smallest(root->right); // find minimal value of right sub tree
        root->data = temp->data; // duplicate the node
        root->right = removeNode(root->right, temp->data); // delete the duplicate node
     }
  }
  return root; // parent node can update reference
}

bst_node *smallest(bst_node *root){
    if(root == NULL){
        return root;
    }
    else{
        return smallest(root->left);
    }
    return root;
}

char * removeSmallest (bst_node ** root ){
    //root = smallest(*root);
    //root = (*root);
    (*root) = removeNode( smallest(*root), (*root)->data);
    return (*root)->data;
}

bst_node *largest(bst_node *root){
    if(root == NULL){
        return root;
    }
    else{
        return largest(root->right);
    }
    return root;
}


char * removeLargest ( bst_node ** root ){

    (*root) = removeNode( largest(*root), (*root)->data);
    return (*root)->data;
}




