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
    void eventSignal_String(const QString &message);
    void eventSignal_Variant(const QVariant &variant);
public slots:
    void eventSlot_String(const QString &message);
    void eventSlot_Variant(const QVariant &variant);
};

#endif // DISPATCHER_H
