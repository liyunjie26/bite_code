#include"contact.h"
void ContactInit(Contact_t *pct)
{
	memset(pct->base, 0, sizeof(PersonInfo_t)*MAX_CONTACT_SIZE);
	pct->size = 0;
	pct->capacity = MAX_CONTACT_SIZE;
}