//
//  CreateNode.c
//  DoubleCircularLinkList
//
//  Created by pheonix on 10/05/20.
//  Copyright © 2020 pheonix. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "DoubleCircularStructure.h"


DCLINK *head = NULL;
void createNode(void) {
    if(head == NULL) {
        head = (DCLINK*)malloc(sizeof(DCLINK));
        head -> pre = head;
        head -> data = getData();  // calls emp getData()
        head -> next = head;
        return;
    }
    // create new noode and adjust its previous and next node information
    DCLINK *th;
    th = (DCLINK*)malloc(sizeof(DCLINK));
    // we have to adjust previous node and next node
    th -> pre = head -> pre;
    th -> data = getData();
    th -> next = head;
    // must be required to change previous node next and headnode previous value
    
    
    head -> pre -> next = th;
    head -> pre = th;
    return;
}
