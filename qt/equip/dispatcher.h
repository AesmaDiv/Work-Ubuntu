#ifndef DISPATCHER_H
#define DISPATCHER_H

#include <QObject>

class Dispatcher : public QObject
{
    Q_OBJECT
public:
    explicit Dispatcher(QObject *parent = nullptr);

signals:

public slots:
};

#endif // DISPATCHER_H