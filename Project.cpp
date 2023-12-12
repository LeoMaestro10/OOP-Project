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
		string full_Name, first_name, last_name,roll_Number;
		int age,*e_Marks=0,t_Att=0;
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
		if (temporary>0)
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
			Student*temp=new Student(full_Name, roll_Number, age, contact, din_att, e_Marks, t_Att, course_Code);
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
			if (roll_No==course_Students[i].roll_Getter())
			{
				checker = 1;
				length = students_Enrolled - 1;
				temp = new Student[length];
				int k = 0;
				for (int j = 0; j < students_Enrolled; j++)
				{
					if (roll_No==course_Students[j].roll_Getter())
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
		string inst_f_name,inst_l_name;
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
				if (rol_Number==temp[i].course_Students[j].roll_Getter())
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
			if (flag==true)
			{
				break;
			}
		}
		if (flag==1&&moye!=stu-1)
		{
			for (int i = moye+1; i < stu; i++)
			{
				length = temp[i].students_Enrolled;
				for (int j = 0; j < length; j++)
				{
					if (rol_Number==temp[i].course_Students[j].roll_Getter())
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
		if (total>0)
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
			co_pointer[i].file_reader(co_Code, co_Name, co_Instructor, co_Credits,co_Capacity,cour_Students,stu_Enrolled);
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