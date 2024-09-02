#include <QTextStream>
#include <qDebug>
using namespace std;


int main()
{
    QTextStream input(stdin);
    int value;

    qDebug() <<"Enter value";
    input >>value;

    qDebug() <<value;


    return 0;
}
