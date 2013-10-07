#include <glibmm/ustring.h>
#include <iostream>
#include "gutils.h"

using namespace Glib;
using namespace std;

int main()
{
  Glib::ustring str1 = "Just want to %find% some %keywords% in this %text%";

  Gutils::RegexMatches m("%([a-z]*)%", str1);

  m.replaceMatch("paint");
  m.next();
  m.replaceMatch("paintings");
  m.next();
  m.replaceMatch("room");
  cout << "String: "<<m.str()<<endl;
}
