#include "ClubEvent.h"

ClubEvent::ClubEvent(int id, string name, string description, string date, string time,  string location, int maxCap, string organizer, string eventLength, string club) : Event(id, name, description, date, time, location, maxCap, organizer, eventLength){
    this->club = club;
}

string ClubEvent::getClub() const {
    return club;
}

void ClubEvent::setClub(string newClub){
    this->club = newClub;
}

void ClubEvent::printDetails() const {
    Event::printDetails();
    cout << "Club: " << getClub() << endl;
}
