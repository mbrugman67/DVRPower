#ifndef UTIL_H_
#define UTIL_H_

#include <string>
#include <cstdarg>

#define BIT(x)          (1u << x)
#define GETBIT(w,b)     (w & BIT(b))
#define SETBIT(w,b)     (w |= BIT(b))
#define CLRBIT(w,b)     (w &= ~(BIT(b)))

class util
{
public:

    util() {};
    ~util() {};
    static const std::string stringFormat(const std::string format, ...);
};

#endif // define UTIL_H_