#include <QCoreApplication>
#include <readcsvfile.h>
#include <course.h>
#include <QDebug>
#include <iostream>
#include <QVector>
#include <day.h>
#include <writeschedule.h>


using namespace std;

void fillVectorOfCourse(QVector<course>&);
void fillVectorOfScheduleWithService( QVector<day>&,QVector<course>&);
void fillVectorOfBusy(QVector<QString>&);
void printVectorOfCourse(const QVector<course>&);
int getNumberOfDay(QString);
void fillVectorOfScheduleWithDepartment( QVector<day>&, QVector<course>&, QVector<QVector<QString>>&);
bool isSameTimeSlotMorningForClass(day& dayValue, course& courseValue);
bool isSameTimeSlotAfternoonForClass(day& dayValue, course& courseValue);
bool isBusyOrNotCourseMorning(course& courseValue, int dayIndex, QVector<QVector<QString>>& busyTimeSlot);
bool isBusyOrNotCourseAfternoon(course& courseValue, int dayIndex, QVector<QVector<QString>>& busyTimeSlot);
void printSchedule(const QVector<day>&);


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QVector<course> myCourse;
    fillVectorOfCourse(myCourse);

    QVector<day> schedule(5);
    schedule[0].dayName = "Monday";
    schedule[1].dayName = "Tuesday";
    schedule[2].dayName = "Wednesday";
    schedule[3].dayName = "Thursday";
    schedule[4].dayName = "Friday";
    QVector<QVector<QString>> busyTimeSlot = readCsvFile().splitToString("C:/Users/Hatice Seyma Yigit/Documents/CoursePlanner/busy.csv");
    fillVectorOfScheduleWithService(schedule,myCourse);
    fillVectorOfScheduleWithDepartment(schedule, myCourse, busyTimeSlot);

   writeSchedule().writeFile(schedule);

    return a.exec();
}

int getNumberOfDay(QString dayValue){
if(dayValue=="Monday") return 0;
if(dayValue=="Tuesday") return 1;
if(dayValue=="Wednesday") return 2;
if(dayValue=="Thursday") return 3;
if(dayValue=="Friday") return 4;
else return -1;
}


