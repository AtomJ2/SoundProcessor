#include <iostream>
#include <string>

void SendSms(const std::string& number, const std::string& message);
void SendEmail(const std::string& email, const std::string& message);


class INotifier {
public:
    virtual void Notify(const std::string& message) const = 0;
};

class SmsNotifier : public INotifier {
public:
    SmsNotifier(const std::string& phoneNumber) : phoneNumber(phoneNumber) {}

    void Notify(const std::string& message) const override {
        SendSms(phoneNumber, message);
    }

private:
    std::string phoneNumber;
};

class EmailNotifier : public INotifier {
public:
    EmailNotifier(const std::string& emailAddress) : emailAddress(emailAddress) {}

    void Notify(const std::string& message) const override {
        SendEmail(emailAddress, message);
    }

private:
    std::string emailAddress;
};

// Пример использования
int main() {
    std::string phoneNumber = "1234567890";
    std::string emailAddress = "example@example.com";

    SmsNotifier smsNotifier(phoneNumber);
    EmailNotifier emailNotifier(emailAddress);

    smsNotifier.Notify("Hello, SMS!");
    emailNotifier.Notify("Hello, email!");

    return 0;
}
