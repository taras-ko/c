#include <stdio.h>
#include <stdlib.h>

#include <stringlocal.h>
#include <tblfun.h>
#include <debug.h>

#define HASHSIZE 101
static struct nlist *hashtab[HASHSIZE]; /* table of pointers */

/* hash: hash-code generation for s string */
unsigned hash(char *s)
{
	unsigned hashval;
	unsigned hash;

	for (hashval = 0; *s != '\0'; s++)
		hashval = *s + 31 * hashval;

	hash = hashval % HASHSIZE;
	debug_print("hash = %u\n", hash);
	return hash;
}

/* lookup: seach element s in table hashtab */
struct nlist *lookup(char *name)
{
	struct nlist *np;

	for (np = hashtab[hash(name)]; np != NULL; np = np->next)
		if (strcmp(name, np->d.name) == 0) {
			debug_print("name = %s, val = %s\n", np->d.name, np->d.val);
			return np; /* found element */
		}
	return NULL;	   /* couldn't found element */
}

/* install: puts record "name + definition "
 *		(name, defn) in the hastab
 */
struct nlist *install(struct defn *dp)
{
	struct nlist *np;
	unsigned hashval;

	if ((np = lookup(dp->name)) == NULL) { /* name not found */
		np = (struct nlist *) malloc(sizeof(*np));
		if (np == NULL || (np->d.name = _strdup(dp->name)) == NULL)
			return NULL;
		hashval = hash(dp->name);
		np->next = hashtab[hashval];
		hashtab[hashval] = np;
		debug_print("%s %s\n", dp->name, dp->val);
	} else /* already in the table */
		free((void *) np->d.val); /* deletion of the old defenition */
	if ((np->d.val = _strdup(dp->val)) == NULL)
		return NULL;
	return np;
}

void undef(char *name)
{
	struct nlist *np;

	if ((np = lookup(name)) != NULL) {
		debug_print("free some np\n");
		free((void *) np->d.name);
		free((void *) np->d.val);
		free((void *) np);
	}
}
