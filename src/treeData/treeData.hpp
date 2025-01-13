/**
 * @authors Mateusz Basiaga (basmateusz@wp.pl), Kamil Gruca
 * @brief
 * @date 2025-01-13
 *
 * @copyright Copyright (c) 2025
 *
 */
#ifndef TREEDATA_H
#define TREEDATA_H

#include <map>
#include <string>
#include <vector>

#include "../lineParser/lineData.hpp"

 /// \class TreeData
 /// \brief Klasa obs�uguj�ca hierarchiczn� struktur� danych z pliku CSV.
class TreeData {
public:
    /// \struct QuarterNode
    /// \brief Reprezentuje dane z podzia�em na kwarta�y dnia.
    struct QuarterNode {
        int quarter; ///< Numer kwarta�u (0-3).
        int hour; ///< Godzina rozpocz�cia kwarta�u.
        int minute; ///< Minuta rozpocz�cia kwarta�u.
        std::vector<LineData> data; ///< Dane przypisane do kwarta�u.
    };

    /// \struct DayNode
    /// \brief Reprezentuje dane dzienne.
    struct DayNode {
        int day; ///< Dzie� miesi�ca.
        std::map<int, QuarterNode> quarters; ///< Mapa kwartalnych danych w dniu.
    };

    /// \struct MonthNode
    /// \brief Reprezentuje dane miesi�czne.
    struct MonthNode {
        int month; ///< Numer miesi�ca.
        std::map<int, DayNode> days; ///< Mapa dziennych danych w miesi�cu.
    };

    /// \struct YearNode
    /// \brief Reprezentuje dane roczne.
    struct YearNode {
        int year; ///< Rok.
        std::map<int, MonthNode> months; ///< Mapa miesi�cznych danych w roku.
    };

    /// \brief Dodaje dane do struktury drzewa.
    /// \param lineData Obiekt LineData reprezentuj�cy wiersz danych.
    void addData(const LineData& lineData);

    /// \brief Wy�wietla ca�� struktur� drzewa.
    void print() const;

    /// \brief Pobiera dane w podanym przedziale czasowym.
    /// \param startDate Data pocz�tkowa w formacie dd.mm.yyyy hh:mm.
    /// \param endDate Data ko�cowa w formacie dd.mm.yyyy hh:mm.
    /// \return Wektor obiekt�w LineData w podanym zakresie czasowym.
    std::vector<LineData> getDataBetweenDates(const std::string& startDate, const std::string& endDate) const;

    /// \brief Oblicza sumy danych w podanym przedziale czasowym.
    /// \param startDate Data pocz�tkowa w formacie dd.mm.yyyy hh:mm.
    /// \param endDate Data ko�cowa w formacie dd.mm.yyyy hh:mm.
    /// \param[out] autokonsumpcjaSum Suma autokonsumpcji.
    /// \param[out] eksportSum Suma eksportu.
    /// \param[out] importSum Suma importu.
    /// \param[out] poborSum Suma poboru.
    /// \param[out] produkcjaSum Suma produkcji.
    void calculateSumsBetweenDates(const std::string& startDate, const std::string& endDate, float& autokonsumpcjaSum, float& eksportSum, float& importSum, float& poborSum, float& produkcjaSum) const;

    /// \brief Oblicza �rednie dane w podanym przedziale czasowym.
    /// \param startDate Data pocz�tkowa w formacie dd.mm.yyyy hh:mm.
    /// \param endDate Data ko�cowa w formacie dd.mm.yyyy hh:mm.
    /// \param[out] autokonsumpcjaAvg �rednia autokonsumpcji.
    /// \param[out] eksportAvg �rednia eksportu.
    /// \param[out] importAvg �rednia importu.
    /// \param[out] poborAvg �rednia poboru.
    /// \param[out] produkcjaAvg �rednia produkcji.
    void calculateAveragesBetweenDates(const std::string& startDate, const std::string& endDate, float& autokonsumpcjaAvg, float& eksportAvg, float& importAvg, float& poborAvg, float& produkcjaAvg) const;

    /// \brief Por�wnuje dane mi�dzy dwoma zakresami czasowymi.
    /// \param startDate1 Data pocz�tkowa pierwszego zakresu.
    /// \param endDate1 Data ko�cowa pierwszego zakresu.
    /// \param startDate2 Data pocz�tkowa drugiego zakresu.
    /// \param endDate2 Data ko�cowa drugiego zakresu.
    /// \param[out] autokonsumpcjaDiff R�nica autokonsumpcji.
    /// \param[out] eksportDiff R�nica eksportu.
    /// \param[out] importDiff R�nica importu.
    /// \param[out] poborDiff R�nica poboru.
    /// \param[out] produkcjaDiff R�nica produkcji.
    void compareDataBetweenDates(const std::string& startDate1, const std::string& endDate1, const std::string& startDate2, const std::string& endDate2, float& autokonsumpcjaDiff, float& eksportDiff, float& importDiff, float& poborDiff, float& produkcjaDiff) const;

    void serialize(std::ofstream& out) const;

    /// \brief Wyszukuje rekordy w podanym zakresie czasowym z uwzgl�dnieniem tolerancji.
    /// \param startDate Data pocz�tkowa w formacie dd.mm.yyyy hh:mm.
    /// \param endDate Data ko�cowa w formacie dd.mm.yyyy hh:mm.
    /// \param value Warto�� wyszukiwana.
    /// \param tolerance Tolerancja dla warto�ci.
    /// \return Wektor obiekt�w LineData spe�niaj�cych kryteria wyszukiwania.
    std::vector<LineData> searchRecordsWithTolerance(const std::string& startDate, const std::string& endDate, float value, float tolerance) const;

private:
    std::map<int, YearNode> years; ///< Mapa lat zawieraj�cych dane w hierarchii.
};

#endif // TREEDATA_H
