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
int EventSystem::findEventById(const int id) const
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
void EventSystem::displayEvent(const int id) const
{
    int index = findEventById(id);
    if (index != -1)
    {
        events[index]->printDetails();
    }
    else
    {
        cerr << "Error: Event not found." << endl;
    }
}
void EventSystem::displayEvent(const string& name) const
{
    int index = findEventByName(name);
    displayEvent(index);
}
void EventSystem::displayAllEvents() const {
    for (const auto& event : events)
    {
        event->printDetails();
        cout << endl;
    }
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

const vector<unique_ptr<Event>>* EventSystem::getEventsPointer() const {
    return &events;
}

