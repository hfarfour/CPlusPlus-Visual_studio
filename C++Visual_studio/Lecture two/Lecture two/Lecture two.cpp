
#include <iostream>
#include <vector>
#include <string>
using namespace std;




int mai()

{
    const int numberOfCourseWork = 4;
    int courseWorkMark[numberOfCourseWork];
    double courseWorkWeight[numberOfCourseWork];
    int ExamMark = 0;
    double examWeight = 1, moduleMark = 0;
    char input;
    do
    {
        enterMarks(courseWorkMark, courseWorkWeight, numberOfCourseWork, ExamMark, examWeight);
        moduleMark = calculateModuleMark(courseWorkMark, courseWorkWeight, numberOfCourseWork, ExamMark, examWeight);
        displayMark(courseWorkMark, courseWorkWeight, numberOfCourseWork, ExamMark, examWeight);
        cout << "module mark  - " << moduleMark << endl;
        cout << "calculate again = [y/n " << endl;
    } while (input == 'y' || input == 'Y');

    return 0;
}

void enterMarks(int courseWorkMark[], double courseWorkWeight[],
    int  numberOfCourseWork, int& ExamMark, double& examWeight)
{
    for (int i = 0; i < numberOfCourseWork; i++)
    {
        courseWorkMark[i] = courseworkMark(i);
        courseWorkWeight[i] = courseWorkWeight(i);
        examWeight = examWeight - courseWorkWeight[i];
    }
    ExamMark = enterMarks();
}





double calculateModuleMark(int courseWorkMark[], double courseWorkWeight[],
    int  numberOfCourseWork, int ExamMark, double examWeight)
{
    double moduleMark = 0;
    for (int i = 0; i < numberOfCourseWork; i++)
    {
        moduleMark = moduleMark + courseWorkMark[i] * courseWorkWeight[i];
    }
    moduleMark = moduleMark + ExamMark * examWeight;
    return moduleMark;
}

void displayMark(int courseWorkMark[], double courseWorkWeight[],
    int  numberOfCourseWork, int ExamMark, double examWeight)
{
    cout << endl;

    for (int i = 0; i < numberOfCourseWork; i++)
    {
        cout << "coursework [" << i << "]  mark = " << courseWorkMark[i] << endl;
        cout << "coursework [" << i << "]  weight = " << courseWorkWeight[i] << endl;
    }
    cout << " exam mark " << ExamMark << endl;
    cout << " exam weight  " << examWeight << endl;
    ExamMark = enterMarks();
}








/*class Exam
{
private:
    string examTitle;
    int examMark;
    double examWeighting;
public:
    int getMark() const { return examMark; }
    double getWeighting() const { return examWeighting; }
    string getTitle() const { return examTitle; }

    void enterMark() {
        do {
            cout << "Enter exam result <0?100> = ";
            cin >> examMark;
        } while (examMark < 0 || examMark > 100);
    }

    void setWeighting(double examW) {
        examWeighting = examW;
        cout << "Calculated exam weighting= " << examWeighting;
    }
    void enterTitle() {
        cout << "\nEnter exam title : ";
        cin >> examTitle;
    }
};
class Coursework
{
private:
    int courseworkMark;
    double courseworkWeighting;
    string courseworkTitle;
    unsigned int courseworkNumber;
public:
    int getMark() const { return courseworkMark; }
    double getWeighting() const { return courseworkWeighting; }
    string getTitle() const { return courseworkTitle;}

    void enterMark() {
        do {
            cout << "Enter coursework " << courseworkNumber + 1 << " result <0?100> = ";
            cin >> courseworkMark;
        } while (courseworkMark < 0 || courseworkMark > 100);
    }
    void enterWeighting() {
        do {
            cout << "Enter coursework " << courseworkNumber + 1 << " weighting 0.1 or 0.2 = ";
            cin >> courseworkWeighting;
        } while (!(courseworkWeighting == 0.1 || courseworkWeighting == 0.2));
    }
    void enterTitle() {
        cout << "Enter coursework " << courseworkNumber + 1 << " title : ";
        cin >> courseworkTitle;
    }
    void setCourseworkNumber(unsigned int courseworkNum) {
        courseworkNumber = courseworkNum;
    }
};
class Module
{
private:
    double moduleMark;
    string moduleTitle;
    vector<Coursework> Courseworks;
    Exam exam;
public:
    Module(string moduleTitle) {
        cout << "Module " << moduleTitle << " created!" << endl << endl;
    }
    void addCourseworks() {
        Courseworks.clear();
        unsigned int numberCourseworks = 0;
        cout << "Enter number of courseworks = ";
        cin >> numberCourseworks;
        for (unsigned int i = 0; i < numberCourseworks; i++) {
            Courseworks.push_back(Coursework());
            Courseworks[i].setCourseworkNumber(i);
            Courseworks[i].enterTitle();
            Courseworks[i].enterWeighting();
            Courseworks[i].enterMark();
        }
    }
    void addExam() {
        exam.enterTitle();
        exam.enterMark();
        double examWeighting = 1;
        for (unsigned int i = 0; i < Courseworks.size(); i++)
            examWeighting = examWeighting ? Courseworks[i].getWeighting();
        exam.setWeighting(examWeighting);
    }
    int calculateModuleMark() {
        moduleMark = 0;
        for (unsigned i = 0; i < Courseworks.size(); i++) {
            moduleMark = moduleMark + Courseworks[i].getMark()
                * Courseworks[i].getWeighting();
        }
        moduleMark = moduleMark + exam.getMark() * exam.getWeighting();
        return moduleMark;
    }
};
void main() {
    Module pMyModule = Module("<<OO programming>>");
    pMyModule.addCourseworks();
    pMyModule.addExam();
    cout << "\nModule Mark= " << pMyModule.calculateModuleMark();
    getchar();
    getchar();
};*/