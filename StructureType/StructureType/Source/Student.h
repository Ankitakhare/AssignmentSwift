//
//  Student.h
//  StructureType
//
//  Created by Balu Naik on 4/26/20.
//  Copyright © 2020 BaluTutorial. All rights reserved.
//

#ifndef Student_h
#define Student_h

#include <stdio.h>

/* Structure Declaration */

struct Student {
    int rollNumber;
    char name[50];
    unsigned marks;
};

/* Creating Alias name */
typedef struct Student Student;

/* Function Declaration */
Student getStudentDetails(void);
void showStudentsDetaisl(Student s);

#endif /* Student_h */
