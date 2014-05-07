struct defn {
	char *name;	/* name in the #define */
	char *val;	/* replacement string */
};

struct nlist { /* record of the table */
	struct nlist *next; /* next record in the chain */
	struct defn d;
};

struct nlist *lookup(char *);
struct nlist *install(struct defn *);

