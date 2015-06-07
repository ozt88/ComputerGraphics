#include "pch.h"
#include "Config.h"
#include <fstream>

Config::Config()
{
}


Config::~Config()
{
}

bool Config::Init(const std::string& path)
{
	std::ifstream configFile(path);

	if(!configFile.is_open())
		return false;

	char buf[1024] = {0, };

	while(!configFile.eof())
	{
		configFile.getline(buf, 1024);

		auto it = std::find(buf, buf + strlen(buf), '=');
		std::string key;
		std::string value;

		key.assign(buf, it);
		value.assign(it + 1, buf + strlen(buf));
		m_Data[key] = value;
	}

	return true;
}

float Config::GetDataByFloat(const std::string& key)
{
	return std::stod(m_Data[key]);
}

int Config::GetDataByInt(const std::string& key)
{
	return std::stoi(m_Data[key]);
}

std::string Config::GetDataByString(const std::string& key)
{
	return m_Data[key];
}