void fillVectorOfScheduleWithDepartment( QVector<day>& schedule, QVector<course>& myCourse, QVector<QVector<QString>>& busyTimeSlot){
    for (int i=0; i<myCourse.size(); i++) {
        if(myCourse[i].isAssigned==true){
            continue;
        }

        bool isElective = myCourse[i].getCompulsoryOrElective() == "E" ? true : false;
        for (int dayIndex = 0; dayIndex<5; dayIndex++) {

            bool isSameClassMorningForNow = isSameTimeSlotMorningForClass(schedule[dayIndex], myCourse[i]);
            bool isSameClassAfternoonForNow = isSameTimeSlotAfternoonForClass(schedule[dayIndex], myCourse[i]);

            bool isBusyOrNotCourseMorningNow = isBusyOrNotCourseMorning(myCourse[i], dayIndex, busyTimeSlot);
            bool isBusyOrNotCourseAfternoonNow = isBusyOrNotCourseAfternoon(myCourse[i], dayIndex, busyTimeSlot);

            if ( isSameClassMorningForNow == true && isSameClassAfternoonForNow == true )
                continue;

            if ( isBusyOrNotCourseMorningNow == true && isBusyOrNotCourseAfternoonNow == true )
                continue;

            if ( isSameClassMorningForNow == false && isBusyOrNotCourseMorningNow == false )
            {
                if ( isElective )
                {
                    if(schedule[dayIndex].morning.smallClassroom1 == false){
                    schedule[dayIndex].morning.smallClassroom1 = true;
                    myCourse[i].isAssigned = true;
                    schedule[dayIndex].morning.smallClassroom1Course = myCourse[i];
                    }
                    else if(schedule[dayIndex].morning.smallClassroom2 == false){
                    schedule[dayIndex].morning.smallClassroom2= true;
                    myCourse[i].isAssigned = true;
                    schedule[dayIndex].morning.smallClassroom2Course = myCourse[i];
                    }
                    else if(schedule[dayIndex].morning.bigClassroom1 == false){
                    schedule[dayIndex].morning.bigClassroom1 = true;
                    myCourse[i].isAssigned = true;
                    schedule[dayIndex].morning.bigClassroom1Course = myCourse[i];
                    }
                    else if(schedule[dayIndex].morning.bigClassroom2 == false){
                    schedule[dayIndex].morning.bigClassroom2 = true;
                    myCourse[i].isAssigned = true;
                    schedule[dayIndex].morning.bigClassroom2Course = myCourse[i];
                    }

                }
                else { //Compulsory
                    if(schedule[dayIndex].morning.bigClassroom1 == false){
                    schedule[dayIndex].morning.bigClassroom1 = true;
                    myCourse[i].isAssigned = true;
                    schedule[dayIndex].morning.bigClassroom1Course = myCourse[i];
                    }
                    else if(schedule[dayIndex].morning.bigClassroom2 == false){
                    schedule[dayIndex].morning.bigClassroom2 = true;
                    myCourse[i].isAssigned = true;
                    schedule[dayIndex].morning.bigClassroom2Course = myCourse[i];
                    }
                }
            }
            else if ( isSameClassAfternoonForNow == false && isBusyOrNotCourseAfternoonNow == false  )
            {
                if ( isElective )
                {
                    if(schedule[dayIndex].afternoon.smallClassroom1 == false){
                    schedule[dayIndex].afternoon.smallClassroom1 = true;
                    myCourse[i].isAssigned = true;
                    schedule[dayIndex].afternoon.smallClassroom1Course = myCourse[i];

                    }
                    else if(schedule[dayIndex].afternoon.smallClassroom2 == false){
                    schedule[dayIndex].afternoon.smallClassroom2= true;
                    myCourse[i].isAssigned = true;
                    schedule[dayIndex].afternoon.smallClassroom2Course = myCourse[i];
                    }
                    else if(schedule[dayIndex].afternoon.bigClassroom1 == false){
                    schedule[dayIndex].afternoon.bigClassroom1 = true;
                    myCourse[i].isAssigned = true;
                    schedule[dayIndex].afternoon.bigClassroom1Course = myCourse[i];
                    }
                    else if(schedule[dayIndex].afternoon.bigClassroom2 == false){
                    schedule[dayIndex].afternoon.bigClassroom2 = true;
                    myCourse[i].isAssigned = true;
                    schedule[dayIndex].afternoon.bigClassroom2Course = myCourse[i];
                    }

                }
                else { //compulsory
                    if(schedule[dayIndex].afternoon.bigClassroom1 == false){
                    schedule[dayIndex].afternoon.bigClassroom1 = true;
                    myCourse[i].isAssigned = true;
                    schedule[dayIndex].afternoon.bigClassroom1Course = myCourse[i];
                    }
                    else if(schedule[dayIndex].afternoon.bigClassroom2 == false){
                    schedule[dayIndex].afternoon.bigClassroom2 = true;
                    myCourse[i].isAssigned = true;
                    schedule[dayIndex].afternoon.bigClassroom2Course = myCourse[i];
                    }
                }
            }

        }

    }
}

