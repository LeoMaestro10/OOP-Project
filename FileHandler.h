#pragma once
#ifndef FILEHANDLER_H
#define FILEHANDLER_H
#include<string>
#include<fstream>
#include"Course.h"
#include"Student.h"
using namespace std;

class FileHandler
{
private:
	string FileName;
	ios::openmode modder;
	fstream Filer;
public:
	FileHandler()
	{
		Filer;
	}
	void file_Opener(string name, ios::openmode mode)
	{
		Filer.open(name, mode);
	}
	void file_Closer()
	{
		Filer.close();
	}
	void file_Reader(Student*& stu_pointer, int& students_En)
	{
		Filer >> students_En;
		stu_pointer = new Student[students_En];
		string stu_Name, stu_first_Name, stu_Last_Name;
		string stu_roll_No;
		int stu_Age;
		long double stu_Contact;
		for (int i = 0; i < students_En; i++)
		{
			Filer >> stu_first_Name;
			Filer >> stu_Last_Name;
			stu_Name = stu_first_Name + " " + stu_Last_Name;
			Filer >> stu_Age;
			Filer >> stu_roll_No;
			Filer >> stu_Contact;
			stu_pointer[i].file_reader(stu_Name, stu_roll_No, stu_Age, stu_Contact);
		}
	}
	void read(Course*& co_pointer, int& course_En)
	{
		Filer >> course_En;
		co_pointer = new Course[course_En];
		string co_Code, co_Name, co_Instructor, co_Instructor_First, co_Instructor_Last;
		int co_Credits, co_Capacity;
		for (int i = 0; i < course_En; i++)
		{
			Filer >> co_Code;
			Filer >> co_Name;
			Filer >> co_Instructor_First;
			Filer >> co_Instructor_Last;
			co_Instructor = co_Instructor_First + " " + co_Instructor_Last;
			Filer >> co_Credits;
			Filer >> co_Capacity;
			fstream student_Reader;
			Student* cour_Students = 0;
			int stu_Enrolled;
			string name_Of_File = co_Code + ".txt";
			student_Reader.open(name_Of_File, ios::in);
			if (student_Reader)
			{
				student_Reader >> stu_Enrolled;
				cour_Students = new Student[stu_Enrolled];
				string first_Name, last_Name;
				for (int j = 0; j < stu_Enrolled; j++)
				{
					student_Reader >> first_Name;
					student_Reader >> last_Name;
					cour_Students[j].Name = first_Name + " " + last_Name;
					student_Reader >> cour_Students[j].Age;
					student_Reader >> cour_Students[j].roll_No;
					student_Reader >> cour_Students[j].contact;
					string name_Of_File2 = co_Code + cour_Students[j].roll_No + ".txt";
					fstream attendance_Reader;
					attendance_Reader.open(name_Of_File2, ios::in);
					attendance_Reader >> cour_Students[j].total_Attendance;
					cour_Students[j].attendance = new char[cour_Students[j].total_Attendance];
					for (int k = 0; k < cour_Students[j].total_Attendance; k++)
					{
						attendance_Reader >> cour_Students[j].attendance[k];
					}
					attendance_Reader.close();
					string name_Of_File3 = co_Code + cour_Students[j].roll_No + "M" + ".txt";
					attendance_Reader.open(name_Of_File3, ios::in);
					attendance_Reader >> cour_Students[j].total_Marks;
					cour_Students[j].marks = new int[cour_Students[j].total_Marks];
					for (int k = 0; k < cour_Students[j].total_Marks; k++)
					{
						attendance_Reader >> cour_Students[j].marks[k];
					}
					attendance_Reader.close();
				}
			}
			else
			{
				stu_Enrolled = 0;
				cour_Students = 0;
			}
			student_Reader.close();
			co_pointer[i].file_reader(co_Code, co_Name, co_Instructor, co_Credits, co_Capacity, cour_Students, stu_Enrolled);
		}
	}
	template<typename decider>
	void operator<<(decider writer)
	{
		Filer << writer;
	}
	template<typename decider1>
	void operator>>(decider1& reader)
	{
		Filer >> reader;
	}
	bool operator!()
	{
		return (Filer.eof() == 0);
	}
};
#endif 
