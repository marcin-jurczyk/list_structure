//
//  list.cpp
//  Lista na strukturze
//
//  Created by Marcin Jurczyk on 14/07/2019.
//  Copyright © 2019 Marcin Jurczyk. All rights reserved.
//

#include <iostream>
#include "list.hpp"
using namespace std;

void list::print()
{
    node *temp = head;
    while (temp != NULL) {
        if (temp -> next == NULL)
            cout << temp -> val << endl;
        else
            cout << temp -> val << " | ";
        temp = temp -> next;
    }
    cout << "Head: " << head -> val << endl
    << "Tail: " << tail -> val << endl;
}

int list::size()
{
    node *temp = head;
    int iter = 0;
    while (temp) {
        iter++;
        temp = temp -> next;
    }
    return iter;
}

void list::loadRandomInteger(int a, int b, int n)
{
    for (int i = 0; i < n; i++) {
        addHead(rand()%(b-a+1)+a);
    }
}

void list::addHead(double x)
{
    node *temp = new node;
    temp -> val = x;
    if (head == NULL) {
        temp -> next = NULL;
        temp -> prev = NULL;
        head = temp;
        tail = head;
    }
    else {
        temp -> next = head;
        temp -> prev = NULL;
        head -> prev = temp;
        head = temp;
    }
}

void list::addTail(double x)
{
    node *temp = new node;
    temp -> val = x;
    if (head == NULL) {
        temp -> next = NULL;
        temp -> prev = NULL;
        tail = temp;
        head = tail;
    }
    else {
        temp -> next = NULL;
        temp -> prev = tail;
        tail -> next = temp;
        tail = temp;
    }
}

void list::deleteHead()
{
    if (head == tail)
        delete head;
    else {
        head = head -> next;
        delete head -> prev;
        head -> prev = NULL;
    }
}

void list::deleteTail()
{
    if (head == tail)
        delete tail;
    else {
        tail = tail -> prev;
        delete tail -> next;
        tail -> next = NULL;
    }
}

int list::sum()
{
    node *temp = head;
    int x = 0;
    while (temp) {
        temp = temp -> next;
        x++;
    }
    return x;
}

int list::numberOfRepetitions(double x) {
    int iter = 0;
    node *temp = head;
    while (temp) {
        if (temp -> val == x) iter++;
        temp = temp -> next;
    }
    return iter;
}

int* list::findByValue(double x) {
    list ltemp;
    ltemp.head = NULL;
    ltemp.tail = NULL;
    node *temp = head;
    for (int i = 0; i < size(); i++) {
        if (temp -> val == x) ltemp.addTail(i);
        temp = temp -> next;
    }
    temp = ltemp.head;
    if (ltemp.size() != 0) {
        int *tab = new int[ltemp.size()];
        for (int i = 0; i < ltemp.size(); i++) {
            tab[i] = temp -> val;
            temp = temp -> next;
        }
        return tab;
    } else return NULL;
}

double list::findByIndex(int index)
{
    if (index >= 0 && index < size()) {
        node *temp = head;
        for (int i = 0; i < index; i++) {
            temp = temp -> next;
        }
        return temp -> val;
    }
    else cout << "Out of range";
    return NULL;
}

node* list::get(int index)
{
    if (index >= 0 && index < size()) {
        node *temp = head;
        for (int i = 0; i < index; i++) {
            temp = temp -> next;
        }
        return temp;
    }
    else cout << "Out of range";
    return NULL;
}

void list::replaceByValue(double x, double y)
{
    node *temp = head;
    for (int i = 0; i < size(); i++) {
        if (temp -> val == x) temp -> val = y;
        temp = temp -> next;
    }
}

void list::replaceByIndex(int index, double y)
{
    if (index >= 0 && index < size()) {
        node *temp = head;
        for (int i = 0; i < index; i++) temp = temp -> next;
        temp -> val = y;
    } else cout << "Out of range" << endl;
}

void list::insert(int index, double y) {
    if (index >= 0 && index < size()) {
        node *temp = head;
        node *newNode = NULL;
        newNode -> val = y;
        for (int i = 0; i < index - 1; i++) temp = temp -> next;
        newNode -> next = temp -> next;
        temp -> next = newNode;
    } else cout << "Out of range" << endl;
}

