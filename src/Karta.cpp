#include "Karta.hpp"

Karta::Karta(const std::string& numerKarty, const std::string& typKarty, const std::string& pin, double saldo)
    : numerKarty_(numerKarty), typKarty_(typKarty), pin_(pin), saldo_(saldo) {}

bool Karta::sprawdzPin(const std::string& pin) const {
    return pin == pin_;
}

std::string Karta::pobierzTypKarty() const {
    return typKarty_;
}

double Karta::pobierzSaldo() const {
    return saldo_;
}

void Karta::wplacPieniadze(double kwota) {
    saldo_ += kwota;
}

bool Karta::wyplacPieniadze(double kwota) {
    if (saldo_ >= kwota) {
        saldo_ -= kwota;
        return true;
    }
    return false;
}
