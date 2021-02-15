#ifndef HUMAN_H
#define HUMAN_H

#include <QObject>

class Human : public QObject
{
    Q_OBJECT
public:
    explicit Human(QObject *parent = nullptr);

    int age();
    void setAge(int age);

    char sexSymbol();
    void setSexSymbol(char sexSymbol);

private:
    int m_age;
    char m_sexSymbol;
};

#endif // HUMAN_H
