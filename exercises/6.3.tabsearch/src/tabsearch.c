#include <iostream>
#include <fstream>
#include <string>
#include <cassert>

#include <tabfun.h>

#if 0
#include <ctype.h>
#include <string.h>

/* copies 1 word from stdin to the s */
int getword(const string& line, char *w)
{
	int c;
	while (isspace(c = getchar()))
		;
	*w++ = c;
	while ((c = getchar()) != EOF && !isspace(c))
		*w++ = c;
	*w = '\0';
	return c;
}
#endif

bool getdefn(std::ifstream& in, defn& def)
{
	return true;
}

class idefstream {
	std::ifstream ifs;
	const bool getword(std::string& word);
	std::string word;
public:
	idefstream(const char *filename, std::ios_base::openmode mode = std::ios_base::in)
		: ifs(filename, mode) {}
	operator bool() const {
		return ifs.good();
	}
	const idefstream& operator>>(defn& def);

};

const bool idefstream::getword(std::string& word) {
	char c;

	ifs >> c;
	ifs.putback(c);

	word.clear();

	while (ifs.get(c) && !isspace(c))
		word.push_back(c);

	ifs.putback(c);

	return word.empty() ? false : true;
}

const idefstream& idefstream::operator>>(defn& def) {
	char c;

	std::string word;
	while (getword(word))
		if (word == "#define")
			if (getword(def.name) && getword(def.val))
				break;

	return *this;
}



int main(int argc, char *argv[])
{
	using namespace std;
try {
	idefstream din(*++argv); // Input stream of defines
//	in.exceptions(ifstream::failbit);

	string name;
	string val;
	defn def = {
		name,
		val,
	};

	while (din >> def)
		cout << def.name << ' ' << def.val << endl;

} catch (ios_base::failure &fail) {
	cerr << fail.what();
}
#if 0
	string line;
	string word;
	int c;
	while (getline(line))
		if (strcmp("#define", w) == 0) {
			getword(d.name);
			getword(d.val);
			install(&d);
		}

	undef("F");
	lookup("IN");
	lookup("OUT");
	lookup("A");
	lookup("B");
	lookup("C");
	lookup("D");
	lookup("E");
	lookup("F");
#endif
}

