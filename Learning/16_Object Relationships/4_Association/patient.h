#ifndef PATIENT_H
#define PATIENT_H

#include <string>
#include <string_view>
#include <vector>
#include <functional>
#include <iostream>

class Doctor;

class Patient
{
private:
    std::string m_name{};
    std::vector<std::reference_wrapper<const Doctor>> m_doctors{};

public:
    Patient(std::string_view name) : m_name{ name }
    {        
    }
    
    std::string_view getName() const;
    void addDoctor(const Doctor&);
    bool hasDoctors() const;

    friend std::ostream& operator<<(std::ostream&, const Patient&);
};

#endif
