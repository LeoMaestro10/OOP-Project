#include<iostream>
#include<fstream>
using namespace std;
class Student
{
	string Name;
	string roll_No;
	int Age;
	long double contact;
	string Courses;
	//char Attendance[];
	int marks;

private:

};
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


};

class System
{
	double Students;
	int Courses;
	int Menus;

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

				}

			}
			else if (sub_Choice==2)
			{

			}
			else if (sub_Choice == 3)
			{

			}
			else if (sub_Choice == 4)
			{

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

			}
			else if (sub_Choice==2)
			{

			}
			else if (sub_Choice==3)
			{
				this->main_Menu();
			}
			else
			{

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

			}
			else if (sub_Choice == 2)
			{

			}
			else if (sub_Choice == 3)
			{
				this->main_Menu();
			}
			else
			{

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

			}
			else if (sub_Choice == 2)
			{

			}
			else if (sub_Choice == 3)
			{
				this->main_Menu();
			}
			else
			{

			}
		}
		else if (choice == 3)
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
			else
			{

			}
			}
	}
	

};

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
	void file_Reader(Student* &stu_pointer, int &students_En)
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
		//Student* course_Students;
		//int students_Enrolled;
		for (int i = 0; i < course_En; i++)
		{
			Filer >> co_Code;
			Filer >> co_Name;
			Filer >> co_Instructor;
			Filer >> co_Credits;
			Filer >> co_Capacity;
			co_pointer[i].file_reader(co_Code, co_Name, co_Instructor, co_Credits,co_Capacity);
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