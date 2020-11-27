#include "util.h"

#include <iostream>

const std::string util::stringFormat(const std::string format, ...)
{
    std::string retString;
    va_list args; 
    va_list argsCopy;
    va_start(args, format);

    // make a copy.  We'll use up the original testing size required
    // for output string
    va_copy(argsCopy, args);

    // find out how big the output string needs to be
    size_t size = std::vsnprintf(NULL, 0, format.c_str(), args) + 1;

    try 
    {
        retString.resize(size);
        std::vsnprintf(&retString[0], size, format.c_str(), argsCopy);
    }
    // at this point, about the only thing that could fail is allocation
    catch (const std::bad_alloc& ex)
    {
        std::cerr << "stringFormat() failed to allocate " << size << " length std::string" << std::endl
                  << "\tException: " << ex.what() << std::endl;
    }
    catch (const std::exception& ex)
    {
        std::cerr << "\nstringFormat() exception " << ex.what() << std::endl << std::endl;
    }

    va_end(argsCopy);
    va_end(args);

    return (retString);
}
