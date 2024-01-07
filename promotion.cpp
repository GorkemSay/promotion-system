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
class EmployeeManager{
private:
    vector<Employee> employees;
public:
    void addEmployee(const Employee& employee){
        employees.push_back(employee);
    }

    void displayEmployees(){
        for(const auto& employee : employees){
            employee.staffInformation();
            cout << "- - - - - - - - -" << endl;
        }
    }

    void checkPromotion(){
        for(auto & employee : employees){
            employee.askForPromotion();
        }
    }
};
class Employee : AbstractEmployee{
private:    
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
 };   
int main(){
    EmployeeManager manager;
    Employee emp1 = Employee("Gorkem", Department::Mobile, Relation::Good, 2, 27);
    Employee emp2 = Employee("Furkan", Department::Web, Relation::Good, 4, 29);
    emp1.askForPromotion();
    emp2.askForPromotion();
}