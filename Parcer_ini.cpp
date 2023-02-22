#include "Parcer_ini.h"

//Чтение файла
void Parcer_ini::IReaderFile(const std::string& file_name){

	std::ifstream path;
	path.open(file_name);
	std::string currenLine;
	
	if (path.is_open()) {
		while (getline(path, currenLine)) {			
			if (currenLine[0] == '[') {
				_sectionTitle = currenLine.substr(1, currenLine.find(']') - 1);
				_section[_sectionTitle];
			}
			else {
				if (currenLine.size() !=0 && currenLine[0] != ';' && currenLine[0] != '#' && currenLine[0] != '[') { 
					for (int i = 0; i < currenLine.size(); i++) {
						if (currenLine[i] == '=') {
							_key = currenLine.substr(0, currenLine.find('=') - 1);
						}
						while (currenLine[i] != ';' || currenLine[i] != '#') {
							_value = currenLine.substr(currenLine.find('=') + 1) + currenLine[i];
							_value = _value.substr(_value.find(' ') - 1);							
						}
							//parameterValues[key] = value;
							//parameterValues[currenLine.substr(0, currenLine.find('=') - 1)] = currenLine.substr(currenLine.find('=') + 1);
							//_section[sectionTitle] = parameterValues;
							_section[_sectionTitle][_key] = _value;						
					}
				}
			}			
		}		
	}
	else
		throw "Error open file";

	path.close();
}

//Поиск ключа по секциям (в какой секции ключ)
void Parcer_ini::IfindKey(const std::string& find_key){
	for (const auto& section : _section) {
		for (const auto& element : section.second) {
			if (element.first == find_key)
				std::cout << "The key: " << element.first << " in section!" << section.first << std::endl;
		}
	}
	std::cout << "The key: " << find_key << " is not in the sections!" << std::endl;
}

//Существует ли секция
void Parcer_ini::IfindSection(const std::string& find_section){
	for (const auto& section : _section) {		
			if (section.first == find_section)
				std::cout << "The section: " << section.first << " exists!" << std::endl;
	}
	std::cout << "The section: " << find_section << " does not exist!" << std::endl;
}

//Ключ в файле
void Parcer_ini::keyInFile(const std::string& find_key){
	for (const auto& section : _section) {
		for (const auto& element : section.second) {
			if (element.first == find_key)
				std::cout << "The key: " << element.first << " in file!" << std::endl;
		}
	}
	std::cout << "The key: " << find_key << " is not in the file!" << std::endl;
}

//Существует ли значение в файле
void Parcer_ini::valueInFile(const std::string& find_value){
	for (const auto& section : _section) {
		for (const auto& element : section.second) {
			if (element.second == find_value)
				std::cout << "The value: " << element.second << " in file!" << std::endl;
		}
	}
	std::cout << "The value: " << find_value << " is not in the file!" << std::endl;
}

//Значение ключа в секции
void Parcer_ini::keyValueInSection(const std::string& section_name, const std::string& key_name) {
	for (const auto& section : _section) {
		if (section.first == section_name) {
			for (const auto& element : section.second) {
				if (element.first == key_name)
					std::cout << "Key value in section: " << element.second << std::endl;
				else //(element.first != key_name) 
					std::cout << "No key in section!" << std::endl;				
			}
		}
		else
			std::cout << "No section in file!" << std::endl;
	}
}

//Замена значения ключа
/*
void Parcer_ini::keyValueReplacement(const std::string& section_name, const std::string& key_name, const std::string& value_newName) {
	for (const auto& section : _section) {
		if (section.first == section_name) {
			for (const auto& element : section.second) {
				if (element.first == key_name) {
					element.second == value_newName;
					std::cout << "Key: " << element.first << " value changed to: " << element.second << std::endl;
				}
			}
		}
		else {
			if (section.first != section_name) {
				section.first == section_name;
				for (const auto& element : section.second) {
					element.first == key_name;
					element.second == value_newName;
					std::cout << "New section created: " << section.first << "\nNew key created: " << element.first << "\nNew value created:" << element.second << std::endl;
				}
			}
			else {
				if (section.first == section_name) {
					for (const auto& element : section.second) {
						if (element.first != key_name) {
							element.first == key_name;
							element.second == value_newName;
							std::cout << "New key created: " << element.first << "\nNew value created:" << element.second << std::endl;
						}
					}
				}
			}
		}		
	}
}
*/

//Замена значения ключа 2
void Parcer_ini::keyValueReplacement(const std::string& section_name, const std::string& key_name, const std::string& value_newName) {
	for (const auto& section : _section) {
		if (section.first == section_name) {
			for (const auto& element : section.second) {
				if (element.first == key_name) {
					_value = value_newName;
					_section[_sectionTitle][_key] = _value;
					std::cout << "Key: " << element.first << " value changed to: " << element.second << std::endl;
				}
			}
		}
		else {
			if (section.first != section_name) {
				_sectionTitle = section_name;
				for (const auto& element : section.second) {
					_key = key_name;
					_value = value_newName;
					_section[_sectionTitle][_key] = _value;
					std::cout << "New section created: " << section.first << "\nNew key created: " << element.first << "\nNew value created:" << element.second << std::endl;
				}
			}
			else {
				if (section.first == section_name) {
					for (const auto& element : section.second) {
						if (element.first != key_name) {
							_key = key_name;
							_value = value_newName;
							_section[_sectionTitle][_key] = _value;
							std::cout << "New key created: " << element.first << "\nNew value created:" << element.second << std::endl;
						}
					}
				}
			}
		}
	}
}

//Запись парсера в файл
void Parcer_ini::writeToFile(const std::string& file_name){

	std::string path = file_name;
	getline(std::cin, path);	
	std::fstream out;
	std::string parser;
	out.open(path);
	if (out.is_open()) {
		
		for (const auto& section : _section) {
			parser += '[' + section.first + ']' + '\n';
			for (const auto& element : section.second) {
				parser += element.first + '=' + element.second + '\n';
			}
		}
		out << parser << "\n";

		std::cout << "\nThe parser is written to the specified file!\n";
		system("pause");
	}
	else
		std::cout << "Error opening file! File does not exist.\n";

	system("pause");
	out.close(); 
	system("cls");
}

//Вывод Парсера в консоль
void Parcer_ini::showParcer(){
	for (const auto& section : _section) {
		std::cout << "[" << section.first << "]" << std::endl;
			for (const auto& element : section.second) {
					std::cout << "key: " << element.first << " " << "value: " << element.second << std::endl;
			}
	}
}

