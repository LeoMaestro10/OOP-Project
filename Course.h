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
	Course()
	{
		course_Code = "";
		course_Name = "";
		course_Instructor = "";
		course_Credits = 0;
		course_Students = 0;
		course_Capacity = 0;
		students_Enrolled = 0;

	}
	Course(string c_Code, string c_Name, string c_Instrutor, float c_Credits, double c_Capacity, int st_Enrolled, Student* c_Students)
	{
		course_Code = c_Code;
		course_Name = c_Name;
		course_Instructor = c_Instrutor;
		course_Credits = c_Credits;
		course_Capacity = c_Capacity;
		students_Enrolled = st_Enrolled;
		course_Students = c_Students;
	}
	void students_Displayer()
	{
		system("cls");
		cout << endl;
		cout << course_Code << "\t\t";
		cout << course_Name << "\t\t";
		cout << course_Instructor << "\t\t";
		cout << course_Capacity << "\t\t";
		cout << students_Enrolled << "\t\t";
		for (int i = 0; i < students_Enrolled; i++)
		{
			cout << course_Students[i];
		}
	}
	void student_Enroller()
	{
		FileHandler fin;
		int temporary = students_Enrolled;
		students_Enrolled++;
		string full_Name, first_name, last_name, roll_Number;
		int age, * e_Marks = 0, t_Att = 0;
		long double contact;
		char* din_att = 0;
		cout << "Enter First Name : ";
		cin >> first_name;
		cout << "Enter Last Name : ";
		cin >> last_name;
		full_Name = first_name + " " + last_name;
		cout << "Enter Age : ";
		cin >> age;
		cout << "Enter Roll Number : ";
		cin >> roll_Number;
		cout << "Enter Contact : ";
		cin >> contact;
		if (temporary > 0)
		{
			Student* temp = new Student[students_Enrolled];
			for (int i = 0; i < temporary; i++)
			{
				temp[i] = course_Students[i];
			}
			temp[students_Enrolled - 1] = Student(full_Name, roll_Number, age, contact, din_att, e_Marks, t_Att, course_Code);
			int stu = temp[0].total_Att_Getter();
			temp[students_Enrolled - 1].attendance_Setter(stu);
			delete[] course_Students;
			course_Students = temp;
		}
		else
		{
			Student* temp = new Student(full_Name, roll_Number, age, contact, din_att, e_Marks, t_Att, course_Code);
			course_Students = temp;
		}
		const char* name_Of_File;
		name_Of_File = string_Helper::str_From_Memory(course_Code + ".txt");
		remove(name_Of_File);
		fin.file_Opener(name_Of_File, ios::app);
		fin << students_Enrolled;
		fin << '\n';
		for (int i = 0; i < students_Enrolled; i++)
		{
			fin << course_Students[i].name_Getter();
			fin << "\t\t";
			fin << course_Students[i].umar_Getter();
			fin << "\t\t";
			fin << course_Students[i].roll_Getter();
			fin << "\t\t";
			fin << course_Students[i].rabta_Getter();
			fin << "\n";
		}
		fin.file_Closer();
	}
	void student_Remover()
	{
		FileHandler fin;
		string roll_No;
		Student* temp;
		int length;
		system("cls");
		cout << "Enter Roll No : ";
		cin >> roll_No;
		bool checker = 0;
		for (size_t i = 0; i < students_Enrolled; i++)
		{
			if (roll_No == course_Students[i].roll_Getter())
			{
				checker = 1;
				length = students_Enrolled - 1;
				temp = new Student[length];
				int k = 0;
				for (int j = 0; j < students_Enrolled; j++)
				{
					if (roll_No == course_Students[j].roll_Getter())
					{
						continue;
					}
					else
					{
						temp[k] = course_Students[j];
						k++;
					}
				}
				delete[] course_Students;
				course_Students = temp;
				students_Enrolled = length;
			}
		}
		if (!checker)
		{
			cout << "Sorry ! Roll No Not Found . ";
		}
		const char* name_Of_File;
		name_Of_File = string_Helper::str_From_Memory(course_Code + ".txt");
		remove(name_Of_File);
		fin.file_Opener(name_Of_File, ios::app);
		fin << students_Enrolled;
		fin << '\n';
		for (int i = 0; i < students_Enrolled; i++)
		{
			fin << course_Students[i].name_Getter();
			fin << "\t\t";
			fin << course_Students[i].umar_Getter();
			fin << "\t\t";
			fin << course_Students[i].roll_Getter();
			fin << "\t\t";
			fin << course_Students[i].rabta_Getter();
			fin << "\n";
		}
		fin.file_Closer();
	}
	void operator=(const Course& object)
	{
		course_Code = object.course_Code;
		course_Name = object.course_Name;
		course_Instructor = object.course_Instructor;
		course_Credits = object.course_Credits;
		course_Capacity = object.course_Capacity;
		students_Enrolled = object.students_Enrolled;
		course_Students = new Student[students_Enrolled];
		for (int i = 0; i < students_Enrolled; i++)
		{
			course_Students[i] = object.course_Students[i];
		}
	}
	void input_Getter()
	{
		system("cls");
		string inst_f_name, inst_l_name;
		cout << "Enter Course Code : ";
		cin >> course_Code;
		cout << "Enter Course Name : ";
		cin >> course_Name;
		cout << "Enter First Name Of Instructor : ";
		cin >> inst_f_name;
		cout << "Enter Last Name Of Instructor : ";
		cin >> inst_l_name;
		course_Instructor = inst_f_name + " " + inst_l_name;
		cout << "Enter Course Credit Hours : ";
		cin >> course_Credits;
		cout << "Enter Students Capacity Of Course : ";
		cin >> course_Capacity;
		students_Enrolled = 0;
		course_Students = 0;
	}
	Course* student_Details_Editor(int stu)
	{
		Course* temp = this;
		string rol_Number;
		int length, moye, moya;
		bool flag = 0;
		system("cls");
		cout << "Enter Roll No : ";
		cin >> rol_Number;
		for (int i = 0; i < stu; i++)
		{
			length = temp[i].students_Enrolled;
			for (int j = 0; j < length; j++)
			{
				if (rol_Number == temp[i].course_Students[j].roll_Getter())
				{
					temp[i].course_Students[j].student_Info_Updater();
					moye = i;
					moya = j;
					flag = 1;
					FileHandler fin;
					const char* editor;
					editor = string_Helper::str_From_Memory(temp[i].course_Code + ".txt");
					remove(editor);
					fin.file_Opener(editor, ios::app);
					fin << temp[i].students_Enrolled;
					fin << '\n';
					for (int k = 0; k < temp[i].students_Enrolled; k++)
					{
						fin << temp[i].course_Students[k].name_Getter();
						fin << "\t\t";
						fin << temp[i].course_Students[k].umar_Getter();
						fin << "\t\t";
						fin << temp[i].course_Students[k].roll_Getter();
						fin << "\t\t";
						fin << temp[i].course_Students[k].rabta_Getter();
						fin << '\n';
					}
					fin.file_Closer();
					break;
				}
			}
			if (flag == true)
			{
				break;
			}
		}
		if (flag == 1 && moye != stu - 1)
		{
			for (int i = moye + 1; i < stu; i++)
			{
				length = temp[i].students_Enrolled;
				for (int j = 0; j < length; j++)
				{
					if (rol_Number == temp[i].course_Students[j].roll_Getter())
					{
						temp[i].course_Students[j] = temp[moye].course_Students[moya];
						FileHandler fin;
						const char* name_File;
						name_File = string_Helper::str_From_Memory(temp[i].course_Code + ".txt");
						remove(name_File);
						fin.file_Opener(name_File, ios::app);
						fin << temp[i].students_Enrolled;
						fin << '\n';
						for (int k = 0; k < temp[i].students_Enrolled; k++)
						{
							fin << temp[i].course_Students[k].name_Getter();
							fin << "\t\t";
							fin << temp[i].course_Students[k].umar_Getter();
							fin << "\t\t";
							fin << temp[i].course_Students[k].roll_Getter();
							fin << "\t\t";
							fin << temp[i].course_Students[k].rabta_Getter();
							fin << '\n';
						}
						fin.file_Closer();
					}
				}
			}
		}
		else
		{
			cout << "Sorry ! Student Not Found . " << endl;
			return this;
		}
		return temp;
	}
	void file_reader(string coco_Code, string coco_name, string coco_inst, int credit, int space, Student* object, int total)
	{
		course_Code = coco_Code;
		course_Name = coco_name;
		course_Instructor = coco_inst;
		course_Credits = credit;
		course_Capacity = space;
		students_Enrolled = total;
		if (total > 0)
		{
			course_Students = new Student[total];
			for (int i = 0; i < total; i++)
			{
				course_Students[i] = object[i];
			}
		}
		else
		{
			students_Enrolled = 0;
			course_Students = 0;
		}
	}
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
