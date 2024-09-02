#include <QCoreApplication>
#include <iostream>
#include <qDebug>

template <class Type>
Type Added(Type a, Type b)
{
    Type c = a+b;
    return c;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    int integer = Added(50,2);
    short value = Added(100, 90);  //this is also an integer just like double and flaot are the same thing

    qDebug() <<"Integer: "<<integer<<'\n';
    qDebug() <<"short: "<<value<<'\n';



    return a.exec();
}
