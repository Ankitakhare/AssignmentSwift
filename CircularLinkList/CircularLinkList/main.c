//
//  main.c
//  SingleLinkedList
//
//  Created by ankita on 14/12/21.
//  Copyright © 2021 ankita. All rights reserved.
//
//

#include <stdio.h>
#include "SLinkStructure.h"

int main(int argc, const char * argv[]) {
    
    int option;
    while (1) {    //Always true
        printf("\n1.For create...");
        printf("\n2.For Display..");
        printf("\n3.Number of nodes: ");
      
        printf("\n4. Insert node: ");
        printf("\n5. Delete node: ");
       
   
        printf("\n6. For Exit...");
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
                insertNode();
                break;
            case 5:
                deleteNode();
                break;
            
            case 6:
                free(head);
                head = NULL;
                return 0;
            default:
                break;
        }
    }
    
    return 0;
}
