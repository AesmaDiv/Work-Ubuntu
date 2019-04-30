#ifndef DISPATCHER_HPP
#define DISPATCHER_HPP

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


inline bool Dispatcher::setProperty(const char* object_name, const char* property_name, const QVariant &value) {
    QObject* obj = this->parent()->findChild<QObject*>(object_name);
    if (obj == nullptr) {
        return false;
    }
    obj->setProperty(property_name, value);
    return true;
}
inline bool Dispatcher::getProperty(const char* object_name, const char* property_name, QVariant &value) {
    QObject* obj = this->parent()->findChild<QObject*>(object_name);
    if (obj == nullptr) {
        return false;
    }
    value = obj->property(property_name);
    return true;
}
inline void Dispatcher::eventSlot_String(const QString &message) {
    this->eventSignal_String(message);
}
inline void Dispatcher::eventSlot_Variant(const QVariant &variant) {
    this->eventSignal_Variant(variant);
}
#endif // DISPATCHER_H
