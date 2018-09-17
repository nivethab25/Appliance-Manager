//
//  RefCount.cpp
//  ApplianceManager
//
//  Created by Nivetha Babu on 4/21/18.
//  Copyright © 2018 Nivetha Babu. All rights reserved.
//

#include "RefCount.hpp"

RefCount::RefCount(){
    count = 0;
}
void RefCount::addRef(){
    count++;
}

int RefCount::release(){
    return --count;
}
