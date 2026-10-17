#include "OrganizerManagement.h"

int OrganizerManagement::numOrganizers = 0;

OrganizerManagement::OrganizerManagement(const EventSystem& events) {
    for (const auto& event : *events.getEventsPointer()) {
        int index = findIndexByName(event->getOrganizer());
        if (index != -1 && events.getEventsPointer()->size() != 0) {
            associatedEventIds.resize(events.getEventsPointer()->size());
            associatedEventIds[index].push_back(event->getEventId());
        }
    }
}
void OrganizerManagement::addOrganizer(const string& name, const int organizerId, const string& email, const string& department)
{
    if (findIndexByName(name) == -1) {
        organizers.push_back(Organizer(name, organizerId, email, department));
        numOrganizers++;
    }
    else {
        cout << "Organizer already exists." << endl;
    }
}
int OrganizerManagement::findIndexByName(const string& name) const
{
    for (int i = 0; i < organizers.size(); i++) {
        if (organizers[i].getName() == name) {
            return i;
        }
    }
    return -1;
}
int OrganizerManagement::findIndexById(int id) const
{
    for (int i = 0; i < organizers.size(); i++) {
        if (organizers[i].getOrganizerId() == id) {
            return i;
        }
    }
    return -1;
}
string OrganizerManagement::findNameById(int id) const {
    for (const auto& organizer : organizers) {
        if (organizer.getOrganizerId() == id) {
            return organizer.getName();
        }
    }
}
void OrganizerManagement::displayOrganizer(const string& name) const
{
    int index = findIndexByName(name);
    if (index != -1) {
        cout << "Name: " << organizers[index].getName() << endl;
        cout << "ID: " << organizers[index].getOrganizerId() << endl;

        // If the organizer does not have an email or department, display N/A
        cout << "Email: " << (organizers[index].getEmail() == "" ? "N/A" : organizers[index].getEmail()) << endl;
        cout << "Department: " << (organizers[index].getDepartment() == "" ? "N/A" : organizers[index].getDepartment()) << endl;
    }
    else {
        cout << "Organizer not found." << endl;
    }
}
void OrganizerManagement::displayOrganizer(int id) const
{
    int index = findIndexById(id);
    if (index != -1) {
        cout << "Name: " << organizers[index].getName() << endl;
        cout << "ID: " << organizers[index].getOrganizerId() << endl;

        // If the organizer does not have an email or department, display N/A
        cout << "Email: " << (organizers[index].getEmail() == "" ? "N/A" : organizers[index].getEmail()) << endl;
        cout << "Department: " << (organizers[index].getDepartment() == "" ? "N/A" : organizers[index].getDepartment()) << endl;
    }
    else {
        cout << "Organizer not found." << endl;
    }
}
void OrganizerManagement::displayAllOrganizers() const
{
    for (const auto& organizer : organizers)
    {
        displayOrganizer(organizer.getName());
        cout << endl;
    }
}
int OrganizerManagement::getNumOrganizers() const
{
    return numOrganizers;
}
const vector<Organizer>* OrganizerManagement::getOrganizersPointer() const {
    return &organizers;
}
void OrganizerManagement::updateOrganizers(const EventSystem& events) {
    for (const auto& event : *events.getEventsPointer()) {

        // Adds the organizer to the vector if it's not already in the vector
        if (findIndexByName(event->getOrganizer()) == -1) {
            if (!organizers.empty()) {
                addOrganizer(event->getOrganizer(), organizers.back().getOrganizerId() + 1, "", "");
            }
            else {
                addOrganizer(event->getOrganizer(), 1, "", "");
            }
        }
    }
}
void OrganizerManagement::viewAssociatedEvents(const string& name, const EventSystem& events) const {
    int numAssociations{};

    for (const auto& event : *events.getEventsPointer()) {
        if (event->getOrganizer() == name) {
            event->printDetails();
            cout << endl;
            numAssociations++;
        }
    }
    if (numAssociations == 0) {
        cout << "No associated events found." << endl;
    }
}