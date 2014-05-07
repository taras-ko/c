/* qsort: sort v[left]...v[right] in increase order */
void qsort(void *v[], int left, int right,
		int (*comp) (void *, void *), int reverse)
{
	int i, last;
	void swap(void *v[], int i, int j);

	if (left >= right)  /* nothing to do if in array */
		return;			/* if less than 2 elements */
	swap(v, left, (left + right)/2);
	last = left;
	for (i = left + 1; i <= right; i++)
		if (!reverse && (*comp)(v[i], v[left]) < 0 ||
			reverse && (*comp)(v[i], v[left]) > 0)
			swap(v, ++last, i);
	swap(v, left, last);
	qsort(v, left, last - 1, comp, reverse);
	qsort(v, last + 1, right, comp, reverse);
}
