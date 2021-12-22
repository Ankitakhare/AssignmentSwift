//
//  BinaryTreeStructure.h
//  BinarySearchTree
//
//  Created by ankita on 13/12/21.
//  Copyright © 2021 ankita. All rights reserved.
//

#ifndef BinaryTreeStructure_h
#define BinaryTreeStructure_h

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
}node;

void insert(node **,int);
void inOrder(node *);// it takes root node
void preOrder(node *); // it vtakes root node
void postOrder(node *); // it vtakes root node
#endif /* BinaryTreeStructure_h */
