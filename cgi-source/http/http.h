#ifndef HTTP_H_
#define HTTP_H_

#include <string>
#include <map>

class httpHelper
{
public:
    httpHelper();
    virtual ~httpHelper();

    const std::string htmlHeader(const std::string& title = std::string("rPI Power")) const;
    const std::string xmlHeader(void) const;
    const std::string timeString() const;
    static const std::map<std::string, std::string> parseTokens(const std::string& POST);

    const std::string pingServer(const std::string& host) const;

protected:

private:


};

#endif // define HTTP_H_