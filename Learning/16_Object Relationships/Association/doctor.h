#ifndef DOCTOR_H
#define DOCTOR_H

#include <string>
#include <string_view>
#include <functional>
#include <vector>
#include <iostream>

class Patient;

class Doctor
{
private:
    std::string_view m_name{};
    std::vector<std::reference_wrapper<const Patient>> m_patients{};

public:
    Doctor(std::string_view name) : m_name{ name }
    {        
    }

    std::string_view getName() const;
    void addPatient(Patient&);
    bool hasPatients() const;

    friend std::ostream& operator<<(std::ostream&, const Doctor&);

};

#endif
