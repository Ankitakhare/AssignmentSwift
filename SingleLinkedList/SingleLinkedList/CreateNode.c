//
//  CreateNode.c
//  SingleLinkedList
//
//  Created by Balu Naik on 5/2/20.
//  Copyright © 2020 BaluTutorial. All rights reserved.
//

#include <stdio.h>
#include "SLinkStructure.h"

/*
   - This function used to create new node's
   - it can have 2 casses
   - case#1  if head is NULL
   - case#2 if nead is not NULL
 */

SLINK *head = NULL;  // it's variable definition
// memeory will be created here for global variable

void createNewNode(void) {
    int value;
    
    if (head == NULL) {
        head = (SLINK*)malloc(sizeof(SLINK));   // new node is created and assigned address to head
        printf("\nEnter data: ");
        scanf("%d",&value);
        head -> data = value;
        head -> next = NULL;   //its the tail node
        
        return;
    }
    
    SLINK *th = head;
    while (th->next != NULL) {
        th = th -> next;
    }
    //when we are moving out of the loop...Can you tell me where th is pointing?????
    //th is pointing to tail node
    
    th->next = (SLINK*)malloc(sizeof(SLINK));
    printf("\nEnter data: ");
    scanf("%d",&value);
    th = th-> next;  // move to new node i.e. from 700 -> 800
    th -> data = value;
    th->next = NULL;
    th = NULL;
    
    return;
}
