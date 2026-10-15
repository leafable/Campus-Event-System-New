#pragma once
#include <string>
#include <iostream>
using namespace std;

class Event{
    protected:
    int id;
    string eventName;  // string that stores the events name
    string eventDescription;  //string that stores what the event is about
    string eventDate;  //this is the date of the event as a string, stored as 
                       //(month day) ex) october 1st
    string eventTime;  //the time will just be the hour the event starts
    string eventLength;  //stores how long the event will run in number of hours
    string eventLocation;  //stores the name of the events location
    int eventMaxCapacity;  //stores the max capacity of the event location
    string organizer;  //stores the name of the event organizer
    public:
    Event(int id, string name, string description, string date, string time,  string location, int maxCap, string organizer, string eventLength);
    string getEventName() const;  //Returns the events name
    virtual string getEventDescription() const;  //Returns the events description
    string getEventDate() const;  //Returns the events date in the form
                                  //of a string
    string getEventTime() const;  //Returns the time the event starts
    string getEventLocation() const;  //Returns the name of the location
                                      //of the event
    int getEventMaxCapacity() const;  //Returns the events maximum
                                      //capacity of people
    string getOrganizer() const;  //Returns name of the organizer
    string getEventLength() const;  //Returns the length of the event in
                                 //the number of hours
    void setEventName(string newEventName);  //Changes the events name
    void setEventDescription(string newEventDescription);
                                //changes the events description
    void setEventDate(string newEventDate);  //changes the events date
    void setEventTime(string newEventTime);  //changes the time the event 
                                          //starts
    void setEventLength(string newEventLength);  //changes the amount of
                                              //hours the event is set
                                              //to run
    void setEventMaxCapacity(int newEventMaxCapacity);
                                        //changes the events max cap
    void setOrganizer(string newOrganizer); //changes the organizer of
                                            //the event
    void setLocation(string newLocation);  //changes the location of the
                                           //event
    int getEventId() const;
    virtual void printDetails() const;
};