//
//  DoubleCircularStructure.h
//  DoubleCircularLinkList
//
//  Created by pheonix on 10/05/20.
//  Copyright © 2020 pheonix. All rights reserved.
//

#ifndef DoubleCircularStructure_h
#define DoubleCircularStructure_h
#include <stdlib.h>
#include "EmpStructure.h"

struct DoubleCircularStructure {
    struct DoubleCircularStructure *pre;
    //int data;
    EMP data;
    struct DoubleCircularStructure *next;
};

typedef struct DoubleCircularStructure DCLINK;

extern DCLINK *head;


// Function declaration
void createNode(void);
int getCount(void);
void display(void);
void displayReverse(void);
void insertNode(void);
void deletNode(void);
int isPalindrome(void);



#endif /* DoubleCircularStructure_h */
