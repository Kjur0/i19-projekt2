#include <iostream>
#include <cmath>

using namespace std;

void zad1() {
	// tworzy zmienn¹ wskaŸnikow¹ typu int o nazwie wsk
	int* wsk;

	// rezerwuje jej miejsce w pamiêci
	wsk = new int;

	// wprowadza wartoœæ do komórki wskazywanej przez zmienn¹ wsk
	cout << "Podaj wartosc: ";
	cin >> *wsk;

	// wyœwietla wartoœæ zmiennej wsk
	cout << "Wartosc zmiennej wsk: " << wsk << endl;

	// wyœwietla zawartoœæ komórki wskazywanej przez zmienn¹ wsk (poprzez dereferencjê)
	cout << "Zawartosc komorki wskazywanej przez wsk: " << *wsk << endl;

	// usuwa obiekt, na który wskazuje zmienna wsk
	delete wsk;

	// przypisuje do zmiennej wsk wartoœæ 0 lub nullptr
	wsk = nullptr;
}

void zad2() {
	// utwórz 3 zmienne wskaŸnikowe wsk_x wsk_y, wsk_z
	int* wsk_x;
	int* wsk_y;
	int* wsk_z;

	// zaalokuj pamiêæ dla 3 liczb typu int
	wsk_x = new int;
	wsk_y = new int;
	wsk_z = new int;

	// wprowadŸ wartoœci do komórek wskazywanych przez wskaŸniki
	cout << "Podaj wartosc dla wsk_x: ";
	cin >> *wsk_x;
	cout << "Podaj wartosc dla wsk_y: ";
	cin >> *wsk_y;
	cout << "Podaj wartosc dla wsk_z: ";
	cin >> *wsk_z;

	// posortuj wskaŸniki w kolejnoœci rosn¹cej, u¿ywaj¹c funkcji swap
	if (*wsk_x > *wsk_y)
		swap(wsk_x, wsk_y);
	if (*wsk_y > *wsk_z)
		swap(wsk_y, wsk_z);
	if (*wsk_x > *wsk_y)
		swap(wsk_x, wsk_y);

	// wyœwietl wartoœci wskazywane przez posortowane wskaŸniki
	cout << "Posortowane wartosci: " << *wsk_x << ", " << *wsk_y << ", " << *wsk_z << endl;

	// zwolnij pamiêæ zajmowan¹ przez liczby
	delete wsk_x;
	delete wsk_y;
	delete wsk_z;
}

// struktura trojkat
struct trojkat {
	int a, b, c; // parametry bokow
};

// funkcja, ktora sprawdza, czy mozna utworzyc trojkat z podanych bokow
bool warunek_trojkata(int a, int b, int c) {
	return (a + b > c) && (a + c > b) && (b + c > a);
}

// funkcja, ktora oblicza obwod trojkata
int obwod_trojkata(int a, int b, int c) {
	return a + b + c;
}

// funkcja, ktora oblicza pole trojkata ze wzoru Herona
double pole_trojkata(int a, int b, int c) {
	double p = (a + b + c) / 2.0; // polowa obwodu
	return sqrt(p * (p - a) * (p - b) * (p - c)); // wzor Herona
}

void zad3() {
	// utworzenie zmiennej wskaznikowej typu trojkat
	trojkat* t = new trojkat;

	// pobranie dlugosci bokow od uzytkownika
	cout << "Podaj dlugosc boku a: ";
	cin >> t->a;
	cout << "Podaj dlugosc boku b: ";
	cin >> t->b;
	cout << "Podaj dlugosc boku c: ";
	cin >> t->c;

	// sprawdzenie warunku trojkata
	if (warunek_trojkata(t->a, t->b, t->c)) {
		// obliczenie i wypisanie obwodu i pola
		cout << "Obwod trojkata wynosi: " << obwod_trojkata(t->a, t->b, t->c) << endl;
		cout << "Pole trojkata wynosi: " << pole_trojkata(t->a, t->b, t->c) << endl;
	} else {
		// komunikat o bledzie
		cout << "Z podanych bokow nie mozna utworzyc trojkata." << endl;
	}

	// zwolnienie pamieci
	delete t;
}

// struktura element, ktora reprezentuje pojedynczy element stosu
struct element {
	int wartosc; // wartosc przechowywana w elemencie
	element* nastepny; // wskaznik na nastepny element stosu
};

