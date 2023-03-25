#include <iostream>
#include "Person.h"
using namespace std;


class Customer : public Person //Inherits from class Person
{
private:
    int mechanicID;
    Appointment appointment;
public:
    bool operator< (const Customer& other) const
    {
        if (appointment.hours < other.appointment.hours)
            return true;
        else if (appointment.hours == other.appointment.hours && appointment.minutes < other.appointment.minutes)
            return true;
        else
            return false;
    }
    bool operator> (const Customer& other) const
    {
        if (appointment.hours > other.appointment.hours)
            return true;
        else if (appointment.hours == other.appointment.hours && appointment.minutes > other.appointment.minutes)
            return true;
        else
            return false;
    }
    bool operator== (const Customer& other) const
    {
        if (appointment.hours == other.appointment.hours && appointment.minutes == other.appointment.minutes)
            return true;
        else
            return false;
    }
    void setMechanicID(int id)
    {
        mechanicID = id;
    }
    void setAppointment(int h, int m)
    {
        appointment.hours = h; appointment.minutes = m;
    }
    int getMechanicID() const
    {
        return mechanicID;
    }
    Appointment getAppointment() const
    {
        return appointment;
    }
};