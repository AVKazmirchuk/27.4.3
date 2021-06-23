#pragma once
#include <iostream>

class Employee
{
private:
    std::pair<int, char> subTask;
public:
    Employee(char inSubTask); ;

    std::pair<int, char>& setSubTask();

    std::pair<int, char>& getSubTask();
};

class Manager
{
private:
    int task{};
    int numberOfTasks{};
    const char noTask = 'X';
    const char subTaskMin = 'A';
    const char subTaskMax = 'C';

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