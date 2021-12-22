//
//  main.c
//  pointerDataAccess
//
//  Created by Balu Naik on 4/25/20.
//  Copyright © 2020 BaluTutorial. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int iValue = 10;
    int *iPtr;
    
    float fValue = 12.3;
    float *fPtr;
    
    char ch ='B';
    char *cptr;
    
    iPtr = &iValue;  // Assigning int variable address into integer pointer
    
    fPtr = &fValue;   // Assigning float variable address into float pointer
    
    cptr = &ch;   // Assigning char variable address into char pointer
    
    printf("%d %f %c\n", *iPtr, *fPtr, *cptr);
    
    return 0;
}
