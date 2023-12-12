#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include <iostream>
#include <string>
#include <fstream>
#include"Student.h"
#include"Course.h"

using namespace std;

class FileHandler
{
	string FileName;
	fstream Filer; // To open File
	ios::openmode modder; // to decide which mode should the file be opened in

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
		Filer >> students_En; // getting total students from file
		stu_pointer = new Student[students_En];
		string stu_Name;
		string stu_roll_No;
		int stu_Age;
		long double stu_Contact;
		for (int i = 0; i < students_En; i++)
		{
			Filer >> stu_Name;
			Filer >> stu_roll_No;
			Filer >> stu_Age;
			Filer >> stu_Contact;
			stu_pointer[i].file_reader(stu_Name, stu_roll_No, stu_Age, stu_Contact);
		}
	}
	void file_Reader(Course*& co_pointer, int& course_En)
	{
		Filer >> course_En; // getting total students from file
		co_pointer = new Course[course_En];
		string co_Code;
		string co_Name;
		string co_Instructor;
		float co_Credits;
		double co_Capacity;
		for (int i = 0; i < course_En; i++)
		{
			Filer >> co_Code;
			Filer >> co_Name;
			Filer >> co_Instructor;
			Filer >> co_Credits;
			Filer >> co_Capacity;
			fstream student_Reader;

			Student* cour_Students = nullptr;
			int stu_Enrolled;
			string name_Of_File = co_Code + ".txt";
			student_Reader.open(name_Of_File, ios::in);
			if (student_Reader)
			{
				Filer >> stu_Enrolled;
				cour_Students = new Student[stu_Enrolled];
				string first_Name, last_Name;
				for (int j = 0; j < stu_Enrolled; j++)
				{
					student_Reader >> first_Name;
					student_Reader >> last_Name;
					cour_Students[j].Name = first_Name + " " + last_Name;
					student_Reader >> cour_Students[j].roll_No;
					student_Reader >> cour_Students[j].Age;
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
					string name_Of_File3 = co_Code + cour_Students[j].roll_No + "marks.txt";
					fstream marks_Reader;
					marks_Reader.open(name_Of_File3, ios::in);
					marks_Reader >> cour_Students[j].total_Marks;
					cour_Students[j].marks = new int[cour_Students[j].total_Marks];
					for (int l = 0; l < cour_Students[j].total_Marks; l++)
					{
						marks_Reader >> cour_Students[j].marks[l];
					}
					marks_Reader.close();
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
	template <typename decider>
	void operator>>(decider& reader)
	{
		Filer >> reader;
	}
	template <typename decider>
	void operator<<(decider writer)
	{
		Filer << writer;
	}
	bool operator!()
	{
		return (Filer.eof() == 0);
	}

};

#endif 