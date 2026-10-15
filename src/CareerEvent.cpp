#include "CareerEvent.h"

CareerEvent::CareerEvent(int id, string name, string description, string date, string time,  string location, int maxCap, string organizer, string eventLength, string companyName, string recruiterName) : Event(id, name, description, date, time, location, maxCap, organizer, eventLength){
    this->companyName = companyName;
    this->recruiterName = recruiterName;
}

string CareerEvent::getCompanyName() const {
    return companyName;
}

string CareerEvent::getRecruiterName() const {
    return recruiterName;
}

void CareerEvent::setCompanyName(string newCompanyName){
    this->companyName = newCompanyName;
}

void CareerEvent::setRecruiterName(string newRecruiterName){
    this->recruiterName = newRecruiterName;
}

void CareerEvent::printDetails() const {
    Event::printDetails();
    cout << "Company: " << getCompanyName() << endl;
    cout << "Recruiter: " << getRecruiterName() << endl;
}
