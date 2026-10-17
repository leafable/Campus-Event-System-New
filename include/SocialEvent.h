#pragma once
#include "Event.h"

class SocialEvent : public Event{
    private:
    bool isFancy;
    public:
    SocialEvent(int id, string name, string description, string date, string time,  string location, int maxCap, string organizer, string eventLength, bool isFancy);
    ~SocialEvent() override = default;
    bool getIfFancy() const;
    void setIfFancy(bool isFancy);
    void printDetails() const override;
    string getCSV() override;
};