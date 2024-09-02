#include <QList>
#include <QString>
#include <QDebug>

int main()
{


    QList<QString> list;

    list.append("Pear");
    list.append("bananas");
    list.append("Oranges");



       qDebug() <<list;



    return 0;
}
