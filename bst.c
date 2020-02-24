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
        printf("%s ", root->data);
        inorder(root->right);
    }
}


bst_node * removeNode(bst_node *root, char *data) {
    //printf("here in removeNode\n");
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
        //printf("%s\n", root->data);
        return root;
        free(root); // wipe out the memory, in C, use free function
        root = NULL;
     }
     // case 2: one child (right)
     else if (root->left == NULL) {
        bst_node *temp = root; // save current node as a backup
        root = root->right;
        //printf("%s\n", temp->data);
        return temp;
        free(temp);
     }
     // case 3: one child (left)
     else if (root->right == NULL) {
        bst_node *temp = root; // save current node as a backup
        root = root->left;
        //printf("%s\n", temp->data);
        return temp;
        free(temp);
     }
     // case 4: two children
     else {
        bst_node *temp = smallest(root->right); // find minimal value of right sub tree
        root->data = temp->data; // duplicate the node
        //printf("%s\n", temp->data);
        return temp;
        root->right = removeNode(root->right, temp->data); // delete the duplicate node
     }
  }
  //printf("%s\n", root->data);
  return root; // parent node can update reference
}


bst_node *smallest(bst_node *root){
    //printf("here in smallest\n");
    //bst_node *current = root;
    while(root && root->left != NULL){
        root = root->left;
    }
    printf("%s\n", root->data);
    return root;
}

char * removeSmallest (bst_node ** root ){
    //printf("here in removeSmallest\n");
    //root = smallest(*root);
    //root = (*root);
     bst_node *smallestNode = smallest(*root);
     //printf("%s\n", smallestNode->data);
     //root = &smallestNode;
     //printf("%s\n", smallestNode->data);
     return (removeNode((*root), smallestNode->data))->data;
    //return (*root)->data;
    //return NULL;
}

bst_node *largest(bst_node *root){
    while(root && root->right != NULL){
        root = root->right;
    }
    printf("%s\n", root->data);
    return root;
}


char * removeLargest ( bst_node ** root ){
    bst_node *largestNode = largest(*root);
    //(*root) = removeNode( largest(*root), (*root)->data);
    return (removeNode((*root), largestNode->data))->data;
}




