#pragma once
class Config
{
public:
	Config();
	~Config();
	bool		Init(const std::string& path);
	std::string GetDataByString(const std::string& key);
	int			GetDataByInt(const std::string& key);
	float		GetDataByFloat(const std::string& key);

private:
	std::map<std::string, std::string> m_Data;
};

