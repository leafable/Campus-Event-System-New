#include "SocialEvent.h"

SocialEvent::SocialEvent(int id, string name, string description, string date, string time,  string location, int maxCap, string organizer, string eventLength, bool isFancy) : Event(id, name, description, date, time, location, maxCap, organizer, eventLength){
    this->isFancy = isFancy;
}

bool SocialEvent::getIfFancy() const {
    return isFancy;
}

void SocialEvent::setIfFancy(bool isFancy){
    this->isFancy = isFancy;
}

void SocialEvent::printDetails() const {
    Event::printDetails();
    cout << "Fancy: " << (getIfFancy() ? "True" : "False") << endl;
}
