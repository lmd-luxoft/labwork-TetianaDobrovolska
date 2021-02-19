#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include <QObject>
#include <QString>

class BankAccount : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString holderName READ holderName WRITE setHolderName)
    Q_PROPERTY(qint64 balance MEMBER m_balance READ balance CONSTANT)

public:
    explicit BankAccount(QObject *parent = 0);

    void deposit(long amount);
    void withdraw(long amount);

    QString holderName();
    void setHolderName(QString holderName);
    quint64 balance();

private:
    QString m_holderName;
    long m_balance;
};

#endif // BANKACCOUNT_H
