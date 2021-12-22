//
//  SLinkStructure.h
//  SingleLinkedList
//
//  Created by Balu Naik on 5/2/20.
//  Copyright © 2020 BaluTutorial. All rights reserved.
//

#ifndef SLinkStructure_h
#define SLinkStructure_h

#include <stdlib.h>

struct SinleLinkedList {
    int data;
    struct SinleLinkedList *next;   // This is called self refereance
};

typedef struct SinleLinkedList SLINK;  // short name of structure(SLINK)

//extern SLINK *head = NULL;  //its root/head node (it's global so we can access in every file)
  // heade file should have only declaration of extern/global variables

extern SLINK *head;  // it's declaration of global variable
// declaration means doen't take any memeory


/* Function Declaration */
void createNewNode(void);
int getNodeCount(void);
int getNodeCountByRec( SLINK *th);
void displayNode(void);
void insertNode(void);
void deleteNode(void);
int searchNode(int kValue);
int detectLoop(SLINK *tempHead);


#endif /* SLinkStructure_h */



/*
   - When structure having a pointer of same type is called self reference structure
   - Why required?
   - Because every node will having address of next node and its also same type
   - If we take any other type of pointer then its not possible to manage elements properly
 */
