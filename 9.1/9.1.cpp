#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h> // забезпечення відображення кирилиці

using namespace std;

enum Spec { KOMP, INF, MAT, FIZ, TR };

string specStr[] = { "Комп'ютерні науки", "Інформатика", "Математика ті економіка", "Фізика та інформатика", "Трудове навчання" };

struct Student
{
	string prizv;
	int kurs;
	Spec spec;
	int fiz;
	int mat;
	double avr;
	union
	{
		int pr;
		int ch;
		int pedo;
	};
};

void Create(Student* p, const int N);
void Print(Student* p, const int N);
void Search(Student* p, const int N);

int main()

{ // забезпечення відображення кирилиці:
	SetConsoleCP(1251); // встановлення сторінки win-cp1251 в потік вводу
	SetConsoleOutputCP(1251); // встановлення сторінки win-cp1251 в потік виводу

	int N;
	cout << "Введіть кількість студентів N: "; cin >> N;

	Student* p = new Student[N];

	double proc;
	int menuItem;

	do {
		cout << endl << endl << endl;
		cout << "Виберіть дію:" << endl << endl;
		cout << " [1] - введення даних з клавіатури" << endl;
		cout << " [2] - вивід даних на екран" << endl;
		cout << " [3] - вивід прізвищ студентів, які вчаться без трійок," << endl;
		cout << " та кількості відмінників з фізики" << endl;
		cout << " [0] - вихід та завершення роботи програми" << endl << endl;
		cout << "Введіть значення: "; cin >> menuItem;
		cout << endl << endl << endl;

		switch (menuItem)
		{
		case 1:
			Create(p, N);
			break;
		case 2:
			Print(p, N);
			break;
		case 3:
			Search(p, N);
			break;
		case 0:
			break;
		default:
			cout << "Ви ввели помилкове значення! "
				"Слід ввести число - номер вибраного пункту меню" << endl;
		}
	} while (menuItem != 0);
	system("pause");
	return 0;
}

void Create(Student* p, const int N)
{
	int spec;
	for (int i = 0; i < N; i++)
	{
		cout << "Студент № " << i + 1 << ":" << endl;

		cin.get(); // очищуємо буфер клавіатури – бо залишаються символи
		cin.sync(); // "кінець рядка", які не дають ввести наступний літерний рядок

		cout << " прізвище: "; getline(cin, p[i].prizv);
		cout << " курс: "; cin >> p[i].kurs;
		cout << " спціальність (0 - Комп'ютерні науки, 1 - Інформатика, 2 - Математика та економіка, 3 - Фізика та інформатика, 4 - Трудове навчання): ";
		cin >> spec;
		p[i].spec = (Spec)spec;
		switch (p[i].spec)
		{
		case KOMP:
			cout << " оцінка з фізики : "; cin >> p[i].fiz;
			cout << " оцінка з математики : "; cin >> p[i].mat;
			cout << " оцінка з програмування : "; cin >> p[i].pr;
			p[i].avr = (p[i].fiz + p[i].mat + p[i].pr) / 3;
			break;
		case INF:
			cout << " оцінка з фізики : "; cin >> p[i].fiz;
			cout << " оцінка з математики : "; cin >> p[i].mat;
			cout << " оцінка з чисельних методів : "; cin >> p[i].ch;
			p[i].avr = (p[i].fiz + p[i].mat + p[i].ch) / 3;
			break;
		case MAT:
			cout << " оцінка з фізики : "; cin >> p[i].fiz;
			cout << " оцінка з математики : "; cin >> p[i].mat;
			cout << " оцінка з педагогіки : "; cin >> p[i].pedo;
			p[i].avr = (p[i].fiz + p[i].mat + p[i].pedo) / 3;
			break;
		case FIZ:
			cout << " оцінка з фізики : "; cin >> p[i].fiz;
			cout << " оцінка з математики : "; cin >> p[i].mat;
			cout << " оцінка з педагогіки : "; cin >> p[i].pedo;
			p[i].avr = (p[i].fiz + p[i].mat + p[i].pedo) / 3;
			break;
		case TR:
			cout << " оцінка з фізики : "; cin >> p[i].fiz;
			cout << " оцінка з математики : "; cin >> p[i].mat;
			cout << " оцінка з педагогіки : "; cin >> p[i].pedo;
			p[i].avr = (p[i].fiz + p[i].mat + p[i].pedo) / 3;
			break;
		}
		cout << endl;
	}
}

