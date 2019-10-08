#include "DCAWeather.hpp"
#include <LibCurlWrap.hpp>

#include <libxml++/libxml++.h>

#include <iostream>
#include <sstream>

using namespace std;
using namespace libcurlwrap;

static string _KDCA("https://w1.weather.gov/xml/current_obs/KDCA.xml");

DCAWeather::DCAWeather()
{
}

DCAWeather::~DCAWeather()
{
}

void DCAWeather::refresh()
{
	LibCurlWrap lc_wrapper;

    string xhtml = lc_wrapper.getXHTML(_KDCA);

	xmlpp::DomParser parser;
	
	parser.parse_memory(xhtml);
	if ( ! parser )
	{
		cerr << "Failure parsing response from " << _KDCA << endl;
		return;
	}

	xmlpp::Document *doc  = parser.get_document();
	xmlpp::Node     *root = doc->get_root_node();
	
	stringstream new_weather;

	appendElement(root, new_weather, string("station_id"),         string("Station"));
	appendElement(root, new_weather, string("location"),           string("Location"));
	appendElement(root, new_weather, string("observation_time"),   string("Time"));
	appendElement(root, new_weather, string("temperature_string"), string("Temperature"));

	_weather = new_weather.str();
}

void DCAWeather::appendElement(void *doc_root, stringstream& strm, string node_name, string tag)
{
	xmlpp::Node    *root = (xmlpp::Node *) doc_root;

	xmlpp::NodeSet nset  = root->find(string("//").append(node_name));

	strm << tag << ":" << endl;	
	for(xmlpp::NodeSet::iterator i = nset.begin(); i != nset.end(); i++)
    {
		xmlpp::Element *ele = dynamic_cast<xmlpp::Element *>(*i);
		if ( ele )
		{
			strm << "\t" << ele->get_child_text()->get_content() << endl;
		}
    }

	return;
}

string DCAWeather::getWeather()
{
	if (_weather.size() ==  0)
	{
		refresh();
	}

	return _weather;
}
