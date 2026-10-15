#include "Registration.h"

using namespace std;

Registration::Registration()
    : studentID(0), eventID(0), registrationDate(""), status(1)
{
}

Registration::Registration(int studentID, int eventID,
                           const string& registrationDate,
                           bool status)
    : studentID(studentID), eventID(eventID),
      registrationDate(registrationDate), status(status)
{
}

int Registration::getStudentID() const
{
    return studentID;
}

int Registration::getEventID() const
{
    return eventID;
}

const string& Registration::getRegistrationDate() const
{
    return registrationDate;
}

const bool Registration::getStatus() const
{
    return status;
}

void Registration::setStatus(const bool status)
{
    this->status = status;
}