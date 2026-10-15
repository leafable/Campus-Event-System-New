#include "RegistrationManager.h"
#include <iostream>
 
using namespace std;
 
int RegistrationManager::findIndex(int studentID, int eventID) const
{
    for (size_t i = 0; i < registrations.size(); i++)
    {
        if (registrations[i].getStudentID() == studentID &&
            registrations[i].getEventID() == eventID)
        {
            return static_cast<int>(i);
        }
    }
    return -1;
}
 
bool RegistrationManager::addRegistration(const Registration& registration, int maxCapacity)
{
    // check if student is not already actively registered for this event
    if (isRegistered(registration.getStudentID(), registration.getEventID()))
    {
        return false;
    }
 
    // check if event still has space
    if (isFull(registration.getEventID(), maxCapacity))
    {
        return false;
    }
 
    // check if student cancelled and rewrites that to avoid duplicate entries
    int index = findIndex(registration.getStudentID(), registration.getEventID());
    if (index != -1)
    {
        registrations[index] = registration;
        registrations[index].setStatus(true);
        return true;
    }
 
    registrations.push_back(registration);
    return true;
}

// used only by FileManager when loading saved registrations from the file:
// these were already checked when they were first made, so they go straight into the vector
void RegistrationManager::loadRegistration(const Registration& registration)
{
    registrations.push_back(registration);
}

bool RegistrationManager::isRegistered(int studentID, int eventID) const
{
    int index = findIndex(studentID, eventID);
    return index != -1 && registrations[index].getStatus();
}
 
bool RegistrationManager::isFull(int eventID, int maxCapacity) const
{
    return countForEvent(eventID) >= maxCapacity;
}
 
bool RegistrationManager::cancelRegistration(int studentID, int eventID)
{
    // Can only cancel an active registration
    if (!isRegistered(studentID, eventID))
    {
        return false;
    }
 
    int index = findIndex(studentID, eventID);
    registrations[index].setStatus(false);
    return true;
}
 
int RegistrationManager::countForEvent(int eventID) const
{
    int count = 0;
    for (const Registration& registration : registrations)
    {
        if (registration.getEventID() == eventID && registration.getStatus())
        {
            count++;
        }
    }
    return count;
}
 
void RegistrationManager::printRegistrationStatus(int studentID, int eventID) const
{
    int index = findIndex(studentID, eventID);
 
    if (index == -1)
    {
        cout << "No registration found for student " << studentID
             << " in event " << eventID << ".\n";
    }
    else if (registrations[index].getStatus())
    {
        cout << "Student " << studentID << " is registered for event "
             << eventID << ".\n";
    }
    else
    {
        cout << "Student " << studentID << " cancelled their registration for event "
             << eventID << ".\n";
    }
}
 
vector<int> RegistrationManager::getEventIDsForStudent(int studentID) const
{
    vector<int> eventIDs;
    for (const Registration& registration : registrations)
    {
        if (registration.getStudentID() == studentID && registration.getStatus())
        {
            eventIDs.push_back(registration.getEventID());
        }
    }
    return eventIDs;
}
 
vector<int> RegistrationManager::getStudentIDsForEvent(int eventID) const
{
    vector<int> studentIDs;
    for (const Registration& registration : registrations)
    {
        if (registration.getEventID() == eventID && registration.getStatus())
        {
            studentIDs.push_back(registration.getStudentID());
        }
    }
    return studentIDs;
}
 
const vector<Registration>& RegistrationManager::getAllRegistrations() const
{
    return registrations;
}