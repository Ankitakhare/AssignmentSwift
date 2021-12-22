//
//  DeleateNode.c
//  SingleLinkedList
//
//  Created by Balu Naik on 5/3/20.
//  Copyright © 2020 BaluTutorial. All rights reserved.
//

#include <stdio.h>
#include "SLinkStructure.h"


void deleteNode(void) {
    if (head == NULL) {
        printf("\nEmpty list: ");
        return;
    }
    int position, lp = 1;
    printf("\nEnter link position: ");
    scanf("%d",&position);
    SLINK *th, *th2;
    if (position == 1) {
        th = head;
        head = head -> next;
        th -> next = NULL;
        free(th);
        th = NULL;
        return;
    }
    th = head;
    while (lp< position -1) {
        th = th -> next;
        ++lp;
    }
    // th is pointing to just before kth - 1 node
    //take another pointer and assign kth node
    
    th2 = th -> next;
    th -> next = th2 -> next;
    th2 -> next = NULL;
    free(th2);
    return;
}
