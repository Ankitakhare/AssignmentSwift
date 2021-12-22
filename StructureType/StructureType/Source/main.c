//
//  main.c
//  StructureType
//
//  Created by Balu Naik on 4/26/20.
//  Copyright © 2020 BaluTutorial. All rights reserved.
//

#include <stdio.h>
#include "Student.h"

int main(int argc, const char * argv[]) {
    
    Student s1;  //variable creating
    
    s1 = getStudentDetails();
    showStudentsDetaisl(s1);
    
  
    return 0;
}
// In iOS c version (C99) we have to declare any function before it use
 
