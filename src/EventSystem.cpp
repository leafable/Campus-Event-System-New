#include "../include/EventSystem.h"
#include "../include/AcademicEvent.h"
#include "../include/ClubEvent.h"
#include "../include/CareerEvent.h"
#include "../include/SocialEvent.h"
#include <utility>

void EventSystem::createEvent(unique_ptr<Event> event)
{
    events.push_back(std::move(event));
}

int EventSystem::findEventByName(const string& name) const {
    for (int i = 0; i < events.size(); i++)
    {
        if (events[i]->getEventName() == name)
        {
            return i;
        }
    }
    return -1;
}

int EventSystem::findEventById(int id) const
{
    for (int i = 0; i < events.size(); i++)
    {
        if (events[i]->getEventId() == id)
        {
            return i;
        }
    }
    return -1;
}

int EventSystem::findEventByDescription(const string& description) const
{
    for (int i = 0; i < events.size(); i++)
    {
        if (events[i]->getEventDescription() == description)
        {
            return i;
        }
    }
    return -1;
}

int EventSystem::findEventByDate(const string& date) const
{
    for (int i = 0; i < events.size(); i++)
    {
        if (events[i]->getEventDate() == date)
        {
            return i;
        }
    }
    return -1;
}

int EventSystem::findEventByTime(const string& time) const
{
    for (int i = 0; i < events.size(); i++)
    {
        if (events[i]->getEventTime() == time)
        {
            return i;
        }
    }
    return -1;
}

int EventSystem::findEventByLocation(const string& location) const
{
    for (int i = 0; i < events.size(); i++)
    {
        if (events[i]->getEventLocation() == location)
        {
            return i;
        }
    }
    return -1;
}

int EventSystem::findEventByCapacity(int capacity) const
{
    for (int i = 0; i < events.size(); i++)
    {
        if (events[i]->getEventMaxCapacity() == capacity)
        {
            return i;
        }
    }
    return -1;
}

int EventSystem::findEventByOrganization(const string& organization) const
{
    for (int i = 0; i < events.size(); i++)
    {
        if (events[i]->getOrganizer() == organization)
        {
            return i;
        }
    }
    return -1;
}

int EventSystem::findEventByDuration(const string& duration) const
{
    for (int i = 0; i < events.size(); i++)
    {
        if (events[i]->getEventLength() == duration)
        {
            return i;
        }
    }
    return -1;
}

void EventSystem::displayEvent(int index) const
{
    events[index]->printDetails();
}

void EventSystem::displayAllEvents() const {
    for (const auto& event : events)
    {
        event->printDetails();
        cout << endl;
    }
}
const vector<unique_ptr<Event>>* EventSystem::getEventsPointer() const {
    return &events;
}

