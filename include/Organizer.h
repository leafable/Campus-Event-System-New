#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Event.h"

using namespace std;

class Organizer {
private:
    string name;
    int organizerId;
    string email;
    string department;
public:
    Organizer(const string& name, const int organizerId, const string& email, const string& department);
    string getName() const;
    int getOrganizerId() const;
    string getEmail() const;
    string getDepartment() const;
};