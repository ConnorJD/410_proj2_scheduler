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

Stats::Stats(std::vector<PCB> &finished_vector) {
	*vec = finished_vector;
}

void Stats::showAllProcessInfo() {
	cout << vec->size();
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
	for(int i = 0 ; i < vec->size() ; i++) {
		total += vec->at(i).start_time - vec->at(i).arrival_time;
	}
	return (float)total / (float)(vec->size());
}

float Stats::get_av_turnaround_time() {
	int total = 0;
	for(int i = 0 ; i < vec->size() ; i++) {
		total += vec->at(i).finish_time - vec->at(i).arrival_time;
	}
	return (float)total / (float)(vec->size());
}

float Stats::get_av_wait_time() {
	int total = 0;
	for(int i = 0 ; i < vec->size() ; i++) {
		total += vec->at(i).finish_time - vec->at(i).arrival_time - vec->at(i).required_cpu_time;
	}
	return (float)total / (float)(vec->size());
}

void Stats::calcStats() {
	this->av_wait_time = get_av_wait_time();
	this->av_turnaround_time = get_av_turnaround_time();
	this->av_response_time = get_av_response_time();
}
