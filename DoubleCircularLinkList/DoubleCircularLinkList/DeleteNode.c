//
//  DeleteNode.c
//  DoubleCircularLinkList
//
//  Created by pheonix on 10/05/20.
//  Copyright © 2020 pheonix. All rights reserved.
//

#include <stdio.h>
#include "DoubleCircularStructure.h"


void deletNode(void) {
    
    if(head == NULL)
        return;   //Empty no operation

    int lp;
    printf("\nEnter link position: ");
    scanf("%d",&lp);
    if(lp < 1 || lp > getCount()) {
        printf("\nInvalid position");
        return;
    }
    DCLINK *th1, *th2 = NULL;
    if (lp == 1) { // case#2
        th1 = head;
        head = head -> next;
        head -> pre = th1 -> pre;
        head -> pre -> next = head;
        th1 -> pre = NULL;
        th1 -> next = NULL;
        free(th1);
        return;
    }
    
    
    
    if (lp <= getCount() / 2) {
        th1 = head;
        for (int i  = 1; i < lp - 1; i++)
            th1 = th1 -> next;
           th2 = th1 -> next;
            th1 -> next = th2 -> next;
            //th2 -> data = getData();
            th2 -> pre -> next = th1;
            th2 -> pre = NULL;
            th2 -> next = NULL;
          
        free(th2);
        th2 = NULL;
        
            
        
    }else{
        th1 = head ->pre;
        for (int i  = lp ; i < getCount() - 1; i++)
            th1 = th1 -> pre;
        if (lp == getCount()) {
            head -> pre = th1 -> pre;
            th1->pre -> next = head;
            th1 -> pre = NULL;
            th1 -> next = NULL;
            free(th1);
            th1 = NULL;
            return;
        }
        
            th2 = th1 -> pre;
            th2 -> pre = th2 -> next;
            th2-> next -> pre = th2 -> pre;
            th2 -> next = NULL;
            th2 -> pre = NULL;
            free(th2);
            th2 = NULL;
        
        
    }
    return;
    
}
