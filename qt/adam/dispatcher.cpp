#include "dispatcher.h"

bool Dispatcher::setProperty(const char* object_name, const char* property_name, const QVariant &value) {
    QObject* obj = this->parent()->findChild<QObject*>(object_name);
    if (obj == nullptr) {
        return false;
    }
    obj->setProperty(property_name, value);
    return true;
}
bool Dispatcher::getProperty(const char* object_name, const char* property_name, QVariant &value) {
    QObject* obj = this->parent()->findChild<QObject*>(object_name);
    if (obj == nullptr) {
        return false;
    }
    value = obj->property(property_name);
    return true;
}
void Dispatcher::eventSlot(const QString &message) {
    this->eventSignal(message);
}
