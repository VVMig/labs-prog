#pragma once
#include <string>
#include <fstream>

using namespace std;

class Patient
{
private:
	class PatientInfo
	{
	private:
		string firstName;
		string surname;
		string secondName;
		string adress;
	public:
		void setFirstName(string firstName);
		void setSurname(string surname);
		void setSecondName(string secondName);
		void setAdress(string adress);
		string getFirstName();
		string getSurname();
		string getSecondName();
		string getAdress();
	};
	int medicalCardNum;
	string diagnosis;
	PatientInfo patient;
public:
	int getMedicalCardNum();
	string getDiagnosis();
	void setMedicalCardNum(int medicalCardNum);
	void setDiagnosis(string diagnosis);
	PatientInfo getPatientInfo();
	void show();
	friend ofstream& operator << (ofstream& f, Patient a);
	friend ifstream& operator >> (ifstream& f, Patient &a);
	friend ostream& operator << (ostream& f, Patient a);
	friend istream& operator >> (istream& f, Patient& a);
};

