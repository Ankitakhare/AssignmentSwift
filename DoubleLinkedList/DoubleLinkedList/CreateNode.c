//
//  createNode.c
//  DoubleLinkedList
//
//  Created by Balu Naik on 5/3/20.
//  Copyright © 2020 BaluTutorial. All rights reserved.
//

#include <stdio.h>
#include "DoubleLinkStructure.h"

DLINK *head = NULL;
void createNode(void) {
    if(head == NULL) {
        head = (DLINK*)malloc(sizeof(DLINK));
        head -> pre = NULL;
        head -> data = getData();  // calls emp getData()
        head -> next = NULL;
        return;
    }
    DLINK *th= head;
    while (th -> next != NULL)
        th = th -> next;
    
    //once loop is ended. th is pointing to tail node.
    th -> next = (DLINK *)malloc(sizeof(DLINK)); // new node (old node points to new node.)
    th -> next -> pre = th; // new nodes points to old node
    th = th-> next;  // move temp pointer to new node
    th -> data = getData();
    th -> next = NULL;
    th = NULL;
    return;
    
    /*  // With temp pointer
     DLINK *th2;
     th2 = (DLINK*)malloc(sizeof(DLINK));  // new node
     th2 -> pre = th;    // new node to pre sjpuld be old node
     th2 -> data = getData();  //read data
     th2 -> next = NULL;   // because its tail node
     
     th -> next = th2;  //old node should point to new node.
     th2 = th = NULL; */
    
}
