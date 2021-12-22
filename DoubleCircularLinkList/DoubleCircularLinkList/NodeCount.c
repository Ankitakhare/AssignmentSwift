//
//  NodeCount.c
//  DoubleCircularLinkList
//
//  Created by pheonix on 10/05/20.
//  Copyright © 2020 pheonix. All rights reserved.
//

#include <stdio.h>
#include "DoubleCircularStructure.h"

int getCount(void) {
    int count=0;
    if (head == NULL)
        return  0;
    
    DCLINK *th = head;
    do {
        ++count;
        th = th -> next;
    } while (th != head);
    
    return count;
}
