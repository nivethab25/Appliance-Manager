//
//  Appliance.hpp
//  ApplianceManager
//
//  Created by Nivetha Babu on 4/17/18.
//  Copyright © 2018 Nivetha Babu. All rights reserved.
//

#ifndef Appliance_hpp
#define Appliance_hpp

#include "ApplianceType.hpp"
#include <string>
#include <vector>

using namespace std;

class Appliance {
protected:
    int id_;
    ApplianceType type_;
    string manufacturer_;
    float price_;
    vector<string> pictures_;
public:
    static int count;
    Appliance();
    Appliance (int id, ApplianceType type, string manufacturer,float price, vector<string> pictures);
    int getID_();
    ApplianceType getType_();
    string getManufacturer_();
    float getPrice_();
    void setPrice_(float);
    vector<string> getPictures_();
    Appliance& operator*();
};

#endif /* Appliance_hpp */
