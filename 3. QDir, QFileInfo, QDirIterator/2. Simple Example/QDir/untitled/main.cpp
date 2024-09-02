#include <QDebug>
#include <QDir>  //include this

int main()
{
    QDir directory("C:/Users/krish/Desktop/Modules 2024/COS2614/Lessons/Chapter 4/3. QDir, QFileInfo, QDirIterator/2. Simple Example/QDir/untitled");
    //Searching to see if its own file exists

    if(directory.exists())
    {
        qDebug() <<"The file does exist";
    }
    else
    {
        qDebug() <<"The file does not exist";
    }



    foreach(QFileInfo var, directory.drives())   //var takes in the drive where the directory is kept on
    {
        qDebug() <<var.absoluteFilePath();    //the drives will be displayed
    }

}
