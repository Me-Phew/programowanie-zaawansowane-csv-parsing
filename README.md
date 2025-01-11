![GitHub Workflow Status](https://img.shields.io/github/actions/workflow/status/Me-Phew/programowanie-zaawansowane-template/ci.yaml?logo=bilibili&style=for-the-badge) ![GitHub deployments](https://img.shields.io/github/deployments/Me-Phew/programowanie-zaawansowane-template/github-pages?label=Doxygen%20Documentaion&logo=bilibili&style=for-the-badge) ![GitHub last commit](https://img.shields.io/github/last-commit/Me-Phew/programowanie-zaawansowane-template?color=8bd5ca&logo=starship&style=for-the-badge) ![GitHub repo size](https://img.shields.io/github/repo-size/Me-Phew/programowanie-zaawansowane-template?logo=github&style=for-the-badge)

# Programowanie zaawansowane - szablon

## Spis treści

- 🚀 [Użycie](#usage)
- 🧩 [Funkcjonalność](#features)
- ⚖️ [Licencja](#license)

### <a name="usage">🚀 Użycie</a>

Użyj polecenia `npm i`, aby umożliwić działanie Git Hooks

- Wyszukaj wszystkie wystąpienia poniższych tekstów i zamień je na właściwe dla swojego projektu.
  - Nazwa projektu
    - `ProjectName`
    - `Project Name`
  - Autor
    - `AuthorName`
  - Ścieżka do repozytorium (w linku GitHub)
    - `Me-Phew/programowanie-zaawansowane-template`

### <a name="features">🧩 Funkcjonalność</a>

- Generator systemu budowania - [CMake](https://cmake.org/)
  - System budowania - [Ninja](https://ninja-build.org/)
  - Konfiguracja dla [GCC](https://gcc.gnu.org/) z [MSYS2](https://www.msys2.org/) (MinGW64 / UCRT64)
  - Kompilacja dla systemu Linux ([GCC](https://gcc.gnu.org/))
  - Kompilacja dla systemu Windows ([MINGW-w64](https://www.mingw-w64.org/))
- Dokumentacja
  - Szablon LaTeX - dostosowany przez mgr inż. Dawid Kotlarski
  - Automatyczna - narzędzie [Doxygen](https://www.doxygen.nl/)
    - Konfiguracja motywu strony - [Doxygen Awesome](https://github.com/jothepro/doxygen-awesome-css)
    - Kolory motywu inspirowane stroną [Nuxt](https://nuxt.com/)
- Git Hooks - [Lefthook](https://github.com/evilmartians/lefthook)
  - Walidacja zgodności wiadomośći commitów z konwencją [Conventional Commits](https://www.conventionalcommits.org/en/v1.0.0/) przy pomocy narzędzia [Commitlint](https://commitlint.js.org/)
- Continous Integration - [GitHub Actions](https://docs.github.com/en/actions)
  - Walidacja zgodności wiadomośći commitów z konwencją [Conventional Commits](https://www.conventionalcommits.org/en/v1.0.0/) przy pomocy narzędzia [Commitlint](https://commitlint.js.org/)
  - Generowanie strony dokumentacji automatycznej ([GitHub Pages](https://pages.github.com/))
  - Tworzenie tagów wersji
  - Tworzenie wydań zawierających:
    - Wygenerowane pliki wykonywalne dla platform:
      - Windows
      - Linux
    - Pliki dokumentacji:
      - Automatyczna ([Doxygen](https://www.doxygen.nl/))
      - LaTeX - szablon dostosowany przez mgr inż. Dawid Kotlarski

### <a name="license">⚖️ Licencja</a>

[GNU GENERAL PUBLIC LICENSE v.3.0](./LICENSE)
