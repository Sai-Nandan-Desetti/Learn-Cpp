#include "patient.h"
#include "doctor.h"

std::string_view Patient::getName() const
{
    return m_name;
}

void Patient::addDoctor(const Doctor& doctor)
{
    m_doctors.push_back(doctor);
}

bool Patient::hasDoctors() const
{
    return not m_doctors.empty();
}

std::ostream& operator<<(std::ostream& out, const Patient& patient)
{
    if (patient.hasDoctors())
    {
        out << patient.m_name << " is seeing doctors: ";
        for (auto doctor : patient.m_doctors)
            out << doctor.get().getName() << ' ';
    }
    else
    {
        out << patient.m_name << " isn't seeing any doctors now.";
    }

    return out;        
}
