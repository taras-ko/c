#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>

#include <bintree.h>

struct tnode *talloc(void)
{
	return (struct tnode *) malloc(sizeof(struct tnode));
}

struct tnode *addtree(struct tnode *node, wint_t *word)
{
	int cond;

	if (node == NULL && (node = talloc())) {
		node->word = wcsdup(word);
		node->count = 1;
		node->left = node->right = NULL;
	} else if ((cond = wcscmp(word, node->word)) == 0)
		node->count++;
	else if (cond < 0)
		node->left = addtree(node->left, word);
	else
		node->right = addtree(node->right, word);

	return node;
}

void treeprint(struct tnode *root)
{
	if (root != NULL) {
		treeprint(root->left);
		printf("%d %ls\n",root->count, root->word);
		treeprint(root->right);
	}
}


