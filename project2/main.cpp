//
// Created by 71401 on 2021/6/9.
//
#include "bot.h"
#include "rand.h"
#include "constants.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <cstdlib>
#include <cassert>

using namespace std;

bool AllisNum(const string &str) {
    for (char i : str) {
        int tmp = (int) i;
        if (tmp >= 48 && tmp <= 57) {
            continue;
        } else {
            return false;
        }
    }
    return true;
}

int main(int argc, char const *argv[]) {
    // check MISSING_ARGUMENT_MESSAGE
    if (argc < 4) {
        cout << MISSING_ARGUMENT_MESSAGE << endl;
        return 0;
    }

    //  Part 1: Data file for courses/instructor
    ifstream course(argv[1]);
    if (!course) {
        cout << CANNOT_OPEN_FILE_PREFIX << argv[1] << endl;
        return 0;
    }
    string course_line;
    getline(course, course_line);
    int CourseNum = stoi(course_line);
    CourseInfo Courses[CourseNum];
    int i = 0;
    while (getline(course, course_line)) {
        istringstream iStream(course_line);
        string temp;
        getline(iStream, temp, ',');
        Courses[i].CourseCode = temp;
        getline(iStream, temp, ',');
        Courses[i].CourseName = temp;
        getline(iStream, temp);
        Courses[i].Instructor = temp;
        i++;
    }

    //    Part 2: Group Inform
    ifstream group(argv[2]);
    if (!group) {
        cout << CANNOT_OPEN_FILE_PREFIX << argv[2] << endl;
        return 0;
    }
    string InformPath, temp;

    getline(group, InformPath);
    getline(group, temp); // temp->num_group
    int GroupNum = 0;
    try {
        GroupNum = stoi(temp);
    }
    catch (std::invalid_argument &ia) {
        std::cerr << "GroupNum Error" << endl;
    }
    string Groups[GroupNum];
    for (int i = 0; i < GroupNum; ++i) {
        getline(group, temp);
        Groups[i] = temp;
    }


    //  Part 3: bot
    // check INVALID_ARGUMENT_MESSAGE
    if (!AllisNum(argv[3])) {
        cout << INVALID_ARGUMENT_MESSAGE << endl;
        return 0;
    }
    // check OUT_OF_RANGE_MESSAGE
    if (stod(argv[3]) > 2147483647) {
        cout << OUT_OF_RANGE_MESSAGE << endl;
        return 0;
    }
    // initialize With Seed
    initializeWithSeed(stoi(argv[3]));
    // call the bot
//    bot(Courses, CourseNum, InformPath);
    bot(Courses, CourseNum, Groups, GroupNum, InformPath);

    return 0;
}
