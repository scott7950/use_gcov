SRCDIR = src
SIMDIR = sim

SOURCE = code.cpp main.cpp
PROGRAM = $(SIMDIR)/code.out

COMPFILES = $(patsubst %.cpp,%.o,$(SOURCE))

INCDIR = ./$(SRC)
COMPARG = -std=c++11

SOURCEWITHPATH = $(addprefix src/,$(SOURCE))

all: clean coverageHtmlGen
	echo $(COMPFILES)

clean:
	rm -rf $(SIMDIR) *.gcno *.out *.gcda *.o coverage.info coverage_html

%.o: $(SRCDIR)/%.cpp
	g++ --coverage -I$(INCDIR) $(COMPARG) -c $< -o $@

$(PROGRAM): $(COMPFILES)
	if [ ! -e $(SIMDIR) ]; then mkdir $(SIMDIR); fi
	g++ --coverage $? -o $@

run: $(PROGRAM)
	./$(PROGRAM)

coverageGen: run
	gcov $(SOURCEWITHPATH)

coverageHtmlGen: coverageGen
	lcov --capture --directory ./ --output-file coverage.info
	genhtml coverage.info --output-directory coverage_html


