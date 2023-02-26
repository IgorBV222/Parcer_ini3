#pragma once
#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <iostream>
#include <chrono>
#include "IParcer.h"



class Parcer_ini : public IParcer{

public:
	//Чтение файла
	void IReaderFile(const std::string& file_name) override;

	//Поиск ключа по секциям (в какой секции ключ)
	void IfindKey(const std::string& find_key) override;

	//Существует ли секция
	void IfindSection(const std::string& find_section) override;

	//Ключ в файле
	bool keyInFile(const std::string& find_key) override;

	//Существует ли значение в файле
	bool valueInFile(const std::string& find_value) override;
	
	//Значение ключа в секции
	void keyValueInSection(const std::string& section_name, const std::string& key_name) override;

	//Замена значения ключа
	void keyValueReplacement(const std::string& section_name, const std::string& key_name, const std::string& value_newName) override;

	//Запись парсера в файл
	const void writeToFile(const std::string& file_name) override;

	//Вывод Парсера в консоль
	void showParcer() override;

private:
	
	std::map <std::string, std::map < std::string, std::string>> _section;	
	
};

