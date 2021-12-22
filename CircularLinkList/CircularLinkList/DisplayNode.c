//
//  DisplayNode.c
//  SingleLinkedList
//
//  Created by ankita on 14/12/21.
//  Copyright © 2021 ankita. All rights reserved.
//
//
#include <stdio.h>
#include "SCLinkStructure.h"

void displayNode() {
    
    if (head == NULL) {
        printf("\nLIST IS EMPTY: ");
        
        return;
    }
    // if heade is not NULL then
    // take th and travel untill end
    SCLink *th = head;
    do {
        printf("%d ", th->data);
        th = th -> next;
    } while (th != head);
    
    return;
}
