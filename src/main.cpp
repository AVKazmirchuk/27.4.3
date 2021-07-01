#include <iostream>
#include <ctime>

#include "../include/header.h"

bool cinNoFail()
{
    if (std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid data!\n";
        return false;
    }
    else
    {
        if (std::cin.peek() != '\n')
        {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid data!\n";
            return false;
        }
    }

    return true;
}



std::pair<int, int*> input()
{
    int numberOfManagers;
    while (true)
    {
        std::cout << "Number of Managers: ";
        std::cin >> numberOfManagers;

        if (cinNoFail()) break;
    }

    int* employees = new int[numberOfManagers];
    for (int i{}; i < numberOfManagers; ++i)
        while (true)
        {
            std::cout << "Number of team employees " << i + 1 << ": ";
            std::cin >> employees[i];

            if (cinNoFail()) break;
        }

    return { numberOfManagers, employees };
}



void output(Chief* chief)
{
    std::cout << "--------------------\n";

    for (int j{}; j < chief->getNumberOfManagers(); ++j)
    {
        std::cout << "Manager: " << j + 1 << ", employees: " << chief->getManagerByIndex(j)->getNumberOfEmployees() <<
                  ", tasks: " << chief->getManagerByIndex(j)->getTask() << ", number of tasks: " <<
                  chief->getManagerByIndex(j)->getNumberOfTasks() << '\n';

        for (int i{}; i < chief->getManagerByIndex(j)->getNumberOfEmployees(); ++i)
        {
            SubTasks subTask = chief->getManagerByIndex(j)->getEmployeeByIndex(i)->getSubTask().second;
            char outSubTask;

            switch (subTask)
            {
                case SubTasks::A : outSubTask = 'A'; break;
                case SubTasks::B : outSubTask = 'B'; break;
                case SubTasks::C : outSubTask = 'C'; break;
                case SubTasks::X : outSubTask = 'X'; break;
                default: break;
            }

            std::cout << chief->getManagerByIndex(j)->getEmployeeByIndex(i)->getSubTask().first << outSubTask << ' ';
        }

        std::cout << '\n';
    }

    std::cout << "--------------------\n";
}



int main()
{
    std::pair<int, int*> init = input();

    Chief* chief = new Chief(init);

    delete init.second;

    while (!chief->availableEmployees())
    {
        std::cout << "\nThere are available employees!\n";
        while (true)
        {
            std::cout << "Task: ";
            std::cin >> chief->setTask();

            if (cinNoFail()) break;
        }

        chief->assigningTasks();

        output(chief);
    }

    std::cout << "\nAll employees are busy...\n";

    delete chief;
}