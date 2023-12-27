#include <iostream>

using namespace std;

class Employee{
    string Name;
    string Department;
    string Relation;
    int Experience;
    int Age;
public:
    void setName(string name){
        Name = name;
    }
    string getName(){
        return Name;
    }

    void setDepartment(string department){
        Department = department;
    }
    string getDepartment(){
        return Department;
    }

    void setRelation(string relation){
        Relation = relation;
    }
    string getRelation(){
        return Relation;
    }

    void setExperience(int experience){
        Experience = experience;
    }
    int getExperience(){
        return Experience;
    }

    void setAge(int age){
        if (age >= 18) {
            Age = age;
        }
    }
    int getAge(){
        return Age;
    }
 };   
int main(){}