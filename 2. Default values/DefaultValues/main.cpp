#include <QCoreApplication>
#include <QDate>
#include <iostream>
using namespace std;

class Date
{
public:
    Date(int d = 0, int m = 0, int y = 0);
    void display(bool eoln = true) const;
private:
    int m_Day, m_Month, m_Year;
};

Date::Date(int d , int m , int y ): m_Day(d), m_Month(m), m_Year(y)
{
 static QDate currentDate = QDate::currentDate();
 if (m_Day == 0) m_Day = currentDate.day();
 if (m_Month == 0) m_Month = currentDate.month();
 if (m_Year == 0) m_Year = currentDate.year();
}


void Date::display(bool eoln) const
{
 using namespace std;
 cout << m_Year << "/" << m_Month << '/' << m_Day;
 if (eoln)
 cout << endl;
}





int main() {

    Date d1;
    Date d2(15);
    Date d3(23, 8);
    Date d4(19, 11, 2003);

    d1.display(false);
    cout << '\t';
    d2.display();

    d3.display(false);
    cout << '\t';
    d4.display();


    return 0;
}

