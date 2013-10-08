/* @(#)gutils_regex.h
 */

#ifndef _GUTILS_REGEX_H
#define _GUTILS_REGEX_H 1

#include <glibmm/ustring.h>
#include <glibmm/regex.h>
#include <vector>

using namespace Glib;

namespace Gutils
{
  class RegexMatches
  {
  public:
    /**
       In a regexp we can find several return expressions, imagine %([a-z])% in "Hello %goodbye% guys" 
       it would return "%goodbye% and goodbye as second expression. SingleMatch is just one of them.
    */
    struct SingleMatch
    {
      ustring str;
      int start, end, size;
    };
    typedef std::vector<SingleMatch> Match;
    /**
	But a regex may be found several times within a string, so "First %hello% then %goodbye%", would
	return (%hello%, hello) and (%goodbye%, goodbye). Each pair will be a Match.
    */
    typedef std::vector<Match> Matches;

    /**
     * @brief RegexMatches constructor
     * @param regex Regular Expression
     * @param text Input text
     * @param offset Where to start within text
     * @param match_options RegexMatchFlags
     * @param compile_options Compile Options
     */
    RegexMatches(ustring regex, ustring text, int offset=0, 
		  Glib::RegexMatchFlags match_options=static_cast< Glib::RegexMatchFlags >(0), 
		  Glib::RegexCompileFlags compile_options=static_cast< Glib::RegexCompileFlags >(0) );
    virtual ~RegexMatches();

    /**
     * @brief Gets all matches of regexp within the original string
     * @return Matches object (vector or vectors of SingleMatch)
     */
    Matches getAll();

    /**
     * @brief Gets the current Match pointed by the internal pointer. It
     * can be used to easily iterate the class.
     *
     * @throws Gutils::Exception if internal pointer is invalid.
     * @return Current element
     */
    Match get();
    /* Gets single match (number e) */
    SingleMatch get(unsigned e, bool exception=false);
    /* Have item to give */
    bool haveMatch();
    /* Points to the next Match */
    bool next();
    /* Rewind to the first Match */
    void rewind();
    /* Number ot Matches in total */
    int count();
    /* Count sub-matches */
    int countSub(int n=0);
    /* Gets Match number n */
    Match getn(unsigned n, bool exception=false);
    /* Gets the SingleMatch e, from Match number n */
    SingleMatch getn(unsigned n, unsigned e, bool exception=false);
    /* If we have changed anything, let's go to the beginning */
    void revertChanges();
    /* Replace SingleMatch e, where the obtained word will become newText
     if continue=true it will continue until the last appearance.
     if n==-1, it will start replacing from the current pointed SingleMatch, otherwise,
     it will start from Match number n */
    bool replaceMatch(ustring newText, unsigned e=0, bool cont=false, int n=-1);
    /* returns current string. With all modifications */
    ustring str();
    /* return original string */
    ustring original();
    /* replaces all matches with newText */
    inline bool replaceAll(ustring newText, unsigned e=0)
    {
      return replaceMatch(newText, e, true, 0);
    }
    ustring debug();
  private:
    unsigned ipr;
    ustring _original;
    ustring workCopy;
    Matches matches;
    bool end;
  };

};

#endif /* _GUTILS_REGEX_H */

