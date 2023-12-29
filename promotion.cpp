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
    void staffInformation(){
        cout << "Name: " << Name << endl;
        cout << "Department: " << Department << endl;
        cout << "Relation: " << Relation << endl;
        cout << "Experience: " << Experience << endl;
        cout << "Age: " << Age << endl; 
    }
    Employee(string name, string department, string relation, int experience, int age){
        Name = name;
        Department = department;
        Relation = relation;
        Experience = experience;
        Age = age;
    }
    void askForPromotion(){
        if(Age >= 18 && Relation == "Good" && Experience >= 3){
            cout << Name << " deserves a promotion." << endl;
        }else{
            cout << "Sorry, " << Name << " does not deserve a promotion." << endl;
        }
    }
 };   
int main(){
    Employee emp1 = Employee("Gorkem", "Mobile", "Good", 2, 27);
    Employee emp2 = Employee("Furkan", "IT", "Good", 4, 29);
    emp1.askForPromotion();
    emp2.askForPromotion();
}