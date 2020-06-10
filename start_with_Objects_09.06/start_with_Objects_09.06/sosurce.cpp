#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
using namespace std;

//
//class Student
//{
//private:
//    char name[30];
//    char lastname[30];
//public:
//    Student() {
//        cout << "Student constructor()\n";
//        strcpy(name, "");
//        strcpy(lastname, "");
//    }
//    Student(const char* n, const char* l) {
//        cout << "Student constructor(n,l)\n";
//        //        strcpy(name, n);
//        //        strcpy(lastname, l);
//        setName(n);
//        setLastname(l);
//    }
    //~Student() {
    //    cout << "Student ~Destructor\n";
    //}
    //void setName(const char* n) {
    //    strcpy(name, n);
    //}
    //void setLastname(const char* n) {
    //    strcpy(lastname, n);
    //}
    //const char* getName() {
    //    return name;
    //}
    //const char* getLastname() {
    //    return lastname;
    //}
//};
//
//
//class Point {
//    int x;
//    int y;
//public:
//    Point() {
//        x = 0;
//        y = 0;
//    }
//    Point(int a, int b) {
//        setX(a);
//        setY(b);
//    }
//    void setX(int a) {
//        x = abs(a);
//    }
//    void setY(int a) {
//        y = abs(a);
//    }
//    int getX() { return x; }
//    int getY() { return y; }
//};
//
//int main()
//{
//    Point p(5, -10);
//    cout << p.getX() << " " << p.getY() << endl;
//
//
//    //    {
//    //        Student student("Alex", "Klar");
//    //        //    student.setName("Alex");
//    //        //    student.setLastname("Klar");
//    //
//    //        cout << student.getName() << "\t" << student.getLastname() << endl;
//    //    }
//    //
//    //    cout << "End of program\n";
//    return 0;
//}

class Group {
private:
	Student ** students;
	double avgGroupGrade;
	int quant;
	char groupName[30];

public:
	Group() {
		avgGroupGrade = 0;
		quant = 0;
		strcpy(groupName, "EMPTY");
	}

	~Group() {
		cout << "Group destroyed!\n";
	}

	//void addStudentToGroup(const char * n, const char * l, double avg) {
	//	addPlaceForStudent(students);
	//	quant++;
	//	int index = quant - 1;
	//	students[index].setStudent(n, l, avg);
	//}

	void setGroupName(const char* n) { strcpy(groupName, n); }
	void showGroupInfoCOUT() {
		cout << "\nHere is griup information: \n";
		cout << "Quantity: " << quant << "\n";

	}
	double getAvgGroupGrade() {
		double sum = 0;
		for (int i = 0; i < quant; i++)
		{
			sum += students[i]->getAvgGrade;
		}
		return sum / quant;

	}
	void appendGroup(Student s)
	{
		Student ** tmp = new Student *[quant + 1];
		for (int i = 0; i < quant; i++) 
			tmp[i] = students[i];
		tmp[quant] = &s;
		quant++;
		students = tmp;
	}
	//void createDynArr(Student **& arr, int rowCount) {
	//	arr = new char *[rowCount];
	//	for (int i = 0; i < rowCount; i++)
	//		arr[i] = new char[BUF];
	//}

};

class Student {
private:
	char name[30];
	char lastName[30];
	double avgGrade;
public:
	Student() {
		strcpy(name, "EMPTY");
		strcpy(lastName, "EMPTY");
		avgGrade = -1;
	}
	void setStudent(const char * n, const char* l, int g) {
		strcpy(name, n);
		strcpy(lastName, l);
		avgGrade = g;
	}
	~Student() {
		cout << "Student ~Destructor\n";
	}
	void setName(const char* n) {
		strcpy(name, n);
	}
	void setLastname(const char* n) {
		strcpy(lastName, n);
	}
	const char* getName() {
		return name;
	}
	const char* getLastname() {
		return lastName;
	}
	double getAvgGrade() {
		return avgGrade;
	}

};

class Dot {
private:
	int x;
	int y;
	int z;
public:
	Dot() {
		x = 0;
		y = 0;
		z = 0;
	}
	Dot(int oX, int oY, int oZ) {
		x = oX;
		y = oY;
		z = oZ;
	}
	~Dot() {
		cout << "Dot object destryer worked!\n";
	}
	void setX(int oX) {
		x = oX;
	}
	void setY(int oY) {
		y = oY;
	}
	void setZ(int oZ) {
		z = oZ;
	}
	int getX(){
		return x;
	}
	int getY() {
		return y;
	}
	int getZ() {
		return z;
	}
};

void testerDotSetGet() {
	cout << "Test points setters and getters\n";
	Dot firstDot;
	cout << "before filling: " << firstDot.getX() << " " << firstDot.getY() << ' ' << firstDot.getZ() << '\n';
	firstDot.setX(12);
	firstDot.setY(111);
	firstDot.setZ(17);
	cout << "Now filled: " << firstDot.getX() << " " << firstDot.getY() << ' ' << firstDot.getZ() << '\n';

	Dot filledDot(71, 111, 21);
	cout << " new dot that was not filled in program: " << filledDot.getX() << " " << filledDot.getY() << ' ' << filledDot.getZ() << '\n';

	cout << "Test ended!\n";
}

void main() {
	//testerDotSetGet();
	Student st1;
	st1.setStudent("Alex", "Gyver", 5);
	cout << st1.getName() << ' ' << st1.getLastname() << '\n';

	Student st2;
	st2.setStudent("Max", "Bigun", 4);
	cout << st2.getName() << ' ' << st2.getLastname() << '\n';

	Group gr1;
	gr1.setGroupName("ATP-31");
	gr1.appendGroup(st1);
	gr1.showGroupInfoCOUT();

	cout << '\n';
	system("pause");
}
