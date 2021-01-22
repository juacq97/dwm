int
isdualstacklayout(Monitor *m)
{
	if (m->lt[m->sellt]->arrange != &flextile)
		return 0;

	int layout = m->ltaxis[LAYOUT];
	if (layout < 0)
		layout *= -1;

	return (
		layout == SPLIT_HORIZONTAL_DUAL_STACK ||
		layout == SPLIT_HORIZONTAL_DUAL_STACK_FIXED ||
		layout == SPLIT_VERTICAL_DUAL_STACK ||
		layout == SPLIT_VERTICAL_DUAL_STACK_FIXED
	);
}

int
iscenteredlayout(Monitor *m, int n)
{
	if (m->lt[m->sellt]->arrange != &flextile)
		return 0;

	int layout = m->ltaxis[LAYOUT];
	if (layout < 0)
		layout *= -1;

	return (
			(layout == SPLIT_CENTERED_VERTICAL && (n - m->nmaster > 1)) ||
			layout == SPLIT_CENTERED_VERTICAL_FIXED ||
			(layout == SPLIT_CENTERED_HORIZONTAL && (n - m->nmaster > 1)) ||
			layout == SPLIT_CENTERED_HORIZONTAL_FIXED ||
			layout == FLOATING_MASTER
	);
}


void
insertclient(Client *item, Client *insertItem, int after)
{
	Client *c;
	if (item == NULL || insertItem == NULL || item == insertItem)
		return;
	detach(insertItem);
	if (!after && selmon->clients == item) {
		attach(insertItem);
		return;
	}
	if (after) {
		c = item;
	} else {
		for (c = selmon->clients; c; c = c->next) {
			if (c->next == item)
				break;
		}
	}
	insertItem->next = c->next;
	c->next = insertItem;
}

void
inplacerotate(const Arg *arg)
{
	Monitor *m = selmon;
	if (!m->sel || (m->sel->isfloating && !arg->f))
		return;

	unsigned int n, selidx = 0, i = 0, tidx, center, dualstack;
	Client *c = NULL,
		*shead = NULL, *stail = NULL,
		*thead = NULL, *ttail = NULL,
		*mhead = NULL, *mtail = NULL;

	for (n = 0, c = nexttiled(m->clients); c; c = nexttiled(c->next), ++n);
	tidx = m->nmaster + (m->nstack > 0 ? m->nstack : (n - m->nmaster) / 2 + ((n - m->nmaster) % 2 > 0 ? 1 : 0));

	// Shift client
	for (c = m->clients; c; c = c->next) {
		if (ISVISIBLE(c) && !(c->isfloating) && !HIDDEN(c)) {
			if (m->sel == c)
				selidx = i;
			if (i == m->nmaster - 1)
				mtail = c;
			if (i == m->nmaster)
				shead = c;
			if (i == tidx - 1)
				stail = c;
			if (i == tidx)
				thead = c;
			if (mhead == NULL)
				mhead = c;
			ttail = c;
			i++;
		}
	}

	center = iscenteredlayout(m, n);
	dualstack = isdualstacklayout(m);
	if ((!center && !dualstack) || (center && n <= m->nmaster + (m->nstack ? m->nstack : 1))) {
		if (arg->i < 0 && selidx >= selmon->nmaster) insertclient(ttail, shead, 1);
		if (arg->i > 0 && selidx >= selmon->nmaster) insertclient(shead, ttail, 0);
	} else {
		if (arg->i < 0 && selidx >= selmon->nmaster && selidx < tidx) insertclient(stail, shead, 1);
		if (arg->i > 0 && selidx >= selmon->nmaster && selidx < tidx) insertclient(shead, stail, 0);
		if (arg->i < 0 && selidx >= tidx) insertclient(ttail, thead, 1);
		if (arg->i > 0 && selidx >= tidx) insertclient(thead, ttail, 0);
	}
	if (arg->i < 0 && selidx < selmon->nmaster)  insertclient(mtail, mhead, 1);
	if (arg->i > 0 && selidx < selmon->nmaster)  insertclient(mhead, mtail, 0);

	// Restore focus position
	i = 0;
	for (c = selmon->clients; c; c = c->next) {
		if (!ISVISIBLE(c) || (c->isfloating))
			continue;
		if (i == selidx) {
			focus(c);
			break;
		}
		i++;
	}
	arrangemon(selmon);
	focus(c);
}
