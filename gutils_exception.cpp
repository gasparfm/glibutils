/**
*************************************************************
* @file gutils_exception.cpp
* @brief Breve descripción
* Pequeña documentación del archivo
*
*
*
*
*
* @author Gaspar Fernández <blakeyed@totaki.com>
* @version
* @date 07 oct 2013
* Historial de cambios:
*
*
*
*
*
*
*
*************************************************************/

#include "gutils_exception.h"
#include <glibmm/ustring.h>

using namespace Glib;

namespace Gutils
{
  Exception::Exception(int code, ustring error): code(code), error(error)
  {
  }

  Exception::~Exception() throw()
  {
  }

  ustring Exception::what()
  {
    return error;
  }

  int Exception::getCode()
  {
    return code;
  }
};
