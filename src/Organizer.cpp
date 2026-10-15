#include "Organizer.h"

Organizer::Organizer(const string& name, const int organizerId, const string& email, const string& department) {
    this->name = name;
    this->organizerId = organizerId;
    this->email = email;
    this->department = department;
}

string Organizer::getName() const {
    return name;
}

int Organizer::getOrganizerId() const {
    return organizerId;
}

string Organizer::getEmail() const {
    return email;
}

string Organizer::getDepartment() const {
    return department;
}