#include "Bankomat.hpp"
#include "Karta.hpp"
#include <iostream>

int main() {
    Bankomat bankomat({"Visa", "American Express", "Mastercard"});
    Karta mojaKarta("1234567890123456", "Visa", "1234", 1500.00);

    std::cout << "Witaj w aplikacji bankowej 'JKubaczynski Bank'\n";
    if (!bankomat.wlozKarte(mojaKarta)) {
        std::cout << "Karta nieakceptowana.\n\n";
        return 0;
    }

    std::cout << "Karta zaakceptowana.\n\n";

    int wybor;
    std::string pin;
    double kwota;
    std::string kodBLIK;
    bool pinZweryfikowany = false;

    do {
        std::cout << "Wybierz opcje:\n";
        if (!pinZweryfikowany) {
            std::cout << "1. Wprowadz PIN\n";
            std::cout << "5. Wyplata BLIK\n";
            std::cout << "6. Zakoncz\n\n";
        } else {
            std::cout << "2. Sprawdz saldo\n";
            std::cout << "3. Wplac pieniadze\n";
            std::cout << "4. Wyplac pieniadze\n";
            std::cout << "5. Wyplata BLIK\n";
            std::cout << "6. Zakoncz\n\n";
        }

        std::cin >> wybor;

        switch (wybor) {
            case 1:
                std::cout << "Podaj PIN: ";
                std::cin >> pin;
                if (bankomat.wprowadzPin(pin)) {
                    std::cout << "PIN poprawny. Mozesz teraz wykonac operacje na koncie.\n\n";
                    pinZweryfikowany = true;
                } else {
                    std::cout << "Bledny PIN.\n\n";
                }
                break;
            case 2:
                if (pinZweryfikowany) {
                    bankomat.sprawdzSaldo();
                    std::cout << "\n";
                } else {
                    std::cout << "Blad: Autoryzacja PIN wymagana.\n\n";
                }
                break;
            case 3:
                if (pinZweryfikowany) {
                    std::cout << "Podaj kwote do wplaty: ";
                    std::cin >> kwota;
                    bankomat.wplacPieniadze(kwota);
                    std::cout << "Wplacono " << kwota << " zl.\n\n";
                } else {
                    std::cout << "Blad: Autoryzacja PIN wymagana.\n\n";
                }
                break;
            case 4:
                if (pinZweryfikowany) {
                    std::cout << "Podaj kwote do wyplaty: ";
                    std::cin >> kwota;
                    if (bankomat.wyplacPieniadze(static_cast<int>(kwota))) {
                        std::cout << "Wyplacono " << kwota << " zl.\n\n";
                    } else {
                        std::cout << "Operacja nieudana.\n\n";
                    }
                } else {
                    std::cout << "Blad: Autoryzacja PIN wymagana.\n\n";
                }
                break;
            case 5:
                std::cout << "Podaj kod BLIK: ";
                std::cin >> kodBLIK;
                if (kodBLIK.length() == 6) {
                    std::cout << "Podaj kwote: ";
                    std::cin >> kwota;
                    if (bankomat.wyplataBLIK(std::stoi(kodBLIK), static_cast<int>(kwota))) {
                        std::cout << "Wyplata BLIK na kwote " << kwota << " zl zrealizowana pomyslnie.\n\n";
                    } else {
                        std::cout << "Operacja BLIK nieudana.\n\n";
                    }
                } else {
                    std::cout << "Nieprawidlowy kod BLIK.\n\n";
                }
                break;
            case 6:
                std::cout << "Dziekujemy za skorzystanie z naszego bankomatu.\n";
                return 0;
        }
    } while (true);

    return 0;
}
