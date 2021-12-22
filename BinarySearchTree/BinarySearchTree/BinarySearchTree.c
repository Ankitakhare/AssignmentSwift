//
//  BinarySearchTree.c
//  BinarySearchTree
//
//  Created by ankita on 13/12/21.
//  Copyright © 2021 ankita. All rights reserved.
//

#include <stdio.h>
#include "BinaryTreeStructure.h"
#include <stdlib.h>


void insert(node **temp,int num ){
    /*
     binary search tree creation
     if temp pointer value is null create new node and make left and right null
     else check the num is less thanb process to left chiid
     else process to right side
     */
    if (*temp == NULL) {
        *temp = (node *)malloc(sizeof(node));
        (*temp) -> left = NULL;
        (*temp) -> right = NULL;
        (*temp) -> data = num;
        return;
    }else{
        if (num < (*temp) -> data) {
            insert(&((*temp) -> left), num); // we should pass addess of a pointer node -> left address
            
        }else{
            insert(&((*temp) -> right), num);
        }
    }
    return;
}



void inOrder(node *t){
    /*
     visti left
     visit root
     visit right
     
     */
    if (t != NULL) {
        inOrder(t -> left);
        printf("%d", t -> data);
        inOrder(t -> right);
    }
}

void preOrder(node *t){
    /*
    visti root
    visit left
    visit right
    
    */
    if (t != NULL) {
        printf("%d", t -> data);
        inOrder(t -> left);
        inOrder(t -> right);
    }
}

void postOrder(node *t){
    /*
    visti left
    visit right
    visit root
    
    */
    if (t != NULL) {
       
        inOrder(t -> left);
        inOrder(t -> right);
        printf("%d", t -> data);
    }
}

node *search(node* temp, int key){
    if (temp == NULL || temp ->data == key) {
        return temp;
    }
    if (key < temp -> data) {
        return search(temp -> left, key);
    }
    return search(temp -> right, key);
    
}


// lowest  common Ancestor


