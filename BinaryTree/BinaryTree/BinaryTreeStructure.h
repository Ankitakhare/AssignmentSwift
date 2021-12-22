//
//  BinaryTreeStructure.h
//  BinaryTree
//
//  Created by ankita on 14/12/21.
//  Copyright © 2021 ankita. All rights reserved.
//
//

#ifndef BinaryTreeStructure_h
#define BinaryTreeStructure_h

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
}node;

node* create(); // return an address ity node address or rooot node address
void inOrder(node *);// it takes root node
void preOrder(node *); // it vtakes root node
void postOrder(node *); // it vtakes root node
#endif /* BinaryTreeStructure_h */
