#pragma once
#ifndef STUDENT_H
#define STUDENT_H

#include<iostream>
#include<string>
#include"Filehandler.h"
using namespace std;
class string_Helper
{
public:
	static void str_Cpy(char* destination, string source)
	{
		int i;
		for (i = 0; source[i] != '\0'; i++)
		{
			destination[i] = source[i];
		}
		destination[i] = '\0';
	}
	static char* str_From_Memory(string array)
	{
		int length = array.length();
		char* temp = new char[length];
		str_Cpy(temp, array);
		return temp;
	}
	static bool str_Finder(char* str, const char*& substring)
	{

		for (int i = 0; str[i] != '\0'; i++)
		{
			if (substring[0] == str[i])
			{
				bool flag = true;
				int k = i;
				for (int j = 0; substring[j] != '\0'; j++, k++)
				{
					if (str[k] != substring[j])
					{
						flag = false;
					}
				}
				if (flag == true)
				{
					return true;
				}
			}
		}
		return false;
	}
};
class Student
{
private:
	string Name;
	string roll_No;
	int Age;
	long long contact;
	int total_Attendance;
	char* attendance;
	int* marks;
	int total_Marks;
public:
	friend class FileHandler;
	Student();
	Student(string st_Name, string st_Roll, int Umer, long double Raabta, char* day_Att, int* each_marks, int to_Att, string c_Code);
	void attendance_Marker(string course_Code);
	void marks_Assigner(string course_Code);
	Student(const Student& object)
	{
		Name = object.Name;
		roll_No = object.roll_No;
		Age = object.Age;
		contact = object.contact;
		attendance = object.attendance;
		marks = object.marks;
	}
	void operator=(const Student& object)
	{
		Name = object.Name;
		roll_No = object.roll_No;
		Age = object.Age;
		contact = object.contact;
		attendance = object.attendance;
		marks = object.marks;
		total_Attendance = object.total_Attendance;
		if (total_Attendance > 0)
		{
			attendance = new char[total_Attendance];
			for (int i = 0; i < total_Attendance; i++)
			{
				attendance[i] = object.attendance[i];
			}
		}
		total_Marks = object.total_Marks;
		if (total_Marks > 0)
		{
			marks = new int[total_Marks];
			for (int i = 0; i < total_Marks; i++)
			{
				marks[i] = object.marks[i];
			}
		}
	}
	friend void operator<<(ostream& out, Student& object)
	{
		out << object.Name << "\t\t";
		out << object.Age << "\t\t";
		out << object.roll_No << "\t\t";
		out << object.contact << endl;
	}
	void file_reader(string naam = " ", string roll = " ", int umar = 0, long long rabta = 0)
	{
		Name = naam;
		roll_No = roll;
		Age = umar;
		contact = rabta;
	}
	string name_Getter()
	{
		return Name;
	}
	string roll_Getter()
	{
		return roll_No;
	}
	int umar_Getter()
	{
		return Age;
	}
	long long rabta_Getter()
	{
		return contact;
	}
	int total_Att_Getter()
	{
		return total_Attendance;
	}
	void attendance_Setter(int at)
	{
		total_Attendance = at;
		attendance = new char[total_Attendance];
		for (int i = 0; i < total_Attendance; i++)
		{
			attendance[i] = '-';
		}
	}
	void student_Info_Updater()
	{
		string first_Name, last_Name;
		cout << "\n\"Enter Updated Details Of Student" << endl << endl;
		cout << "Enter First Name : ";
		cin >> first_Name;
		cout << "Enter Last Name : ";
		cin >> last_Name;
		Name = first_Name + " " + last_Name;
		cout << "Enter Age = ";
		cin >> Age;
		cout << "Enter Contact No = ";
		cin >> contact;
		cout << "Enter Roll No = ";
		cin >> roll_No;
	}
	void attendance_Displayer()
	{
		if (total_Attendance == 0)
		{
			cout << "Sorry ! There hasn't Been Any Class Held ." << endl;
		}
		else
		{
			for (int i = 0; i < total_Attendance; i++)
			{
				cout << attendance[i];
				if (i != total_Attendance - 1)
				{
					cout << "  ";
				}
			}
			cout << endl;
		}
	}
	void Marks_Displayer()
	{
		if (total_Marks == 0)
		{
			cout << "Sorry ! There hasn't Been Any Exam Held ." << endl;
		}
		else
		{
			for (int i = 0; i < total_Marks; i++)
			{
				cout << marks[i];
				if (i != total_Marks - 1)
				{
					cout << "  ";
				}
			}
			cout << endl;
		}
	}
	~Student()
	{
		Name = "";
		roll_No = "";
		Age = 0;
		contact = 0;
		if (attendance)
		{
			delete[] attendance;
		}
		else
		{
			attendance = 0;
		}
		if (marks)
		{
			delete[] marks;
		}
		else
		{
			marks = 0;
		}
	}
};
#endif 