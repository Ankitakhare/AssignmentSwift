//
//  insertNode.c
//  DoubleCircularLinkList
//
//  Created by pheonix on 10/05/20.
//  Copyright © 2020 pheonix. All rights reserved.
//

#include <stdio.h>
#include "DoubleCircularStructure.h"

void insertNode(void) {
   if (head == NULL)
       return;    // No operation beacuse list is empty
  
   int lp;
   printf("\nEnter link position: ");
   scanf("%d",&lp);
   if (lp<1 || lp > getCount()) {   // Noode position validation
       printf("\nInvalid lisnk position");
       return;
   }
   DCLINK *th1,*th2;
   if (lp == 1) {   //case#2 insert new node at head position
       th1 = (DCLINK*)malloc(sizeof(DCLINK));   //new node created
       th1 -> pre = head -> pre;
       th1 -> data = getData();
       th1 -> next = head;     //it will point to next node in list
       
       head -> pre = th1;     //pre node should point back to new node
       head -> pre ->next = th1; // tail is pointing back to head
       
       head = th1;
       return;
   }
    
    
    if (lp <= getCount() / 2) {
        th1 = head;
        for (int i  = 1; i < lp - 1; i++)
            th1 = th1 -> next;
            th2 = (DCLINK*)malloc(sizeof(DCLINK));
            th2 -> pre = th1 -> next;
            th2 -> data = getData();
            th2 -> next = th1 -> next -> next;
            th2 -> pre -> next = th2;
            th2 -> next -> pre = th2;
           
            
        
    }else{
        th1 = head ->pre;
        for (int i  = lp ; i < getCount() - 1; i++)
            th1 = th1 -> pre;
        th2 = (DCLINK*)malloc(sizeof(DCLINK));
        th2 -> pre = th1 -> pre -> pre;
        th2 -> data = getData();
        th2 -> next = th1 -> pre;
        
        th2 -> pre ->next = th2;
        th1 -> pre -> pre = th2;
        
    }
  
    return;
}
