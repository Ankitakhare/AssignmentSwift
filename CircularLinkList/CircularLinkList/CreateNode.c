//
//  CreateNode.c
//  SingleLinkedList
//
//  Created by ankita on 15/12/21.
//  Copyright © 2021 ankita. All rights reserved.
//
//

#include <stdio.h>
#include <stdlib.h>
#include "SCLinkStructure.h"

/*
   - This function used to create new node's
   - it can have 2 casses
   - case#1  if head is NULL
   - case#2 if nead is not NULL
 */

SCLink *head = NULL;  // it's variable definition
// memeory will be created here for global variable

void createNewNode(void) {
    int value;
    
    if (head == NULL) {
        head = (SCLink*)malloc(sizeof(SCLink));   // new node is created and assigned address to head
        printf("\nEnter data: ");
        scanf("%d",&value);
        head -> data = value;
        head -> next = head;   //its the tail node
        
        return;
    }
    
    SCLink *th = head;
    while (th ->next != head){
        th = th ->next;
    }
   
    //when we are moving out of the loop...Can you tell me where th is pointing?????
    //th is pointing to tail node
    
    th->next = (SCLink*)malloc(sizeof(SCLink));
    printf("\nEnter data: ");
    scanf("%d",&value);
    th = th-> next;  // move to new node i.e. from 700 -> 800
    th -> data = value;
    th->next = head;
    th = NULL;
    
    return;
}
