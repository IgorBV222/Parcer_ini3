#include "Parcer_ini.h"

//Чтение файла
/*
void Parcer_ini::IReaderFile(const std::string& file_name) {
std::ifstream path;
path.open(file_name);
std::string currenLine;

if (path.is_open()) {
	while (getline(path, currenLine)) {
		if (currenLine[0] == '[') { //выводим имя секции
			_sectionTitle = currenLine.substr(1, currenLine.find(']') - 1);
			_section[_sectionTitle];
		}
		else {
			if (currenLine.size() != 0 && currenLine[0] != ';' && currenLine[0] != '#' && currenLine[0] != '[') {
				for (int i = 0; i < currenLine.size(); i++) {
					if (currenLine[i] == '=') {
						_key = currenLine.substr(0, currenLine.find('='));

					}
				}
			}
		}
	
	
	
	
	
	
	
		_section[_sectionTitle][_key] = _value;
	}
}
else
	throw "Error open file";
	path.close();
}*/


void Parcer_ini::IReaderFile(const std::string& file_name) {

	std::ifstream path;
	path.open(file_name);
	std::string currenLine;
	std::string sectionTitle, key, value;
	
	if (path.is_open()) {
		while (getline(path, currenLine)) {			
			if (currenLine[0] == '[') {
				sectionTitle = currenLine.substr(1, currenLine.find(']') - 1);
				//_section[_sectionTitle];
			}
			else {
				if (currenLine.size() !=0 && currenLine[0] != ';' && currenLine[0] != '#' && currenLine[0] != '[') {
					for (int i = 0; i < currenLine.size(); i++) {
						if (currenLine[i] == '=') {
							key = currenLine.substr(0, currenLine.find('='));
							value = currenLine.substr(currenLine.find('=') + 1, currenLine.find(';'));
						}
						/*
						for (int i = currenLine.find('='); i < currenLine.size(); i++) {
							if (currenLine[i] == ';') {
								_value = currenLine.substr(currenLine.find('=') +1, currenLine.find(';'));
							}
							if (currenLine[i] == '#') {
								_value = currenLine.substr(currenLine.find('=') +1, currenLine.find('#'));
							}
							else 
							    _value = currenLine.substr(currenLine.find('=') +1) + currenLine[i];
						}
						*/
						//while (currenLine[i] != ';' || currenLine[i] != '#') {
						//	_value = currenLine.substr(currenLine.find('=') + 1) + currenLine[i];
						//	_value = _value.substr(_value.find(' ') - 1);							
						//}
							//parameterValues[key] = value;
							//parameterValues[currenLine.substr(0, currenLine.find('=') - 1)] = currenLine.substr(currenLine.find('=') + 1);
							//_section[sectionTitle] = parameterValues;
							//_section[_sectionTitle][_key] = _value;						
					}
				}
				_section[sectionTitle][key] = value;
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
				std::cout << "The key: " << element.first << " in section " << section.first << std::endl;	
			else //(element.first != find_key)
				std::cout << "The key: " << find_key << " is not in the sections!" << section.first << std::endl;
		}
	}	
}

//Существует ли секция
void Parcer_ini::IfindSection(const std::string& find_section) {
	for (const auto& section : _section) {
		if (section.first == find_section) 
			std::cout << "Section exists!" << std::endl;
		else
			std::cout << "There is no such section...." << std::endl;
	}
	
}






//Ключ в файле
bool Parcer_ini::keyInFile(const std::string& find_key){
	for (const auto& section : _section) {
		for (const auto& element : section.second) {
			if (element.first == find_key)
				return true;
		}
	}
	return false;
}

//Существует ли значение в файле
bool Parcer_ini::valueInFile(const std::string& find_value){
	for (const auto& section : _section) {
		for (const auto& element : section.second) {
			//if (element.second == find_value)
			if(element.second.find(find_value)) // при условии, что для ключа в поле значения есть перечисление
				return true;
		}
	}
	return false;
}

//Значение ключа в секции
void Parcer_ini::keyValueInSection(const std::string& section_name, const std::string& key_name) {
	for (const auto& section : _section) {
		if (section.first == section_name) {
			for (const auto& element : section.second) {
				if (element.first == key_name)
					std::cout << "Key value in section: " << element.second << std::endl;
				//else //(element.first != key_name) 
					//std::cout << "No key in section!" << std::endl;				
			}
		}
		//else
			//std::cout << "No section in file!" << std::endl;
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
	std::string sectionTitle, key, value;
	for (const auto& section : _section) {
		if (section.first == section_name) {
			for (const auto& element : section.second) {
				if (element.first == key_name) {
					value = value_newName;
					_section[sectionTitle][key] = value;
					std::cout << "Key: " << element.first << " value changed to: " << element.second << std::endl;
				}
			}
		}
		else {
			if (section.first != section_name) {
				sectionTitle = section_name;
				for (const auto& element : section.second) {
					key = key_name;
					value = value_newName;
					_section[sectionTitle][key] = value;
					std::cout << "New section created: " << section.first << "\nNew key created: " << element.first << "\nNew value created:" << element.second << std::endl;
				}
			}
			else {
				if (section.first == section_name) {
					for (const auto& element : section.second) {
						if (element.first != key_name) {
							key = key_name;
							value = value_newName;
							_section[sectionTitle][key] = value;
							std::cout << "New key created: " << element.first << "\nNew value created:" << element.second << std::endl;
						}
					}
				}
			}
		}
	}
}

//Запись парсера в файл
const void Parcer_ini::writeToFile(const std::string& file_name){	
	std::fstream out;	
	out.open(file_name);
	if (out.is_open()) {
		
		for (const auto& section : _section) {
			//parser += ('[' + section.first + ']' + '\n');
			out << ('[' + section.first + ']' + '\n');
			for (const auto& element : section.second) {
				//parser += (element.first + '=' + element.second + '\n');
				out << (element.first + '=' + element.second + '\n');
			}
		}
		//out << parser << "\n";
		

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
					std::cout << element.first << "=" << element.second << std::endl;
			}
	}
}

