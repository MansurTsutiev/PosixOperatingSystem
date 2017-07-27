//
//  CPU.hpp
//  OS_Project
//
//  Created by Mansur Tsutiev on 5/12/17.
//  Copyright © 2017 Mansur Tsutiev. All rights reserved.
//

#ifndef CPU_hpp
#define CPU_hpp

#include <stdio.h>
#include <list>
#include <iostream>
#include "RAM.hpp"
using namespace std;

class CPU
{
	
public:
	//data:
	PCB running_PCB;
	
	
	list<PCB> priority_queue_0;
	list<PCB> priority_queue_1;
	list<PCB> priority_queue_2;
	list<PCB> priority_queue_3;
	list<PCB> priority_queue_4;
	
	
	//methods:
	CPU();
	void add_to_que(PCB pcb);
	void exec_next_proc();
    void terminate_proc();
	void remove_current_proc();
	
	//helpers
	bool find_next_pcb(PCB &next_pcb);
	void display();
	
};

#endif /* CPU_hpp */