void list::remove(int index) {
    if (index >= 0 && index < size()) {
        node *temp = head;
        for (int i = 0; i < index; i++) temp = temp -> next;
        temp -> prev -> next = temp -> next;
        temp -> next -> prev = temp -> prev;
        //return temp -> val;
        delete temp;
    } else cout << "Out of range" << endl;
}

void list::swapNeighbours(node *temp1, node *temp2)
{
    if (temp1 != temp2) {
        temp1 -> next = temp2 -> next;
        temp2 -> prev = temp1 -> prev;
        temp1 -> prev = temp2;
        if (temp2 == tail) tail = temp1;
        else temp1 -> next -> prev = temp1;
        temp2 -> next = temp1;
        if (temp1 == head) head = temp2;
        else temp2 -> prev -> next = temp2;
    }
}

void list::swapNotNeighbours(node *temp1, node *temp2)
{
    if (temp1 != temp2) {
        node *temp = new node;
        temp -> next = temp1 -> next;
        temp -> prev = temp1 -> prev;
        
        temp1 -> next = temp2 -> next;
        temp1 -> prev = temp2 -> prev;
        temp1 -> prev -> next = temp1;
        if (temp2 == tail) tail = temp1;
        else temp1 -> next -> prev = temp1;
        
        temp2 -> next = temp -> next;
        temp2 -> prev = temp -> prev;
        temp2 -> next -> prev = temp2;
        if (temp1 == head) head = temp2;
        else temp2 -> prev -> next = temp2;
        
        delete temp;
    }
}

void list::swapByIndex(int index1, int index2)
{
    if (index1 >= 0 && index2 >= 0 && index2 < size() && index2 < size()) {
        if (index1 > index2) {
            int t = index1;
            index1 = index2;
            index2 = t;
        }
        node *temp1 = head;
        node *temp2 = head;
        for (int i = 0; i < index1; i++) temp1 = temp1 -> next;
        for (int i = 0; i < index2; i++) temp2 = temp2 -> next;
        
        if (temp1 -> next == temp2) swapNeighbours(temp1, temp2);
        else swapNotNeighbours(temp1, temp2);
    
    } else cout << "Out of range" << endl;
}

// temp1 - element wczesniejszy
void list::swap(node *temp1, node *temp2)
{
    if (temp1 -> next == temp2) swapNeighbours(temp1, temp2);
    else swapNotNeighbours(temp1, temp2);
}

void list::bubbleSort()
{
    node *temp = head -> next;
    for (int i = 0; i < size(); i++) {
        while (temp) {
            if (temp -> val < temp -> prev -> val) {
                swapNeighbours(temp -> prev, temp);
                temp = temp -> next;
            }
            //if (i == 0) print();
            temp = temp -> next;
        }
        temp = head -> next;
    }
}

void list::insertSort()
{
    node *key = head;
    node *temp;
    for (int i = 1; i < size(); i++) {
        key = get(i);
        temp = key -> prev;
        if (temp -> val > key -> val) {
            if (key -> next) {
                key -> next -> prev = temp;
                temp -> next = key -> next;
            }
            else {
                temp -> next = NULL;
                tail = temp;
            }
            while (temp -> val > key -> val) {
                if (temp -> prev) temp = temp -> prev;
                else {
                    temp = NULL;
                    break;
                }
            }
            if (temp == NULL)
            {
                head -> prev = key;
                key -> next = head;
                key -> prev = NULL;
                head = key;
            }
            else {
                key -> next = temp -> next;
                temp -> next -> prev = key;
                temp -> next = key;
                key -> prev = temp;
            }
        }
    }
}

void list::selectionSort()
{
    node* temp1 = head;
    node* temp2 = head;
    node* min = NULL;
    for (int i = 1; i < size(); i++) {
        temp2 = temp1 -> next;
        min = temp1;
        while (temp2) {
            if (temp2 -> val < min -> val) {
                min = temp2;
            }
            temp2 = temp2 -> next;
        }
        swap(temp1, min);
        temp1 = get(i);
    }
}



