int getMiddle(struct node *p) {

	int mid;
	struct node *p1, *p2;
	p1 = p2 = p;

	while (p2->link != NULL && p2->link->link != NULL) {
		p1 = p1->link;
		p2 = p2->link->link;
	}

	return p1->data;
}
