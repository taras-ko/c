#ifndef TREE_H
#define TREE_H

struct tnode {
	wint_t *word;
	int count;
	struct tnode *left;
	struct tnode *right;
};

#endif //TREE_H
