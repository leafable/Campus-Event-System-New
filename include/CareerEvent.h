#pragma once
#include "Event.h"

class CareerEvent : public Event{
    private:
    string companyName;
    string recruiterName;
    public:
    CareerEvent(int id, string name, string description, string date, string time,  string location, int maxCap, string organizer, string eventLength, string companyName, string recruiterName);
    string getCompanyName() const;
    string getRecruiterName() const;
    void setCompanyName(string newCompanyName);
    void setRecruiterName(string newRecruiterName);
    void printDetails() const override;
};