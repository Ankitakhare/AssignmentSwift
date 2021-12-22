//
//  InsertNode.c
//  SingleLinkedList
//
//  Created by ankita on 14/12/21.
//  Copyright © 2021 ankita. All rights reserved.
//
//
#include <stdio.h>
#include <stdlib.h>
#include "SCLinkStructure.h"

void insertNode() {
    
    if (head == NULL) {
        printf("\nList is empty..");
        
        return;
    }
    int kPosition, value, lp=1;
    SCLink *th;
    printf("\nEnter link position to insert: ");
    scanf("%d", &kPosition);
    
    if(kPosition == 1) { // We are inserting link at heade position
        th = (SCLink*)malloc(sizeof(SCLink));  //create new node
        th->next = head;              // new node next must be point to current heade
        printf("\nEnter data: ");
        scanf("%d",&value);
        th->data = value;
       //final step to doupdate tail node next pointerto new node
        head = th;      // move head to new node beacuse it's on top of listh
        th = th -> next;
        while (th -> next != head->next) {
             th = th -> next;
        }
        th ->next = head;
        th = NULL;
        return;
    }
    
    if (kPosition < 1 || kPosition > getNodeCount()) {
        printf("\nInvalid position: ");
        return;
    }
    th = head;
    while (lp < kPosition-1) {
        th = th -> next;
        ++lp;
    }
    // Now th is th is pointing to just before position i.e. kPosition-1
    
    SCLink *th2;
    th2 = (SCLink*)malloc(sizeof(SCLink));
    printf("\nEnter data: ");
    scanf("%d",&value);
    th2 -> data = value;
    th2 -> next = th -> next;  // new node pointing to next node in sequence
    th -> next = th2;          // pre-node should be point to new node
    th = th2 = NULL;  // just making temp pointer to null because all adjustments are done
    return;
}
