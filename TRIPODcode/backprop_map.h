#pragma once
#include <iostream>
#include <fstream>
#include <conio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <stdio.h>
#include <float.h>
#include <map>
#include <string>
#include "backprop.h"

#define IA   16807
#define IM   2147483647
#define AM   (1.0 / IM)
#define IQ   127773
#define IR   2836
#define NTAB 32
#define NDIV (1+(IM-1) / NTAB)
#define EPS  1.2e-7
#define RNMX (1.0 - EPS)

using namespace std;
map<string, int> workclass;
map<string, int> education;
map<string, int> marital_status;
map<string, int> occupation;
map<string, int> income;
map<string, int> relationship;
map<string, int> race;
map<string, int> gender;
map<string, int> native_country;

int mapToValue_output(int, string);
int mapToValue_input(int, string);
int gaset = -2500;
float bedlam(long*);

void mapping(char *datafilename,char *makefilename)
{
	workclass.insert(make_pair("Private", 1));
	workclass.insert(make_pair("Self-emp-not-inc", 2));
	workclass.insert(make_pair("Self-emp-inc", 3));
	workclass.insert(make_pair("Federal-gov", 4));
	workclass.insert(make_pair("Local-gov", 5));
	workclass.insert(make_pair("State-gov", 6));
	workclass.insert(make_pair("Without-pay", 7));
	workclass.insert(make_pair("Never-worked", 8));

	education.insert(make_pair("Preschool", 9));
	education.insert(make_pair("1st-4th", 10));
	education.insert(make_pair("5th-6th",11));
	education.insert(make_pair("7th-8th", 12));
	education.insert(make_pair("9th", 13));
	education.insert(make_pair("10th", 14));
	education.insert(make_pair("11th", 15));
	education.insert(make_pair("12th", 16));
	education.insert(make_pair("HS-grad", 17));
	education.insert(make_pair("Assoc-acdm", 18));
	education.insert(make_pair("Assoc-voc", 19));
	education.insert(make_pair("Some-college", 20));
	education.insert(make_pair("Prof-school", 21));
	education.insert(make_pair("Bachelors", 22));
	education.insert(make_pair("Masters", 23));
	education.insert(make_pair("Doctorate", 24));

	marital_status.insert(make_pair("Married-civ-spouse", 25));
	marital_status.insert(make_pair("Divorced", 26));
	marital_status.insert(make_pair("Never-married", 27));
	marital_status.insert(make_pair("Separated", 28));
	marital_status.insert(make_pair("Widowed", 29));
	marital_status.insert(make_pair("Married-spouse-absent", 30));
	marital_status.insert(make_pair("Married-AF-spouse", 31));

	occupation.insert(make_pair("Tech-support", 32));
	occupation.insert(make_pair("Craft-repair", 33));
	occupation.insert(make_pair("Other-service", 34));
	occupation.insert(make_pair("Sales", 35));
	occupation.insert(make_pair("Exec-managerial", 36));
	occupation.insert(make_pair("Prof-specialty", 37));
	occupation.insert(make_pair("Handlers-cleaners", 38));
	occupation.insert(make_pair("Machine-op-inspct", 39));
	occupation.insert(make_pair("Adm-clerical", 39));
	occupation.insert(make_pair("Farming-fishing", 40));
	occupation.insert(make_pair("Transport-moving", 41));
	occupation.insert(make_pair("Priv-house-serv", 42));
	occupation.insert(make_pair("Protective-serv", 43));
	occupation.insert(make_pair("Armed-Forces", 44));

	relationship.insert(make_pair("Wife", 45));
	relationship.insert(make_pair("Own-child", 46));
	relationship.insert(make_pair("Husband", 47));
	relationship.insert(make_pair("Not-in-family", 48));
	relationship.insert(make_pair("Other-relative", 49));
	relationship.insert(make_pair("Unmarried", 50));

	race.insert(make_pair("White", 511));
	race.insert(make_pair("Asian-Pac-Islander", 52));
	race.insert(make_pair("Amer-Indian-Eskimo", 53));
	race.insert(make_pair("Other", 54));
	race.insert(make_pair("Black", 55));

	gender.insert(make_pair("Female", 56));
	gender.insert(make_pair("Male", 57));


	native_country.insert(make_pair("United-States", 58));
	native_country.insert(make_pair("Cambodia", 59));
	native_country.insert(make_pair("England", 60));
	native_country.insert(make_pair("Puerto-Rico", 61));
	native_country.insert(make_pair("Canada", 62));
	native_country.insert(make_pair("Germany", 63));
	native_country.insert(make_pair("Outlying-US(Guam-USVI-etc)", 64));
	native_country.insert(make_pair("India", 65));
	native_country.insert(make_pair("Japan", 66));
	native_country.insert(make_pair("Greece", 67));
	native_country.insert(make_pair("South", 68));
	native_country.insert(make_pair("China", 69));
	native_country.insert(make_pair("Cuba", 70));
	native_country.insert(make_pair("Iran", 71));
	native_country.insert(make_pair("Honduras", 72));
	native_country.insert(make_pair("Philippines", 73));
	native_country.insert(make_pair("Italy", 74));
	native_country.insert(make_pair("Poland", 75));
	native_country.insert(make_pair("Jamaica", 76));
	native_country.insert(make_pair("Vietnam", 77));
	native_country.insert(make_pair("Mexico", 78));
	native_country.insert(make_pair("Portugal", 79));
	native_country.insert(make_pair("Ireland", 80));
	native_country.insert(make_pair("France", 81));
	native_country.insert(make_pair("Dominican-Republic", 82));
	native_country.insert(make_pair("Laos", 83));
	native_country.insert(make_pair("Ecuador", 84));
	native_country.insert(make_pair("Taiwan", 85));
	native_country.insert(make_pair("Haiti", 86));
	native_country.insert(make_pair("Columbia", 87));
	native_country.insert(make_pair("Hungary", 88));
	native_country.insert(make_pair("Guatemala", 89));
	native_country.insert(make_pair("Nicaragua", 90));
	native_country.insert(make_pair("Scotland", 91));
	native_country.insert(make_pair("Thailand", 92));
	native_country.insert(make_pair("Yugoslavia", 93));
	native_country.insert(make_pair("El-Salvador", 94));
	native_country.insert(make_pair("Trinadad&Tobago", 95));
	native_country.insert(make_pair("Peru", 96));
	native_country.insert(make_pair("Hong", 97));
	native_country.insert(make_pair("Holand-Netherlands", 98));

	income.insert(make_pair("<=50K", 0));
	income.insert(make_pair(">50K", 1));

	ifstream in(datafilename);
	ofstream out(makefilename);
	
	if (!in) {
		cout << endl << "failed to load original data file" << endl;
		return;
	}
	if (!out) {
		cout << endl << "failed to open make file" << endl;
		return;
	}
	//////////////////////////////////////////////////make file setting////////////////////////////
	int x, y, z;
	double inpx, bias_array_size, input_array_size, hidden_array_size, output_array_size;
	string input_string;
	cout << "how many input units? "; //98
	cin >> input_array_size;
	out << input_array_size << endl;
	cout << "how many hidden units? "; //1
	cin >> hidden_array_size;
	out << hidden_array_size << endl;
	cout << "how many output units? "; //1
	cin >> output_array_size;
	out << output_array_size << endl;
	bias_array_size = hidden_array_size + output_array_size;
	cout << endl << "Learning rate: ";
	cin >> inpx;
	out << inpx << endl;
	cout << endl << "Number of input patterns: ";
	cin >> z;
	out << z << endl << endl;
	for (x = 0; x < bias_array_size; x++) {
		out << (1.0 - (2.0 * bedlam((long*)(&gaset)))) << ' ';
	}
	out << endl << endl;
	for (x = 0; x<input_array_size; x++) {
		for (y = 0; y<hidden_array_size; y++) out << (1.0 - (2.0 * bedlam((long*)(&gaset)))) << ' ';
	}
	out << endl << endl;
	for (x = 0; x<hidden_array_size; x++) {
		for (y = 0; y<output_array_size; y++) out << (1.0 - (2.0 * bedlam((long*)(&gaset)))) << ' ';
	}
	out << endl << endl;
	/*for (x = 0; x < z; x++) {
		cout << endl << "input pattern " << (x + 1) << endl;
		for (y = 0; y<input_array_size; y++) {
			cout << (y + 1) << ": ";
			cin >> input_string;
			out << input_string << ' ';
		}
		cout << endl << "target output pattern " << (x + 1) << endl;
		for (y = 0; y<output_array_size; y++) {
			cout << (y + 1) << ": ";
			cin >> input_string;
			out << input_string << ' ';
		}
		out << endl;
	}*/
	
	//////////////////////////////////////////////original data conversion to make file////////////////////////////////
	string temp;
	int num_data;
	int num_input_data_attributes, num_output_data_attributes;
	int i, j, k;
	int input_line[99]; //input node + output node (98+1)
	in >> num_input_data_attributes; //14
	in >> num_output_data_attributes; //1
	for (i = 0; i < z; i++) {
		for (j = 0; j < input_array_size+output_array_size; j++) input_line[j] = 0;
		for (j = 0; j < num_input_data_attributes; j++) {
			in >> temp;
			k=mapToValue_input(j, temp);
			if(k >= 0 ) input_line[k] = 1;
		}
		in >> temp;
		k = mapToValue_output(0, temp);
		if (k == 0) input_line[98] = 0; //50k 이하 소득은 0
		else input_line[98] = 1;
		for (j = 0; j < 99;j++) out << input_line[j] << ' ';
		out << endl;
	}
	in.close();
	out.close();
}
int mapToValue_input(int attributes_num, string key) {
	map<string, int>::iterator it;
	if (key.compare("?") == 0) return -1; //값이 없는 ?값인 경우 -1리턴해서 아무것도 일어나지 않도록한다.
	switch (attributes_num) {
	case 0:
		return -1;
	case 1:
		it = workclass.find(key);
		if (it == workclass.end()) return -1; //-1은 에러 혹은 쓸못없는 attribute일 때 반환
		break;
	case 2:
		return -1;
	case 3:
		it = education.find(key);
		if (it == education.end()) return -1;
		break;
	case 4:
		return -1;
	case 5:
		it = marital_status.find(key);
		if (it == marital_status.end()) return -1;
		break;
	case 6:
		it = occupation.find(key);
		if (it == occupation.end()) return -1;
		break;
	case 7:
		it = relationship.find(key);
		if (it == relationship.end()) return -1;
		break;
	case 8:
		it = race.find(key);
		if (it == race.end()) return -1;
		break;
	case 9:
		it = gender.find(key);
		if (it == gender.end()) return -1;
		break;
	case 10:
		return -1;
	case 11:
		return -1;
	case 12:
		return -1;
	case 13:
		it = native_country.find(key);
		if (it == native_country.end()) return -1;
		break;
	default:
		return -1;
	}
	return (it->second)-1;
}
int mapToValue_output(int attributes_num, string key) {
	map<string, int>::iterator it;
	switch (attributes_num) {
	case 0:
		it = income.find(key);
		if (it == income.end()) return -1;
		break;
	}
	return it->second;
}
float bedlam(long *idum)
{
	int xj;
	long xk;
	static long iy = 0;
	static long iv[NTAB];
	float temp;

	if (*idum <= 0 || !iy)
	{
		if (-(*idum) < 1)
		{
			*idum = 1 + *idum;
		}
		else
		{
			*idum = -(*idum);
		}
		for (xj = NTAB + 7; xj >= 0; xj--)
		{
			xk = (*idum) / IQ;
			*idum = IA * (*idum - xk * IQ) - IR * xk;
			if (*idum < 0)
			{
				*idum += IM;
			}
			if (xj < NTAB)
			{
				iv[xj] = *idum;
			}
		}
		iy = iv[0];
	}

	xk = (*idum) / IQ;
	*idum = IA * (*idum - xk * IQ) - IR * xk;
	if (*idum < 0)
	{
		*idum += IM;
	}
	xj = iy / NDIV;
	iy = iv[xj];
	iv[xj] = *idum;

	if ((temp = AM*iy) > RNMX)
	{
		return(RNMX);
	}
	else
	{
		return(temp);
	}
}