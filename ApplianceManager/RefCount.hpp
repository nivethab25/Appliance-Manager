//
//  RefCount.hpp
//  ApplianceManager
//
//  Created by Nivetha Babu on 4/21/18.
//  Copyright © 2018 Nivetha Babu. All rights reserved.
//

#ifndef RefCount_hpp
#define RefCount_hpp

#include <stdio.h>

class RefCount{
private:
    int count;
public:
    RefCount();
    void addRef();
    int release();
};

#endif /* RefCount_hpp */
