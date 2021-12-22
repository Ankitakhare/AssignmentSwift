//
//  BinaryTree.c
//  BinaryTree
//
//  Created by ankita on 14/12/21.
//  Copyright © 2021 ankita. All rights reserved.
//
//

#include <stdio.h>
#include <stdlib.h>
#include "BinaryTreeStructure.h"


node* create(){
    node *p = NULL;
    int value;
    printf("\n enter data: (-1 for no node or terminal)");
    scanf("%d",&value);
    
    if (value == -1)
        return p;
    /*
     if its is not leaf node value is not -1
     create a node node at p temp pointer
     and assign value of x to p -> data
     ask about left child(if its required we should create left childe node first until its null)
     left child is terminated then
     ask about right child (if its required we should create right childe node first until its null)
     */
    p = (node *)malloc(sizeof(node));
    p -> data = value;
    printf("\n enter left child of %d",value);
    p -> left = create();
    printf("\n enter right child of %d",value);
    p -> right = create();
    return p;
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
