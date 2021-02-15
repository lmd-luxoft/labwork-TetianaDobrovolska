#include "human.h"

Human::Human(QObject *parent) : QObject(parent)
{

}

int Human::age()
{
    return m_age;
}

void Human::setAge(int age)
{
    m_age = age;
}

char Human::sexSymbol()
{
    return m_sexSymbol;
}

void Human::setSexSymbol(char sexSymbol)
{
    m_sexSymbol = sexSymbol;
}
