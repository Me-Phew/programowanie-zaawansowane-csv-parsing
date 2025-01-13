/**
 * @authors Mateusz Basiaga (basmateusz@wp.pl), Kamil Gruca
 * @brief
 * @date 2025-01-13
 *
 * @copyright Copyright (c) 2025
 *
 */

#ifndef LINEDATA_HPP
#define LINEDATA_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

/// \class LineData
/// \brief Klasa reprezentuj�ca dane jednego wiersza z pliku CSV.
class LineData {
public:
    /// \brief Konstruktor przetwarzaj�cy wiersz danych z formatu CSV.
    /// \param line Wiersz danych wej�ciowych.
    explicit LineData(const string& line);

    /// \brief Konstruktor odczytuj�cy dane z pliku binarnego.
    /// \param in Strumie� wej�ciowy.
    LineData(ifstream& in);

    /// \brief Wypisuje wszystkie dane na standardowe wyj�cie.
    void print() const;

    /// \brief Wypisuje tylko dane liczbowe (bez daty) na standardowe wyj�cie.
    void printData() const;

    /// \brief Zwraca dane jako ci�g znak�w.
    /// \return Dane w formacie tekstowym.
    string printString();

    /// \brief Serializuje obiekt do pliku binarnego.
    /// \param out Strumie� wyj�ciowy.
    void serialize(ofstream& out) const;

    /// \brief Deserializuje obiekt z pliku binarnego.
    /// \param in Strumie� wej�ciowy.
    void deserialize(ifstream& in);

    /// \brief Zwraca dat�.
    /// \return Data w formacie tekstowym.
    string getDate() const { return date; }

    /// \brief Zwraca warto�� autokonsumpcji.
    /// \return Autokonsumpcja jako liczba zmiennoprzecinkowa.
    float getAutokonsumpcja() const { return autokonsumpcja; }

    /// \brief Zwraca warto�� eksportu.
    /// \return Eksport jako liczba zmiennoprzecinkowa.
    float getEksport() const { return eksport; }

    /// \brief Zwraca warto�� importu.
    /// \return Import jako liczba zmiennoprzecinkowa.
    float getImport() const { return import; }

    /// \brief Zwraca warto�� poboru.
    /// \return Pob�r jako liczba zmiennoprzecinkowa.
    float getPobor() const { return pobor; }

    /// \brief Zwraca warto�� produkcji.
    /// \return Produkcja jako liczba zmiennoprzecinkowa.
    float getProdukcja() const { return produkcja; }

private:
    string date; ///< Data wiersza.
    float autokonsumpcja; ///< Autokonsumpcja w W.
    float eksport; ///< Eksport w W.
    float import; ///< Import w W.
    float pobor; ///< Pob�r w W.
    float produkcja; ///< Produkcja w W.
};

#endif /* LINEDATA_HPP */
