#include "car.h"
#include <fstream>
car_c::car_c()
{
}
car_c::~car_c()
{

}
car_c::car_c(int _key, int _year, string _owner, string _color)
{
	key = _key;
	year = _year;
	owner = _owner;
	color = _color;
}
string car_c::get_owner()
{
	if (!owner.size()){
		cerr << "no owner name";
		return owner;
	}
	else
	return owner;
}

int car_c::get_year()
{	
	if(year == NULL){
		cerr << "no data year";
	return year;
	}
	else
	return year;
}

string car_c::get_color()
{
	if (!color.size()) {
		cerr << "no data of color";
		return color;
	}
	else
		return color;
}

int car_c::get_key()
{
	if (key == NULL){
		cerr << "no key data";
		return key;
	}
	else
		return key;
}

void car_c::set_owner()
{
	getline(cin,owner);
}

void car_c::set_year()
{
	do
	{
		cin >> year;
		if (year < 0 || year > 2021)cerr << "out of range min 0 max 2021";
	} while (year < 0 || year > 2021);
	cin.get();
}

void car_c::set_color()
{
	getline(cin,color);
}

void car_c::set_key()
{
	do
	{
		cin >> key;
		if (key < 1 || key > 9999)cerr << "out of range min 1 max 9999";
	} while (key < 1 || key > 9999);
	cin.get();
}

void car_c::save_to_bin(ostream& fout)
{
		
		int len;
		fout.write((char*)&key, sizeof(key));
		fout.write((char*)&year, sizeof(year));

		len = owner.size();
		fout.write((char*)&len, sizeof(len));
		fout.write((char*)owner.c_str(), len);

		len = color.size();
		fout.write((char*)&len, sizeof(len));
		fout.write((char*)color.c_str(), len);

		cout << ">";
	
}

bool car_c::read_from_bin(istream& fin)
{
	bool read = false;
	if (fin.read((char*)&key, sizeof(key))) {
		int len;
		read = true;
		fin.read((char*)&year, sizeof(year));

		fin.read((char*)&len, sizeof(len));
		owner = string(len, '\0');
		fin.read((char*)owner.data(), len);

		fin.read((char*)&len, sizeof(len));
		color = string(len, '\0');
		fin.read((char*)color.data(), len);
		cout << "<";
		return read;
	}
	else return read;
}


ostream& operator+=(ostream& out, const car_c& _car)
{
	int len;
	out.write((char*)&_car.key, sizeof(_car.key));
	out.write((char*)&_car.year, sizeof(_car.year));

	len = _car.owner.size();
	out.write((char*)&len, sizeof(len));
	out.write((char*)_car.owner.c_str(), len);

	len = _car.color.size();
	out.write((char*)&len, sizeof(len));
	out.write((char*)_car.color.c_str(), len);

	cerr << ">";
	return out;
}

istream& operator>>(istream& in, car_c& _car)
{  
	in >> _car.key;
	in.ignore(1);
	in >> _car.year;
	in.ignore(1);
	getline(in, _car.owner, '~');
	getline(in, _car.color);
	cout << "<";
	return in;
}

ostream& operator<<(ostream& out, const car_c& _car)
{
	if (typeid(out) == typeid(ofstream)) {
		out << _car.key << '~' << _car.year << '~' << _car.owner << '~' << _car.color << endl;
		cout << ">";
	}
	
	if (typeid(out) == typeid(ostream)) {
		out << "\nregisrant number: " << _car.key;
		out << "\nowner: " << _car.owner;
		out << "\ncolor: " << _car.color;
		out << "\nbuild year: " << _car.year << endl;
	}
	return out;
}



