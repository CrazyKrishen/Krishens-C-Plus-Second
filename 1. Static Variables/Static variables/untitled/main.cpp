#include <QDebug>
using namespace std;


//static means if one object gets updated in the int main(), the other objects get updated in the int main() automatically


class Person
{
private:
    static int shared;    //this is a static variable which every Person object shares one memory location with 'shared'
                          //meaning if any instance object in the int main() gets updated, all objects get updated in
                          //the int main() becuase that object updates the static variable here and the static object
                          //updates all other objects in the int main().
                          //So conclusion is all objects in the int main() share one memeory location.
                          //its needs a global variale to be updated

public:

    int getSharedVariable()
    {
        return shared;
    }
    void addOne() //adds one each time called
    {
        shared++;
    }

};

//definition of static memeber variable outside the class (global variable)
int Person::shared =0;




int main()
{
    Person obj1, obj2;

    qDebug() <<"Object1: "<<obj1.getSharedVariable()<<" Object2: "<<obj2.getSharedVariable();

    obj1.addOne();   //adding one to  object1

    qDebug() <<"Object1: "<<obj1.getSharedVariable()<<" Object2: "<<obj2.getSharedVariable();//both objects(obj1 and obj2)
    //get updated


    obj2.addOne();   //adding one to obj2
    qDebug() <<"Object1: "<<obj1.getSharedVariable()<<" Object2: "<<obj2.getSharedVariable(); //both objects(obj1 and obj2)
    //get updated




    return 0;
}

//video to explain: https://www.youtube.com/watch?v=_eV0qHYsfq4



