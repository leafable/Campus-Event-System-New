#pragma once
#include "Event.h"

class AcademicEvent : public Event{ 
    private:
    string department;  //stores the department name
    string speaker;  //stoes the speakers name
    public:
    AcademicEvent(int id, string name, string description, string date, string time,  string location, int maxCap, string organizer, string eventLength, string department, string speaker);
    string getDepartment() const;
    string getSpeaker() const;
    void setDepartment(string newDepartment);
    void setSpeaker(string newSpeaker);
    void printDetails() const override;
};