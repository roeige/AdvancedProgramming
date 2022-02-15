//
// Created by roei on 15/02/2022.
//

#ifndef ADVANCEDPROGRAMMING1_COMPOSITE_H
#define ADVANCEDPROGRAMMING1_COMPOSITE_H

#include <list>
#include <vector>
#include <algorithm>

class Employee {
public:
    virtual void print() {
        cout << "Employee" << endl;
    }

    virtual ~Employee() {}
};

class Engineer : public Employee {
public:
    virtual void print() {
        cout << "Engineer" << endl;
    }
};

list<Employee *> has_manager;

class Manager : public Employee {
    list<Employee *> emps;

    bool findEmpl(Employee *employee) {
        auto it = std::find(has_manager.begin(), has_manager.end(), employee);
        if (it != has_manager.end()) { //if the employee has a manager
            return true;
        }
        return false;
    }

    /**
     * Check if there is a cycle.
     */
    bool isCycled(Employee *employee) {
        //run over its employees and check if one of them is this.
        if(employee==this)
            return true;
            Manager *m = dynamic_cast<Manager *>(employee);
            if (m) {// in case its actually manager
             for(auto it:m->emps){
                 if(isCycled(it)){
                     return true;
                 }
            }
        }
        return false;
    }

public:
    void addEmployee(Employee *emp) {
        if (isCycled(emp) || findEmpl(emp)) {
            cout << "Execption" << endl;
            return;
        }
        //adding employee to both lists.
        emps.push_back(emp);
        has_manager.push_back(emp);
    }

    ~Manager() override {
        for_each(emps.begin(), emps.end(), [](Employee *employee) { delete (employee); });
    }
};

class Demo {
public:
    void operate() {
        Manager *m0 = new Manager();
        Manager *m1 = new Manager();
        Manager *m2 = new Manager();
        Employee *e0 = new Engineer();
        Employee *e1 = new Engineer();
        Employee *e2 = new Engineer();
        Employee *e3 = new Engineer();
        m0->addEmployee(e0);
        m0->addEmployee(m1);
        m1->addEmployee(e1);
        m1->addEmployee(e2);
        m1->addEmployee(m2);
        m2->addEmployee(e3);
        m1->addEmployee(e0);

        m2->addEmployee(m0);

        m1->addEmployee(m1);
        delete m0;
    }
};

#endif //ADVANCEDPROGRAMMING1_COMPOSITE_H
