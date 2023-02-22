#pragma once
#include <iostream>

class IParcer{

public:
	//Чтение файла
	virtual void IReaderFile(const std::string& file_name){}
	//Поиск ключа по секциям (в какой секции ключ)
	virtual void IfindKey(const std::string& find_key){}
	//Существует ли секция
	virtual void IfindSection(const std::string& find_section) {}
	//Ключ в файле
	virtual void keyInFile(const std::string& find_key) {}
	//Существует ли значение в файле
	virtual void valueInFile(const std::string& find_value) {}
	//Значение ключа в секции
	virtual void keyValueInSection(const std::string& section_name, const std::string& key_name) {}
	//Замена значения ключа
	virtual void keyValueReplacement(const std::string& section_name, const std::string& key_name, const std::string& value_newName) {}
	//Запись парсера в файл writeToFile
	virtual void writeToFile(const std::string& file_name) {}
	

	//Вывод Парсера в консоль
	virtual void showParcer(){}


	virtual ~IParcer() {}
};

