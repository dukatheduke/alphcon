CC = g++
LIBS = -lboost_system -lboost_locale-mt -lboost_program_options
CFLAGS = -std=c++0x -Wall -Wextra -pedantic

IPATHS = -I/usr/local/include
LPATHS = -L/usr/local/lib
BINDIR = bin
SRCDIR = src
DOCDIR = doc
EXTDIR = ext
OBJDIR = obj
TMPDIR = tmp

SRCFILES = src/main.cpp src/conv.cpp src/cli.cpp
OBJFILES = $(subst $(SRCDIR)/,$(OBJDIR)/,$(SRCFILES:.cpp=.o))
OBJSDIRS = $(subst $(SRCDIR)/,$(OBJDIR)/,$(filter %/, $(wildcard $(SRCDIR)/*/)))

alphcon: $(BINDIR) $(OBJDIR) $(OBJFILES)
	$(CC) $(CFLAGS) $(LPATHS) -o $(BINDIR)/alphcon $(OBJFILES) $(LIBS)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(CC) -c $(CFLAGS) $(IPATHS) $< -o $@

$(BINDIR):
	@mkdir -p $@

$(OBJDIR):
	@mkdir -p $@

test:
	@echo "A \ta \tB \tb \tC \tc \tČ \tč \tĆ \tć"
	@echo "A \ta \tB \tb \tC \tc \tČ \tč \tĆ \tć" | ./bin/alphcon -l
	@echo "A \ta \tB \tb \tC \tc \tČ \tč \tĆ \tć" | ./bin/alphcon -l | ./bin/alphcon -c
	@echo "\n"
	@echo "D \td \tDž\tdž\tĐ \tđ \tE \te \tF \tf"
	@echo "D \td \tDž\tdž\tĐ \tđ \tE \te \tF \tf" | ./bin/alphcon -l
	@echo "D \td \tDž\tdž\tĐ \tđ \tE \te \tF \tf" | ./bin/alphcon -l | ./bin/alphcon -c
	@echo "\n"
	@echo "G \tg \tH \th \tI \ti \tJ \tj \tK \tk"
	@echo "G \tg \tH \th \tI \ti \tJ \tj \tK \tk" | ./bin/alphcon -l
	@echo "G \tg \tH \th \tI \ti \tJ \tj \tK \tk" | ./bin/alphcon -l | ./bin/alphcon -c
	@echo "\n"
	@echo "L \tl \tLj\tlj\tM \tm \tN \tn \tNj\tnj"
	@echo "L \tl \tLj\tlj\tM \tm \tN \tn \tNj\tnj" | ./bin/alphcon -l
	@echo "L \tl \tLj\tlj\tM \tm \tN \tn \tNj\tnj" | ./bin/alphcon -l | ./bin/alphcon -c
	@echo "\n"
	@echo "O \to \tP \tp \tR \tr \tS \ts \tŠ \tš"
	@echo "O \to \tP \tp \tR \tr \tS \ts \tŠ \tš" | ./bin/alphcon -l
	@echo "O \to \tP \tp \tR \tr \tS \ts \tŠ \tš" | ./bin/alphcon -l | ./bin/alphcon -c
	@echo "\n"
	@echo "T \tt \tU \tu \tV \tv \tZ \tz \tŽ \tž"
	@echo "T \tt \tU \tu \tV \tv \tZ \tz \tŽ \tž" | ./bin/alphcon -l
	@echo "T \tt \tU \tu \tV \tv \tZ \tz \tŽ \tž" | ./bin/alphcon -l | ./bin/alphcon -c

clean:
	@rm -rf $(BINDIR) $(OBJDIR)
