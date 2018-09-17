//
//  main.cpp
//  ApplianceManager
//
//  Created by Nivetha Babu on 4/16/18.
//  Copyright © 2018 Nivetha Babu. All rights reserved.
//

#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
#include "AppliancePtr.hpp"
#include "Appliance.hpp"
#include "LinkedList.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    
    LinkedList appliancePtrs;
    bool notEnd = true;
    char command;
    int currAppId = 0;
    int noOfAppliancesInMemory = 0;
    
    appliancePtrs.insert(0);
    appliancePtrs.insert(1);
    appliancePtrs.insert(2);
    appliancePtrs.insert(3);
    appliancePtrs.insert(4);
    appliancePtrs.insert(5);
    appliancePtrs.insert(6);
    appliancePtrs.insert(7);
    appliancePtrs.insert(8);
    appliancePtrs.insert(9);
    
    cout<<"\n---APPLIANCE MANAGER--";
    cout<<"\nl - List all appliances";
    cout<<"\n0...9 - Edit an appliance";
    cout<<"\nc - Create an appliance";
    cout<<"\np - Change price of current appliance";
    cout<<"\ns - Save all appliances";
    cout<<"\nq - Quit";
    
    do {
        
        cout<<"\nEnter a command: ";
        cin>>command;
        
        //quit
        if (command == 'q')
            exit(0);
        
        noOfAppliancesInMemory = (appliancePtrs.find(currAppId))->count;
        
        //edit an appliance
        if(isdigit(command) != 0) {
            
            //checking and freeing memory if already 3 appliances are in memory
            if (noOfAppliancesInMemory == 3) {
                appliancePtrs.remove();
                noOfAppliancesInMemory--;
                appliancePtrs.insert(currAppId);
            }
            
            currAppId = command-48;
            noOfAppliancesInMemory = (appliancePtrs.find(currAppId))->count;
            
        }
        
        else if(isalpha(command) != 0) {
            //list all appliances
            if(command == 'l'){
                
                for(int i=0;i<10;i++){
                    //checking and freeing memory if already 3 appliances are in memory
                    if (noOfAppliancesInMemory == 3) {
                        int oldId = currAppId;
                        currAppId = appliancePtrs.remove();
                        appliancePtrs.insert(oldId);
                    }
                    
                    cout<<"\nID               : "<<(appliancePtrs.find(i))->getID_();
                    
                    int iType = (appliancePtrs.find(i))->getType_();
                    string sType;
                    if(iType == 0)
                        sType = "LAUNDRY_MACHINE";
                    else if(iType == 1)
                        sType = "DISH_WASHER";
                    else
                        sType = "DRYER";
                    cout<<"\nType             : "<<sType;
                    
                    cout<<"\nManufacturer      : "<<(appliancePtrs.find(i))->getManufacturer_();
                    
                    cout<<"\nPrice             : "<<(appliancePtrs.find(i))->getPrice_();
                    
                    cout<<"\nPictures           : ";
                    vector<string> pics = (appliancePtrs.find(i))->getPictures_();
                    copy(pics.begin(), pics.end(), ostream_iterator<string>(cout, " "));
                    
                    currAppId = i;
                    
                }
            }
            //create an appliance
            else if(command == 'c'){
                int id ;
                string type;
                string manufacturer;
                float price;
                string pics;
                
                cout<<"\nEnter ID: ";
                cin>>id;
                
                cout<<"\nEnter type: ";
                cin>>type;
                
                cout<<"\nEnter manufacturer: ";
                cin>>manufacturer;
                
                cout<<"\nEnter price: ";
                cin>>price;
                
                cout<<"\nEnter images (i.e file path strings of images each separated by a space) : ";
                
                cin.ignore();
                getline(cin, pics);
                
                //checking and freeing memory if already 3 appliances are in memory
                if (noOfAppliancesInMemory == 3) {
                    int oldId = currAppId;
                    currAppId = appliancePtrs.remove();
                    appliancePtrs.insert(oldId);
                }
                
                string filename = to_string(id) + ".txt";
                
                ofstream file;
                file.open(filename,ios_base::trunc);
                file<<id<<" "<<type<<" "<<manufacturer<<" "<<price<<" "<<pics;
                
                currAppId = id;
                noOfAppliancesInMemory = (appliancePtrs.find(currAppId))->count;
                
            }
            //change price of current appliance
            else if(command == 'p'){
                
                float price;
                cout<<"\nEnter new price: ";
                cin>>price;
                (appliancePtrs.find(currAppId))->setPrice_(price);
                cout<<"\nNew Content of this appliance instance";
                cout<<"\nID                 : "<<(appliancePtrs.find(currAppId))->getID_();
                int iType = (appliancePtrs.find(currAppId))->getType_();
                string sType;
                if(iType == 0)
                    sType = "LAUNDRY_MACHINE";
                else if(iType == 1)
                    sType = "DISH_WASHER";
                else
                    sType = "DRYER";
                cout<<"\nType             : "<<sType;
                cout<<"\nManufacturer       : "<<(appliancePtrs.find(currAppId))->getManufacturer_();
                
                cout<<"\nPrice              : "<<(appliancePtrs.find(currAppId))->getPrice_();
                
                cout<<"\nPictures           : ";
                vector<string> pics = (appliancePtrs.find(currAppId))->getPictures_();
                copy(pics.begin(), pics.end(), ostream_iterator<string>(cout, " "));
                
            }
            //save all appliances
            else if (command == 's'){
                for(int i=0;i<3;i++){
                   
                      ApplianceType type = (appliancePtrs.find(currAppId))->getType_();
                       string manufacturer = (appliancePtrs.find(currAppId))->getManufacturer_();
                        float price = (appliancePtrs.find(currAppId))->getPrice_();
                    vector<string> pictures = (appliancePtrs.find(currAppId))->getPictures_();
                    
                    string filename = to_string(currAppId) + ".txt";
                    
                    ofstream file;
                    file.open(filename,ios_base::trunc);
                    file<<currAppId<<" "<<type<<" "<<manufacturer<<" "<<price<<" ";
                    ostream_iterator<string> file_iterator(file," ");
                    copy(pictures.begin(), pictures.end(), file_iterator);
                    currAppId = appliancePtrs.remove();
                    noOfAppliancesInMemory = (appliancePtrs.find(currAppId))->count;
                
            }
            }
        }
        
        else
            notEnd = false;
        
    }while (notEnd);
    
    return 0;
}
