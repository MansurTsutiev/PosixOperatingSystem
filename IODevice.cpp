//
//  IODevice.cpp
//  OS_Project
//
//  Created by Mansur Tsutiev on 5/12/17.
//  Copyright © 2017 Mansur Tsutiev. All rights reserved.
//

#include "IODevice.hpp"


IODevice::IODevice(int num, string name)
{
    type = name;
    
	for (int i = 0; i < num; i++)
	{
		list<PCB> que;
        PCB pcb;
        pcb.pid = -1;
		devices.push_back(que);
        currently_running_for_device.push_back(pcb);
	}
}
void IODevice::add(PCB pcb, int num)
{
	devices[num-1].push_back(pcb);
	update(num);
	
}
void IODevice::update(int num)
{
	if (currently_running_for_device[num-1].pid == -1)
	{
		if (!devices[num-1].empty())
		{
			PCB pcb = devices[num-1].front();
			devices[num-1].pop_front();
			currently_running_for_device[num-1] = pcb;
		}
	}
}
PCB IODevice::remove_proc(int num)
{
	PCB pcb;
	pcb.pid = -1;
	pcb.priority = -1;
	if (currently_running_for_device[num - 1].pid != -1)
	{
		pcb = currently_running_for_device[num - 1];
		currently_running_for_device[num - 1].pid = -1;
		update(num);
	}
	return pcb;
}

void IODevice::display()
{
    cout<<"****************************** "<<type<<" State *******************************\n";
    for (unsigned int i = 0; i < currently_running_for_device.size(); i++)
    {
        cout<<type<<" "<<i+1<<":\n";
        if (currently_running_for_device[i].pid != -1)
        {
            cout<<"Currently running process: PID = "<<currently_running_for_device[i].pid<<endl;
            cout<<"PIDs currently in que: ";
			list<PCB>::iterator it = devices[i].begin();
			for (; it != devices[i].end(); it++)
			{
				cout<<it->pid<<" -> ";
			}
			cout<<endl<<endl;
        }
        else
        {
            cout<<"Has no running processes\n\n";
        }
    }
}
