#include "OrganizerManagement.h"

int OrganizerManagement::numOrganizers = 0;

OrganizerManagement::OrganizerManagement()
{
}
void OrganizerManagement::addOrganizer(const string& name, const int organizerId, const string& email, const string& department)
{
    organizer.push_back(Organizer(name, organizerId, email, department));
    numOrganizers++;
}
int OrganizerManagement::findByName(const string& name) const
{
    for (int i = 0; i < organizer.size(); i++) {
        if (organizer[i].getName() == name) {
            return i;
        }
    }
    return -1;
}
void OrganizerManagement::displayOrganizer(const string& name) const
{
    int index = findByName(name);
    if (index != -1) {
        cout << "Name: " << organizer[index].getName() << endl;
        cout << "ID: " << organizer[index].getOrganizerId() << endl;
        cout << "Email: " << organizer[index].getEmail() << endl;
        cout << "Department: " << organizer[index].getDepartment() << endl;
    }
    else {
        cout << "Organizer not found." << endl;
    }
}
void OrganizerManagement::displayAllOrganizers() const
{
    for (int i = 0; i < organizer.size(); i++)
    {
        cout << "Name: " << organizer[i].getName() << ", ID: " << organizer[i].getOrganizerId() << ", Email: " << organizer[i].getEmail() << ", Department: " << organizer[i].getDepartment() << endl; 
    }
}
int OrganizerManagement::getNumOrganizers() const
{
    return numOrganizers;
}
const vector<Organizer>* OrganizerManagement::getOrganizersPointer() const {
    return &organizer;
}