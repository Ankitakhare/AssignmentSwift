//
//  main.c
//  BSTToDLL
//
//  Created by ankita on 14/12/21.
//  Copyright © 2021 ankita. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *left;
    struct node *right;
}NODE,DLL;



// create a helper function
// create node and assign data
// make left right to subtree to null
// return node

NODE *newNode(int value){
    NODE *newnode = (NODE *)malloc(sizeof(NODE));
    newnode -> data = value;
    newnode -> left = NULL;
    newnode -> right = NULL;
    
    return newnode;
}
/*
 create a function to convert binary into double link list
 takes 2 arguments
 */


void binaryToDll(NODE *root,DLL **head){
    //base case
    if (root == NULL)
        return;
    //create a static variable to manage previously visited node
    //static will created only once so it was pre value to next
    //initialize with null
    static DLL *prev = NULL;
    // recursivly convert left subtree
    binaryToDll(root -> left, head);
    
    if (prev == NULL) {
        *head = root;
        
    }else{
        root -> left = prev;
        prev -> right = root;
        
    }
    prev = root;
    // then convert right subtree
    
    binaryToDll(root -> right, head);
}

/*
 design a function to display elements in DLL
 start from head and travel to trail
 display each node element
 */

void display(DLL*head){
    while (head != NULL) {
        printf("%d",head -> data);
        head = head -> right;
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    NODE *root  = newNode(10);
    root -> left = newNode(20);
    root -> right = newNode(30);
    
    root -> left -> left = newNode(40);
     root -> right -> left = newNode(50);
    
    DLL *head = NULL;
    binaryToDll(root, &head);
    display(head);
    
    free(head);
    free(root);
    
    
    
    return 0;
}
