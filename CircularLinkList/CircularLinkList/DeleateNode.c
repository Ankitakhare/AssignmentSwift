//
//  DeleateNode.c
//  SingleLinkedList
//
//  Created by ankita on 14/12/21.
//  Copyright © 2021 ankita. All rights reserved.
//
//

#include <stdio.h>
#include "SCLinkStructure.h"
#include <stdlib.h>

void deleteNode(void) {
    if (head == NULL) {
        printf("\nEmpty list: ");
        return;
    }
    int position, lp = 1;
    printf("\nEnter link position: ");
    scanf("%d",&position);
    SCLink *th, *th2;
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
