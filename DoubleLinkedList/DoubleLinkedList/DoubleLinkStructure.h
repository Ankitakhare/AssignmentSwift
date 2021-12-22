//
//  DoubleLinkStructure.h
//  DoubleLinkedList
//
//  Created by Balu Naik on 5/3/20.
//  Copyright © 2020 BaluTutorial. All rights reserved.
//

#ifndef DoubleLinkStructure_h
#define DoubleLinkStructure_h

#include <stdlib.h>
#include "EmpStructure.h"

struct DoubleLinkStructure {
    struct DoubleLinkStructure *pre;
    //int data;
    EMP data;
    struct DoubleLinkStructure *next;
};

typedef struct DoubleLinkStructure DLINK;

extern DLINK *head;


// Function declaration
void createNode(void);
int getCount(void);
void displayFL(void);
void displayLF(void);
void insertNode(void);
void deletNode(void);
void reverNode(void);


#endif /* DoubleLinkStructure_h */
