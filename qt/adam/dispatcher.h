#ifndef DISPATCHER_H
#define DISPATCHER_H

#include <QObject>
#include <QVariant>

class Dispatcher : public QObject
{
    Q_OBJECT
public:
    explicit Dispatcher(QObject *parent = nullptr) : QObject(parent) {}

    bool setProperty(const char* object_name, const char* property_name, const QVariant &value);
    bool getProperty(const char* object_name, const char* property_name, QVariant &value);
signals:
    void eventSignal(const QString &message);
public slots:
    void eventSlot(const QString &message);
};

#endif // DISPATCHER_H
