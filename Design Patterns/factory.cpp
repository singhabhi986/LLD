#include <string>
#include <iostream>

enum class NotificationType {
    SMS,
    Email,
    WhatsApp
};

class Notification {
public:
    virtual ~Notification() = default;
    virtual void notify(const std::string& message) = 0;
};

class SMSNotification : public Notification {
public:
    void notify(const std::string& message) override {
        // Implementation for sending SMS notification
        std::cout << "SMS Notification: " << message << std::endl;
    }
};

class EmailNotification : public Notification {
public:
    void notify(const std::string& message) override {
        // Implementation for sending Email notification
        std::cout << "Email Notification: " << message << std::endl;
    }
};

class whatsappNotification : public Notification {
public:
    void notify(const std::string& message) override {
        // Implementation for sending WhatsApp notification
        std::cout << "WhatsApp Notification: " << message << std::endl;
    }
};

class NotificationFactory {
public:
    static Notification* createNotification(NotificationType type) {
        switch (type) {
            case NotificationType::SMS:
                return new SMSNotification();
            case NotificationType::Email:
                return new EmailNotification();
            case NotificationType::WhatsApp:
                return new whatsappNotification();
            default:
                return nullptr;
        }
    }
};

class NotificationManager {
    public:
        void sendNotification(NotificationType type, const std::string& msg){
            Notification* notification = NotificationFactory::createNotification(type);
            if(notification){
                notification->notify(msg);
                delete notification;
        }   
    }
};