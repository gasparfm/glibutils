/* @(#)gutils_string.h
 */

#ifndef _GUTILS_STRING_H
#define _GUTILS_STRING_H 1

#include <glibmm/ustring.h>
#include <map>

using namespace Glib;

namespace Gutils
{
  const ustring whiteSpaces( " \f\n\r\t\v" );
  const ustring endl="\n";

  ustring replace(ustring source, ustring fromStr, ustring toStr, int offset=0, int times=1);
  ustring replace(ustring source, std::map<ustring,ustring>strMap, int offset=0, int times=1);

  inline ustring replaceAll(ustring source, ustring fromStr, ustring toStr, int offset=0)
  {
    return replace(source, fromStr, toStr, offset, 0);
  }

  inline ustring replaceAll(ustring source, std::map<ustring, ustring>strMap, int offset=0)
  {
    return replace(source, strMap, offset, 0);
  }

  ustring trimRight( ustring &str, ustring trimChars = whiteSpaces );
  ustring trimRightC (ustring str, ustring trimChars = whiteSpaces );
  ustring trimLeft( ustring &str, const ustring trimChars = whiteSpaces );
  ustring trimLeftC (ustring str, ustring trimChars = whiteSpaces );
  ustring trim( ustring &str, const ustring trimChars = whiteSpaces );
  ustring trimC(ustring str, ustring trimChars = whiteSpaces );

  ustring indentation(int level, ustring indentStr);
  int strtol(long &value, ustring str, int base);
  int strtol(long &value, ustring str, long &value2, ustring str2, int base);
  int strtod(double &value, ustring str);

};

#endif /* _GUTILS_STRING_H */

