//
//  SCLinkStructure.h
//  CircularLinkList
//
//  Created by ankita on 14/12/21.
//  Copyright © 2021 ankita. All rights reserved.
//


#ifndef SCLinkStructure_h
#define SCLinkStructure_h

#include <stdio.h>

struct SingleCircularLinkList {
    int data;
    struct SingleCircularLinkList *next;
    
};
typedef struct SingleCircularLinkList SCLink;
//extern SLink *head = NULL; //its root  head node its global so we can access in everyfile
// headed file should have only declaration of extern or global variable
extern SCLink *head;
/*  Function Declaration*/

void createNewNode(void);
int getNodeCount(void);
void displayNode(void);
void insertNode(void);
void deleteNode(void);




#endif /* SCLinkStructure_h */
