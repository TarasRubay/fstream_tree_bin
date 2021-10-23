#pragma once
#include "tree.h"
#include "car.h"
#include <fstream>
class colec_car 
{
	tree<int, car_c> colect;
public:
	void add();
	void add(car_c& _car);
	void find(int _key);
	void save_to_txt(string& _path);
	void rev_file(string& _path, string& _path_rev);
	void read_from_txt(string& _path);
	void output_all_colect();
	void save_to_bin(string& _path);
	void read_from_bin(string& _path);
	void clear_colect();
	};
void print();
void rev(ifstream& _fin, ofstream& fout);