void fillVectorOfScheduleWithService( QVector<day>& schedule, QVector<course>& myCourse){
    readCsvFile readcsv;
    QString fileName="C:/Users/Hatice Seyma Yigit/Documents/CoursePlanner/service.csv";
    QVector<QVector<QString>> serviceCourse = readcsv.splitToString(fileName);

    for (int i=0; i<serviceCourse.size(); i++) {
         int courseIndex=-1;
        for (int j = 0; j < myCourse.size(); ++j) {
            if (myCourse[j].getCourseCode()== serviceCourse[i][0]) {
            courseIndex=j;
            break;
            }
        }

        int dayIndex = getNumberOfDay(serviceCourse[i][1]);
        bool isElective = myCourse[courseIndex].getCompulsoryOrElective() == "E" ? true : false;

        if( serviceCourse[i][2] == "Afternoon" )
        {
            if ( isElective )
            {
                if(schedule[dayIndex].afternoon.smallClassroom1 == false){
                schedule[dayIndex].afternoon.smallClassroom1 = true;
                myCourse[courseIndex].isAssigned = true;
                schedule[dayIndex].afternoon.smallClassroom1Course = myCourse[courseIndex];

                }
                else if(schedule[dayIndex].afternoon.smallClassroom2 == false){
                schedule[dayIndex].afternoon.smallClassroom2= true;
                myCourse[courseIndex].isAssigned = true;
                schedule[dayIndex].afternoon.smallClassroom2Course = myCourse[courseIndex];
                }
                else if(schedule[dayIndex].afternoon.bigClassroom1 == false){
                schedule[dayIndex].afternoon.bigClassroom1 = true;
                myCourse[courseIndex].isAssigned = true;
                schedule[dayIndex].afternoon.bigClassroom1Course = myCourse[courseIndex];
                }
                else if(schedule[dayIndex].afternoon.bigClassroom2 == false){
                schedule[dayIndex].afternoon.bigClassroom2 = true;
                myCourse[courseIndex].isAssigned = true;
                schedule[dayIndex].afternoon.bigClassroom2Course = myCourse[courseIndex];
                }

            }
            else { //compulsory
                if(schedule[dayIndex].afternoon.bigClassroom1 == false){
                schedule[dayIndex].afternoon.bigClassroom1 = true;
                myCourse[courseIndex].isAssigned = true;
                schedule[dayIndex].afternoon.bigClassroom1Course = myCourse[courseIndex];
                }
                else if(schedule[dayIndex].afternoon.bigClassroom2 == false){
                schedule[dayIndex].afternoon.bigClassroom2 = true;
                myCourse[courseIndex].isAssigned = true;
                schedule[dayIndex].afternoon.bigClassroom2Course = myCourse[courseIndex];
                }
            }
        }
        else if(serviceCourse[i][2] == "Morning")
        {
            if ( isElective )
            {
                if(schedule[dayIndex].morning.smallClassroom1 == false){
                schedule[dayIndex].morning.smallClassroom1 = true;
                myCourse[courseIndex].isAssigned = true;
                schedule[dayIndex].morning.smallClassroom1Course = myCourse[courseIndex];
                }
                else if(schedule[dayIndex].morning.smallClassroom2 == false){
                schedule[dayIndex].morning.smallClassroom2= true;
                myCourse[courseIndex].isAssigned = true;
                schedule[dayIndex].morning.smallClassroom2Course = myCourse[courseIndex];
                }
                else if(schedule[dayIndex].morning.bigClassroom1 == false){
                schedule[dayIndex].morning.bigClassroom1 = true;
                myCourse[courseIndex].isAssigned = true;
                schedule[dayIndex].morning.bigClassroom1Course = myCourse[courseIndex];
                }
                else if(schedule[dayIndex].morning.bigClassroom2 == false){
                schedule[dayIndex].morning.bigClassroom2 = true;
                myCourse[courseIndex].isAssigned = true;
                schedule[dayIndex].morning.bigClassroom2Course = myCourse[courseIndex];
                }

            }
            else { //Compulsory
                if(schedule[dayIndex].morning.bigClassroom1 == false){
                schedule[dayIndex].morning.bigClassroom1 = true;
                myCourse[courseIndex].isAssigned = true;
                schedule[dayIndex].morning.bigClassroom1Course = myCourse[courseIndex];
                }
                else if(schedule[dayIndex].morning.bigClassroom2 == false){
                schedule[dayIndex].morning.bigClassroom2 = true;
                myCourse[courseIndex].isAssigned = true;
                schedule[dayIndex].morning.bigClassroom2Course = myCourse[courseIndex];
                }
            }

        }
    }



}

