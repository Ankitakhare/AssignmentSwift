//
//  main.c
//  BinarySearchTree
//
//  Created by ankita on 13/12/21.
//  Copyright © 2021 ankita. All rights reserved.


#include <stdio.h>
#include <stdlib.h>
#include "BinaryTreeStructure.h"

int main(int argc, const char * argv[]) {
    int option, num;
    node *root = NULL;
    node *temp;
     int key;
    while (1) {
        printf("\n 1  for insert node in BSR");
         printf("\n 2  Preorder");
         printf("\n 3  postorder");
         printf("\n 4  inorder");
          printf("\n 5  file search ");
         printf("\n 6 Exit");
        scanf("%d",&option);
        switch (option) {
            case 1:
                printf("\n enter data: ");
                scanf("%d",&num);
                insert(&root, num);
                break;
            case 2:
                printf("\n preorder");
                preOrder(root);
                break;
            case 3:
                printf("\n post order");
                postOrder(root);
                break;
            case 4:
                printf("\n in order");
                inOrder(root);
                break;
                
           case 5:
               
                printf("\n enter the key");
                scanf("%d",&key);
                temp = search(root, key);
                if (temp != NULL) {
                    printf("\n key found at loaction temp %p",temp);
                }else{
                     printf("\n key not found");
                }
                break;
          case 6:
                free(root);
                return 0;
                default:
                printf("\n envalid option....");
                break;
        }
    }
    return 0;
}
