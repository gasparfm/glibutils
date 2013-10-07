/* @(#)gutils_exception.h
 */

#ifndef _GUTILS_EXCEPTION_H
#define _GUTILS_EXCEPTION_H 1

#include <exception>
#include <glibmm/ustring.h>

using namespace Glib;

namespace Gutils
{
  class Exception : public std::exception
  {
  public:
    Exception(int code, ustring error);
    virtual ~Exception() throw();

    ustring what();
    int getCode();

  private:
    ustring error;
    int code;
  };
};

#endif /* _GUTILS_EXCEPTION_H */

