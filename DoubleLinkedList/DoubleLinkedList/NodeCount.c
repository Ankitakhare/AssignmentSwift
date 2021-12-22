//
//  NodeCount.c
//  DoubleLinkedList
//
//  Created by Balu Naik on 5/3/20.
//  Copyright © 2020 BaluTutorial. All rights reserved.
//

#include <stdio.h>
#include "DoubleLinkStructure.h"

int getCount(void) {
    int count=0;
    if (head == NULL)
        return  0;
    
    DLINK *th = head;
    do {
        ++count;
        th = th -> next;
    } while (th != NULL);
    
    return count;
}
