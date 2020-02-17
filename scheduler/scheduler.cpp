/*
 * scheduler.cpp
 *
 *  Created on: Sep 8, 2019
 *      Author: keith
 */

//TODO fill in content

#include "../includes/scheduler.h"
#include <queue>

using namespace std;

void Scheduler::add(PCB p) {
	ready_q->push(p);
}

PCB Scheduler::getNext() {
	PCB temp = ready_q->front();
	ready_q->pop();
	return temp;
}

bool Scheduler::isEmpty() {
	return ready_q->empty();
}

bool Scheduler::time_to_switch_processes(int tick_count, PCB &p) {
	if(preemptive) {
		return tick_count >= time_slice;
	}
	else {
		return tick_count >= p.required_cpu_time;
	}
}

