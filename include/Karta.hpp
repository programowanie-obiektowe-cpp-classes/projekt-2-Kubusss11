#pragma once
#include <string>

class Karta {
public:
    Karta(const std::string& numerKarty, const std::string& typKarty, const std::string& pin, double saldo);
    bool sprawdzPin(const std::string& pin) const;
    std::string pobierzTypKarty() const;
    double pobierzSaldo() const;
    void wplacPieniadze(double kwota);
    bool wyplacPieniadze(double kwota);

private:
    std::string numerKarty_;
    std::string typKarty_;
    std::string pin_;
    double saldo_;
};
