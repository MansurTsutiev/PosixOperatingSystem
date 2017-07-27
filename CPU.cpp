//
//  CPU.cpp
//  OS_Project
//
//  Created by Mansur Tsutiev on 5/12/17.
//  Copyright © 2017 Mansur Tsutiev. All rights reserved.
//

#include "CPU.hpp"

CPU::CPU()
{
	running_PCB.pid = -1;
	running_PCB.priority = -1;
}

void CPU::add_to_que(PCB pcb)
{
	if (pcb.priority == 0)
		priority_queue_0.push_back(pcb);
	else if (pcb.priority == 1)
		priority_queue_1.push_back(pcb);
	else if (pcb.priority == 2)
		priority_queue_2.push_back(pcb);
	else if (pcb.priority == 3)
		priority_queue_3.push_back(pcb);
	else if (pcb.priority == 4)
		priority_queue_4.push_back(pcb);
}

void CPU::terminate_proc()
{
    running_PCB.pid = -1;
    running_PCB.priority = -1;
}
void CPU::remove_current_proc()
{
	running_PCB.pid = -1;
	running_PCB.priority = -1;
	exec_next_proc();
}
void CPU::exec_next_proc()
{
	PCB next_pcb;
	bool result;
	//find next candidate proc
	if (!priority_queue_4.empty())
	{
		next_pcb = priority_queue_4.front();
		result = find_next_pcb(next_pcb);
		if (result)
			priority_queue_4.pop_front();
		
	}
	else if (!priority_queue_3.empty())
	{
		next_pcb = priority_queue_3.front();
		result = find_next_pcb(next_pcb);
		if (result)
			priority_queue_3.pop_front();
	}
	else if (!priority_queue_2.empty())
	{
		next_pcb = priority_queue_2.front();
		result = find_next_pcb(next_pcb);
		if (result)
			priority_queue_2.pop_front();
	}
	else if (!priority_queue_1.empty())
	{
		next_pcb = priority_queue_1.front();
		result = find_next_pcb(next_pcb);
		if (result)
			priority_queue_1.pop_front();
	}
	else if (!priority_queue_0.empty())
	{
		next_pcb = priority_queue_0.front();
		result = find_next_pcb(next_pcb);
		if (result)
			priority_queue_0.pop_front();
	}
	else
	{
		cout<<"Message: All ques in CPU are empty.\n";
	}
}


bool CPU::find_next_pcb(PCB &next_pcb)
{
	bool result = false;
	if (running_PCB.pid == -1 || running_PCB.priority < next_pcb.priority)
	{
		add_to_que(running_PCB);
		running_PCB = next_pcb;
		result = true;
	}
	return result;
}

void CPU::display()
{
	cout<<"************************** CPU State: *********************************\n";
	if (running_PCB.pid == -1)
	{
		cout<<"No currently running processes: \n";
	}
	else
	{
		cout<<"Currently Running PCB: \n";
		cout<<"PID = "<<running_PCB.pid<<" | Priority = "<<running_PCB.priority<<endl<<endl;
		list<PCB>::iterator it = priority_queue_4.begin();
		cout<<"Priority Que #4:\n";
		for (; it != priority_queue_4.end(); it++) {
			cout<<"PIDs: "<<it->pid<<" -> ";
		}
		cout<<endl<<endl;
		
		it = priority_queue_3.begin();
		cout<<"Priority Que #3:\n";
		for (; it != priority_queue_3.end(); it++) {
			cout<<"PIDs: "<<it->pid<<" -> ";
		}
		cout<<endl<<endl;
		
		it = priority_queue_2.begin();
		cout<<"Priority Que #2:\n";
		for (; it != priority_queue_2.end(); it++) {
			cout<<"PIDs: "<<it->pid<<" -> ";
		}
		cout<<endl<<endl;
		
		
		it = priority_queue_1.begin();
		cout<<"Priority Que #1:\n";
		for (; it != priority_queue_1.end(); it++) {
			cout<<"PIDs: "<<it->pid<<" -> ";
		}
		cout<<endl<<endl;
		
		it = priority_queue_0.begin();
		cout<<"Priority Que #0:\n";
		for (; it != priority_queue_0.end(); it++) {
			cout<<"PIDs: "<<it->pid<<" -> ";
		}
		cout<<endl<<endl;

	}
		cout<<"***********************************************************************\n\n";

}













