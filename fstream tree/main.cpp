#include "colect_car.h"
int main() {
	int menu = 100, max_menu = 9;
	int switch_on = menu;
	colec_car car;
	string path_txt = "car.txt";
	string path_txt_rev = "car_rev.txt";
	string path_bin = "car.bin";
	do
	{
		switch (switch_on)
		{
		case 100:
			do
			{
				print();
				cin >> switch_on;
				system("cls");
			} while (switch_on < 0 || switch_on > max_menu);
			cin.get();

			break;
		case 1:
			car.read_from_txt(path_txt);
			switch_on = menu;
			break;
		case 2:
			car.read_from_bin(path_bin);
			//cout << "under development";
			switch_on = menu;
			break;
		case 3:
			car.add();
			switch_on = menu;
			break;
		case 4:
			do
			{
				cout << "enter registrat number to find: ";
				cin >> switch_on;
			} while (switch_on < 0);
			cin.get();
			car.find(switch_on);
			switch_on = menu;
			break;
		case 5:
			car.save_to_txt(path_txt);
			switch_on = menu;
			break;
		case 6:
			car.save_to_bin(path_bin);
			//cout << "under development";
			switch_on = menu;
			break;
		case 7:
			car.output_all_colect();
			switch_on = menu;
			break;
		case 8:
			car.rev_file(path_txt,path_txt_rev);
			switch_on = menu;
			break;
		case 9:
			car.clear_colect();
			switch_on = menu;
			break;

		default:
			break;
		}

	} while (switch_on != 0);
	return 0;
}