/*
 * VE280 Lab 7, SU2021
 * Created by cyx on 20-5-22.
 * Modified by makersmelx on June 28th, 2021.
 */

#include <iostream>
#include "course.h"

using namespace std;

TechnicalCourse::TechnicalCourse(const std::string &course_code, int size) {
    tasks = new Task[size];
    sizeTasks = size;
    numTasks = 0;
    this->courseCode = course_code;
}

TechnicalCourse::~TechnicalCourse() {
    delete[] tasks;
}

void TechnicalCourse::updateTask(const std::string &type, int index, int dueMonth, int dueDay)
/* REQUIRES: dueMonth and dueDay are in normal range.
// MODIFIES: this
// EFFECTS: if Task index of type already exists in tasks, updates its dueMonth & dueDay ;
//          otherwise, adds Task i of type at the end of tasks if tasks is not full,
          throw an exception if tasks is full*/
{
    // TODO: implement this function
    //check if there exists such Task
    bool isExist = false;
    for (int i = 0; i < this->numTasks; ++i) {
        if (this->tasks[i].type == type && this->tasks[i].index == index) {
            this->tasks[i].dueDay = dueDay;
            this->tasks[i].dueMonth = dueMonth;
            isExist = true;
            break;
        }

    }

    if (!isExist) {

        if (this->numTasks >= sizeTasks) {
            throw TooManyTasks{};
        }

        this->tasks[numTasks].type = type;
        this->tasks[numTasks].index = index;
        this->tasks[numTasks].dueDay = dueDay;
        this->tasks[numTasks].dueMonth = dueMonth;
        numTasks++;

        std::cout << this->courseCode << ' ' << type << ' ' << index << " is released! Submit it via ";
        if (type == "Lab" || type == "Project") {
            std::cout << "oj!\n";
        } else {
            std::cout << "canvas!\n";
        }
    }
}

void TechnicalCourse::finishTask(const std::string &type, int index, int finishMonth, int finishDay)
/* REQUIRES: Task index of type is in tasks. finishMonth and finishDay are in normal range.
// MODIFIES: this
// EFFECTS: removes Task index of type*/
{
    // TODO: implement this function
    for (int i = 0; i < this->numTasks; ++i) {
        if (this->tasks[i].type == type && this->tasks[i].index == index) {
            std::cout << this->courseCode << ' ' << type << ' ' << index << " is ";
            if (finishMonth < this->tasks[i].dueMonth ||
                (finishMonth == this->tasks[i].dueMonth && finishDay <= this->tasks[i].dueDay)) {
                std::cout << "finished!\n";
            } else {
                std::cout << "overdue!\n";
            }

            for (int j = i; j < this->numTasks - 1; ++j) {
                this->tasks[j] = this->tasks[j + 1];
            }
            this->numTasks--;
            break;
        }
    }
}

void TechnicalCourse::print() {
    std::cout << courseCode << std::endl;
    for (int i = 0; i < numTasks; ++i) {
        std::cout << tasks[i].type << " " << tasks[i].index << ": "
                  << tasks[i].dueMonth << "/" << tasks[i].dueDay << std::endl;
    }
}

UpperLevelTechnicalCourse::UpperLevelTechnicalCourse(const std::string &courseCode, int size) : TechnicalCourse(
        courseCode, size) {}

UpperLevelTechnicalCourse::~UpperLevelTechnicalCourse() = default;

void UpperLevelTechnicalCourse::updateTask(const std::string &type, int index, int dueMonth, int dueDay)
// REQUIRES: dueMonth and dueDay are in normal range.
// MODIFIES: this
// EFFECTS: If Task index of type does not exist in tasks,
//          adds Task i of type according to its due date if tasks is not full, throw an exception if tasks is full.
//          If Task index of type already exists in tasks,
//          updates its position in tasks & dueMonth & dueDay if its dueMonth/dueDay is changed,
//          do nothing if its dueMonth/dueDay is unchanged.
{
    // TODO: implement this function
    //check if there exists such Task
    bool isExist = false;
    for (int i = 0; i < this->numTasks; ++i) {
        if (this->tasks[i].type == type && this->tasks[i].index == index) {
            this->tasks[i].dueDay = dueDay;
            this->tasks[i].dueMonth = dueMonth;
            isExist = true;
            break;
        }

    }

    if (!isExist) {

        if (this->numTasks >= sizeTasks) {
            throw TooManyTasks{};
        }

        this->tasks[numTasks].type = type;
        this->tasks[numTasks].index = index;
        this->tasks[numTasks].dueDay = dueDay;
        this->tasks[numTasks].dueMonth = dueMonth;
        numTasks++;

        std::cout << this->courseCode << ' ' << type << ' ' << index << " is released! Submit it via ";
        if (type == "Lab" || type == "Project") {
            std::cout << "oj!\n";
        } else if (type == "Team Project") {
            std::cout << "github!\n";
        }
        else {
            std::cout << "canvas!\n";
        }
    }
    //sort
    for (int i = 0; i < numTasks - 1; ++i) {
        for (int j = i; j < numTasks - 1; ++j) {
            if (tasks[j].dueMonth > tasks[j + 1].dueMonth ||
                (tasks[j].dueMonth == tasks[j + 1].dueMonth && tasks[j].dueDay > tasks[j + 1].dueDay)) {
                Task temp = tasks[j];
                tasks[j] = tasks[j + 1];
                tasks[j + 1] = temp;
            }
        }
    }


}

Course *create(const std::string &classType, const std::string &courseCode) {
    if (classType == "Technical") {
        return new TechnicalCourse(courseCode);
    } else if (classType == "Upper Level Technical") {
        return new UpperLevelTechnicalCourse(courseCode);
    } else {
        return nullptr;
    }
}

Course *create(const std::string &classType, const std::string &courseCode, const int &size) {
    if (classType == "Technical") {
        return new TechnicalCourse(courseCode, size);
    } else if (classType == "Upper Level Technical") {
        return new UpperLevelTechnicalCourse(courseCode, size);
    } else {
        return nullptr;
    }
}