bool isSameTimeSlotMorningForClass(day& dayValue, course& courseValue)
{
    bool returnedValue = false;

    if ( dayValue.morning.bigClassroom1 == true &&
         dayValue.morning.bigClassroom1Course.getSemesterYear() == courseValue.getSemesterYear() )
        returnedValue = true;

    if ( dayValue.morning.bigClassroom2 == true &&
         dayValue.morning.bigClassroom2Course.getSemesterYear() == courseValue.getSemesterYear() )
        returnedValue = true;

    if ( dayValue.morning.smallClassroom1 == true &&
         dayValue.morning.smallClassroom1Course.getSemesterYear() == courseValue.getSemesterYear() )
        returnedValue = true;

    if ( dayValue.morning.smallClassroom2 == true &&
         dayValue.morning.smallClassroom2Course.getSemesterYear() == courseValue.getSemesterYear() )
        returnedValue = true;

    return returnedValue;

}

bool isSameTimeSlotAfternoonForClass(day& dayValue, course& courseValue)
{
    bool returnedValue = false;

    if ( dayValue.afternoon.bigClassroom1 == true &&
         dayValue.afternoon.bigClassroom1Course.getSemesterYear() == courseValue.getSemesterYear() )
        returnedValue = true;

    if ( dayValue.afternoon.bigClassroom2 == true &&
         dayValue.afternoon.bigClassroom2Course.getSemesterYear() == courseValue.getSemesterYear() )
        returnedValue = true;

    if ( dayValue.afternoon.smallClassroom1 == true &&
         dayValue.afternoon.smallClassroom1Course.getSemesterYear() == courseValue.getSemesterYear() )
        returnedValue = true;

    if ( dayValue.afternoon.smallClassroom2 == true &&
         dayValue.afternoon.smallClassroom2Course.getSemesterYear() == courseValue.getSemesterYear() )
        returnedValue = true;

    return returnedValue;
}

bool isBusyOrNotCourseMorning(course& courseValue, int dayIndex, QVector<QVector<QString>>& busyTimeSlot)
{
    bool returnedValue = false;
    for ( int i = 0; i < busyTimeSlot.size() ; ++i )
    {
        int busyTimeSlotDayIndex = getNumberOfDay(busyTimeSlot[i][1]);
        if ( courseValue.getCourseCode() == busyTimeSlot[i][0] && dayIndex == busyTimeSlotDayIndex &&
               busyTimeSlot[i][2] == "Morning" )
        {
            returnedValue = true;
            break;
        }
    }

    return returnedValue;

}

bool isBusyOrNotCourseAfternoon(course& courseValue, int dayIndex, QVector<QVector<QString>>& busyTimeSlot)
{
    bool returnedValue = false;
    for ( int i = 0; i < busyTimeSlot.size() ; ++i )
    {
        int busyTimeSlotDayIndex = getNumberOfDay(busyTimeSlot[i][1]);
        if ( courseValue.getCourseCode() == busyTimeSlot[i][0] && dayIndex == busyTimeSlotDayIndex &&
               busyTimeSlot[i][2] == "Afternoon" )
        {
            returnedValue = true;
            break;
        }
    }

    return returnedValue;
}

void fillVectorOfCourse(QVector<course>& newMyCourse){
      readCsvFile readcsv;
      QString fileName="C:/Users/Hatice Seyma Yigit/Documents/CoursePlanner/courses.csv";
      readcsv.splitToString(fileName);
      int z=0;
      for (int k=0; k<readcsv.splitToString(fileName).size(); k++) {
          course newCourse(readcsv.splitToString(fileName)[k][z], readcsv.splitToString(fileName)[k][z+1],
                 readcsv.splitToString(fileName)[k][z+2], readcsv.splitToString(fileName)[k][z+3],
                  readcsv.splitToString(fileName)[k][z+4], readcsv.splitToString(fileName)[k][z+5],
                  readcsv.splitToString(fileName)[k][z+6]);

          newMyCourse.push_back(newCourse);
      }

}

