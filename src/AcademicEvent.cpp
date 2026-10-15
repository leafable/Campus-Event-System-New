#include "AcademicEvent.h"

AcademicEvent::AcademicEvent(int id, string name, string description, string date, string time,  string location, int maxCap, string organizer, string eventLength, string department, string speaker) : Event(id, name, description, date, time, location, maxCap, organizer, eventLength){
    this->department = department;
    this->speaker = speaker;
}

string AcademicEvent::getDepartment() const {
    return department;
}

string AcademicEvent::getSpeaker() const {
    return speaker;
}

void AcademicEvent::setDepartment(string newDepartment){
    this->department = newDepartment;
}

void AcademicEvent::setSpeaker(string newSpeaker){
    this->speaker = newSpeaker;
}

void AcademicEvent::printDetails() const {
    Event::printDetails();
    cout << "Department: " << getDepartment() << endl;
    cout << "Speaker: " << getSpeaker() << endl;

}