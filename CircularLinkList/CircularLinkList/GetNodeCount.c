//
//  GetNodeCount.c
//  SingleLinkedList
//
//  Created by ankita on 14/12/21.
//  Copyright © 2021 ankita. All rights reserved.
//
//

#include <stdio.h>
#include "SCLinkStructure.h"

int getNodeCount() {
    
    if(head == NULL) {
        
        return  0;  // it's empty list
    }
    // if there are nodes
    SCLink *th = head;
    int count = 1;
    while (th->next != head) {
        ++count;
        th = th -> next;
    }
    // loop will be stop at tail node and count having final value
    
    return count;
}

int getNodeCountByRec( SCLink *th) {
    
    if(th == NULL) {
        
        return 0;
    }
    
    return 1 + getNodeCountByRec(th->next);
}
