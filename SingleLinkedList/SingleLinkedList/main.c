//
//  main.c
//  SingleLinkedList
//
//  Created by Balu Naik on 5/2/20.
//  Copyright © 2020 BaluTutorial. All rights reserved.
//

#include <stdio.h>
#include "SLinkStructure.h"

int main(int argc, const char * argv[]) {
    
    int option;
    while (1) {    //Always true
        printf("\n1.For create...");
        printf("\n2.For Display..");
        printf("\n3.Number of nodes: ");
        printf("\n4.Number of nodes(R): ");
        printf("\n5. Insert node: ");
        printf("\n6. Delete node: ");
        printf("\n7. Search element:");
        printf("\n8. Detect loop:");
        printf("\n10. For Exit...");
        printf("\nEnter option:");
        scanf("%d",&option);
        
        switch (option) {
            case 1:
                createNewNode();
                break;
            case 2:
                displayNode();
                break;
            case 3:
                printf("\nCount: %d",getNodeCount());
                break;
            case 4:
                printf("\nCount: %d",getNodeCountByRec(head));
                break;
            case 5:
                insertNode();
                break;
            case 6:
                deleteNode();
                break;
            case 7: {
                int value;
                printf("\nEnter value to search: ");
                scanf("%d",&value);
                if (searchNode(value)) {
                    printf("\n%d FOUND IN LIST", value);
                } else {
                    printf("\n%d NOT FOUND", value);
                }
                break;
            }
            case 8:
                //Hard code here to make loop but must request min of 5 nodes
                head -> next -> next -> next = head -> next;  //don't do this its for testing only
                if(detectLoop(head)) {
                    printf("\nFOUND LOOP");
                } else {
                    printf("\nNO LOOP FOUND");
                }
                break;
            case 10:
                free(head);
                head = NULL;
                return 0;
            default:
                break;
        }
    }
    
    return 0;
}
