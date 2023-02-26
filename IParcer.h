#pragma once
#include <iostream>

class IParcer{

public:
	//Чтение файла
	virtual void IReaderFile(const std::string& file_name) = 0;
	//Поиск ключа по секциям (в какой секции ключ)
	virtual void IfindKey(const std::string& find_key) = 0;
	//Существует ли секция
	virtual void IfindSection(const std::string& find_section) = 0;
	//Ключ в файле
	virtual bool keyInFile(const std::string& find_key) = 0;
	//Существует ли значение в файле
	virtual bool valueInFile(const std::string& find_value) = 0;
	//Значение ключа в секции
	virtual void keyValueInSection(const std::string& section_name, const std::string& key_name) = 0;
	//Замена значения ключа
	virtual void keyValueReplacement(const std::string& section_name, const std::string& key_name, const std::string& value_newName) = 0;
	//Запись парсера в файл writeToFile
	virtual const void writeToFile(const std::string& file_name) = 0;
	

	//Вывод Парсера в консоль
	virtual void showParcer() = 0;


	virtual ~IParcer() {}
};

