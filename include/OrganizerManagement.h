#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Organizer.h"
#include "EventSystem.h"

class OrganizerManagement
{
private:
    vector<Organizer> organizers;
    vector<vector<int>> associatedEventIds;
    static int numOrganizers;
public:
    OrganizerManagement(const EventSystem& events);
    void addOrganizer(const string& name, int organizerId, const string& email, const string& department);
    int findByName(const string& name) const;
    void displayOrganizer(const string& name) const;
    void displayAllOrganizers() const;
    int getNumOrganizers() const;
    const vector<Organizer>* getOrganizersPointer() const;
    void updateOrganizers(const EventSystem& events);
    void viewAssociatedEvents(const string& name, const EventSystem& events) const;
};