#include <iostream> ///enter code save as validation pacs
#include <cstdlib> ///then merge with validation user_id version
#include <ctime> ///acs61 21st oct
#include <stdlib.h>
#include <iomanip>
using namespace std;
int row_total, row_average;
string best_student;
int best_average;

class validation
{
public:
    bool test_PAC(float PACs, float pUser_PAC);
    bool test_User_Id(double pUser_ID);
    bool test_mark(float mark);
private:
    float dm_PAC, dm_User_PAC;
    double dm_User_Id;
    double dm_mark;
} ;

bool validation::test_mark(float mark) ///tests marks are valid
{
    dm_mark = mark;
    if (dm_mark <0 || dm_mark >100)
    {
        return false;
    }
    else{
        return true;

    }
}

bool validation::test_PAC(float PACs, float pUser_PAC) ///tests pac is valid
{
    dm_PAC = PACs;
    dm_User_PAC = pUser_PAC;

    if ((dm_PAC == 1 && dm_User_PAC == 1) || (dm_PAC == 2 && dm_User_PAC == 1) || (dm_PAC == 3 && dm_User_PAC == 0)
        || (dm_PAC == 4 && dm_User_PAC == 8) || (dm_PAC == 5 && dm_User_PAC == 8))
    {
        return true;
    }
    else{
        return false;
    }
}

bool validation::test_User_Id(double pUser_Id) ///tests user id validity
{

    dm_User_Id = pUser_Id;
    if (dm_User_Id == 12345678)
    {
        return true;
    }

}

class exams:public validation{
public:
    string get_grade(float subject_mark);
    void print_report1_headings();
    void print_report2_headings();
    int get_CAO_points(float subject_mark);
private:
    float dm_subject_mark, dm_CAO_points;
    string dm_grade;
    string dm_sub_name[6] = {"OOP","Web A", "Work Exp", "DataBase", "Maths", "Soft A"};
};

void exams::print_report1_headings() ///prints report 1
{
    cout << endl;
    cout << setw(70) << "QQI Grades & CAO Points"  << endl;
    cout << setw(8) << "Modules";
for (int c=0;c<6;c++)
{
    cout << left << setw(10) << dm_sub_name[c];
}
cout << setw(10) << "Average ";
cout << endl;
}

void exams::print_report2_headings(){ ///prints report 2
    cout << setw(70)<< "QQI Grades & CAO Points"  << endl;
    cout << setw(8)<< "Modules" ;
for (int c=0;c<6;c++)
{
    cout << left << setw(10) << dm_sub_name[c] ;
}
cout << setw(10) << "\nCAO points";
cout << endl;
}

string exams::get_grade(float subject_mark){

    dm_subject_mark = subject_mark;
        if (dm_subject_mark >= 80 && dm_subject_mark<=100) {dm_grade = "D"; dm_CAO_points =50;}
        if (dm_subject_mark >= 65 && dm_subject_mark<80) {dm_grade = "M"; }
        if (dm_subject_mark >=50 && dm_subject_mark<65) {dm_grade = "P"; }
        if (dm_subject_mark >=0 && dm_subject_mark<50) {dm_grade = "U"; }

    return dm_grade;
}

int exams::get_CAO_points(float subject_mark)

{   dm_subject_mark = subject_mark;
if (dm_subject_mark >=80) { dm_CAO_points = 50;}
if (dm_subject_mark >=65  && dm_subject_mark<80) {dm_CAO_points = 33;}  ///defines cao points from grade
if (dm_subject_mark >=50 && dm_subject_mark<65) {dm_CAO_points = 16;}
if (dm_subject_mark >= 0 && dm_subject_mark<50) {dm_CAO_points = 0;}

return dm_CAO_points;
}

double user_id;
int pac1, pac2, pac3;
int user_pac1, user_pac2, user_pac3;
const int no_of_columns = 6;
const int no_of_rows = 6;

int data[6][6] = {50,50,50,50,50,50,
                    60,80,75,50,60,75,
                    80,55,65,59,70,70,
                    60,68,75,50,60,55,
                    60,70,70,67,70,70,
                    90,90,90,90,90,101};
int column_total [6];

string student_name[6] = {"D James", "S Aguero", "M Alonso", "J McClean", "B Johnson" ,"S Duffy"};

