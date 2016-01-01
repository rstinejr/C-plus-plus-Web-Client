#ifndef DCA_WEATHER_HPP
#define DCA_WEATHER_HPP

#include <string>
#include <sstream>

class DCAWeather
{
public:
    DCAWeather();
    ~DCAWeather();
	
	void refresh();

    std::string getWeather();

private:
    std::string _weather;
	void        appendElement(void *doc_root, std::stringstream& strm, std::string node_name, std::string tag);
};

#endif
