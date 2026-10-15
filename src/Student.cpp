#include "../include/Student.h"

Student::Student() {
    id = 0;
    name = "";
    email = "";
    major = "";
}

Student::Student(const int id, const string& name, const string& email, const string& major) {
    this->id = id;
    this->name = name;
    this->email = email;
    this->major = major;
}

int Student::getId() const {
    return id;
}

string Student::getName() const {
    return name;
}

string Student::getEmail() const {
    return email;
}

string Student::getMajor() const {
    return major;
}