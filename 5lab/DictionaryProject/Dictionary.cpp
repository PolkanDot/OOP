#include "DictionaryFunctions.h"

const string notArgs = "The dictionary was not transmitted \n";
const string openErr = "Failed to open ";
const string reading = " for reading\n";
const string changed = "В словарь были внесены изменения. Введите \"Yes\", если хотите сохранить новые слова или \"No\" в противном случае: \n";
const string yes = "Yes";

// В структуре данного типа будем хранить аргументы командной строки
struct Args
{
	string dictionaryFileName;
};

// Парсинг аргументов, идущих на вход программе, проверка на правильность их количества
optional<Args> ParseArgs(int argc, char* argv[])
{
	if (argc != 2)
	{
		return std::nullopt;
	}
	// Объявляем переменную args типа Args
	Args args;
	args.dictionaryFileName = argv[1];
	return args;
}

int main(int argc, char* argv[])
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	map<string, string> dictionary;
	auto args = ParseArgs(argc, argv);
	if (!args)
	{
		cout << notArgs;
		return 1;
	}
	// Создаём поток для чтение из входного файла 
	fstream dictionaryFile;
	dictionaryFile.open(args->dictionaryFileName, ios::in);
	// Проверем, открылся ли входной файл
	if (!dictionaryFile.is_open())
	{
		cout << openErr << args->dictionaryFileName << reading;
		return 1;
	}

	// читаем записи из файла словаря в map
	ReadDictionary(dictionaryFile, dictionary);
	map<string, string> dictionaryWithNewWords;

	if (Translate(cin, cout, dictionary, dictionaryWithNewWords))
	{
		cout << changed;
		string response;
		cin >> response;
		if (response == yes)
		{
			dictionaryFile.close();
			dictionaryFile.open(args->dictionaryFileName, ios::app);
			WriteRecordToFile(dictionaryFile, dictionaryWithNewWords);
		}
	}
}
