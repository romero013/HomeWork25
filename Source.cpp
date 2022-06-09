#include <iostream>
#include <string>
using namespace std;

// �������
struct movies {
	string title;
	int year;
	string genre;
	unsigned int duration;
	unsigned int price;
};
movies TheLionKing = { "������ ���", 1994, "����������", 88, 123 };
movies TheProposal = { "�����������", 2009, "�������", 108, 234 };
movies WhyHim = { "������ ��?", 2016, "�������", 111, 345 };

// ������ 1 (����� ������ � ������)
void showMovie(movies& M) {
	cout << "�������� ������: " << M.title << endl;
	cout << "��� ������: " << M.year << ".\n";
	cout << "����: " << M.genre << ".\n";
	cout << "����������������� ������: " << M.duration << " �����." << endl;
	cout << "���� �� ����: " << M.price << " ���.\n\n";
}

// ������ 2 (����������� ������ �������� ������)
movies expensive(movies& M, movies& M1, movies& M2) {
	if (M.price > M1.price && M.price > M2.price)
		return M;
	else
		if (M1.price > M.price && M1.price > M2.price)
			return M1;
		else
			return M2;
}

// ������ 3 (��������� ������ ���������� ������)
void updateinfo(movies& M) {
	cout << "��������, ����� ���������� � ������ ���������� ��������:\n";
	cout << "1. ��������;\n";
	cout << "2. ��� ������;\n";
	cout << "3. ����;\n";
	cout << "4. �����������������;\n";
	cout << "5. ���� �� ����.\n";
	cout << "���� -> ";
	short x;
	cin >> x;
	cin.ignore();
	switch (x) {
	case 1: {
		cout << "������� ����� �������� ������:\n���� -> ";
		getline(cin, M.title);
		cout << "���������� ���������!\n\n";
		break;
	}
	case 2: {
		cout << "������� ����� ��� ������ ������:\n���� -> ";
		cin >> M.year;
		cin.ignore();
		cout << "���������� ���������!\n\n";
		break;
	}
	case 3: {
		cout << "������� ����� ���� ������:\n���� -> ";
		getline(cin, M.genre);
		cout << "���������� ���������!\n\n";
		break;
	}
	case 4: {
		cout << "������� ����� ����������������� ������:\n���� -> ";
		cin >> M.duration;
		cin.ignore();
		cout << "���������� ���������!\n\n";
		break;
	}
	case 5: {
		cout << "������� ����� ���� �� ����:\n���� -> ";
		cin >> M.price;
		cin.ignore();
		cout << "���������� ���������!\n\n";
		break;
	}
	default: cout << "������ �������� �����������!\n\n";
	}
}

int main() {
	setlocale(LC_ALL, "Russian");

	// ������ 1
	cout << "������ 1.\n";
	showMovie(TheLionKing);
	showMovie(TheProposal);
	showMovie(WhyHim);

	// ������ 2
	cout << "������ 2.\n������ � ����� ������� ����� �� ����:\n";
	movies expFilm = expensive(TheLionKing, TheProposal, WhyHim);
	showMovie(expFilm);

	// ������ 3
	cout << "������ 3.\n�������� �������� ������, ������ �������� ���������� ��������:\n";
	cout << "1. ������ ���.\n";
	cout << "2. �����������.\n";
	cout << "3. ������ ��?\n";
	cout << "���� -> ";
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
	default: cout << "����� ����������� � ������!\n\n";
	}

	return 0;
}