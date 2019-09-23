#include<stdio.h>
#include<stdlib.h>
struct treenode {
	struct treenode *lchild;
	char data;
	struct treenode *rchild;
};
main() {
	struct treenode *a, *b, *c, *d, *e, *f, *g;

	a = malloc(sizeof(struct treenode));
	a->data = 'A';
	a->lchild = a->rchild = NULL;

	b = malloc(sizeof(struct treenode));
	b->data = 'B';
	b->lchild = b->rchild = NULL;
	a->lchild = b;

	c = malloc(sizeof(struct treenode));
	c->data = 'C';
	c->lchild = c->rchild = NULL;
	a->rchild = c;

	d = malloc(sizeof(struct treenode));
	d->data = 'D';
	d->lchild = d->rchild = NULL;
	b->lchild = d;

	e = malloc(sizeof(struct treenode));
	e->data = 'E';
	e->lchild = d->rchild = NULL;
	b->rchild = e;

	f = malloc(sizeof(struct treenode));
	f->data = 'F';
	f->lchild = f->rchild = NULL;
	c->lchild = f;

	g = malloc(sizeof(struct treenode));
	g->data = 'G';
	g->lchild = g->rchild = NULL;
	c->rchild = g;

	print(a);
}

print(struct treenode *p) {
	if (p != NULL) {
		print(p->lchild);
		printf("%c\t", p->data);
		print(p->rchild);
	}
}

