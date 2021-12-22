//
//  EmpStructure.h
//  DoubleLinkedList
//
//  Created by Balu Naik on 5/3/20.
//  Copyright © 2020 BaluTutorial. All rights reserved.
//

#ifndef EmpStructure_h
#define EmpStructure_h

#include <stdio.h>

struct employee {
    unsigned empID;
    char empName[30];
    unsigned empSalary;
};

typedef struct employee EMP;


// Function Declaration
EMP getData(void);
void showData(EMP e);


#endif /* EmpStructure_h */
