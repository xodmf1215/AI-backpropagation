//Backpropagation, 25x25x8 units, binary sigmoid function network
//Written by Thomas Riga, University of Genoa, Italy
//thomas@magister.magi.unige.it

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "backprop.h"

using std::cout;
using std::cin;
using std::end;
using std::endl;

int main()
{
	errorTestingFunction();
	cout << "backpropagation network by Thomas Riga, University of Genoa, Italy" << endl;
	for (;;) {
		char choice;
		cout << endl << "1. load data" << endl;
		cout << "2. learn from data" << endl;
		cout << "3. compute output pattern" << endl;

		cout << "4. make new data file" << endl;

		cout << "5. save data" << endl;
		cout << "6. print data" << endl;

		cout << "7. change learning rate" << endl;

		cout << "8. exit" << endl << endl;
		cout << "Enter your choice (1-8)";
		do { choice = _getch(); } while (choice != '1' && choice != '2' && choice != '3' && choice != '4' && choice != '5' && choice != '6' && choice != '7' && choice != '8');
		switch (choice) {
		case '1':
		{
			if (file_loaded == 1) clear_memory();
			get_file_name();
			file_loaded = 1;
			load_data(filename);
		}
		break;
		case '2': learn();
			break;
		case '3': compute_output_pattern();
			break;
		case '4': make();
			break;
		case '5':
		{
			if (file_loaded == 0)
			{
				cout << endl
					<< "there is no data loaded into memory"
					<< endl;
				break;
			}
			cout << endl << "enter a filename to save data to: ";
			cin >> filename;
			save_data(filename);
		}
		break;
		case '6': print_data();
			break;
		case '7': change_learning_rate();
			break;
		case '8': return 0;
		};
	}
}
void errorTestingFunction()
{
	string a;
	//cin >> a;
	//a = getString();
}
