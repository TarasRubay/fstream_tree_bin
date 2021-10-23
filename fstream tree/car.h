#pragma once
#include "tree.h"
class car_c
{
	string owner;
	int year = NULL;
	string color;
	int key = NULL;
public:
	car_c();
	~car_c();
	car_c(int _key,int _year,string _owner, string _color);
	string get_owner();
	int get_year();
	string get_color();
	int get_key();
	void set_owner();
	void set_year();
	void set_color();
	void set_key();
	void save_to_bin(ostream& fout);
	bool read_from_bin(istream& fin);
	friend ostream& operator+=(ostream& out, const car_c& _car);
	friend istream& operator>>(istream& in, car_c& _car);
	friend ostream& operator<<(ostream& out, const car_c& _car);


};