main()
{
      class validation user1;
      start1:
      cout << "                                     " << endl;
      cout << "|                                   |" << endl; ///asks user to input id
      cout << "|     Key in user id <12345678>     |" << endl;
      cout << "|" << setw(36) << "|"                  << endl;
      cout << "         " ;
      cin >> user_id;

    if (user1.test_User_Id(user_id)== false)
    {
    cout << "|        Invalid user_id            |";
    goto start1;
    }

    cout << "|        Valid user_id              |"<< endl;
    cout << "_____________________________________" << endl;
    cout << "| Users have two attempts to log in |" << endl;
    cout << "|Enter appropriate PAC eg. PAC 1 = 1|" << endl;
    cout << "|PAC 2=1, PAC 3=0, PAC 4=8, PAC 5=8 |" << endl;
    cout << "|" << setw(36) << "|"                  << endl;

    start:  srand(time(0));
            pac1 = 1+ (rand()%5);
            pac2 = 1+ (rand()%5);
            pac3 = 1+ (rand()%5);


    if (pac1 == pac2 || pac1 == pac3 || pac2 == pac3)
    {
        goto start;
    }
        cout << "|                                   |" << endl; ///asks user to input pac
        cout << "| Enter PAC" << pac1 << " :";
        cin >> user_pac1;

    if(user1.test_PAC(pac1, user_pac1) == false) ///informs user invalid pac
   {
        cout << "|-----------------------------------|" << endl;
        cout << "|     ONE OR MORE PACS NOT VALID    |" << endl;
        cout << "|-----------------------------------|" << endl;
        goto start;
   }

        cout << "| Enter PAC" << pac2 << " :";
        cin >> user_pac2;

    if(user1.test_PAC(pac2, user_pac2) == false)
   {
        cout << "|-----------------------------------|" << endl;
        cout << "|     ONE OR MORE PACS NOT VALID    |" << endl;
        cout << "|-----------------------------------|" << endl;
        goto start;
   }

        cout << "| Enter PAC" << pac3 << " :";
        cin >> user_pac3;
    if(user1.test_PAC(pac3, user_pac3) == false)
   {
        cout << "|-----------------------------------|" << endl;
        cout << "|     ONE OR MORE PACS NOT VALID    |" << endl;
        cout << "|-----------------------------------|" << endl;
        goto start;
   }

    if (user1.test_mark(100)){
        cout << "\nValid mark";
    }
    else{
        cout << "\nInvalid mark";
    }

    class exams student[6];
    	exams reports;
    	reports.print_report1_headings();

    for (int row = 0 ; row < no_of_rows ; row++){
        row_total = 0 ;
        cout << setw(10) << student_name[row];

    for (int column = 0 ; column < no_of_columns ; column++){

            if (student[row].test_mark(data[row][column]) != true){
                cout << data[row][column] << " is invalid " << endl;
                system("PAUSE");
            }

    cout << setw(10) << data[row][column];
    row_total = row_total + data[row][column];
    column_total[column] = column_total [column]+data[row][column];
    }

    row_average = row_total / no_of_columns;

        if(best_average < row_average){
        best_average = row_average;
        best_student = student_name[row];
        }

    cout << setw(10) << row_average;
    cout << endl;
    }

    cout << setw(10) << "Average" ;

    for (int i=0;i<6;i++){
    cout<< setw(10) << column_total[i] / no_of_rows;
    }

    cout << endl;
    cout << "\nBest Student is " << best_student << " with an average of " << best_average << endl;
    cout << "End of Report 1\n\n"  << endl;

    reports.print_report2_headings();

  for (int row = 0 ; row < no_of_rows ; row++){
        row_total = 0 ;
        cout << setw(10) << student_name[row];

  for (int column = 0 ; column < no_of_columns ; column++){
        cout << setw(10) << student[row].get_grade(data[row][column]);
        student[row].get_CAO_points(data[row][column]);
        row_total = row_total + student[row].get_CAO_points(data[row][column]);
        row_average = row_total / no_of_columns;

        if(best_average < row_average){
        best_average = row_total;
        best_student = student_name[row];
        }
        }

        cout << setw(20) << row_total;
        cout << endl;
        }

        cout << "\nBest Student is "  << best_student << " with an average of " << best_average << endl;
        cout << "End of Report 2 "  << endl;
}

