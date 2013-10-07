/**
*************************************************************
* @file test.cpp
* @brief Breve descripción
* Pequeña documentación del archivo
*
*
*
*
*
* @author Gaspar Fernández <blakeyed@totaki.com>
* @version
* @date 01 oct 2013
* Historial de cambios:
*
*
*
*
*
*
*
*************************************************************/

#include <iostream>
#include "gutils.h"

using namespace std;

int main(int argc, char *argv[])
{
  Glib::ustring text1 = "      String beginning and ending with spaces and tabs\t\t   ";
  Glib::ustring text2 = "      String beginning and ending with new line and more \n\t\n \r";
  Glib::ustring text3 = "///\\\\String beginning and ending with other characters $%&/&%$&/&";
  cout << "Original: \""<<text1<<"\""<<endl;
  cout << "trimmed: \""<<Gutils::trim(text1)<<"\""<<endl;
  cout << endl;
  cout << "Original: \""<<text2<<"\""<<endl;
  cout << "trimmed: \""<<Gutils::trim(text2)<<"\""<<endl;
  cout << endl;
  cout << "Original: \""<<text3<<"\""<<endl;
  // Customizing characters to trim
  cout << "trimmed: \""<<Gutils::trim(text3, "/\\$%&")<<"\""<<endl;
  cout << endl;
  return 0;
}

