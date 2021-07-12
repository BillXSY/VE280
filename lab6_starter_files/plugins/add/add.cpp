//
// Created by 71401 on 2021/6/25.
//

#include "plugin.h"
#include <iostream>
#include <sstream>
#include <regex>

class Add : public Plugin {
public:
    Add() : Plugin() {
        this->name = "add";
        this->author = "Meual";
        this->description = "add two integers";
        this->help = "Usage: add <integer> <integer>";
    }

    string response(const string &str) const override {
        int int1, int2;
        string name;
        istringstream iStream(str);
        iStream >> name >> int1 >> int2;
        return to_string(int1 + int2);
    }

    int matchRule(const string &str) const override {
        istringstream iStream(str);
        string name;
        iStream >> name;
        if (name == "add") {
            return 1;
        }
        return 0;
    }

    string toString() const override {
        string output = "Add operations is great     --Meual";
        return output;
    }

};

extern "C" Plugin *create() {
    return new Add;
}

extern "C" int *destroy(Plugin *p) {
    delete p;
    return 0;
}