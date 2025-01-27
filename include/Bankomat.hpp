#pragma once
#include "Karta.hpp"
#include <vector>
#include <string>

class Bankomat {
public:
    Bankomat(const std::vector<std::string>& akceptowaneKarty);
    bool wlozKarte(const Karta& karta);
    bool wprowadzPin(const std::string& pin);
    void sprawdzSaldo();
    void wplacPieniadze(double kwota);
    bool wyplacPieniadze(int kwota);
    bool wyplataBLIK(int kodBLIK, int kwota);

private:
    Karta* aktualnaKarta_;
    std::vector<std::string> akceptowaneKarty_;
    bool kartaWlozona_;
    bool pinZweryfikowany_;
};
