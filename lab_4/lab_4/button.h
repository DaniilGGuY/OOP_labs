#ifndef BUTTON_H
#define BUTTON_H

#include <QObject>
#include <QPushButton>

enum Direction
{
    DOWN = -1,
    STOP = 0,
    UP = 1,
    LIFT = 0
};

class Button : public QPushButton
{
    Q_OBJECT;

    enum ButtonState
    {
        ACTIVE,
        INACTIVE
    };

public:
    Button(size_t floor, Direction dir, QWidget *parent = nullptr);
    ~Button() = default;

public slots:
    void pressed();
    void unpressed(size_t floor, Direction dir);

signals:
    void buttonPressedSignal(size_t floor, Direction dir);

private:
    ButtonState _state;
    size_t _floor;
    Direction _dir;
};

#endif
