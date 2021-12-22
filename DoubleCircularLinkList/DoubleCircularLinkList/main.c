//
//  main.c
//  DoubleCircularLinkList
//
//  Created by pheonix on 10/05/20.
//  Copyright © 2020 pheonix. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "DoubleCircularStructure.h"

int main(int argc, const char * argv[]) {
    int option;
    while (1) {
        printf("\n1. For Create: ");
        printf("\n2. For Display: ");
        printf("\n3. For DisplayReverse: ");
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
                display();
                break;
            case 3:
                displayReverse();
                break;
            case 4:
                printf("\nTotal Count:%d", getCount());
                break;
            case 5:
                insertNode();
                break;
            case 6 :
                deletNode();
                break;
            case 7:
                if (isPalindrome()) {
                     printf("\nlist is in palindrome");
                }else{
                     printf("\nlist is not palindrome");
                }
                
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
