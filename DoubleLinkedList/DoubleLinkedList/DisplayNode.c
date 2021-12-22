//
//  DisplayNode.c
//  DoubleLinkedList
//
//  Created by Balu Naik on 5/3/20.
//  Copyright © 2020 BaluTutorial. All rights reserved.
//

#include <stdio.h>
#include "DoubleLinkStructure.h"

void displayFL(void) {
    if (head == NULL) {
        printf("\nList is empty!!!");
        return;
    }
    DLINK *th = head;
    do {
        showData(th -> data);
        th = th -> next;
    } while (th!= NULL);
    
    return;
}

void displayLF(void) {
    if (head == NULL) {
        printf("\nList is empty!!!");
        return;
    }
    
    DLINK *th = head;
    while (th-> next != NULL)
        th = th -> next;
    // after loop th points to tail position
    
    // start traveling in revers order
    do {
        showData(th -> data);
        th = th -> pre;
    } while (th != NULL);
    
    return;
}
