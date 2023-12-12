#include<iostream>
#include<fstream>
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

public:
	friend class FileHandler;
	
	


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
		for (int i = 0; i < course_En; i++)
		{
			Filer >> co_Code;
			Filer >> co_Name;
			Filer >> co_Instructor;
			Filer >> co_Credits;
			Filer >> co_Capacity;
			fstream student_Reader;
			
			Student* cour_Students=nullptr;
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
			co_pointer[i].file_reader(co_Code, co_Name, co_Instructor, co_Credits,co_Capacity);
		}
	}
	template <typename decider>
	void operator>>(decider &reader)
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