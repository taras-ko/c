#include <string>
struct defn {
	std::string& name;	/* name in the #define */
	std::string& val;	/* replacement string */
};

struct nlist { /* record of the table */
	struct nlist *next; /* next record in the chain */
	struct defn d;
};

struct nlist *lookup(char *);
struct nlist *install(struct defn *);

