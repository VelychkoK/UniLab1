#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>

using namespace std;

class Student
{
	string name;
	string surname;
	string subject;
	int score;
	
public:

	void takeInfo(string name, string surname, string subject, int score)
	{
		this->name = name;
		this->surname = surname;
		this->subject = subject;
		this->score = score;
		
	}

	string getName()
	{
		return name;
	}
	string getSurname()
	{
		return surname;
	}
	string getSubject()
	{
		return subject;
	}
	int getScore()
	{
		return score;
	}
	
	void dataOutput()
	{
		cout << "Student " << surname << " " << name << "\thave " << score << " points" << " from " << subject << "\n";
	}
};

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	string str;
	int rowCounter = 0, currentSubject;

	ifstream fin("data.txt");

	cout << "Enter a subject: Math = 0, Physics = 1, IT = 2\n";
	cin >> currentSubject;

	if (fin)
	{
		while (!fin.eof())
		{
			if (rowCounter == 0)
			{
				fin.ignore(255, '\n');
			}
			
			getline(fin, str, '\n');
			rowCounter++;
			
		}
	
		Student* classObjPointer = new Student[rowCounter];
		fin.clear();
		fin.seekg(0);
	
		fin.ignore(255, '\n');

		for (int i = 0; i < rowCounter; i++)
		{
			string name;
			string surname;
			string subject;
			int scoreMath;
			int scoreInf;
			int scorePhis;

			fin >> surname;
			fin >> name;

			fin >> scoreMath;
			fin >> scorePhis;
			fin >> scoreInf;

			if (currentSubject == 0)
			{
				subject = "Math";
				classObjPointer[i].takeInfo(name, surname, subject,  scoreMath);
			}
			else if (currentSubject == 1)
			{
				subject = "Physics";
				classObjPointer[i].takeInfo(name, surname, subject, scorePhis);
			}
			else
			{
				subject = "IT";
				classObjPointer[i].takeInfo(name, surname, subject, scoreInf);
			}
			
		}

		for (int i = 0; i < rowCounter; i++)
		{
			for (int j = i + 1; j < rowCounter; j++)
			{
				if (classObjPointer[i].getSurname() > classObjPointer[j].getSurname())
				{
					swap(classObjPointer[i], classObjPointer[j]);
				}
				if (classObjPointer[i].getScore() < classObjPointer[j].getScore())
				{
					swap(classObjPointer[i], classObjPointer[j]);
				}
			}
		}

		for (int i = 0; i < rowCounter; i++)
		{
			classObjPointer[i].dataOutput();
		}
				
		fin.close();
		delete[]classObjPointer;

	}
	else
	{
		cout << "Unable to open file";
	}

}
