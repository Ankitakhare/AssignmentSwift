//
//  main.c
//  BinaryTree
//
//  Created by ankita on 14/12/21.
//  Copyright © 2021 ankita. All rights reserved.
//

#include <stdio.h>
#include "BinaryTreeStructure.h"
#include <stdlib.h>

int main(int argc, const char * argv[]) {
    node *root = NULL;
    /*
     first create binary tree
            10
     30             20
   5    40        35    50
70
     */
    root = create();
    printf("\n Preorder traversal result: ");
    preOrder(root);
    
    printf("\n inOrder traversal result: ");
    inOrder(root);
    
    printf("\n Postorder traversal result: ");
    postOrder(root);
    
    free(root);
    return 0;
}
