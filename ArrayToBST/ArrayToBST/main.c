//
//  main.c
//  ArrayToBST
//
//  Created by ankita on 13/12/21.
//  Copyright © 2021 ankita. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int data;
    struct node *left;
    struct node *right;
}node;

node *create(int data){
    node *p = (node *)malloc(sizeof(node));
    p -> data = data;
    p -> left = NULL;
    p -> right = NULL;
    return p;
}


void preOrder(node *temp){
    if (temp == NULL)
        return;
    printf("%d", temp -> data);
    preOrder(temp -> left);
    preOrder(temp -> right);
    
}


node * arrayToBST(int list[], int minIndex, int maxIndex){
    //base case
    if (minIndex > maxIndex) {
        return NULL;
    }
    // get middle element and make it root node
    int mid = (minIndex + maxIndex) / 2;
    
    node *root  = create(list[mid]);
    root -> left = arrayToBST(list, minIndex, mid - 1);
    
    root -> right = arrayToBST(list, mid + 1, maxIndex);
    
    return root;
    
}




int main(int argc, const char * argv[]) {
    // insert code here...
    int arr[] = {10,20,30,40,50,60,70};
    int size = sizeof(arr)/sizeof(arr[0]);
    node *root = arrayToBST(arr, 0, size - 1);
    
    printf("\n preorder result : ");
    preOrder(root);
    printf("\n");
    free(root);
    
    return 0;
}
