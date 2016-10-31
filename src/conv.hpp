/**
 *  @author     Dušan Vudragović, dusan.vudragovic@gmail.com
 *  @file       conv.hpp
 */

#ifndef _CONV_HPP_
#define _CONV_HPP_

#include <map>

typedef std::map<std::wstring const, std::wstring const> alphconmap;

class conv {
public:
    static alphconmap lattocyr, cyrtolat;
    static void converter(alphconmap& map);
};

#endif
