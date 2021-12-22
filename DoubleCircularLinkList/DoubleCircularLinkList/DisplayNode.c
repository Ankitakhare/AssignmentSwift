//
//  DisplayNode.c
//  DoubleCircularLinkList
//
//  Created by pheonix on 10/05/20.
//  Copyright © 2020 pheonix. All rights reserved.
//

#include <stdio.h>
#include "DoubleCircularStructure.h"

void display(void) {
    if (head == NULL) {
        printf("\nList is empty!!!");
        return;
    }
    DCLINK *th = head;
    do {
        showData(th -> data);
        th = th -> next;
    } while (th!= head);
    
    return;
}

void displayReverse(void) {
    if (head == NULL) {
        printf("\nList is empty!!!");
        return;
    }
    
    DCLINK *th = head -> pre;
    do {
        showData(th -> data);
        th = th -> pre;
    } while (th != head -> pre);
    
    return;
}
