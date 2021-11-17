#include "mailing.h"

class mailingData : public QSharedData
{
public:

};

mailing::mailing() : data(new mailingData)
{

}

mailing::mailing(const mailing &rhs) : data(rhs.data)
{

}

mailing &mailing::operator=(const mailing &rhs)
{
    if (this != &rhs)
        data.operator=(rhs.data);
    return *this;
}

mailing::~mailing()
{

}
