#include <QCoreApplication>
#include <QTextStream>


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // Create a QTextStream that writes to the standard output
    QTextStream out(stdout);  //to declare somehting like cout



    // Display a message using QTextStream
    out << "Hello, World! This is a QTextStream example." << endl;

    return a.exec();
}
