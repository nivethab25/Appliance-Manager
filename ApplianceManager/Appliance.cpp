//
//  Appliance.cpp
//  ApplianceManager
//
//  Created by Nivetha Babu on 4/17/18.
//  Copyright © 2018 Nivetha Babu. All rights reserved.
//

#include "Appliance.hpp"

int Appliance::count = 0;

Appliance::Appliance() {
    
}

Appliance::Appliance (int id, ApplianceType type, string manufacturer,float price, vector<string> pictures): id_(id), type_(type), manufacturer_(manufacturer), price_(price), pictures_(pictures){
    count++;
}

int Appliance::getID_(){
    return id_;
}

ApplianceType Appliance::getType_(){
    return type_;
}

string Appliance::getManufacturer_(){
    return manufacturer_;
}

float Appliance::getPrice_(){
    return price_;
}

void Appliance::setPrice_(float price){
    price_= price;
}

vector<string> Appliance::getPictures_(){
    return pictures_;
}

Appliance& Appliance::operator*(){
    return *this;
}
