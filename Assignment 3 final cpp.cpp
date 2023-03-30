#include <iostream>
#include <string>
#include "Customer.h"
#include "Person.h"
#include "Mechanic.h"
#include "queue.h"

using namespace std;

int main()
{
    int size;
    int age, id;
    string name;

    cout << "Enter Number of available Mechanics: ";
    cin >> size;

    Mechanic* mechanics = new Mechanic[size];  //creates array of mechanics

    for (int i = 0; i < size; i++)
    {
        cout << "Enter Mechanic's Name: ";
        cin >> name;
        cout << "Enter Mechanic's ID: ";
        cin >> id;
        cout << "Enter Mechanic's Age: ";
        cin >> age;

        mechanics[i].setName(name);
        mechanics[i].setID(id);
        mechanics[i].setAge(age);
    } //user input for mechanic data

    int customerNo;
    appointment s;

    cout << "Enter Number of Customers: ";
    cin >> customerNo;

    Customer* customer = new Customer[customerNo];

    for (int i = 0; i < customerNo; i++)
    {
        cout << "Enter Customer's Name: ";
        cin >> name;
        cout << "Enter Customer's ID: ";
        cin >> id;
        cout << "Enter Customer's Age: ";
        cin >> age;
        cout << "Enter the hour of appointment: ";
        cin >> s.hours;
        cout << "Enter the minutes of appointment: ";
        cin >> s.mins;

        customer[i].setName(name);
        customer[i].setAge(age);
        customer[i].setID(id);
        customer[i].setAppointment(s);
    } //user input for customer data
    int size2 = size;
    for (int i = 0; i < customerNo; i++)
    {
        bool temp = false;
        while (size2 > 0)
        {
            if (mechanics[size - size2].isAvailable(customer[i].getAppointment())) //checks availibility of the first mechanic in line and then the next and so on
            {
                mechanics[size - size2].setAppointments(customer[i].getAppointment());
                customer[i].setMechanicID(mechanics[size - size2].getid());
                size2--;
                temp = true;
                break;
            }
            size2--;
        }
        if (size2 == 0)
            size2 = size;
        if (!temp)
        {
            cout << "Appointment Cancelled: No Mechanic is Available at that time" << endl;
            appointment f; f.hours = -1; f.mins = -1;
            customer[i].setAppointment(f);
        }

    }

    Customer temp1;

    for (int i = 0; i < customerNo; i++)
    {
        for (int j = 0; j < size; j++)
        {
            //checks that the mechanic's ID matches the one assigned to the customer
            if (customer[i].getMechanicID() == mechanics[j].getid()) 
            {

                cout << customer[i].getName() << " should be appointed to "
                    << mechanics[j].getName() << " at "
                    << customer[i].getAppointment().hours << ":";
                if (customer[i].getAppointment().mins < 10)
                    cout << "0" << customer[i].getAppointment().mins << endl;
                else
                    cout << customer[i].getAppointment().mins << endl;
                break;
            } //prints info about customer's appointment
        }
    }

    for (int i = 0; i < customerNo - 1; i++)
    {
        for (int j = i + 1; j < customerNo; j++)
        {
            if (customer[i] > customer[j]) //sorts customers in ascending order of appointments
            {

                temp1 = customer[i];
                customer[i] = customer[j];
                customer[j] = temp1;
            }
        }
    }

    queue<Customer> queue(customerNo); //defines a template Queue of type Customer

    for (int i = 0; i < customerNo; i++)
    {
        queue.Enqueue(customer[i]); //inserts customers in queue 
    }

    for (int i = 0; i < customerNo; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (customer[i].getMechanicID() == mechanics[j].getid()) //checks that the mechanic's ID matches the one assigned to the customer
            {

                cout << customer[i].getName() << " has an appointment "
                    << "at "
                    << customer[i].getAppointment().hours << ":";
                if (customer[i].getAppointment().mins < 10)
                    cout << "0" << customer[i].getAppointment().mins;
                else
                    cout << customer[i].getAppointment().mins;
                cout << " with " << mechanics[j].getName() << endl;
                break;
            }
        }
    } //prints confirmed information about customers' appointments
    return 0;
}
