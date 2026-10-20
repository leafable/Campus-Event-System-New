#pragma once
#include <vector>
#include <string>
#include <memory>
#include "Event.h"

class EventSystem
{
private:
    vector<unique_ptr<Event>> events;
    static int numEvents;
    friend class FileManager;
public:
    void createEvent(unique_ptr<Event> event);
    int findEventById(int id) const; // Returns index of event
    int findEventByDescription(const string &description) const;
    int findEventByDate(const string &date) const;
    int findEventByTime(const string &time) const;
    int findEventByLocation(const string &location) const;
    int findEventByCapacity(int capacity) const;
    int findEventByOrganization(const string &organization) const;
    int findEventByDuration(const string &duration) const;
    int findEventByName(const string& name) const;
    void displayEvent(int index) const;
    void displayAllEvents() const;
    const vector<unique_ptr<Event>>* getEventsPointer() const;
};