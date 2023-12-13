#ifndef COURSE_H
#define COURSE_H

#include <iostream>
#include <string>
#include <fstream>
#include"FileHandler.h"
#include"Student.h"
using namespace std;

class Course
{
private:
	string course_Code;
	string course_Name;
	string course_Instructor;
	float course_Credits;
	double course_Capacity;
	Student* course_Students;
	int students_Enrolled;

public:
	friend class FileHandler;
	
	Course();
	Course(string c_Code, string c_Name, string c_Instrutor, float c_Credits, double c_Capacity, int st_Enrolled, Student* c_Students);
	void students_Displayer();
	void student_Enroller();
	void student_Remover();
	void operator=(const Course& object);
	void input_Getter();
	Course* student_Details_Editor(int stu);
	void file_reader(string coco_Code, string coco_name, string coco_inst, int credit, int space, Student* object, int total);
	void available_Course()
	{
		cout << "[ " << course_Code << " ]  " << course_Name << endl;
	}
	string code_Getter()
	{
		return course_Code;
	}
	string name_Getter()
	{
		return course_Name;
	}
	string inst_Getter()
	{
		return course_Instructor;
	}
	int credit_Getter()
	{
		return course_Credits;
	}
	int space_Getter()
	{
		return course_Capacity;
	}
	void Attendance_Shower()
	{
		for (int i = 0; i < students_Enrolled; i++)
		{
			cout << course_Students[i].name_Getter() << " : ";
			course_Students[i].attendance_Displayer();
		}
	}
	void Attendance_Marker()
	{
		for (int i = 0; i < students_Enrolled; i++)
		{
			cout << course_Students[i].name_Getter() << " : ";
			course_Students[i].attendance_Marker(course_Code);
		}
	}
	void marks_Assigner()
	{
		for (int i = 0; i < students_Enrolled; i++)
		{
			cout << course_Students[i].name_Getter() << " : ";
			course_Students[i].marks_Assigner(course_Code);
		}
	}
	void marks_Displayer()
	{
		for (int i = 0; i < students_Enrolled; i++)
		{
			cout << course_Students[i].name_Getter() << " : ";
			course_Students[i].Marks_Displayer();
		}
	}
	~Course()
	{
		course_Code = " ";
		course_Name = " ";
		course_Instructor = " ";
		course_Credits = 0;
		students_Enrolled = 0;
		if (course_Students)
		{
			delete[]course_Students;
		}
		else
		{
			course_Students = 0;
		}
	}
};

#endif 
