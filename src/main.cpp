/**
 *  @brief      Alphcon is Latin to Cyrillic (Cyrillic to Latin) alphabet converter.
 *  @author     Dušan Vudragović, dusan.vudragovic@gmail.com
 *  @file       main.cpp
 */

#include "main.hpp"

#include <boost/locale.hpp>

#include "conv.hpp"
#include "cli.hpp"

#define LANGUAGE    "en_US.UTF-8"

using std::wcin;
using std::wcout;
using std::locale;
using boost::locale::generator;

int main(int argc, char **argv) {
    cli cli(argc, argv);

    // Set locale manually.
    generator gen;
    locale loc = gen(LANGUAGE);
    wcin.imbue(loc); wcout.imbue(loc);

    switch (cli.get_mode()) {
    case MODE_LATTOCYR:
        conv::converter(conv::lattocyr);
        break;
    case MODE_CYRTOLAT:
        conv::converter(conv::cyrtolat);
        break;
    case MODE_HELP:
        cli.help();
        break;
    case MODE_UNKNOWN:
        cli.help();
        break;
    }

    return EXIT_SUCCESS;
}
