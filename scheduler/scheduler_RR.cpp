/*
 * SchedulerSTRR.cpp
 *
 *  Created on: Sep 7, 2019
 *      Author: keith
 *
 *      implements round robin scheduling algorithm
 *      pre-emptive
 */

#include "../includes/scheduler_RR.h"

int count = 0;

bool Scheduler_RR::time_to_switch_processes(int tick_count, PCB &p) {
	if((p.required_cpu_time - p.remaining_cpu_time) % time_slice == 0 || p.remaining_cpu_time <= 0) {
		return true;
	}
	else {
		return false;
	}

}

void Scheduler_RR::sort() {

}
