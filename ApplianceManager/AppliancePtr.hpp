//
//  AppliancePtr.hpp
//  ApplianceManager
//
//  Created by Nivetha Babu on 4/18/18.
//  Copyright © 2018 Nivetha Babu. All rights reserved.
//

#ifndef AppliancePtr_hpp
#define AppliancePtr_hpp

#include <stdio.h>
#include "Appliance.hpp"
#include "RefCount.hpp"
#include <fstream>

class AppliancePtr{
protected:
    int id_;
    RefCount* reference_;
    Appliance* pAppliance_;
    Appliance* loadFromFile(int);
    AppliancePtr(const AppliancePtr&);
    AppliancePtr& operator=(const AppliancePtr&);
public:
    AppliancePtr();
    AppliancePtr(int);
    ~AppliancePtr();
    int getId();
    Appliance* operator->();
    Appliance& operator*();
};

#endif /* AppliancePtr_hpp */
