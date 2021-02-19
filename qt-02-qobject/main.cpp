#include <QCoreApplication>
#include <QDebug>

#include "human.h"

void printTreeInfo(QObject *parent)
{
    // TODO: print here info about all nodes
    Human *human = qobject_cast<Human*>(parent);
    qDebug() << parent->objectName()
             << "age:" << human->age()
             << "sex:" << human->sexSymbol();
    for (int i = 0; i < human->children().length(); ++i) {
        printTreeInfo(human->children().at(i));
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Human* parent;

    // TODO: create here required hierarchy
    parent = new Human;
    parent->setObjectName("Lucas Grey");
    parent->setAge(54);
    parent->setSexSymbol('M');

    Human *maryGrey = new Human(parent);
    maryGrey->setObjectName("Mary Grey");
    maryGrey->setAge(28);
    maryGrey->setSexSymbol('F');

    Human *jasonGrey = new Human(parent);
    jasonGrey->setObjectName("Jason Grey");
    jasonGrey->setAge(32);
    jasonGrey->setSexSymbol('M');

    Human *fredSmith = new Human(maryGrey);
    fredSmith->setObjectName("Fred Smith");
    fredSmith->setAge(2);
    fredSmith->setSexSymbol('M');

    Human *janeSmith = new Human(maryGrey);
    janeSmith->setObjectName("Jane Smith");
    janeSmith->setAge(2);
    janeSmith->setSexSymbol('F');

    Human *seanGrey = new Human(jasonGrey);
    seanGrey->setObjectName("Sean Grey");
    seanGrey->setAge(5);
    seanGrey->setSexSymbol('M');

    Human *jessicaGrey = new Human(jasonGrey);
    jessicaGrey->setObjectName("Jessica Grey");
    jessicaGrey->setAge(1);
    jessicaGrey->setSexSymbol('F');

    Human *hannahGrey = new Human(jasonGrey);
    hannahGrey->setObjectName("Hannah Grey");
    hannahGrey->setAge(1);
    hannahGrey->setSexSymbol('F');

	// TODO: dump tree info using standard Qt method
    parent->dumpObjectTree();
    printTreeInfo(parent);

    // TODO: delete here what need only
    delete parent;

    return a.exec();
}
