//
// Created by 71401 on 2021/6/25.
//

#include "plugin.h"
#include <iostream>
#include <sstream>
#include <regex>

class Styled : public Plugin {
public:
    Styled() : Plugin() {
        this->name = "styled";
        this->author = "Second Lobster";
        this->description = "description: (Just Write anything you like)";
        this->help = "help: (Just Write anything you like)";
    }

    string response(const string &str) const override {
        return "You are not playing Warcraft 3, guys...";
    }

    int matchRule(const string &str) const override {
        istringstream iStream(str);
        string name;
        iStream >> name;
        if (name == "WhosYourDaddy") {
            return 1;
        }
        return 0;
    }

    string toString() const override {
        string output = "Second Lobster writes styled because he thinks it is fun";
        return output;
    }

};

extern "C" Plugin *create() {
    return new Styled;
}

extern "C" int *destroy(Plugin *p) {
    delete p;
    return 0;
}