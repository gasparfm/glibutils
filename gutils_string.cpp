/**
*************************************************************
* @file gutils_string.cpp
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

#include "gutils_string.h"
#include <cstdlib>

namespace Gutils
{
  ustring replace(ustring source, ustring fromStr, ustring toStr, int offset, int times)
  {
    int total = 0;
    ustring::size_type pos=offset;
    while ( ( (pos = source.find(fromStr, pos)) < Glib::ustring::npos) && ( (times==0) || (total++<times) ) )
      {
	source.replace(pos, fromStr.length(), toStr);
	pos+=toStr.size();
      }
    return source;
  }

  ustring replace(ustring source, std::map<ustring,ustring>strMap, int offset, int times)
  {
    int total = 0;
    ustring::size_type pos;

    for (std::map<ustring, ustring>::iterator i=strMap.begin(); i!=strMap.end(); ++i)
      {
	ustring fromStr = i->first;
	ustring toStr = i->second;
	pos=offset;
	while ( (pos = source.find(fromStr, pos)) < Glib::ustring::npos)
	  {
	    if ( (times!=0) && (total++>=times) )
	      return source;	// Don't work anymore

	    source.replace(pos, fromStr.length(), toStr);
	    pos+=toStr.size();
	  }
      }
    return source;
  }

  ustring trimRight( ustring &str, ustring trimChars)
  {
    ustring::size_type pos = str.find_last_not_of( trimChars );
    str.erase( pos + 1 );

    return str;
  }

  ustring trimLeft( ustring &str, const ustring trimChars)
  {
    ustring::size_type pos = str.find_first_not_of( trimChars );
    str.erase( 0, pos );

    return str;
  }

  ustring trim( ustring &str, const ustring trimChars)
  {
    trimRight( str, trimChars );
    trimLeft( str, trimChars );

    return str;
  }

  ustring trimRightC( ustring &str, ustring trimChars)
  {
    ustring copy=str;
    return trimRight(copy, trimChars);
  }

  ustring trimLeftC( ustring &str, const ustring trimChars)
  {
    ustring copy=str;
    return trimLeft(copy, trimChars);
  }

  ustring trimC( ustring str, const ustring trimChars)
  {
    ustring copy=str;

    trimRight(copy, trimChars);
    trimLeft(copy, trimChars );

    return copy;
  }

  ustring indentation(int level, ustring indentStr)
  {
    ustring retStr="";

    for (unsigned i=0; i<level; ++i)
      retStr+=indentStr;

    return retStr;
  }

  int strtol(long &value, ustring str, int base)
  {
    const char *nptr = str.c_str();
    char *eptr;
    value = ::strtol(nptr, &eptr, base);

    if (nptr==eptr)
      return -1;
    else if (eptr<(char*)nptr+str.length())
      return 0;
    else
      return 1;
  }

  int strtod(double &value, ustring str)
  {
    const char *nptr = str.c_str();
    char *eptr;
    value = ::strtod(nptr, &eptr);

    if (nptr==eptr)
      return -1;
    else if (eptr<(char*)nptr+str.length())
      return 0;
    else
      return 1;
  }

  int strtol(long &value, ustring str, long &value2, ustring str2, int base)
  {
    const char *nptr = str.c_str();
    const char *nptr2 = str.c_str();
    char *eptr, *eptr2;
    value = ::strtol(nptr, &eptr, base);
    value2 = ::strtol(nptr2, &eptr2, base);

    if ( (nptr==eptr) || (nptr2==eptr2) )
      return -1;
    else if ( (eptr<(char*)nptr+str.length()) && (eptr2<(char*)nptr2+str2.length()) )
      return 0;
    else
      return 1;
  }
};
