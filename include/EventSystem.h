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
    void displayEvent(int id) const;
    void displayEvent(const string& name) const;
    void displayAllEvents() const;
    int findEventByName(const string& name) const; // Returns index of event
    const vector<unique_ptr<Event>>* getEventsPointer() const;
};