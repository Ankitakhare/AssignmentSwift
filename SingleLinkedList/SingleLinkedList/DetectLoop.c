//
//  DetectLoop.c
//  SingleLinkedList
//
//  Created by Balu Naik on 5/3/20.
//  Copyright © 2020 BaluTutorial. All rights reserved.
//

#include <stdio.h>
#include "SLinkStructure.h"


int detectLoop(SLINK *tempHead) {
    SLINK *slowPtr, *fastPointer;
    // slow pointer move by 1 step
    // Fast pointer move by 2 step
    slowPtr = fastPointer = tempHead;  //pointing to 1st node
    while (slowPtr && fastPointer && fastPointer -> next) { // all are should not be NULL
        slowPtr = slowPtr -> next;   //Move by 1 step
        fastPointer = fastPointer -> next -> next;  //Move by 2 step
        if(slowPtr == fastPointer)
            return 1;
    }
    
    return  0;
}
