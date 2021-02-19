#include <QCoreApplication>
#include <QDebug>
#include <QStack>
#include <qdebug.h>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QList<QString> names;
    names << "Mary" << "Ann" << "Charlynn" << "Marylynn" << "Margaret"
          << "Kate" << "Rose" << "Gwendolyn";


    // TODO: using Java-style iterators print the longest name from the list
    // use QString::arg to output message with this name
    QListIterator<QString> javaIterator(names);
    QString longestName = javaIterator.next();
    while (javaIterator.hasNext()) {
        QString currentName = javaIterator.next();
        if (currentName.size() >= longestName.size())
            longestName = currentName;
    }
    QString output("Longest name: %1");
    qDebug() << output.arg(longestName);

    // TODO: using STL-style iterators print the shortest name from the list
    // use QString::prepend and append to output message with this name
    QString shortestName = *names.begin();
    for (QList<QString>::iterator i = names.begin(); i != names.end(); ++i) {
        if ((*i).size() <= shortestName.size())
            shortestName = *i;
    }
    qDebug() << shortestName.prepend("Shortest name: ");

    // TODO: using foreach and QStringList show all names with "lynn" suffix
    // and print it separated by ',' as one string
    QStringList namesList;
    foreach (QString name, names) {
        if(name.contains("lynn"))
            namesList += name;
    }
    qDebug() << namesList.join(',');

    // print all names in reverse order
    // TODO: 1. Using QStack
    QStack<QString> namesReverseStack;
    for(QList<QString>::reverse_iterator it = names.rbegin(); it != names.rend(); ++it) {
        namesReverseStack.push(*it);
    }
    qDebug() << namesReverseStack;

    // TODO: 2. Using other QList
    QList<QString> namesReverseList;
    for(QList<QString>::reverse_iterator it = names.rbegin(); it != names.rend(); ++it) {
        namesReverseList.append(*it);
    }
    qDebug() << namesReverseList;

    // TODO: 3. Without other containers
    for (int i = 0; i < names.size()/2; ++i) {
        names.swap(i, names.size() - i - 1);
    }
    qDebug() << names;

    return a.exec();
}
