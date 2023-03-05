// Lecture3Polymorphism.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
#include<vector>


class Assessment
{
protected:
	int aMark;
	string aTitle;
	double aWeighting;
	int assessmentNumber;
public:
	Assessment() : aMark(0), aWeighting(0.0), assessmentNumber(0)
	{
	}
	int getMark()
	{ 
		return aMark; 
	}
	double getWeighting()
	{
		return aWeighting;
	}
	string getTitle()
	{ 
		return aTitle;
	}
	
	void setWeighting(double aW)
	{
		aWeighting = aW; 
	}
	void setAssessmentNumber(int assessmentNum) {
		assessmentNumber = assessmentNum;
	}
	virtual void enterMark() {}
	virtual void enterWeighting(void) {}
	virtual void enterTitle(void) {}
	virtual ~Assessment() = default;
};
class Coursework : public Assessment
{
public:
	void enterMark()
	{
		do {
			cout << "Enter coursework " << assessmentNumber + 1 << " result < 0 - 100 > = ";
				cin >> aMark;
		} while (aMark < 0 || aMark > 100);
	}

	void enterWeighting(void) 
	{
		do {
			cout << "Enter coursework " << assessmentNumber + 1 << " weighting 0.1 or 0.2 = ";
				cin >> aWeighting;
		} while (!(aWeighting == 0.1 || aWeighting == 0.2));
	}
	void enterTitle(void)
	{
		cout << "Enter coursework " << assessmentNumber + 1 << " title : ";
		cin >> aTitle;
	}
};
class Exam : public Assessment
{
public:
	void enterMark(void)
	{
		do {
			cout << "Enter exam result <0-100> = ";
			cin >> aMark;
		} while (aMark < 0 || aMark > 100);
	}
	void enterTitle(void) 
	{
		cout << "\nEnter exam title : ";
		cin >> aTitle;
	}
	void enterWeighting(void)
	{
		setWeighting(aWeighting);
	}
	void setWeighting(double examW) {
		aWeighting = examW;
		cout << "Calculated exam weighting= " << examW;
	}
};
class Module
{
private:
	double moduleMark;
	string moduleTitle;
	vector<Assessment*> assessments;
public:
	Module(string moduleTitle) : moduleMark(0.0)
	{
		cout << "Module " << moduleTitle << " created!" << endl << endl;
	}
	~Module(void)
	{

		for (int i = 0; i < assessments.size(); i++)
		{
			delete assessments[i];
		}
	}
	void addAssessment(Assessment* pA, int i)
	{
		pA->setAssessmentNumber(i);
		pA->enterTitle();
		pA->enterWeighting();
		pA->enterMark();
		assessments.push_back(pA);
	}
	void addExam(Assessment* pA)
	{
		double examWeighting = 1;
		pA->enterTitle();
		pA->enterMark();
		for (int i = 0; i < assessments.size(); i++)
			examWeighting = examWeighting - assessments[i]->getWeighting();
		pA->setWeighting(examWeighting);
		assessments.push_back(pA);
	}
	double calculateModuleMark()
	{
		moduleMark = 0;
		for (int i = 0; i < assessments.size(); i++) {
			moduleMark = moduleMark + assessments[i]->getMark()
				* assessments[i]->getWeighting();
		}
		cout << "\nModule Mark= " << moduleMark;
		return moduleMark;
	}
};
//Module::Module(string moduleTitle) : moduleMark(0.0)
//{
//	cout << "Module " << moduleTitle << " created!" << endl << endl;
//}
//Module::~Module(void)
//{
//	for (int i = 0; i < assessments.size(); i++) {
//		delete assessments[i];
//	}
//}
//void Module::addAssessment(Assessment* pA, int i) 
//{
//	pA->setAssessmentNumber(i);
//	pA->enterTitle();
//	pA->enterWeighting();
//	pA->enterMark();
//	assessments.push_back(pA);
//}
//void Module::addExam(Assessment* pA) 
//{
//	double examWeighting = 1;
//	pA->enterTitle();
//	pA->enterMark();
//	for (int i = 0; i < assessments.size(); i++)
//		examWeighting = examWeighting - assessments[i]->getWeighting();
//	pA->setWeighting(examWeighting);
//	assessments.push_back(pA);
//}
//double Module::calculateModuleMark(void)
//{
//	moduleMark = 0;
//	for (int i = 0; i < assessments.size(); i++) {
//		moduleMark = moduleMark + assessments[i]->getMark()
//			* assessments[i]->getWeighting();
//	}
//	cout << "\nModule Mark= " << moduleMark;
//	return moduleMark;
//}



int main() 
{
	Module pMyModule = Module("<<OO programming>>");
	int numberAssessments;
	cout << "Enter number of Assessments = ";
	cin >> numberAssessments;
	for (int i = 0; i < numberAssessments - 1; i++)
	{
		pMyModule.addAssessment(new Coursework, i);
	}
	pMyModule.addExam(new Exam);
	pMyModule.calculateModuleMark();
}