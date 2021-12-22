//
//  searchNode.c
//  SingleLinkedList
//
//  Created by Balu Naik on 5/3/20.
//  Copyright © 2020 BaluTutorial. All rights reserved.
//

#include <stdio.h>
#include "SLinkStructure.h"

int searchNode(int kValue) {
    if (head == NULL)
        return 0;   // false
    SLINK *th = head;
    while (th != NULL) {
        if(th -> data == kValue)
            return 1;   // true
        th = th-> next;
    }
    
    return 0;
}


SLINK*searchNodeAddress() {
    if (head == NULL)
        return NULL;
    SLINK *th = head;
    int lp = 1;
    
    while (lp < getNodeCount() - 1) {
        th = th-> next;
        ++lp;
    }
    
    return th;
}
