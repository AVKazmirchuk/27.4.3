#pragma once
#include <iostream>

enum class SubTasks
{
        A,
        B,
        C,
        X
};




class Employee
{
private:
    std::pair<int, SubTasks> subTask;
public:
    Employee(SubTasks inSubTask);
    std::pair<int, SubTasks>& setSubTask();
    std::pair<int, SubTasks>& getSubTask();
};



class Manager
{
private:
    int task{};
    int numberOfTasks{};

    int numberOfEmployees;

    Employee** employees;
public:
    Manager(int inNumberOfEmployees);

    ~Manager();

    int& setTask();

    int getTask() const;

    int getNumberOfTasks() const;

    int getNumberOfEmployees() const;

    Employee* getEmployeeByIndex(int idx);

    bool availableEmployees();

    void distributeTasks();
};



class Chief
{
private:
    int task{};
    int numberOfManagers;
    Manager** managers;
public:
    Chief(std::pair<int, int*> parameter);

    ~Chief();

    int& setTask();

    int getNumberOfManagers() const;

    Manager* getManagerByIndex(int idx);

    bool availableEmployees();

    void assigningTasks();
};