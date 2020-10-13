#include<iostream>
#include<string>
#include<unordered_map>
#include<vector>
using namespace std;

#define MAX_STUDENT 2

/* Approach-1 */
/* Use hash_map */
class Student
{
    private:
        string StudentName ;
        vector<int>Grades ;
        double Average ;
    public:
        Student(string _student_name)
        {
            this->StudentName = _student_name;
        }
        string GetName ()
        {
            return this->_student_name ;
        }
        void AddGrades (vector<int>&grades) /*clarify if only the grades as given as input or courses as well */
        {
            this->Grades = grades;
        }
        vector<int>GetGrades()
        {
            return (this->Grades);
        }
        double AverageOfGrades()
        {
            int sum = 0;
            for(int num:Grades)
            {
                sum += num;
            }
            this->Average = (double)sum/Grades.size();
            return (this->Average);
        }
} ;
int main()
{
    string HoldStudentName;
    /*key is student and value is the object of that class */
    unordered_map<string,Student>StudentToGradeMap ;
    /* Approach-1 Input Student Name */
    /*
    cout<<"---Input Student Name---"<<endl;
    cin>>HoldStudentName;
    */
    Student s1("Shreyat");
    vector<int>GradeInput = {100,90,80};
    s1.AddGrades(GradeInput);
    StudentToGradeMap.emplace("Shreyat",s1);
    Student s2("Jamie");
    GradeInput = {50,60,70} ;
    s2.AddGrades(GradeInput);
    StudentToGradeMap.emplace("Jamie",s2);
    
    /*Display Content*/
    cout<<"Student     "<<"|"<<" Grades"<<endl;
    for(auto &x:StudentToGradeMap)
    {
        Student object = x.second;
        cout<<object.GetName()<<"       |";
        auto GradesResult = object.GetGrades();
        for(auto &y:GradesResult)
        {
            cout<<y<<" ";
        }
        cout<<"\n";
    }
    
    /*Get Content*/
    cout<<"Enter Student Entry:"<<endl;
    cin>>HoldStudentName;
    
    if(StudentToGradeMap.count(HoldStudentName) == 0)
        {
            cout<<"No such entry exist for this student"<<endl;
            exit(0);
        }
    else
    {
        /* There has to be a loop |cannot avoid that*/
        for(auto &x:StudentToGradeMap)
        {
            if(x.first == HoldStudentName)
            {
                cout<<"Marks:"<<endl;
                Student Object = x.second;
                auto GradesResult = Object.GetGrades();
                for(int num:GradesResult)
                {
                    cout<<num<<" ";
                }
                cout<<"\n";
                cout<<"CumulativeGrade:"<<Object.AverageOfGrades()<<endl;
            }
        }
        
    }
    
    
    return 0;
    
}

