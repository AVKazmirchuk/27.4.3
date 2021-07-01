#include <iostream>
#include <ctime>
#include "../include/header.h"

//-------Class Employee------

Employee::Employee(SubTasks inSubTask) { subTask.second = inSubTask; }

std::pair<int, SubTasks>& Employee::setSubTask() { return subTask; }

std::pair<int, SubTasks>& Employee::getSubTask() { return subTask; }

//-------Class Manager-------

Manager::Manager(int inNumberOfEmployees) : numberOfEmployees{ inNumberOfEmployees }
{
    employees = new Employee * [numberOfEmployees];
    for (int i{}; i < numberOfEmployees; ++i)
        employees[i] = new Employee(SubTasks::X);
}

Manager::~Manager()
{
    for (int i{}; i < numberOfEmployees; ++i)
        delete employees[i];

    delete employees;
}

int& Manager::setTask() { return task; }

int Manager::getTask() const { return task; }

int Manager::getNumberOfTasks() const { return numberOfTasks; }

int Manager::getNumberOfEmployees() const { return numberOfEmployees; }

Employee* Manager::getEmployeeByIndex(int idx) { return employees[idx]; }

bool Manager::availableEmployees()
{
    for (int i{}; i < numberOfEmployees; ++i)
        if (employees[i]->getSubTask().second == SubTasks::X) return false;

    return true;
}

void Manager::distributeTasks()
{
    std::srand(task);
    numberOfTasks = rand() % numberOfEmployees + 1;

    for (int i{}; i < getNumberOfEmployees(); ++i)
    {
        if (employees[i]->getSubTask().second != SubTasks::X) continue;

        for (int j{ 1 }; j <= numberOfTasks; ++j)
        {
            SubTasks privSubTask[]{ SubTasks::X, SubTasks::X, SubTasks::X };

            for (int k{}; k < (static_cast<int>(SubTasks::X) - static_cast<int>(SubTasks::A)); ++k)
            {
                if (i == getNumberOfEmployees()) return;

                //Разбиение задачи на подзадачи

                SubTasks currentSubTask = static_cast<SubTasks>(rand() %
                        (static_cast<int>(SubTasks::X) - static_cast<int>(SubTasks::A)) + static_cast<int>(SubTasks::A));

                if (currentSubTask != privSubTask[0] && currentSubTask != privSubTask[1]) privSubTask[k] = currentSubTask;
                else { --k;	continue; }

                employees[i]->setSubTask() = { j, privSubTask[k] };
                ++i;
            }
        }

        return;
    }
}

//-------Class Chief---------

Chief::Chief(std::pair<int, int*> parameter) : numberOfManagers{ parameter.first }
{
    managers = new Manager * [numberOfManagers];
    for (int i{}; i < numberOfManagers; ++i)
        managers[i] = new Manager(parameter.second[i]);
}

Chief::~Chief()
{
    for (int i{}; i < numberOfManagers; ++i)
        delete managers[i];

    delete managers;
}

int& Chief::setTask() { return task; }

int Chief::getNumberOfManagers() const { return numberOfManagers; }

Manager* Chief::getManagerByIndex(int idx) { return managers[idx]; }

bool Chief::availableEmployees()
{
    for (int i{}; i < numberOfManagers; ++i)
        if (!managers[i]->availableEmployees()) return false;

    return true;
}

void Chief::assigningTasks()
{
    for (int i{}; i < numberOfManagers; ++i)
    {
        managers[i]->setTask() = task + i + 1;

        managers[i]->distributeTasks();
    }
}