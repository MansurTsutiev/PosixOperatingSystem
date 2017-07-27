//
//  IODevice.hpp
//  OS_Project
//
//  Created by Mansur Tsutiev on 5/12/17.
//  Copyright © 2017 Mansur Tsutiev. All rights reserved.
//

#ifndef IODevice_hpp
#define IODevice_hpp

#include <stdio.h>
#include <iostream>
#include <list>
#include <vector>
#include "RAM.hpp"

using namespace std;

class IODevice
{
public:
	//data:
	string type;
	vector<PCB> currently_running_for_device;
	vector<list<PCB> > devices;
	
	//methods:
	IODevice(int num, string name);
	void add(PCB pcb, int num);
	void update(int num);
	PCB remove_proc(int num);
    void display();
	
};

#endif /* IODevice_hpp */
