#ifndef ENUMERATOR_HPP
#define ENUMERATOR_HPP

#include <QObject>

class Info : public QObject
{
    Q_OBJECT
public:
    enum State {
        Information,
        Debug,
        Warning,
        Error
    };
    Q_ENUM(State)
};

#endif // ENUMERATOR_HPP
