/*
 * SchedulerSRTF.cpp
 *
 *  Created on: Sep 10, 2019
 *      Author: keith
 *
 *      implements shortest remaining time first scheduling algorithm
 *     pre-emptive
 */

#include "../includes/scheduler_SRTF.h"
#include <algorithm>
#include <vector>

bool Scheduler_SRTF::time_to_switch_processes(int tick_count, PCB &p) {
	sort();
	if(ready_q->front().remaining_cpu_time < p.remaining_cpu_time) { //If the current process does not have shortest remaining CPU time then switch
		return true;
	}
	if(p.remaining_cpu_time <= 0) { //Otherwise wait until the process is done
		return true;
	}
	return false;
}

bool sortCPUTime(const PCB &a, const PCB &b) {return a.remaining_cpu_time < b.remaining_cpu_time;}

void Scheduler_SRTF::sort() {
	std::vector<PCB> tempVec; //Creates a temp vector to sort the queue

	while(!ready_q->empty()) { //Loads the values of the queue into the vector
		tempVec.push_back(ready_q->front());
		ready_q->pop();
	}

	std::sort(tempVec.begin(), tempVec.end(), sortCPUTime); //Sorts the vector by remaining CPU time

	for(int i = 0 ; i < tempVec.size() ; i++) { //Puts the values of the vector back into the CPU
		ready_q->push(tempVec[i]);
	}
}