void Search(Student* p, const int N)
{
	cout << "Студенти, які вчаться без трійок:" << endl;
	for (int i = 0; i < N; i++)
	{
		switch (p[i].spec)
		{
		case KOMP:
			if (p[i].fiz > 3 && p[i].mat > 3 && p[i].pr > 3)
				cout << "    " << p[i].prizv << endl;
			break;
		case INF:
			if (p[i].fiz > 3 && p[i].mat > 3 && p[i].ch > 3)
				cout << "    " << p[i].prizv << endl;
			break;
		case MAT:
			if (p[i].fiz > 3 && p[i].mat > 3 && p[i].pedo > 3)
				cout << "    " << p[i].prizv << endl;
			break;
		case FIZ:
			if (p[i].fiz > 3 && p[i].mat > 3 && p[i].pedo > 3)
				cout << "    " << p[i].prizv << endl;
			break;
		case TR:
			if (p[i].fiz > 3 && p[i].mat > 3 && p[i].pedo > 3)
				cout << "    " << p[i].prizv << endl;
			break;
		}
	}
	cout << "Кількість відмінників з фізики: ";

	int count = 0;

	for (int i = 0; i < N; i++)
	{
		if (p[i].fiz == 5)
			count++;
	}
	cout << count;
}

void Print(Student* p, const int N)
{
	cout << "============================================================================================================================"
		<< endl;
	cout << "| № |    Прізвище    | Курс |      Спеціальність      | Фізика | Математика | Програмування | Чисельні методи | Педагогіка |"
		<< endl;
	cout << "----------------------------------------------------------------------------------------------------------------------------"
		<< endl;
	for (int i = 0; i < N; i++)
	{
		cout << "| " << setw(1) << right << i + 1 << " ";
		cout << "| " << setw(15) << left << p[i].prizv
			<< "| " << setw(4) << right << p[i].kurs << " "
			<< "| " << setw(24) << left << specStr[p[i].spec];
		switch (p[i].spec)
		{
		case KOMP:
			cout << "| " << setw(6) << fixed << right << p[i].fiz << " |";
			cout << setw(11) << fixed << right << p[i].mat << " |";
			cout << setw(14) << fixed << right << p[i].pr << " |";
			cout << setw(18) << fixed << "|";
			cout << setw(13) << fixed << "|" << endl;
			break;
		case INF:
			cout << "| " << setw(6) << fixed << right << p[i].fiz << " |";
			cout << setw(11) << fixed << right << p[i].mat << " |";
			cout << setw(16) << fixed << "|";
			cout << setw(16) << fixed << right << p[i].ch << " |";
			cout << setw(13) << fixed << "|" << endl;
			break;
		case MAT:
			cout << "| " << setw(6) << fixed << right << p[i].fiz << " |";
			cout << setw(11) << fixed << right << p[i].mat << " |";
			cout << setw(16) << fixed << "|";
			cout << setw(18) << fixed << "|";
			cout << setw(11) << fixed << right << p[i].pedo << " |" << endl;
			break;
		case FIZ:
			cout << "| " << setw(6) << fixed << right << p[i].fiz << " |";
			cout << setw(11) << fixed << right << p[i].mat << " |";
			cout << setw(16) << fixed << "|";
			cout << setw(18) << fixed << "|";
			cout << setw(11) << fixed << right << p[i].pedo << " |" << endl;
			break;
		case TR:
			cout << "| " << setw(6) << fixed << right << p[i].fiz << " |";
			cout << setw(11) << fixed << right << p[i].mat << " |";
			cout << setw(16) << fixed << "|";
			cout << setw(18) << fixed << "|";
			cout << setw(11) << fixed << right << p[i].pedo << " |" << endl;
			break;
		}
	}
	cout << "============================================================================================================================"
		<< endl;
	cout << endl;
}
