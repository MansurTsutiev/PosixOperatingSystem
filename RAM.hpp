//
//  RAM.hpp
//  OS_Project
//
//  Created by Mansur Tsutiev on 5/7/17.
//  Copyright © 2017 Mansur Tsutiev. All rights reserved.
//

#ifndef RAM_hpp
#define RAM_hpp

#include <stdio.h>
#include <list>

using namespace std;

struct PCB
{
	int pid;
	int priority;
    unsigned long long int size;
	unsigned long long int first;
	unsigned long long int last;

};

class RAM
{
public:
    //VARIABLES:
	RAM(unsigned long long int size);
	unsigned long long int memory_size;
	int global_id;
	list<PCB> proc_list;
    
    //METHODS:
	PCB add(int priority, unsigned long long int proc_size);
    void remove(int pid);
    list<PCB>::iterator find_hole(unsigned long long int proc_size);
	void display();
};

#endif /* RAM_hpp */
