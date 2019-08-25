//
//  main.cpp
//  Lista na strukturze
//
//  Created by Marcin Jurczyk on 14/07/2019.
//  Copyright © 2019 Marcin Jurczyk. All rights reserved.
//
#include <iostream>
#include "list.hpp"
using namespace std;

int main() {
    srand((unsigned int)time(NULL));
    
    list l;
    l.head = NULL;
    l.tail = NULL;
    l.loadRandomInteger(0, 9, 10);
  
    l.print();
    l.bubbleSort();
    l.print();    
}
