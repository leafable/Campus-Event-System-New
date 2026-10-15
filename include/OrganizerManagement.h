#pragma once
#include <string>
#include <vector>
#include "Organizer.h"

class OrganizerManagement
{
private:
    vector<Organizer> organizer;
    static int numOrganizers;
public:
    OrganizerManagement();
    void addOrganizer(const string& name, const int organizerId, const string& email, const string& department);
    int findByName(const string& name) const;
    void displayOrganizer(const string& name) const;
    void displayAllOrganizers() const;
    int getNumOrganizers() const;
    const vector<Organizer>* getOrganizersPointer() const;
};