//
//  LinkedList.cpp
//  ApplianceManager
//
//  Created by Nivetha Babu on 4/17/18.
//  Copyright © 2018 Nivetha Babu. All rights reserved.
//

#include "LinkedList.hpp"

LinkedList::LinkedList(){
    front = NULL;
    back = NULL;
}

LinkedList::~LinkedList(){
    while (!isEmpty()) {
        remove();
    }
}

LinkedList& LinkedList::insert(int id){
    Node* pNode = new Node(id);
    if(isEmpty())
        front = back = pNode;
    else{
        back->next = pNode;
        back = pNode;
    }
    return *this;
}

AppliancePtr& LinkedList::find(int id){
    if(isEmpty()){
        cerr<<"LinkedList is empty!!";
        exit(0);
    }
    Node* itr = front;
    while(!isEmpty()){
        Node* pNode = itr;
        itr = itr->next;
        
        if(pNode->elem.getId() == id){
            return pNode->elem;
        }
    }
    return front->elem;
}

int LinkedList::remove(){
    if(isEmpty()){
        cerr<<"LinkedList is empty!!";
        exit(0);
    }
    
        Node* pNode = front;
        front = front->next;
        
    delete pNode;
    return front->elem.getId();
    
}
