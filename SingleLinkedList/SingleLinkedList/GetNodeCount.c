//
//  GetNodeCount.c
//  SingleLinkedList
//
//  Created by Balu Naik on 5/2/20.
//  Copyright © 2020 BaluTutorial. All rights reserved.
//

#include <stdio.h>
#include "SLinkStructure.h"

int getNodeCount() {
    
    if(head == NULL) {
        
        return  0;  // it's empty list
    }
    // if there are nodes
    SLINK *th = head;
    int count = 1;
    while (th->next != NULL) {
        ++count;
        th = th -> next;
    }
    // loop will be stop at tail node and count having final value
    
    return count;
}

int getNodeCountByRec( SLINK *th) {
    
    if(th == NULL) {
        
        return 0;
    }
    
    return 1 + getNodeCountByRec(th->next);
}
