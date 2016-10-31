/**
 *  @author     Dušan Vudragović, dusan.vudragovic@gmail.com
 *  @file       conv.cpp
 */

#include "conv.hpp"

#include <iostream>

using std::endl;
using std::wcin;
using std::wcout;
using std::wstring;
using std::getline;

// Latin to Cyrillic alphabet conversation map.
alphconmap conv::cyrtolat = {
    {L"А",  L"A"},
    {L"Б",  L"B"},
    {L"В",  L"V"},
    {L"Г",  L"G"},
    {L"Д",  L"D"},
    {L"Ђ",  L"Đ"},
    {L"Е",  L"E"},
    {L"Ж",  L"Ž"},
    {L"З",  L"Z"},
    {L"И",  L"I"},
    {L"Ј",  L"J"},
    {L"К",  L"K"},
    {L"Л",  L"L"},
    {L"Љ",  L"Lj"},
    {L"М",  L"M"},
    {L"Н",  L"N"},
    {L"Њ",  L"Nj"},
    {L"О",  L"O"},
    {L"П",  L"P"},
    {L"Р",  L"R"},
    {L"С",  L"S"},
    {L"Т",  L"T"},
    {L"Ћ",  L"Ć"},
    {L"У",  L"U"},
    {L"Ф",  L"F"},
    {L"Х",  L"H"},
    {L"Ц",  L"C"},
    {L"Ч",  L"Č"},
    {L"Џ",  L"Dž"},
    {L"Ш",  L"Š"},
    {L"а",  L"a"},
    {L"б",  L"b"},
    {L"в",  L"v"},
    {L"г",  L"g"},
    {L"д",  L"d"},
    {L"ђ",  L"đ"},
    {L"е",  L"e"},
    {L"ж",  L"ž"},
    {L"з",  L"z"},
    {L"и",  L"i"},
    {L"ј",  L"j"},
    {L"к",  L"k"},
    {L"л",  L"l"},
    {L"љ",  L"lj"},
    {L"м",  L"m"},
    {L"н",  L"n"},
    {L"њ",  L"nj"},
    {L"о",  L"o"},
    {L"п",  L"p"},
    {L"р",  L"r"},
    {L"с",  L"s"},
    {L"т",  L"t"},
    {L"ћ",  L"ć"},
    {L"у",  L"u"},
    {L"ф",  L"f"},
    {L"х",  L"h"},
    {L"ц",  L"c"},
    {L"ч",  L"č"},
    {L"џ",  L"dž"},
    {L"ш",  L"š"}
};

// Cyrillic to Latin alphabet conversation map.
alphconmap conv::lattocyr = {
    {L"A",  L"А"},
    {L"B",  L"Б"},
    {L"C",  L"Ц"},
    {L"Č",  L"Ч"},
    {L"Ć",  L"Ћ"},
    {L"D",  L"Д"},
    {L"Dž", L"Џ"}, {L"DŽ", L"Џ"},
    {L"Đ",  L"Ђ"}, {L"DJ", L"Ђ"}, {L"Dj", L"Ђ"},
    {L"E",  L"Е"},
    {L"F",  L"Ф"},
    {L"G",  L"Г"},
    {L"H",  L"Х"},
    {L"I",  L"И"},
    {L"J",  L"Ј"},
    {L"K",  L"К"},
    {L"L",  L"Л"},
    {L"Lj", L"Љ"}, {L"LJ", L"Љ"},
    {L"M",  L"М"},
    {L"N",  L"Н"},
    {L"Nj", L"Њ"}, {L"NJ", L"Њ"},
    {L"O",  L"О"},
    {L"P",  L"П"},
    {L"R",  L"Р"},
    {L"S",  L"С"},
    {L"Š",  L"Ш"},
    {L"T",  L"Т"},
    {L"U",  L"У"},
    {L"V",  L"В"},
    {L"Z",  L"З"},
    {L"Ž",  L"Ж"},
    {L"a",  L"а"},
    {L"b",  L"б"},
    {L"c",  L"ц"},
    {L"č",  L"ч"},
    {L"ć",  L"ћ"},
    {L"d",  L"д"},
    {L"dž", L"џ"},
    {L"đ",  L"ђ"}, {L"dj", L"ђ"},
    {L"e",  L"е"},
    {L"f",  L"ф"},
    {L"g",  L"г"},
    {L"h",  L"х"},
    {L"i",  L"и"},
    {L"j",  L"ј"},
    {L"k",  L"к"},
    {L"l",  L"л"},
    {L"lj", L"љ"},
    {L"m",  L"м"},
    {L"n",  L"н"},
    {L"nj", L"њ"},
    {L"o",  L"о"},
    {L"p",  L"п"},
    {L"r",  L"р"},
    {L"s",  L"с"},
    {L"š",  L"ш"},
    {L"t",  L"т"},
    {L"u",  L"у"},
    {L"v",  L"в"},
    {L"z",  L"з"},
    {L"ž",  L"ж"}
};

void conv::converter(alphconmap& map) {
    wstring str;
    wchar_t c;

    str.clear();
    wcin.get(c);
    str.push_back(c);

    while (wcin.get(c)) {
        str.push_back(c);
        if (map.count(str)) {
            wcout << map[str];
            str.clear();
            if (wcin.get(c)) str.push_back(c);
        } else {
            if (map.count(str.substr(0, 1))) wcout << map[str.substr(0, 1)];
            else wcout << str.substr(0, 1);
            str.erase(0, 1);
        }

    }
    if (map.count(str)) wcout << map[str];
    else wcout << str;

    return;
}
