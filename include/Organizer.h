#pragma once
#include <string>

using namespace std;

class Organizer {
private:
    string name;
    int organizerId;
    string email;
    string department;
public:
    Organizer(const string& name, int organizerId, const string& email, const string& department);
    string getName() const;
    int getOrganizerId() const;
    string getEmail() const;
    string getDepartment() const;
};