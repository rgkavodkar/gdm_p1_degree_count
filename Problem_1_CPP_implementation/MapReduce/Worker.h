/*
 * Worker.h
 *
 *  Created on: 18-Sep-2014
 *      Author: rg_kavodkar
 */
#include <map>
#include <string>
#ifndef WORKER_H_
#define WORKER_H_

namespace mapreduce {

class Worker {
	long **vertices;
	long size;
	long index;
	//std::map<long, long> v_degree;
	long *v_degree;
public:
	Worker(long array_size, long vertex_count);
	virtual ~Worker();
	void display();
	void enter_into_map(long vertex_id);
	void add_to_vertices(long vertex_1, long vertex_2);
	void perform_mapping();
	long get_vertices_count();
	//std::map<long, long> get_vertices_degrees();
	long* get_vertices_degrees();
};

long* perform_reducing(Worker **workers, int no_of_workers, long no_of_vertices);

} /* namespace mapreduce */

#endif /* WORKER_H_ */
