#pragma once
#include "Student.h"
#include <vector>

class StudentManagement {
private:
    vector<Student> students;
    static int numStudents;
    friend class FileManager;
public:
    StudentManagement();
    void addStudent(const Student& student);
    void addStudent(const int id, const string& name, const string& email, const string& major);
    int findById(const int id) const;
    int findByName(const string& name) const;
    void displayStudent(const int id) const;
    void displayStudent(const string& name);
    void displayAllStudents() const;
    bool isDuplicateId(const int id) const;
    static int getNumStudents();
    const vector<Student>& getStudentVector();
};