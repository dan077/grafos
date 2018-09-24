#include <iostream>
#include <stdlib.h>

using namespace std;

struct vertex;
struct edge;

struct vertex
{
	char id;
	vertex* sgt;
	edge* ady;
};

struct edge
{
	int weight;
	edge* sgt;
	vertex* assoc;
};

vertex* Head = NULL, * Tail = NULL ;

void add_vertex(vertex*& , char , vertex*&);
void show_vertex(vertex*);

void add_edge(vertex*&, vertex*&,int);
void build_edge(vertex*&);
void show_edge(vertex*);
void inf_edge(vertex*);

vertex* search_vertex(vertex*, char);
edge* exist_edge(vertex*, vertex*);



int main() {

	add_vertex(Head, 'a', Tail);
	add_vertex(Head, 'b', Tail);
	add_vertex(Head, 'c', Tail);
	show_vertex(Head);
	build_edge(Head);
	build_edge(Head);
	//build_edge(Head);
	show_edge(Head);
	show_edge(Head);
	inf_edge(Head);

	system("pause");
	return 0;
}

void add_vertex(vertex*& h, char id, vertex*& t) {
	vertex *new_vertex = (vertex*)malloc(sizeof(vertex));
	new_vertex->id = id;
	new_vertex->ady = NULL;
	new_vertex->sgt = NULL;

	if (!h) {
		h = new_vertex;
		t = h;
	}
	else {
		t->sgt = new_vertex;
		t = new_vertex;
	}
		
	

}

void show_vertex(vertex* h) {
	if (h) {
		cout << "Vertices: ";
		for (; h != NULL; h = h->sgt) {
			cout << h->id;
			if (h->sgt)
				cout << '-';
		}
		cout << "\n";
	}
	else
		cout << "No se han creado vertices\n";
}

void add_edge(vertex*& source, vertex*& dest, int weight) {
		if (source) {
			if (dest) {
				edge* new_edge = (edge*)malloc(sizeof(edge));
				new_edge->weight = weight;
				new_edge->assoc = dest;
				new_edge->sgt = NULL;

				if (source->ady == NULL) {
					source->ady = new_edge;
				}
				else {
					edge* aux = source->ady;
					for (; aux->sgt != NULL; aux = aux->sgt);
					aux->sgt = new_edge;
				}

				cout << "\nLa arista se ha creado satisfactoriamente\n";
			}
			else
				cout << "El nodo asociado no existe.\n";
		}
		else
			cout << "El nodo destino no existe.\n";
	
}

void build_edge(vertex*& h) {
	if (h) {
		char id;
		int weight;
		vertex *source = NULL,*dest = NULL;

		cout << "\nAcontinuacion, usted agregara el vertice , el vertice al que se va a asociar y el peso.\n";
		cout << "Ingrese la identificacion del vertice: ";
		cin >> id;
		source = search_vertex(h, id);

		if (source) {
			cout << "Ingrese la identificacion del vertice a asociar: ";
			cin >> id;
			dest = search_vertex(h, id);

			if (dest) {

				if (!exist_edge(source, dest)) {
					cout << "Ingrese el peso: ";
					cin >> weight;
					add_edge(source, dest, weight);
				}
				else {
					cout << "Relacion existente.\n";
				}
				
			}
		}
	}
	else
		cout << "No se ha podido crear una arista, ya que aun no existen vertices\n";
}

void show_edge(vertex* vert) {
	if (vert) {
		edge* edg = vert->ady;
		cout << "aristas del vertice: ";
		for (; edg != NULL; edg = edg->sgt) {
			cout << '[' << vert->id << ',' << edg->assoc->id << ']';
			if (edg->sgt != NULL) {
				cout << ',';
			}
			else {
				cout << '\n';
			}
		}

	}
}

vertex* search_vertex(vertex* h, char id) {
	if (h) {
		for (; h->id != id and h->sgt != NULL; h = h->sgt);
		if (h->id == id) {
			return h;
		}
		else {
			cout << "El id del nodo no existe.\n";
			return NULL;
		}
	}
}

edge* exist_edge(vertex* source, vertex*dest) {
	if (source) {
		if (dest) {
			edge* aux = source->ady;
			for (;aux != NULL; aux = aux->sgt) {
				if (aux->assoc == dest) {
					return aux;
				}
			}
			return NULL;
		}
		else {
			cout << "El vertice asociado no existe.\n";
		}
	}
	else {
		cout << "El vertice de origen no existe.\n";
	}
}

void inf_edge(vertex* h) {
	char IDsource, IDdest;
	edge* info;
	vertex* source,*dest;
	cout << "Ingrese el ID del vertice de origen: ";
	cin >> IDsource;
	cout << "Ingrese el nodo asociado: ";
	cin >> IDdest;

	source = search_vertex(h, IDsource);
	dest = search_vertex(h, IDdest);
	info = exist_edge(source,dest);
	cout << "Información de la relación:\n";

	if (info) {
		cout <<"Origen: " << source->id << '\n';
		cout << "Destin: "<< info->assoc->id << '\n';
		cout << "Peso: " << info->weight << '\n';
	}
	else {
		cout << "EROR";
	}


}