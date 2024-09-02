#include <QDebug>
#include <QStringList>
using namespace std;


int main()
{

    QString cars = "Mercedes, BMW";
    QString vans = "Hilux, Isuzu";
    QString trucks = "MAN, Scania";


    QStringList list;

    list.append(cars);   //appending
    list <<vans;         //writing in
    list += trucks;       //adding in


    qDebug() <<"Called without an index: "<<list;

    qDebug() <<" ";

    qDebug() <<"Called by index eg list[1]: "<<list[1];    //Separate strings put together in a list but its like an array where they are still separate
    //and i can call an index

    qDebug() <<" ";

    QString allcars = list.join(", ");
    qDebug() <<"Using the join() function: "<<allcars;    //Here you cant use an index becuase they are joined togther
    //no more like an array


    QStringList SplitUp = allcars.split(", ");   //you slip the QString which is allcars into individual strings

    qDebug() <<" ";

    qDebug() <<"Using split() fucntion: "<<SplitUp;

    qDebug() <<" ";

    //Please take note split() and join() can only be used on QStrings not on QStringList or on QList

    return 0;

}
