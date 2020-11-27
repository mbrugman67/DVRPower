#include "http.h"
#include "../util/util.h"

#include <map>
#include <utility>
#include <string>
#include <sstream>
#include <exception>

#define TIME_STR_LEN	100

httpHelper::httpHelper()
{

}
httpHelper::~httpHelper()
{

}

const std::string httpHelper::htmlHeader(const std::string& title) const
{
	// first cout is for the header string and must be in this format
	return (util::stringFormat("Content-type: text/html\n\n<!DOCTYPE html><html><head>"
        "<title>%s</title><link rel='stylesheet' href='/css/main.css'>"
        "<script src='/js/general.js'></script>"
        "</head><body>",
        title.c_str()));
}

const std::string httpHelper::timeString() const
{
    std::string ret;
    time_t rawtime;
    struct tm * timeinfo;
    ret.resize(TIME_STR_LEN + 1);

    time (&rawtime);
    timeinfo = localtime (&rawtime);

    strftime (&ret[0], TIME_STR_LEN, "%c",timeinfo);

    //return (std::string(buffer));
    return (ret);
}

const std::string httpHelper::xmlHeader(void) const
{
    return (std::string("Content-type: text/xml\n\n"));
}

const std::map<std::string, std::string> httpHelper::parseTokens(const std::string& POST)
{
	static std::map<std::string, std::string>tokens;

	size_t start = POST.find_first_not_of("&");
    size_t end = start;

	while (start != std::string::npos)
	{
		// Find next occurence of delimiter
		end = POST.find("&", start);

		// get that name/value pair and plop it into the map
		std::string thisToken = POST.substr(start, end - start);
		size_t posn = thisToken.find("=");
		if (posn != std::string::npos)
		{
			std::string key = thisToken.substr(0, posn);
			std::string value = thisToken.substr(posn + 1, std::string::npos);
			tokens.insert(std::make_pair<std::string, std::string>((std::string)key, (std::string)value));
		}

		// Skip all occurences of the delimiter to find new start
		start = POST.find_first_not_of("&", end);
	}   

    return (tokens); 
}

const std::string httpHelper::pingServer(const std::string& host) const
{
    std::ostringstream out;
    int result = 1;

    try
    {
        std::string command = util::stringFormat("ping -c1 %s >> /dev/null 2>&1", host.c_str());
        result = std::system(command.c_str());
    }
    catch (std::exception ex)
    {
        out << ex.what();
    }

    if (result == 0)
    {
        out << "DVR machine is <span style='color:DarkSeaGreen;'><b>UP</b></span>";
    }
    else
    {
        out << "DVR machine is <span style='color:red;'><b>DOWN</b></span>";
    }

    out << ", last updated at " << this->timeString().c_str();
    out << "</body></html>";

    return (out.str());
}
