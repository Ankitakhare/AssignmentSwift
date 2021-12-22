//
//  DisplayNode.c
//  SingleLinkedList
//
//  Created by Balu Naik on 5/2/20.
//  Copyright © 2020 BaluTutorial. All rights reserved.
//

#include <stdio.h>
#include "SLinkStructure.h"

void displayNode() {
    
    if (head == NULL) {
        printf("\nLIST IS EMPTY: ");
        
        return;
    }
    // if heade is not NULL then
    // take th and travel untill end
    SLINK *th = head;
    do {
        printf("%d ", th->data);
        th = th -> next;
    } while (th != NULL);
    
    return;
}
