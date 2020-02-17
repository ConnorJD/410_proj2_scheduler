/*
 * Dispatcher.cpp
 *
 *  Created on: Sep 8, 2019
 *      Author: keith
 */

#include "../includes/dispatcher.h"

PCB Dispatcher::get_from_CPU() {
	if(is_valid_job_on_cpu) {
		is_valid_job_on_cpu = false;
		return cpu->get_process_off_core();
	}
	PCB temp;
	return temp;
}

void Dispatcher::put_on_CPU(PCB &process) {
	if(!process.isEmpty()) {
		is_valid_job_on_cpu = true;
		cpu->put_process_on_core(process);
	}
}

bool Dispatcher::isValidJobOnCPU() {
	return is_valid_job_on_cpu;
}
