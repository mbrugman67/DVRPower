#include <iostream>
#include <memory>
#include <map>
#include <exception>

#include <unistd.h>

#include "util/util.h"
#include "util/io.h"
#include "http/http.h"


int main(int argc, char** argv)
{
	// get the query string
	std::string queryString;
	std::cin >> queryString;

	std::string function;

	if (!queryString.empty())
	{
		std::map<std::string, std::string>tokens = httpHelper::parseTokens(queryString);
		function = tokens["func"];
	}
	else
	{
		queryString = "Null";
	}

	std::unique_ptr<httpHelper>http(new httpHelper());

	std::cout << http->htmlHeader("DVR") << std::flush;

	if (function == std::string("ping"))
	{
		std::cout << http->pingServer(std::string("rangersmith"));
	}
	else if (function == std::string("reset"))
	{
		std::cout << "Done!";
		std::unique_ptr<ioHandler>io(new ioHandler(1));
		io->turnOn();
		sleep(3);
		io->turnOff();
	}
	
	return (0);
}
