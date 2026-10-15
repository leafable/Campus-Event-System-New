#ifndef REGISTRATION_H
#define REGISTRATION_H

#include <string>

class Registration
{
private:
    int studentID;
    int eventID;
    std::string registrationDate;
    bool status;

public:
    Registration();
    

    Registration(int studentID, int eventID,
                 const std::string& registrationDate,
                 bool status = 1);

    
    int getStudentID() const;
    int getEventID() const;
    const std::string& getRegistrationDate() const;
    const bool getStatus() const;

    void setStatus(bool status);
};

#endif