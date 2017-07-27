//
//  RAM.cpp
//  OS_Project
//
//  Created by Mansur Tsutiev on 5/7/17.
//  Copyright © 2017 Mansur Tsutiev. All rights reserved.
//

#include "RAM.hpp"
#include <iostream>
using namespace std;


RAM::RAM(unsigned long long int size)
{
	memory_size = size;
	global_id = 0;
}
PCB RAM::add(int priority, unsigned long long int proc_size)
{
    PCB pcb;
	if (global_id == 0)					//first proc in memory
	{
        pcb.pid = ++global_id;
        pcb.priority = priority;        //add first proc
		pcb.first = 0;
		pcb.last = proc_size - 1;
        pcb.size = proc_size;
		proc_list.push_back(pcb);
		
		PCB limit_pcb;					//add dummy pcb to indicate limit
        limit_pcb.pid = -1;
        limit_pcb.priority = 0;
        limit_pcb.first = memory_size-1;
		limit_pcb.last = memory_size-1;
		proc_list.push_back(limit_pcb);
        
        memory_size -= proc_size;       //decrement memory size
		
		return pcb;
		
	}
	else
	{
        list<PCB>::iterator node = find_hole(proc_size);
		if (node == proc_list.end())
		{
			cout<<"Error: no hole is found.\n";
			
		}
		else	//add pcb
		{
			node--;
            pcb.pid = ++global_id;
            pcb.priority = priority;
			pcb.first = node->last + 1;
			pcb.last = pcb.first + (proc_size-1);
			node++;
            pcb.size = proc_size;
			proc_list.insert(node, pcb);
            memory_size -= proc_size;
		}
		
	}
	return pcb;
}
void RAM::remove(int pid)	//FIX
{
	//find the node
	list<PCB>::iterator it = proc_list.begin();
	for (; it != prev(proc_list.end()); it++)
	{
		if (it->pid == pid)
		{
			proc_list.erase(it);
			memory_size += it->size;
			break;
		}
	}
	
	
}

void RAM::display()
{
    cout<<"**************** Memory State ********************\n";
	for (list<PCB>::const_iterator it = proc_list.begin(); it != prev(proc_list.end()); ++it)
	{
        cout<<"PID = "<<it->pid<<endl;
        cout<<"Process size = "<<it->size<<endl;
		cout<<"Range: from "<<it->first<<" to "<<it->last<<"\n\n";
        
	}
    cout<<"Memory left: "<<memory_size<<" bytes.\n";
    cout<<"\n**************************************************\n";
}

list<PCB>::iterator RAM::find_hole(unsigned long long int proc_size)
{
    list<PCB>::iterator node = proc_list.end();
    for (list<PCB>::iterator it = proc_list.begin(); it != prev(proc_list.end()); it++)
    {
		list<PCB>::iterator prev = it;
        it++;
        //cout<<"Hole = "<<it->first<<" - "<<prev->last<<" = "<<it->first - prev->last<<endl;
        if ( (it->first - prev->last) >= proc_size)
        {
            return it;
			
        }
		it--;
    }
    return node;
}
