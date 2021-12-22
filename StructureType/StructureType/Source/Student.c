//
//  Student.c
//  StructureType
//
//  Created by Balu Naik on 4/26/20.
//  Copyright © 2020 BaluTutorial. All rights reserved.
//

#include "Student.h"

/* - This function used for printing data on console
   - it takes a parameter of type Student
   - From any user define type if we accessing data we have to use .(dot) operator
   - Like variable.memebr
   - if variable is pointer type we should use -> (arrow) operator
   - Like pointe -> memebr
 */

void showStudentsDetaisl(Student s) {
    printf("\n Rool Number: %d Name:%s Marks:%u", s.rollNumber, s.name, s.marks);
}

/*
 - This function used to set student data
 - This function will tae input values from use and pass back to calling location
 */

Student getStudentDetails() {
    Student temp;
    printf("\nEnter Roll Number: ");
    scanf("%d",&temp.rollNumber);
    printf("\nEnter Name: ");
    fflush(stdin);
    //gets(temp.name);
    fgets(temp.name, 49, stdin);
    // stdin standed input buffer
    // stdout output buffer
    /* warning: this program uses gets(), which is unsafe.
     it will not read every thing and no upper limit check
     */
    printf("\nEnter Marks: ");
    scanf("%u", &temp.marks);
    
    return temp;
}

