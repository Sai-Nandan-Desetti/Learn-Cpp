#include "doctor.h"
#include "patient.h"


std::string_view Doctor::getName() const
{
    return m_name;
}

void Doctor::addPatient(Patient& patient)
{
    m_patients.push_back(patient);
    patient.addDoctor(*this);
}

bool Doctor::hasPatients() const
{
    return not m_patients.empty();
}

std::ostream& operator<<(std::ostream& out, const Doctor& doctor)
{
    if (doctor.hasPatients())
    {   
        out << doctor.m_name << " is seeing patients: ";
        for (auto patient : doctor.m_patients)
            out << patient.get().getName() << ' ';
    }
    else
    {
        out << doctor.m_name << " isn't seeing any patients now.";
    }
    
    return out;
}
