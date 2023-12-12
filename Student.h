#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>
#include <fstream>
#include"FileHandler.h"
#include"Course.h"

using namespace std;

class string_Helper
{
public:

	static int str_Len(string str)
	{
		int count = 0;
		for (; str[count] != '\0'; count++)
			return count;	
	}

	static void str_Cpy(char* destination, string source)
	{
		int i;
		for ( i = 0; source[i]!='\0'; i++)
		{
			destination[i] = source[i];
		}
		destination[i] = '\0';
	}
	static char* str_From_Memory(string array)
	{
		int length = str_Len(array);
		char* temp = new char[length];
		str_Cpy(temp, array);
		return temp;
	}
	static bool str_Finder(char* str, const char*& substring)
	{
		for (int i = 0; str[i]!= '\0'; i++)
		{
			if (substring[0]==str[i])
			{

				bool flag = 1;
				int k = i;
				for (int j = 0; substring[j]!='\0'; j++,k++)
				{
					if (str[k]!=substring[j])
					{
						flag = 0;
					}
				}
				if (flag==1)
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
	string Name;
	string roll_No;
	int Age;
	long double contact;
	int total_Attendance;
	char* attendance;
	int* marks;
	int total_Marks;

public:
	friend class FileHandler;
	Student()// Default Constructor
	{
		Name = "";
		roll_No = "";
		Age = 0;
		contact = 0;
		total_Attendance = 0;
		attendance = 0;
		marks = 0;
		total_Marks = 0;
	}
	Student(string st_Name, string st_Roll, int Umer, long double Raabta, char* day_Att, int* each_marks, int to_Att, string c_Code) // parameterized Constructor
	{
		Name = st_Name;
		roll_No = st_Roll;
		Age = Umer;
		contact = Raabta;
		attendance = day_Att;
		total_Attendance = to_Att;
		marks = each_marks;
		string stu_File = c_Code + roll_No + ".txt";
		FileHandler fin;
		fin.file_Opener(stu_File, ios::out);
		fin.file_Closer();
	}
	void attendance_Marker(string course_Code)
	{
		if (total_Attendance>0)
		{
			for (int i = 0; i < total_Attendance; i++)
			{
				cout << attendance[i] << " ";
			}
			char today_Attendance;
			cout << "Enter Today's Attendance : ";
			cin >> today_Attendance;
			char* att;
			int length_Att = total_Attendance + 1;
			att = new char[length_Att];
			int m = 0;
			for ( m; m < total_Attendance; m++)
			{
				att[m] = attendance[m];
			}
			att[m] = today_Attendance;
			delete[] attendance;
			attendance = att;
			total_Attendance = length_Att;
			string att_Sheet = roll_No + ".txt";
			const char* filename = string_Helper::str_From_Memory(course_Code + att_Sheet);
			remove(filename);
			FileHandler fin;
			fin.file_Opener(filename, ios::app);
			fin << total_Attendance;
			fin << '\n';
			for (int i = 0; i < total_Attendance; i++)
			{
				fin << attendance[i];
				fin << "  ";
			}
			fin.file_Closer();
		}
		else
		{
			total_Attendance += 1;
			attendance = new char[total_Attendance];
			cin >> attendance[total_Attendance - 1];
			string att_Sheet = roll_No + ".txt";
			const char* filename = string_Helper::str_From_Memory(course_Code + att_Sheet);
			remove(filename);
			FileHandler fin;
			fin.file_Opener(filename, ios::app);
			fin << total_Attendance;
			fin << '/n';
			fin << attendance[total_Attendance - 1];
			fin << " ";
			fin.file_Closer();
		}
	}
	void marks_Assigner(string course_Code)
	{
		if (total_Marks>0)
		{
			for (int i = 0; i < total_Marks; i++)
			{
				cout << marks[i] << "  ";
			}
			int today_Marks;
			cin >> today_Marks;
			int* mar;
			int length_Marks = total_Marks + 1;
			mar = new int[length_Marks];
			int m = 0;
			for (m; m < total_Marks; m++)
			{
				mar[m] = marks[m];
			}
			mar[m] = today_Marks;
			delete[] marks;
			marks = mar;
			total_Marks = length_Marks;
			string Mark_Sheet = roll_No +"M"+".txt";
			const char* filename = string_Helper::str_From_Memory(course_Code + Mark_Sheet);
			remove(filename);
			FileHandler fin;
			fin.file_Opener(filename, ios::app);
			fin << total_Marks;
			fin << '/n';
			for (int i = 0; i < total_Marks; i++)
			{
				fin << marks[i];
				fin << "  ";
			}
			fin.file_Closer();

		}
		else
		{
			total_Marks += 1;
			marks = new int[total_Marks];
			cin >> attendance[total_Marks - 1];
			string Mark_Sheet = roll_No +"M" + ".txt";
			const char* filename = string_Helper::str_From_Memory(course_Code + Mark_Sheet);
			FileHandler fin;
			fin.file_Opener(filename, ios::app);
			fin << total_Attendance;
			fin << '/n';
			fin << attendance[total_Attendance - 1];
			fin << " ";
			fin.file_Closer();
		}
	}
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
		if (total_Attendance>0)
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
		out << object.Name << "\t";
		out << object.Age << "\t";
		out << object.roll_No << "\t";
		out << object.contact << "\t";
	}
	void file_reader(string naam = " ", string roll = " ", int umar = 0, long double rabta = 0)
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
	long double rabta_Getter()
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
		string first_Name,last_Name;
		cout << endl;
		cout << "Enter Updated Details Of Student" << endl << endl;
		cout << "Enter First Name : ";
		cin >> first_Name;
		cout << "Enter Last Name : ";
		cin >> last_Name;
		Name = first_Name + " " + last_Name;
		cout << "Enter Age : ";
		cin >> Age;
		cout << "Enter Contact No : ";
		cin >> contact;
		cout << "Enter Roll No : ";
		cin >> roll_No;
		
	}
	void attendance_Displayer()
	{
		if (total_Attendance==0)
		{
			cout << "Sorry ! There hasn't Been Any Class Held ." << endl;
		}
		else
		{
			for (int i = 0; i < total_Attendance; i++)
			{
				cout << attendance[i];
				if (i!=total_Attendance-1)
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

#endif // STUDENT_H
