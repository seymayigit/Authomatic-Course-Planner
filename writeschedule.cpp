#include "writeschedule.h"
#include <QDebug>
#include <QFile>
writeSchedule::writeSchedule()
{


}

void writeSchedule::writeFile(const QVector<day>& schedule)
{
    QFile mfile("C:/Users/Hatice Seyma Yigit/Documents/CoursePlanner/writedosya.txt");
    if(!mfile.open(QFile::WriteOnly | QFile::Text))
    {
        qDebug() << mfile.errorString();
    }

        QTextStream out(&mfile);

        for (int i=0; i<schedule.size(); i++) {

            if ( schedule[i].morning.bigClassroom1 == true )
                qDebug() << schedule[i].dayName << " Morning bigClassroom1 " << schedule[i].morning.bigClassroom1Course.getCourseCode();
                out << schedule[i].dayName << " Morning bigClassroom1 " << schedule[i].morning.bigClassroom1Course.getCourseCode()<<endl;
            if ( schedule[i].morning.bigClassroom2 == true )
                qDebug() << schedule[i].dayName << " Morning bigClassroom2 " << schedule[i].morning.bigClassroom2Course.getCourseCode();
                out<<schedule[i].dayName << " Morning bigClassroom2 " << schedule[i].morning.bigClassroom2Course.getCourseCode()<<endl;
            if ( schedule[i].morning.smallClassroom1 == true )
                qDebug() << schedule[i].dayName << " Morning smallClassroom1 " << schedule[i].morning.smallClassroom1Course.getCourseCode();
                out<<schedule[i].dayName << " Morning smallClassroom1 " << schedule[i].morning.smallClassroom1Course.getCourseCode()<<endl;
            if ( schedule[i].morning.smallClassroom2 == true )
                qDebug() << schedule[i].dayName << " Morning smallClassroom2 " << schedule[i].morning.smallClassroom2Course.getCourseCode();
                out<<schedule[i].dayName << " Morning smallClassroom2 " << schedule[i].morning.smallClassroom2Course.getCourseCode()<<endl;
            if ( schedule[i].afternoon.bigClassroom1 == true )
                qDebug() << schedule[i].dayName << " Afternoon bigClassroom1 " << schedule[i].afternoon.bigClassroom1Course.getCourseCode();
                out<<schedule[i].dayName << " Afternoon bigClassroom1 " << schedule[i].afternoon.bigClassroom1Course.getCourseCode() <<endl;
            if ( schedule[i].afternoon.bigClassroom2 == true )
                qDebug() << schedule[i].dayName << " Afternoon bigClassroom2 " << schedule[i].afternoon.bigClassroom2Course.getCourseCode();
                out<<schedule[i].dayName << " Afternoon bigClassroom2 " << schedule[i].afternoon.bigClassroom2Course.getCourseCode()<<endl;
            if ( schedule[i].afternoon.smallClassroom1 == true )
                qDebug() << schedule[i].dayName << " Afternoon smallClassroom1 " << schedule[i].afternoon.smallClassroom1Course.getCourseCode();
                out<<schedule[i].dayName << " Afternoon smallClassroom1 " << schedule[i].afternoon.smallClassroom1Course.getCourseCode()<<endl;
            if ( schedule[i].afternoon.smallClassroom2 == true )
                qDebug() << schedule[i].dayName << " Afternoon smallClassroom2 " << schedule[i].afternoon.smallClassroom2Course.getCourseCode();
                out<<schedule[i].dayName << " Afternoon smallClassroom2 " << schedule[i].afternoon.smallClassroom2Course.getCourseCode()<<endl;
        }

        qDebug() << " FILE PRINTED!!";
       mfile.flush();
       mfile.close();
}

