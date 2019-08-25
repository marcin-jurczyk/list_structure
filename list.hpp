//
//  list.hpp
//  Lista na strukturze
//
//  Created by Marcin Jurczyk on 14/07/2019.
//  Copyright © 2019 Marcin Jurczyk. All rights reserved.
//

#include <iostream>
using namespace std;

struct node {
    double val;
    node *next;
    node *prev;
};

struct list {
    node *head;
    node *tail;
    void print();
    int size();
    void loadRandomInteger(int a, int b, int n); // n - ilosc liczb, a - przedzial dolny, b - przedzial gorny
    void addHead(double x);
    void addTail(double x);
    void deleteHead();
    void deleteTail();
    int sum();
    node* get(int index);
    int numberOfRepetitions(double x);
    int* findByValue(double x);
    double findByIndex(int index); // indeksy - |0|1|2|3|...|
    void replaceByValue(double x, double y);
    void replaceByIndex(int index, double y);
    void insert(int index, double y);
    void remove(int index);
    void swapNeighbours(node *temp1, node *temp2);
    void swapNotNeighbours(node *temp1, node *temp2);
    void swapByIndex(int index1, int index2);
    void swap(node *temp1, node *temp2);
    
    void bubbleSort();
    void insertSort();
    void selectionSort();
    
};
