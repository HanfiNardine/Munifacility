#ifndef MAILING_H
#define MAILING_H

#include <QDeclarativeItem>
#include <QMainWindow>
#include <QObject>
#include <QQuickItem>
#include <QSharedDataPointer>
#include <QWidget>

class mailingData;

class mailing
{
    Q_OBJECT
public:
    mailing();
    mailing(const mailing &);
    mailing &operator=(const mailing &);
    ~mailing();

private:
    QSharedDataPointer<mailingData> data;
};

#endif // MAILING_H
