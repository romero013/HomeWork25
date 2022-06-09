#include <iostream>
#include <string>
using namespace std;

// Задание
struct movies {
	string title;
	int year;
	string genre;
	unsigned int duration;
	unsigned int price;
};
movies TheLionKing = { "Король лев", 1994, "Мультфильм", 88, 123 };
movies TheProposal = { "Предложение", 2009, "Комедия", 108, 234 };
movies WhyHim = { "Почему он?", 2016, "Комедия", 111, 345 };

// Задача 1 (Вывод данных о фильме)
void showMovie(movies& M) {
	cout << "Название фильма: " << M.title << endl;
	cout << "Год выхода: " << M.year << ".\n";
	cout << "Жанр: " << M.genre << ".\n";
	cout << "Продолжительность фильма: " << M.duration << " минут." << endl;
	cout << "Цена за диск: " << M.price << " руб.\n\n";
}

// Задача 2 (Возвращение самого дорогого фильма)
movies expensive(movies& M, movies& M1, movies& M2) {
	if (M.price > M1.price && M.price > M2.price)
		return M;
	else
		if (M1.price > M.price && M1.price > M2.price)
			return M1;
		else
			return M2;
}

// Задача 3 (Изменение данных выбранного фильма)
void updateinfo(movies& M) {
	cout << "Выберите, какую информацию о фильме необходимо обновить:\n";
	cout << "1. Название;\n";
	cout << "2. Год выхода;\n";
	cout << "3. Жанр;\n";
	cout << "4. Продолжительность;\n";
	cout << "5. Цена за диск.\n";
	cout << "Ввод -> ";
	short x;
	cin >> x;
	cin.ignore();
	switch (x) {
	case 1: {
		cout << "Введите новое название фильма:\nВвод -> ";
		getline(cin, M.title);
		cout << "Информация обновлена!\n\n";
		break;
	}
	case 2: {
		cout << "Введите новый год выхода фильма:\nВвод -> ";
		cin >> M.year;
		cin.ignore();
		cout << "Информация обновлена!\n\n";
		break;
	}
	case 3: {
		cout << "Введите новый жанр фильма:\nВвод -> ";
		getline(cin, M.genre);
		cout << "Информация обновлена!\n\n";
		break;
	}
	case 4: {
		cout << "Введите новую продолжительность фильма:\nВвод -> ";
		cin >> M.duration;
		cin.ignore();
		cout << "Информация обновлена!\n\n";
		break;
	}
	case 5: {
		cout << "Введите новую цену за диск:\nВвод -> ";
		cin >> M.price;
		cin.ignore();
		cout << "Информация обновлена!\n\n";
		break;
	}
	default: cout << "Данный параметр отсутствует!\n\n";
	}
}

int main() {
	setlocale(LC_ALL, "Russian");

	// Задача 1
	cout << "Задача 1.\n";
	showMovie(TheLionKing);
	showMovie(TheProposal);
	showMovie(WhyHim);

	// Задача 2
	cout << "Задача 2.\nОбъект с самой высокой ценой за диск:\n";
	movies expFilm = expensive(TheLionKing, TheProposal, WhyHim);
	showMovie(expFilm);

	// Задача 3
	cout << "Задача 3.\nВыберите название фильма, данные которого необходимо изменить:\n";
	cout << "1. Король лев.\n";
	cout << "2. Предложение.\n";
	cout << "3. Почему он?\n";
	cout << "Ввод -> ";
	short n;
	cin >> n;
	cin.ignore();
	switch (n) {
	case 1: {
		showMovie(TheLionKing);
		updateinfo(TheLionKing);
		showMovie(TheLionKing);
		break;
	}
	case 2: {
		showMovie(TheProposal);
		updateinfo(TheProposal);
		showMovie(TheProposal);
		break;
	}
	case 3: {
		showMovie(WhyHim);
		updateinfo(WhyHim);
		showMovie(WhyHim);
		break;
	}
	default: cout << "Фильм отсутствует в списке!\n\n";
	}

	return 0;
}