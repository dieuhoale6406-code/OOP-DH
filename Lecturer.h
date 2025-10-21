#pragma once
#include "Person.h"

class Lecturer : public Person {
        String LecturerID;
        String rank;
        static bool is_space(char);
    public:
        Lecturer();
        Lecturer(const String&, int, const String&, bool, const String&);
        ~Lecturer();

        const String& getId() const;
        const String& getRank() const;
        void setRank(const String&);
        void setId();
        void setName(const String&);

        void show() const override;

        friend std::ostream& operator<<(std::ostream&, const Lecturer&);
        friend std::istream& operator>>(std::istream&, Lecturer&);
};