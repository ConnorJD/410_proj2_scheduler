/*
 * Dispatcher.cpp
 *
 *  Created on: Sep 8, 2019
 *      Author: keith
 */

#include "../includes/dispatcher.h"

PCB Dispatcher::get_from_CPU() {
	if(is_valid_job_on_cpu) {
		is_valid_job_on_cpu = false; // False because there is no longer a process on CPU
		return cpu->get_process_off_core(); //Gets the value and removes the process from the CPU
	}
	PCB temp;
	return temp; // Returns uninitialized PCB
}

void Dispatcher::put_on_CPU(PCB &process) {
	if(!process.isEmpty()) { // If the process is valid
		is_valid_job_on_cpu = true; // Turns true because there is now a process on CPU
		cpu->put_process_on_core(process); // Puts the process on the CPU
	}
}

bool Dispatcher::isValidJobOnCPU() {
	return is_valid_job_on_cpu;
}
