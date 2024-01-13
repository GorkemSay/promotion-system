#include <iostream>
#include <vector>
using namespace std;

// Enumeration for employee  relations
enum class Relation{
    Excellent,
    Good,
    Average,
    Poor,
    Bad
};

// Enumeration for department
enum class Department{
    Mobile,
    Web,
    HR,
    Sales,
    Management
};

// Abstract class for askForPromotion function
class AbstractEmployee{
    virtual void askForPromotion() = 0;
};
class Employee : AbstractEmployee{
protected:    
    string Name;
    Department employeeDepartment;
    Relation employeeRelation;
    int Experience;
    int Age;
public:
    // Constructor with initialization list
    Employee(string name, Department department, Relation relation, int experience, int age)
    : Name(name), employeeDepartment(department), employeeRelation(relation), Experience(experience), Age(age){
    }
    void setName(string name){
        Name = name;
    }
    string getName(){
        return Name;
    }
    void setDepartment(Department department){
        employeeDepartment = department;
    }
    Department getDepartment(){
        return employeeDepartment;
    }
    void setRelation(Relation relation) {
        employeeRelation = relation;
    }
    Relation getRelation() {
        return employeeRelation;
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
    // Display staff information
    void staffInformation() const {
        cout << "Name: " << Name << endl;
        cout << "Department: " << static_cast<int>(employeeDepartment) << endl;
        cout << "Relation: " << static_cast<int>(employeeRelation) << endl;
        cout << "Experience: " << Experience << endl;
        cout << "Age: " << Age << endl; 
    }
    // Check eligibility for promotion
    void askForPromotion(){
        if(Age >= 18 && employeeRelation == Relation::Good && Experience >= 3){
            cout << Name << " deserves a promotion." << endl;
        }else{
            cout << "Sorry, " << Name << " does not deserve a promotion." << endl;
        }
    }
    virtual void Work(){
        cout << Name << ": " << "is working." << endl;
    }
 };
   // Engineers class inherited from Employee class
  // For obtain specific developer things
 // Like programming languages or frameworks
 class Engineers : public Employee{
public:
    string ProgrammingLanguages;
    Engineers(string name, Department department, Relation relation, int experience, int age, string programming_languages)
    : Employee(name, department, relation, experience, age){
        ProgrammingLanguages = programming_languages;
    }
    void Work(){
        cout << Name << ": is writing " << ProgrammingLanguages << " code" << endl;
    }
 };
 class Human_Resources : public Employee{
public:
string performance_metric;
 };
class EmployeeManager{
private:
    vector<Employee> employees;
public:
    // Add an employee to manager
    void addEmployee(const Employee& employee){
        employees.push_back(employee);
    }

    // Display information for all employees
    void displayAllEmployees(){
        for(const auto& employee : employees){
            employee.staffInformation();
            cout << "- - - - - - - - -" << endl;
        }
    }

    // Chech promotion eligibility for all employees
    void checkPromotions(){
        for(auto & employee : employees){
            employee.askForPromotion();
        }
    }
};   
int main(){
    EmployeeManager manager;
    Engineers emp1 = Engineers("Gorkem", Department::Mobile, Relation::Good, 2, 27, "Swift");
    Employee *e = &emp1;
    emp1->Work();
    Employee emp2 = Employee("Furkan", Department::Web, Relation::Good, 4, 29);
    emp1.askForPromotion();
    emp2.askForPromotion();
    manager.addEmployee(Employee("Gorkem", Department::Mobile, Relation::Good, 2, 27));
    manager.addEmployee(Employee("Furkan", Department::Web, Relation::Good, 4, 29));

    manager.displayAllEmployees();
    manager.checkPromotions();
}