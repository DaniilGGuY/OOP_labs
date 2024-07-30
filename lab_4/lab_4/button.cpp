#include "button.h"

Button::Button(size_t floor, Direction dir, QWidget *parrent) : QPushButton(parrent), _state(INACTIVE), _floor(floor), _dir(dir)
{
    QObject::connect(this, SIGNAL(clicked()), this, SLOT(pressed()));

    if (_dir == DOWN)
        this->setText(QString::number(_floor) + " V");
    else if (_dir == UP)
        this->setText(QString::number(_floor) + " ^");
    else
        this->setText(QString::number(_floor));
}

void Button::pressed()
{
    if (_state == INACTIVE)
    {
        _state = ACTIVE;
        setDisabled(true);
        setStyleSheet("background-color:green;");
        update();
        emit buttonPressedSignal(_floor, _dir);
    }
}

void Button::unpressed(size_t floor, Direction dir)
{
    if (_state == ACTIVE && _floor == floor && _dir == dir)
    {
        _state = INACTIVE;
        setDisabled(false);
        setStyleSheet("background-color:grey;");
        update();
    }
}
