
#include <windows.h>
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <string>
#include <iomanip>

using namespace std;
int main(int argc, char* argv[])
{ 
	int choice, i = 1;
	string Patient_name;
	string Patient_surname;
	string Id;
	string Tel;
	int Patient_age;
	char Patient_gender;
	string date;
	string doc_name;
	string Diagnosis;
	double Fee;
	char ans = 'e';
	do
	{
		cout << "\n\n"; 

		cout << " What would you like to do ? " << endl;
		cout << "\n"; 
		cout << " 1) Patient Registration " << endl;
		cout << " 2) Create an Appointment " << endl;
		cout << " 3) Show Appointments " << endl;
		cout << " 4) Exit Program " << endl;
		cin >> choice;
	} while (choice != 1 && choice != 2 && choice != 3 && choice != 4);
	if (choice == 1)
	{
		ofstream FileWrite;
		FileWrite.open("Patient.txt", ios::app);
		do
		{
			cout << "\n Patient ID :"; cin >> Id;
			cout << "\n Patient Name :"; cin >> Patient_name;
			cout << "\n Patient Surname :"; cin >> Patient_surname;
			cout << "\n Patient Age :"; cin >> Patient_age;
			cout << "\n Telephone No :"; cin >> Tel;
			cout << "\n Gender :"; cin >> Patient_gender;
			FileWrite << Id << " " << Patient_name << ' ' << Patient_surname << ' '
				<< Patient_age << ' ' << Tel << ' '
				<< Patient_gender << "\n";
			cout << "\n Would you like to make another registration? (y/n) "; cin >> ans;
		} while (!(ans == 'n'));
		FileWrite.close();
		cout << "File was created successfully. ";
	}
	if (choice == 2)
	{
		string ID;
		cout << " Patient ID :"; cin >> ID;
		ifstream FileRead("Patient.txt");
		while (!FileRead.eof())
		{
			FileRead >> Id >> Patient_name >> Patient_surname
				>> Patient_age >> Tel >> Patient_gender;
			if (ID == Id)
			{
				cout << "\n Patient Information \n";
				cout << " ***********************\n\n";
				cout << "ID no :" << Id << endl;
				cout << "Name :" << Patient_name << endl;
				cout << "Surname :" << Patient_surname << endl;
				cout << "Age :" << Patient_age << endl;
				cout << "Telephone no :" << Tel << endl;
				cout << "Gender:" << Patient_gender << endl;
				cout << "\n ";
				cout << " Do you want to make an appointment? (y/n)" << endl;
				cin >> ans;
				if (ans == 'y')
				{
					FileRead.close();
					ofstream FileWrite;
					FileWrite.open("Appointment.txt", ios::app);
					cout << "\n Appointment Details \n";
					cout << "\n Date :"; cin >> date;
					cout << "\n Doctor's Name :"; cin >> doc_name;
					cout << "\n Diagnosis :"; cin >> Diagnosis;
					cout << "\n Appointment Fee :"; cin >> Fee;
					FileWrite << Id << ' ' << date << ' ' << doc_name << ' '
						<< Diagnosis << ' ' << Fee <<"€"<< "\n";
					FileWrite.close();
					system("PAUSE");
					exit(0);
				}
				else
				{
					exit(0);
				}
			}
		}
	}
	

	if (choice == 3)
	{
		string ID;
		cout << " Patient ID :"; cin >> ID;
		ifstream FileRead("Patient.txt");
		while (!FileRead.eof())
		{
			FileRead >> Id >> Patient_name >> Patient_surname
				>> Patient_age >> Tel >> Patient_gender;
			if (ID == Id)
			{
				cout << "\n Patient Information \n";
				cout << " ID no :" << Id << endl;
				cout << " Name :" << Patient_name << endl;
				cout << " Surname :" << Patient_surname << endl;
				cout << " Age :" << Patient_age << endl;
				cout << " Telephone No :" << Tel << endl;
				cout << " Gender:" << Patient_gender << endl;
				ID = Id;
				FileRead.close();
				ofstream FileWrite;
				FileRead.open("Appointment.txt", ios::in);
				cout << "\n        Appointment Details \n" << endl;
				cout << "         *********************\n\n";
				cout << setw(8) << " ID " << setw(11) << " Date " << setw(17) << " Doctor's Name " << setw(13)
					<< " Diagnosis " << setw(7) << " Fee" << endl;
				while (!FileRead.eof())
				{
					FileRead >> Id >> date >> doc_name >> Diagnosis >> Fee;
					if (ID == Id)
					{
						cout << setw(12) << Id << setw(14) << date << setw(12) << doc_name
							<< setw(9)
							<< Diagnosis << setw(6) << Fee << endl;
							cout << "\n\n";
					}
				}
				FileWrite.close();
				system("PAUSE");
				exit(0);
			}
		}
	}
	if (choice==4)
	{
		system("PAUSE");
		exit(0);
	}
	
}
