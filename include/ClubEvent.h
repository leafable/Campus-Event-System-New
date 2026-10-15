#pragma once
#include "Event.h"

class ClubEvent : public Event{
    private:
    string club;
    public:
    ClubEvent(int id, string name, string description, string date, string time,  string location, int maxCap, string organizer, string eventLength, string club);
    string getClub() const;
    void setClub(string newClub);
    void printDetails() const override;
};