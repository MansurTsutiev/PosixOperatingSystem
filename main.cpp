//
//  main.cpp
//  OS_Project
//
//  Created by Mansur Tsutiev on 5/6/17.
//  Copyright © 2017 Mansur Tsutiev. All rights reserved.
//

#include <iostream>
#include <string>
#include <list>
using namespace std;
#include "RAM.hpp"
#include "CPU.hpp"
#include "IODevice.hpp"


int main()
{
    //get initial input:
	unsigned long int memory_size;
	int num_hard_disks;
	int num_printers;
	
	cout<<"How much memory does the system have in bytes? (Maximum 4GB)\n";
	cin>>memory_size;
	if (memory_size <= 1 || memory_size > 4000000000) { cout<<"Error: memory size is invalid\n"; exit(0);}
	cout<<"How many hard disks are threre? (1-10)\n";
	cin>>num_hard_disks;
	if (num_hard_disks < 1 || num_hard_disks > 10) { cout<<"Error: number of hard disks is invalid\n"; exit(0);}
	cout<<"How many printers are there? (1-10)\n";
	cin>>num_printers;
	if (num_printers < 1 || num_printers > 10) {cout<<"Error: number of printers is invalid\n"; exit(0); }
	cin.ignore(10000, '\n');
	
	CPU Processor;
	RAM Memory(memory_size);
	IODevice HardDisk(num_hard_disks, "Hard Disk");
	IODevice Printer(num_printers, "Printer");
	
	//for testing purposes:
	//string s[] = {"A 2 1000000","A 1 123","S r","A 3 2000000", "S r", "d 1", "S r","S i","d 1","S i","S r","t","S m","A 1 100","S m","D 1","S r","S i","t","A 1 3000000","S m"};


	
	//loop prompt
	string input = "";
	while (input != "exit")
	{
		cout<<"Enter command: \n";
		getline(cin, input);

		if (input[0] == 'A')					//OPTION: A - new proc
		{
			int priority = atoi(&input[2]);
			if (priority < 0 || priority > 4)
			{
				cout<<"Error: invalid priority number.\n";
			}
			else
			{
				unsigned long long int proc_size = stoull(input.substr(4,input.length()-1));
				if (proc_size <= 1 || proc_size > 4000000000)
				{
					cout<<"Error: invalid process size.\n";
				}
				else
				{
					PCB pcb = Memory.add(priority, proc_size);
					Processor.add_to_que(pcb);
					Processor.exec_next_proc();
				}
			}
			
		}
		else if (input[0] == 't')				//OPTION: t - terminate proc
		{
			if (input.size() != 1)
			{
				cout<<"Error: Invalid command (did you mean 't' to terminate?)\n";
			}
			else
			{
				Memory.remove(Processor.running_PCB.pid);
                Processor.terminate_proc();
                Processor.exec_next_proc();
			}
        }
		else if (input.length() >= 3 && input[0] == 'd')  //OPTION: d - use hard disk
		{
			int num = stoi(input.substr(2,input.length()-1));
			if (num > num_hard_disks)
			{
				cout<<"Error: Invalid specified hard disk.\n\n";
			}
			else
			{
                if (Processor.running_PCB.pid != -1)
                {
					HardDisk.add(Processor.running_PCB, num);
					Processor.remove_current_proc();
					Processor.exec_next_proc();
					
                }
                else
                {
                    cout<<"Error: There are no runnig processes in CPU.\n";
                }
			}
			
		}
		else if (input.length() >= 3 && input[0] == 'p')		//OPTION: p - user printer
		{
			int num = stoi(input.substr(2,input.length()-1));
			if (num > num_printers)
			{
				cout<<"Error: Invalid specified printer.\n\n";
			}
			else
			{
				if (Processor.running_PCB.pid != -1)
				{
					Printer.add(Processor.running_PCB, num);
					Processor.remove_current_proc();
					Processor.exec_next_proc();
				}
				else
				{
					cout<<"Error: There are no runnig processes in CPU.\n";
				}
			}
			
		}
		else if (input.length() >= 3 && input[0] == 'D')		//OPTION: D - hard disk finished work for one proc
		{
			int num = stoi(input.substr(2,input.length()-1));
			if (num > num_hard_disks)
			{
				cout<<"Error: Invalid specified hard disk.\n\n";
			}
			else
			{
				PCB pcb = HardDisk.remove_proc(num);
				if (pcb.pid == -1)
				{
					cout<<"There is no running PCB in Hard Disk "<<num<<endl;
				}
				else
				{
					Processor.add_to_que(pcb);
					Processor.exec_next_proc();
				}
			}
		}
		else if (input.length() >= 3 && input[0] == 'P')	//OPTION: P - printer finished work for one proc
		{
			int num = stoi(input.substr(2,input.length()-1));
			if (num > num_printers)
			{
				cout<<"Error: Invalid specified hard disk.\n\n";
			}
			else
			{
				PCB pcb = Printer.remove_proc(num);
				if (pcb.pid == -1)
				{
					cout<<"There is no running PCB in Hard Disk "<<num<<endl;
				}
				else
				{
					Processor.add_to_que(pcb);
					Processor.exec_next_proc();
				}

			}
		}
		else if (input.length() == 3 && input[0] == 'S' && input[2] == 'm')
		{
			Memory.display();
		}
		else if (input.length() == 3 && input[0] == 'S' && input[2] == 'r')
		{
			Processor.display();
		}
        else if (input.length() == 3 && input[0] == 'S' && input[2] == 'i')
        {
            HardDisk.display();
            Printer.display();
        }
        else
        {
            cout<<"Error: command is invalid.\n\n";
        }
		
	}
	
	
	
	
	
	
	cout<<endl;
	return 0;
}
