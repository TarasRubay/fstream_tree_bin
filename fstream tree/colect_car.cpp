#include "colect_car.h"
#include "car.h"
#include "tree.h"

void colec_car::add()
{
	car_c new_car;
	cout << "enter owner name: ";
	new_car.set_owner();
	cout << "enter build year car: ";
	new_car.set_year();
	cout << "enter color car: ";
	new_car.set_color();
	cout << "enter registrant number: ";
	new_car.set_key();
	colect.add(new_car.get_key(), new_car);
	cout << "\nadd comleted...\n";
}

void colec_car::add(car_c& _car)
{
	colect.add(_car.get_key(), _car);
}


void colec_car::find(int _key)
{

	car_c* tmp = colect.find(_key);
	if (tmp == nullptr)cerr << "not found";
	else {
		cout << "owner: " << tmp->get_owner();
		cout << "\ncolor: " << tmp->get_color();
		cout << "\nbuild year: " << tmp->get_year() << endl;
	}
}

void colec_car::save_to_txt(string& _path)
{
	ofstream fout;
	fout.open(_path);
	if (!fout.is_open()) {
		cerr << "open error";
	}
	else {
		cerr << "file.txt open\n";
		colect.output(fout);
		cerr << "\nfile.txt close";
	}
	fout.close();

}

void colec_car::rev_file(string& _path, string& _path_rev)
{
	ifstream fin;
	fin.open(_path);
	if (!fin.is_open()) {
		cerr << "open error";
	}
	else {
		cerr << "file.txt open\n";
		ofstream fout;
		fout.open(_path_rev);
		if (!fout.is_open()) {
			cerr << "open error";
		}
		else {
			cerr << "file.txt open\n";
			rev(fin,fout);
			cerr << "\nfile.txt close\n";
		fout.close();
		}
		cerr << "file.txt close";
	}
	fin.close();
}



void colec_car::read_from_txt(string& _path)
{
	ifstream fin;
	fin.open(_path);
	if (!fin.is_open()) {
		cerr << "open error";
	}
	else {
		car_c tmp;
		cerr << "file.txt open\n";
		while (fin >> tmp)
			colect.add(tmp.get_key(), tmp);
		cerr << "\nfile.txt close";
	}
	fin.close();
}

void colec_car::output_all_colect()
{
	if (colect.empty())cerr << "colection is empty";
	else colect.output(cout);
}

void colec_car::save_to_bin(string& _path)
{
	ofstream fout;
	fout.open(_path);
	if (!fout.is_open()) {
		cerr << "open error";
	}
	else {
		cerr << "file.bin open\n";
		colect.output_bin(fout);
		cerr << "\nfile.bin close";
	}
	fout.close();

}

void colec_car::read_from_bin(string& _path)
{
	ifstream fin;
	fin.open(_path);
	if (!fin.is_open()) {
		cerr << "open error";
	}
	else {
		car_c tmp;
		cerr << "file.bin open\n";
		while(tmp.read_from_bin(fin))
		add(tmp);
		cerr << "\nfile.bin close";
	}
	fin.close();
}

void colec_car::clear_colect()
{
	colect.~tree();
}

void print()
{
	cout << "\n1 - read from .txt file\n";
	cout << "2 - read from .bin file\n";
	cout << "3 - greate new car\n";
	cout << "4 - find car\n";
	cout << "5 - save in .txt file\n";
	cout << "6 - save in .bin file\n";
	cout << "7 - view all colection\n";
	cout << "8 - write revers colection\n";
	cout << "9 - clear colection\n";
	cout << "0 - exit\n";
}

void rev(ifstream& _fin, ofstream& fout)
{
	car_c tmp;
	while(_fin >> tmp)rev(_fin, fout);
	if(tmp.get_key())
		fout << tmp;
}




