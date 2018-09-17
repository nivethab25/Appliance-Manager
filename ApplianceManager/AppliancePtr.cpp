//
//  AppliancePtr.cpp
//  ApplianceManager
//
//  Created by Nivetha Babu on 4/18/18.
//  Copyright © 2018 Nivetha Babu. All rights reserved.
//

#include "AppliancePtr.hpp"

using namespace std;

AppliancePtr::AppliancePtr(){
    
}

AppliancePtr::AppliancePtr(int id): id_(id), reference_(), pAppliance_(){
    
}

AppliancePtr::~AppliancePtr(){
    
    if(reference_->release()==0){
        pAppliance_->count--;
        delete pAppliance_;
        delete reference_;
    }

}

Appliance* AppliancePtr::loadFromFile(int id){
    string filename = to_string(id) + ".txt";
    ifstream file(filename);
    
    int iD;
    string strType;
    ApplianceType type = LAUNDRY_MACHINE;
    string manufacturer;
    string price;
    vector<string> pictures;
    
    if(!file.eof()){
    
    file>>iD;
    
    
    file>>strType;
    
    if(strType.compare("LAUNDRY_MACHINE") == 0)
        type = LAUNDRY_MACHINE;
    if(strType.compare("DISH_WASHER") == 0)
        type = DISH_WASHER;
    if(strType.compare("DRYER") == 0)
        type = DRYER;
    
   
    file>>manufacturer;
    
   
    file>>price;
    
    streamoff currPos = file.tellg();
    currPos++;
    streampos nextPos = currPos;
    file.seekg(nextPos);
    file.seekg(nextPos,file.end);
    streamoff length = file.tellg();
    file.seekg(nextPos);
    
    string picturesWithSpaces;
    char* buffer = new char[length];
    file.read(buffer, length);
    picturesWithSpaces = buffer;
    
    
    size_t pos = 0, found;
    while ((found = picturesWithSpaces.find_first_of(' ', pos)) != string::npos) {
        pictures.push_back(picturesWithSpaces.substr(pos, found - pos));
        pos = found+1;
    }
    pictures.push_back(picturesWithSpaces.substr(pos));
    
    pAppliance_ = new Appliance(id, type, manufacturer, stof(price), pictures);
    reference_ = new RefCount();
    reference_->addRef();
    }
    
    return pAppliance_;
    
}

Appliance& AppliancePtr::operator*(){
    if(pAppliance_ == NULL)
        pAppliance_ = loadFromFile(id_);
        return *pAppliance_;
}

Appliance* AppliancePtr::operator->(){
    if(pAppliance_ == NULL){
            pAppliance_ = loadFromFile(id_);
        
    }
    
    return pAppliance_;
}

int AppliancePtr::getId(){
    return id_;
}
