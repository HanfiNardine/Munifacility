#include "connection.h"
#include<QSqlDatabase>
Connection::Connection()
{

}
bool Connection::TestConnection()
{

    bool test=false;

QSqlDatabase db=QSqlDatabase ::addDatabase("QODBC");
db.setDatabaseName("Source_Projet2A");
db.setUserName("system");
db.setPassword("191jMT1036");
if(db.open())
return true;
return test;

}
