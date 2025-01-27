#include "Bankomat.hpp"
#include <iostream>
#include <algorithm>

Bankomat::Bankomat(const std::vector<std::string>& akceptowaneKarty)
    : akceptowaneKarty_(akceptowaneKarty), aktualnaKarta_(nullptr), kartaWlozona_(false), pinZweryfikowany_(false) {}

bool Bankomat::wlozKarte(const Karta& karta) {
    if (std::find(akceptowaneKarty_.begin(), akceptowaneKarty_.end(), karta.pobierzTypKarty()) != akceptowaneKarty_.end()) {
        aktualnaKarta_ = const_cast<Karta*>(&karta);
        kartaWlozona_ = true;
        return true;
    } else {
        std::cout << "Typ karty nie jest akceptowany.\n";
        return false;
    }
}

bool Bankomat::wprowadzPin(const std::string& pin) {
    if (kartaWlozona_ && aktualnaKarta_->sprawdzPin(pin)) {
        pinZweryfikowany_ = true;
        return true;
    } else {
        return false;
    }
}

void Bankomat::sprawdzSaldo() {
    if (kartaWlozona_ && pinZweryfikowany_) {
        std::cout << "Twoje saldo wynosi: " << aktualnaKarta_->pobierzSaldo() << " zl.\n";
    } else {
        std::cout << "Blad: Autoryzacja PIN wymagana.\n";
    }
}

void Bankomat::wplacPieniadze(double kwota) {
    if (kartaWlozona_ && pinZweryfikowany_) {
        aktualnaKarta_->wplacPieniadze(kwota);
    } else {
        std::cout << "Blad: Autoryzacja PIN wymagana.\n";
    }
}

bool Bankomat::wyplacPieniadze(int kwota) {
    if (kartaWlozona_ && pinZweryfikowany_ && aktualnaKarta_->wyplacPieniadze(kwota)) {
        return true;
    } else {
        return false;
    }
}

bool Bankomat::wyplataBLIK(int kodBLIK, int kwota) {
    if (kartaWlozona_) {
        if (aktualnaKarta_->wyplacPieniadze(kwota)) {
            return true;
        } else {
            return false;
        }
    } else {
        return false;
    }
}
