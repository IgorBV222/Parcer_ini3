#pragma once
#include <iostream>

class IParcer{

public:
	//������ �����
	virtual void IReaderFile(const std::string& file_name){}
	//����� ����� �� ������� (� ����� ������ ����)
	virtual void IfindKey(const std::string& find_key){}
	//���������� �� ������
	virtual void IfindSection(const std::string& find_section) {}
	//���� � �����
	virtual void keyInFile(const std::string& find_key) {}
	//���������� �� �������� � �����
	virtual void valueInFile(const std::string& find_value) {}
	//�������� ����� � ������
	virtual void keyValueInSection(const std::string& section_name, const std::string& key_name) {}
	//������ �������� �����
	virtual void keyValueReplacement(const std::string& section_name, const std::string& key_name, const std::string& value_newName) {}
	//������ ������� � ���� writeToFile
	virtual void writeToFile(const std::string& file_name) {}
	

	//����� ������� � �������
	virtual void showParcer(){}


	virtual ~IParcer() {}
};

