
typedef int variable;
typedef struct Listcode
{
	variable* list;
	int size;
	int capacity;
}Listcode;

void Initialization(Listcode* sl);
void Dilatation(Listcode* sl);
void Add(Listcode* sl, variable value);
void Delete(Listcode* sl);
