#ifndef BINTREE_H
#define BINTREE_H

struct tnode {
	wint_t *word;
	int count;
	struct tnode *left;
	struct tnode *right;
};

struct tnode *talloc(void);
struct tnode *addtree(struct tnode *node, wint_t *word);
void treeprint(struct tnode *root);

#endif //BINTREE_H
