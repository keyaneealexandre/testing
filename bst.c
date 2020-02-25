#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bst.h"

/*
 * This program performs basic operations on a binary search tree.
 * It reads a sequence of instructions from the standard input stream
 * and outputs the results to the standard output stream.
 * Author: Keyanee Alexandre
 *
 */


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
    return;
}



bst_node *smallest(bst_node *root){
    while(root && root->left != NULL){
        root = root->left;
    }
    return root;
}



char * removeSmallest (bst_node ** root ){
    if((*root)==NULL){
        return NULL;
    }
    else if((*root)->left != NULL){
        return removeSmallest(&((*root)->left));
    }
    else{
        if ((*root)->left == NULL)
        {
            char * toReturn = (*root)->data;
            bst_node *temp = *root;
            *root = (*root)->right;
            free(temp);
            return toReturn;
        }
        else if ((*root)->right == NULL)
        {
            char * toReturn = (*root)->data;
            bst_node *temp = *root;
            *root = (*root)->left;
            free(temp);
            return toReturn;
        }
        char * toReturn = (*root)->data;
        bst_node* temp = smallest((*root)->right);
        (*root)->data = temp->data;
        (*root)->right = removeSmallest(&((*root)->left));
        return toReturn;
    }

}

char * removeLargest ( bst_node ** root ){
   if((*root)==NULL){
        return NULL;
    }
    else if((*root)->right != NULL){
        return removeLargest(&((*root)->right));
    }
    else{
        if ((*root)->left == NULL)
        {
            char * toReturn = (*root)->data;
            bst_node *temp = *root;
            *root = (*root)->right;
            free(temp);
            return toReturn;
        }
        else if ((*root)->right == NULL)
        {
            char * toReturn = (*root)->data;
            bst_node *temp = *root;
            *root = (*root)->left;
            free(temp);
            return toReturn;
        }
        char * toReturn = (*root)->data;
        printf("%s\n", toReturn);
        bst_node* temp = smallest((*root)->right);
        (*root)->data = temp->data;
        (*root)->right = removeLargest(&((*root)->right));
        return toReturn;
    }
}




