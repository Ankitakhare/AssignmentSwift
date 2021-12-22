//
//  main.c
//  DoubleLinkedList
//
//  Created by Balu Naik on 5/3/20.
//  Copyright © 2020 BaluTutorial. All rights reserved.
//

#include <stdio.h>
#include "DoubleLinkStructure.h"

int main(int argc, const char * argv[]) {
    int option;
    while (1) {
        printf("\n1. For Create: ");
        printf("\n2. For DisplayFL: ");
        printf("\n3. For DisplayLF: ");
        printf("\n4. For Count: ");
        printf("\n5. For Insert: ");
        printf("\n6. For Delete: ");
        printf("\n7. For Reverse: ");
        printf("\n8. For Exit: ");
        printf("\nEnter option: ");
        scanf("%d",&option);
        switch (option) {
            case 1:
                createNode();
                break;
            case 2:
                displayFL();
                break;
            case 3:
                displayLF();
                break;
            case 4:
                printf("\nTotal Count:%d", getCount());
                break;
            case 8:
                free(head);
                head = NULL;
                return 0;
            default:
                break;
        }
    }
    
    return 0;
}
