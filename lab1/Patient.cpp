#include "Patient.h"
#include <string>
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

Patient::PatientInfo Patient::getPatientInfo() {
	return this->patient;
}

string Patient::PatientInfo::getAdress() {
	return this->adress;
}

string Patient::getDiagnosis() {
	return this->diagnosis;
}

string Patient::PatientInfo::getFirstName() {
	return this->firstName;
}

string Patient::PatientInfo::getSecondName() {
	return this->secondName;
}

string Patient::PatientInfo::getSurname() {
	return this->surname;
}

int Patient::getMedicalCardNum() {
	return this->medicalCardNum;
}

void Patient::PatientInfo::setAdress(string adress) {
	this->adress = adress;
}

void Patient::PatientInfo::setFirstName(string firstName) {
	this->firstName = firstName;
}

void Patient::PatientInfo::setSecondName(string secondName) {
	this->secondName = secondName;
}

void Patient::PatientInfo::setSurname(string surname) {
	this->surname = surname;
}

void Patient::setMedicalCardNum(int medicalCardNum) {
	this->medicalCardNum = medicalCardNum;
}

void Patient::setDiagnosis(string diagnosis) {
	this->diagnosis = diagnosis;
}


void Patient::show() {
	cout << setw(15) << this->patient.getSurname() << setw(1) << "|" << setw(1) << setw(15)
		<< setw(15) << this->patient.getFirstName() << setw(1) << "|" << setw(1) << setw(15)
		<< setw(15) << this->patient.getSecondName() << setw(1) << "|" << setw(1) << setw(15)
		<< setw(15) << this->patient.getAdress() << setw(1) << "|" << setw(1) << setw(15)
		<< setw(15) << this->diagnosis << setw(1) << "|" << setw(1) << setw(15)
		<< setw(15) << this->medicalCardNum << setw(1) << "|" << setw(1)<< setw(15) << endl;
}

ofstream& operator<<(ofstream& f, Patient a)
{
	int fieldLength = 15;
	f << setw(fieldLength) << a.patient.getSurname() << setw(1) << "|" << setw(1) << setw(fieldLength) 
		<< setw(fieldLength) << a.patient.getFirstName() << setw(1) << "|" << setw(1) << setw(fieldLength)
		<< setw(fieldLength) << a.patient.getSecondName() << setw(1) << "|" << setw(1) << setw(fieldLength)
		<< setw(fieldLength) << a.patient.getAdress() << setw(1) << "|" << setw(1) << setw(fieldLength)
		<< setw(fieldLength) << a.getDiagnosis() << setw(1) << "|" << setw(1) << setw(fieldLength)
		<< setw(fieldLength) << a.getMedicalCardNum() << setw(1) << "|" << setw(1) << setw(fieldLength) << endl;
	return f;
}

ifstream& operator >> (ifstream& f, Patient &a) {
	string s;

	f >> s;
	a.patient.setSurname(s);

	f >> s;
	a.patient.setFirstName(s);

	f >> s;
	a.patient.setSecondName(s);

	f >> s;
	a.patient.setAdress(s);

	f >> s;
	a.setDiagnosis(s);

	f >> s;
	a.setMedicalCardNum(1);

	return f;
}

ostream& operator<<(ostream& f, Patient a)
{
	int fieldLength = 15;
	f << setw(fieldLength) << a.patient.getSurname() << setw(1) << "|" << setw(1) << setw(fieldLength)
		<< setw(fieldLength) << a.patient.getFirstName() << setw(1) << "|" << setw(1) << setw(fieldLength)
		<< setw(fieldLength) << a.patient.getSecondName() << setw(1) << "|" << setw(1) << setw(fieldLength)
		<< setw(fieldLength) << a.patient.getAdress() << setw(1) << "|" << setw(1) << setw(fieldLength)
		<< setw(fieldLength) << a.getDiagnosis() << setw(1) << "|" << setw(1) << setw(fieldLength)
		<< setw(fieldLength) << a.getMedicalCardNum() << setw(1) << "|" << setw(1) << setw(fieldLength) << endl;
	return f;
}

istream& operator>>(istream& f, Patient& a)
{
	string s;

	f >> s;
	a.patient.setSurname(s);

	f >> s;
	a.patient.setFirstName(s);

	f >> s;
	a.patient.setSecondName(s);

	f >> s;
	a.patient.setAdress(s);

	f >> s;
	a.setDiagnosis(s);

	f >> s;
	a.setMedicalCardNum(1);

	return f;
}

