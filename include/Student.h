#pragma once
#include <iostream>
#include <string>

using namespace std;

class Student {
private:
    int id;
    string name;
    string email;
    string major;
    friend class FileManager;
public:
    Student();
    Student(const int id, const string& name, const string& email, const string& major);
    int getId() const;
    string getName() const;
    string getEmail() const;
    string getMajor() const;
};