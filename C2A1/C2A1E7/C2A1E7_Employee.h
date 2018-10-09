/*
 * Nicholas Patience U07985691
 * Nickspatience@gmail.com
 * C/C++ Programming II : Dynamic Memory and File I/O Concepts
 * 134312 Ray Mitchell
 * 10/01/2018
 * C2A1E7_Employee.h
 * Win 10
 * Visual C++ 2017
 *
 * Contains information set of Employee class that has a name
 * age, raise value, and salary. Also has multiple overloaded
 * Set and Get methods
 */

#ifndef C2A1E7_EMPLOYEE_H
#define C2A1E7_EMPLOYEE_H

class Employee
{
private:
    char *name;
    int age;
    float raise;
    double salary;

public:
    void Set(const char *value);        // Proto-only

    void Set(int value = 25)            // For age
    {
        age = value;
    }
    void Set(const float &value)        // For raise
    {
        raise = value;
    }
    void Set(const double *value)       // For salary
    {
        salary = *value;
    }

    char *Get(char **value)             // For name
    {
        *value = name;
        return name;
    }
    int Get(int &value) const           // For age
    {
        value = age;
        return age;
    }
    float &Get(float &value)            // For raise
    {
        value = raise;
        return raise;
    }
    inline double Get(double *value) const;   // For salary
};

double Employee::Get(double *value) const
{
    *value = salary;
    return salary;
} 
#endif // !C2A1E7_EMPLOYEE_H
