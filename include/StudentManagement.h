#pragma once
#include <iostream>
#include <vector>
#include "Student.h"

class StudentManagement {
private:
    vector<Student> students;
    static int numStudents;
    friend class FileManager;
public:
    StudentManagement();
    void addStudent(const Student& student);
    void addStudent(int id, const string& name, const string& email, const string& major);
    int findById(int id) const;
    int findByName(const string& name) const;
    void displayStudent(int id) const;
    void displayStudent(const string& name);
    void displayAllStudents() const;
    bool isDuplicateId(int id) const;
    static int getNumStudents();
    const vector<Student>& getStudentVector();
};