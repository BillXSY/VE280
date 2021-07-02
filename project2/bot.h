//
// Created by 71401 on 2021/6/9.
//

#ifndef VE280_BOT_H
#define VE280_BOT_H

#include <sstream>
#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

struct CourseInfo {
    string CourseCode;
    string CourseName;
    string Instructor;
};

//deal with unknown command
void unknown_command(const string &content);

//output all the courses that contain "obj" in their CourseCode
void check_course(struct CourseInfo Courses[], int CourseNum, const string &obj);

//output all the Instructors who have "obj" in their name
//and output their courses
void check_instructor(struct CourseInfo Courses[], int CourseNum, const string &obj);

//output help message
void help_message();

//    if the user is in the admin list of certain group
//    print "Good night. I am going to sleep"
//    and terminate the whole program
//    else print "You are not qualified to stop me" and continue
void stop(const string &InformPath, const string &group, const string &obj, bool &flag);

//the chat bot
void bot(struct CourseInfo Courses[], int CourseNum, string Groups[], int GroupNum, const string &InformPath);


#endif //VE280_BOT_H
