#include<iostream>
#include<fstream>
#include<string>
#include<stdio.h>
#include<cmath>
#include"FileHandler.h"
#include"Course.h"
#include"Student.h"
using namespace std;
class Course;
class Student;
class Filehandler;

Student::Student()
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
Student::Student(string st_Name, string st_Roll, int Umer, long double Raabta, char* day_Att, int* each_marks, int to_Att, string c_Code) // parameterized Constructor
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
void Student::attendance_Marker(string course_Code )
{
	if (total_Attendance > 0)
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
		for (m; m < total_Attendance; m++)
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
		fin << '\n';
		fin << attendance[total_Attendance - 1];
		fin << " ";
		fin.file_Closer();
	}
}
void Student::marks_Assigner(string course_Code)
{
	if (total_Marks > 0)
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
		string Mark_Sheet = roll_No + "M" + ".txt";
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
		string Mark_Sheet = roll_No + "M" + ".txt";
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
Course::Course()
{
	course_Code = "";
	course_Name = "";
	course_Instructor = "";
	course_Credits = 0;
	course_Students = 0;
	course_Capacity = 0;
	students_Enrolled = 0;
}
Course::Course(string c_Code, string c_Name, string c_Instrutor, float c_Credits, double c_Capacity, int st_Enrolled, Student* c_Students)
{
	course_Code = c_Code;
	course_Name = c_Name;
	course_Instructor = c_Instrutor;
	course_Credits = c_Credits;
	course_Capacity = c_Capacity;
	students_Enrolled = st_Enrolled;
	course_Students = c_Students;
}
void Course::students_Displayer()
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
void Course::student_Enroller()
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
void Course::student_Remover()
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
void Course:: operator=(const Course& object)
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
void Course::input_Getter()
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
Course* Course::student_Details_Editor(int stu)
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
void Course::file_reader(string coco_Code, string coco_name, string coco_inst, int credit, int space, Student* object, int total)
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

class System
{
	double Students;
	int Courses;
	int Menus;
	Course* t_Course;

public:
	void main_Menu()
	{
		start:
		cout << "\t\t\t Welcome To FLEX \t\t\t" << endl<<endl<<endl;
		cout << "\t\t\t Main Menu \t\t\t"<<endl<<endl;
		cout << "1. Enroll A Student" << endl;
		cout << "2. Course Registration" << endl;
		cout << "3. Attendance" << endl;
		cout << "4. Marks" << endl;
		cout << "5. Course Withdrawal" << endl;
		cout << "6. Exit"<<endl<<endl;
		cout << "\tEnter Your Choice ( 1 - 6 ) : ";
		cin >> Menus;

		if (Menus>6 || Menus<=0)
		{
			cout << "Invalid Input Entered !! " << endl;
			goto start;
		}
		else if (Menus<=5)
		{
			this->Sub_Menu(Menus);
		}
		else
		{
			cout << "JazakAllah Khair For Visiting Flex :)" << endl;
		}

	}
	void Sub_Menu(int choice)
	{
		int sub_Choice;
	start1:
		if (choice==1)
		{
			system("cls");
			cout << "\t\t\t ENROLL A STUDENT \t\t\t" << endl << endl;
			cout << "1. Display Already Enrolled Students" << endl;
			cout << "2. Enroll New Student" << endl;
			cout << "3. Remove Already Enrolled Student" << endl;
			cout << "4. Edit Details of Already Enrolled Student" << endl;
			cout << "5. Return to Main Menu" << endl << endl;
			cout << "Enter Your Choice ( 1 - 5 ) : ";
			cin >> sub_Choice;
			if (sub_Choice>5 || sub_Choice<=0)
			{
				cout << "Invalid Input Entered !! " << endl;
				goto start1;
			}
			else if (sub_Choice==1)
			{
				for (int i = 0; i < Courses; i++)
				{
					t_Course[i].students_Displayer();
				}
				goto start1;
			}
			else if (sub_Choice==2)
			{
				int M = 0;
			initiator:
				system("cls");
				cout << "\t\t Available Courses" << endl << endl;
				for (int j = 0; j < Courses; j++)
				{
					cout << "\t" << j << "  ";
					t_Course[j].available_Course();
				}
				do
				{
					if (M<0 || M>Courses)
					{
						system("cls");
						cout << "Invalid Input Entered . " << endl;
						goto initiator;
					}
					cout << "Select Course In Which You Want To Enroll Student : ";
					cin >> M;
				} while (M<0 || M>Courses);
				t_Course[M].student_Enroller();
				goto start1;
			}
			else if (sub_Choice == 3)
			{
				int M = 0;
			initiator1:
				system("cls");
				cout << "\t\t Available Courses" << endl << endl;
				for (int j = 0; j < Courses; j++)
				{
					cout << "\t" << j << "  ";
					t_Course[j].available_Course();
				}
				do
				{
					if (M<0 || M>Courses)
					{
						system("cls");
						cout << "Invalid Input Entered . " << endl;
						goto initiator1;
					}
					cout << "Select Course In Which You Want To Remove Student : ";
					cin >> M;
				} while (M<0 || M>Courses);
				t_Course[M].student_Remover();
				goto start1;
			}
			else if (sub_Choice == 4)
			{
				t_Course = t_Course->student_Details_Editor(Courses);
				goto start1;
			}
			else if (sub_Choice == 5)
			{
				this->main_Menu();
			}
		}
		else if (choice==2)
		{
			system("cls");
			cout << "\t\t\t COURSE REGISTRATION \t\t\t" << endl << endl;
			cout << "1. Available Courses" << endl;
			cout << "2. Register a New Course" << endl;
			cout << "3. Return To Main Menu " << endl;
			cout << "Enter Your Choice ( 1 - 3 ) : ";
			cin >> sub_Choice;
			if (sub_Choice > 3 || sub_Choice <= 0)
			{
				cout << "Invalid Input Entered !! " << endl;
				goto start1;
			}
			else if (sub_Choice==1)
			{
				cout << "\t\tAvailable Courses"<<endl<<endl;
				for (int j = 0; j < Courses; j++)
				{
					t_Course[j].available_Course();
				}
				goto start1;
			}
			else if (sub_Choice==2)
			{
				int i = 0, length = Courses + 1;
				Course* temp = new Course[length];
				for ( i ; i < Courses; i++)
				{
					temp[i] = t_Course[i];
				}
				temp[i].input_Getter();
				delete t_Course;
				t_Course = temp;
				Courses = length;
				FileHandler fin;
				remove("courses.txt");
				fin.file_Opener("courses.txt", ios::app);
				fin << Courses;
				fin << '\n';
				for (int j = 0; j < Courses; j++)
				{
					fin << t_Course[j].code_Getter();
					fin << "\t\t";
					fin << t_Course[j].name_Getter();
					fin << "\t\t";
					fin << t_Course[j].inst_Getter();
					fin << "\t\t";
					fin << t_Course[j].credit_Getter();
					fin << "\t\t";
					fin << t_Course[j].space_Getter();
					fin << '\n';
				}
				fin.file_Closer();
				goto start1;
			}
			else if (sub_Choice==3)
			{
				this->main_Menu();
			}
		}
		else if (choice==3)
		{
			system("cls");
			cout << "\t\t\t ATTENDANCE \t\t\t" << endl << endl;
			cout << "1. Display Subject Wise Attendance " << endl;
			cout << "2. Mark Attendance" << endl;
			cout << "3. Return To Main Menu " << endl;
			cout << "Enter Your Choice ( 1 - 3 ) : ";
			cin >> sub_Choice;
			if (sub_Choice > 3 || sub_Choice <= 0)
			{
				cout << "Invalid Input Entered !! " << endl;
				goto start1;
			}
			else if (sub_Choice == 1)
			{
				int Siu = 0;
			point:
				system("cls");
				cout << "\t\tAvailable Courses" << endl << endl;
				for (int j = 0; j < Courses; j++)
				{
					cout << "\t" << j << "  ";
					t_Course[j].available_Course();
				}
				do
				{
					if (Siu<0 || Siu>Courses)
					{
						system("cls");
						cout << "Invalid Input Entered ." << endl;
						goto point;
					}
					cout << endl << "Which Course's Attendance You Want to Display :  ";
					cin >> Siu;

				} while (Siu<0||Siu>Courses);
				t_Course[Siu].Attendance_Shower();
				goto start1;

			}
			else if (sub_Choice == 2)
			{
				int Siu = 0;
			pointer:
				system("cls");
				cout << "\t\tAvailable Courses" << endl << endl;
				for (int j = 0; j < Courses; j++)
				{
					cout << "\t" << j << "  ";
					t_Course[j].available_Course();
				}
				do
				{
					if (Siu<0 || Siu>Courses)
					{
						system("cls");
						cout << "Invalid Input Entered ." << endl;
						goto pointer;
					}
					cout << endl << "Which Course's Attendance You Want to Mark :  ";
					cin >> Siu;

				} while (Siu<0 || Siu>Courses);
				t_Course[Siu].Attendance_Marker();
				goto start1;
			}
			else if (sub_Choice == 3)
			{
				this->main_Menu();
			}
		}
		else if (choice == 4)
		{
			system("cls");
			cout << "\t\t\t MARKS \t\t\t" << endl << endl;
			cout << "1. Display Subject Wise Marks " << endl;
			cout << "2. Assign Marks" << endl;
			cout << "3. Return To Main Menu " << endl;
			cout << "Enter Your Choice ( 1 - 3 ) : ";
			cin >> sub_Choice;
			if (sub_Choice > 3 || sub_Choice <= 0)
			{
				cout << "Invalid Input Entered !! " << endl;
				goto start1;
			}
			else if (sub_Choice == 1)
			{
				int Siu = 0;
			pointer1:
				system("cls");
				cout << "\t\tAvailable Courses" << endl << endl;
				for (int j = 0; j < Courses; j++)
				{
					cout << "\t" << j << "  ";
					t_Course[j].available_Course();
				}
				do
				{
					if (Siu<0 || Siu>Courses)
					{
						system("cls");
						cout << "Invalid Input Entered ." << endl;
						goto pointer1;
					}
					cout << endl << "Which Course's Marks You Want to Display :  ";
					cin >> Siu;

				} while (Siu<0 || Siu>Courses);
				t_Course[Siu].marks_Displayer();
				goto start1;
			}
			else if (sub_Choice == 2)
			{
				int Siu = 0;
			pointer2:
				system("cls");
				cout << "\t\tAvailable Courses" << endl << endl;
				for (int j = 0; j < Courses; j++)
				{
					cout << "\t" << j << "  ";
					t_Course[j].available_Course();
				}
				do
				{
					if (Siu<0 || Siu>Courses)
					{
						system("cls");
						cout << "Invalid Input Entered ." << endl;
						goto pointer2;
					}
					cout << endl << "Which Course's Marks You Want to Assign :  ";
					cin >> Siu;

				} while (Siu<0 || Siu>Courses);
				t_Course[Siu].marks_Assigner();
				goto start1;
			}
			else if (sub_Choice == 3)
			{
				this->main_Menu();
			}
			
		}
		else if (choice == 5)
		{
			system("cls");
			cout << "\t\t\t COURSE WITHDRAW \t\t\t" << endl << endl;
			cout << "1. Enrolled Courses " << endl;
			cout << "2. Drop A Course" << endl;
			cout << "3. Return To Main Menu " << endl;
			cout << "Enter Your Choice ( 1 - 3 ) : ";
			cin >> sub_Choice;
			if (sub_Choice > 3 || sub_Choice <= 0)
			{
				cout << "Invalid Input Entered !! " << endl;
				goto start1;
			}
			else if (sub_Choice == 1)
			{

			}
			else if (sub_Choice == 2)
			{

			}
			else if (sub_Choice == 3)
			{
				this->main_Menu();
			}
		}
	}
	

};



class Validator
{
public:
	

private:

};

void main()
{
	System claa;
	claa.main_Menu();



	system("pause");
}