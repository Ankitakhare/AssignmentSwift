//
//  Palindrome.c
//  DoubleCircularLinkList
//
//  Created by pheonix on 10/05/20.
//  Copyright © 2020 pheonix. All rights reserved.
//

#include <stdio.h>
#include "DoubleCircularStructure.h"

int isPalindrome(void){
    
    DCLINK *forPointer, *backPointer;
    forPointer = head;
    backPointer = head -> pre;
    if (backPointer == forPointer)
        return 0;
    while (forPointer !=  backPointer) {
        if ((forPointer ->data).empID != (backPointer ->data).empID ) {
            return 0;
        }
        forPointer = forPointer -> next ;
        backPointer = backPointer -> pre;
        
    }
    return 1;
}
