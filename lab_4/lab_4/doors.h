#ifndef DOOR_H
#define DOOR_H

#include <QObject>
#include <QDebug>
#include <QTimer>

#define DOORS_TIME   500

class Doors : public QObject
{
    Q_OBJECT;

    enum DoorsState
    {
        CLOSED,
        OPENING,
        OPENED,
        CLOSING
    };

public:
    Doors();
    ~Doors() = default;

public slots:
    void opening();
    void opened();
    void closed();
    void closing();

signals:
    void closedSignal();

private:
    DoorsState _state;
    QTimer _opening_timer;
    QTimer _closing_timer;
    QTimer _opened_timer;
};

#endif
