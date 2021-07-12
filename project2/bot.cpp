//
// Created by 71401 on 2021/6/9.
//
#include "bot.h"
#include "rand.h"
#include "constants.h"

using namespace std;

//deal with unknown command
void unknown_command(const string &content) {
    RespChoice choice = randomResponse();
    switch (choice) {
        case 1:
            cout << content << endl << endl;
            break;
        case 2:
            if (flipCoin()) {
                cout << "Respect ";
            } else {
                cout << "I really admire ";
            }
            cout << content << endl;
            break;
        default:
            cout << endl;
            break;
    }
}

//output all the courses that contain "obj" in their CourseCode
void check_course(struct CourseInfo Courses[], int CourseNum, const string &obj) {
    if (obj.empty()) {
        cout << "Oh, input the search keyword first...\n" << endl;
        return;
    }
    int count = 0;
    for (int i = 0; i < CourseNum; ++i) {
        string::size_type position;
        string s = Courses[i].CourseCode;
        position = s.find(obj);
        if (position != std::string::npos) {
            cout << "Course Code: " << Courses[i].CourseCode << endl;
            cout << "Course Name: " << Courses[i].CourseName << endl;
            cout << "Instructor: " << Courses[i].Instructor << endl;
            count++;
        }
    }
    if (!count) {
        cout << "I don't know this course" << endl;
    }
    cout << endl;
}

//output all the Instructors who have "obj" in their name
//and output their courses
void check_instructor(struct CourseInfo Courses[], int CourseNum, const string &obj) {
    if (obj.empty()) {
        cout << "Oh, input the search keyword first...\n" << endl;
        return;
    }
//    cout << "Instructor to check is: " << obj << endl;
    int count = 0;
    string candidates[CourseNum];
    for (int i = 0; i < CourseNum; ++i) {
        string::size_type position;
        string s = Courses[i].Instructor;
        position = s.find(obj);
        if (position != std::string::npos) {
            bool is_exist = false;
            for (const string& candidate : candidates) {
                if (candidate == s) {
                    is_exist = true;
                }
            }
            if (!is_exist) {
                candidates[count++] = s;
            }
        }
    }

    if (!count) {
        cout << "I don't know this instructor\n" << endl;
        return;
    }
    for (const string &p : candidates) {
        if (!p.empty()) {
            cout << "Instructor: " << p << endl;
            cout << "Courses:";
            for (int i = 0; i < CourseNum; ++i) {
                if (Courses[i].Instructor == p) {
                    cout << ' ' << Courses[i].CourseCode;
                }
            }
            cout << endl;
        }
    }
    cout << endl;
}

//output help message
void help_message() {
    cout << "Cheat Sheet for Repeater Bot:" << endl;
    cout << "Notice: Commands start with #" << endl;
    cout << "   course [keyword]:     find all the courses that contain the keyword" << endl;
    cout << "   instructor [keyword]:    find all the instructors that contain the keyword" << endl;
    cout << "   help:    show help message" << endl;
    cout << "   time:    show the time when the message was sent" << endl;
    cout << "   stop:    (For bot admins only) stop the bot\n" << endl;
}

//    if the user is in the admin list of certain group
//    print "Good night. I am going to sleep"
//    and terminate the whole program
//    else print "You are not qualified to stop me" and continue
void stop(const string &InformPath, const string &group, const string &obj, bool &flag) {
    string temp;
    ifstream adminInfo(InformPath + '/' + group);
    getline(adminInfo, temp);
    int admin_num = 0;
    try {
        admin_num = stoi(temp);
    }
    catch (std::invalid_argument &ia) {
        std::cerr << "admin_num Error" << endl;
    }
    for (int i = 0; i < admin_num; ++i) {
        getline(adminInfo, temp);
//        cout << temp << ' ' << obj << endl;
        if (temp == obj) {
            cout << EXIT_PROMPT << "\n" << endl;
            flag = false;
            return;
        }
    }
    cout << "You are not qualified to stop me\n" << endl;
}

//the chat bot
void bot(struct CourseInfo Courses[], int CourseNum, string Groups[], int GroupNum, const string &InformPath) {
//    cout << CourseNum << GroupNum << endl;
//    for (int j = 0; j < CourseNum; ++j) {
//        cout << "#" << j + 1 << ' ' << Courses[j].CourseCode << ',' << Courses[j].CourseName << ','
//             << Courses[j].Instructor << endl;
//    }
//    for (int j = 0; j < GroupNum; ++j) {
////        cout << "Path: " << InformPath + '/' + to_string(gp) << endl;
////        ifstream info(InformPath + '/' + to_string(gp));
////        while(getline(info, temp)) {
////            cout << temp << endl;
////        }
//        cout << Groups[j] << endl;
//    }


    bool flag = true;
    while (flag) {
        string temp, time_in, group_in, user_in, content_in;
        getline(cin, temp, ',');
        time_in = temp;
        getline(cin, temp, ',');
        group_in = temp;
        getline(cin, temp, ',');
        user_in = temp;
        getline(cin, temp, '\n');
        content_in = temp;

        bool valid_groupID = false;
        for (int i = 0; i < GroupNum; ++i) {
            if (Groups[i] == group_in) {
                valid_groupID = true;
            }
        }
        if (!valid_groupID) {
            cout << endl;
            continue;
        }
//        cout << time_in << ' ' << group_in << ' ' << user_in << ' ' << content_in << endl;

        string command, obj;
        istringstream iStream(content_in);
//        cout << "'" << content_in << "'" << endl;
        getline(iStream, command, ' ');
//        iStream >> command >> obj;
        getline(iStream, obj);
//        cout << "command: '" << command << "'" << endl << "obj: '" << obj << "'" << endl;

        string s(content_in, 0, 1);
//        cout << "s: " << s << endl;

        if (s != "#") {
            unknown_command(content_in);
        } else if (command == "#course") {
            check_course(Courses, CourseNum, obj);
        } else if (command == "#instructor") {
            check_instructor(Courses, CourseNum, obj);
        } else if (command == "#help") {
            help_message();
        } else if (command == "#time") {
            cout << time_in << endl << endl;
        } else if (command == "#stop") {
            stop(InformPath, group_in, user_in, flag);
        } else {
            unknown_command(content_in);
        }


    }

}