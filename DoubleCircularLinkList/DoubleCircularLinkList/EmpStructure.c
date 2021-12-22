//
//  EmpStructure.c
//  DoubleLinkedList
//
//  Created by Balu Naik on 5/3/20.
//  Copyright © 2020 BaluTutorial. All rights reserved.
//

#include "EmpStructure.h"
#include <stdlib.h>
#include <string.h>

EMP getData(void) {
    EMP temp;
    printf("\nEnter ID: ");
    scanf("%u",&temp.empID);
    printf("\nEnter Name: ");
    fflush(stdin);
    fgets(temp.empName, 29, stdin);
    unsigned charCount = strlen(temp.empName);
    temp.empName[charCount - 1] = '\0';
    printf("\nEnter Salary: ");
    scanf("%u",&temp.empSalary);
    
    return  temp;
}

void showData(EMP e) {
    printf("\n ID: %u NAME:%s SALARY:%u", e.empID, e.empName, e.empSalary);
}
