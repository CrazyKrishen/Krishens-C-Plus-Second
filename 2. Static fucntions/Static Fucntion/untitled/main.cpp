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



    static void updatedShared(int i)   //static fucntion update
    {
        shared = i;
    }

    static int retreiveShared()
    {
        return shared;
    }

    //these static functions can be executed without an instance of class Person (without Person object being decalred), only class
    //name being called
};

//definition of static memeber variable outside the class (global variable)
int Person::shared =0;




int main()
{



    //no instance of Person defined (This is for the static fucntions), meaning no object of person was created, only the class name was called
    //with scope resolution ::
    qDebug() <<Person::retreiveShared();

    Person::updatedShared(99);   //giving static object a value


    qDebug() <<Person::retreiveShared();   //returned updated


    return 0;
}

//video to explain: https://www.youtube.com/watch?v=_eV0qHYsfq4
