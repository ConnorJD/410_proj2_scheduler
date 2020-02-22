/*
 * Stats.cpp
 *
 *  Created on: Sep 10, 2019
 *      Author: keith
 */

#include "../includes/stats.h"
#include "../includes/PCB.h"
#include <vector>
#include <iostream>

using namespace std;

//Initializes the values in the same way the scheduler header files do
Stats::Stats(std::vector<PCB> &finished_vector) : vec(&finished_vector), av_wait_time(0), av_turnaround_time(0), av_response_time(0) {}

void Stats::showAllProcessInfo() {
	//Prints out the process info, could be more organized with printf
	for(int i = 0 ; i < vec->size() ; i++) {
		cout << "Process " << vec->at(i).process_number
				<< " " << "Required CPU time:" << vec->at(i).required_cpu_time
				<< " " << "arrived:" << vec->at(i).arrival_time << " "
				<< "started:" << vec->at(i).start_time << " "
				<< "finished:" << vec->at(i).finish_time;
		}
}

float Stats::get_av_response_time() {
	int total = 0;
	for(int i = 0 ; i < vec->size() ; i++) { //Gets total response time
		total += vec->at(i).start_time - vec->at(i).arrival_time;
	}
	return (float)total / (float)(vec->size()); //Gets average response time
}

float Stats::get_av_turnaround_time() {
	int total = 0;
	for(int i = 0 ; i < vec->size() ; i++) { //Gets total turnaround time
		total += vec->at(i).finish_time - vec->at(i).arrival_time;
	}
	return (float)total / (float)(vec->size()); //Gets average turnaround time
}

float Stats::get_av_wait_time() {
	int total = 0;
	for(int i = 0 ; i < vec->size() ; i++) { //Gets total wait time
		total += vec->at(i).finish_time - vec->at(i).arrival_time - vec->at(i).required_cpu_time;
	}
	return (float)total / (float)(vec->size()); //Gets average wait time
}

void Stats::calcStats() {
	this->av_wait_time = get_av_wait_time();
	this->av_turnaround_time = get_av_turnaround_time();
	this->av_response_time = get_av_response_time();
}
