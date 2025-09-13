#include <iostream>
#include <string>

//product

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

//creator
class NotificationCreator {
    public:
        virtual Notification* createNotification() = 0;
        virtual ~NotificationCreator() = default;
        void sendNotification(const std::string& msg){
            Notification* notification = createNotification();
            if(notification){
                notification->notify(msg);
            }
        }
};

class SMSNotificationCreator : public NotificationCreator {
    public:
        Notification* createNotification() override {
            return new SMSNotification();
        }
};

class EmailNotificationCreator : public NotificationCreator {
    public:
        Notification* createNotification() override {
            return new EmailNotification();
        }
};

class WhatsAppNotificationCreator : public NotificationCreator {
    public:
        Notification* createNotification() override {
            return new whatsappNotification();
        }
};

int main() {
    
    NotificationCreator* creator = new SMSNotificationCreator();
    creator->sendNotification("Hello via SMS!");
    delete creator;

    creator = new EmailNotificationCreator();
    creator->sendNotification("Hello via Email!");
    delete creator;

    creator = new WhatsAppNotificationCreator();
    creator->sendNotification("Hello via WhatsApp!");
    delete creator;

    return 0;
}