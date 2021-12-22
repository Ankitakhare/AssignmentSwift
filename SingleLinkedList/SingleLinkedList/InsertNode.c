//
//  InsertNode.c
//  SingleLinkedList
//
//  Created by Balu Naik on 5/2/20.
//  Copyright © 2020 BaluTutorial. All rights reserved.
//

#include <stdio.h>
#include "SLinkStructure.h"

void insertNode() {
    
    if (head == NULL) {
        printf("\nList is empty..");
        
        return;
    }
    int kPosition, value, lp=1;
    SLINK *th;
    printf("\nEnter link position to insert: ");
    scanf("%d", &kPosition);
    
    if(kPosition == 1) { // We are inserting link at heade position
        th = (SLINK*)malloc(sizeof(SLINK));  //create new node
        th->next = head;              // new node next must be point to current heade
        printf("\nEnter data: ");
        scanf("%d",&value);
        th->data = value;
        head = th;      // move head to new node beacuse it's on top of list
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
    
    SLINK *th2;
    th2 = (SLINK*)malloc(sizeof(SLINK));
    printf("\nEnter data: ");
    scanf("%d",&value);
    th2 -> data = value;
    th2 -> next = th -> next;  // new node pointing to next node in sequence
    th -> next = th2;          // pre-node should be point to new node
    th = th2 = NULL;  // just making temp pointer to null because all adjustments are done
    return;
}
