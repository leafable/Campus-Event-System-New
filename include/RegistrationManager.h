#ifndef REGISTRATIONMANAGER_H
#define REGISTRATIONMANAGER_H

#include <vector>
#include "Registration.h"

class RegistrationManager
{

    friend class FileManager;
        
private:
    std::vector<Registration> registrations;

    // Returns the position of a registration (active or cancelled) in the vector, or -1 if not found
    int findIndex(int studentID, int eventID) const;

public:
    void loadRegistration(const Registration& registration);
    // Returns false if this student is already actively registered OR the event is full.
    // If the student previously cancelled, their registration is reactivated.
    bool addRegistration(const Registration& registration, int MaxCapacity);

    // Returns true only if the student has an active (not cancelled) registration
    bool isRegistered(int studentID, int eventID) const;    

    bool isFull(int eventID, int maxCapacity) const;

    // Marks the registration as cancelled (status = false).
    // Returns false if there is no active registration to cancel.
    bool cancelRegistration(int studentID, int eventID);

    // Counts only active registrations
    int countForEvent(int eventID) const;

    // Prints whether the student is registered, cancelled, or has no registration for this event
    void printRegistrationStatus(int studentID, int eventID) const;

    // Return only active registrations
    std::vector<int> getEventIDsForStudent(int studentID) const;
    std::vector<int> getStudentIDsForEvent(int eventID) const;

    // Used by FileManager when saving (includes cancelled registrations)
    const std::vector<Registration>& getAllRegistrations() const;
};

#endif