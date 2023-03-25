#include <iostream>
#include "Person.h"
#include "Customer.h"
using namespace std;

class Mechanic : public Person
{
private:
    int counter;
    Appointment appointments[10];
public:
    Mechanic(string n, int a) : Person(n), counter(0)
    {
    }
    bool isAvailable(int time)
    {
        for (int i = 0; i < counter; i++)
        {
            if (appointments[i].hours * 60 + appointments[i].minutes == time)
            {
                return false;
            }
        }
        return true;
    }
    void addAppointment(int hour, int minute)
    {
        if (counter >= 10)
        {
            cout << "Cannot add appointment. Mechanic is fully booked." << endl;
            return;
        }
        appointments[counter].hours = hour;
        appointments[counter].minutes = minute;
        counter++;
    }
    int getCounter()
    {
        return counter;
    }
    void setCounter(int c)
    {
        counter = c;
    }
    int getAppointmentHour(int index)
    {
        return appointments[index].hours;
    }
    int getAppointmentMinute(int index)
    {
        return appointments[index].minutes;
    }
    void setAppointmentHour(int index, int hour)
    {
        appointments[index].hours = hour;
    }
    void setAppointmentMinute(int index, int minute)
    {
        appointments[index].minutes = minute;
    }
    void removeAppointment(int index)
    {
        for (int i = index + 1; i < counter; i++)
        {
            appointments[i - 1] = appointments[i];
        }
        counter--;
    }
};
