<<<<<<< HEAD
# Gestionarea Datelor unui Magazin

## Student

**Nume:** Lupulescu Maria-Alexandra  
**Grupa:** 322AB

## Mediu de dezvoltare

- **Sistem de operare:** Windows
- **IDE utilizat:** Code::Blocks

---

# Descrierea temei

Proiectul implementează un sistem simplu de gestionare a datelor unui magazin folosind concepte de **Programare Orientată pe Obiecte (OOP)** în C++. Programul citește informații despre produse și comenzi din fișiere text, procesează comenzile clienților și generează fișiere de output cu detalii despre comenzile efectuate și stocul rămas.

Pentru implementare au fost utilizate trei clase principale:

## Clasa `Produs`

Clasa `Produs` modelează un produs din magazin și conține atribute precum:

- denumirea produsului
- prețul
- cantitatea disponibilă în stoc

Funcționalități implementate:

- funcții **getter și setter** pentru accesul și modificarea atributelor private
- suprascrierea operatorilor **`>>` și `<<`** pentru citirea și afișarea obiectelor de tip `Produs`
- funcția **`creare_stoc`**, care citește din fișierul `produse.txt` numărul de produse și creează un vector ce reprezintă stocul inițial
- funcția **`afisare_stoc`**, care afișează stocul curent al produselor

---

## Clasa `Comanda`

Clasa `Comanda` gestionează produsele comandate de un client.

Funcționalități implementate:

- funcții **getter și setter**
- suprascrierea operatorilor **`>>` și `<<`** pentru citirea și afișarea comenzilor
- funcția **`eliminare`**, care este apelată în momentul procesării unei comenzi

Această funcție:

- caută produsul comandat în vectorul de stoc
- decrementează cantitatea produsului din stoc
- setează prețul produsului pentru calcularea costului comenzii

---

## Clasa `Client`

Clasa `Client` gestionează informațiile despre clienți și comenzile acestora.

Funcționalități implementate:

- funcția **`modificare`**, care:
  - citește datele din fișierul `clienti.txt`
  - procesează comenzile fiecărui client
  - apelează funcția `eliminare` pentru actualizarea stocului
  - scrie rezultatele în fișierul **`output_comenzi.txt`**

---

# Explicația funcției `main`

În funcția `main` sunt apelate funcțiile principale ale programului în ordinea necesară funcționării aplicației:

1. Se apelează funcția **`creare_stoc`** pentru a citi datele din fișierul `produse.txt` și pentru a inițializa vectorul de produse din stoc.
2. Se apelează funcția **`modificare`**, care citește comenzile din `clienti.txt`, procesează comenzile clienților și actualizează stocul produselor.
3. În timpul procesării comenzilor se generează fișierul **`output_comenzi.txt`**, care conține detaliile fiecărei comenzi.
4. La final, se afișează stocul actualizat în fișierul **`output_stoc_ramas.txt`**.

Astfel, programul parcurge toate comenzile, actualizează stocul produselor și generează fișierele de output cerute.

---

# Fișiere de input

- `produse.txt` – conține produsele din magazin și stocul inițial
- `clienti.txt` – conține informații despre clienți și comenzile acestora

# Fișiere de output

- `output_comenzi.txt` – detalii despre comenzile fiecărui client
- `output_stoc_ramas.txt` – stocul rămas după procesarea comenzilor
=======
# gestionare_magazin
Proiect C++ pentru gestionarea datelor unui magazin
>>>>>>> ca65489e16b780709592cc3c4df7fad26bd8582b
