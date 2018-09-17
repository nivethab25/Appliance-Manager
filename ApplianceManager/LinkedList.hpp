//
//  LinkedList.hpp
//  ApplianceManager
//
//  Created by Nivetha Babu on 4/17/18.
//  Copyright © 2018 Nivetha Babu. All rights reserved.
//

#ifndef LinkedList_hpp
#define LinkedList_hpp

#include <iostream>
#include <stdlib.h>
#include "AppliancePtr.hpp"

using namespace std;
class LinkedList;

class Node{
    friend class LinkedList;
    friend ostream& operator<<(ostream&, LinkedList&);
protected:
    Node(int id);
    AppliancePtr elem;
    Node* next;
    
};

inline Node::Node(int id): elem(id), next(NULL){
    
}

class LinkedList{
    friend ostream& operator<<(ostream&, LinkedList&);
public:
    LinkedList();
    ~LinkedList();
    LinkedList& insert(int);
    AppliancePtr& find(int id);
    int remove();
    bool isEmpty();
protected:
    Node* front;
    Node* back;
    
};

inline bool LinkedList::isEmpty(){
    return front == NULL ? true: false;
}

#endif /* LinkedList_hpp */
