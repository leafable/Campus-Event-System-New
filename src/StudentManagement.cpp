#include "../include/StudentManagement.h"

int StudentManagement::numStudents = 0;

StudentManagement::StudentManagement() {
    vector<Student> students;
}

void StudentManagement::addStudent(const Student& student) {
    if (isDuplicateId(student.getId())) {
        cout << "Error: Duplicate student ID." << endl;
    }
    else {
        students.push_back(student);
        numStudents++;
    }
}

void StudentManagement::addStudent(const int id, const string& name, const string& email, const string& major) {
    if (isDuplicateId(id)) {
        cout << "Error: Duplicate student ID." << endl;
    }
    else {
        Student student(id, name, email, major);
        students.push_back(student);
        numStudents++;
    }
}

int StudentManagement::findById(const int id) const {
    for (int i = 0; i < students.size(); i++) {
        if (students[i].getId() == id) {
            return i;
        }
    }
    return -1;
}

int StudentManagement::findByName(const string& name) const {
    for (int i = 0; i < students.size(); i++) {
        if (students[i].getName() == name) {
            return i;
        }
    }
    return -1;
}

bool StudentManagement::isDuplicateId(const int id) const {
    if (findById(id) == -1) {
        return 0;
    }
    return 1;
}

void StudentManagement::displayStudent(const int id) const {
    int index = findById(id);
    if (index != -1) {
        cout << "ID: " << students[index].getId() << endl;
        cout << "Name: " << students[index].getName() << endl;
        cout << "Email: " << students[index].getEmail() << endl;
        cout << "Major: " << students[index].getMajor() << endl;
    }
    else {
        cout << "Student not found." << endl;
    }
}

void StudentManagement::displayStudent(const string& name) {
    int index = findByName(name);
    if (index != -1) {
        cout << "ID: " << students[index].getId() << endl;
        cout << "Name: " << students[index].getName() << endl;
        cout << "Email: " << students[index].getEmail() << endl;
        cout << "Major: " << students[index].getMajor() << endl;
    }
    else {
        cout << "Student not found." << endl;
    }
}

void StudentManagement::displayAllStudents() const {
    if (!students.empty()) {
        for (int i = 0; i < students.size(); i++) {
            cout << "ID: " << students[i].getId() << ", Name: " << students[i].getName() << ", Email: " << students[i].getEmail() << ", Major: " << students[i].getMajor() << endl;
        }
    }
    else {
        cout << "No students to display." << endl;
    }
}

int StudentManagement::getNumStudents() {
    return numStudents;
}

const vector<Student>& StudentManagement::getStudentVector(){
    return students;
}