// struktura stos, ktora reprezentuje caly stos
struct stos {
	element* top; // wskaznik na szczyt stosu
	int rozmiar; // liczba elementow na stosie
};

// funkcja, ktora tworzy nowy stos i zwraca wskaznik na niego
stos* nowy_stos() {
	stos* s = new stos; // alokacja pamieci dla stosu
	s->top = NULL; // ustawienie szczytu na NULL
	s->rozmiar = 0; // ustawienie rozmiaru na 0
	return s; // zwrocenie wskaznika na stos
}

// funkcja, ktora sprawdza, czy stos jest pusty
bool czy_pusty(stos* s) {
	return s->top == NULL; // stos jest pusty, gdy szczyt jest NULL
}

// funkcja, ktora dodaje nowy element na szczyt stosu
void push(stos* s, int x) {
	element* e = new element; // alokacja pamieci dla elementu
	e->wartosc = x; // przypisanie wartosci do elementu
	e->nastepny = s->top; // ustawienie nastepnego elementu na aktualny szczyt stosu
	s->top = e; // ustawienie szczytu stosu na nowy element
	s->rozmiar++; // zwiekszenie rozmiaru stosu o 1
}

// funkcja, ktora zdejmuje element ze szczytu stosu i zwraca jego wartosc
int pop(stos* s) {
	if (czy_pusty(s)) { // sprawdzenie, czy stos jest pusty
		cout << "Stos jest pusty." << endl; // wypisanie komunikatu o bledzie
		return -1; // zwrocenie wartosci bledu
	} else {
		element* e = s->top; // zapamietanie elementu ze szczytu stosu
		int x = e->wartosc; // zapamietanie wartosci elementu
		s->top = e->nastepny; // ustawienie szczytu stosu na nastepny element
		delete e; // zwolnienie pamieci dla elementu
		s->rozmiar--; // zmniejszenie rozmiaru stosu o 1
		return x; // zwrocenie wartosci elementu
	}
}

// funkcja, ktora zwraca wartosc elementu ze szczytu stosu bez zdejmowania go
int peek(stos* s) {
	if (czy_pusty(s)) { // sprawdzenie, czy stos jest pusty
		cout << "Stos jest pusty." << endl; // wypisanie komunikatu o bledzie
		return -1; // zwrocenie wartosci bledu
	} else {
		return s->top->wartosc; // zwrocenie wartosci elementu ze szczytu stosu
	}
}

// funkcja, ktora zwraca rozmiar stosu
int rozmiar(stos* s) {
	return s->rozmiar; // zwrocenie liczby elementow na stosie
}

// funkcja, ktora wyswietla zawartosc stosu od szczytu do dna
void wyswietl(stos* s) {
	element* e = s->top; // ustawienie wskaznika na szczyt stosu
	cout << "Stos: ";
	while (e != NULL) { // dopoki wskaznik nie jest NULL
		cout << e->wartosc << " "; // wypisanie wartosci elementu
		e = e->nastepny; // przejscie do nastepnego elementu
	}
	cout << endl;
}

void zad4() {
	// utworzenie nowego stosu
	stos* s = nowy_stos();

	// dodanie kilku elementow na stos
	push(s, 10);
	push(s, 20);
	push(s, 30);

	// wyswietlenie zawartosci i rozmiaru stosu
	wyswietl(s);
	cout << "Rozmiar stosu: " << rozmiar(s) << endl;

	// zdejmowanie elementow ze stosu
	cout << "Zdejmuje: " << pop(s) << endl;
	cout << "Zdejmuje: " << pop(s) << endl;

	// wyswietlenie zawartosci i rozmiaru stosu
	wyswietl(s);
	cout << "Rozmiar stosu: " << rozmiar(s) << endl;

	// sprawdzenie wartosci na szczycie stosu
	cout << "Wartosc na szczycie: " << peek(s) << endl;

	// zwolnienie pamieci
	delete s;
}

int main() {
	cout << "Wprowadz nr zadania(1-4): ";
	int zad;
	cin >> zad;

	switch (zad) {
		case 1:
			zad1();
			break;
		case 2:
			zad2();
			break;
		case 3:
			zad3();
			break;
		case 4:
			zad4();
			break;
		default:
			cout << "Nie ma takiego zadania" << endl;
			break;
	}

	for (int i = 15; i > 0; i--)
		cout << endl;

	cout << "Aby zakonczyc wciœnij dowolny klawisz...";
	system("pause>nul");

	return 0;
}