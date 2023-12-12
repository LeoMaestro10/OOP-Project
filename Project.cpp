#include<iostream>
#include<fstream>
#include"FileHandler.h"
#include"Course.h"
#include"Student.h"
using namespace std;


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